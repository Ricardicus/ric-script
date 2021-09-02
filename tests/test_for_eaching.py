import os
from settings import *

def test_for_each():
  output_lines = [
"0",
"1",
"2",
"3",
"4",
"5",
"6",
"7",
"8",
"9",
"a: 1",
"b: 2",
"c: 3",
"H",
"e",
"l",
"l",
"o",
" ",
"w",
"o",
"r",
"l",
"d",
"!",
"a",
"2",
"b",
"4",
"['0','10','20','30','40','50','60','70','80','90']",
"['1','2','3','2','3','4','3','4','5','4','5','6','5','6','7']",
"0",
"1",
"0",
"[0,1,1,2,3,5,8,13,21,34,55,89,144,233,377]"
]

  lib_script = callSample('forEaching.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

