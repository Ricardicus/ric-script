#include "ext_lib.h"

int ric_example(LIBRARY_PARAMS())
{
  printf("Hejsan\n");
  return 0;
}

libFunction_t ric_library[] = {
  DECLARE_LIB_FUNCTION("ric_example", 0, ric_example)
};

EXPORT_MODULE("example_ric");