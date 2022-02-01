#include "libio.h"

int ric_open_file(LIBRARY_PARAMS()) {
  stackval_t stv;
  FILE *fp;
  char *filename = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      filename = stv.t;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, string expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  /* Check if file exist, if it doesn't create it */
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fp = fopen(filename, "w");
  } else {
    fclose(fp);
    fp = fopen(filename, "r+");
  }

  if (fp == NULL) {
    // Failed to open such a file
    // Pushing the result 1
    PUSH_INT(1, sp, sc);
    return 0;
  }

  /* Pushing file pointer */
  PUSH_POINTER(((uintptr_t)fp), sp, sc);

  return 0;
}

int ric_close_file(LIBRARY_PARAMS()) {
  stackval_t stv;
  FILE *fp;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
      fp = (FILE *)stv.p;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, pointer expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  fclose(fp);

  /* Pushing 0, as in OK */
  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_read_file(LIBRARY_PARAMS()) {
  stackval_t stv;
  FILE *fp;
  size_t datasize = 0;
  expr_t *e;
  size_t readBytes = 0;
  int dummy;
  heapval_t *hpv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
      fp = (FILE *)stv.p;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, pointer expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      datasize = (size_t)stv.i;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, integer expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  e = newExpr_RawData(datasize);

  readBytes = fread(e->rawdata->data, 1, e->rawdata->size, fp);

  if (readBytes != e->rawdata->size) {
    e->rawdata->size = readBytes;
  }

  stv.type = RAWDATATYPE;
  stv.rawdata = e->rawdata;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the raw data read */
  PUSH_RAWDATA(stv.rawdata, sp, sc);

  free(e);

  return 0;
}

int ric_write_file(LIBRARY_PARAMS()) {
  stackval_t stv;
  FILE *fp;
  char *text = NULL;
  rawdata_t *rawdata = NULL;
  int backslash = 0;
  char *c;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
      fp = (FILE *)stv.p;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, pointer expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      text = stv.t;
      break;
    case RAWDATATYPE:
      rawdata = stv.rawdata;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, string expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  if (text != NULL) {
    /* Parsing the string, some character combos: '\r', '\n' should be interpreted disctincly */
    c = text;
    while (*c) {

      if (!backslash && *c == '\\') {
        backslash = 1;
        ++c;
        continue;
      }

      if (backslash) {
        switch (*c) {
          case 'n':
            // Print a new line
            fprintf(fp, "\n");
            break;
          case 'r':
            // print the other one windows likes
            fprintf(fp, "\r");
            break;
          case '\\':
            // print a backslash
            fprintf(fp, "\\");
            break;
          case 't':
            // print a tab
            fprintf(fp, "\t");
            break;
          default:
            // Ignoring this backslashed one, since I don't understand it..
            break;
        }
      } else {
        fputc(*c, fp);
      }

      ++c;
      backslash = 0;
    }
  } else if (rawdata != NULL) {
    /* Write raw data to file */
    fwrite(rawdata->data, 1, rawdata->size, fp);
  }

  /* Pushing 0, as in OK */
  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_read_lines_file(LIBRARY_PARAMS()) {
  stackval_t stv;
  expr_t *vec = NULL;
  argsList_t *vecContent = NULL;
  FILE *fp = NULL;
  char *buffer = NULL;
  heapval_t *hpv;
  int dummy;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
      fp = (FILE *)stv.p;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, pointer expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  buffer = calloc(MAX_LINE_LENGTH, 1);
  if (buffer == NULL) {
    fprintf(stderr, "%s error: Memory allocation failed\n", LIBRARY_FUNC_NAME());
    exit(1);
  }

  while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
    /* Take the remaining part also */
    expr_t *e;
    argsList_t *a;
    e = newExpr_Text(buffer);
    a = newArgument(e, vecContent);
    vecContent = a;
    memset(buffer, 0, MAX_LINE_LENGTH);
  }

  /* Reset file pointer */
  fseek(fp, 0, SEEK_SET);

  free(buffer);

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

int ric_read_input(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *t = NULL;
  char *inputText = NULL;
  char *buffer = NULL;
  char *c = NULL;
  heapval_t *hpv;
  int dummy;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      inputText = stv.t;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, pointer expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  buffer = calloc(MAX_LINE_LENGTH, 1);
  if (buffer == NULL) {
    fprintf(stderr, "%s error: Memory allocation failed\n", LIBRARY_FUNC_NAME());
    exit(1);
  }

  printf("%s", inputText);

  if (fgets(buffer, MAX_LINE_LENGTH, stdin) != NULL) {
    /* Take the remaining part also */
    c = strchr(buffer, '\r');
    if (c != NULL) {
      *c = 0;
    }
    c = strchr(buffer, '\n');
    if (c != NULL) {
      *c = 0;
    }

    t = calloc(strlen(buffer) + 1, 1);
    if (t == NULL) {
      fprintf(stderr, "%s error: Memory allocation failed\n", LIBRARY_FUNC_NAME());
      exit(1);
    }
    snprintf(t, strlen(buffer) + 1, "%s", buffer);
  }

  free(buffer);

  stv.type = TEXT;
  stv.t = t;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the parsed value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}
