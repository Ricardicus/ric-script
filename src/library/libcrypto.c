#include "libcrypto.h"

#include <ctype.h>

int ric_sha256(LIBRARY_PARAMS()) {
  stackval_t stv;
  SHA256_CTX sha256;
  unsigned char buf[SHA256_BLOCK_SIZE];
  unsigned char *stringArg = NULL;
  rawdata_t *rawdata = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      stringArg = (unsigned char *)stv.t;
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

  sha256_init(&sha256);
  if (stringArg != NULL) {
    sha256_update(&sha256, stringArg, strlen((char *)stringArg));
  } else if (rawdata != NULL) {
    sha256_update(&sha256, rawdata->data, rawdata->size);
  }

  sha256_final(&sha256, buf);

  if (stringArg != NULL) {
    char *result = ast_ecalloc(SHA256_BLOCK_SIZE * 2 + 1);
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
      sprintf(result + (i * 2), "%02x", buf[i]);
    }

    /* Pushing the parsed value */
    PUSH_STRING(result, sp, sc);
  } else if (rawdata != NULL) {
    heapval_t *hpv;
    int dummy;
    void *hp = PROVIDE_CONTEXT()->hp;
    expr_t *e = newExpr_RawData(SHA256_BLOCK_SIZE);

    memcpy(e->rawdata->data, buf, SHA256_BLOCK_SIZE);
    stv.type = RAWDATATYPE;
    stv.rawdata = e->rawdata;
    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    free(e);

    PUSH_RAWDATA(stv.rawdata, sp, sc);
  }

  return 0;
}

int ric_md5(LIBRARY_PARAMS()) {
  stackval_t stv;
  MD5_CTX md5ctx;
  unsigned char buf[MD5_BLOCK_SIZE];
  unsigned char *stringArg = NULL;
  rawdata_t *rawdata = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      stringArg = (unsigned char *)stv.t;
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

  md5_init(&md5ctx);
  if (stringArg != NULL) {
    md5_update(&md5ctx, stringArg, strlen((char *)stringArg));
  } else if (rawdata != NULL) {
    md5_update(&md5ctx, rawdata->data, rawdata->size);
  }

  md5_final(&md5ctx, buf);
  if (stringArg != NULL) {
    char *result = ast_ecalloc(MD5_BLOCK_SIZE * 2 + 1);
    for (int i = 0; i < MD5_BLOCK_SIZE; i++) {
      sprintf(result + (i * 2), "%02x", buf[i]);
    }
    stv.type = TEXT;
    stv.t = result;

    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    /* Pushing the parsed value */
    PUSH_STRING(result, sp, sc);
  } else if (rawdata != NULL) {
    heapval_t *hpv;
    int dummy;
    expr_t *e = newExpr_RawData(MD5_BLOCK_SIZE);

    memcpy(e->rawdata->data, buf, MD5_BLOCK_SIZE);
    stv.type = RAWDATATYPE;
    stv.rawdata = e->rawdata;
    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    free(e);

    PUSH_RAWDATA(stv.rawdata, sp, sc);
  }

  return 0;
}

int ric_base64_decode(LIBRARY_PARAMS()) {
  stackval_t stv;
  unsigned char *result = NULL;
  char *stringArg = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  size_t input_length;
  size_t output_length;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;
  expr_t *e = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      stringArg = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  input_length = strlen(stringArg);
  output_length = base64_decode((unsigned char *)stringArg, NULL, input_length);
  result = ast_ecalloc(output_length);

  (void)base64_decode((unsigned char *)stringArg, result, input_length);

  e = newExpr_RawData(output_length);
  free(e->rawdata->data);
  e->rawdata->data = result;

  stv.type = RAWDATATYPE;
  stv.rawdata = e->rawdata;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(e);

  PUSH_RAWDATA(stv.rawdata, sp, sc);

  return 0;
}

int ric_base64_encode(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *stringArg = NULL;
  rawdata_t *rawdata = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  size_t input_length;
  size_t output_length;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      stringArg = stv.t;
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

  if (stringArg != NULL) {
    unsigned char *result = NULL;

    /* Pushing the parsed value */
    input_length = strlen(stringArg);
    output_length = base64_encode((unsigned char *)stringArg, NULL, input_length, 1) + 1;
    result = ast_ecalloc(output_length);

    (void)base64_encode((unsigned char *)stringArg, result, input_length, 1);

    stv.type = TEXT;
    stv.t = (char *)result;

    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    PUSH_STRING((char *)result, sp, sc);
  } else if (rawdata != NULL) {
    unsigned char *result = NULL;

    /* Pushing the parsed value */
    input_length = rawdata->size;
    output_length = base64_encode(rawdata->data, NULL, input_length, 1) + 1;
    result = ast_ecalloc(output_length);

    (void)base64_encode(rawdata->data, result, input_length, 1);

    stv.type = TEXT;
    stv.t = (char *)result;

    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    PUSH_STRING((char *)result, sp, sc);
  }

  return 0;
}

int ric_hex_decode(LIBRARY_PARAMS()) {
  stackval_t stv;
  unsigned char *result = NULL;
  char *stringArg = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  size_t input_length;
  size_t output_length;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;
  expr_t *e = NULL;
  size_t i = 0;
  char value;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      stringArg = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function call '%s' got unexpected data type as argument, string expected.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  input_length = strlen(stringArg);
  output_length = input_length / 2;
  result = ast_ecalloc(output_length);

  value = 0;
  while (i < input_length) {
    int q = i % 2;
    int v = 0;
    char c = tolower(stringArg[i]);

    if (c >= 'a' && c <= 'z') {
      v = c - 'a' + 10;
    } else if (c >= '0' && c <= '9') {
      v = c - '0';
    }

    if (q == 0) {
      value = v;
    } else {
      value = (value << 4) + v;
      result[i / 2] = value;
    }

    ++i;
  }

  e = newExpr_RawData(output_length);
  free(e->rawdata->data);
  e->rawdata->data = result;

  stv.type = RAWDATATYPE;
  stv.rawdata = e->rawdata;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(e);

  PUSH_RAWDATA(stv.rawdata, sp, sc);

  return 0;
}

int ric_hex_encode(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *stringArg = NULL;
  rawdata_t *rawdata = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      stringArg = stv.t;
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

  if (stringArg != NULL) {
    size_t len = strlen(stringArg);
    size_t i;
    char *result = ast_ecalloc(len * 2 + 1);

    for (i = 0; i < len; i++) {
      sprintf(&result[i * 2], "%02x", (unsigned char)stringArg[i]);
    }

    stv.type = TEXT;
    stv.t = result;

    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    PUSH_STRING((char *)result, sp, sc);
  } else if (rawdata != NULL) {
    size_t len = rawdata->size;
    size_t i;
    char *result = ast_ecalloc(len * 2 + 1);

    for (i = 0; i < len; i++) {
      sprintf(&result[i * 2], "%02x", ((unsigned char *)rawdata->data)[i]);
    }

    stv.type = TEXT;
    stv.t = result;

    ALLOC_HEAP(&stv, hp, &hpv, &dummy);

    PUSH_STRING((char *)result, sp, sc);
  }

  return 0;
}
