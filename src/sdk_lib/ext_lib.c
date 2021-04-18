#include "ext_lib.h"

int ric_example_print(LIBRARY_PARAMS())
{
  stackval_t stv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

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
#ifdef _WIN32
          printf("\\t");
#else
          // print a tab
          printf("\t");
#endif
          break;
          default:
#ifdef _WIN32
          printf("%c", *c);
#endif
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
    case TIMETYPE: {
      struct tm *info;
      if ( stv.time < 0 ) {
        /* Relative time to now */
        time_t nowTime;
        time_t result;
        time(&nowTime);
        result = nowTime + stv.time;
        info = localtime( &result );
      } else {
        info = localtime( &stv.time );
      }
      printf("%s\n", asctime(info));
      break;
    }
    case DOUBLETYPE:
    printf("%lf\n", stv.d);
    break;
    case CLASSTYPE: {
      if ( ! stv.classObj->initialized ) {
        printf("<Class: '%s'>\n", stv.classObj->id);
      } else {
        printf("<Class object: '%s'>\n", stv.classObj->id);
      }
    }
    break;
    case POINTERTYPE:
    printf("<%" PRIuPTR ">\n", stv.p);
    break;
    case DICTTYPE: {
      printf("DICTIONARY..\n");
      break;
    }
    case FUNCPTRTYPE:
    printf("<Function: '%s'>\n", stv.func->id.id);
    break;
    case VECTORTYPE:
    {
      printf("VECTOR...\n");
    }
    break;
    case RAWDATATYPE:
    {
      size_t i = 0;
      while ( i < stv.rawdata->size ) {
        printf("%c", ((char*)stv.rawdata->data)[i]);
        ++i;
      }
      printf("\n");
    }
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  return 0;
}

MARK_EXPORT libFunction_t EXPORT_FUNCTION_LIST[] = {
  DECLARE_LIB_FUNCTION("ric_example_print", 1, ric_example_print)
};

EXPORT_MODULE("example_ric");
