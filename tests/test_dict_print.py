import os
from settings import *

def test_dict_print():
  output_lines = [
"<Dictionary, keys: [a, 1337, c]>",
"b",
"d",
"1337",
"f",
"hej",
"<Dictionary, no keys in it>",
"<Dictionary, keys: [a, b]>",
"<Dictionary, keys: [a]>",
"e",
"foobar",
"1",
"0",
"['a','foobar']",
"['a']",
"['a','b']"
]

  lib_script = callSample('dictionary.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

