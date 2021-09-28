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
#include "libtime.h"
#include "libnet.h"
#include "libctx.h"
#include "libjson.h"
#include "libbigint.h"

#define EXPORT_STR(s) XEXPORT_STR(s)
#define XEXPORT_STR(s) #s

struct dl_handle;
typedef struct dl_handle dl_handle_t;

void initialize_ric_lib();
size_t ric_lib_calls();
libFunction_t* look_up_lib(char *id);
void ric_get_dynamic_libraries(dl_handle_t **hnds, int *nbrLibs);

/* Exported modules fileds */
#define EXPORT_VERSION_MAJ 0
#define EXPORT_VERSION_MIN 1
#define EXPORT_VERSION_SYM_MAJ export_ver_maj_nbr
#define EXPORT_VERSION_SYM_MIN export_ver_min_nbr
#define EXPORT_FUNCTION_LIST ric_export_library
#define EXPORT_MOD_NAME ext_lib_name
#define EXPORT_MOD_NBR_FUNCS ext_lib_get_nbr_exported_funcs
#define EXPORT_MODULE_FILE "ric_modules.txt"
typedef size_t (*exportModSizeFunc_t)(void);

#endif

