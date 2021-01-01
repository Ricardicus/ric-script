#include "sync.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

#include "sync.h"

typedef struct ricSyncCtx {
  pthread_mutex_t mutex;
  pthread_t threads[RICSCRIPT_MAX_THREADS];
  bool threadTaken[RICSCRIPT_MAX_THREADS];
  void *threadFuncs[RICSCRIPT_MAX_THREADS];
  int threadIndex;
} ricSyncCtx_t;

void* initiateRicCall(void* ctx) {
  context_full_t newCtx = *((context_full_t*)ctx);
  ricSyncCtx_t *ricCtx = ((context_full_t*)ctx)->syncCtx;
  functionDef_t *func;
  size_t sc;
  void *sp;
  void *sb;

  newCtx.sc = &sc;

  // Setup a new stack
  SETUP_STACK(&sp, &sb, RIC_STACKSIZE, newCtx.sc);
  newCtx.sp = &sp;
  newCtx.sb = &sb;

  // Setup a set of locals 
  newCtx.varLocals = ast_emalloc(sizeof(locals_stack_t));
  newCtx.varLocals->sp = 0;
  newCtx.varLocals->sb = 0;
  getContext(ctx);
  func = (functionDef_t*) ricCtx->threadFuncs[ricCtx->threadIndex];
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  ricCtx->threadIndex = ( ricCtx->threadIndex + 1 ) % RICSCRIPT_MAX_THREADS;
  releaseContext(ctx);
  interpret_statements_(func->body, &newCtx, NULL, NULL);

  // free locals
  free(newCtx.varLocals);

  // Free stack
  FREE_STACK(newCtx.sp, newCtx.sb);

  return NULL;
}

void *createContext() {
  int i;
  ricSyncCtx_t *ctx = calloc(1, sizeof(ricSyncCtx_t));

  if ( ctx == NULL ) {
  	return NULL;
  }

  i = 0;
  while ( i < RICSCRIPT_MAX_THREADS ) {
  	ctx->threadTaken[i] = false;
  	++i;
  }

  ctx->threadIndex = 0;

  if (pthread_mutex_init(&ctx->mutex, NULL) != 0) { 
  	free(ctx);
  	return NULL;
  }

  return ctx;
}

void getContext(void *ctx) {
  /* Take the mutex */
  ricSyncCtx_t *ricCtx;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;
  pthread_mutex_lock(&ricCtx->mutex);
}

void releaseContext(void *ctx) {
  /* Release the mutex */
  ricSyncCtx_t *ricCtx;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;

  pthread_mutex_unlock(&ricCtx->mutex);
}

void createThread(void *ctx, void *func, size_t stacksize, void *arg) {
  ricSyncCtx_t *ricCtx;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;

  if ( ricCtx->threadTaken[ricCtx->threadIndex] ) {
  	// Waiting for the thread to finish
  	pthread_join(ricCtx->threads[ricCtx->threadIndex], NULL);
  }

  getContext(ctx);
  ricCtx->threadFuncs[ricCtx->threadIndex] = func;
  pthread_create(&(ricCtx->threads[ricCtx->threadIndex]), 
    NULL, 
    &initiateRicCall, arg); 
  releaseContext(ctx);
}

void freeContext(void *ctx) {
  ricSyncCtx_t *ricCtx;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;
  pthread_mutex_destroy(&ricCtx->mutex); 
  free(ricCtx);
}
