#ifndef SYS_RIC_LIB_H
#define SYS_RIC_LIB_H

#include <stdlib.h>

#include "hashtable.h"
#include "eval.h"
#include "ast.h"

#define EXPORT_STR(s) XEXPORT_STR(s)
#define XEXPORT_STR(s) #s

void initialize_ric_lib();
size_t ric_lib_calls();
libFunction_t* look_up_lib(char *id);

/* Exported modules fileds */
#define EXPORT_VERSION_MAJ 0
#define EXPORT_VERSION_MIN 1
#define EXPORT_VERSION_SYM_MAJ export_ver_maj_nbr
#define EXPORT_VERSION_SYM_MIN export_ver_min_nbr
#define EXPORT_FUNCTION_LIST ric_library
#define EXPORT_MOD_NAME ext_lib_name
#define EXPORT_MOD_NBR_FUNCS ext_lib_get_nbr_exported_funcs
#define EXPORT_MODULE_FILE "ric_modules.txt"
typedef size_t (*exportModSizeFunc_t)(void);

#endif

