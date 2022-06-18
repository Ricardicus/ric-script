import os
from settings import *

def test_ext_lib_args():

  output_lines = [
  "hejsan",
  "[hejsan, hejsan]",
"example_class_add add::example_class: Added 1337 to member1. Member1: 1337",
"example_class_add add::example_class: Added 1337 to member1. Member1: 2674",
"example_class_sub sub::example_class: substitute 1337 to member1. Member1: 1337"

  ]

  lib_script = callSampleArgs('ext_lib_example.ric', ['hejsan'])

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]



