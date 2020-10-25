import os
from settings import *

def test_vector_print():
  output_lines = [
"load_nt.ric",
"demo.ric",
"forever_and_ever.ric",
"gcd.ric",
"dictionary.ric",
"folder",
" a",
"  a",
"   c.txt",
"   b.txt",
"   a.txt",
"   d.txt",
"  c",
"   a.txt",
"  b",
"   a",
"    b.txt",
"    a.txt",
"   c.txt",
"   b.txt",
"   a.txt",
"   b",
"    b.txt",
" README.md",
"ric_lib.ric",
"funccall_as_expr.ric",
"load.ric",
"listFiles.ric",
"func_ptr.ric",
"args.ric",
"example.ric",
"recursion.ric",
"rpn.ric",
"function_within_function.ric",
"locals_globals.ric",
"string_manipulations.ric",
"vector_print.ric",
"math.ric",
"foobar.ric"
]
  if ( os.name == 'nt' ):
    # list directory only works on unix platforms
    # due to the fact that Windows uses backslash
    # instead of forward slashes.
    assert 1 == 1
    return

  script = callSampleArgs('listFiles.ric', ["../samples"])

  ric_result = os.popen(script).read().splitlines()

  assert len(output_lines) == len(ric_result)
  assert len(set(output_lines)) == len(set(ric_result))

