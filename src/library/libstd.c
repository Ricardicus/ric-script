#include "libstd.h"

int ric_exit(EXPRESSION_PARAMS())
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

int ric_print(EXPRESSION_PARAMS())
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
    case FUNCPTRTYPE:
    printf("<Function: '%s'>\n", stv.func->id.id);
    break;
    case VECTORTYPE:
    {
      print_vector(stv.vec, EXPRESSION_ARGS());
      printf("\n");
    }
    break;
    default: {
      fprintf(stderr, "error: function call 'print' got unexpected data type as argument.\n");
      exit(1);
    }
    break;
  }

  return 0;
}


