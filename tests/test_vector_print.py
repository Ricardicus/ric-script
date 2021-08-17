import os
from settings import *

def test_vector_print():
  output_lines = [
"['hej',1337,'hejsan']",
"hej",
"1337",
"hejsan",
"[1337,['hej',1337,'hejsan']]",
"1337",
"['hej',1337,'hejsan']",
"hej",
"1337",
"hejsan",
"hej",
"1337",
"hejsan",
"['foo','bar']",
"2",
"foo",
"bar",
"Foobar! foo ",
"Foobar! foo ",
"bar",
"foo",
"bar",
"['Foobar! foo ','bar','foo','bar']",
"[['hejsan'],'hej']",
"foo",
"bar",
"0",
"1",
"0",
"1",
"['hejsan','hoppsan','falleralera']",
"['hejsan',1,3,4]",
"['hejsan',1,3,4,'hejsan',1,3,4]",
"['hejsan',1,3,4,'hejsan',1,3,4,'hejsan',1,3,4]",
"[40,41,42,43,44,45,46,47,48,49]",
"[0,1,2,3]",
"[0,1,2,3,4]",
"[2,3,4]",
"[1]",
"[0,1,2,3,4]"
]

  lib_script = callSample('vector_print.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

