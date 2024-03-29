#include "libprioqueue.h"
#include "eval.h"

int ric_new_min_heap(LIBRARY_PARAMS()) {
  int capacity = PRIO_QUEUE_DEFAULT_CAP;
  priority_queue_t *result = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  result = new_priority_queue(capacity, 1);

  /* Pushing the parsed value */
  PUSH_PRIOQUEUE(result, sp, sc);

  return 0;
}

int ric_new_max_heap(LIBRARY_PARAMS()) {
  int capacity = PRIO_QUEUE_DEFAULT_CAP;
  priority_queue_t *result = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  result = new_priority_queue(capacity, 0);

  /* Pushing the parsed value */
  PUSH_PRIOQUEUE(result, sp, sc);

  return 0;
}

int ric_heap_insert(LIBRARY_PARAMS()) {
  stackval_t stv;
  priority_queue_t *arg = NULL;
  expr_t *toAdd = NULL;
  int priority = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Get argument
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case PRIOQUEUE:
      arg = stv.prioqueue;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, expected a priority queue.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  // Get what to insert
  POP_VAL(&stv, sp, sc);
  toAdd = stackval_to_expression(&stv, 0, EXPRESSION_ARGS());

  // Get priority
  POP_VAL(&stv, sp, sc);
  switch (stv.type) {
    case INT32TYPE:
      priority = stv.i;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, expected an integer.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  priority_queue_insert(arg, toAdd, priority);

  return 0;
}

int ric_heap_pop(LIBRARY_PARAMS()) {
  stackval_t stv;
  priority_queue_t *arg = NULL;
  expr_t *popped = NULL;
  heapval_t *hp = PROVIDE_CONTEXT()->hp;
  heapval_t *hpv = NULL;
  int dummy;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Get argument
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case PRIOQUEUE:
      arg = stv.prioqueue;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, expected a priority queue.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  // check if size is larger than zero
  if (arg->size == 0) {
    fprintf(stderr, "error: function call '%s' got empty priority queue.\n", LIBRARY_FUNC_NAME());
    exit(1);
  }

  // pop the maximum prio value from the queue
  popped = priority_queue_pop(arg);

  push_expression(popped, EXPRESSION_ARGS());

  // allocate the popped argument to the heap so that it
  // can be freed later
  POP_VAL(&stv, sp, sc);
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  push_expression(popped, EXPRESSION_ARGS());

  free(popped);
  return 0;
}
