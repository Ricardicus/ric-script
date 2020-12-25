#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

hashtable_t *libCallbacks = NULL;

/* The ric library */
libFunction_t ric_library[] = {
  // libstd
  DECLARE_LIB_FUNCTION("exit", 1, ric_exit),
  DECLARE_LIB_FUNCTION("print", 1, ric_print),
  DECLARE_LIB_FUNCTION("printf", 1, ric_printf),
  DECLARE_LIB_FUNCTION("append", 2, ric_append),
  DECLARE_LIB_FUNCTION("len", 1, ric_len),
  DECLARE_LIB_FUNCTION("contains", 2, ric_contains),
  DECLARE_LIB_FUNCTION("keys", 1, ric_keys),
  DECLARE_LIB_FUNCTION("isDefined", 1, ric_is_defined),
  DECLARE_LIB_FUNCTION("help", 0, ric_help),
  DECLARE_LIB_FUNCTION("type", 1, ric_type),
  DECLARE_LIB_FUNCTION("typeInText", 1, ric_type_text),
  // libstring
  DECLARE_LIB_FUNCTION("parseInt", 1, ric_atoi),
  DECLARE_LIB_FUNCTION("split", 2, ric_split),
  DECLARE_LIB_FUNCTION("charCode", 1, ric_char_code),
  // libio
  DECLARE_LIB_FUNCTION("isFile", 1, ric_is_file),
  DECLARE_LIB_FUNCTION("fileOpen", 1, ric_open_file),
  DECLARE_LIB_FUNCTION("fileClose", 1, ric_close_file),
  DECLARE_LIB_FUNCTION("fileWrite", 2, ric_write_file),
  DECLARE_LIB_FUNCTION("fileRead", 2, ric_read_file),
  DECLARE_LIB_FUNCTION("fileReadLines", 1, ric_read_lines_file),
  DECLARE_LIB_FUNCTION("input", 1, ric_read_input),
  // libmath
  DECLARE_LIB_FUNCTION("pow", 2, ric_power),
  DECLARE_LIB_FUNCTION("log", 1, ric_log),
  DECLARE_LIB_FUNCTION("sqrt", 1, ric_sqrt),
  DECLARE_LIB_FUNCTION("sin", 1, ric_sin),
  DECLARE_LIB_FUNCTION("cos", 1, ric_cos),
  DECLARE_LIB_FUNCTION("tan", 1, ric_tan),
  DECLARE_LIB_FUNCTION("exp", 1, ric_exp),
  DECLARE_LIB_FUNCTION("abs", 1, ric_abs),
  DECLARE_LIB_FUNCTION("floor", 1, ric_floor),
  DECLARE_LIB_FUNCTION("ceil", 1, ric_ceil),
  DECLARE_LIB_FUNCTION("randomInt", 2, ric_random_uniform_int),
  DECLARE_LIB_FUNCTION("random", 0, ric_random_uniform),
  // libload
  DECLARE_LIB_FUNCTION("load", 1, ric_load),
  // libtime
  DECLARE_LIB_FUNCTION("now", 0, ric_new_time),
  DECLARE_LIB_FUNCTION("timeSeconds", 1, ric_time_seconds),
  DECLARE_LIB_FUNCTION("timeMinutes", 1, ric_time_minutes),
  DECLARE_LIB_FUNCTION("timeHours", 1, ric_time_hours),
  DECLARE_LIB_FUNCTION("timeDays", 1, ric_time_days),
  DECLARE_LIB_FUNCTION("timeWeeks", 1, ric_time_weeks),
  DECLARE_LIB_FUNCTION("timeMonths", 1, ric_time_months),
  DECLARE_LIB_FUNCTION("timeYears", 1, ric_time_years),
  DECLARE_LIB_FUNCTION("timeSecond", 1, ric_time_second),
  DECLARE_LIB_FUNCTION("timeMinute", 1, ric_time_minute),
  DECLARE_LIB_FUNCTION("timeHour", 1, ric_time_hour),
  DECLARE_LIB_FUNCTION("timeDay", 1, ric_time_day),
  DECLARE_LIB_FUNCTION("timeWeek", 1, ric_time_week),
  DECLARE_LIB_FUNCTION("timeMonth", 1, ric_time_month),
  DECLARE_LIB_FUNCTION("timeYear", 1, ric_time_year),
#ifndef NO_XATTR
  // libxattr
  DECLARE_LIB_FUNCTION("xattrList", 1, ric_list_xattr),
  DECLARE_LIB_FUNCTION("xattrGet", 2, ric_get_xattr),
  DECLARE_LIB_FUNCTION("xattrSet", 3, ric_set_xattr),
  DECLARE_LIB_FUNCTION("xattrFindKey", 1, ric_find_xattr),
  DECLARE_LIB_FUNCTION("xattrRm", 2, ric_remove_xattr),
#endif
  // libos
  DECLARE_LIB_FUNCTION("sleep", 1, ric_sleep),
  DECLARE_LIB_FUNCTION("isDir", 1, ric_is_directory),
  DECLARE_LIB_FUNCTION("ls", 1, ric_ls),
  DECLARE_LIB_FUNCTION("rm", 1, ric_rm),
  DECLARE_LIB_FUNCTION("mkdir", 1, ric_mkdir),
  DECLARE_LIB_FUNCTION("find", 1, ric_find_files),
  DECLARE_LIB_FUNCTION("cd", 1, ric_cd),
  // libnet
  DECLARE_LIB_FUNCTION("socketServer", 1, ric_setup_server_socket),
  DECLARE_LIB_FUNCTION("socketAccept", 1, ric_socket_accept_incoming_connection),
  DECLARE_LIB_FUNCTION("socketRead", 2, ric_read_socket),
  DECLARE_LIB_FUNCTION("socketWrite", 2, ric_write_socket),
  DECLARE_LIB_FUNCTION("socketClose", 1, ric_close_socket),
  DECLARE_LIB_FUNCTION("socketConnect", 2, ric_connect_socket)
};

void initialize_ric_lib() {
  size_t i = 0;
  size_t libFuncs = sizeof(ric_library) / sizeof(*ric_library);
  libCallbacks = hashtable_new(100, 0.8);
  assert(libCallbacks != NULL);

  while ( i < libFuncs ) {
    libFunction_t *func = &ric_library[i];
    hashtable_put(libCallbacks, func->libFuncName, func);
    ++i;
  }
}

size_t ric_lib_calls() {
  return sizeof(ric_library) / sizeof(libFunction_t);
}

libFunction_t* look_up_lib(char *id) {
  if ( libCallbacks == NULL ) {
    return NULL;
  }
  return (libFunction_t*) hashtable_get(libCallbacks, id);
}

