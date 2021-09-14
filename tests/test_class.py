import os
from settings import *

def test_class_print():
  output_lines = [
"<Class: 'hej'>",
"hello",
"my member 'a' has value: 1337",
"Now 'a' is: 1338",
"hej",
"<Class object: 'hej'>",
"Wanting to set 'a' to: 100",
"100",
"100",
"{'a' : 100}"
]

  lib_script = callSample('class.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

