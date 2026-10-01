import os
from settings import *

def test_class_print():
  output_lines = [
"{'a' : 'b', 'c' : {'a' : 1337.000000, 'b' : 'c', 'd' : {'a' : 'hejsan'}}}",
"{'a' : 'b', 'c' : {'a' : 1337.000000, 'b' : 'c', 'd' : {'a' : 'hejsan'}}}"
]

  lib_script = callSample('json.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]



def test_serialization_grows_buffer_and_preserves_hash_collisions(tmp_path):
  import json
  import subprocess
  from pathlib import Path

  script = tmp_path / "large-dictionary.ric"
  script.write_text('d = {} . (30 ... i) { d[text(i)] = "abc" } print(jsonConvert(d))',
                    encoding="utf-8")
  result = subprocess.run([str(Path(EXECUTABLE).resolve()), str(script)],
                          capture_output=True, text=True, timeout=10)
  assert result.returncode == 0, result.stderr
  assert result.stderr == ""
  assert json.loads(result.stdout) == {str(i): "abc" for i in range(30)}


def test_json_empty_array_keeps_its_type(tmp_path):
  import subprocess
  from pathlib import Path

  script = tmp_path / "empty-array.ric"
  script.write_text('d = jsonLoad(\'{"items":[]}\') '
                    'print(typeInText(d["items"])) print(d["items"])', encoding="utf-8")
  result = subprocess.run([str(Path(EXECUTABLE).resolve()), str(script)],
                          capture_output=True, text=True, timeout=10)
  assert result.returncode == 0, result.stderr
  assert result.stderr == ""
  assert result.stdout.splitlines() == ["list", "[]"]
