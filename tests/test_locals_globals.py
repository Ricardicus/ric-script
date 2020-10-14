import os
from settings import *

def test_vector_print():
  output_lines = [
"Goin into scope 1 after defining a global",
"Printing global: 1337",
"Printing local: hello",
"Going into scope 2 after defining a local",
"Printing global: 1337",
"Printing old local: hello",
"Printing new local: hello again",
"Going out of scope 2 after defining a new local",
"Global still defined in scope 1",
"local still defined in scope 1",
"Local has the value in scope 1 that it was assigned in scope 2, which is right",
"Going out of scope 1",
"Global still defined in scope 0",
"Test result is good!"
]

  test_script = callSample('locals_globals.ric')

  ric_result = os.popen(test_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

