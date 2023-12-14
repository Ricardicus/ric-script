#include "libcrypto.h"

int ric_sha256(LIBRARY_PARAMS()) {
  stackval_t stv;
  SHA256_CTX sha256;
  unsigned char buf[SHA256_BLOCK_SIZE];
  unsigned char *stringArg = NULL;
  rawdata_t *rawdata = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  char *result = NULL;
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      stringArg = (unsigned char*)stv.t;
      break;
    case RAWDATATYPE:
      rawdata = stv.rawdata;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, string or data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }
 
  result = ast_ecalloc(SHA256_BLOCK_SIZE * 2 + 1);

  sha256_init(&sha256);
  if (stringArg != NULL) {
    sha256_update(&sha256, stringArg, strlen((char*)stringArg));
  } else if (rawdata != NULL) {
    sha256_update(&sha256, rawdata->data, rawdata->size);
  }
  sha256_final(&sha256, buf);
  for ( int i = 0; i < SHA256_BLOCK_SIZE; i++ ) {
    sprintf(result + (i * 2), "%02x", buf[i]);
  }

  /* Pushing the parsed value */
  PUSH_STRING(result, sp, sc);

  return 0;
}
