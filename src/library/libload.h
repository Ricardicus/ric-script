#ifndef LIBLOAD_H
#define LIBLOAD_H

/*
 *
 * The idea of this libio translation unit is
 * adding FILE IO to the standard included library
 * of my scripting language
 *
 */

#include "hashtable.h"
#include "ast.h"
#include "hooks.h"
#include "eval.h"

int ric_load(LIBRARY_PARAMS());

#endif
