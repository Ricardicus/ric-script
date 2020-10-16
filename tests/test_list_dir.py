import os
from settings import *

def test_vector_print():
  output_lines = [
"../samples/folder/a/b/b/b.txt",
"../samples/folder/a/b/b.txt",
"../samples/folder/a/b/a/b.txt",
"../samples/folder/a/b/a/a.txt",
"../samples/folder/a/b/c.txt",
"../samples/folder/a/b/a.txt",
"../samples/folder/a/a/b.txt",
"../samples/folder/a/a/d.txt",
"../samples/folder/a/a/c.txt",
"../samples/folder/a/a/a.txt",
"../samples/folder/a/c/a.txt",
"../samples/folder/README.md",
"../samples/func_ptr.ric",
"../samples/forever_and_ever.ric",
"../samples/ric_lib.ric",
"../samples/args.ric",
"../samples/recursion.ric",
"../samples/locals_globals.ric",
"../samples/demo.ric",
"../samples/vector_print.ric",
"../samples/example.ric",
"../samples/listFiles.ric",
"../samples/funccall_as_expr.ric",
"../samples/function_within_function.ric",
"../samples/load.ric",
"../samples/foobar.ric",
"../samples/gcd.ric",
"../samples/load_nt.ric",
"../samples/math.ric",
"../samples/dictionary.ric",
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

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

