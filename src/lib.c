#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

#ifndef NO_XATTR
#include "libxattr.h"
#endif

#include "dl.h"

#define MAX_NBR_MODULES 100

/* The ric library */
libFunction_t ric_library[] = {
    // libstd
    DECLARE_LIB_FUNCTION("exit", 1, ric_exit), DECLARE_LIB_FUNCTION("print", 1, ric_print),
    DECLARE_LIB_FUNCTION("printf", 1, ric_printf), DECLARE_LIB_FUNCTION("append", 2, ric_append),
    DECLARE_LIB_FUNCTION("push", 2, ric_push), DECLARE_LIB_FUNCTION("pop", 1, ric_pop),
    DECLARE_LIB_FUNCTION("len", 1, ric_len), DECLARE_LIB_FUNCTION("contains", 2, ric_contains),
    DECLARE_LIB_FUNCTION("keys", 1, ric_keys),
    DECLARE_LIB_FUNCTION("isDefined", 1, ric_is_defined),
    DECLARE_LIB_FUNCTION("help", 0, ric_help), DECLARE_LIB_FUNCTION("type", 1, ric_type),
    DECLARE_LIB_FUNCTION("typeInText", 1, ric_type_text),
    DECLARE_LIB_FUNCTION("list", 1, ric_create_list),
    DECLARE_LIB_FUNCTION("data", 1, ric_create_data),
    DECLARE_LIB_FUNCTION("text", 1, ric_create_text),
    DECLARE_LIB_FUNCTION("printEnv", 0, ric_print_env),
    DECLARE_LIB_FUNCTION("sum", 1, ric_sum),
    // libjson
    DECLARE_LIB_FUNCTION("jsonLoad", 1, ric_json_load),
    DECLARE_LIB_FUNCTION("jsonConvert", 1, ric_json_convert),
    // libstring
    DECLARE_LIB_FUNCTION("parseInt", 1, ric_atoi), DECLARE_LIB_FUNCTION("split", 2, ric_split),
    DECLARE_LIB_FUNCTION("charCode", 1, ric_char_code),
    DECLARE_LIB_FUNCTION("toUpper", 1, ric_to_upper),
    DECLARE_LIB_FUNCTION("toLower", 1, ric_to_lower),
    DECLARE_LIB_FUNCTION("startsWith", 2, ric_starts_with),
    DECLARE_LIB_FUNCTION("endsWith", 2, ric_ends_with),
    // libbigint
    DECLARE_LIB_FUNCTION("bigInt", 1, ric_new_big_int),
    // libio
    DECLARE_LIB_FUNCTION("isFile", 1, ric_is_file),
    DECLARE_LIB_FUNCTION("fileOpen", 1, ric_open_file),
    DECLARE_LIB_FUNCTION("fileClose", 1, ric_close_file),
    DECLARE_LIB_FUNCTION("fileWrite", 2, ric_write_file),
    DECLARE_LIB_FUNCTION("fileRead", 2, ric_read_file),
    DECLARE_LIB_FUNCTION("fileReadLines", 1, ric_read_lines_file),
    DECLARE_LIB_FUNCTION("input", 1, ric_read_input),
    // libmath
    DECLARE_LIB_FUNCTION("pow", 2, ric_power), DECLARE_LIB_FUNCTION("log", 1, ric_log),
    DECLARE_LIB_FUNCTION("sqrt", 1, ric_sqrt), DECLARE_LIB_FUNCTION("sin", 1, ric_sin),
    DECLARE_LIB_FUNCTION("cos", 1, ric_cos), DECLARE_LIB_FUNCTION("tan", 1, ric_tan),
    DECLARE_LIB_FUNCTION("exp", 1, ric_exp), DECLARE_LIB_FUNCTION("abs", 1, ric_abs),
    DECLARE_LIB_FUNCTION("floor", 1, ric_floor), DECLARE_LIB_FUNCTION("ceil", 1, ric_ceil),
    DECLARE_LIB_FUNCTION("randomInt", 2, ric_random_uniform_int),
    DECLARE_LIB_FUNCTION("random", 0, ric_random_uniform),
    DECLARE_LIB_FUNCTION("textBase", 2, ric_print_nbr_base),
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
    DECLARE_LIB_FUNCTION("isDir", 1, ric_is_directory), DECLARE_LIB_FUNCTION("ls", 1, ric_ls),
    DECLARE_LIB_FUNCTION("rm", 1, ric_rm), DECLARE_LIB_FUNCTION("mkdir", 1, ric_mkdir),
    DECLARE_LIB_FUNCTION("find", 1, ric_find_files), DECLARE_LIB_FUNCTION("cd", 1, ric_cd),
    DECLARE_LIB_FUNCTION("osName", 0, ric_os_name),
    // libctx
    DECLARE_LIB_FUNCTION("setTimeout", 2, ric_set_timeout),
    DECLARE_LIB_FUNCTION("setInterval", 2, ric_set_interval),
    // libnet
    DECLARE_LIB_FUNCTION("socketServer", 1, ric_setup_server_socket),
    DECLARE_LIB_FUNCTION("socketAccept", 1, ric_socket_accept_incoming_connection),
    DECLARE_LIB_FUNCTION("socketRead", 2, ric_read_socket),
    DECLARE_LIB_FUNCTION("socketWrite", 2, ric_write_socket),
    DECLARE_LIB_FUNCTION("socketClose", 1, ric_close_socket),
    DECLARE_LIB_FUNCTION("socketConnect", 2, ric_connect_socket)};

