import os
from settings import *

def test_load():
  output_lines = [
"I have set a variable, named 'a', to: 1",
"Hi, the shared variable now holds value: 2"
]

  also_acceptable = "Hi, the shared variable now holds value: 3"

  lib_script = callSample('threads_test.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  assert output_lines[0] == ric_result[0]
  assert output_lines[1] == ric_result[1] or also_acceptable == ric_result[1]


