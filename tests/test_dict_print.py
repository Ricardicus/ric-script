import os
from settings import *

def test_dict_print():
  output_lines = [
"{'a' : 'b', '1337' : 1337, 'c' : 'd'}",
"b",
"d",
"1337",
"f",
"hej",
"{}",
"{'a' : 1, 'b' : 2}",
"{'a' : {'a' : 1, 'b' : 2}}",
"e",
"foobar",
"1",
"0",
"['a','foobar']",
"['a']",
"['a','b']",
"a",
"{'b' : {'c' : {'d' : 'e'}}}",
"foobar",
"<Function: 'foobar'>",
"{'c' : ['d','e','f',{'g' : 'h'}], 'a' : 'b'}"
]

  lib_script = callSample('dictionary.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

