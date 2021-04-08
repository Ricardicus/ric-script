#include "dl.h"

int dl_open(const char *lib, dl_handle_t *dl_lib) {
  void *handle = NULL;
  char **mod_name = NULL;
  exportModSizeFunc_t sizeFunc;
  libFunction_t *funcList;

  handle = dlopen(lib, RTLD_LAZY);
  if ( !handle ) {
    return -1;
  }

  dlerror();

  dl_lib->hnd = handle;
  mod_name = (char**) dlsym(dl_lib->hnd, str(EXPORT_MOD_NAME));
  if ( mod_name != NULL ) {
    dl_lib->mod_name = *mod_name;
  }
  sizeFunc = (exportModSizeFunc_t) dlsym(dl_lib->hnd, str(EXPORT_MOD_NBR_FUNCS));
  if ( sizeFunc != NULL ) {
    dl_lib->nbr_funcs = (sizeFunc)();
  }
  funcList = (libFunction_t*) dlsym(dl_lib->hnd, str(EXPORT_FUNCTION_LIST));
  if ( funcList != NULL ) {
    dl_lib->funcs = funcList;
  } else {
    printf("IS EMPTY\n");
  }

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

void dl_print_mod_info(FILE *stream, const dl_handle_t *hnd) {
  int i;
  if ( hnd == NULL ) {
    return;
  }
  fprintf(stream, "Module Name: %s\n", hnd->mod_name);
  fprintf(stream, "Nbr funcs:   %d\n", hnd->nbr_funcs);

  i = 0;
  while ( i < hnd->nbr_funcs ) {
    libFunction_t f = hnd->funcs[i];
    printf("  %s ( %d )\n", f.libFuncName, f.nbrArgs);
    i++;
  }
}