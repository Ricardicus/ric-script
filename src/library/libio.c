#include "libio.h"

int ric_is_file(LIBRARY_PARAMS())
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
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
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

int ric_open_file(LIBRARY_PARAMS())
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
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
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


int ric_close_file(LIBRARY_PARAMS())
{
  stackval_t stv;
  FILE *fp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
    fp = (FILE*)stv.p;
    break;
    default:{
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, pointer expected.\n",
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

int ric_write_file(LIBRARY_PARAMS())
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
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, pointer expected.\n",
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
    default:{
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
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

