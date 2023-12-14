#ifndef LIBCRYPTO_H
#define LIBCRYPTO_H

/*
 *
 * The idea of this libjson translation unit is
 * adding some basic JSON parsing to support this
 * data format in the standard library
 *
 */

#include <sha256.h>
#include <base64.h>

#include "lib.h"
#include "ast.h"

int ric_sha256(LIBRARY_PARAMS());

#endif
