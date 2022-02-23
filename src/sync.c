#include "sync.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <fcntl.h>

#include "sync.h"

typedef struct ricSyncCtx {
  pthread_mutex_t mutex;
  sem_t *event;
  pthread_t threads[RICSCRIPT_MAX_THREADS];
  int times[RICSCRIPT_MAX_THREADS];
  bool threadTaken[RICSCRIPT_MAX_THREADS];
  void *threadFuncs[RICSCRIPT_MAX_THREADS];
  context_full_t *ctxs[RICSCRIPT_MAX_THREADS];
  int threadIndex;
} ricSyncCtx_t;

void markContext(void *ctx, uint32_t markval) {
  ricSyncCtx_t *ricCtx;
  int i;

  if (ctx == NULL) return;

  ricCtx = (ricSyncCtx_t *)ctx;
  i = 0;
  while (i < RICSCRIPT_MAX_THREADS) {
    if (ricCtx->threadTaken[i]) {
      context_full_t *c = ricCtx->ctxs[i];
      mark(NULL, markval, NULL, NULL, c, NULL, NULL);
    }
    ++i;
  }
}

void *initiateRicCallTimeout(void *ctx) {
  context_full_t *newCtx = ast_emalloc(sizeof(context_full_t));
  ricSyncCtx_t *ricCtx = ((context_full_t *)ctx)->syncCtx;
  int thisThreadIndex = 0;
  functionDef_t *func;
  int timeout;
  size_t sc;
  void *sp;
  void *sb;

  *newCtx = *((context_full_t *)ctx);

  newCtx->sc = &sc;

  // Setup a new stack
  SETUP_STACK(&sp, &sb, RIC_STACKSIZE, newCtx->sc);
  newCtx->sp = &sp;
  newCtx->sb = &sb;

  // Setup a set of locals
  newCtx->varLocals = ast_emalloc(sizeof(locals_stack_t));
  newCtx->varLocals->sp = 0;
  newCtx->varLocals->sb = 0;
  getContext(ricCtx);
  func = (functionDef_t *)ricCtx->threadFuncs[ricCtx->threadIndex];
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  timeout = ricCtx->times[ricCtx->threadIndex];
  ricCtx->ctxs[ricCtx->threadIndex] = newCtx;
  thisThreadIndex = ricCtx->threadIndex;
  ricCtx->threadIndex = (ricCtx->threadIndex + 1) % RICSCRIPT_MAX_THREADS;
  releaseContext(ricCtx);

  /* Signal that we are running */
  sem_post(ricCtx->event);

  (void)sleep((unsigned int)timeout);

  interpret_statements_(func->body, newCtx, NULL, NULL);

  // free locals
  free(newCtx->varLocals);

  // Free stack
  FREE_STACK(sp, sb);

  getContext(ricCtx);
  ricCtx->threadTaken[thisThreadIndex] = false;
  releaseContext(ricCtx);

  free(newCtx);
  return NULL;
}

void *initiateRicCallInterval(void *ctx) {
  context_full_t *newCtx = ast_emalloc(sizeof(context_full_t));
  ricSyncCtx_t *ricCtx = ((context_full_t *)ctx)->syncCtx;
  functionDef_t *func;
  stackval_t stv;
  int thisThreadIndex = 0;
  int timeout;
  time_t startTime;
  size_t sc;
  void *sp;
  void *sb;

  *newCtx = *((context_full_t *)ctx);

  newCtx->sc = &sc;

  // Setup a new stack
  SETUP_STACK(&sp, &sb, RIC_STACKSIZE, newCtx->sc);
  newCtx->sp = &sp;
  newCtx->sb = &sb;

  // Setup a set of locals
  newCtx->varLocals = ast_emalloc(sizeof(locals_stack_t));
  newCtx->varLocals->sp = 0;
  newCtx->varLocals->sb = 0;
  getContext(ricCtx);
  func = (functionDef_t *)ricCtx->threadFuncs[ricCtx->threadIndex];
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  timeout = ricCtx->times[ricCtx->threadIndex];
  ricCtx->ctxs[ricCtx->threadIndex] = newCtx;
  thisThreadIndex = ricCtx->threadIndex;
  ricCtx->threadIndex = (ricCtx->threadIndex + 1) % RICSCRIPT_MAX_THREADS;
  releaseContext(ricCtx);

  /* Signal that we are running */
  sem_post(ricCtx->event);

  (void)sleep((unsigned int)timeout);

  while (1) {
    time_t endTime;

    /* Current time */
    time(&startTime);
    interpret_statements_(func->body, newCtx, NULL, NULL);
    /* After execution */
    time(&endTime);

    /* Check return value on the stack, if zero stop execution */
    if (*newCtx->sc > 0) {
      POP_VAL(&stv, newCtx->sp, newCtx->sc);

      if (stv.type == INT32TYPE && stv.i != 0) {
        /* Stop executing this function now */
        break;
      }
    }

    if (endTime - startTime < timeout) {
      /* Sleep some more before going at it again */
      (void)sleep((unsigned int)(timeout - (endTime - startTime)));
    }
  }

  // free locals
  free(newCtx->varLocals);

  // Free stack
  FREE_STACK(sp, sb);

  getContext(ricCtx);
  ricCtx->threadTaken[thisThreadIndex] = false;
  releaseContext(ricCtx);

  free(newCtx);

  return NULL;
}

