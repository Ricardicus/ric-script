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
conflicts: 3 shift/reduce, 48 reduce/reduce
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
  "Re-evaluating"
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

# System call
$ "echo 'hello, the variable a has the value: " + a + "'"

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

print("Nu e de slut")============================================
Interpretation of file 'samples/example.ric'
============================================
AST:

[0x7fcda5c05920] Declaration: ID('a'), Expr(2)
[0x7fcda5c05980] Expr(1337);
[0x7fcda5c059e0] Expr(1.337000);
[0x7fcda5c05b40] Expr(ADD(ADD(1335,1),1));
[0x7fcda5c05ca0] Expr(DIV(1337,ADD(1,2)));
[0x7fcda5c05d30] Declaration: ID('a'), Expr(1337)
[0x7fcda5c05df0] Function Call: ID('print') args(ID('a'))
[0x7fcda5c06130] Function Call: ID('print') args(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)))
[0x7fcda5c061d0] Declaration: ID('b'), Expr(' hejsan!')
[0x7fcda5c063f0] Function Call: ID('print') args(ADD(ADD('hello',' hello!'),ID('b')))
[0x7fcda5c06830] Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')))
[0x7fcda5c06980] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x7fcda5c06a40] Function Call: ID('print') args(ID('b'))
[0x7fcda5c06b90] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x7fcda5c06c50] Function Call: ID('print') args(ID('b'))
[0x7fcda5c06cd0] Expr('10.100000 > 10.000000: ');
[0x7fcda5c06e90] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x7fcda5c06f50] Function Call: ID('print') args(ID('b'))
[0x7fcda5c06f90] Expr('10.100000 < 10.000000:');
[0x7fcda5c07170] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x7fcda5c07230] Function Call: ID('print') args(ID('b'))
[0x7fcda5c07290] Expr('10.100000 <= 10.100000:');
[0x7fcda5c07460] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x7fcda5c07520] Function Call: ID('print') args(ID('b'))
[0x7fcda5c07580] Expr('10.100000 >= 10.100000:');
[0x7fcda5c07750] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x7fcda5c07810] Function Call: ID('print') args(ID('b'))
[0x7fcda5c07870] Expr(5);
[0x7fcda5c07890] Expr('10.100000 >= 10.000000: ');
[0x7fcda5c07ac0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x7fcda5c07b80] Function Call: ID('print') args(ID('b'))
[0x7fcda5c07be0] Expr('10.100000 <= 10.000000:');
[0x7fcda5c07db0] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x7fcda5c07e70] Function Call: ID('print') args(ID('b'))
[0x7fcda5c080c0] if-statement - condition: [1] > [0]
[0x7fcda5c07f40]     Declaration: ID('a'), Expr(1337)
[0x7fcda5c08000]     Function Call: ID('print') args(ID('a'))
[0x7fcda5c08320] if-statement - condition: [ID('b')] > [0]
[0x7fcda5c081a0]     Declaration: ID('a'), Expr(1337)
[0x7fcda5c08260]     Function Call: ID('print') args(ID('a'))
[0x7fcda5c083b0] Declaration: ID('p'), Expr(1337)
[0x7fcda5c09860] if-statement - condition: [ID('p')] < [1337]
[0x7fcda5c084c0]     Function Call: ID('print') args('Something went wrong.. Not supposed to be in this 'if' section.')
else-if-statement - condition: [ID('p')] == [1337]
[0x7fcda5c09290]         Function Call: ID('print') args('Yey, I am in an else-if!')
else-if-statement - condition: [ID('p')] == [1338]
[0x7fcda5c08ef0]         Function Call: ID('print') args('There is something wrong.. I am in an 'else-if' section..')
else-statment:
[0x7fcda5c09560]     Function Call: ID('print') args('Nope, something isn't right. I am in an 'else' section..')
[0x7fcda5c09a80] Function Declaration: ID('foobar') args()
[0x7fcda5c09970]         Declaration: ID('b'), Expr('hello from foobar')
[0x7fcda5c09a20]         Function Call: ID('print') args(ID('b'))
[0x7fcda5c09ad0] Function Call: ID('foobar') args()
[0x7fcda5c09b60] Declaration: ID('i'), Expr(0)
[0x7fcda5c09e70] loop-if-statement - condition: [ID('i')] < [5]
[0x7fcda5c09d30]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7fcda5c09df0]     Function Call: ID('print') args(ID('i'))
[0x7fcda5c09e10]     === CONTINUE ===
[0x7fcda5c09f00] Declaration: ID('a'), Expr(1338)
[0x7fcda5d044a0] loop-if-statement - condition: [ID('a')] == [1337]
[0x7fcda5c0a1e0]     Function Call: ID('print') args(ADD('Now the variable is: ',ID('a')))
[0x7fcda5c0a2b0]     Function Call: ID('print') args('yey!')
else-statment:
[0x7fcda5d042d0]     Function Call: ID('print') args(ADD('A variable was not 1337, it was: ',ID('a')))
[0x7fcda5d04360]     Declaration: ID('a'), Expr(1337)
[0x7fcda5d043d0]     Expr('Re-evaluating');
[0x7fcda5d043f0]     === CONTINUE ===
[0x7fcda5d044e0] Expr('================');
[0x7fcda5d04660] Expr(' Nested looping');
[0x7fcda5d04730] Expr('================');
[0x7fcda5d048e0] Declaration: ID('a'), Expr(0)
[0x7fcda5d05510] loop-if-statement - condition: [ID('a')] < [2]
[0x7fcda5d04a10]     Declaration: ID('b'), Expr(0)
[0x7fcda5d05370]     loop-if-statement - condition: [ID('b')] < [2]
[0x7fcda5d04b50]         Declaration: ID('c'), Expr(0)
[0x7fcda5d051d0]         loop-if-statement - condition: [ID('c')] < [2]
[0x7fcda5d05030]             Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('a: ',ID('a')),', b: '),ID('b')),', c: '),ID('c')))
[0x7fcda5d05150]             Declaration: ID('c'), Expr(ADD(ID('c'),1))
[0x7fcda5d05170]             === CONTINUE ===
[0x7fcda5d052f0]         Declaration: ID('b'), Expr(ADD(ID('b'),1))
[0x7fcda5d05310]         === CONTINUE ===
[0x7fcda5d05490]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7fcda5d054b0]     === CONTINUE ===
[0x7fcda5d05550] Expr('================');
[0x7fcda5c0a630] Function Declaration: ID('testFunc') args(ID('a'),ID('b'),ID('c'))
[0x7fcda5c0a5d0]         Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('arg1: ',ID('a')),', arg2: '),ID('b')),', arg3: '),ID('c')))
[0x7fcda5c0a7a0] Function Call: ID('testFunc') args(14,12,15)
[0x7fcda5c0abc0] System(ADD(ADD('echo 'hello, the variable a has the value: ',ID('a')),'''));
[0x7fcda5c0ac50] Declaration: ID('a'), Expr(0)
[0x7fcda5c0b090] loop-if-statement - condition: [ID('a')] < [4]
[0x7fcda5c0ae20]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7fcda5c0aee0]     Function Call: ID('print') args(ID('a'))
[0x7fcda5c0b010]     if-statement - condition: [ID('a')] >= [2]
[0x7fcda5c0afb0]         === BREAK ===
[0x7fcda5c0b030]     === CONTINUE ===
[0x7fcda5c0b1b0] Function Call: ID('print') args('Nu e de slut')


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
hello, the variable a has the value: 2
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


