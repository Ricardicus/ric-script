import os
from settings import *

def test_file_exist():

  file = "test.txt"
  output_lines = [
"ABCDEFGHIJKLMNOPQRSTUVWXY",
"YXWVUTSRQPONMLKJIHGFEDCBA",
"GIKMOQS",
"SQOMKIG",
"[119,104,101,101,108,10,112,121,116,101,115,116,10,10,10]"]

  lib_script = callSample('data_print.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

