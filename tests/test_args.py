import os
from settings import *

def test_no_args():

  output_lines = [
  "Number of arguments: 2",
  "args: ['./../builddir/src/ric','../samples/args.ric']"
  ]

  lib_script = callSample('args.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]


def test_some_args_ints():

  output_lines = [
  "Number of arguments: 5",
  "args: ['./../builddir/src/ric','../samples/args.ric',1,2,3]"
  ]

  args = [1,2,3]

  lib_script = callSampleArgs('args.ric', args)

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

def test_some_args_strings():

  output_lines = [
  "Number of arguments: 5",
  "args: ['./../builddir/src/ric','../samples/args.ric','a','ab','abc']"
  ]

  args = ['a','ab','abc']

  lib_script = callSampleArgs('args.ric', args)

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]


