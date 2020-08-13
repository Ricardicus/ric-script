#include "libmath.h"

int ric_power(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double arg2 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
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
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = pow(arg1, arg2);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_log(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = log(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_sqrt(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = sqrt(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_sin(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = sin(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}


int ric_cos(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = cos(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}


int ric_tan(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = tan(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}


int ric_exp(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = exp(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_abs(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = fabs(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_floor(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = floor(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

int ric_ceil(LIBRARY_PARAMS())
{
  stackval_t stv;
  double arg1 = 1;
  double result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    arg1 = (double) stv.i;
    break;
    case DOUBLETYPE:
    arg1 = stv.d;
    break;
    default:{
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = ceil(arg1);

  /* Pushing file pointer */
  PUSH_DOUBLE(result, sp, sc);

  return 0;
}

