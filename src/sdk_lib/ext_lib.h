#ifndef RIC_EXT_LIB_H
#define RIC_EXT_LIB_H

#include "ast.h"

#define EXPORT_MODULE(name) char* EXPORT_MOD_NAME = name;\
size_t EXPORT_MOD_NBR_FUNCS () { return sizeof(EXPORT_FUNCTION_LIST)/sizeof(*EXPORT_FUNCTION_LIST); }

#endif