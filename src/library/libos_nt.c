#include "libos.h"
#include <synchapi.h>

int ric_sleep(LIBRARY_PARAMS())
{
  stackval_t stv;
  int32_t sleepTime = 0;  // Sleep time is seconds

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    sleepTime = stv.i;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, integer expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  Sleep((unsigned int)sleepTime*1000);

  /* Pushing zero */
  PUSH_INT(0, sp, sc);

  return 0;
}

