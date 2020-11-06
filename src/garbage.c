/*
* Garbage collection
*/

#include "garbage.h"
#include "eval.h"

uint32_t generate_mark_value()
{
  static int initial = 1;
  uint32_t r;

  if ( initial ) {
    /* Only called once */
    srand(time(NULL));
  }

  r = (uint32_t) rand();

  initial = 0;

  return r;
}

static void mark (
  hashtable_t *varDecs,
  uint32_t markVal,
  EXPRESSION_PARAMS()) {
  char *variableIDS[RIC_MAX_NBR_VARS];
  int argCount = 0;
  int i = 0;
  int hashSize = varDecs->size;
  struct key_val_pair *ptr;

  if ( varLocals != NULL ) {
    /* Mark local variables */
    i = 0;
    while ( i < varLocals->sp ) {
      heapval_t *hv = varLocals->stack[i].hpv;

      hv->mark = markVal;
      if ( hv->sv.type == DICTTYPE ) {
        mark(hv->sv.dict->hash, markVal, EXPRESSION_ARGS());
      } else if ( hv->sv.type == CLASSTYPE && hv->sv.classObj->initialized ) {
        mark(hv->sv.classObj->varMembers, markVal, EXPRESSION_ARGS());
      }

      ++i;
    }
  }

  argCount = 0;
  i = 0;
  while ( i < hashSize ) {
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
  while ( i < argCount ) {
    heapval_t *hv = hashtable_get(varDecs, variableIDS[i]);
    hv->mark = markVal;

    if ( hv->sv.type == DICTTYPE ) {
      mark(hv->sv.dict->hash, markVal, EXPRESSION_ARGS());
    }
    ++i;
  }
}

static void sweep (
  uint32_t markVal,
  EXPRESSION_PARAMS()) {
  int i = 0;
  int32_t size = (*(heapval_t*)hp).sv.i;
  heapval_t *heap = (heapval_t*)hp;

  /* Sweep the heap values that haven't got the mark */
  i = 1;
  while ( i < size - 1 ) {
    if ( heap[i].occupied && 
        heap[i].mark != markVal) {
      // Sweep this value
      if ( heap[i].toFree ) {
        if ( heap[i].sv.type == TEXT ) {
          free(heap[i].sv.t);
        } else if ( heap[i].sv.type == VECTORTYPE ) {
          expr_t *e = newExpr_Vector(NULL);
          free(e->vec);
          e->vec = heap[i].sv.vec;
          free_expression(e);
          free(e);
        } else if ( heap[i].sv.type == DICTTYPE ) {
          hashtable_free(((heapval_t*) hp)[i].sv.dict->hash);
          free(heap[i].sv.dict);
        }
        heap[i].toFree = false;
      }
      heap[i].occupied = false;
    }

    ++i;
  }
}

void mark_and_sweep (
  hashtable_t *varDecs,
  EXPRESSION_PARAMS()) {
  uint32_t markVal;
  /* Generate mark value */
  markVal = generate_mark_value();
  /* Mark objects to keep */
  mark(varDecs, markVal, EXPRESSION_ARGS());
  /* Sweep the rest */
  sweep(markVal, EXPRESSION_ARGS());
}

void free_heap(void *hp, void *hbp) {
  int32_t size = (*(heapval_t*)hp).sv.i;
  int32_t i = 0;
  while ( i < size ) {
    if ( ((heapval_t*) hp)[i].occupied &&
     ((heapval_t*) hp)[i].toFree ) {
        if ( ((heapval_t*) hp)[i].sv.type == TEXT ) {
          free(((heapval_t*) hp)[i].sv.t);
        } else if ( ((heapval_t*) hp)[i].sv.type == VECTORTYPE ) {
          expr_t *e = newExpr_Vector(NULL);
          free(e->vec);
          e->vec = ((heapval_t*) hp)[i].sv.vec;
          free_expression(e);
          free(e);
        } else if ( ((heapval_t*) hp)[i].sv.type == DICTTYPE ) {
          hashtable_free(((heapval_t*) hp)[i].sv.dict->hash);
          free(((heapval_t*) hp)[i].sv.dict);
        }
    }
    ++i;
  }
  free(hbp);
}



