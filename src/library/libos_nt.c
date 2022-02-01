#include <windows.h>
#include <string.h>
#include <pcre.h>

#include "libos.h"

int ric_sleep(LIBRARY_PARAMS()) {
  stackval_t stv;
  int32_t sleepTime = 0; // Sleep time is seconds
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      sleepTime = stv.i;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, integer expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  Sleep((unsigned int)sleepTime * 1000);

  /* Pushing zero */
  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_is_directory(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *string = NULL;
  int result = 0;
  DWORD ftyp;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      string = stv.t;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, string expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  ftyp = GetFileAttributesA(string);
  if (ftyp == INVALID_FILE_ATTRIBUTES) {
    result = 0;
  } else if (ftyp & FILE_ATTRIBUTE_DIRECTORY) {
    result = 1;
  } else {
    result = 0;
  }

  /* Pushing the result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_ls(LIBRARY_PARAMS()) {
  WIN32_FIND_DATA fdFile;
  HANDLE hFind = NULL;
  char sPath[1024];
  expr_t *vec = NULL;
  argsList_t *vecContent = NULL;
  stackval_t stv;
  heapval_t *hpv;
  int dummy;
  char *argText;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  // pop arg 1 - directory to search in
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      argText = stv.t;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, string expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  snprintf(sPath, sizeof(sPath), "%s\\*.*", argText);

  if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "error %s: Failed to open folder '%s'\n", LIBRARY_FUNC_NAME(), argText);
  } else {
    do {
      if (strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0) {
        snprintf(sPath, sizeof(sPath), "%s\\\\%s", argText, fdFile.cFileName);
        expr_t *e;
        argsList_t *a;
        e = newExpr_Text(sPath);
        a = newArgument(e, vecContent);
        vecContent = a;
      }
    } while (FindNextFile(hFind, &fdFile));
  }

  FindClose(hFind);

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);
  return 0;
}

int ric_cd(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *argText;
  int result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // pop arg 1 - directory to search in
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      argText = stv.t;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, string expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  result = SetCurrentDirectory(argText);

  /* Pushing the result */
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_is_file(LIBRARY_PARAMS()) {
  stackval_t stv;
  FILE *fp;
  char *filename = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      filename = stv.t;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, string expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  fp = fopen(filename, "r+");

  if (fp != NULL) {
    // There is such a file
    fclose(fp);
    // Pushing the result 1
    PUSH_INT(1, sp, sc);
  } else {
    // There is no such file, pushing the result 0
    PUSH_INT(0, sp, sc);
  }

  return 0;
}

int ric_rm(LIBRARY_PARAMS()) {
  stackval_t stv;
  char *file = NULL;
  int result = 0;
  DWORD ftyp;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      file = stv.t;
      break;
    default:
      {
        fprintf(
            stderr,
            "error: function call '%s' got unexpected data type as argument, string expected.\n",
            LIBRARY_FUNC_NAME());
        exit(1);
      }
      break;
  }

  ftyp = GetFileAttributesA(file);
  if (ftyp == INVALID_FILE_ATTRIBUTES) {
    result = -1;
  } else if (ftyp & FILE_ATTRIBUTE_DIRECTORY) {
    result = RemoveDirectoryA(file);
  } else {
    result = DeleteFileA(file);
  }

  /* Pushing the result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_mkdir(LIBRARY_PARAMS()) {
  stackval_t stv;
  int32_t result;
  char *dir = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      dir = stv.t;
      break;
    default:
      {
        fprintf(stderr,
                "error: function '%s' got unexpected data type as argument, expected string.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  result = CreateDirectory(dir, NULL);

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

static int file_recursion_max_depth(char *pattern) {
  /*
   * On windows, the match we be of two in a row '\\', not the most
   * beautiful, but the important thing is that it works if you are
   * informed on what to do! :)
   */
  int ret = 1;
  char *walker = pattern;
  int justFoundBackslash = 0;
  int dot = 0;
  int addDepth = 0;

  while (*walker) {
    if (*walker == '\\') {
      if (justFoundBackslash) {
        if (!dot) addDepth++; // Descend an additional level
        dot = 0;
      }
      justFoundBackslash = 1;
    } else {
      justFoundBackslash = 0;
    }
    if (*walker == '.') dot = 1;
    ++walker;
  }

  if (addDepth == 0) {
    /* Go through all the levels, limit at 100 */
    ret = 100;
  } else {
    ret += addDepth;
  }

  return ret;
}

void DirectoryWalkAndMatch(const char *sDir, pcre *re, argsList_t **vecContent, int level,
                           int maxDepth) {
  WIN32_FIND_DATA fdFile;
  HANDLE hFind = NULL;
  char sPath[2048];
  int ovector[30];
  int rc;

  if (level > maxDepth) return;

  snprintf(sPath, sizeof(sPath), "%s\\\\*.*", sDir);

  if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) {
    return;
  }

  do {
    if (strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0) {
      snprintf(sPath, sizeof(sPath), "%s\\\\%s", sDir, fdFile.cFileName);

      /* Execute regular expression matching */
      rc = pcre_exec(re, NULL, sPath, strlen(sPath), 0, 0, ovector,
                     sizeof(ovector) / sizeof(*ovector));

      if (rc >= 0) {
        /* We had a match! */
        expr_t *e;
        argsList_t *a;
        e = newExpr_Text(sPath);
        a = newArgument(e, *vecContent);
        *vecContent = a;
      }
      if (fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        DirectoryWalkAndMatch(sPath, re, vecContent, level + 1, maxDepth);
      }
    }
  } while (FindNextFile(hFind, &fdFile));

  FindClose(hFind);
}