void *createContext() {
  int i;
  ricSyncCtx_t *ctx = calloc(1, sizeof(ricSyncCtx_t));

  if (ctx == NULL) {
    return NULL;
  }

  i = 0;
  while (i < RICSCRIPT_MAX_THREADS) {
    ctx->threadTaken[i] = false;
    ++i;
  }

  ctx->threadIndex = 0;

  if (pthread_mutex_init(&ctx->mutex, NULL) != 0) {
    free(ctx);
    return NULL;
  }

  ctx->event = sem_open("RicScriptSync", O_CREAT, 0664, 0);
  if (ctx->event == NULL) {
    pthread_mutex_destroy(&ctx->mutex);
    free(ctx);
    return NULL;
  }

  return ctx;
}

void getContext(void *ctx) {
  /* Take the mutex */
  ricSyncCtx_t *ricCtx;

  if (ctx == NULL) return;

  ricCtx = (ricSyncCtx_t *)ctx;
  pthread_mutex_lock(&ricCtx->mutex);
}

void releaseContext(void *ctx) {
  /* Release the mutex */
  ricSyncCtx_t *ricCtx;

  if (ctx == NULL) return;

  ricCtx = (ricSyncCtx_t *)ctx;
  pthread_mutex_unlock(&ricCtx->mutex);
}

void createThreadTimeout(void *ctx, void *func, size_t stacksize, void *arg, int time) {
  ricSyncCtx_t *ricCtx;

  if (ctx == NULL) return;

  ricCtx = (ricSyncCtx_t *)ctx;

  if (ricCtx->threadTaken[ricCtx->threadIndex] == true) {
    // Waiting for the thread to finish
    pthread_join(ricCtx->threads[ricCtx->threadIndex], NULL);
  }

  getContext(ctx);
  ricCtx->threadFuncs[ricCtx->threadIndex] = func;
  ricCtx->times[ricCtx->threadIndex] = time;
  pthread_create(&(ricCtx->threads[ricCtx->threadIndex]), NULL, &initiateRicCallTimeout, arg);
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  releaseContext(ctx);

  /* Await the start signal */
  sem_wait(ricCtx->event);
}

void createThreadInterval(void *ctx, void *func, size_t stacksize, void *arg, int time) {
  ricSyncCtx_t *ricCtx;

  if (ctx == NULL) return;

  ricCtx = (ricSyncCtx_t *)ctx;

  if (ricCtx->threadTaken[ricCtx->threadIndex] == true) {
    // Waiting for the thread to finish
    pthread_join(ricCtx->threads[ricCtx->threadIndex], NULL);
  }

  getContext(ctx);
  ricCtx->threadFuncs[ricCtx->threadIndex] = func;
  ricCtx->times[ricCtx->threadIndex] = time;
  pthread_create(&(ricCtx->threads[ricCtx->threadIndex]), NULL, &initiateRicCallInterval, arg);
  ricCtx->threadTaken[ricCtx->threadIndex] = true;
  releaseContext(ctx);

  /* Await the start signal */
  sem_wait(ricCtx->event);
}

void freeContext(void *ctx) {
  ricSyncCtx_t *ricCtx;
  int i;

  if (ctx == NULL) return;

  ricCtx = (ricSyncCtx_t *)ctx;

  /* Wait for all threads to finish */
  i = 0;
  while (i < RICSCRIPT_MAX_THREADS) {
    if (ricCtx->threadTaken[i] == true) {
      errno = 0;
      if (pthread_join(ricCtx->threads[i], NULL) != 0) {
        int errorType = errno;
        switch (errorType) {
          case EDEADLK:
            fprintf(
                stderr,
                "error: A deadlock was detected (e.g., two threads tried to join with each other); or thread specifies the calling thread.\n");
            break;
          case EINVAL:
            fprintf(stderr, "error: Thread is not a joinable thread.\n");
            fprintf(stderr,
                    "       Another thread is already waiting to join with this thread.\n");
            break;
          case ESRCH:
            fprintf(stderr, "error: No thread with the ID thread could be found.\n");
            break;
          default:
            fprintf(stderr, "error: Other error on join %d\n", errorType);
            break;
        }
      }
    }
    ++i;
  }

  sem_close(ricCtx->event);
  pthread_mutex_destroy(&ricCtx->mutex);
  free(ricCtx);
}

/* Used in interactive mode, no buffering */
void setUnbufferedOutput() {
  /* Unbuffered mode */
  setvbuf(stdout, NULL, _IONBF, 0);
}

