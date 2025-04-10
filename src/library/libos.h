#ifndef LIBOS_H
#define LIBOS_H

/*
 *
 * The idea of this libio translation unit is
 * adding FILE IO to the standard included library
 * of my scripting language
 *
 */

#include "hashtable.h"
#include "ast.h"

int ric_sleep(LIBRARY_PARAMS());
int ric_is_directory(LIBRARY_PARAMS());
int ric_is_file(LIBRARY_PARAMS());
int ric_ls(LIBRARY_PARAMS());
int ric_cd(LIBRARY_PARAMS());
int ric_rm(LIBRARY_PARAMS());
int ric_os_name(LIBRARY_PARAMS());
int ric_mkdir(LIBRARY_PARAMS());
int ric_find_files(LIBRARY_PARAMS());
int ric_env_keys(LIBRARY_PARAMS());

#endif
