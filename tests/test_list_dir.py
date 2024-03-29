import os
from settings import *

def test_directory_print():

  output_lines = [
"load_test",
" numbers.txt",
" definitions.ric",
"load_nt.ric",
"types.ric",
"demo.ric",
"forever_and_ever.ric",
"gcd.ric",
"forEaching.ric",
"threads.ric",
"dictionary.ric",
"folder",
"bigIntegers.ric",
"time_of_day.ric",
"conditional.ric",
"xattr.ric",
"socketServer.ric",
"socketClient.ric",
"socketClientServer.ric",
"threads_test.ric",
"data_print.ric",
"json.ric",
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
"find_files.ric",
"funccall_as_expr.ric",
"load.ric",
"listFiles.ric",
"func_ptr.ric",
"args.ric",
"example.ric",
"recursion.ric",
"rpn.ric",
"rpn_classes.ric",
"class.ric",
"ramanujan_three.ric",
"function_within_function.ric",
"locals_globals.ric",
"string_manipulations.ric",
"vector_print.ric",
"math.ric",
"foobar.ric",
"crypto.ric"
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
  for n in output_lines:
    assert(n in ric_result)


