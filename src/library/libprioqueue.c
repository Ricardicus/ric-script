#include "libprioqueue.h"
#include "eval.h"

int ric_new_priority_queue(LIBRARY_PARAMS()) {
  stackval_t stv;
  int capacity = 0;
  priority_queue_t *result = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      capacity = stv.i;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, expected an integer.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  result = new_priority_queue(capacity);

  /* Pushing the parsed value */
  PUSH_PRIOQUEUE(result, sp, sc);

  return 0;
}

int ric_priority_queue_insert(LIBRARY_PARAMS()) {
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

  /* Pushing the parsed value */
  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_priority_queue_pop_max(LIBRARY_PARAMS()) {
  stackval_t stv;
  priority_queue_t *arg = NULL;
  expr_t *popped = NULL;
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
  popped = priority_queue_pop_max(arg);

  push_expression(popped, EXPRESSION_ARGS());
  return 0;
}
