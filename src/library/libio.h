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

int ric_is_file(LIBRARY_PARAMS());
int ric_open_file(LIBRARY_PARAMS());
int ric_close_file(LIBRARY_PARAMS());
int ric_write_file(LIBRARY_PARAMS());

#endif

