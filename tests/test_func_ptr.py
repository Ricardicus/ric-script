import os
from settings import *

def test_file_exist():

  file = "test.txt"
  output_lines = [
"Foobar!",
"Foobar! foo",
"Foobar! foobar",
"Foobar! foo bar :)",
"hejsan",
"hej"
  ]

  lib_script = callSample('func_ptr.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

