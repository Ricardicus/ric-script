/*
 * Garbage collection
 */

#include "garbage.h"
#include "eval.h"
#include "sync.h"

uint32_t generate_mark_value() {
  static int initial = 1;
  uint32_t r;

  if (initial) {
    /* Only called once */
    srand(time(NULL));
  }

  r = (uint32_t)rand();

  initial = 0;

  return r;
}

void mark(hashtable_t *varDecs, uint32_t markVal, EXPRESSION_PARAMS()) {
  char *variableIDS[RIC_MAX_NBR_VARS];
  int argCount = 0;
  int i = 0;
  int hashSize = 0;
  struct key_val_pair *ptr;
  locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;

  if (varDecs != NULL) {
    hashSize = varDecs->size;
  }

  if (varLocals != NULL) {
    /* Mark local variables */
    i = 0;
    while (i < varLocals->sp) {
      heapval_t *hv = varLocals->stack[i].hpv;
      if (hv->mark == markVal) {
        i++;
        continue;
      }
      hv->mark = markVal;
      if (hv->sv.type == DICTTYPE) {
        mark(hv->sv.dict->hash, markVal, EXPRESSION_ARGS());
      } else if (hv->sv.type == CLASSTYPE && hv->sv.classObj->initialized) {
        mark(hv->sv.classObj->varMembers, markVal, EXPRESSION_ARGS());
      } else if (hv->sv.type == VECTORTYPE) {
        vector_t *vec = hv->sv.vec;
        argsList_t *args = vec->content;
        while (args != NULL) {
          expr_t *e = args->arg;
          if (e->type == EXPR_TYPE_DICT && e->dict->type == RIC_DICTIONARY_DYN) {
            mark(e->dict->hash, markVal, EXPRESSION_ARGS());
          }
          if (e->type == EXPR_TYPE_CLASSPTR && e->classObj->initialized) {
            mark(e->classObj->varMembers, markVal, EXPRESSION_ARGS());
          }
          args = args->next;
        }
      }

      ++i;
    }
  }

  argCount = 0;
  i = 0;
  while (i < hashSize) {
    ptr = varDecs->table[i];
    while (ptr != NULL) {
      variableIDS[argCount] = ptr->key;
      argCount++;
      ptr = ptr->next;
    }
    i++;
  }

  /* Mark all variables in the heap */
  i = 0;
  while (i < argCount) {
    heapval_t *hv = hashtable_get(varDecs, NULL, variableIDS[i]);
    hv->mark = markVal;

    if (hv->sv.type == DICTTYPE) {
      mark(hv->sv.dict->hash, markVal, EXPRESSION_ARGS());
    } else if (hv->sv.type == CLASSTYPE && hv->sv.classObj->initialized) {
      mark(hv->sv.classObj->varMembers, markVal, EXPRESSION_ARGS());
    } else if (hv->sv.type == VECTORTYPE) {
      vector_t *vec = hv->sv.vec;
      argsList_t *args = vec->content;
      while (args != NULL) {
        expr_t *e = args->arg;
        if (e->type == EXPR_TYPE_DICT && e->dict->type == RIC_DICTIONARY_DYN) {
          mark(e->dict->hash, markVal, EXPRESSION_ARGS());
        }
        args = args->next;
      }
    }
    ++i;
  }
}

static void sweep(uint32_t markVal, EXPRESSION_PARAMS()) {
  int i = 0;
  void *hp = PROVIDE_CONTEXT()->hp;
  int32_t size = (*(heapval_t *)hp).sv.i;
  heapval_t *heap = (heapval_t *)hp;

  /* Sweep the heap values that haven't got the mark */
  i = 1;
  while (i < size - 1) {
    if (heap[i].occupied && heap[i].mark != markVal) {
      // Sweep this value
      if (heap[i].toFree) {
        if (heap[i].sv.type == TEXT) {
          free(heap[i].sv.t);
        } else if (heap[i].sv.type == VECTORTYPE) {
          expr_t *e = newExpr_Vector(NULL);
          free(e->vec);
          e->vec = heap[i].sv.vec;
          free_expression(e);
          free(e);
        } else if (heap[i].sv.type == DICTTYPE) {
          if (((heapval_t *)hp)[i].sv.dict->hash) {
            hashtable_free(((heapval_t *)hp)[i].sv.dict->hash);
          }
          if (((heapval_t *)hp)[i].sv.dict->type == RIC_DICTIONARY_DYN) {
            free_keyvals(((heapval_t *)hp)[i].sv.dict);
          }
          free(heap[i].sv.dict);
        } else if (heap[i].sv.type == BIGINT) {
          mpz_clear(*heap[i].sv.bigInt);
          free(heap[i].sv.bigInt);
        } else if (heap[i].sv.type == RAWDATATYPE) {
          free(heap[i].sv.rawdata->data);
          free(heap[i].sv.rawdata);
        } else if (heap[i].sv.type == CLASSTYPE) {
          if (((heapval_t *)hp)[i].sv.classObj->initialized) {
            hashtable_free(((heapval_t *)hp)[i].sv.classObj->varMembers);
            hashtable_free(((heapval_t *)hp)[i].sv.classObj->funcDefsScript);
            hashtable_free(((heapval_t *)hp)[i].sv.classObj->funcDefsABI);
          }
          free(((heapval_t *)hp)[i].sv.classObj);
        }
        heap[i].toFree = false;
      }
      heap[i].occupied = false;
    }

    ++i;
  }
}

