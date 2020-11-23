#include "libxattr.h"

int ric_list_xattr(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1 = NULL;
  char *buffer = NULL;
  size_t bufferSize = 1024;
  expr_t *vec;
  argsList_t *vecContent = NULL;
  size_t offset = 0;
  ssize_t ret;
  heapval_t *hpv;
  int dummy;

  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  buffer = calloc(bufferSize, 1);
  if ( buffer == NULL ) {
    fprintf(stderr, "error: Memory error, failed to list xattr.\n");
    exit(1);
  }

  ret = listxattr(arg1, buffer, bufferSize);

  if ( ret >= 0 ) {
    offset = 0;
    while ( offset < ret ) {
      expr_t *e;
      argsList_t *a;

      e = newExpr_Text(&buffer[offset]);
      a = newArgument(e, vecContent);
      vecContent = a;
      offset += strlen(&buffer[offset]) + 1;
    }
  }

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  free(buffer);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

int ric_set_xattr(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1;
  char *arg2;
  char *arg3;
  int32_t result = 0;

  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 2 - xattr key
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg2 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 3 - xattr value
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg3 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }
 
  result = setxattr(arg1, arg2, arg3, strlen(arg3), 0);

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_get_xattr(LIBRARY_PARAMS()) {
  char *arg1;
  char *arg2;
  stackval_t stv;
  heapval_t *hpv;
  int dummy;
  char *resultValue = NULL;
  size_t valueMaxLen = 256;

  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 2 - xattr key
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg2 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }
 
  resultValue = calloc(valueMaxLen+1, 1);
  if ( resultValue == NULL ) {
      fprintf(stderr, "error: calloc memory error during function call '%s', sorry I will terminate.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
  }

  (void)getxattr(arg1, arg2, resultValue, valueMaxLen);

  stv.type = TEXT;
  stv.t = resultValue;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_remove_xattr(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1;
  char *arg2;
  int32_t result = 0;

  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 2 - xattr key
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg2 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  result = removexattr(arg1, arg2);

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

