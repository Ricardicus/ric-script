#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <regex.h>

#include "libos.h"

int ric_sleep(LIBRARY_PARAMS())
{
  stackval_t stv;
  int32_t sleepTime = 0;  // Sleep time is seconds
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    sleepTime = stv.i;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, integer expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  (void)sleep((unsigned int)sleepTime);

  /* Pushing zero */
  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_is_directory(LIBRARY_PARAMS())
{
  stackval_t stv;
  char *string = NULL;
  int result = 0;
  struct stat path_stat;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    string = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  stat(string, &path_stat);
  if ( S_ISDIR(path_stat.st_mode) ) {
    result = 1;
  } else {
    result = 0;
  }

  /* Pushing the result */
  PUSH_INT(result, sp, sc);

  return 0;
}


static int recursive_delete(const char *path) {
  DIR *d = opendir(path);
  size_t path_len = strlen(path);
  int r = -1;

  if (d) {
    struct dirent *p;

    r = 0;
    while (!r && (p=readdir(d))) {
      int r2 = -1;
      char *buf;
      size_t len;

      /* Skip the names "." and ".." as we don't want to recurse on them. */
      if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
        continue;

      len = path_len + strlen(p->d_name) + 2; 
      buf = malloc(len);

      if (buf) {
        struct stat statbuf;

        snprintf(buf, len, "%s/%s", path, p->d_name);
        if (!stat(buf, &statbuf)) {
          if (S_ISDIR(statbuf.st_mode))
            r2 = recursive_delete(buf);
          else
            r2 = unlink(buf);
        }
        free(buf);
      }
      r = r2;
    }
    closedir(d);
   }

  if (!r)
    r = rmdir(path);

  return r;
}

int ric_rm(LIBRARY_PARAMS())
{
  stackval_t stv;
  char *file = NULL;
  int result = 0;
  struct stat path_stat;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    file = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  stat(file, &path_stat);
  if ( S_ISDIR(path_stat.st_mode) ) {
    result = recursive_delete(file);
  } else {
    result = remove(file);
  }

  /* Pushing the result */
  PUSH_INT(result, sp, sc);

  return 0;
}


int ric_ls(LIBRARY_PARAMS())
{
  DIR *d;
  struct dirent *dir;
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
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  d = opendir(argText);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      expr_t *e;
      argsList_t *a;
      e = newExpr_Text(dir->d_name);
      a = newArgument(e, vecContent);
      vecContent = a;
    }
    closedir(d);
  }

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);
  return 0;
}

int ric_cd(LIBRARY_PARAMS())
{
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
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  result = chdir(argText);

  /* Pushing the result */
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_is_file(LIBRARY_PARAMS())
{
  stackval_t stv;
  char *filename = NULL;
  struct stat path_stat;
  int result;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    filename = stv.t;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument, string expected.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  stat(filename, &path_stat);
  if ( S_ISREG(path_stat.st_mode) ) {
    result = 1;
  } else {
    result = 0;
  }

  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_mkdir(LIBRARY_PARAMS())
{
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
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument, expected string.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

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
  int justFoundSlash = 0;
  int dot = 0;
  int addDepth = 0;

  while ( *walker ) {
    if ( *walker == '/' ) {
      if ( justFoundSlash ) {
        if ( !dot )
          addDepth++; // Descend an additional level
        dot = 0;
      }
      justFoundSlash = 1;
    } else {
      justFoundSlash = 0;
    }
    if ( *walker == '.' )
      dot = 1;
    ++walker;
  }

  if ( addDepth == 0 ) {
    /* Go through all levels, limit to 100 */
    ret = 100;
  } else {
    ret += addDepth;
  }

  return ret;
}

void DirectoryWalkAndMatch(const char *name,
  regex_t *re, argsList_t **vecContent, int level, int maxDepth)
{
  char path[1024];
  DIR *dir;
  int rc;
  struct dirent *entry;

  if ( level > maxDepth )
    return;

  if (!(dir = opendir(name)))
    return;

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;
    snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);

    /* Execute regular expression matching */
    rc = regexec(re, path, 0, NULL, 0);

    if ( rc == 0 ) {
      /* We had a match! */
      expr_t *e;
      argsList_t *a;
      e = newExpr_Text(path);
      a = newArgument(e, *vecContent);
      *vecContent = a;
    } 

    if (entry->d_type == DT_DIR) {
      DirectoryWalkAndMatch(path, re, vecContent, level + 1, maxDepth);
    }
  }
  closedir(dir);
}

int ric_find_files(LIBRARY_PARAMS()) {
  /* Walks through the file system in search for a file, matching a regular expression */
  stackval_t stv;
  regex_t re;
  heapval_t *hpv;
  int dummy;
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
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument, expected string.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  rc = regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB);
  if ( rc != 0 ) {
    fprintf(stderr, "error: function '%s' got an invalid regular expression pattern: '%s'\r\n", LIBRARY_FUNC_NAME(), pattern);

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
  DirectoryWalkAndMatch(rootDir, &re, &vecContent, 1, maxDepth);
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

int ric_os_name(LIBRARY_PARAMS())
{
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
  if ( *fixer == '"' ) {
    /*
    * Build required -DTARGET_OS="linux",
    * i.e. a stringified define. Otherwise I just get '1'.
    * I will take care of that here...
    */
    int fixIt = 0;
    fixer = resultText;
    while ( *fixer ) {
      ++fixer;
      if ( *fixer == '"' && resultText[0] == '"' ) {
        // Avoid this problem
        fixIt = 1;
        *fixer = 0;
      }
    }
    if ( fixIt ) {
      int idx = 0;
      fixer = resultText;
      while ( *fixer ) {
        fixer[idx] = fixer[idx+1];
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

