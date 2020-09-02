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
"[['hejsan'],'hej']"
  ]

  lib_script = "./" + EXECUTABLE + " ../samples/vector_print.ric "

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

