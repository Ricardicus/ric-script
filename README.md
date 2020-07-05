# Work in progress

Parsing layer complete,
will dig into the code generation or interpretation now. 
Not sure what target there will be yet.


test.ric contains a program with OK syntax.

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
conflicts: 3 shift/reduce, 44 reduce/reduce
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

[ i < 5 ] {
  i = i + 1
  print(i)
  @
}

# A funny feature with this language
a = 1338

[ a == 1337 ] {
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
[ a < 2 ] {
  b = 0
  [ b < 2 ] {
    c = 0
    [ c < 2 ] {
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

print("Nu e de slut")


============================================
Interpretation of file 'samples/example.ric'
============================================
AST:

[0x7f815d6058b0] Declaration: ID('a'), Expr(2)
[0x7f815d605910] Expr(1337);
[0x7f815d605970] Expr(1.337000);
[0x7f815d605ad0] Expr(ADD(ADD(1335,1),1));
[0x7f815d605c30] Expr(DIV(1337,ADD(1,2)));
[0x7f815d605cc0] Declaration: ID('a'), Expr(1337)
[0x7f815d605d80] Function Call: ID('print') args(ID('a'))
[0x7f815d6060c0] Function Call: ID('print') args(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)))
[0x7f815d606160] Declaration: ID('b'), Expr(' hejsan!')
[0x7f815d606380] Function Call: ID('print') args(ADD(ADD('hello',' hello!'),ID('b')))
[0x7f815d6067c0] Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')))
[0x7f815d606910] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x7f815d6069d0] Function Call: ID('print') args(ID('b'))
[0x7f815d606b20] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x7f815d606be0] Function Call: ID('print') args(ID('b'))
[0x7f815d606c60] Expr('10.100000 > 10.000000: ');
[0x7f815d606e20] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x7f815d606ee0] Function Call: ID('print') args(ID('b'))
[0x7f815d606f20] Expr('10.100000 < 10.000000:');
[0x7f815d607100] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x7f815d6071c0] Function Call: ID('print') args(ID('b'))
[0x7f815d607220] Expr('10.100000 <= 10.100000:');
[0x7f815d6073f0] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x7f815d6074b0] Function Call: ID('print') args(ID('b'))
[0x7f815d607510] Expr('10.100000 >= 10.100000:');
[0x7f815d6076e0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x7f815d6077a0] Function Call: ID('print') args(ID('b'))
[0x7f815d607800] Expr(5);
[0x7f815d607820] Expr('10.100000 >= 10.000000: ');
[0x7f815d4041c0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x7f815d404280] Function Call: ID('print') args(ID('b'))
[0x7f815d4042e0] Expr('10.100000 <= 10.000000:');
[0x7f815d4044b0] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x7f815d404570] Function Call: ID('print') args(ID('b'))
[0x7f815d4047c0] if-statement - condition: [1] > [0]
[0x7f815d404640]     Declaration: ID('a'), Expr(1337)
[0x7f815d404700]     Function Call: ID('print') args(ID('a'))
[0x7f815d404a20] if-statement - condition: [ID('b')] > [0]
[0x7f815d4048a0]     Declaration: ID('a'), Expr(1337)
[0x7f815d404960]     Function Call: ID('print') args(ID('a'))
[0x7f815d404ab0] Declaration: ID('p'), Expr(1337)
[0x7f815d405d50] if-statement - condition: [ID('p')] < [1337]
[0x7f815d404bc0]     Function Call: ID('print') args('Something went wrong Not supposed to be in this 'if' section')
else-if-statement - condition: [ID('p')] == [1337]
[0x7f815d405820]         Function Call: ID('print') args('Yey, I am in an else-if!')
else-if-statement - condition: [ID('p')] == [1338]
[0x7f815d405540]         Function Call: ID('print') args('There is something wrong I am in an 'else-if' section')
else-statment:
[0x7f815d405cd0]     Function Call: ID('print') args('Nope, something isn't right I am in an 'else' section')
[0x7f815d405f70] Function Declaration: ID('foobar') args()
[0x7f815d405e60]         Declaration: ID('b'), Expr('hello from foobar')
[0x7f815d405f10]         Function Call: ID('print') args(ID('b'))
[0x7f815d405fc0] Function Call: ID('foobar') args()
[0x7f815d406050] Declaration: ID('i'), Expr(0)
[0x7f815d406360] if-statement - condition: [ID('i')] < [5]
[0x7f815d406220]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7f815d4062e0]     Function Call: ID('print') args(ID('i'))
[0x7f815d406300]     === CONTINUE ===
[0x7f815d4063f0] Declaration: ID('a'), Expr(1338)
[0x7f815d406ca0] if-statement - condition: [ID('a')] == [1337]
[0x7f815d4066d0]     Function Call: ID('print') args(ADD('Now the variable is: ',ID('a')))
[0x7f815d4067a0]     Function Call: ID('print') args('yey!')
else-statment:
[0x7f815d406ad0]     Function Call: ID('print') args(ADD('A variable was not 1337, it was: ',ID('a')))
[0x7f815d406b60]     Declaration: ID('a'), Expr(1337)
[0x7f815d406bd0]     Expr('Re-evaluating');
[0x7f815d406bf0]     === CONTINUE ===
[0x7f815d406ce0] Expr('================');
[0x7f815d406e60] Expr(' Nested looping');
[0x7f815d406f30] Expr('================');
[0x7f815d4070e0] Declaration: ID('a'), Expr(0)
[0x7f815d407d10] if-statement - condition: [ID('a')] < [2]
[0x7f815d407210]     Declaration: ID('b'), Expr(0)
[0x7f815d407b70]     if-statement - condition: [ID('b')] < [2]
[0x7f815d407350]         Declaration: ID('c'), Expr(0)
[0x7f815d4079d0]         if-statement - condition: [ID('c')] < [2]
[0x7f815d407830]             Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('a: ',ID('a')),', b: '),ID('b')),', c: '),ID('c')))
[0x7f815d407950]             Declaration: ID('c'), Expr(ADD(ID('c'),1))
[0x7f815d407970]             === CONTINUE ===
[0x7f815d407af0]         Declaration: ID('b'), Expr(ADD(ID('b'),1))
[0x7f815d407b10]         === CONTINUE ===
[0x7f815d407c90]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7f815d407cb0]     === CONTINUE ===
[0x7f815d407d50] Expr('================');
[0x7f815d408470] Function Declaration: ID('testFunc') args(ID('a'),ID('b'),ID('c'))
[0x7f815d408410]         Function Call: ID('print') args(ADD(ADD(ADD(ADD(ADD('arg1: ',ID('a')),', arg2: '),ID('b')),', arg3: '),ID('c')))
[0x7f815d4085e0] Function Call: ID('testFunc') args(14,12,15)
[0x7f815d408a00] System(ADD(ADD('echo 'hello, the variable a has the value: ',ID('a')),'''));
[0x7f815d408b20] Function Call: ID('print') args('Nu e de slut')


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


