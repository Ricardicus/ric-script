#ifndef SYS_RIC_LIB_H
#define SYS_RIC_LIB_H

#include <stdlib.h>

#include "hashtable.h"
#include "eval.h"
#include "ast.h"

/* Including the library functions */
#include "libio.h"
#include "libmath.h"
#include "libstd.h"
#include "libstring.h"
#include "libload.h"
#include "libos.h"

#define DECLARE_LIB_FUNCTION(name, args, func) {name, args, func}

void initialize_ric_lib();
size_t ric_lib_calls();
libFunction_t* look_up_lib(char *id);

#endif

