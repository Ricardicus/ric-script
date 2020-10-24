#include "libos.h"
#include <windows.h>
#include <synchapi.h>

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

  Sleep((unsigned int)sleepTime*1000);

  /* Pushing zero */
  PUSH_INT(0, sp, sc);

  return 0;
}

int ric_is_directory(LIBRARY_PARAMS())
{
  stackval_t stv;
  char *string = NULL;
  int result = 0;
  DWORD ftyp;

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

int ric_ls(LIBRARY_PARAMS())
{
  WIN32_FIND_DATA fdFile;
  HANDLE hFind = NULL;
  char sPath[1024];
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

  snprintf(sPath, sizeof(sPath), "%s\\*.*", argText);

  if ( (hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE ) {
    fprintf(stderr, "error %s: Failed to open folder '%s'\n", LIBRARY_FUNC_NAME(), argText);
  } else {
    do {
      if (strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0) {
        snprintf(sPath, sizeof(sPath), "%s\\%s", argText, fdFile.cFileName);
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

  result = SetCurrentDirectory(argText);

  /* Pushing the result */
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_is_file(LIBRARY_PARAMS())
{
  stackval_t stv;
  FILE *fp;
  char *filename = NULL;

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

  fp = fopen(filename, "r+");

  if ( fp != NULL ) {
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

static int recursive_delete(const char *dir)
{
  int ret = 0;
  FTS *ftsp = NULL;
  FTSENT *curr;

  char *files[] = { (char *) dir, NULL };

  ftsp = fts_open(files, FTS_NOCHDIR | FTS_PHYSICAL | FTS_XDEV, NULL);
  if (!ftsp) {
    ret = -1;
    goto recursive_delete_finish;
  }

  while ((curr = fts_read(ftsp))) {
    switch (curr->fts_info) {
      case FTS_NS:
      case FTS_DNR:
      case FTS_ERR:
        break;

      case FTS_DC:
      case FTS_DOT:
      case FTS_NSOK:
        // Not reached unless FTS_LOGICAL, FTS_SEEDOT, or FTS_NOSTAT were
        // passed to fts_open()
        break;

      case FTS_D:
        // Do nothing. Need depth-first search, so directories are deleted
        // in FTS_DP
        break;

      case FTS_DP:
      case FTS_F:
      case FTS_SL:
      case FTS_SLNONE:
      case FTS_DEFAULT:
      if (remove(curr->fts_accpath) < 0) {
        fprintf(stderr, "%s: Failed to remove: %s\n",
        curr->fts_path, strerror(curr->fts_errno));
        ret = -1;
      }
      break;
    }
  }

recursive_delete_finish:
  if (ftsp) {
    fts_close(ftsp);
  }

  return ret;
}

int ric_rm(LIBRARY_PARAMS())
{
  stackval_t stv;
  char *file = NULL;
  int result = 0;

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

  result = recursive_delete(file);

  /* Pushing the result */
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

  result = CreateDirectory(dir, NULL);

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}


