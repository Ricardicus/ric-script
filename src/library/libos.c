#include "libos.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int ric_sleep(LIBRARY_PARAMS())
{
  stackval_t stv;
  int32_t sleepTime = 0;  // Sleep time is seconds

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

int ric_find_files(LIBRARY_PARAMS()) {
  return 0;
}

