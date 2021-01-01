#include "libctx.h"



int ric_set_timeout(LIBRARY_PARAMS()) {
  stackval_t stv;
  functionDef_t *func;
  int timeout = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Read first argument, function definiton */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case FUNCPTRTYPE:
    func = stv.func;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  /* Read second argument, timeout */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    timeout = stv.i;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  /* TODO: Add timeout feature here, the delaying of execution in a separate thread */
  (void)timeout;

  /* Launching the function in another thread */
  createThread(PROVIDE_CONTEXT()->syncCtx, func, 0, PROVIDE_CONTEXT());

  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_set_interval(LIBRARY_PARAMS()) {

  return 0;
}
