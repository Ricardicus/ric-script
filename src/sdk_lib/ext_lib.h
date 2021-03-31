#ifndef RIC_EXT_LIB_H
#define RIC_EXT_LIB_H

#include "ast.h"

#define EXPORT_MODULE(name) char *ext_lib_name = name;\
size_t ext_lib_get_nbr_exported_funcs () { return sizeof(ric_library)/sizeof(*ric_library); }

#endif