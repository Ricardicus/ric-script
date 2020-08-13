#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

hashtable_t *libCallbacks = NULL;

/* The ric library */
libFunction_t ric_library[] = {
  // libstd
  DECLARE_LIB_FUNCTION("exit", 1, ric_exit),
  DECLARE_LIB_FUNCTION("print", 1, ric_print),
  // libstring
  DECLARE_LIB_FUNCTION("parseInt", 1, ric_atoi),
  // libio
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

