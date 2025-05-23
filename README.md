<p align="center">
<img width="300px" src="https://github.com/Ricardicus/ric-script/blob/master/images/icon_round.png?raw=true" />
</p>

![Building and testing](https://github.com/Ricardicus/ric-script/workflows/Building%20and%20testing/badge.svg)
![Building docker image](https://github.com/Ricardicus/ric-script/workflows/Building%20docker%20image/badge.svg)
![Memory leakage detection](https://github.com/Ricardicus/ric-script/workflows/Memory%20leakage%20detection/badge.svg)

# ric-script

I am developing a programming language that resembles Python and Javascript. Imagine Python without the pedantic indentation and Javascript without the semicolons.
In fact, ric-script has zero contrainst regarding line breaks, spaces, tabs or semicolons and you can do what you want in regards to formatting.

It is an interpreted language and I draw a lot of inspiration from Python and Javascript.
The AST is built using yacc and I implement everything in C. 
I am continously working on the interpreter for my language, and it is a work
in progress. In the future I might make it possible to compile the program to some sort 
of intermediate codes that I can build a much smaller
interpreter for (some sort of virtual RISC).
Not sure what target there will be (if so).

The samples folder contains ric scripts with OK syntax; but many of these sample scripts are used
in continous testing and not very "pedagogical" or even commented. I 
will provide some samples here in the README further below that walks through some concepts.

The entire thing has a working title of 'ric-script'. I want to stress that
it is a scripting language and my first three letters sound cool according to me.

<a href="https://ric-script-u5ep8.ondigitalocean.app/doc">Here is a link to more of the language documentation</a>

[You can also access a terminal with the ric-script interpreter included here](https://ric-script-u5ep8.ondigitalocean.app/).

# Build

You can build the interpreter from source for this language on multiple platforms.
I currently support iOSX, Linux and Windows.

On linux or mac use meson or GNU make you build like this: 

```BASH
# fetch the code 
git clone https://github.com/Ricardicus/ric-script && cd ric-script
# on linux or mac
make
# or, with meson:
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
meson builddir
cd builddir
ninja
# Now the interpreter binary 'ric' will be found under
# the folder 'src'
```


For windows only meson works:

```BASH
# fetch the code 
git clone https://github.com/Ricardicus/ric-script && cd ric-script
# set up a python environment
python3 -m venv venv
venv\Source\activate
pip install -r requirements.txt
mkdir install
meson builddir --prefix %cd%\install
cd builddir
ninja
# Ignore the warnings...
ninja install
# Now you have built the program!
# You find it under ..\install\bin\ric.exe
```

# Docker

A containarized node.js app has been developed to test the language.
The docker image exposes the port 3000. 
## Docker example
```BASH
git clone https://github.com/Ricardicus/ric-script
cd ric-script
docker build -t node-ric-script:1.0 .
docker run --rm -d -p 3002:3000 node-ric-script:1.0
```

Now go visit localhost:3002! 

The interpreter is shipped in a terminal that looks like this (after cat'ing the README):

<img src="https://raw.githubusercontent.com/Ricardicus/ric-script/master/images/screenshot-docker-app.png"></img>

### Online ric-script interpreter

I also host the docker server for you to play around with [here](https://ric-script-u5ep8.ondigitalocean.app/).

# Code interpreter

This is a work in progress and the first time I am developing a language.
I expect there are things one can easily solve during the interpretation
that is harder to compile, but I don't bother too much with that at the moment.
I am developing the interpreter and while doing so I decide what features
this language should have.

I will be using **javascript syntax highlighting** for the examples provided below, for the sake of making it look pretty
Therefore, I have to add an additional '//' etc. before comments, since it does not do well with the '#' comment symbol. 

# syntax snapshot: RPN calculator

A calulator in reverse Polish notation can be implemented like this in ric-script:

```javascript
#!/usr/bin/ric
# RPN calculator implementation in ric-script
stack = {"head" : 0, "data" : []}
operators = ["+", "*", "-", "/"]
numberChars = [ (10 ... i) { text(i) } ]

@ isNumber(num) {
  . (num ... c) {
    ? [ !numberChars.contains( c ) ] {
      -> 0
    }
  }
  -> 1
}

@ pop() {
  head = stack["head"]
  ? [ head == 0 ] {
    print("Too few arguments on the stack. Goodbye!")
    exit(2)
  }
  head -= 1
  val = stack["data"][head]
  stack["head"] = head
  -> val
}

@ push (val) {
  head = stack["head"]
  ? [ head >= len(stack["data"]) ] {
    append(stack["data"], val)
  } ~ {
    stack["data"][head] = val
  }
  stack["head"] += 1
}

@ eval (op) {
  ? [ op == '+' ] {
    -> pop() + pop()
  } ~[ op == '-' ] {
    tmp = pop()
    -> pop() - tmp
  } ~[ op == '*' ] {
    -> pop() * pop()
  } ~[ op == '/' ] {
    tmp = pop()
    -> pop() / tmp
  } ~ {
    -> 0
  }
}

print("RPN Calculator (quit by typing 'q'):")

run = 1
. [ run ] {
  in = input(">> ")
  expr = split(in, " ")
  . ( expr ... e ) {
    ? [ e.isNumber() ] {
      push( e.parseInt() )
    } ~[ operators.contains(e) ] {
      s = eval(e)
      push(s)
    } ~[ e.contains("q") ] {
      run = 0
    } ~ {
      print("Sorry, I don't understand this: " + e)
    }
  }
  ? [ stack["head"] > 0 ] {
    print(stack["data"][ stack["head"] - 1 ])
  }
  stack["head"] = 0
  @
}
```

Example of using this calculator:

```BASH
$ ./ric samples/rpn.ric                    
RPN Calculator (quit by typing 'q'):
>> 2 1000 * 10 5 + + 19 100 * 8 10 * 5 + + -
30
>> q
```

# syntax snapshot: RPN calculator (revisited) with classes

A calulator in reverse Polish notation can be implemented like this in ric-script using the syntax for classes:

```javascript
#!/usr/bin/ric
# RPN calculator implementation in ric-script
;; RPN ;; {
  stack = {"head" : 0, "data" : []}
  operators = ["+", "*", "-", "/"]

  @ pop() {
    head = stack["head"]
    ? [ head == 0 ] {
      print("Too few arguments on the stack. Goodbye!")
      exit(2)
    }
    head -= 1
    val = stack["data"][head]
    stack["head"] = head
    -> val
  }

  @ push (val) {
    head = stack["head"]
    ? [ head >= len(stack["data"]) ] {
      append(stack["data"], val)
    } ~ {
      stack["data"][head] = val
    }
    stack["head"] += 1
  }

  @ eval (op) {
    tmp = pop()
    ? [ op == '+' ] {
      -> tmp + pop()
    } ~[ op == '-' ] {
      -> pop() - tmp
    } ~[ op == '*' ] {
      -> tmp * pop()
    } ~[ op == '/' ] {
      -> pop() / tmp
    } ~ {
      print("Error: operator '" + op + "' is not supported")
      exit(1)
    }
  }

  @ printResult() {
    ? [ stack["head"] > 0 ] {
      print(stack["data"][ stack["head"] - 1 ])
    }
  }

  @ getOperators() {
    -> operators
  }

  @ reset () {
    stack["head"] = 0
  }
}

@ isNumber(num) {
  numberChars = [ (10 ... i) { text(i) } ]
  . (num ... c) {
    ? [ ! numberChars.contains( c ) ] {
      -> 0
    }
  }
  -> 1
}

print("RPN Calculator (quit by typing 'q'):")

calc = RPN()
operators = calc::getOperators()
run = 1
. [ run ] {
  in = input(">> ")
  expr = split(in, " ")
  . ( expr ... e ) {
    ? [ e.isNumber() ] {
      calc::push( e.parseInt() )
    } ~[ operators.contains(e) ] {
      s = calc::eval(e)
      calc::push(s)
    } ~[ e.contains("q") ] {
      run = 0
    } ~ {
      print("Sorry, I don't understand this: " + e)
    }
  }
  calc::printResult()
  calc::reset()
  @
}
```

Example of using this calculator:

```BASH
$ ./ric samples/rpn.ric                    
RPN Calculator (quit by typing 'q'):
>> 2 1000 * 10 5 + + 19 100 * 8 10 * 5 + + -
30
>> q
```

# syntax snapshot: Ramanujan 3 formula

Since I use JavaScript syntax highlighting here on GitHub, I have **added /\*\*/** just before the original
ric-script comment symbol **#**.

```javascript
//#!/usr/bin/ric
/*
#
# Ramanujans formula for the number 3
# it should be infinite recursion, but
# I set a limit at 100.
#
# outputs: 3.000000
#
*/

@ ram_three (count, limit) {
  ? [ count == limit ] {
    -> 1.0
  }
  -> sqrt(1 + count * ram_three(count + 1, limit))
}

print(ram_three(2, 100))
```


# syntax snapshot: Multithreading

I have been inspired by Javascript and added the functions **setTimeout** and **setInterval** for
handling multithreading. Since I use JavaScript syntax highlighting here on GitHub, I have **added /\*\*/** just before the original
ric-script comment symbol **#**.

```javascript
//#!/usr/bin/ric
/*
# This program shows how you can create
# different types of thread contexts in
# ricscript. It is inspired by Javascript.
# You can do function calls by timeouts
# over intervals.
# The interval thread stops if the function
# returns a non-zero value.
*/
a = 1

@ iterate () {
  ? [ a > 10 ] {
    -> 1
  }
  a += 1
}

@ end () {
  print("Hi, the shared variable now holds value: " + a)
}

print("Hi I am gonna start some threads...")
print("I have set a variable, named 'a', to: " + a)
print("In 10 seconds, I will read its value again.")
print("By the time, a thread running with an interval")
print("will increment this variables value with each iteration.")
print("Let's begin...")

end.setTimeout(10)
iterate.setInterval(1)

print("I have now launched the threads!")
print("They are running in a separate context.")
print("I will return with an update...")
print("...")

```

The example above outputs:

```
$ ./ric samples/threads.ric
Hi I am gonna start some threads...
I have set a variable, named 'a', to: 1
In 10 seconds, I will read its value again.
By the time, a thread running with an interval
will increment this variables value with each iteration.
Let's begin...
I have now launched the threads!
They are running in a separate context.
I will return with an update...
...
Hi, the shared variable now holds value: 10
```

# syntax snapshot: Multithreading, revisited

Here is an example of how to launch a server and a client thread in ric-script.
The server is an echo-server.

```javascript
#!/usr/bin/ric
# Example of how to use the built in
# socket interface in ric script.
# This is an echo-server.

reads = 10
sends = 10

@ usage () {
  print("usage: " + args[0] + " " + args[1] + " host port content-to-write")
  exit(1) 
}

? [ args.len() < 5 ] {
  usage()
}

@ clientThread () {
  i = 0
  . [ i < sends ] {
    print("Opening connection to host: " + args[2] + ":" + args[3])
    s = socketConnect(args[2], args[3])
    ? [ s < 0 ] {
      print("Failed to create the socket, sorry.. error code: " + s)
      exit(1)
    }

    t = s.socketWrite(args[4])
    ? [ t > 0 ] {
      print("Sent " + t + " bytes to server.")
    }
    s.socketClose()
    sleep(1)
    i += 1
    @
  }
}

@ serverThread () {
  s = socketServer(args[3])
  ? [ s < 0 ] {
    print("Failed to create the socket, sorry..")
    exit(1)
  }

  i = 0
  . [ i < reads ] {
    t = s.socketAccept()
    ? [ t > 0 ] {
      in = t.socketRead(50)
      print("read " + in.len() + " bytes: " + in)
      t.socketWrite(in)
      t.socketClose()
    }
    i += 1
    @
  }

  s.socketClose()
}

# Start server thread immediately
serverThread.setTimeout(0)
# Start client server one second later
clientThread.setTimeout(1)
```

This would output something like this:

```
$ ./ric samples/socketClientServer.ric localhost 8083 hejsan
Opening connection to host: localhost:8083
Sent 6 bytes to server.
read 6 bytes: hejsan
...
```

# syntax snapshot: File listing

Since I use other languages syntax highlighting here on GitHub, I have **added //** just before the original
ric-script comment symbol **#** so it looks alright.

```rust
//#!/usr/bin/ric
//# A script to demonstrate how one can list files using ric-script

@ printUsage() {
  print("usage: " + args[0] + " " + args[1] + " directory")
}

@ listFiles(folder, indent) {
  ( folder.ls() ... file ) {
    fullfile = folder + "/" + file
    ? [ fullfile.isFile() ] {
      printf(" " * indent)
      print(file)
    } ~ {
      ? [ file != '.' ] {
      ? [ file != '..'] {
        printf(" " * indent)
        print(file)
        fullfile.listFiles(indent + 1)
      }}
    }
  }
}

//# argument checking
? [ args.len() < 3 ] {
  printUsage()
  exit(1)
}

? [ isDir(args[2]) ] {
  //# print folder structure
  listFiles(args[2], 0)
} ~ {
  //# not a folder given
  printUsage()
  exit(1)
}
```

# Syntax snapshot: Extended file attributes

On BSD systems (such as Linux and macOS) I have added support for listing, setting, getting and removing
extended file attributes in the file system. Not supported in Windows. 

```javascript
file = "requirements.txt"
s = xattrList(file)
print("xattr's of '" + file + "':")
print(s)

print("Setting some xattributes")

file.xattrSet("user.owner", "Rickard")
file.xattrSet("user.master", "Rickard of course")

print("xattr's of '" + file + "' and values:")
s = file.xattrList()
i = 0
. [ i < s.len() ] {
  val = file.xattrGet(s[i])
  print("    - '" + s[i] + "': '" + val + "'")
  i += 1
  @
}

print("Removing xattributes I just set")
s = xattrList(file)
i = 0
. [ i < s.len() ] {
  file.xattrRm(s[i])
  i += 1
  @
}

s = file.xattrList()
print("xattr's of '" + file + "':")
print(s)
```

outputs:

```
xattr's of 'requirements.txt':
[]
Setting some xattributes
xattr's of 'requirements.txt' and values:
    - 'user.owner': 'Rickard'
    - 'user.master': 'Rickard of course'
Removing xattributes I just set
xattr's of 'requirements.txt':
[]
```

# short walkthrough of some of the language syntax

Since I use JavaScript syntax highlighting here on GitHub, I have **added //** just before the original
ric-script comment symbol **#** so it looks alright.

```javascript
//#!/usr/bin/ric

//# Placing a dot in front of a condition
//# makes it a return spot, operator '@' returns there.
a = 1338

. [ a == 1337 ] {
  print("Now the variable is: " + a)
  print("yey!")
} ~ {
  print("A variable was not 1337, it was: " + a)
  a = 1337
  print("Re-evaluating")
  @
}

//# Defining a function
@ hej (a, b) {
  /*
  # Calling a with b as argument.
  # a should be a function pointer (dynamically type)
  # otherwise execution stops (no exception handling)
  # with error message
  */
  a(b)
}

//# Defining a function
@ willprint (a) {
  print(a)
}

//# Calling out 'hej' function with our 'willprint' function as first argument
willprint.hej("hej")
//# Calling out 'hej' function with standard library 'print' function as first argument
print.hej("hejsan")

//# Dictionary expressions
s = {"hello": "world", "elit": 1337}
print(s)
print(s["hello"])
print(s["elit"])

//# extending with more fields
s["new field"] = 1337
print(s)
print(s["new field"])

//# extending with another dictionary
s["dict"] = {"hello": "world"}
print(s)
print(s["dict"]["hello"])

//# Calling a function pointer in a list and a dictionary
@ foo () { print("foo") }
@ bar () { print("bar") }

d = {"foo": foo, "bar": bar}
d["foo"]()
d["bar"]()

l = [foo, bar]
l[0]()
l[1]()

//# Ric-script classes
;; myClass ;; {
  myMem = "not updated"
  @ myClass () {
    print("I get constructed!")
    print("my memory is: " + myMem)
  }

  @ set(a) {
    myMem = a
  }

  @ get() {
    -> myMem
  }
}

c = myClass()
print(c::get())
c::set("updated from the outside")
print(c::get())

//# first 20 values in the Fibbonacci series generated 
//# using advanced list initialization with a for-each loop.
s = [(20 ... i ) {
  @ fibPos (a) {
    ? [ a == 0 ] { -> 0 }
    ? [ a == 1 ] { -> 1 }
    -> fibPos(a-1) + fibPos(a-2) 
  }
  fibPos(i)
}]
print(s)
```

Outputs:

```
$ ./ric samples/demo.ric
A variable was not 1337, it was: 1338
Re-evaluating
Now the variable is: 1337
yey!
hej
hejsan
{'elit' : 1337, 'hello' : 'world'}
world
1337
{'elit' : 1337, 'hello' : 'world', 'new field' : 1337}
1337
{'dict' : {'hello' : 'world'}, 'elit' : 1337, 'hello' : 'world', 'new field' : 1337}
world
foo
bar
foo
bar
I get constructed!
my memory is: not updated
not updated
updated from the outside
[0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181]
```

For more of a walkthrough check [here](https://ricardicus.se/doc/syntaxwalkthrough.html).

I have also implemented some [Advent of code](https://adventofcode.com/) problems in ric-script in this repo: [https://github.com/Ricardicus/ric-script-advent-of-code](https://github.com/Ricardicus/ric-script-advent-of-code).

## Loading external scripts

Use **load** to import function and class definitions from other ric-scripts:
```
load("another-script.ric")
# Now all functions in 'another-script.ric' is usable here
```

# Todo list

Here is a list of steps taken, and
aims to take in the future:

- [x] Function declarations
- [x] Function calls
- [x] Function pointer
- [x] Variable declarations
- [x] Variable usage
- [x] The '+' operator on strings with string as well as non-string expressions
- [x] Function delaration overloads
- [x] Function delarations as statements
- [x] Function argument passing
- [x] Standard library for print and exit
- [x] Standard library for file output
- [x] Basic test suite (using pytest atm)
- [x] Passing arguments
- [x] Meson build (beside make, for increased portability)
- [x] Vector expressions
- [x] Garbage collector (mark & sweep)
- [x] Passing arguments as vector instead of variables
- [x] Dictionary expressions
- [x] Loading external scripts declarations into script namespace (maybe like pythons \_\_name\_\_)
- [x] Local scope for variables (distinction between global and local)
- [x] Classes
- [x] Better error reporting (always include at least line number)
- [x] Socket interface
- [x] Support for at least swedish UTF-8 characters å, ä and ö. 
- [x] Threading interface
- [x] Dynamic library support
- [x] Built in JSON <-> ric-script dictionary mapping (like Pythons 'json' module)
- [x] Support for huge integers (powered by https://gmplib.org/)
- [x] Some form of variable scope for calling functions (Implemented ID.ID(args) <=> ID(ID, args)
- [x] Possibility to define classes, with functions, in C for export.
- [ ] Nested function declarations that properly catches variable scope (makes it suitable for functional programming).
- [ ] Support for function declarations with different number of parameters but same id without overload
- [ ] Built in support for using xattr-tags instead of file paths when browsing files
- [ ] Better interactive mode, support for multi-lines (single lines is supported in interactive mode, the language is also indifferent to line breaks).
- [ ] Bigger standard library, more battery power (for reference, see: [src/library](https://github.com/Ricardicus/ric-script/blob/master/src/library))


# Interactive prompt

This is implemented as of today in its earliest stage.
What I mean by that, is that you have to do what you want to
do in a single line.. I have not made an effort of deciding
when to keep reading line after another without interpreting.
For example, one typically makes a new line when opening
a body bracket ('{'). In the future, I want to fix this. 
But I am glad that it works anyhow. You can still
do what you want, as long as you keep it on one line.
Fortunately; this language does not care about line breaks and
much can be done in one single line.

```
$ ./ric
RicScript 0.9.1 (linux, Apr 22 2022, 18:17:01)
You are running in interactive mode. Stop it by typing: 'quit'.
This is in it's very early stage... it only supports one liners!

Some short tips:
help() gives you a list of available functions
printVars() lists the names of variables defined in this session
quit() quits this interpreter interactive mode

>> a = 1337
>> print(a)
1337
>> # Making a function declaration, in one line...
>> @ foobar (a) { print(a) }
>> # calling this function
>> foobar(a)
1337
>> quit()
```
# Including batteries

I am contiuously working on this languages [standard library](https://github.com/Ricardicus/ric-script/blob/master/src/library).

If you feel like contributing to this project, I would be more than happy to see some PRs in this department!

## Making your own library functions

There is support for compiling your own code and integrating it in the ric-script interpreter. On Windows this is done with .dll files, on Linux .so and on iOSX .dylib.

Go to src/sdk_lib and study the example there. Study in particual 'ext_lib.c'. It is a Meson project, that can be built like this:

```BASH
cd src/sdk_lib
meson builddir && cd builddir && ninja
```

Now the dynamic library is to be found in the build directory.
What now is required, and I must remind you this is a _work in progress_, is a
file named "ric_modules.txt". In this file, you write the location of this file.
It is best provided as an absolute path, but relative (containing a slash) also works.

You can see if you successfully loaded your dynamic library function by using the _help()_ function available in the interactive mode. It can look like this, after reading a module named 'example_ric':

```
$ ric
RicScript 0.9.1 (linux, Apr 22 2022, 18:17:01)
You are running in interactive mode. Stop it by typing: 'quit'.
This is in it's very early stage... it only supports one liners!

Some short tips:
help() gives you a list of available functions
printVars() lists the names of variables defined in this session
quit() quits this interpreter interactive mode

>> help()
These are the functions I know:
function-name ( number-of-arguments)
- exit ( 1 )
- print ( 1 )
- printf ( 1 )
- append ( 2 )
...
- socketRead ( 2 )
- socketWrite ( 2 )
- socketClose ( 1 )
- socketConnect ( 2 )
These are the modules and functions loaded dynamically:
function-name ( number-of-arguments)
Module    : example_ric
Nbr funcs : 2
Version   : 0.1
  ric_example_print ( 1 )
  example_class ( 0 )
>>
```

# Sublime Text syntax highlightning for ric-script

## Install without Package Control

* Place the file sublime/ricscript.sublime-syntax inside the Sublime Text packages User folder (found under Preferences -> Browse Packages...)
* Restart Sublime Text

## Install with Package Control

* Open Preferences -> Package Control
* Select Add Repository
* Type in: https://github.com/Ricardicus/ric-script-syntax
* Open Preferences -> Package Control
* Select Install Package
* Search for ric-script, find it, click it

# Vim syntax highlighting for ric-script

I use nvim and my configuration files for ric-script can be found under the folder 'vim' here.
The installation guide below is for nvim, but the configuration files are valid for vim also.

## Install ric script syntax highlighter

Place the syntax highlighter file vim/syntax/ric.vim to ~/.config/nvim/syntax/ric.vim
and the file detecter to vim/ftdetect/ric.vim to ~/.config/nvim/ftdetect/ric.vim .

If you are using vim-plug, you can install the ric-script syntax highlighter by inserting
the following line to your run commands file:

```
" ric-script
Plug 'Ricardicus/ric-script.vim'
```

