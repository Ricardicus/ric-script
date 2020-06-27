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
pip install meson
meson builddir
cd builddir
ninja
# Now you have built the program!
# Ignore the warnings.....
```

# Code interpreter

I am now working on an interpreter for this baby script language
The following code is ric-script that is currently supported
and is found in **samples/example.ric**. 

```
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

```


# make test

Will input script into the program and let it output the AST.
Like this:

```
============================================
Interpretation of file 'samples/example.ric'
============================================
AST:

[0x7f829dd040f0] Declaration: ID('a'), Expr(2)
[0x7f829dd04150] Expr(1337);
[0x7f829dd041b0] Expr(1.337000);
[0x7f829dd04310] Expr(ADD(ADD(1335,1),1));
[0x7f829dd04470] Expr(DIV(1337,ADD(1,2)));
[0x7f829dd04500] Declaration: ID('a'), Expr(1337)
[0x7f829dd04570] Expr(ID('a'));
[0x7f829dd04860] Expr(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)));
[0x7f829dd04900] Declaration: ID('b'), Expr(' hejsan!')
[0x7f829dd04ad0] Expr(ADD(ADD('hello',' hello!'),ID('b')));
[0x7f829dd04ec0] Expr(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')));
[0x7f829dd05010] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x7f829dd05080] Expr(ID('b'));
[0x7f829dd051d0] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x7f829dd05240] Expr(ID('b'));
[0x7f829dd052c0] Expr('10.100000 > 10.000000: ');
[0x7f829dd05480] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x7f829dd054f0] Expr(ID('b'));
[0x7f829dd05530] Expr('10.100000 < 10.000000:');
[0x7f829dd05710] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x7f829dd05780] Expr(ID('b'));
[0x7f829dd057e0] Expr('10.100000 <= 10.100000:');
[0x7f829dd059b0] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x7f829dd05a20] Expr(ID('b'));
[0x7f829dd05a80] Expr('10.100000 >= 10.100000:');
[0x7f829dd05c50] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x7f829dd05cc0] Expr(ID('b'));
[0x7f829dd05d20] Expr(5);
[0x7f829dd05d40] Expr('10.100000 >= 10.000000: ');
[0x7f829dd05f70] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x7f829dd05fe0] Expr(ID('b'));
[0x7f829dd06040] Expr('10.100000 <= 10.000000:');
[0x7f829dd06210] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x7f829dd06280] Expr(ID('b'));
[0x7f829dd06480] if-statement - condition: [1] > [0]
[0x7f829dd06350]     Declaration: ID('a'), Expr(1337)
[0x7f829dd063c0]     Expr(ID('a'));
[0x7f829dd06690] if-statement - condition: [ID('b')] > [0]
[0x7f829dd06560]     Declaration: ID('a'), Expr(1337)
[0x7f829dd065d0]     Expr(ID('a'));
[0x7f829dd06720] Declaration: ID('p'), Expr(1337)
[0x7f829dd07890] if-statement - condition: [ID('p')] < [1337]
[0x7f829dd067f0]     Expr('Something went wrong Not supposed to be in this 'if' section');
else-if-statement - condition: [ID('p')] == [1338]
[0x7f829dd06d30]         Expr('There is something wrong I am in an 'else-if' section');
else-if-statement - condition: [ID('p')] == [1337]
[0x7f829dd07270]         Expr('Yey, I am in an else-if!');
else-statment:
[0x7f829dd07290]     Expr('Nope, something isn't right I am in an 'else' section');
[0x7f829dd07a50] Function Declaration: ID('foobar') args()
[0x7f829dd07990]         Declaration: ID('b'), Expr('hello from foobar')
[0x7f829dd079f0]         Expr(ID('b'));
[0x7f829dd07aa0] Function Call: ID('foobar') args()
[0x7f829dd07b30] Declaration: ID('i'), Expr(0)
[0x7f829dd07df0] if-statement - condition: [ID('i')] < [5]
[0x7f829dd07d00]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7f829dd07d70]     Expr(ID('i'));
[0x7f829dd07d90]     === CONTINUE ===
[0x7f829dd07e80] Declaration: ID('a'), Expr(1338)
[0x7f829dd08640] if-statement - condition: [ID('a')] == [1337]
[0x7f829dd08110]     Expr(ADD('Now the variable is: ',ID('a')));
[0x7f829dd08130]     Expr('yey!');
else-statment:
[0x7f829dd08160]     Expr(ADD('A variable was not 1337, it was: ',ID('a')));
[0x7f829dd08500]     Declaration: ID('a'), Expr(1337)
[0x7f829dd08570]     Expr('Re-evaluating');
[0x7f829dd08590]     === CONTINUE ===
[0x7f829dd08680] Expr('================');
[0x7f829dd08800] Expr(' Nested looping');
[0x7f829dd088d0] Expr('================');
[0x7f829dd08a80] Declaration: ID('a'), Expr(0)
[0x7f829dd09660] if-statement - condition: [ID('a')] < [2]
[0x7f829dd08bb0]     Declaration: ID('b'), Expr(0)
[0x7f829dd094c0]     if-statement - condition: [ID('b')] < [2]
[0x7f829dd08cf0]         Declaration: ID('c'), Expr(0)
[0x7f829dd09320]         if-statement - condition: [ID('c')] < [2]
[0x7f829dd09180]             Expr(ADD(ADD(ADD(ADD(ADD('a: ',ID('a')),', b: '),ID('b')),', c: '),ID('c')));
[0x7f829dd092a0]             Declaration: ID('c'), Expr(ADD(ID('c'),1))
[0x7f829dd092c0]             === CONTINUE ===
[0x7f829dd09440]         Declaration: ID('b'), Expr(ADD(ID('b'),1))
[0x7f829dd09460]         === CONTINUE ===
[0x7f829dd095e0]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7f829dd09600]     === CONTINUE ===
[0x7f829dd096a0] Expr('================');
[0x7f829dd09d70] Function Declaration: ID('testFunc') args(ID('a'),ID('b'),ID('c'))
[0x7f829dd09d10]         Expr(ADD(ADD(ADD(ADD(ADD('arg1: ',ID('a')),', arg2: '),ID('b')),', arg3: '),ID('c')));
[0x7f829dd09ee0] Function Call: ID('testFunc') args(14,12,15)
[0x7f829dd0a300] System(ADD(ADD('echo 'hello, the variable a has the value: ',ID('a')),'''));
[0x7f829dd0a370] Expr('Nu e de slut');


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

# Code generation

I am thinking of inventing a bytecode language for this, 
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


