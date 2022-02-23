/* Interactive shell */

/*
*
* In order for this program to work,
* ric-script interpretor must be placed
* in the path.
*
* This will not work on a Windows machine.
*
*/

var express = require('express')

const { spawn, spawnSync } = require('child_process');
const Stream = require('stream');
var app = express();
var fs = require('fs');
var bodyParser  = require('body-parser');
var http = require('http').createServer(app);
var io = require('socket.io')(http);

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
  extended: true
}));
app.use(express.static(__dirname + '/public'));

var startDir = false;
if ( process.argv.length >= 3 ) {
  startDir = process.argv[2];
}

/* BASH is used */
var shell = "bash";

/* Output index file */
app.get('/', function(req, res) {
    res.sendFile(__dirname + '/index.html');
});

app.get('/node_modules/*', function(req, res) {
        res.sendFile(__dirname + req.originalUrl);
});

child = null;

// Create Interface
function initializeInterface(socket) {
  var interface = {
      terminal: spawn("./ric"),
      handler: console.log,
      send: (data) => {
          interface.terminal.stdin.write(data + '\n');
      },
      cwd: () => {
          let cwd = fs.readlinkSync('/proc/' + interface.terminal.pid + '/cwd');
          interface.handler({ type: 'cwd', data: cwd });
      }
  };

  // Handle Data
  interface.terminal.stdout.on('data', (buffer) => {
      interface.handler({ type: 'data', data: buffer });
      socket.emit("terminal-output-stdout", {message: buffer.toString('utf8')});
  });

  // Handle Error
  interface.terminal.stderr.on('data', (buffer) => {
      interface.handler({ type: 'error', data: buffer });
      socket.emit("terminal-output-stderr", {message: buffer.toString('utf8')});
  });

  // Handle Closure
  interface.terminal.on('close', () => {
      interface.handler({ type: 'closure', data: null });
      socket.emit("terminal-exit-code", {message: 1337});
  });

  return interface;
}

function closeInterface(interface) {
  interface.terminal.kill("SIGTERM");
}

/* Redirect the rest to index */
app.get('*', function(req, res) {
    res.redirect('/');
});

io.on('connection', (socket) => {
  if ( startDir ) {
    process.chdir(startDir);
  }

  var interface = initializeInterface(socket);

  socket.on('disconnect', () => {
    /* User disconnected */
    closeInterface(interface);
  });

  socket.on('input', (command) => {
    interface.send(command);
  });
});

http.listen(3000, () => {
  console.log('listening on *:3000');
});
