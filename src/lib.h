#ifndef SYS_RIC_LIB_H
#define SYS_RIC_LIB_H

#include <stdlib.h>

#include "hashtable.h"
#include "eval.h"
#include "ast.h"

#define DECLARE_LIB_FUNCTION(name, args, func) {name, args, func}

typedef int (*ric_lib_callback_t)(EXPRESSION_PARAMS());

typedef struct libFunction {
  char *libFuncName;
  int nbrArgs;
  ric_lib_callback_t func;
} libFunction_t;

void initialize_ric_lib();
libFunction_t* look_up_lib(char *id);

#endif

