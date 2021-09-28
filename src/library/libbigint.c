#include "libbigint.h"

int ric_new_big_int(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *stringArg = NULL;
  int32_t intArg = 0;
  expr_t *e = NULL;
  mpz_t *n = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  int dummy = 0;
  heapval_t *hpv = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    stringArg = stv.t;
    break;
    case INT32TYPE:
    intArg = stv.i;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string or data expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  if ( stringArg != NULL ) {
    e = newExpr_BigIntFromStr(stringArg);
    n = e->bigInt;
    free(e);
  } else {
    e = newExpr_BigIntFromInt(intArg);
    n = e->bigInt;
    free(e);
  }

  stv.type = BIGINT;
  stv.bigInt = n;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the parsed value */
  PUSH_BIGINT(n, sp, sc);

  return 0;
}
