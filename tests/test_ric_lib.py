import os
from settings import *

def test_exit_code():
  lib_script = "./" + EXECUTABLE + " ../samples/ric_lib.ric "


  ret = os.system(lib_script)
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

  lib_script = "./" + EXECUTABLE + " ../samples/ric_lib.ric "

  ret = os.system(lib_script)
  if (os.WIFEXITED(ret)):
    ret = os.WEXITSTATUS(ret)

  # Will throw exception if file does not exist
  f = open(file, "r")

  real_file_content = f.read().splitlines()

  assert len(file_content) == len(real_file_content)

  for i in range(0,len(file_content)):
    assert file_content[i] == real_file_content[i]

