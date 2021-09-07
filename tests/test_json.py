import os
from settings import *

def test_class_print():
  output_lines = [
"{'a' : 'b', 'c' : {'a' : 1337.000000, 'b' : 'c', 'd' : {'a' : 'hejsan'}}}",
"{'a' : 'b', 'c' : {'a' : 1337.000000, 'b' : 'c', 'd' : {'a' : 'hejsan'}}}"
]

  lib_script = callSample('json.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

