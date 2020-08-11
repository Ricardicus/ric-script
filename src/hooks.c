#include "hooks.h"

static MainParserFunc parser = NULL;
static statement_t **root = NULL;

void setParser( MainParserFunc func )
{
  parser = func;
}

void setRoot(statement_t **newRoot) {
  root = newRoot;
}

MainParserFunc getParser() {
  return parser;
}

statement_t *getRoot() {
  return *root;
}

