/*
* Garbage collection
*/

#include "garbage.h"

char *args[RIC_MAX_NBR_VARS];
int argCount = 0;

static void list_ids(void *key, void *val)
{
  if ( argCount > RIC_MAX_NBR_VARS )
    return;

  (void)val;
  args[argCount] = (char*) key;
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

void mark_and_sweep(
  hashtable_t *varDecs,
  heapval_t* heap) {
  int i = 0;
  int32_t size = (*(heapval_t*)heap).sv.i;
  int32_t heapWalk = 0;

  argCount = 0;
  for_each_pair(varDecs, list_ids);

  /* Get a mark value for this session */
  uint32_t markVal = get_mark_value();

  /* Mark all variables in the heap */
  while ( i < argCount ) {
    heapval_t *hv = hashtable_get(varDecs, args[i]);
    hv->mark = markVal;
    ++i;
  }

  /* Sweep the heap values that haven't got the mark */
  while ( heapWalk < size ) {
    if ( heap[i].occupied && 
        heap[i].mark != markVal) {
      // Sweep this value
      if ( heap[i].toFree ) {
        free(heap[i].sv.t);
        heap[i].toFree = false;
      }

      heap[i].occupied = false;
    }

    ++heapWalk;
  }

}