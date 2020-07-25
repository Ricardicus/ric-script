#include <assert.h>
#include <stdlib.h>

#include "lib.h"

hashtable_t *libCallbacks = NULL;

int ric_exit(void **sp, size_t *sc)
{
  stackval_t stv;
  int exitCode = 0;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    exitCode = (int) stv.i;
    break;
    default:{
      fprintf(stderr, "error: function call 'exit' expects a single integer as argument.\n");
      exit(1);
    }
    break;
  }

  exit(exitCode);
  return 1;
}

int ric_print(void **sp, size_t *sc)
{
  stackval_t stv;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT: 
    {
      char *c = stv.t;
      int backslash = 0;

      /* 
      * Parsing the string,
      * some character combos (such as: '\r','\n)
      * should be interpreted disctincly
      */
      while ( *c ) {

        if ( !backslash && *c == '\\' ) {
          backslash = 1;
          ++c;
          continue;
        }

        if ( backslash ) {
          switch (*c) {
          case 'n':
          // Print a new line
          printf("\n");
          break;
          case 'r':
          // print the other one windows likes
          printf("\r");
          break;
          case '\\':
          // print a backslash
          printf("\\");
          break;
          case 't':
          // print a tab
          printf("\t");
          break;
          default:
          // Ignoring this backslashed one, since I don't understand it..
          break;
          }
        } else {
          printf("%c", *c);
        }

        ++c;
        backslash = 0;
      }

      // end with new line
      printf("\n");
    }
    break;
    case INT32TYPE:
    printf("%d\n", stv.i);
    break;
    case DOUBLETYPE:
    printf("%lf\n", stv.d);
    break;
    case POINTERTYPE:
    printf("<%" PRIuPTR ">\n", stv.p);
    break;
    default: {
      fprintf(stderr, "error: function call 'print' got unexpected data type as argument.\n");
      exit(1);
    }
    break;
  }

  return 0;
}

int ric_is_file(void **sp, size_t *sc)
{
  stackval_t stv;
  FILE *fp;
  char *filename = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    filename = stv.t;
    break;
    default:{
      fprintf(stderr, "error: function call 'isFile' got unexpected data type as argument, string expected.\n");
      exit(1);
    }
    break;
  }

  fp = fopen(filename, "r");

  if ( fp != NULL ) {
    // There is such a file
    fclose(fp);
    // Pushing the result 1
    PUSH_INT(1, sp, sc);
  } else {
    // There is no such file, pushing the result 0
    PUSH_INT(0, sp, sc);
  }

  return 0;
}

int ric_open_file(void **sp, size_t *sc)
{
  stackval_t stv;
  FILE *fp;
  char *filename = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    filename = stv.t;
    break;
    default:{
      fprintf(stderr, "error: function call 'openFile' got unexpected data type as argument, string expected.\n");
      exit(1);
    }
    break;
  }

  fp = fopen(filename, "w+");

  if ( fp == NULL ) {
    // Failed to open such a file
    // Pushing the result 1
    PUSH_INT(1, sp, sc);
    return 0;
  }

  /* Pushing file pointer */
  PUSH_POINTER(((uintptr_t)fp), sp, sc);

  return 0;
}

int ric_close_file(void **sp, size_t *sc)
{
  stackval_t stv;
  FILE *fp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
    fp = (FILE*)stv.p;
    break;
    default:{
      fprintf(stderr, "error: function call 'closeFile' got unexpected data type as argument, pointer expected.\n");
      exit(1);
    }
    break;
  }

  fclose(fp);

  /* Pushing 0, as in OK */
  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_write_file(void **sp, size_t *sc)
{
  stackval_t stv;
  FILE *fp;
  char *text = NULL;
  int backslash = 0;
  char *c;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
    fp = (FILE*)stv.p;
    break;
    default:{
      fprintf(stderr, "error: function call 'writeFile' got unexpected data type as argument, pointer expected.\n");
      exit(1);
    }
    break;
  }

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    text = stv.t;
    break;
    default:{
      fprintf(stderr, "error: function call 'writeFile' got unexpected data type as argument, string expected.\n");
      exit(1);
    }
    break;
  }

  /* Parsing the string, some character combos: '\r', '\n' should be interpreted disctincly */
  c = text;
  while ( *c ) {

    if ( !backslash && *c == '\\' ) {
      backslash = 1;
      ++c;
      continue;
    }

    if ( backslash ) {
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

  /* Pushing 0, as in OK */
  PUSH_INT(0, sp, sc);

  return 0;
}

/* The ric library */
libFunction_t ric_library[] = {
  DECLARE_LIB_FUNCTION("exit", 1, ric_exit),
  DECLARE_LIB_FUNCTION("print", 1, ric_print),
  DECLARE_LIB_FUNCTION("isFile", 1, ric_is_file),
  DECLARE_LIB_FUNCTION("fileOpen", 1, ric_open_file),
  DECLARE_LIB_FUNCTION("fileClose", 1, ric_close_file),
  DECLARE_LIB_FUNCTION("fileWrite", 2, ric_write_file)
};

void initialize_ric_lib() {
  size_t i = 0;
  size_t libFuncs = sizeof(ric_library) / sizeof(*ric_library);
  libCallbacks = hashtable_new(100, 0.8);
  assert(libCallbacks != NULL);

  while ( i < libFuncs ) {
    libFunction_t *func = &ric_library[i];
    hashtable_put(libCallbacks, func->libFuncName, func);
    ++i;
  }
}

libFunction_t* look_up_lib(char *id) {
  if ( libCallbacks == NULL ) {
    return NULL;
  }
  return (libFunction_t*) hashtable_get(libCallbacks, id);
}

