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

int ric_blowfish_keys(LIBRARY_PARAMS()) {
  stackval_t stv;
  unsigned char *user_key;
  size_t user_key_len = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  BLOWFISH_KEY *key = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      user_key = (unsigned char *)stv.t;
      user_key_len = strlen(stv.t);
      break;
    case RAWDATATYPE:
      user_key = (unsigned char *)stv.rawdata->data;
      user_key_len = stv.rawdata->size;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, string or data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  key = ast_ecalloc(sizeof(BLOWFISH_KEY));
  blowfish_key_setup(user_key, key, user_key_len);

  PUSH_POINTER((uintptr_t)key, sp, sc);

  return 0;
}

int ric_blowfish_encrypt(LIBRARY_PARAMS()) {
  stackval_t stv;
  unsigned char *data_in;
  unsigned char *data_in_buf = NULL;
  size_t data_in_len = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  BLOWFISH_KEY *key = NULL;
  BYTE block[BLOWFISH_BLOCK_SIZE];
  BYTE *data_out = NULL;
  size_t data_out_len = 0;
  size_t i;
  expr_t *e = NULL;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
      key = (BLOWFISH_KEY *)stv.p;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, pointer to blowfish key expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      data_in = (unsigned char *)stv.t;
      data_in_len = strlen(stv.t);
      break;
    case RAWDATATYPE:
      data_in = (unsigned char *)stv.rawdata->data;
      data_in_len = stv.rawdata->size;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, text or raw data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  data_out_len = data_in_len + (8 - data_in_len % 8) % 8;
  data_out = ast_ecalloc(data_out_len);

  data_in_buf = ast_ecalloc(data_out_len);
  memcpy(data_in_buf, data_in, data_in_len);

  for (i = 0; i < data_out_len / BLOWFISH_BLOCK_SIZE; ++i) {
    memcpy(block, data_in_buf + i * BLOWFISH_BLOCK_SIZE,
           BLOWFISH_BLOCK_SIZE); // Copy 8 bytes into the block
    blowfish_encrypt(block, data_out + i * BLOWFISH_BLOCK_SIZE, key); // Encrypt the block
  }

  free(data_in_buf);

  e = newExpr_RawData(data_out_len);
  free(e->rawdata->data);
  stv.type = RAWDATATYPE;
  stv.rawdata = e->rawdata;
  stv.rawdata->data = data_out;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(e);

  PUSH_RAWDATA(stv.rawdata, sp, sc);

  return 0;
}

int ric_blowfish_decrypt(LIBRARY_PARAMS()) {
  stackval_t stv;
  unsigned char *data_in;
  size_t data_in_len = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  BLOWFISH_KEY *key = NULL;
  BYTE block[BLOWFISH_BLOCK_SIZE];
  BYTE *data_out = NULL;
  size_t data_out_len = 0;
  size_t i;
  expr_t *e = NULL;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
      key = (BLOWFISH_KEY *)stv.p;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, pointer to blowfish key expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case RAWDATATYPE:
      data_in = (unsigned char *)stv.rawdata->data;
      data_in_len = stv.rawdata->size;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, raw data expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  data_out_len = data_in_len + (8 - data_in_len % 8) % 8;
  data_out = ast_ecalloc(data_out_len);

  for (i = 0; i < data_in_len / BLOWFISH_BLOCK_SIZE; ++i) {
    memcpy(block, data_in + i * BLOWFISH_BLOCK_SIZE,
           BLOWFISH_BLOCK_SIZE); // Copy 8 bytes into the block
    blowfish_decrypt(block, data_out + i * BLOWFISH_BLOCK_SIZE, key); // Encrypt the block
  }

  // Handle any remaining bytes if the data_in length is not a multiple of 8
  if (data_in_len % BLOWFISH_BLOCK_SIZE != 0) {
    memset(block, 0, BLOWFISH_BLOCK_SIZE); // Clear the block
    memcpy(block, data_in + i * BLOWFISH_BLOCK_SIZE,
           data_in_len % BLOWFISH_BLOCK_SIZE);                        // Copy remaining bytes
    blowfish_decrypt(block, data_out + i * BLOWFISH_BLOCK_SIZE, key); // Encrypt the block
  }

  e = newExpr_RawData(data_out_len);
  free(e->rawdata->data);
  stv.type = RAWDATATYPE;
  stv.rawdata = e->rawdata;
  stv.rawdata->data = data_out;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(e);

  PUSH_RAWDATA(stv.rawdata, sp, sc);

  return 0;
}

int ric_blowfish_keys_destroy(LIBRARY_PARAMS()) {
  stackval_t stv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  BLOWFISH_KEY *key = NULL;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case POINTERTYPE:
      key = (BLOWFISH_KEY *)stv.p;
      break;
    default: {
      fprintf(
          stderr,
          "error: function call '%s' got unexpected data type as argument, pointer to blowfish key expected.\n",
          LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  free(key);

  return 0;
}
