import os
import shutil
import subprocess
import time
from pathlib import Path

import pytest

if os.name == "nt":
    pytest.skip("POSIX terminal tests", allow_module_level=True)

import pty
import select
import termios


@pytest.fixture(scope="module")
def reader_binary(tmp_path_factory):
    compiler = shutil.which("cc")
    if compiler is None:
        pytest.skip("C compiler required")
    folder = tmp_path_factory.mktemp("interactive")
    harness = folder / "reader.c"
    harness.write_text('''
#include <stdio.h>
#include <string.h>
char *readCommand(char *, size_t, const char *);
int main(void) {
  char line[256];
  size_t size = sizeof(line);
  while (readCommand(line, size, "PROMPT> ") != NULL) {
    printf("COMMAND:%s\\n", line);
    if (strcmp(line, "small") == 0) size = 16;
  }
  return 0;
}
''')
    binary = folder / "reader"
    source = Path(__file__).resolve().parents[1] / "src/stdin.c"
    subprocess.run([compiler, "-Wall", "-Wextra", "-Werror", str(harness),
                    str(source), "-o", str(binary)], check=True)
    return binary


class Terminal:
    def __init__(self, binary):
        self.master, self.slave = pty.openpty()
        self.original = termios.tcgetattr(self.slave)
        self.process = subprocess.Popen(
            [str(binary)], stdin=self.slave, stdout=self.slave, stderr=self.slave
        )
        self.read_until(b"PROMPT> ")

    def read_until(self, marker):
        output = b""
        deadline = time.monotonic() + 5
        while marker not in output:
            remaining = deadline - time.monotonic()
            assert remaining > 0, output
            ready, _, _ = select.select([self.master], [], [], remaining)
            assert ready, output
            output += os.read(self.master, 4096)
        return output

    def command(self, data, expected):
        os.write(self.master, data)
        output = self.read_until(b"\r\nPROMPT> ")
        assert b"COMMAND:" + expected + b"\r\n" in output, output

    def close(self):
        if self.process.poll() is None:
            self.process.kill()
        self.process.wait(timeout=5)
        os.close(self.master)
        os.close(self.slave)


@pytest.fixture
def terminal(reader_binary):
    session = Terminal(reader_binary)
    try:
        yield session
    finally:
        session.close()


def test_recent_history_and_navigation(terminal):
    for i in range(110):
        line = str(i).encode()
        terminal.command(line + b"\n", line)
    # Extra Up presses stay at the oldest retained entry. Down returns to
    # the unfinished draft after passing the newest entry.
    terminal.command(b"draft" + b"\x1b[A" * 120 + b"\n", b"10")
    terminal.command(b"draft" + b"\x1b[A" * 3 + b"\x1b[B" * 3 + b"\n", b"draft")
    terminal.command(b"\x1b[A\x7f!\n", b"draf!")


def test_long_commands_and_smaller_recall_buffer(terminal):
    long_line = b"x" * 255
    terminal.command(long_line + b"overflow\n", long_line)
    terminal.command(b"\x1b[A\n", long_line)
    terminal.command(b"small\n", b"small")
    terminal.command(b"\x1b[A\x1b[A\n", b"x" * 15)


def test_ctrl_c_ctrl_d_and_terminal_restoration(terminal):
    terminal.command(b"abandoned\x03", b"")
    terminal.command(b"kept\n", b"kept")
    terminal.command(b"\x1b[A\n", b"kept")
    os.write(terminal.master, b"\x04")
    assert terminal.process.wait(timeout=5) == 0
    restored = termios.tcgetattr(terminal.slave)
    # Some kernels set PENDIN when canonical input is re-enabled.
    restored[3] &= ~getattr(termios, "PENDIN", 0)
    original = terminal.original.copy()
    original[3] &= ~getattr(termios, "PENDIN", 0)
    assert restored == original


def test_redirected_input_and_eof(reader_binary):
    result = subprocess.run([str(reader_binary)], input="one\ntwo\nlast",
                            capture_output=True, text=True, timeout=5)
    assert result.returncode == 0
    assert result.stderr == ""
    assert result.stdout == ("PROMPT> COMMAND:one\nPROMPT> COMMAND:two\n"
                             "PROMPT> COMMAND:last\nPROMPT> ")


def test_incomplete_and_other_escape_sequences(terminal):
    os.write(terminal.master, b"\x1b")
    time.sleep(0.2)
    terminal.command(b"hello\x1b[3~\n", b"hello")
