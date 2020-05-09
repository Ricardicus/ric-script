#ifndef HOOKS_H
#define HOOKS_H

#include <stdlib.h>
#include "ast.h"

typedef int (*MainParserFunc)(void);

void setParser( MainParserFunc func );
void setRoot(statement_t **newRoot);
MainParserFunc getParser();
statement_t *getRoot();

/* Implemented in gram.y */
void initParser();
#endif