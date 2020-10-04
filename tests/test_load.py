import os
from settings import *

def test_load():
  output_lines = [
"foobar",
"yes, loading works!"
]

  lib_script = callSample('load.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