/* Handling dynamically linked libraries */
dl_handle_t libDlHandles[MAX_NBR_MODULES];
int libOpenHandles = 0;
hashtable_t *libCallbacks = NULL;

void initialize_ric_lib() {
  FILE *fp;
  size_t i = 0;
  size_t libFuncs = sizeof(ric_library) / sizeof(*ric_library);
  libCallbacks = hashtable_new(100, 0.8);
  assert(libCallbacks != NULL);

  while (i < libFuncs) {
    libFunction_t *func = &ric_library[i];
    hashtable_put(libCallbacks, NULL, func->libFuncName, func);
    ++i;
  }

  fp = fopen(EXPORT_MODULE_FILE, "r");
  if (fp != NULL) {
    char buf[256];

    memset(buf, 0, sizeof(buf));
    while (fgets(buf, sizeof(buf), fp)) {
      dl_handle_t dl_hnd;
      char *c;
      int res;

      c = strchr(buf, '\n');
      if (c != NULL) {
        *c = 0;
      }

      c = strchr(buf, '\r');
      if (c != NULL) {
        *c = 0;
      }

      res = dl_open(buf, &dl_hnd);
      if (res == 0) {
        libDlHandles[libOpenHandles] = dl_hnd;
        libOpenHandles++;
      }
      memset(buf, 0, sizeof(buf));
    }

    fclose(fp);
  }
}

void ric_get_dynamic_libraries(dl_handle_t **hnds, int *nbrLibs) {
  if (hnds == NULL) {
    return;
  }
  *hnds = libDlHandles;
  *nbrLibs = libOpenHandles;
}

size_t ric_lib_calls() { return sizeof(ric_library) / sizeof(libFunction_t); }

libFunction_t *look_up_lib(char *id) {
  libFunction_t *res = NULL;
  if (libCallbacks != NULL) {
    res = (libFunction_t *)hashtable_get(libCallbacks, NULL, id);
  }
  if (res == NULL) {
    int i;
    /* check among the dymanic libraries */
    i = 0;
    while (i < libOpenHandles) {
      int q;
      dl_handle_t dl = libDlHandles[i];
      int nbrFuncs = dl.nbr_funcs;
      libFunction_t *funcs = dl.funcs;
      q = 0;
      while (q < nbrFuncs) {
        libFunction_t l = funcs[q];
        char *funcID = l.libFuncName;
        if (strcmp(funcID, id) == 0) {
          return (libFunction_t *)&funcs[q];
        }
        q++;
      }
      ++i;
    }
  }
  return res;
}
