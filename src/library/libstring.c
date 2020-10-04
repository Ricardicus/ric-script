#include "libstring.h"

int ric_atoi(LIBRARY_PARAMS())
{
  stackval_t stv;
  char *string = NULL;
  int result = 0;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    string = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  result = atoi(string);
  
  /* Pushing the parsed value */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_split(LIBRARY_PARAMS())
{
  stackval_t stv;
  char *arg1 = NULL;
  char *arg2 = NULL;
  char *buffer = NULL;
  expr_t *vec;
  argsList_t *vecContent = NULL;
  intptr_t offset = 0;
  char *c;
  heapval_t *hpv;
  int dummy;

  // pop arg 1 - string to split
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

  // pop arg 2 - string to split by (delimiter)
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

  buffer = calloc(strlen(arg1)+2, 1);
  if ( buffer == NULL ) {
    fprintf(stderr, "error: Memory error, failed to split.\n");
    exit(1);
  }

  snprintf(buffer, strlen(arg1)+2, "%s", arg1);

  offset = 0;
  while ( (c = strstr(buffer+offset, arg2)) != NULL ) {
    expr_t *e;
    argsList_t *a;

    *c = 0;
    e = newExpr_Text(buffer+offset);
    a = newArgument(e, vecContent);
    vecContent = a;

    offset += strlen(buffer+offset) + strlen(arg2);
  }

  if ( offset != 0 ) {
    /* Take the remaining part also */
    expr_t *e;
    argsList_t *a;
    e = newExpr_Text(buffer+offset);
    a = newArgument(e, vecContent);
    vecContent = a;
  }

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}
