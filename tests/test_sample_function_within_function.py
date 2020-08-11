import os
from settings import *

result = ["foo",
"not bar",
"foo",
"bar",
"hejsan",
"tjenare"]


def test_function_within_function():
  script = "./" + EXECUTABLE + " ../samples/function_within_function.ric"

  sample_result = os.popen(script).read()

  words = sample_result.splitlines()

  assert len(result) == len(words)

  for i in range(0, len(words)):
    assert result[i] == words[i]