#ifndef LIBMATH_H
#define LIBMATH_H

/*
 *
 * The idea of this libmath translation unit is
 * adding  math functions to the standard included library
 * of my scripting language
 *
 */

#include <math.h>
#include <string.h>

/* the big integers library, mini-gmp */
#include <mini-gmp.h>

#include "hashtable.h"
#include "ast.h"

int ric_power(LIBRARY_PARAMS());
int ric_log(LIBRARY_PARAMS());
int ric_sqrt(LIBRARY_PARAMS());
int ric_sin(LIBRARY_PARAMS());
int ric_cos(LIBRARY_PARAMS());
int ric_tan(LIBRARY_PARAMS());
int ric_exp(LIBRARY_PARAMS());
int ric_abs(LIBRARY_PARAMS());
int ric_floor(LIBRARY_PARAMS());
int ric_ceil(LIBRARY_PARAMS());
int ric_get_nbr_base_string(LIBRARY_PARAMS());
int ric_get_nbr_base_int(LIBRARY_PARAMS());
int ric_random_uniform(LIBRARY_PARAMS());
int ric_random_uniform_int(LIBRARY_PARAMS());

#endif
