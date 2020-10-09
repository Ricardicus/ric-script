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
int ric_ls(LIBRARY_PARAMS());
int ric_cd(LIBRARY_PARAMS());

#endif

