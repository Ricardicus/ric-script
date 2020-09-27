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

const { spawn } = require('child_process');
var app = express();
var fs = require('fs');
var bodyParser  = require('body-parser');
var http = require('http').createServer(app);
var io = require('socket.io')(http);

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
  extended: true
}));

/* BASH is used */
var shell = "bash";

/* Output index file */
app.get('/', function(req, res) {
    res.sendFile(__dirname + '/index.html');
});

app.get('/js/:script([a-z][a-z]*)', function(req, res) {
    res.sendFile(__dirname + '/js/' + req.params.script);
});

app.get('/samples/:script([a-z][a-z]*)', function(req, res) {
    var file = __dirname + '/samples/' + req.params.script;
    res.sendFile(file);

    /* Read file content, send it with socket.io */
    fs.readFile(file, "utf8", function(err, data){
        if(err) throw err;

        io.emit("terminal-sample", {message: data});        
    });

});

child = null;

app.post('/interpret', function(req, res) {
  var script = req.body.script;
  var args = req.body.arguments.split(" ");
  var response = "";

  /* Launching child process */
  if ( child != null ) {
    child.kill('SIGTERM');
    io.emit("terminal-refresh", {message: "new script launched"});
  }

  args.unshift('-i');

  console.log(args)

  /* Interpreter MUST be in the path */
  child = spawn("ric", args, {stdio: 'pipe'})

  child.stdout.on('data', function(data) {
      io.emit("terminal-output-stdout", {message: data.toString('utf8')});
  });

  child.stderr.on('data', function(data) {
      io.emit("terminal-output-stderr", {message: data.toString('utf8')});
  });

  child.on('close', (code) => {
    io.emit("terminal-exit-code", {message: code});
  });

  child.stdin.setEncoding('utf-8');
  child.stdin.write(script);
  child.stdin.end();

  res.json({status: "script running", code: 0});
});

/* Redirect the rest to index */
app.get('*', function(req, res) {
    res.redirect('/');
});

io.on('connection', (socket) => {

  socket.on('disconnect', () => {
    /* User disconnected */
  });

});

http.listen(3000, () => {
  console.log('listening on *:3000');
});
