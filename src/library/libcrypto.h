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
#include <md5.h>
#include <blowfish.h>

#include "lib.h"
#include "ast.h"

// Hashing
int ric_sha256(LIBRARY_PARAMS());
int ric_md5(LIBRARY_PARAMS());
// Some binary encodings
int ric_base64_encode(LIBRARY_PARAMS());
int ric_base64_decode(LIBRARY_PARAMS());
int ric_hex_encode(LIBRARY_PARAMS());
int ric_hex_decode(LIBRARY_PARAMS());
// encryption / decryption with blowfish
int ric_blowfish_keys(LIBRARY_PARAMS());
int ric_blowfish_keys_destroy(LIBRARY_PARAMS());
int ric_blowfish_encrypt(LIBRARY_PARAMS());
int ric_blowfish_decrypt(LIBRARY_PARAMS());

#endif
