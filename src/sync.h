#ifndef RICSYNC_H
#define RICSYNC_H

#include <stdlib.h>

#define RICSCRIPT_MAX_THREADS 100

void *createContext();
void getContext(void *ctx);
void releaseContext(void *ctx);
void createThread(void *ctx, void *func, size_t stacksize);
void freeContext(void *ctx);

#endif
