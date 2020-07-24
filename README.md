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

# Code interpreter

Launching the program with arguments -p or -pi will display 
the program as an abstract syntax tree.
The **make test** command will run an input script into the
program and also output the AST (-pi argument).

Like this:

```
$ make test
flex lex.l
yacc -dtv gram.y
conflicts: 4 shift/reduce, 62 reduce/reduce
gcc -c -o main.o main.c -Wall -Werror -O2
gcc -c -o hashtable.o hashtable.c -Wall -Werror -O2
gcc -c -o hooks.o hooks.c -Wall -Werror -O2
gcc -c -o ast.o ast.c -Wall -Werror -O2
gcc -c -o eval.o eval.c -Wall -Werror -O2
gcc -c -o lib.o lib.c -Wall -Werror -O2
gcc -o ric y.tab.c lex.yy.c main.o hashtable.o hooks.o ast.o eval.o lib.o 

============================================
Content of file 'samples/example.ric'
============================================
# Numbers
a = 2;
1337        
1.337
(1335) + 1 + 1
1337/(1+2)

# Variable declaration
a = 1337

# printing a declare variable
print(a)

# Some math, should print 1337
print(a / 2 + 1337/ 2 +1337 % 2 )

# Declaration
b = " hejsan!"

# Using the declaration
print("hello" + " hello!" + b)

# Adding strings with numbers and digits and IDs
print("hello " + 1337.7 + " " + 14 + " " + a)

# Assigning either 1 or 0 to variables 
# based on conditionals
b = "hello" == "hello"
# Should print 1
print(b)

b = ( "hello" == "hi" )
# Should print 0
print(b)

"10.1 > 10.0: "
b = 10.1 > 10.0
print(b)

"10.1 < 10.0:"
b = 10.1 < 10.0
print(b)

"10.1 <= 10.1:"
b = 10.1 <= 10.1
print(b)

"10.1 >= 10.1:"
b = 10.1 >= 10.1
print(b)

5 "10.1 >= 10.0: "
b = 10.1 >= 10.0
print(b)

"10.1 <= 10.0:"
b = 10.1 <= 10.0
print(b)

[ 1 ] {
  
  # should print 1337
  a = 1337
  print(a)

}

[ b ] {
  
  # should not print 1337
  a = 1337
  print(a)

}

# Some if-else if- else logic
p = 1337
[ p < 1337 ] {
  print("Something went wrong.. Not supposed to be in this 'if' section.")
} ~[p == 1338] {
 print("There is something wrong.. I am in an 'else-if' section..")
} ~[p == 1337] {
  print("Yey, I am in an else-if!")
} ~ {
  print("Nope, something isn't right. I am in an 'else' section..")
}

@ foobar() {
  
  b = "hello from foobar"
  print(b)

}

foobar()

# A while loop

i = 0

. [ i < 5 ] {
  i = i + 1
  print(i)
  @
}

# A funny feature with this language
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

"================"
" Nested looping"
"================"

# Nested loops
a = 0
. [ a < 2 ] {
  b = 0
  . [ b < 2 ] {
    c = 0
    . [ c < 2 ] {
      print ( "a: " + a + ", b: " + b + ", c: " + c )
      c = c + 1
      @
    }
    b = b + 1
    @
  }
  a = a + 1
  @
}

"================"

@ testFunc(a,b,c) {
  
  print("arg1: " + a + ", arg2: " + b + ", arg3: " + c)

}

testFunc(14,12, 15)

# System call via variable
syscall = "echo 'hello from the shell via variable, the variable a has the value: " + a + "'"
$ syscall

# system call directly, not via variable
$ "echo 'hello from the shell directly, the variable a has the value: " + a + "'"

a = 0
. [ a < 4 ] {
  a = a + 1
  print( a )
  # Deciding on wether or not to continue the loop
  [ a >= 2 ] {
    !@
  }
  @
}

print("Nu e de slut")

============================================
Interpretation of file 'samples/example.ric'
============================================
AST:

[0x7f843f404170] Declaration: ID('a'), Expr(2)
[0x7f843f4041d0] Expr(1337);
[0x7f843f404230] Expr(1.337000);
[0x7f843f404390] Expr(ADD(ADD(1335,1),1));
[0x7f843f4044f0] Expr(DIV(1337,ADD(1,2)));
[0x7f843f404580] Declaration: ID('a'), Expr(1337)
[0x7f843f404640] Function Call: ID('print') args(ID('a'))
[0x7f843f404980] Function Call: ID('print') args(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)))
[0x7f843f404a20] Declaration: ID('b'), Expr(' hejsan!')
[0x7f843f404c40] Function Call: ID('print') args(ADD(ADD('hello',' hello!'),ID('b')))
[0x7f843f405080] Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')))
[0x7f843f4051d0] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x7f843f405290] Function Call: ID('print') args(ID('b'))
[0x7f843f4053e0] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x7f843f4054a0] Function Call: ID('print') args(ID('b'))
[0x7f843f405520] Expr('10.100000 > 10.000000: ');
[0x7f843f4056e0] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x7f843f4057a0] Function Call: ID('print') args(ID('b'))
[0x7f843f4057e0] Expr('10.100000 < 10.000000:');
[0x7f843f4059c0] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x7f843f405a80] Function Call: ID('print') args(ID('b'))
[0x7f843f405ae0] Expr('10.100000 <= 10.100000:');
[0x7f843f405cb0] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x7f843f405d70] Function Call: ID('print') args(ID('b'))
[0x7f843f405dd0] Expr('10.100000 >= 10.100000:');
[0x7f843f405fa0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x7f843f406060] Function Call: ID('print') args(ID('b'))
[0x7f843f4060c0] Expr(5);
[0x7f843f4060e0] Expr('10.100000 >= 10.000000: ');
[0x7f843f406310] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x7f843f4063d0] Function Call: ID('print') args(ID('b'))
[0x7f843f406430] Expr('10.100000 <= 10.000000:');
[0x7f843f406600] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x7f843f4066c0] Function Call: ID('print') args(ID('b'))
[0x7f843f406910] if-statement - condition: [1] > [0]
[0x7f843f406790]     Declaration: ID('a'), Expr(1337)
[0x7f843f406850]     Function Call: ID('print') args(ID('a'))
[0x7f843f406b70] if-statement - condition: [ID('b')] > [0]
[0x7f843f4069f0]     Declaration: ID('a'), Expr(1337)
[0x7f843f406ab0]     Function Call: ID('print') args(ID('a'))
[0x7f843f406c00] Declaration: ID('p'), Expr(1337)
[0x7f843f4080b0] if-statement - condition: [ID('p')] < [1337]
[0x7f843f406d10]     Function Call: ID('print') args('Something went wrong.. Not supposed to be in this 'if' section.')
else-if-statement - condition: [ID('p')] == [1337]
[0x7f843f407ae0]         Function Call: ID('print') args('Yey, I am in an else-if!')
else-if-statement - condition: [ID('p')] == [1338]
[0x7f843f407740]         Function Call: ID('print') args('There is something wrong.. I am in an 'else-if' section..')
else-statment:
[0x7f843f407db0]     Function Call: ID('print') args('Nope, something isn't right. I am in an 'else' section..')
[0x7f843f4082d0] Function Declaration: ID('foobar') args()
[0x7f843f4081c0]         Declaration: ID('b'), Expr('hello from foobar')
[0x7f843f408270]         Function Call: ID('print') args(ID('b'))
[0x7f843f408320] Function Call: ID('foobar') args()
[0x7f843f4083b0] Declaration: ID('i'), Expr(0)
[0x7f843f4086c0] loop-if-statement - condition: [ID('i')] < [5]
[0x7f843f408580]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7f843f408640]     Function Call: ID('print') args(ID('i'))
[0x7f843f408660]     === CONTINUE ===
[0x7f843f408750] Declaration: ID('a'), Expr(1338)
[0x7f843f408c20] loop-if-statement - condition: [ID('a')] == [1337]
[0x7f843f505a30]     Function Call: ID('print') args(ADD('Now the variable is: ',ID('a')))
[0x7f843f505b00]     Function Call: ID('print') args('yey!')
else-statment:
[0x7f843f408a00]     Function Call: ID('print') args(ADD('A variable was not 1337, it was: ',ID('a')))
[0x7f843f408a90]     Declaration: ID('a'), Expr(1337)
[0x7f843f408b70]     Function Call: ID('print') args('Re-evaluating')
[0x7f843f408b90]     === CONTINUE ===
[0x7f843f6040e0] Expr('================');
[0x7f843f6041b0] Expr(' Nested looping');
[0x7f843f6042c0] Expr('================');
[0x7f843f7040e0] Declaration: ID('a'), Expr(0)
[0x7f843f704ce0] loop-if-statement - condition: [ID('a')] < [2]
[0x7f843f7041e0]     Declaration: ID('b'), Expr(0)
[0x7f843f704b40]     loop-if-statement - condition: [ID('b')] < [2]
[0x7f843f704320]         Declaration: ID('c'), Expr(0)
[0x7f843f7049a0]         loop-if-statement - condition: [ID('c')] < [2]
[0x7f843f704800]             Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('a: ',ID('a')),', b: '),ID('b')),', c: '),ID('c')))
[0x7f843f704920]             Declaration: ID('c'), Expr(ADD(ID('c'),1))
[0x7f843f704940]             === CONTINUE ===
[0x7f843f704ac0]         Declaration: ID('b'), Expr(ADD(ID('b'),1))
[0x7f843f704ae0]         === CONTINUE ===
[0x7f843f704c60]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7f843f704c80]     === CONTINUE ===
[0x7f843f704d20] Expr('================');
[0x7f843f604950] Function Declaration: ID('testFunc') args(ID('a'),ID('b'),ID('c'))
[0x7f843f6048f0]         Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('arg1: ',ID('a')),', arg2: '),ID('b')),', arg3: '),ID('c')))
[0x7f843f604ac0] Function Call: ID('testFunc') args(14,12,15)
[0x7f843f6051f0] Declaration: ID('syscall'), Expr(ADD(ADD('echo 'hello from the shell via variable, the variable a has the value: ',ID('a')),'''))
[0x7f843f605260] System(ID('syscall'));
[0x7f843f605920] System(ADD(ADD('echo 'hello from the shell directly, the variable a has the value: ',ID('a')),'''));
[0x7f843f6059a0] Declaration: ID('a'), Expr(0)
[0x7f843f605de0] loop-if-statement - condition: [ID('a')] < [4]
[0x7f843f605b70]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7f843f605c30]     Function Call: ID('print') args(ID('a'))
[0x7f843f605d60]     if-statement - condition: [ID('a')] >= [2]
[0x7f843f605d00]         === BREAK ===
[0x7f843f605d80]     === CONTINUE ===
[0x7f843f605f00] Function Call: ID('print') args('Nu e de slut')


OUTPUT:

1337
1.337000
1337
445
1337
1337
hello hello! hejsan!
hello 1337.7000 14 1337
1
0
10.100000 > 10.000000: 
1
10.100000 < 10.000000:
0
10.100000 <= 10.100000:
1
10.100000 >= 10.100000:
1
5
10.100000 >= 10.000000: 
1
10.100000 <= 10.000000:
0
1337
Yey, I am in an else-if!
hello from foobar
1
2
3
4
5
A variable was not 1337, it was: 1338
Re-evaluating
Now the variable is: 1337
yey!
================
 Nested looping
================
a: 0, b: 0, c: 0
a: 0, b: 0, c: 1
a: 0, b: 1, c: 0
a: 0, b: 1, c: 1
a: 1, b: 0, c: 0
a: 1, b: 0, c: 1
a: 1, b: 1, c: 0
a: 1, b: 1, c: 1
================
arg1: 14, arg2: 12, arg3: 15
hello from the shell via variable, the variable a has the value: 2
hello from the shell directly, the variable a has the value: 2
1
2
Nu e de slut
```

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


