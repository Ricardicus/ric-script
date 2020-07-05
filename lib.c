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
      fprintf(stderr, "error: function call exit expects a single integer as argument.\n");
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
  char *print_string = 0;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    print_string = stv.t;
    printf("%s\n", print_string);
    break;
    default:{
      fprintf(stderr, "error: function call exit expects a single string as argument.\n");
      exit(1);
    }
    break;
  }

  return 0;
}

/* The ric library */
libFunction_t ric_library[] = {
  DECLARE_LIB_FUNCTION("exit", 1, ric_exit),
  DECLARE_LIB_FUNCTION("print", 1, ric_print)
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

