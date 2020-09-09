![Building and testing](https://github.com/Ricardicus/ric-script/workflows/Building%20and%20testing/badge.svg)
![Building docker image](https://github.com/Ricardicus/ric-script/workflows/Building%20docker%20image/badge.svg)
![Style linter](https://github.com/Ricardicus/ric-script/workflows/Style%20linter/badge.svg)
![Memory leakage detection](https://github.com/Ricardicus/ric-script/workflows/Memory%20leakage%20detection/badge.svg)

# Work in progress

I am developing my first programming language!

Parsing layer complete, continously working on the 
interpreter for my language now. In the future I might
make it possible to compile the program to some sort 
of intermediate codes that I can build a much smaller
interpreter for (some sort of virtual RISC).
Not sure what target there will be (if so).

The samples folder contains ric scripts with OK syntax.

# Build

On linux or mac use meson or GNU make
For windows only meson works:

```
# on windows
python3 -m venv venv
venv\Source\activate
pip install -r requirements.txt
meson builddir
cd builddir
ninja
# Now you have built the program!
# Ignore the warnings.....
```

# Docker

A containarized node.js app has been developed to test the langauge.
The container exposes the port 3000. 
## Docker example
```
git clone https://github.com/Ricardicus/ric-script
cd ric-script
docker build -t node-ric-script:1.0 .
docker run --rm -d -p 3002:3000 node-ric-script:1.0
```

Now go visit localhost:3002! 

The interpreter GUI looks like this:

<img src="https://raw.githubusercontent.com/Ricardicus/ric-script/master/images/screenshot-docker-app.png"></img>



# Code interpreter

This is a work in progress, an the first time I am developing a language.
I expect there are things one can easily solve during the interpretation
that is harder to compile, but I don't bother too much with that at the moment.
I am developing the interpreter and while doing so I decide what features
this language should have. Here is a list of steps I have implemented as
well as haven't implemented:

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
- [ ] Dictionary expressions
- [ ] Bigger standard library, more battery power (for reference, see: **src/library**)
- [ ] Passing arguments as vector instead of variables
- [ ] Loading external scripts declarations into script namespace (maybe like pythons \_\_name\_\_)
- [ ] Support for function declarations with different number of parameters but same id without overload
- [ ] Built in support for using xattr-tags instead of file paths when browsing files




# Snapshot of the language syntax

```
# Conditionals
[ 1 == 1 ] {
  print("True condition")
}

[ 1 == 0 ] {
  # You shall not pass - Gandalf
} ~ {
  print("Untrue condition")
}

# Placing a dot in front of a condition
# makes it a return spot, operator '@' returns there.
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

# Lists
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

# Function definitions and pointers

# Defining a function
@ hej (a, b) {
  # Calling a with b as argument.
  # a should be a function pointer (dynamically type)
  # otherwise execution stops (no exception handling)
  # with error message
  a(b)
}

# Defining a function
@ willprint (a) {
  print(a)
}

# Calling out 'hej' function with our 'willprint' function as first argument
hej(willprint, "hej")
# Calling out 'hej' function with standard library 'print' function as first argument
hej(print, "hejsan")
```

## Output:

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
```

