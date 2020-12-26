#ifndef LIBSTD_H
#define LIBSTD_H

/*
*
* The idea of this libstd translation unit is
* adding some basic standard functions included
* in the library of my scripting language
*
*/

#include "lib.h"
#include "hashtable.h"
#include "ast.h"
#include "eval.h"

int ric_print(LIBRARY_PARAMS());
int ric_printf(LIBRARY_PARAMS());
int ric_exit(LIBRARY_PARAMS());
int ric_append(LIBRARY_PARAMS());
int ric_len(LIBRARY_PARAMS());
int ric_contains(LIBRARY_PARAMS());
int ric_keys(LIBRARY_PARAMS());
int ric_is_defined(LIBRARY_PARAMS());
int ric_help(LIBRARY_PARAMS());
int ric_type(LIBRARY_PARAMS());
int ric_type_text(LIBRARY_PARAMS());
int ric_create_list(LIBRARY_PARAMS());
int ric_create_data(LIBRARY_PARAMS());
int ric_create_text(LIBRARY_PARAMS());

#endif

