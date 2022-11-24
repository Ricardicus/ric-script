#include "libstring.h"

int ric_atoi(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *string = NULL;
  rawdata_t *rawdata = NULL;
  int result = 0;
  double valDouble = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      string = stv.t;
      break;
    case RAWDATATYPE:
      rawdata = stv.rawdata;
      break;
    case DOUBLETYPE:
      valDouble = stv.d;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, string or data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  if (string != NULL) {
    result = atoi(string);
  } else if (rawdata != NULL) {
    result = (int)((unsigned char *)rawdata->data)[0];
  } else {
    result = (int)valDouble;
  }

  /* Pushing the parsed value */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_trim(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *string = NULL;
  char *c = NULL;
  size_t sz = 0;
  int dummy;
  heapval_t *hpv = NULL;
  char *result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      string = stv.t;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, string or data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  c = string;
  while (*c && isspace(*c))
    c++;

  sz = strlen(c);
  result = ast_ecalloc(sz + 2);
  snprintf(result, sz + 1, "%s", c);

  c = result;
  while (*c) {
    ++c;
  }
  --c;

  while (*c && *c == ' ') {
    *c = 0;
    --c;
  }

  stv.type = TEXT;
  stv.t = result;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the trimmed string */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_split(LIBRARY_PARAMS()) {
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
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  // pop arg 1 - string to split
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      arg1 = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  // pop arg 2 - string to split by (delimiter)
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      arg2 = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  buffer = calloc(strlen(arg1) + 2, 1);
  if (buffer == NULL) {
    fprintf(stderr, "error: Memory error, failed to split.\n");
    exit(1);
  }

  snprintf(buffer, strlen(arg1) + 2, "%s", arg1);

  offset = 0;
  while ((c = strstr(buffer + offset, arg2)) != NULL) {
    expr_t *e;
    argsList_t *a;

    *c = 0;
    e = newExpr_Text(buffer + offset);
    a = newArgument(e, vecContent);
    vecContent = a;

    offset += strlen(buffer + offset) + strlen(arg2);
  }

  if (offset != 0 || (strstr(buffer, arg2) == NULL)) {
    /* Take the remaining part also */
    expr_t *e;
    argsList_t *a;
    e = newExpr_Text(buffer + offset);
    a = newArgument(e, vecContent);
    vecContent = a;
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

int ric_char_code(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *string = NULL;
  int result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      string = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  result = (int)string[0];

  /* Pushing the parsed value */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_to_upper(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *string = NULL;
  expr_t *e = NULL;
  int dummy;
  size_t strLen = 0;
  size_t i = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  void *hp = PROVIDE_CONTEXT()->hp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  heapval_t *hpv = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      string = stv.t;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, string or data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  strLen = strlen(string);
  e = newExpr_Text(string);

  while (i < strLen) {
    e->text[i] = (char)toupper(string[i]);
    ++i;
  }

  stv.type = TEXT;
  stv.t = e->text;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(e);

  /* Pushing the parsed value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_to_lower(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *string = NULL;
  expr_t *e = NULL;
  int dummy;
  size_t strLen = 0;
  size_t i = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  void *hp = PROVIDE_CONTEXT()->hp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  heapval_t *hpv = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      string = stv.t;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, string or data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  strLen = strlen(string);
  e = newExpr_Text(string);

  while (i < strLen) {
    e->text[i] = (char)tolower(string[i]);
    ++i;
  }

  stv.type = TEXT;
  stv.t = e->text;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(e);

  /* Pushing the parsed value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_starts_with(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1 = NULL;
  char *arg2 = NULL;
  int result = 0;
  char *compareBase = NULL;
  char *compareWith = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // pop arg 1 - string to split
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      arg1 = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  // pop arg 2 - check what it is to end with
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      arg2 = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  if (strlen(arg2) <= strlen(arg1)) {
    compareBase = arg1;
    compareWith = arg2;

    while (*compareWith && *compareBase && *compareWith == *compareBase) {
      compareBase++;
      compareWith++;
    }

    if (compareWith != arg2 && !*compareWith) {
      result = 1;
    }
  }

  /* Pushing the result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_ends_with(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1 = NULL;
  char *arg2 = NULL;
  int result = 0;
  char *compareBase = NULL;
  char *compareWith = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // pop arg 1 - string to split
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      arg1 = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  // pop arg 2 - check what it is to end with
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      arg2 = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  if (strlen(arg2) <= strlen(arg1)) {
    char *start = arg2;
    compareBase = arg1 + (strlen(arg1) - 1);
    compareWith = arg2 + (strlen(arg2) - 1);

    while (compareWith != start && *compareBase && *compareWith == *compareBase) {
      compareBase--;
      compareWith--;
    }

    if (compareWith == start) {
      result = 1;
    }
  }

  /* Pushing the result */
  PUSH_INT(result, sp, sc);

  return 0;
}
