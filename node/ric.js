/*
* This module is used to spawn the ric-script
* interpreter as a child process
*/
const { exec, spawn } = require('child_process');

console.log("Launching a ric-script interpreter");

// Create Interface
function initializeInterpreter() {
  var interpreter = {
      terminal: spawn("ls"),
      handler: console.log
  };

  // Handle Data
  interpreter.terminal.stdout.on('data', (buffer) => {
      interpreter.handler({ type: 'data', data: buffer });
      process.send(buffer.toString('utf8'));
  });

  // Handle Error
  interpreter.terminal.stderr.on('data', (buffer) => {
      interpreter.handler({ type: 'error', data: buffer });
      process.send(buffer.toString('utf8'));
  });

  // Handle Closure
  interpreter.terminal.on('close', () => {
      interpreter.handler({ type: 'closure', data: null });
  });

  return interpreter;
}

var interpreter = initializeInterpreter();

process.on("message", function (message) {
  console.log("got message: " + message);
  interpreter.terminal.stdin.write(message + '\n');
});

