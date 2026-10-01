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
"['.','..','a.txt','b']",
"['.','..','b.txt']",
"0",
"'1336' as a string + 1 is: '1337'",
"The length of this text before the column including the space behind and the column itself is: 95",
"HI",
"I will exit with exit code: 2"
]

  lib_script = callSample('ric_lib.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(ric_result) == len(output_lines)

  assert len(set(ric_result)) == len(set(output_lines))



def test_file_checks_and_removal_in_clean_directory(tmp_path):
  import subprocess
  from pathlib import Path

  script = tmp_path / "file-checks.ric"
  script.write_text('\n'.join([
    'print(isFile("missing.txt"))',
    'print(isDir("missing.txt"))',
    'print(rm("missing.txt"))',
    'fp = fileOpen("present.txt")',
    'fp.fileClose()',
    'print(isFile("present.txt"))',
    'print(isDir("present.txt"))',
    'print(rm("present.txt"))',
    'print(mkdir("present-dir"))',
    'print(isFile("present-dir"))',
    'print(isDir("present-dir"))',
    'print(rm("present-dir"))',
  ]), encoding="utf-8")
  result = subprocess.run([str(Path(EXECUTABLE).resolve()), str(script)], cwd=tmp_path,
                          capture_output=True, text=True, timeout=10)
  assert result.returncode == 0, result.stderr
  assert result.stderr == ""
  assert result.stdout.splitlines() == ["0", "0", "-1", "1", "0", "0", "0", "0", "1", "0"]
