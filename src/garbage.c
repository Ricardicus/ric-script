/*
* Garbage collection
*/

#include "garbage.h"

uint32_t get_mark_value()
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

void mark_and_sweep (
  hashtable_t *varDecs,
  EXPRESSION_PARAMS()) {
  char *variableIDS[RIC_MAX_NBR_VARS];
  int argCount = 0;
  int i = 0;
  int32_t size = (*(heapval_t*)hb).sv.i;
  heapval_t *heap = (heapval_t*)hb;
  uint32_t markVal;
  int hashSize = varDecs->size;
  struct key_val_pair *ptr;

  argCount = 0;
  while ( i < hashSize ) {
    ptr = varDecs->table[i];
    while (ptr != NULL) {
      variableIDS[argCount] = ptr->key;
      argCount++;     
      ptr = ptr->next;
    }
    i++;
  }

  /* Get a mark value for this session */
  markVal = get_mark_value();

  /* Mark all variables in the heap */
  i = 0;
  while ( i < argCount ) {
    heapval_t *hv = hashtable_get(varDecs, variableIDS[i]);
    hv->mark = markVal;

    if ( hv->sv.type == DICTTYPE ) {
      mark_and_sweep(hv->sv.dict->hash, EXPRESSION_ARGS());
    }
    ++i;
  }

  /* Sweep the heap values that haven't got the mark */
  i = 0;
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
        }
        heap[i].toFree = false;
      }

      heap[i].occupied = false;
    }

    ++i;
  }

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
        }
    }
    ++i;
  }
  free(hbp);
}

