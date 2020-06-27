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
conflicts: 3 shift/reduce, 40 reduce/reduce
gcc -o ric y.tab.c lex.yy.c  main.c hashtable.c hooks.c ast.c eval.c 

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
a

# Some math, should print 1337
a / 2 + 1337/ 2 +1337 % 2 

# Declaration
b = " hejsan!"

# Using the declaration
"hello" + " hello!" + b

# Adding strings with numbers and digits and IDs
"hello " + 1337.7 + " " + 14 + " " + a 

# Assigning either 1 or 0 to variables 
# based on conditionals
b = "hello" == "hello"
# Should print 1
b

b = ( "hello" == "hi" )
# Should print 0
b

"10.1 > 10.0: "
b = 10.1 > 10.0
b

"10.1 < 10.0:"
b = 10.1 < 10.0
b

"10.1 <= 10.1:"
b = 10.1 <= 10.1
b

"10.1 >= 10.1:"
b = 10.1 >= 10.1
b

5 "10.1 >= 10.0: "
b = 10.1 >= 10.0
b

"10.1 <= 10.0:"
b = 10.1 <= 10.0
b

[ 1 ] {
  
  # should print 1337
  a = 1337
  a

}

[ b ] {
  
  # should not print 1337
  a = 1337
  a

}

# Some if-else if- else logic
p = 1337
[ p < 1337 ] {
  "Something went wrong.. Not supposed to be in this 'if' section."
} ~[p == 1338] {
 "There is something wrong.. I am in an 'else-if' section.." 
} ~[p == 1337] {
  "Yey, I am in an else-if!"
} ~ {
  "Nope, something isn't right. I am in an 'else' section.."
}

@ foobar() {
  
  b = "hello from foobar"
  b

}

foobar()

# A while loop

i = 0

[ i < 5 ] {
  i = i + 1
  i
  @
}

# A funny feature with this language
a = 1338

[ a == 1337 ] {
  "Now the variable is: " + a
  "yey!"
} ~ {
  "A variable was not 1337, it was: " + a
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
      "a: " + a + ", b: " + b + ", c: " + c
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
  
  "arg1: " + a + ", arg2: " + b + ", arg3: " + c

}

testFunc(14,12, 15)

# System call
$ "echo 'hello, the variable a has the value: " + a + "'"

"Nu e de slut"


============================================
Interpretation of file 'samples/example.ric'
============================================
AST:

