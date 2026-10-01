import subprocess
from pathlib import Path

import os
from settings import *

def test_dict_print():
  output_lines = [
"{'a' : 'b', '1337' : 1337, 'c' : 'd'}",
"b",
"d",
"1337",
"f",
"hej",
"{}",
"{'a' : 1, 'b' : 2}",
"{'a' : {'a' : 1, 'b' : 2}}",
"e",
"foobar",
"1",
"0",
"['a','foobar']",
"['a']",
"['a','b']",
"a",
"{'b' : {'c' : {'d' : 'e'}}}",
"foobar",
"<Function: 'foobar'>",
"{'a' : 'b', 'c' : ['d','e','f',{'g' : 'h'}]}",
'{"a" : "b", "c" : ["d","e","f",{"g" : "h"}]} (text)',
"{'a' : 'b', 'c' : ['d','e','f',{'g' : 'h'}]}"
]

  lib_script = callSample('dictionary.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i], "denna: " + output_lines[i] + ", verkligt: " + ric_result[i]



def test_nested_dictionary_copies(tmp_path):
  script = tmp_path / "nested-copies.ric"
  script.write_text('\n'.join([
    '@ show(d) { print(d["nested"]["value"]) print(d["items"][0]["value"]) }',
    'inner = {"value": bigInt("12345678901234567890")}',
    '@ makeInner() { -> inner }',
    'd = {"nested": makeInner(), "items": [inner]}',
    'show(d)',
    'print(d["nested"]["value"])',
    'print(d["items"][0]["value"])',
  ]))
  result = subprocess.run([str(Path(EXECUTABLE).resolve()), str(script)],
                          capture_output=True, text=True, timeout=10)
  assert result.returncode == 0, result.stderr
  assert result.stderr == ""
  assert result.stdout.splitlines() == ["12345678901234567890"] * 4


def test_json_nested_dictionary_copies(tmp_path):
  script = tmp_path / "json-copies.ric"
  script.write_text('\n'.join([
    '@ show(d) { print(d["items"][0]["nested"]["value"]) }',
    "d = jsonLoad('{\"items\":[{\"nested\":{\"value\":\"kept\"}}]}')",
    'show(d)',
    'print(d["items"][0]["nested"]["value"])',
  ]))
  result = subprocess.run([str(Path(EXECUTABLE).resolve()), str(script)],
                          capture_output=True, text=True, timeout=10)
  assert result.returncode == 0, result.stderr
  assert result.stderr == ""
  assert result.stdout.splitlines() == ["kept", "kept"]
