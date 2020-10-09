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

  FindClose(hFind); //Always, Always, clean things up!

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);
  return 0;
}