[0x7fc7e9405940] Declaration: ID('a'), Expr(2)
[0x7fc7e94059a0] Expr(1337);
[0x7fc7e9405a00] Expr(1.337000);
[0x7fc7e9405b60] Expr(ADD(ADD(1335,1),1));
[0x7fc7e9405cc0] Expr(DIV(1337,ADD(1,2)));
[0x7fc7e9405d50] Declaration: ID('a'), Expr(1337)
[0x7fc7e9405dc0] Expr(ID('a'));
[0x7fc7e94060b0] Expr(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)));
[0x7fc7e9406150] Declaration: ID('b'), Expr(' hejsan!')
[0x7fc7e9406320] Expr(ADD(ADD('hello',' hello!'),ID('b')));
[0x7fc7e9406710] Expr(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')));
[0x7fc7e9406860] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x7fc7e94068d0] Expr(ID('b'));
[0x7fc7e9406a20] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x7fc7e9406a90] Expr(ID('b'));
[0x7fc7e9406b10] Expr('10.100000 > 10.000000: ');
[0x7fc7e9406cd0] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x7fc7e9406d40] Expr(ID('b'));
[0x7fc7e9406d80] Expr('10.100000 < 10.000000:');
[0x7fc7e9406f60] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x7fc7e9406fd0] Expr(ID('b'));
[0x7fc7e9407030] Expr('10.100000 <= 10.100000:');
[0x7fc7e9407200] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x7fc7e9407270] Expr(ID('b'));
[0x7fc7e94072d0] Expr('10.100000 >= 10.100000:');
[0x7fc7e94074a0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x7fc7e9407510] Expr(ID('b'));
[0x7fc7e9407570] Expr(5);
[0x7fc7e9407590] Expr('10.100000 >= 10.000000: ');
[0x7fc7e94077c0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x7fc7e9407830] Expr(ID('b'));
[0x7fc7e9407890] Expr('10.100000 <= 10.000000:');
[0x7fc7e9407a60] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x7fc7e9407ad0] Expr(ID('b'));
[0x7fc7e9407cd0] if-statement - condition: [1] > [0]
[0x7fc7e9407ba0]     Declaration: ID('a'), Expr(1337)
[0x7fc7e9407c10]     Expr(ID('a'));
[0x7fc7e9407ee0] if-statement - condition: [ID('b')] > [0]
[0x7fc7e9407db0]     Declaration: ID('a'), Expr(1337)
[0x7fc7e9407e20]     Expr(ID('a'));
[0x7fc7e9407f70] Declaration: ID('p'), Expr(1337)
[0x7fc7e9604b70] if-statement - condition: [ID('p')] < [1337]
[0x7fc7e9408040]     Expr('Something went wrong Not supposed to be in this 'if' section');
else-if-statement - condition: [ID('p')] == [1338]
[0x7fc7e96040f0]         Expr('There is something wrong I am in an 'else-if' section');
else-if-statement - condition: [ID('p')] == [1337]
[0x7fc7e9604550]         Expr('Yey, I am in an else-if!');
else-statment:
[0x7fc7e9604570]     Expr('Nope, something isn't right I am in an 'else' section');
[0x7fc7e9604d30] Function Declaration: ID('foobar') args()
[0x7fc7e9604c70]         Declaration: ID('b'), Expr('hello from foobar')
[0x7fc7e9604cd0]         Expr(ID('b'));
[0x7fc7e9604d80] Function Call: ID('foobar') args()
[0x7fc7e9604e10] Declaration: ID('i'), Expr(0)
[0x7fc7e96050d0] if-statement - condition: [ID('i')] < [5]
[0x7fc7e9604fe0]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7fc7e9605050]     Expr(ID('i'));
[0x7fc7e9605070]     === CONTINUE ===
[0x7fc7e9605160] Declaration: ID('a'), Expr(1338)
[0x7fc7e9605920] if-statement - condition: [ID('a')] == [1337]
[0x7fc7e96053f0]     Expr(ADD('Now the variable is: ',ID('a')));
[0x7fc7e9605410]     Expr('yey!');
else-statment:
[0x7fc7e9605440]     Expr(ADD('A variable was not 1337, it was: ',ID('a')));
[0x7fc7e96057e0]     Declaration: ID('a'), Expr(1337)
[0x7fc7e9605850]     Expr('Re-evaluating');
[0x7fc7e9605870]     === CONTINUE ===
[0x7fc7e9605960] Expr('================');
[0x7fc7e9605ae0] Expr(' Nested looping');
[0x7fc7e9605bb0] Expr('================');
[0x7fc7e9605d60] Declaration: ID('a'), Expr(0)
[0x7fc7e9606940] if-statement - condition: [ID('a')] < [2]
[0x7fc7e9605e90]     Declaration: ID('b'), Expr(0)
[0x7fc7e96067a0]     if-statement - condition: [ID('b')] < [2]
[0x7fc7e9605fd0]         Declaration: ID('c'), Expr(0)
[0x7fc7e9606600]         if-statement - condition: [ID('c')] < [2]
[0x7fc7e9606460]             Expr(ADD(ADD(ADD(ADD(ADD('a: ',ID('a')),', b: '),ID('b')),', c: '),ID('c')));
[0x7fc7e9606580]             Declaration: ID('c'), Expr(ADD(ID('c'),1))
[0x7fc7e96065a0]             === CONTINUE ===
[0x7fc7e9606720]         Declaration: ID('b'), Expr(ADD(ID('b'),1))
[0x7fc7e9606740]         === CONTINUE ===
[0x7fc7e96068c0]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7fc7e96068e0]     === CONTINUE ===
[0x7fc7e9606980] Expr('================');
[0x7fc7e9607050] Function Declaration: ID('testFunc') args(ID('a'),ID('b'),ID('c'))
[0x7fc7e9606ff0]         Expr(ADD(ADD(ADD(ADD(ADD('arg1: ',ID('a')),', arg2: '),ID('b')),', arg3: '),ID('c')));
[0x7fc7e96071c0] Function Call: ID('testFunc') args(14,12,15)
[0x7fc7e96075e0] System(ADD(ADD('echo 'hello, the variable a has the value: ',ID('a')),'''));
[0x7fc7e9607650] Expr('Nu e de slut');


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

For starters I only have **global** name scope.
Now I kind of like it. BASH only has global scope
as stored in the environment. Maybe it will be OK? 

The while/do while/for/foreach loops have been mixed
with the if/else if/else concepts by introducing the
**@** langage construct. I think that I very cool!

Have a good day!


