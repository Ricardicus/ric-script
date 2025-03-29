#include "librequests.h"

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable.h"
#include "ast.h"
#include "eval.h"

typedef struct {
  char *data;
  size_t size;
} ResponseBuffer;

static size_t curlWriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t totalSize = size * nmemb;
  ResponseBuffer *mem = (ResponseBuffer *)userp;

  char *ptr = realloc(mem->data, mem->size + totalSize + 1);
  if (ptr == NULL) return 0; // out of memory

  mem->data = ptr;
  memcpy(&(mem->data[mem->size]), contents, totalSize);
  mem->size += totalSize;
  mem->data[mem->size] = 0;

  return totalSize;
}

static CURLcode perform_http_request(const char *url, const char *method, int headers_len,
                                     struct curl_slist *headers, const char *post_data,
                                     char **out_response) {
  CURL *curl = curl_easy_init();
  if (!curl) return CURLE_FAILED_INIT;

  ResponseBuffer chunk = {.data = malloc(1012), .size = 0};
  if (!chunk.data) return CURLE_OUT_OF_MEMORY;

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
  if (headers_len > 0) {
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  }

  if (strcmp(method, "POST") == 0) {
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data ? post_data : "");
  }

  CURLcode res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  if (res != CURLE_OK) {
    free(chunk.data);
    return res;
  }

  *out_response = chunk.data;
  return CURLE_OK;
}

static struct curl_slist *build_headers_from_dict(dictionary_t *dict, int *len,
                                                  EXPRESSION_PARAMS()) {
  struct curl_slist *header_list = NULL;
  keyValList_t *kv = dict->keyVals;
  int count = 0;

  while (kv) {
    if (kv->key->type == EXPR_TYPE_TEXT && kv->val->type == EXPR_TYPE_TEXT) {
      char header_buf[1024];
      char *key = NULL;
      char *val = NULL;
      stackval_t sv;
      void *sp = PROVIDE_CONTEXT()->sp;
      size_t *sc = PROVIDE_CONTEXT()->sc;
      int *interactive = PROVIDE_CONTEXT()->interactive;

      /* Evaluate the key expression */
      evaluate_expression(kv->key, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      if (sv.type != TEXT) {
        fprintf(stderr, "error: expression for headers must be a string, was: %d\n", sv.type);
        if (!*interactive) {
          exit(1);
        }
        return NULL;
      }
      key = sv.t;
      /* Evaluate the value expression */
      evaluate_expression(kv->val, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      if (sv.type != TEXT) {
        fprintf(stderr, "error: expression for headers must be a string, was: %d\n", sv.type);
        if (!*interactive) {
          exit(1);
        }
        return NULL;
      }
      val = sv.t;

      snprintf(header_buf, sizeof(header_buf), "%s: %s", key, val);
      header_list = curl_slist_append(header_list, header_buf);
      count += 1;
    }
    kv = kv->next;
  }
  *len = count;
  return header_list;
}

static int perform_request(const char *method, EXPRESSION_PARAMS()) {
  stackval_t stv_url, stv_headers, stv_body;
  char *url = NULL;
  dictionary_t *headers_dict = NULL;
  char *post_body = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  heapval_t *hpv = NULL;
  int dummy;
  int headers_len = 0;

  POP_VAL(&stv_url, sp, sc);
  POP_VAL(&stv_headers, sp, sc);

  if (strcmp(method, "POST") == 0) {
    POP_VAL(&stv_body, sp, sc);
    if (stv_body.type != TEXT) {
      fprintf(stderr, "error: POST body must be a string.\n");
      return 1;
    }
    post_body = stv_body.t;
  }

  if (stv_url.type != TEXT || stv_headers.type != DICTTYPE) {
    fprintf(stderr, "error: '%s' request expects a string (url) and a dictionary (headers).\n",
            method);
    return 1;
  }

  url = stv_url.t;
  headers_dict = stv_headers.dict;

  struct curl_slist *curl_headers =
      build_headers_from_dict(headers_dict, &headers_len, EXPRESSION_ARGS());

  char *response_body = malloc(1024);
  CURLcode res =
      perform_http_request(url, method, headers_len, curl_headers, post_body, &response_body);
  curl_slist_free_all(curl_headers);

  if (res != CURLE_OK) {
    fprintf(stderr, "error: %s HTTP %s request failed: %s\n", url, method,
            curl_easy_strerror(res));
    PUSH_INT(-1, sp, sc);
    return 0;
  }

  stackval_t stv;
  stv.type = TEXT;
  stv.t = response_body;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  PUSH_STRING(response_body, sp, sc);
  return 0;
}

int ric_requests_get(LIBRARY_PARAMS()) { return perform_request("GET", EXPRESSION_ARGS()); }
int ric_requests_post(LIBRARY_PARAMS()) { return perform_request("POST", EXPRESSION_ARGS()); }
