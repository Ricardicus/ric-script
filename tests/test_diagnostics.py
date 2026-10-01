import subprocess
from pathlib import Path

import pytest

from settings import EXECUTABLE


BINARY = Path(EXECUTABLE).resolve()


def run_script(tmp_path, source, name="script-with-a-long-filename-for-errors.ric"):
    script = tmp_path / name
    script.write_text(source)
    result = subprocess.run([str(BINARY), str(script)], capture_output=True,
                            text=True, timeout=10)
    return script, result


@pytest.mark.parametrize("source,line,column,message", [
    ("# comment\n\nprint(missing)\n", 3, 7, "NameError"),
    ("a = 1 print(missing)\n", 1, 13, "NameError"),
    ("# comment\nprint(1 +\n    missing)\n", 3, 5, "NameError"),
    ('s = "hello\nworld"\nprint(missing)\n', 3, 7, "NameError"),
    ("# comment\r\n\tprint(missing)\r\n", 2, 8, "NameError"),
    ('print("å") print(missing)\n', 1, 18, "NameError"),
    ("print((\n    missing))\n", 2, 5, "NameError"),
    (';; Test ;; {\n  print(1)\n}\n', 2, 3, "SyntaxError"),
    (';; Test ;; {\n  @ Test(a) { }\n}\n', 2, 3, "SyntaxError"),
    ("v = [1]\nprint(v[5])\n", 2, 7, "index error"),
    ("v = [1]\n\nv[5] = 2\n", 3, 1, "index error"),
    ('print("x" - 1)\n', 1, 7, "Cannot substract strings"),
    ("print(len(1))\n", 1, 7, "unexpected data type"),
    ("# comment\nprint(1 +\n    )\n", 3, 5, "SyntaxError"),
    ("print(1", 1, 8, "SyntaxError"),
])
def test_exact_source_location(tmp_path, source, line, column, message):
    script, result = run_script(tmp_path, source)
    assert result.returncode != 0
    assert result.stderr.startswith(f"{script}:{line}:{column}: "), result.stderr
    assert message in result.stderr
    assert "eval.c" not in result.stderr
    assert "Failed to parse program" not in result.stderr


def test_caller_location_restored_after_function_and_library_calls(tmp_path):
    script, result = run_script(tmp_path, "@ value() { -> 1 }\nprint(len(value()))\n")
    assert result.returncode != 0
    assert result.stderr.startswith(f"{script}:2:7: "), result.stderr
    # A library diagnostic should not be repeated as a generic failure.
    assert len(result.stderr.splitlines()) == 1


def test_loaded_function_keeps_its_file_and_line(tmp_path):
    module = tmp_path / "loaded-module-with-a-long-filename.ric"
    module.write_text("# module\n\n@ fail() {\n  print(missing)\n}\n")
    script, result = run_script(tmp_path, f'# main\nload("{module}")\nfail()\n')
    assert result.returncode != 0
    assert result.stderr.startswith(f"{module}:4:9: NameError"), result.stderr
    assert str(script) not in result.stderr


def test_multiple_loaded_files_reset_their_line_counters(tmp_path):
    first = tmp_path / "first.ric"
    first.write_text("# comment\n" * 30 + "@ value() { -> 1 }\n")
    second = tmp_path / "second.ric"
    second.write_text("@ fail() {\n  print(missing)\n}\n")
    _, result = run_script(tmp_path, f'load("{first}")\nload("{second}")\nfail()\n')
    assert result.returncode != 0
    assert result.stderr.startswith(f"{second}:2:9: NameError"), result.stderr


def test_main_file_location_survives_load(tmp_path):
    module = tmp_path / "module.ric"
    module.write_text("# comment\n" * 30 + "@ value() { -> 1 }\n")
    script, result = run_script(tmp_path, f'load("{module}")\nprint(missing)\n')
    assert result.returncode != 0
    assert result.stderr.startswith(f"{script}:2:7: NameError"), result.stderr


def test_bad_loaded_file_is_not_executed(tmp_path):
    module = tmp_path / "bad.ric"
    module.write_text("# comment\n@ value() { -> 1 }\nprint(1 + )\n")
    _, result = run_script(tmp_path, f'load("{module}")\nprint("should not run")\n')
    assert result.returncode != 0
    assert result.stderr.startswith(f"{module}:3:11: SyntaxError"), result.stderr
    assert "should not run" not in result.stdout


def test_threaded_function_uses_its_definition_location(tmp_path):
    script, result = run_script(tmp_path, "@ fail() {\n  print(missing)\n}\nfail.setTimeout(0)\n")
    assert result.returncode != 0
    assert result.stderr.startswith(f"{script}:2:9: NameError"), result.stderr


def test_empty_file_is_valid(tmp_path):
    _, result = run_script(tmp_path, "# comment\n\n")
    assert result.returncode == 0
    assert result.stderr == ""


def test_command_mode_has_a_source_label_and_error_status():
    result = subprocess.run([str(BINARY), "-c", "print(1 + )"],
                            capture_output=True, text=True, timeout=10)
    assert result.returncode != 0
    assert result.stderr.startswith("<command>:1:11: SyntaxError"), result.stderr


def test_interactive_syntax_error_does_not_replay_previous_command():
    result = subprocess.run([str(BINARY), "-np"], input="print(1)\nprint(2 + )\nprint(3)\n",
                            capture_output=True, text=True, timeout=10)
    assert result.returncode == 0
    assert result.stderr.startswith("<stdin>:1:11: SyntaxError"), result.stderr
    assert result.stdout.splitlines()[-2:] == ["1", "3"]


def test_script_read_from_standard_input():
    result = subprocess.run([str(BINARY), "-i"], input="# comment\nprint(missing)\n",
                            capture_output=True, text=True, timeout=10)
    assert result.returncode != 0
    assert result.stderr.startswith("<stdin>:2:7: NameError"), result.stderr
