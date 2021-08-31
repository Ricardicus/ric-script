<p align="center">
<img width="300px" src="https://github.com/Ricardicus/ric-script/blob/master/images/icon_round.png?raw=true" />
</p>

![Building and testing](https://github.com/Ricardicus/ric-script/workflows/Building%20and%20testing/badge.svg)
![Building docker image](https://github.com/Ricardicus/ric-script/workflows/Building%20docker%20image/badge.svg)
![Style linter](https://github.com/Ricardicus/ric-script/workflows/Style%20linter/badge.svg)
![Memory leakage detection](https://github.com/Ricardicus/ric-script/workflows/Memory%20leakage%20detection/badge.svg)

# Work in progress

I am developing a programming language!

It resembles Python and Javascript. Imagine Python without the pedantic indentation and Javascript without the semicolons.

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
Many of the scripts there are made for and used in the test suite,
so not all of them explicitly show the beauty of this language.

The entire thing has a working title of 'ric-script'. I want to stress that
it is a scripting language, and I think 'ric' sounds cool (even if it is a bit self-congratulatory).
But I might change it if someone inspires me to.. 

<a href="https://ric-script-u5ep8.ondigitalocean.app/doc">Here is a link to more of the language documentation</a>

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

The interpreter GUI looks like this:

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
  isNr = 1
  i = 0
  . [ i < len(num) ] {
    ? [ contains( numberChars, num[i] ) ] {
      i = i + 1
      @
    } ~ {
      isNr = 0
    }
  }
  -> isNr
}

@ pop() {
  head = stack["head"]
  ? [ head == 0 ] {
    print("Too few arguments on the stack. Goodbye!")
    exit(2)
  }
  head = head - 1
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
  stack["head"] = head + 1
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
  ( expr ... e ) {
    ? [ isNumber(e) ] {
      push( parseInt(e) )
    } ~[ contains(operators, e) ] {
      s = eval(e)
      push(s)
    } ~[ contains(e, "q") ] {
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
    head = head - 1
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
    stack["head"] = head + 1
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
  isNr = 1
  i = 0
  . [ i < len(num) ] {
    ? [ contains( numberChars, num[i] ) ] {
      i = i + 1
      @
    } ~ {
      isNr = 0
    }
  }
  -> isNr
}

print("RPN Calculator (quit by typing 'q'):")

calc = RPN()
operators = calc::getOperators()
run = 1
. [ run ] {
  in = input(">> ")
  expr = split(in, " ")
  ( expr ... e ) {
    ? [ isNumber(e) ] {
      calc::push( parseInt(e) )
    } ~[ contains(operators, e) ] {
      s = calc::eval(e)
      calc::push(s)
    } ~[ contains(e, "q") ] {
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
#!/usr/bin/ric
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
#!/usr/bin/ric
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
  a = a + 1
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

setTimeout(end, 10)
setInterval(iterate, 1)

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

# syntax snapshot: File listing

Since I use other languages syntax highlighting here on GitHub, I have **added //** just before the original
ric-script comment symbol **#** so it looks alright.

```rust
#!/usr/bin/ric
//# A script to demonstrate how one can list files using ric-script

@ printUsage() {
  print("usage: " + args[0] + " " + args[1] + " directory")
}

@ listFiles(folder, indent) {
  ( ls(folder) ... file ) {
    fullfile = folder + "/" + file
    ? [ isFile(fullfile) ] {
      printf(" " * indent)
      print(file)
    } ~ {
      ? [ file != '.' ] {
      ? [ file != '..'] {
        printf(" " * indent)
        print(file)
        listFiles(fullfile, indent + 1)
      }}
    }
  }
}

//# argument checking
? [ len(args) < 3 ] {
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

xattrSet(file, "user.owner", "Rickard")
xattrSet(file, "user.master", "Rickard of course")

print("xattr's of '" + file + "' and values:")
s = xattrList(file)
i = 0
. [ i < len(s) ] {
  val = xattrGet(file, s[i])
  print("    - '" + s[i] + "': '" + val + "'")
  i = i + 1
  @
}

print("Removing xattributes I just set")
s = xattrList(file)
i = 0
. [ i < len(s) ] {
  xattrRm(file, s[i])
  i = i + 1
  @
}

s = xattrList(file)
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
#!/usr/bin/ric

//# Conditionals
? [ 1 == 1 ] {
  print("True condition")
}

? [ 1 == 0 ] {
  # You shall not pass - Gandalf
} ~ {
  print("Untrue condition")
}

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

//# Lists
h = [ "hej", "hopp" ]
print("len(h): " + len(h))

append(h, "hejsan")

print("len(h): " + len(h))

h = [h, "hoppsan"]

print("len(h): " + len(h))
print("h:")
print(h)
print("Traversing and printing h: ")
print("====================")

i = 0
. [ i < len(h) ] {
  printf("h[" + i + "]: ")
  print(h[i])
  i = i + 1
  @
}

print("====================")

//# Function definitions and pointers

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
hej(willprint, "hej")
//# Calling out 'hej' function with standard library 'print' function as first argument
hej(print, "hejsan")

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
```

Outputs:

```
$ ./ric samples/demo.ric
True condition
Untrue condition
A variable was not 1337, it was: 1338
Re-evaluating
Now the variable is: 1337
yey!
len(h): 2
len(h): 3
len(h): 2
h:
[['hej','hopp','hejsan'],'hoppsan']
Traversing and printing h: 
====================
h[0]: ['hej','hopp','hejsan']
h[1]: hoppsan
====================
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
```

For more of a walkthrough check [here](https://ricardicus.se/doc/syntaxwalkthrough.html).

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
- [ ] Built in JSON <-> ric-script dictionary mapping (like Pythons 'json' module)
- [ ] Possibility to define classes, with functions, in C (this far classes are only implemented in ric-script).
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
You are running in interactive mode. Stop it by typing: 'quit'.
This is in it's very early stage... it only supports one liners!
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

```BASH
$ ric
You are running in interactive mode. Stop it by typing: 'quit'.
This is in it's very early stage... it only supports one liners!
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
These are the modules and functions I have loaded dynamically:
function-name ( number-of-arguments)
Module    : example_ric
Nbr funcs : 1
Version   : 0.1
  ric_example_print ( 1 )
0
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

