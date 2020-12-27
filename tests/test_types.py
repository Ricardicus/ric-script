import os
from settings import *

def test_types_print():
  output_lines = [
"1337",
"text (3)",
"1337",
"i32 (1)",
"foobar",
"data (11)",
"6",
"[102,111,111,98,97,114]",
"list (7)",
"6",
"time (10)",
"Dummy",
"class (9)",
"{'a' : 1337}",
"dictionary (8)",
"standard-library-function-pointer (6)",
"function-pointer (5)",
"foobar",
"foobar",
"h",
"text (3)",
"h",
"data (11)",
"6",
"hej",
"data (11)"
]

  lib_script = callSample('types.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

