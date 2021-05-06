#include "ext_lib.h"

int ric_example_print(LIBRARY_PARAMS())
{
  stackval_t stv;
  /* Getting the stack pointer */
  void *sp = PROVIDE_CONTEXT()->sp;
  /* Getting the stack count */
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Read the argument from the stack */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT: 
    {
      printf("%s\n", stv.t);
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
      /* Walking through the vector */
      vector_t *vec = stv.vec;
      argsList_t *content = vec->content;
      size_t i = 0;

      i = 0;
      printf("[");
      while ( content != NULL ) {
        /* Evaluate the expression */
        EVAL_EXPRESSION(content->arg);
        POP_VAL(&stv, sp, sc);

        if ( i > 0 ) {
          printf(", ");
        }

        switch (stv.type) {
        case TEXT: 
        printf("%s", stv.t);
        break;
        case INT32TYPE:
        printf("%d", stv.i);
        break;
        case DOUBLETYPE:
        printf("%lf", stv.d);
        break;
        default:
          printf("<other>");
          break;
        }
        ++i;
        content = content->next;
      }
      printf("]\n");
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

  /* Return the number 1337 */
  PUSH_INT(1337, sp, sc);

  return 0;
}

MARK_EXPORT libFunction_t EXPORT_FUNCTION_LIST[] = {
  DECLARE_LIB_FUNCTION("ric_example_print", 1, ric_example_print)
};

EXPORT_MODULE("example_ric");
