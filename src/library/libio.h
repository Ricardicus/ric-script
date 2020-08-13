#ifndef LIBIO_H
#define LIBIO_H

/*
*
* The idea of this libio translation unit is
* adding FILE IO to the standard included library
* of my scripting language
*
*/

#include "hashtable.h"
#include "ast.h"

int ric_is_file(EXPRESSION_PARAMS());
int ric_open_file(EXPRESSION_PARAMS());
int ric_close_file(EXPRESSION_PARAMS());
int ric_write_file(EXPRESSION_PARAMS());

#endif