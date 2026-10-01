import shutil
import subprocess
from pathlib import Path

import pytest

from settings import EXECUTABLE


ROOT = Path(__file__).resolve().parents[1]
SAMPLES = sorted((ROOT / "samples").rglob("*.ric"))


def run_program(source):
    result = subprocess.run(
        [EXECUTABLE, "-c", source], capture_output=True, text=True, timeout=10
    )
    assert result.returncode == 0, result.stderr
    assert result.stderr == ""
    return result.stdout.splitlines()


def test_grammar_has_no_conflicts(tmp_path):
    yacc = shutil.which("yacc")
    if yacc is None:
        pytest.skip("yacc is needed to check parser generation")
    result = subprocess.run(
        [yacc, "-dv", "-o", str(tmp_path / "parser.c"), str(ROOT / "src/gram.y")],
        capture_output=True, text=True, timeout=30,
    )
    assert result.returncode == 0, result.stderr
    assert "conflict" not in result.stderr.lower()


@pytest.mark.parametrize("sample", SAMPLES, ids=lambda p: str(p.relative_to(ROOT)))
def test_sample_parses(sample):
    # AST mode also covers platform-specific and intentionally endless samples.
    result = subprocess.run(
        [EXECUTABLE, str(sample), "-p"],
        capture_output=True, text=True, timeout=10,
    )
    assert result.returncode == 0, result.stderr
    assert result.stderr == ""


def test_arithmetic_and_compound_assignments():
    assert run_program("""
        a = 10
        print(a + 2 * 3)
        print(a - 2 - 3)
        print(a / 2 * 3)
        a += 2 * 3
        a -= 1
        a *= 2
        a /= 3
        print(a)
        v = [[10]]
        v[0][0] += 6
        v[0][0] -= 1
        v[0][0] *= 2
        v[0][0] /= 3
        print(v)
    """) == ["16", "5", "15", "10", "[[10]]"]


def test_quotes_and_compound_operators_in_strings():
    assert run_program("""
        print("")
        print('')
        print("a'b")
        print('a"b')
        print(":: += -= *= /=")
        print(':: += -= *= /=')
    """) == ["", "", "a'b", 'a"b', ":: += -= *= /=", ":: += -= *= /="]


def test_slices_with_variable_steps_and_member_indices():
    assert run_program("""
        ;; Index ;; { offset = 1 }
        object = Index()
        start = 1
        step = 2
        values = [0,1,2,3,4,5]
        print(values[start::step])
        print(values[::step])
        print(values[(object::offset)])
        print(values[(object::offset):4])
    """) == ["[2,4]", "[0,2,4]", "1", "[1,2,3]"]


def test_newlines_empty_containers_and_foreach():
    assert run_program("""

        @ empty() {

        }
        empty()
        print({

        })
        dictionary = {
            "a": 1,
            "b": 2

        }
        print(dictionary["b"])
        print(dictionary["a"])
        print([(
            3 ... i) { i }])
        print((
            1 + 2))
        ? [ (
            1 < 2) ] { print("yes") }

    """) == ["{}", "2", "1", "[0,1,2]", "3", "yes"]


@pytest.mark.parametrize("source,output", [
    ("v = [12] v[0] += 6 v[0] -= 2 v[0] *= 3 v[0] /= 4 print(v[0])", "12"),
    ('print([(3 ... i) { ? [ i > 0 ] { i } ~ { 0 } }])', "[0,1,2]"),
    ('a = bigInt(2) print(a + a) print(a + 1) print(1 + a)', "4\n3\n3"),
])
def test_file_execution_cleans_up_owned_and_shared_ast_nodes(tmp_path, source, output):
    script = tmp_path / "cleanup.ric"
    script.write_text(source)
    result = subprocess.run([EXECUTABLE, str(script)], capture_output=True,
                            text=True, timeout=10)
    assert result.returncode == 0, result.stderr
    assert result.stderr == ""
    assert result.stdout.strip() == output
