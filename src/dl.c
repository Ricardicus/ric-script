#include "dl.h"

int dl_open(const char *lib, dl_handle_t *dl_lib) {
  void *handle = NULL;

  handle = dlopen(lib, RTLD_LAZY);
  if ( !handle ) {
    return -1;
  }

  dlerror();

  dl_lib->hnd = handle;
  return 0;
}

libFunction_t* dl_lookup(dl_handle_t *hnd, const char *sym) {
  if ( hnd->hnd == NULL ) {
    return NULL;
  }
  return (libFunction_t*) dlsym(hnd->hnd, sym);
}

int dl_close(dl_handle_t *hnd) {
  if ( hnd->hnd == NULL ) {
    return -1;
  }
  return dlclose(hnd->hnd);
}
