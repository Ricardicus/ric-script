#ifndef LIBSTRING_H
#define LIBSTRING_H

/*
 *
 * The idea of this libstd translation unit is
 * adding some basic string functions included
 * in the library of my scripting language
 *
 */

#include <ctype.h>

#include "lib.h"
#include "hashtable.h"
#include "ast.h"
#include <ctype.h>

int ric_atoi(LIBRARY_PARAMS());
int ric_char_code(LIBRARY_PARAMS());
int ric_split(LIBRARY_PARAMS());
int ric_to_upper(LIBRARY_PARAMS());
int ric_to_lower(LIBRARY_PARAMS());
int ric_ends_with(LIBRARY_PARAMS());
int ric_starts_with(LIBRARY_PARAMS());
int ric_trim(LIBRARY_PARAMS());

#endif
