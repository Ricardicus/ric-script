#include <unistd.h>
#include <dirent.h>
#include <regex.h>

#include "libxattr.h"

int ric_list_xattr(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1 = NULL;
  char *buffer = NULL;
  size_t bufferSize = 1024;
  expr_t *vec;
  argsList_t *vecContent = NULL;
  size_t offset = 0;
  ssize_t ret;
  heapval_t *hpv;
  int dummy;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  buffer = calloc(bufferSize, 1);
  if ( buffer == NULL ) {
    fprintf(stderr, "error: Memory error, failed to list xattr.\n");
    exit(1);
  }

  ret = listxattr(arg1, buffer, bufferSize, 0);

  if ( ret >= 0 ) {
    offset = 0;
    while ( offset < ret ) {
      expr_t *e;
      argsList_t *a;

      e = newExpr_Text(&buffer[offset]);
      a = newArgument(e, vecContent);
      vecContent = a;
      offset += strlen(&buffer[offset]) + 1;
    }
  }

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  free(buffer);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

int ric_set_xattr(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1;
  char *arg2;
  char *arg3;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 2 - xattr key
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg2 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 3 - xattr value
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg3 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }
 
  result = setxattr(arg1, arg2, arg3, strlen(arg3), 0, 0);

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_get_xattr(LIBRARY_PARAMS()) {
  char *arg1;
  char *arg2;
  stackval_t stv;
  heapval_t *hpv;
  int dummy;
  char *resultValue = NULL;
  size_t valueMaxLen = 256;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 2 - xattr key
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg2 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }
 
  resultValue = calloc(valueMaxLen+1, 1);
  if ( resultValue == NULL ) {
      fprintf(stderr, "error: calloc memory error during function call '%s', sorry I will terminate.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
  }

  (void)getxattr(arg1, arg2, resultValue, valueMaxLen, 0, 0);

  stv.type = TEXT;
  stv.t = resultValue;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_remove_xattr(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *arg1;
  char *arg2;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // pop arg 1 - path to file
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  // pop arg 2 - xattr key
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg2 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  result = removexattr(arg1, arg2, 0);

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

static void DirectoryWalkAndMatchXattrKey(const char *name,
  regex_t *re, argsList_t **vecContent, int level, int maxDepth)
{
  char path[1024];
  DIR *dir;
  int ret;
  int rc;
  struct dirent *entry;
  size_t offset = 0;
  char *buffer;
  size_t bufferSize = 1024;

  buffer = calloc(bufferSize, 1);
  if ( buffer == NULL ) {
    fprintf(stderr, "error: Memory error, allocate\n");
    exit(1);
  }

  if ( level > maxDepth ) {
    free(buffer);
    return;
  }

  if (!(dir = opendir(name))) {
    free(buffer);
    return;
  }

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;
    snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);

    /* List and walk through all the xattr-keys of this file */
    ret = listxattr(path, buffer, bufferSize, 0);
    if ( ret >= 0 ) {
      offset = 0;
      while ( offset < ret ) {
        /* Check if we have regex match */
        char *key = &buffer[offset];

        /* Execute regular expression matching */
        rc = regexec(re, key, 0, NULL, 0);

        if ( rc == 0 ) {
          /* We had a match! */
          expr_t *e;
          argsList_t *a;
          e = newExpr_Text(path);
          a = newArgument(e, *vecContent);
          *vecContent = a;
          /* We don't have to look further */
          break;
        }

        offset += strlen(&buffer[offset]) + 1;
      }
    }

    if (entry->d_type == DT_DIR) {
      DirectoryWalkAndMatchXattrKey(path, re, vecContent, level + 1, maxDepth);
    }
  }
  closedir(dir);
  free(buffer);
}

int ric_find_xattr(LIBRARY_PARAMS()) {
  stackval_t stv;
  regex_t re;
  int rc;
  char *arg1 = NULL;
  expr_t *vec;
  argsList_t *vecContent = NULL;
  heapval_t *hpv;
  int dummy;
  int maxDepth = 20;
  char *rootDir = ".";
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  // pop arg 1 - key-pattern
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    arg1 = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  rc = regcomp(&re, arg1, REG_EXTENDED|REG_NOSUB);
  if ( rc != 0 ) {
    fprintf(stderr, "error: function '%s' got an invalid regular expression pattern: '%s'\r\n", LIBRARY_FUNC_NAME(), arg1);

    vec = newExpr_Vector(NULL);

    stv.type = VECTORTYPE;
    stv.vec = vec->vec;
    ALLOC_HEAP(&stv, hp, &hpv, &dummy);
    free(vec);

    /* Pushing the parsed value */
    PUSH_VECTOR(stv.vec, sp, sc);

    return 0;
  }

  /* Walk through the file system and match */
  DirectoryWalkAndMatchXattrKey(rootDir, &re, &vecContent, 1, maxDepth);
  regfree(&re);

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

