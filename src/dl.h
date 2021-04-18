#ifndef RIC_DL_H
#define RIC_DL_H

#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

struct dl_handle;
typedef struct dl_handle dl_handle_t;

struct dl_handle {
  void *hnd;
  libFunction_t *funcs;
  int nbr_funcs;
  char *mod_name;
  int mod_ver_maj;
  int mod_ver_min;
};

int dl_open(const char *lib, dl_handle_t *dl_lib);
libFunction_t* dl_lookup(dl_handle_t *hnd, const char *sym);
int dl_close(dl_handle_t *hnd);
void dl_print_mod_info(FILE *stream, const dl_handle_t *hnd);

#endif

