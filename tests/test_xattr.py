import os
from settings import *

def test_vector_print():
  output_lines = [
"xattr's of 'requirements.txt':",
"[]",
"Setting some xattributes",
"xattr's of 'requirements.txt' and values:",
"    - 'user.owner': 'Rickard'",
"    - 'user.master': 'Rickard of course'",
"Searching for user.* keyed files",
"./requirements.txt",
"Removing xattributes I just set",
"xattr's of 'requirements.txt':",
"[]"
]

  if (os.name == 'nt'):
    # Xattr is not supported on Windows
    return

  lib_script = callSample('xattr.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  assert len(set(output_lines)) == len(set(ric_result))
  for n in output_lines:
    assert(n in ric_result)

