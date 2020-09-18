#ifndef HOOKS_H
#define HOOKS_H

#include <stdlib.h>
#include "ast.h"

typedef int (*MainParserFunc)(void);
typedef void (*interactiveInterpreterFunc)(int, char**, statement_t *, int);

void setParser( MainParserFunc func );
void setRoot(statement_t **newRoot);
MainParserFunc getParser();
statement_t *getRoot();

/* Implemented in gram.y */
void initParser();
void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func);
#endif

