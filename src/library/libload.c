#include "libload.h"

/*
 * This function imports the function definitions
 * of other ric scripts into the one executing
 */
extern FILE *yyin;
extern char *ParsedFile;
int ric_load(LIBRARY_PARAMS()) {
  statement_t *root = NULL;
  statement_t *walk = NULL;
  statement_t *walkPrev = NULL;
  MainParserFunc parse;
  stackval_t stv;
  int result = 0;
  FILE *fp = NULL;
  char *loadFile = NULL;
  statement_t *mainRoot = NULL;
  statement_t *importedFuncDecs = NULL;
  statement_t *importedFuncDecsStart = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Read arg1, the name of the script
  POP_VAL(&stv, sp, sc);

  if (stv.type != TEXT) {
    fprintf(stderr, "load error: Need to provide a string as first argument.\n");
    return 1;
  }

  loadFile = stv.t;

  ParsedFile = loadFile;

  fp = fopen(loadFile, "r");

  if (fp == NULL) {
    fprintf(stderr, "load error: File '%s' not found.\n", loadFile);
    return 1;
  }

  /* Set yacc to parse this file */
  yyin = fp;

  /* Get parser function */
  parse = getParser();

  /* Parse the program */
  parse();

  /* Get the root statement */
  root = getRoot();

  /* Get main root statement */
  mainRoot = getMainRoot();

  /* Traverse the new AST and load its function definitions into the program */
  walk = root;
  walkPrev = NULL;
  while (walk != NULL) {
    if (walk->entity == LANG_ENTITY_FUNCDECL || walk->entity == LANG_ENTITY_CLASSDECL) {
      /* Extract this statement from the new ast */
      if (importedFuncDecs == NULL) {
        importedFuncDecs = malloc(sizeof(statement_t));
        if (importedFuncDecs == NULL) {
          fprintf(stderr, "error: failed to allocate memory\n");
          exit(1);
        }

        *importedFuncDecs = *walk;
        importedFuncDecs->next = NULL;

        importedFuncDecsStart = importedFuncDecs;
      } else {
        statement_t *newImport = malloc(sizeof(statement_t));
        if (newImport == NULL) {
          fprintf(stderr, "error: failed to allocate memory\n");
          exit(1);
        }

        *newImport = *walk;
        importedFuncDecs->next = newImport;
        importedFuncDecs = newImport;
        importedFuncDecs->next = NULL;
      }
    }

    walk = walk->next;
  }

  if (importedFuncDecsStart != NULL) {
    interpret_statements_(importedFuncDecsStart, PROVIDE_CONTEXT(), args, argVals);
    /* Clean up */
    walk = importedFuncDecsStart;
    walkPrev = importedFuncDecsStart;
    while (walk != NULL) {
      walkPrev = walk;
      walk = walk->next;
      free(walkPrev);
    }
  }

  /* Place loaded ast into main ast making it ready for cleanup */
  walk = mainRoot;
  walkPrev = mainRoot;
  while (walk != NULL) {
    walkPrev = walk;
    walk = walk->next;
  }
  walkPrev->next = root;

  /* closing file descriptor */
  fclose(fp);

  return result;
}
