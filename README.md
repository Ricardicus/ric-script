![](https://github.com/Ricardicus/ric-script/workflows/Building%20&%20Testing/badge.svg)
![Building docker image](https://github.com/Ricardicus/ric-script/workflows/Building%20docker%20image/badge.svg)

# Work in progress

Parsing layer complete,
will dig into the code generation or interpretation now. 
Not sure what target there will be yet.


The samples folder contains ric scripts with OK syntax.

# Build

On linux or mac use meson or GNU make
For windows only meson works:

```
# on windows
python -m venv venv
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
cd ric_script
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
- [x] Variable declaratons
- [x] Variable usage
- [x] The '+' operator on strings with string as well as non-string expressions
- [x] Function delaration overloads
- [x] Function delarations as statements
- [x] Function argument passing
- [x] Standard library for print and exit
- [x] Standard library for file output
- [x] Basic test suite (using pytest atm)
- [x] Meson build (beside make, for increased portability)
- [ ] Standard library for file input
- [ ] Standard library for stdin reads
- [ ] Standard library for cool stuff
- [ ] Vector expressions and standard library for vector manipulation

# Intermediate code generation

I am thinking of inventing an intermediate bytecode language for this, 
for which I will compile my programs. After that I will
build a virtual machine for this type of bytecodes.
But I will start by implementing an interpreter for the
"real code" in text format. 

# Comments on the syntax

Some remarks and pointers on the language.

## Namespace

For starters I only have **global** name scope.
Now I kind of like it. BASH only has global scope
as stored in the environment. Maybe it will be OK? 

The while/do while/for/foreach loops have been mixed
with the if/else if/else concepts by introducing the
**@** langage construct. I think that is cool!

## Functions

A function declaration is just like any other 
statement. A function call will be called based
on the latest declared function of the given ID. 
One can also redefine a function multiple times. 
This is exemplified in **samples/function_within_function.ric**.


Have a good day!


