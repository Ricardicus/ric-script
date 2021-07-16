import os
from settings import *

def test_vector_print():
  output_lines = [
"h",
"e",
"j",
"hejhej",
"-ejhej",
"--jhej",
"tjahej",
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
"hej hej hej ",
"hej hej hej hej hej hej hej "
]

  script = callSample('string_manipulations.ric')

  ric_result = os.popen(script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

