import os
from settings import *

def test_exit_code():
  lib_script = callSample('ric_lib.ric')

  ret = os.system(lib_script)
  if ( os.name != 'nt' ):
    if (os.WIFEXITED(ret)):
      ret = os.WEXITSTATUS(ret)

  assert ret == 2

def test_file_exist():

  file = "test.txt"
  file_content = [
  "Hello world!",
  "New line right?",
  "This is a slash: \\",
  "New line?",
  "Have a good day!"
  ]

  lib_script = callSample('ric_lib.ric')

  ret = os.system(lib_script)
  if (os.name != 'nt'):
    if (os.WIFEXITED(ret)):
      ret = os.WEXITSTATUS(ret)

  # Will throw exception if file does not exist
  f = open(file, "r")

  real_file_content = f.read().splitlines()

  assert len(file_content) == len(real_file_content)

  for i in range(0,len(file_content)):
    assert file_content[i] == real_file_content[i]

def test_output():

  output_lines = [
"Hello!",
"Checking if there is a file called: 'test.txt': ",
"- Yes, there was such a file.",
"Opening a file: test.txt",
"File has been opened",
"Closing the file",
"5",
"'1336' as a string + 1 is: '1337'",
"The length of this text before the column including the space behind and the column itself is: 95",
"I will exit with exit code: 2"
]

  lib_script = callSample('ric_lib.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(ric_result) == len(output_lines)

  for line in ric_result:
    assert line in output_lines
