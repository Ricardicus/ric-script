#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sync.h"

typedef struct ricSyncCtx {
  HANDLE mutex;
  HANDLE event;
  HANDLE threads[RICSCRIPT_MAX_THREADS];
  bool threadTaken[RICSCRIPT_MAX_THREADS];
  int time[RICSCRIPT_MAX_THREADS];
  volatile void *threadFuncs[RICSCRIPT_MAX_THREADS];
  volatile int threadIndex;
} ricSyncCtx_t;

DWORD WINAPI initiateRicCallTimeout(void* ctx) {
  context_full_t newCtx = *((context_full_t*)ctx);
  ricSyncCtx_t *ricCtx = ((context_full_t*)ctx)->syncCtx;
  functionDef_t *func;
  int thisThreadID;
  size_t sc;
  void *sp;
  void *sb;
  int timeout;

  newCtx.sc = &sc;

  // Setup a new stack
  SETUP_STACK(&sp, &sb, RIC_STACKSIZE, newCtx.sc);
  newCtx.sp = &sp;
  newCtx.sb = &sb;

  if ( ricCtx->threadTaken[ricCtx->threadIndex] ) {
    WaitForSingleObject(ricCtx->threads[ricCtx->threadIndex], INFINITE);
  }

  // Setup a set of locals 
  newCtx.varLocals = ast_emalloc(sizeof(locals_stack_t));
  newCtx.varLocals->sp = 0;
  newCtx.varLocals->sb = 0;
  getContext(ctx);
  func = (functionDef_t*) ricCtx->threadFuncs[ricCtx->threadIndex];
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  timeout = ricCtx->time[ricCtx->threadIndex];
  thisThreadID = ricCtx->threadIndex;
  ricCtx->threadIndex = ( ricCtx->threadIndex + 1 ) % RICSCRIPT_MAX_THREADS;
  releaseContext(ctx);

  /* Signal that thread has started */
  SetEvent(ricCtx->event);

  /* Sleep */
  Sleep((unsigned int)timeout*1000);

  interpret_statements_(func->body, &newCtx, NULL, NULL);

  // free locals
  free(newCtx.varLocals);

  // Free stack
  FREE_STACK(sp, sb);

  ricCtx->threadTaken[thisThreadID] = false;

  return 0;
}

DWORD WINAPI initiateRicCallInterval(void* ctx) {
  context_full_t newCtx = *((context_full_t*)ctx);
  ricSyncCtx_t *ricCtx = ((context_full_t*)ctx)->syncCtx;
  functionDef_t *func;
  int thisThreadID;
  stackval_t stv;
  size_t sc;
  void *sp;
  void *sb;
  time_t startTime;
  int timeout;

  newCtx.sc = &sc;

  // Setup a new stack
  SETUP_STACK(&sp, &sb, RIC_STACKSIZE, newCtx.sc);
  newCtx.sp = &sp;
  newCtx.sb = &sb;

  // Setup a set of locals 
  newCtx.varLocals = ast_emalloc(sizeof(locals_stack_t));
  newCtx.varLocals->sp = 0;
  newCtx.varLocals->sb = 0;

  if ( ricCtx->threadTaken[ricCtx->threadIndex] ) {
    WaitForSingleObject(ricCtx->threads[ricCtx->threadIndex], INFINITE);
  }

  getContext(ctx);
  func = (functionDef_t*) ricCtx->threadFuncs[ricCtx->threadIndex];
  timeout = ricCtx->time[ricCtx->threadIndex];
  thisThreadID = ricCtx->threadIndex;
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  ricCtx->threadIndex = ( ricCtx->threadIndex + 1 ) % RICSCRIPT_MAX_THREADS;
  releaseContext(ctx);

  /* Signal that thread has started */
  SetEvent(ricCtx->event);

  Sleep((unsigned int)timeout * 1000);
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
      Sleep((unsigned int)(timeout - (endTime - startTime))*1000);
    }
  }

  // free locals
  free(newCtx.varLocals);

  // Free stack
  FREE_STACK(sp, sb);

  ricCtx->threadTaken[thisThreadID] = false;

  return 0;
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
  ctx->mutex = CreateMutex(NULL, FALSE, NULL);

  if ( ctx->mutex == NULL ) {
  	/* Failed to create mutex */
  	free(ctx);
  	return NULL;
  }

  ctx->event = CreateEvent( 
        NULL,               // default security attributes
        TRUE,               // manual-reset event
        FALSE,              // initial state is nonsignaled
        TEXT("SyncEvent")   // object name
        ); 

  if ( ctx->event == NULL ) {
    /* Failed to create mutex */
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
  WaitForSingleObject( 
    ricCtx->mutex,    // handle to mutex
    INFINITE);  // no time-out interval
}

void releaseContext(void *ctx) {
  /* Release the mutex */
  ricSyncCtx_t *ricCtx;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;
  ReleaseMutex(ricCtx->mutex);
}

void createThreadTimeout(void *ctx, void *func, size_t stacksize, void *arg, int time) {
  ricSyncCtx_t *ricCtx;
  DWORD ThreadID;

  if ( ctx == NULL )
  	return;

  ricCtx = (ricSyncCtx_t*)ctx;

  getContext(ctx);
  ricCtx->threadFuncs[ricCtx->threadIndex] = func;
  ricCtx->time[ricCtx->threadIndex] = time;
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  ricCtx->threads[ricCtx->threadIndex] = CreateThread( 
    NULL,       // default security attributes
    stacksize,          // default stack size if 0
    (LPTHREAD_START_ROUTINE) initiateRicCallTimeout, 
    arg,        // thread function arguments
    0,          // default creation flags
    &ThreadID); // receive thread identifier
  releaseContext(ctx);

  /* Wait for the thread to start */
  WaitForSingleObject(ricCtx->event, INFINITE);
}

void createThreadInterval(void *ctx, void *func, size_t stacksize, void *arg, int time) {
  ricSyncCtx_t *ricCtx;
  DWORD ThreadID;

  if ( ctx == NULL )
    return;

  ricCtx = (ricSyncCtx_t*)ctx;

  getContext(ctx);
  ricCtx->threadFuncs[ricCtx->threadIndex] = func;
  ricCtx->time[ricCtx->threadIndex] = time;
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  ricCtx->threads[ricCtx->threadIndex] = CreateThread( 
    NULL,       // default security attributes
    stacksize,          // default stack size if 0
    (LPTHREAD_START_ROUTINE) initiateRicCallInterval, 
    arg,        // thread function arguments
    0,          // default creation flags
    &ThreadID); // receive thread identifier
  releaseContext(ctx);

  /* Wait for the thread to start */
  WaitForSingleObject(ricCtx->event, INFINITE);
}

void freeContext(void *ctx) {
  ricSyncCtx_t *ricCtx;
  int i;

  if ( ctx == NULL )
    return;

  /* Wait for all threads to finish */
  i = 0;
  while ( i < RICSCRIPT_MAX_THREADS ) {
    if ( ricCtx->threadTaken[i] == true ) {
      WaitForSingleObject(ricCtx->threads[i], INFINITE);
    }
    ++i;
  }


  ricCtx = (ricSyncCtx_t*)ctx;
  CloseHandle(ricCtx->mutex);
  CloseHandle(ricCtx->event);
  free(ricCtx);
}
