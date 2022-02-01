#ifndef RIC_EXT_LIB_H
#define RIC_EXT_LIB_H

#include "lib.h"

#ifdef WIN
#define MARK_EXPORT __declspec(dllexport)
#else
#define MARK_EXPORT
#endif

#define EVAL_EXPRESSION(e) evaluate_expression(e, EXPRESSION_ARGS());

#define EXPORT_MODULE(name)                                              \
  MARK_EXPORT char *EXPORT_MOD_NAME = name;                              \
  MARK_EXPORT size_t EXPORT_MOD_NBR_FUNCS() {                            \
    return sizeof(EXPORT_FUNCTION_LIST) / sizeof(*EXPORT_FUNCTION_LIST); \
  }                                                                      \
  MARK_EXPORT int EXPORT_VERSION_SYM_MAJ = EXPORT_VERSION_MAJ;           \
  MARK_EXPORT int EXPORT_VERSION_SYM_MIN = EXPORT_VERSION_MIN;

#endif
