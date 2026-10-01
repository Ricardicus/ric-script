import subprocess
from pathlib import Path

import pytest

import os
from settings import *

def test_vector_print():
  output_lines = [
"['hej',1337,'hejsan']",
"hej",
"1337",
"hejsan",
"[1337,['hej',1337,'hejsan']]",
"1337",
"['hej',1337,'hejsan']",
"hej",
"1337",
"hejsan",
"hej",
"1337",
"hejsan",
"['foo','bar']",
"2",
"foo",
"bar",
"Foobar! foo ",
"Foobar! foo ",
"bar",
"foo",
"bar",
"['Foobar! foo ','bar','foo','bar']",
"[['hejsan'],'hej']",
"foo",
"bar",
"0",
"1",
"0",
"1",
"['hejsan','hoppsan','falleralera']",
"['hejsan',1,3,4]",
"['hejsan',1,3,4,'hejsan',1,3,4]",
"['hejsan',1,3,4,'hejsan',1,3,4,'hejsan',1,3,4]",
"[40,41,42,43,44,45,46,47,48,49]",
"[0,1,2,3]",
"[0,1,2,3,4]",
"[2,3,4]",
"[1]",
"[0,1,2,3,4]",
"[1,2]",
"[0,1,2,3,4]",
"[4,3,2,1,0]",
"[98,96,94,92,90]",
"[0,1,1,2,3,5,8,13,21,34,55,89,144,233,377]",
"[0,1,2,3,4,5,6,7,8,9]",
"9 8 7",
"[0,1,2,3,4,5,6]",
"[9,8,7,6,5,4,3,2,1,0,0,1,2,3,4,5,6]",
"[1,4,23,123,234,321]",
"[2,123,3132,12334]",
"2",
"[123,3132,12334]",
"[0,9,8,7,6,5,4,3,2,1]"
]

  lib_script = callSample('vector_print.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]



@pytest.mark.parametrize("operation", ["pop()", "popFirst()", "popIdx(0)"])
@pytest.mark.parametrize("value,expected", [
    ('"kept"', "kept"),
    ('bigInt("12345678901234567890")', "12345678901234567890"),
    ('[1,2]', "[1,2]"),
])
def test_popped_value_survives_vector_removal(tmp_path, operation, value, expected):
    script = tmp_path / "pop.ric"
    script.write_text(f"v = [{value}]\nr = v.{operation}\nprint(v)\nprint(r)\n")
    result = subprocess.run([str(Path(EXECUTABLE).resolve()), str(script)],
                            capture_output=True, text=True, timeout=10)
    assert result.returncode == 0, result.stderr
    assert result.stderr == ""
    assert result.stdout.splitlines() == ["[]", expected]
