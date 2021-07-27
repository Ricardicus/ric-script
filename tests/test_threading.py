import os
from settings import *

def test_load():
  output_lines = [
"I have set a variable, named 'a', to: 1",
"Hi, the shared variable now holds value: 2"
]

  lib_script = callSample('threads_test.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

