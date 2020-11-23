import os
from settings import *

def test_vector_print():
  output_lines = [
"xattr's of 'requirements.txt':",
"[]",
"Setting some xattributes",
"xattr's of 'requirements.txt' and values:",
"    - 'owner': ''Rickard'",
"    - 'who is best': ''Rickard of course'",
"Removing xattributes I just set",
"xattr's of 'requirements.txt':",
"[]"
]

  lib_script = callSample('xattr.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

