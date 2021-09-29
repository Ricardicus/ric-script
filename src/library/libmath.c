#include "libmath.h"

int ric_power(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double arg2 = 1;
  double result = 0;
  mpz_t *arg1BigInt = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    case BIGINT:
    arg1BigInt = stv.bigInt;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  // Pop val 2
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg2 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg2 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  if ( arg1BigInt != NULL ) {
    /* Calculate big integer */
    int32_t expontent = (double) arg2;
    stackval_t stv;
    void *hp = PROVIDE_CONTEXT()->hp;
    heapval_t *hpv = NULL;
    int dummy;

    if ( expontent < 0 ) {
      fprintf(stderr, "error %s: failed to raise a big int type to a negative expontent\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }

    mpz_t *n = ast_emalloc(sizeof(mpz_t));
    mpz_init(*n);
    mpz_pow_ui(*n, *arg1BigInt, (unsigned long)expontent);

    stv.type = BIGINT;
    stv.bigInt = n;
    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    PUSH_BIGINT(n, sp, sc);
    return 0;
  }

  result = pow(arg1, arg2);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_log(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = log(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_sqrt(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = sqrt(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_sin(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = sin(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}


int ric_cos(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = cos(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}


int ric_tan(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = tan(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}


int ric_exp(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = exp(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_abs(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  mpz_t *arg1BigInt = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    case BIGINT:
    arg1BigInt = stv.bigInt;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  if ( arg1BigInt ) {
    /* Big integer absolute value */
    stackval_t stv;
    void *hp = PROVIDE_CONTEXT()->hp;
    heapval_t *hpv = NULL;
    int dummy;

    mpz_t *n = ast_emalloc(sizeof(mpz_t));
    mpz_init(*n);
    mpz_abs(*n, *arg1BigInt);

    stv.type = BIGINT;
    stv.bigInt = n;
    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    PUSH_BIGINT(n, sp, sc);
    return 0;
  }

  result = fabs(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_floor(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = floor(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_ceil(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = ceil(arg1);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_random_uniform_int(LIBRARY_PARAMS())
{
  stackval_t stv;
  int32_t arg1 = 0;
  int32_t arg2 = 0;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = stv.i;
    break;
    case DOUBLETYPE:
    arg1 = (int) stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  // Pop arg2
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg2 = stv.i;
    break;
    case DOUBLETYPE:
    arg2 = (int32_t) stv.d;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = (int32_t) ((rand() / (double)RAND_MAX) * (arg2-arg1)) + arg1;

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}


int ric_random_uniform(LIBRARY_PARAMS())
{
  double result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  result = (rand() / (double) RAND_MAX);

  /* Pushing result */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_print_nbr_base(LIBRARY_PARAMS())
{
  stackval_t stv;
  int32_t arg1 = 1;
  int32_t arg2 = 10;
  mpz_t *arg1BigInt = NULL;
  expr_t *newText = NULL;
  heapval_t *hpv = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  void *hp = PROVIDE_CONTEXT()->hp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  int dummy;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (int32_t) stv.i;
    break;
    case BIGINT:
    arg1BigInt = stv.bigInt;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  // Pop arg2
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg2 = (int32_t) stv.i;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  if ( arg2 < 2 || arg2 > 16 ) {
    fprintf(stderr, "error: function '%s' only supports bases [2, 16] (%" PRIi32 " given)\n",
      LIBRARY_FUNC_NAME(), arg2);
    return 1;
  }

  if ( arg1BigInt ) {
    /* Big integer absolute value */
    char *buf = ast_ecalloc(RIC_BIG_INT_MAX_SIZE);
    char *c = NULL;

    c = mpz_get_str(buf, (int)arg2, *arg1BigInt);

    newText = newExpr_Text(c);

    free(buf);
  } else {
    char base_digits[16] =
      {'0', '1', '2', '3', '4', '5', '6', '7',
      '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char *converted_number = ast_ecalloc(RIC_BIG_INT_MAX_SIZE);
    int32_t index=0;

    /* convert to the indicated base */
    while (arg1 != 0 && index < RIC_BIG_INT_MAX_SIZE) {
      converted_number[index] = base_digits[arg1 % arg2];
      arg1 = arg1 / arg2;
      ++index;
    }

    newText = newExpr_Text(converted_number);
    free(converted_number);
  }

  stv.type = TEXT;
  stv.t = newText->text;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(newText);

  /* Pushing the parsed value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}
