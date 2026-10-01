#!/usr/bin/env python3
"""Run each supported sample in isolation and retain its memory-check report."""
import argparse
import concurrent.futures
from pathlib import Path
import re
import shutil
import socket
import subprocess
import sys
import tempfile
import threading
import time

ROOT = Path(__file__).resolve().parents[1]
RPN_INPUT = "2 1000 * 10 5 + + 19 100 * 8 10 * 5 + + -\nq\n"


def socket_peer(name, timeout):
    """Supply the other end for standalone client/server demonstrations."""
    listener = socket.socket()
    listener.bind(("127.0.0.1", 0))
    port = listener.getsockname()[1]
    errors = []
    if name == "socketClient.ric":
        listener.listen(10)
        listener.settimeout(timeout)

        def peer():
            try:
                with listener:
                    for _ in range(10):
                        conn, _ = listener.accept()
                        with conn:
                            conn.settimeout(timeout)
                            conn.recv(50)
            except Exception as exc:
                errors.append(str(exc))
    else:
        listener.close()

        def peer():
            try:
                deadline = time.monotonic() + timeout
                for _ in range(10):
                    while True:
                        try:
                            conn = socket.create_connection(("127.0.0.1", port), timeout=1)
                            break
                        except OSError:
                            if time.monotonic() >= deadline:
                                raise TimeoutError("sample server did not accept connections")
                            time.sleep(0.05)
                    with conn:
                        conn.settimeout(timeout)
                        conn.sendall(b"memory-check")
                        assert conn.recv(50) == b"memory-check", "unexpected echo response"
            except Exception as exc:
                errors.append(str(exc))

    thread = None
    if name != "socketClientServer.ric":
        thread = threading.Thread(target=peer, daemon=True)
        thread.start()
    return port, thread, errors


def check(sample, options):
    name = sample.name
    label = str(sample.relative_to(ROOT / "samples"))
    if name == "load_nt.ric" and sys.platform != "win32":
        return label, "SKIP (Windows path example)", True
    with tempfile.TemporaryDirectory(prefix="ric-memory-") as tmp:
        base = Path(tmp)
        shutil.copytree(ROOT / "samples", base / "samples")
        work = base / "tests"
        work.mkdir()
        shutil.copy(ROOT / "tests" / "requirements.txt", work / "requirements.txt")
        (work / "fixture.py").write_text("# File-search fixture\n")
        script = base / "samples" / sample.relative_to(ROOT / "samples")
        note = ""
        if name == "forever_and_ever.ric":
            source = script.read_text()
            assert source.count(". [ 1 ]") == 1
            script.write_text(source.replace(". [ 1 ]", "count = 0\n  . [ count < 100 ]")
                              .replace("print(message)", "print(message)\n    count += 1"))
            note = " (100-iteration bounded copy)"
        args = {
            "gcd.ric": ["21390", "3210"],
            "args.ric": ["1", "2", "3", "hello"],
            "listFiles.ric": ["../samples/folder"],
            "conditional.ric": ["1", "2", "3", "4"],
        }.get(name, [])
        peer = None
        peer_errors = []
        if name.startswith("socket"):
            port, peer, peer_errors = socket_peer(name, options.timeout)
            args = ([str(port)] if name == "socketServer.ric"
                    else ["127.0.0.1", str(port), "memory-check"])
        report = options.output_dir / (label.replace("/", "_") + ".log")
        command = [str(options.binary), str(script), *args]
        if options.tool == "valgrind":
            command = ["valgrind", "--leak-check=full", "--track-origins=yes",
                       "--show-leak-kinds=all", "--errors-for-leak-kinds=definite,indirect,possible",
                       "--error-exitcode=99", *command]
        else:
            command = ["leaks", "--atExit", "--", *command]
        try:
            result = subprocess.run(command, cwd=work, input=RPN_INPUT if name.startswith("rpn") else "",
                                    text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                    timeout=options.timeout)
            report.write_text(result.stdout)
        except subprocess.TimeoutExpired as exc:
            report.write_bytes(exc.stdout or b"")
            return label, f"FAIL timeout; {report}", False
        if peer is not None:
            peer.join(timeout=1)
            if peer.is_alive() or peer_errors:
                return label, f"FAIL socket fixture: {peer_errors}; {report}", False
        if options.tool == "valgrind":
            expected_exit = 2 if name == "ric_lib.ric" else 0
            clean = result.returncode == expected_exit and bool(
                re.search(r"ERROR SUMMARY: 0 errors", result.stdout))
        else:
            clean = result.returncode == 0 and bool(
                re.search(r"0 leaks? for 0 total leaked bytes", result.stdout))
        return label, ("PASS" + note if clean else f"FAIL exit={result.returncode}; {report}"), clean


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--tool", choices=["valgrind", "leaks"],
                        default="leaks" if sys.platform == "darwin" else "valgrind")
    parser.add_argument("--binary", type=Path, default=ROOT / "ric")
    parser.add_argument("--output-dir", type=Path, default=ROOT / "memory-reports")
    parser.add_argument("--timeout", type=float, default=120)
    parser.add_argument("--jobs", type=int, default=4)
    parser.add_argument("samples", nargs="*", help="Optional sample paths relative to samples/")
    options = parser.parse_args()
    options.binary = options.binary.resolve()
    options.output_dir = options.output_dir.resolve()
    options.output_dir.mkdir(parents=True, exist_ok=True)
    if shutil.which(options.tool) is None:
        parser.error(f"{options.tool} is not installed")
    samples = ([ROOT / "samples" / s for s in options.samples] if options.samples
               else sorted((ROOT / "samples").rglob("*.ric")))
    failures = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=options.jobs) as pool:
        results = pool.map(lambda sample: check(sample, options), samples)
        for name, status, clean in results:
            print(f"{name}: {status}", flush=True)
            failures += not clean
    print(f"Checked {len(samples)} samples; {failures} failures. Reports: {options.output_dir}")
    return int(failures != 0)


if __name__ == "__main__":
    sys.exit(main())