void mark_and_sweep(hashtable_t *varDecs, EXPRESSION_PARAMS()) {
  uint32_t markVal;
  /* Rest assure, you are doing this safely */
  getContext(PROVIDE_CONTEXT()->syncCtx);
  /* Generate mark value */
  markVal = generate_mark_value();
  /* Safeguard local variables in threads */
  markContext(PROVIDE_CONTEXT()->syncCtx, markVal);
  /* Mark objects to keep */
  mark(varDecs, markVal, EXPRESSION_ARGS());
  /* Sweep the rest */
  sweep(markVal, EXPRESSION_ARGS());
  releaseContext(PROVIDE_CONTEXT()->syncCtx);
}

void free_heap(void *hp, void *hbp) {
  int32_t size = (*(heapval_t *)hp).sv.i;
  int32_t i = 0;
  while (i < size) {
    if (((heapval_t *)hp)[i].occupied && ((heapval_t *)hp)[i].toFree) {
      if (((heapval_t *)hp)[i].sv.type == TEXT) {
        free(((heapval_t *)hp)[i].sv.t);
      } else if (((heapval_t *)hp)[i].sv.type == VECTORTYPE) {
        expr_t *e = newExpr_Vector(NULL);
        free(e->vec);
        e->vec = ((heapval_t *)hp)[i].sv.vec;
        free_expression(e);
        free(e);
      } else if (((heapval_t *)hp)[i].sv.type == DICTTYPE) {
        hashtable_free(((heapval_t *)hp)[i].sv.dict->hash);
        free(((heapval_t *)hp)[i].sv.dict);
      } else if (((heapval_t *)hp)[i].sv.type == RAWDATATYPE) {
        free(((heapval_t *)hp)[i].sv.rawdata->data);
        free(((heapval_t *)hp)[i].sv.rawdata);
      } else if (((heapval_t *)hp)[i].sv.type == BIGINT) {
        mpz_clear(*((heapval_t *)hp)[i].sv.bigInt);
        free(((heapval_t *)hp)[i].sv.bigInt);
      } else if (((heapval_t *)hp)[i].sv.type == CLASSTYPE) {
        /* References to initialized classes are unique */
        if (((heapval_t *)hp)[i].sv.classObj != NULL) {
          /* Clear this one, only once, set all the other references to NULL*/
          void *unique_ref = ((heapval_t *)hp)[i].sv.classObj;
          int q;

          /* Clear this reference, once and for all */
          if (((heapval_t *)hp)[i].sv.classObj->initialized) {
            hashtable_free(((heapval_t *)hp)[i].sv.classObj->varMembers);
            hashtable_free(((heapval_t *)hp)[i].sv.classObj->funcDefsScript);
            ((heapval_t *)hp)[i].sv.classObj->funcDefsABI->allocated_key = 1;
            hashtable_free(((heapval_t *)hp)[i].sv.classObj->funcDefsABI);
          }
          free(((heapval_t *)hp)[i].sv.classObj);

          /* Purge the rest */
          q = i;
          while (q < size) {
            if (((heapval_t *)hp)[q].toFree && ((heapval_t *)hp)[q].sv.type == CLASSTYPE
                && ((heapval_t *)hp)[q].sv.classObj == unique_ref) {
              ((heapval_t *)hp)[q].sv.classObj = NULL; // Purged
            }
            ++q;
          }
        }
      }
    }
    ++i;
  }
  free(hbp);
}
