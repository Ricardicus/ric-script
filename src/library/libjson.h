#ifndef LIBJSON_H
#define LIBJSON_H

/*
*
* The idea of this libjson translation unit is
* adding some basic JSON parsing to support this
* data format in the standard library
*
*/

#include <cJSON.h>

#include "lib.h"
#include "dl.h"
#include "hashtable.h"
#include "ast.h"
#include "eval.h"

int ric_json_load(LIBRARY_PARAMS());

#endif
