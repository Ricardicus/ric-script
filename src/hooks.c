#include "hooks.h"

static MainParserFunc parser = NULL;
static statement_t *mainProgramRoot = NULL;
static statement_t **root = NULL;
char *ParsedFile = NULL;

void setParser(MainParserFunc func) { parser = func; }

void setMainRoot(statement_t *newRoot) { mainProgramRoot = newRoot; }

void setRoot(statement_t **newRoot) { root = newRoot; }

MainParserFunc getParser(void) { return parser; }

statement_t *getRoot(void) { return *root; }

statement_t *getMainRoot(void) { return mainProgramRoot; }
