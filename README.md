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
and is found in **testInterpret.ric**. 

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

Will input test.ric into the program and let it output the AST.
Like this:

```
==========================================
Interpreration of file 'testInterpret.ric'
==========================================



PROGRAM:

[0x7fcdf7405940] Declaration: ID('a'), Expr(2)
[0x7fcdf74059a0] Expr(1337);
[0x7fcdf7405a00] Expr(1.337000);
[0x7fcdf7405b60] Expr(ADD(ADD(1335,1),1));
[0x7fcdf7405cc0] Expr(DIV(1337,ADD(1,2)));
[0x7fcdf7405d50] Declaration: ID('a'), Expr(1337)
[0x7fcdf7405dc0] Expr(ID('a'));
[0x7fcdf74060b0] Expr(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)));
[0x7fcdf7406150] Declaration: ID('b'), Expr(' hejsan!')
[0x7fcdf7406320] Expr(ADD(ADD('hello',' hello!'),ID('b')));
[0x7fcdf7406710] Expr(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')));
[0x7fcdf7406860] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x7fcdf74068d0] Expr(ID('b'));
[0x7fcdf7406a20] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x7fcdf7406a90] Expr(ID('b'));
[0x7fcdf7406b10] Expr('10.100000 > 10.000000: ');
[0x7fcdf7406cd0] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x7fcdf7406d40] Expr(ID('b'));
[0x7fcdf7406d80] Expr('10.100000 < 10.000000:');
[0x7fcdf7406f60] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x7fcdf7406fd0] Expr(ID('b'));
[0x7fcdf7407030] Expr('10.100000 <= 10.100000:');
[0x7fcdf7407200] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x7fcdf7407270] Expr(ID('b'));
[0x7fcdf74072d0] Expr('10.100000 >= 10.100000:');
[0x7fcdf74074a0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x7fcdf7407510] Expr(ID('b'));
[0x7fcdf7407570] Expr(5);
[0x7fcdf7407590] Expr('10.100000 >= 10.000000: ');
[0x7fcdf74077c0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x7fcdf7407830] Expr(ID('b'));
[0x7fcdf7407890] Expr('10.100000 <= 10.000000:');
[0x7fcdf7407a60] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x7fcdf7407ad0] Expr(ID('b'));
[0x7fcdf7407cd0] if-statement - condition: [1] > [0]
[0x7fcdf7407ba0]     Declaration: ID('a'), Expr(1337)
[0x7fcdf7407c10]     Expr(ID('a'));
[0x7fcdf7407ee0] if-statement - condition: [ID('b')] > [0]
[0x7fcdf7407db0]     Declaration: ID('a'), Expr(1337)
[0x7fcdf7407e20]     Expr(ID('a'));
[0x7fcdf7407f70] Declaration: ID('p'), Expr(1337)
[0x7fcdf74090e0] if-statement - condition: [ID('p')] < [1337]
[0x7fcdf7408040]     Expr('Something went wrong Not supposed to be in this 'if' section');
else-if-statement - condition: [ID('p')] == [1338]
[0x7fcdf7408580]         Expr('There is something wrong I am in an 'else-if' section');
else-if-statement - condition: [ID('p')] == [1337]
[0x7fcdf7408ac0]         Expr('Yey, I am in an else-if!');
else-statment:
[0x7fcdf7408ae0]     Expr('Nope, something isn't right I am in an 'else' section');
[0x7fcdf74092a0] Function Declaration: ID('foobar') args()
[0x7fcdf74091e0]         Declaration: ID('b'), Expr('hello from foobar')
[0x7fcdf7409240]         Expr(ID('b'));
[0x7fcdf74092f0] Function Call: ID('foobar') args()
[0x7fcdf7409380] Declaration: ID('i'), Expr(0)
[0x7fcdf7409640] if-statement - condition: [ID('i')] < [5]
[0x7fcdf7409550]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7fcdf74095c0]     Expr(ID('i'));
[0x7fcdf74095e0]     === CONTINUE ===
[0x7fcdf74096d0] Declaration: ID('a'), Expr(1338)
[0x7fcdf7409e90] if-statement - condition: [ID('a')] == [1337]
[0x7fcdf7409960]     Expr(ADD('Now the variable is: ',ID('a')));
[0x7fcdf7409980]     Expr('yey!');
else-statment:
[0x7fcdf74099b0]     Expr(ADD('A variable was not 1337, it was: ',ID('a')));
[0x7fcdf7409d50]     Declaration: ID('a'), Expr(1337)
[0x7fcdf7409dc0]     Expr('Re-evaluating');
[0x7fcdf7409de0]     === CONTINUE ===
[0x7fcdf7409ed0] Expr('================');
[0x7fcdf740a050] Expr(' Nested looping');
[0x7fcdf740a120] Expr('================');
[0x7fcdf740a2d0] Declaration: ID('a'), Expr(0)
[0x7fcdf740aeb0] if-statement - condition: [ID('a')] < [2]
[0x7fcdf740a400]     Declaration: ID('b'), Expr(0)
[0x7fcdf740ad10]     if-statement - condition: [ID('b')] < [2]
[0x7fcdf740a540]         Declaration: ID('c'), Expr(0)
[0x7fcdf740ab70]         if-statement - condition: [ID('c')] < [2]
[0x7fcdf740a9d0]             Expr(ADD(ADD(ADD(ADD(ADD('a: ',ID('a')),', b: '),ID('b')),', c: '),ID('c')));
[0x7fcdf740aaf0]             Declaration: ID('c'), Expr(ADD(ID('c'),1))
[0x7fcdf740ab10]             === CONTINUE ===
[0x7fcdf740ac90]         Declaration: ID('b'), Expr(ADD(ID('b'),1))
[0x7fcdf740acb0]         === CONTINUE ===
[0x7fcdf740ae30]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x7fcdf740ae50]     === CONTINUE ===
[0x7fcdf740aef0] Expr('================');
[0x7fcdf740b5c0] Function Declaration: ID('testFunc') args(ID('a'),ID('b'),ID('c'))
[0x7fcdf740b560]         Expr(ADD(ADD(ADD(ADD(ADD('arg1: ',ID('a')),', arg2: '),ID('b')),', arg3: '),ID('c')));
[0x7fcdf740b730] Function Call: ID('testFunc') args(14,12,15)
[0x7fcdf740bb50] System(ADD(ADD('echo 'hello, the variable a has the value: ',ID('a')),'''));
[0x7fcdf740bbc0] Expr('Nu e de slut');


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

Have a good day!


