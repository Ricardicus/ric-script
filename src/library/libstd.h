#ifndef LIBSTD_H
#define LIBSTD_H

/*
*
* The idea of this libstd translation unit is
* adding some basic standard functions included
* in the library of my scripting language
*
*/

#include "hashtable.h"
#include "ast.h"
#include "eval.h"

int ric_print(EXPRESSION_PARAMS());
int ric_exit(EXPRESSION_PARAMS());

#endif