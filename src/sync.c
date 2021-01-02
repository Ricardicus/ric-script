#include "sync.h"

#include <sys/eventfd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

#include "sync.h"

typedef struct ricSyncCtx {
  pthread_mutex_t mutex;
  int event;
  uint64_t eventVal;
  pthread_t threads[RICSCRIPT_MAX_THREADS];
  int times[RICSCRIPT_MAX_THREADS];
  bool threadTaken[RICSCRIPT_MAX_THREADS];
  void *threadFuncs[RICSCRIPT_MAX_THREADS];
  int threadIndex;
} ricSyncCtx_t;

void* initiateRicCallTimeout(void* ctx) {
  context_full_t newCtx = *((context_full_t*)ctx);
  ricSyncCtx_t *ricCtx = ((context_full_t*)ctx)->syncCtx;
  functionDef_t *func;
  int timeout;
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
  getContext(ricCtx);
  func = (functionDef_t*) ricCtx->threadFuncs[ricCtx->threadIndex];
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  timeout = ricCtx->times[ricCtx->threadIndex];
  ricCtx->threadIndex = ( ricCtx->threadIndex + 1 ) % RICSCRIPT_MAX_THREADS;
  ricCtx->eventVal = 1;
  releaseContext(ricCtx);

  /* Signal that we are running */
  write(ricCtx->event, &ricCtx->eventVal, sizeof(uint64_t));

  (void)sleep((unsigned int)timeout);

  interpret_statements_(func->body, &newCtx, NULL, NULL);

  // free locals
  free(newCtx.varLocals);

  // Free stack
  FREE_STACK(sp, sb);

  return NULL;
}

void* initiateRicCallInterval(void* ctx) {
  context_full_t newCtx = *((context_full_t*)ctx);
  ricSyncCtx_t *ricCtx = ((context_full_t*)ctx)->syncCtx;
  functionDef_t *func;
  stackval_t stv;
  int timeout;
  time_t startTime;
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
  getContext(ricCtx);
  func = (functionDef_t*) ricCtx->threadFuncs[ricCtx->threadIndex];
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  timeout = ricCtx->times[ricCtx->threadIndex];
  ricCtx->threadIndex = ( ricCtx->threadIndex + 1 ) % RICSCRIPT_MAX_THREADS;
  ricCtx->eventVal = 1;
  releaseContext(ricCtx);

  /* Signal that we are running */
  write(ricCtx->event, &ricCtx->eventVal, sizeof(uint64_t));

  (void)sleep((unsigned int)timeout);

  while ( 1 ) {
    time_t endTime;

    /* Current time */
    time( &startTime );
    interpret_statements_(func->body, &newCtx, NULL, NULL);
    /* After execution */
    time( &endTime );

    /* Check return value on the stack, if zero stop execution */
    if ( *newCtx.sc > 0 ) {
      POP_VAL(&stv, newCtx.sp, newCtx.sc);

      if ( stv.type == INT32TYPE && stv.i != 0 ) {
        /* Stop executing this function now */
        break;
      }
    }

    if ( endTime - startTime < timeout ) {
      /* Sleep some more before going at it again */
      (void)sleep((unsigned int)(timeout - (endTime - startTime)));
    }
  }

  interpret_statements_(func->body, &newCtx, NULL, NULL);

  // free locals
  free(newCtx.varLocals);

  // Free stack
  FREE_STACK(sp, sb);

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

  ctx->event = eventfd(0, 0);
  if ( ctx->event == -1 ) {
    pthread_mutex_destroy(&ctx->mutex);
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

void createThreadTimeout(void *ctx, void *func, size_t stacksize, void *arg, int time) {
  ricSyncCtx_t *ricCtx;
  uint64_t eventVal;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;

  if ( ricCtx->threadTaken[ricCtx->threadIndex] ) {
  	// Waiting for the thread to finish
  	pthread_join(ricCtx->threads[ricCtx->threadIndex], NULL);
  }

  getContext(ctx);
  ricCtx->threadFuncs[ricCtx->threadIndex] = func;
  ricCtx->times[ricCtx->threadIndex] = time;
  pthread_create(&(ricCtx->threads[ricCtx->threadIndex]), 
    NULL, &initiateRicCallTimeout, arg);
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  releaseContext(ctx);

  /* Await the start signal */
  read(ricCtx->event, &eventVal, sizeof(eventVal));
}

void createThreadInterval(void *ctx, void *func, size_t stacksize, void *arg, int time) {
  ricSyncCtx_t *ricCtx;
  uint64_t eventVal;

  if ( ctx == NULL )
    return;

  ricCtx = (ricSyncCtx_t*)ctx;

  if ( ricCtx->threadTaken[ricCtx->threadIndex] ) {
    // Waiting for the thread to finish
    pthread_join(ricCtx->threads[ricCtx->threadIndex], NULL);
  }

  getContext(ctx);
  ricCtx->threadFuncs[ricCtx->threadIndex] = func;
  ricCtx->times[ricCtx->threadIndex] = time;
  pthread_create(&(ricCtx->threads[ricCtx->threadIndex]), 
    NULL, &initiateRicCallInterval, arg);
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  releaseContext(ctx);

  /* Await the start signal */
  read(ricCtx->event, &eventVal, sizeof(eventVal));
}

void freeContext(void *ctx) {
  ricSyncCtx_t *ricCtx;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;
  pthread_mutex_destroy(&ricCtx->mutex); 
  free(ricCtx);
}
