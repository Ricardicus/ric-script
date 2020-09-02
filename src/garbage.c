/*
* Garbage collection
*/

#include "garbage.h"

char *variableIDS[RIC_MAX_NBR_VARS];
int argCount = 0;

static void list_ids(void *key, void *val)
{
  if ( argCount > RIC_MAX_NBR_VARS )
    return;

  (void)val;
  variableIDS[argCount] = (char*) key;
  argCount++;
}

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
  int i = 0;
  int32_t size = (*(heapval_t*)hp).sv.i;
  heapval_t *heap = (heapval_t*)hp;
  int32_t heapWalk = 0;
  uint32_t markVal;

  argCount = 0;
  for_each_pair(varDecs, list_ids);

  /* Get a mark value for this session */
  markVal = get_mark_value();

  /* Mark all variables in the heap */
  while ( i < argCount ) {
    heapval_t *hv = hashtable_get(varDecs, variableIDS[i]);
    hv->mark = markVal;
    ++i;
  }

  /* Sweep the heap values that haven't got the mark */
  while ( heapWalk < size ) {
    if ( heap[i].occupied && 
        heap[i].mark != markVal) {
      // Sweep this value
      if ( heap[i].toFree ) {
        if ( heap[i].sv.type == TEXT ) {
          free(heap[i].sv.t);
        } else if ( heap[i].sv.type == VECTORTYPE ) {
          free_vector(heap[i].sv.vec);
          free(heap[i].sv.vec);
        }
        heap[i].toFree = false;
      }

      heap[i].occupied = false;
    }

    ++heapWalk;
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
          free_vector(((heapval_t*) hp)[i].sv.vec);
        }
    }
    ++i;
  }
  free(hbp);
}

