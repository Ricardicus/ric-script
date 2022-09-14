#ifndef HOOKS_H
#define HOOKS_H

#include <stdlib.h>
#include "ast.h"

typedef int (*MainParserFunc)(void);
typedef void (*interactiveInterpreterFunc)(int, char **, statement_t *, int, int, int);

void setParser(MainParserFunc func);
void setRoot(statement_t **newRoot);
MainParserFunc getParser();
statement_t *getRoot();
void setMainRoot(statement_t *newRoot);
statement_t *getMainRoot();

/* Implemented in gram.y */
void initParser();
void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func, int stacksize, int heapsize, const char *prompt);
void runCommand(int argc, char *argv[], interactiveInterpreterFunc func, char *command, int stacksize, int heapsize);

#endif
