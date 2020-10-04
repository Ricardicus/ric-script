#include "libload.h"

/*
* This function imports the function definitions
* of other ric scripts into the one executing
*/
extern FILE *yyin;
int ric_load(LIBRARY_PARAMS())
{
  statement_t *root = NULL;
  statement_t *newFuncDefs = NULL;
  statement_t *newFuncDefsStart = NULL;
  statement_t *mainRoot = NULL;
  statement_t *walk = NULL;
  statement_t *walkPrev = NULL;
  MainParserFunc parse;
  stackval_t stv;
  int result = 0;
  FILE *fp = NULL;
  char *loadFile = NULL;

  // Read arg1, the name of the script
  POP_VAL(&stv, sp, sc);

  if ( stv.type != TEXT ) {
    fprintf(stderr, "load error: Need to provide a string as first argument.\n");
    return 1;
  }

  loadFile = stv.t;

  fp = fopen(loadFile, "r");

  if ( fp == NULL ) {
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
  walk = root;
  while ( walk != NULL ) {
    walk = walk->next;
  }

  /* Get current main scripts root */
  mainRoot = getMainRoot();

  /* Traverse the new AST and load its function definitions into the program */
  walk = root;
  walkPrev = NULL;
  while ( walk != NULL ) {
    int extracted = 0;
    if ( walk->entity == LANG_ENTITY_FUNCDECL ) {
      /* Extract this statement from the new ast */
      if ( walkPrev != NULL ) {
        walkPrev->next = walk->next;
        extracted = 1;
      }

      if ( newFuncDefs == NULL ) {
        newFuncDefs = walk;
        newFuncDefsStart = newFuncDefs;
      } else {
        newFuncDefs->next = walk;
        newFuncDefs = walk;
      }

      if ( root == walk ) {
        root = walk->next;
      }
    }

    if ( extracted == 0 && walkPrev != NULL ) {
      walkPrev = walk;
    }

    walk = walk->next;
  }

  if ( newFuncDefs != NULL ) {
    /* Insert the new function declaration at the end of the main program */
    statement_t *tmp = newFuncDefs->next;
    newFuncDefs->next = NULL;

    walk = newFuncDefsStart;
    while ( walk != NULL ) {
      walk = walk->next;
    }
    // Set the last statement in the function defs next to null
    interpret_statements_(newFuncDefsStart, PROVIDE_CONTEXT(), args, argVals);
    newFuncDefs->next = tmp;

    /* Place these statements at the end of the main program, so it gets cleaned up */
    walk = mainRoot;
    walkPrev = walk;
    while ( walk != NULL ) {
      walkPrev = walk;
      walk = walk->next;
    }
    walkPrev->next = newFuncDefsStart;
  }

  /* Free the loaded ast (with function defs extracted */
  walk = root;
  while ( walk != NULL ) {
    walk = walk->next;
  }
  free_ast(root);

  return result;
}

