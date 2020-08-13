#include "libstring.h"

int ric_atoi(EXPRESSION_PARAMS())
{
  stackval_t stv;
  char *string = NULL;
  int result = 0;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    string = stv.t;
    break;
    default:{
      fprintf(stderr, "error: function call 'parseInt' got unexpected data type as argument, string expected.\n");
      exit(1);
    }
    break;
  }

  result = atoi(string);
  
  /* Pushing file pointer */
  PUSH_INT(result, sp, sc);

  return 0;
}