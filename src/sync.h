#ifndef RICSYNC_H
#define RICSYNC_H

#include <stdlib.h>

#include "ast.h"
#include "eval.h"

#define RICSCRIPT_MAX_THREADS 100

void *createContext();
void getContext(void *ctx);
void releaseContext(void *ctx);
void createThreadTimeout(void *ctx, void *func, size_t stacksize, void *arg, int time);
void createThreadInterval(void *ctx, void *func, size_t stacksize, void *arg, int time);
void freeContext(void *ctx);
void markContext(void *ctx, uint32_t markval);
void setUnbufferedOutput(); // This one does not really fit in here.

#endif
