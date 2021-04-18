import os
from settings import *

def test_ext_lib_args():

  output_lines = [
  "hejsan svejsan"
  ]

  lib_script = callSampleArgs('ext_lib_example.ric', ['hejsan svejsan'])

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]



