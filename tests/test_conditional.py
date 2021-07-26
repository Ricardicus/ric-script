import os
from settings import *

def test_conditionals_print():
  output_lines = [
"=== a=0 b=0 c=0 d=0 ===",
"=======================",
"=== a=0 b=0 c=0 d=1 ===",
"a || b || c || d",
"a && b && c || d",
"=======================",
"=== a=0 b=0 c=1 d=0 ===",
"a || b || c || d",
"=======================",
"=== a=0 b=0 c=1 d=1 ===",
"a || b || c || d",
"a || b || c && d",
"a && b && c || d",
"=======================",
"=== a=0 b=1 c=0 d=0 ===",
"a || b || c || d",
"a || b || c && d",
"=======================",
"=== a=0 b=1 c=0 d=1 ===",
"a || b || c || d",
"a || b || c && d",
"a && b && c || d",
"=======================",
"=== a=0 b=1 c=1 d=0 ===",
"a || b || c || d",
"a || b || c && d",
"a || b && c",
"=======================",
"=== a=0 b=1 c=1 d=1 ===",
"a || b || c || d",
"a || b || c && d",
"a && b && c || d",
"a || b && c",
"=======================",
"=== a=1 b=0 c=0 d=0 ===",
"a || b || c || d",
"a || b || c && d",
"a || b && c",
"=======================",
"=== a=1 b=0 c=0 d=1 ===",
"a || b || c || d",
"a || b || c && d",
"a && b && c || d",
"a || b && c",
"=======================",
"=== a=1 b=0 c=1 d=0 ===",
"a || b || c || d",
"a || b || c && d",
"a || b && c",
"=======================",
"=== a=1 b=0 c=1 d=1 ===",
"a || b || c || d",
"a || b || c && d",
"a && b && c || d",
"a || b && c",
"=======================",
"=== a=1 b=1 c=0 d=0 ===",
"a || b || c || d",
"a || b || c && d",
"a || b && c",
"=======================",
"=== a=1 b=1 c=0 d=1 ===",
"a || b || c || d",
"a || b || c && d",
"a && b && c || d",
"a || b && c",
"=======================",
"=== a=1 b=1 c=1 d=0 ===",
"a || b || c || d",
"a || b || c && d",
"a && b && c || d",
"a || b && c",
"======================="
]

  lib_script = callSample('conditional.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

