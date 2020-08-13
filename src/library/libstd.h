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
int ric_exit(LIBRARY_PARAMS());

#endif