#include "dl.h"

#include <windows.h>

int dl_open(const char *lib, dl_handle_t *dl_lib) {
  char **mod_name = NULL;
  int *mod_ver = NULL;
  exportModSizeFunc_t sizeFunc;
  libFunction_t *funcList;
  HMODULE m = LoadLibrary(lib);

  if (m == NULL) {
    return -1;
  }
  dl_lib->hnd = m;

  mod_name = (char **)GetProcAddress(dl_lib->hnd, EXPORT_STR(EXPORT_MOD_NAME));

  if (mod_name == NULL) {
    return -1;
  }
  dl_lib->mod_name = *mod_name;

  sizeFunc = (exportModSizeFunc_t)GetProcAddress(dl_lib->hnd, EXPORT_STR(EXPORT_MOD_NBR_FUNCS));
  if (sizeFunc == NULL) {
    printf("failed to find %d\n", __LINE__);
    return -1;
  }
  dl_lib->nbr_funcs = (sizeFunc)();

  funcList = (libFunction_t *)GetProcAddress(dl_lib->hnd, EXPORT_STR(EXPORT_FUNCTION_LIST));
  if (funcList == NULL) {
    printf("failed to find %d\n", __LINE__);
    return -1;
  }
  dl_lib->funcs = funcList;

  mod_ver = (int *)GetProcAddress(dl_lib->hnd, EXPORT_STR(EXPORT_VERSION_SYM_MAJ));
  if (mod_ver == NULL) {
    printf("failed to find %d\n", __LINE__);

    return -1;
  }
  dl_lib->mod_ver_maj = *mod_ver;

  mod_ver = (int *)GetProcAddress(dl_lib->hnd, EXPORT_STR(EXPORT_VERSION_SYM_MIN));
  if (mod_ver == NULL) {
    printf("failed to find %d\n", __LINE__);

    return -1;
  }
  dl_lib->mod_ver_min = *mod_ver;

  return 0;
}

libFunction_t *dl_lookup(dl_handle_t *hnd, const char *sym) {
  if (hnd->hnd == NULL) {
    return NULL;
  }
  return (libFunction_t *)GetProcAddress(hnd->hnd, sym);
}

int dl_close(dl_handle_t *hnd) {
  if (hnd->hnd == NULL) {
    return -1;
  }
  return FreeLibrary(hnd->hnd);
}

void dl_print_mod_info(FILE *stream, const dl_handle_t *hnd) {
  int i;
  if (hnd == NULL) {
    return;
  }

  if (hnd->mod_name == NULL) {
    return;
  }

  fprintf(stream, "Module    : %s\n", hnd->mod_name);
  fprintf(stream, "Nbr funcs : %d\n", hnd->nbr_funcs);
  fprintf(stream, "Version   : %d.%d\n", hnd->mod_ver_maj, hnd->mod_ver_min);

  i = 0;
  while (i < hnd->nbr_funcs) {
    libFunction_t f = hnd->funcs[i];
    printf("  %s ( %d )\n", f.libFuncName, f.nbrArgs);
    i++;
  }
}