int ric_find_files(LIBRARY_PARAMS()) {
  /* Walks through the file system in search for a file, matching a regular expression */
  stackval_t stv;
  pcre *re;
  heapval_t *hpv;
  int dummy;
  char *pcre_error = NULL;
  int pcre_erroffset;
  char *pattern = NULL;
  int rc;
  int maxDepth = 1;
  expr_t *vec;
  argsList_t *vecContent = NULL;
  char *rootDir = ".";
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      pattern = stv.t;
      break;
    default:
      {
        fprintf(stderr,
                "error: function '%s' got unexpected data type as argument, expected string.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  re = pcre_compile(pattern, 0, &pcre_error, &pcre_erroffset, NULL);

  if (re == NULL) {
    fprintf(stderr, "error: function '%s' got an invalid regular expression pattern: '%s'\r\n",
            LIBRARY_FUNC_NAME(), pattern);
    fprintf(stderr, "       compilation failed at offset %d: %s\r\n", pcre_erroffset, pcre_error);

    vec = newExpr_Vector(NULL);

    stv.type = VECTORTYPE;
    stv.vec = vec->vec;
    ALLOC_HEAP(&stv, hp, &hpv, &dummy);
    free(vec);

    /* Pushing the parsed value */
    PUSH_VECTOR(stv.vec, sp, sc);

    return 0;
  }

  /* Get indentation level (how deep we should go) */
  maxDepth = file_recursion_max_depth(pattern);

  /* Walk through the file system and match */
  DirectoryWalkAndMatch(rootDir, re, &vecContent, 1, maxDepth);
  pcre_free(re);

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

int ric_os_name(LIBRARY_PARAMS()) {
  stackval_t stv;
  size_t resultTextLen = strlen(TARGET_OS) + 2;
  char *resultText = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  void *hp = PROVIDE_CONTEXT()->hp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  char *fixer = NULL;
  int dummy;
  heapval_t *hpv = NULL;

  resultText = ast_ecalloc(resultTextLen);
  snprintf(resultText, resultTextLen, "%s", TARGET_OS);

  fixer = resultText;
  if (*fixer == '"') {
    /*
     * Build required -DTARGET_OS="linux",
     * i.e. a stringified define. Otherwise I just get '1'.
     * I will take care of that here...
     */
    int fixIt = 0;
    fixer = resultText;
    while (*fixer) {
      ++fixer;
      if (*fixer == '"' && resultText[0] == '"') {
        // Avoid this problem
        fixIt = 1;
        *fixer = 0;
      }
    }
    if (fixIt) {
      int idx = 0;
      fixer = resultText;
      while (*fixer) {
        fixer[idx] = fixer[idx + 1];
        ++fixer;
      }
    }
  }

  stv.type = TEXT;
  stv.t = resultText;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the value */
  PUSH_STRING(stv.t, sp, sc);
  return 0;
}
