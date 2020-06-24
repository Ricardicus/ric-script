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

# make test

Will input test.ric into the program and let it output the AST.
Like this:

```
======================
AST of file 'test.ric'
======================



PROGRAM:

[0x7fd574c05940] Declaration: ID('x'), Expr(1.337000)
[0x7fd574c059d0] Declaration: ID('sovtid'), Expr(100)
[0x7fd574c05a60] Declaration: ID('a'), Expr(1.337000)
[0x7fd574c05af0] Declaration: ID('neg'), Expr(-12)
[0x7fd574c05f10] Declaration: ID('t'), Expr(ADD(ADD(ADD(ADD('hejsan: ',ID('a')),'hej monica hej monica process san'),ID('a')),'tja'))
[0x7fd574c05f70] Function Declaration: ID('foobar') args()
[0x7fd574c078c0] Function Declaration: ID('foobar') args(ID('a'),ID('b'),ID('c'))
[0x7fd574c06180]         Function Call: ID('print') args(ID('t'))
[0x7fd574c06210]         Declaration: ID('dsadsa'), Expr(312321)
[0x7fd574c062a0]         Declaration: ID('dsa'), Expr(321)
[0x7fd574c06330]         Declaration: ID('aaa'), Expr(1337)
[0x7fd574c06570]         Function Declaration: ID('foofoo') args(ID('q'),ID('r'),ID('e'))
[0x7fd574c06510]                 Declaration: ID('dsa'), Expr(32)
[0x7fd574c06660]         Function Declaration: ID('fo') args()
[0x7fd574c06600]                 Declaration: ID('dsadsadsa'), Expr(1443)
[0x7fd574c06870]         if-statement - condition: [ID('dsa')] == [ID('aaa')]
        else-if-statement - condition: [ID('dsa')] == [23]
[0x7fd574c06900]         Declaration: ID('i'), Expr(0)
[0x7fd574c06b50]         if-statement - condition: [ID('i')] < [10]
[0x7fd574c06ad0]             Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7fd574c06af0]             === CONTINUE ===
[0x7fd574c06c70]         if-statement - condition: [ID('dsa')] < [ID('dsa')]
[0x7fd574c07020]         if-statement - condition: [ID('dsa')] <= [23]
        else-if-statement - condition: [ID('dsa')] <= [2]
[0x7fd574c06ea0]                 Function Call: ID('print') args(ID('dsa'))
        else-if-statement - condition: [ID('dsadsa')] <= [32]
[0x7fd574c07230]         if-statement - condition: [ID('id')] == [2]
        else-statment:
[0x7fd574c071a0]             Function Call: ID('print') args(ID('dsa'))
[0x7fd574c07860]         if-statement - condition: [ID('dsa')] <= [23]
        else-if-statement - condition: [ID('dsa')] <= [2]
[0x7fd574c07460]                 Function Call: ID('print') args(ID('dsa'))
        else-if-statement - condition: [ID('dsadsa')] <= [32]
[0x7fd574c076d0]                 Function Call: ID('print') args(ID('dsa'),1337,1337.000000)
        else-statment:
[0x7fd574c077d0]             Function Call: ID('print') args(ID('sa'))
[0x7fd574c07de0] Declaration: ID('q'), Expr(ADD(ADD(SUB(SUB(ADD(123,ID('d')),MUL(32,4)),2),MOD(MUL(2,ADD(1,2)),2)),1))



==========================================
Interpreration of file 'testInterpret.ric'
==========================================



PROGRAM:

[0x5606919ab5a0] Declaration: ID('a'), Expr(2)
[0x5606919ab600] Expr(1337);
[0x5606919ab660] Expr(1.337000);
[0x5606919ab7c0] Expr(ADD(ADD(1335,1),1));
[0x5606919ab920] Expr(DIV(1337,ADD(1,2)));
[0x5606919ab9c0] Declaration: ID('a'), Expr(1337)
[0x5606919aba40] Expr(ID('a'));
[0x5606919abd40] Expr(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)));
[0x5606919abe80] Declaration: ID('b'), Expr(' hejsan!')
[0x5606919ac040] Expr(ADD(ADD('hello',' hello!'),ID('b')));
[0x5606919ac400] Expr(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')));
[0x5606919ac580] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x5606919ac600] Expr(ID('b'));
[0x5606919ac780] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x5606919ac800] Expr(ID('b'));
[0x5606919ac8c0] Expr('10.100000 > 10.000000: ');
[0x5606919aca80] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x5606919acb00] Expr(ID('b'));
[0x5606919acb60] Expr('10.100000 < 10.000000:');
[0x5606919acd60] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x5606919acde0] Expr(ID('b'));
[0x5606919acea0] Expr('10.100000 <= 10.100000:');
[0x5606919ad060] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x5606919ad0e0] Expr(ID('b'));
[0x5606919ad1a0] Expr('10.100000 >= 10.100000:');
[0x5606919ad360] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x5606919ad3e0] Expr(ID('b'));
[0x5606919ad440] Expr(5);
[0x5606919ad500] Expr('10.100000 >= 10.000000: ');
[0x5606919ad700] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x5606919ad780] Expr(ID('b'));
[0x5606919ad840] Expr('10.100000 <= 10.000000:');
[0x5606919ada00] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x5606919ada80] Expr(ID('b'));
[0x5606919adcb0] if-statement - condition: [1] > [0]
[0x5606919adb60]     Declaration: ID('a'), Expr(1337)
[0x5606919adbe0]     Expr(ID('a'));
[0x5606919adf00] if-statement - condition: [ID('b')] > [0]
[0x5606919addb0]     Declaration: ID('a'), Expr(1337)
[0x5606919ade30]     Expr(ID('a'));
[0x5606919ae150] Function Declaration: ID('foobar') args()
[0x5606919ae080]         Declaration: ID('b'), Expr('hello from foobar')
[0x5606919ae0c0]         Expr(ID('b'));
[0x5606919ae1b0] Function Call: ID('foobar') args()
[0x5606919ae250] Declaration: ID('i'), Expr(0)
[0x5606919ae560] if-statement - condition: [ID('i')] < [5]
[0x5606919ae450]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x5606919ae4d0]     Expr(ID('i'));
[0x5606919ae4f0]     === CONTINUE ===
[0x5606919ae600] Declaration: ID('a'), Expr(1338)
[0x5606919aef80] if-statement - condition: [ID('a')] == [1337]
[0x5606919ae8e0]     Expr(ADD('Now the variable is: ',ID('a')));
[0x5606919ae940]     Expr('yey!');
else-statment:
[0x5606919aea00]     Expr(ADD('A variable was not 1337, it was: ',ID('a')));
[0x5606919aedc0]     Declaration: ID('a'), Expr(1337)
[0x5606919aee80]     Expr('Re-evaluating');
[0x5606919aeee0]     === CONTINUE ===
[0x5606919aefa0] Expr('================');
[0x5606919af200] Expr(' Nested looping');
[0x5606919af2e0] Expr('================');
[0x5606919af580] Declaration: ID('a'), Expr(0)
[0x5606919b0350] if-statement - condition: [ID('a')] < [2]
[0x5606919af6e0]     Declaration: ID('b'), Expr(0)
[0x5606919b0180]     if-statement - condition: [ID('b')] < [2]
[0x5606919af840]         Declaration: ID('c'), Expr(0)
[0x5606919affb0]         if-statement - condition: [ID('c')] < [2]
[0x5606919afde0]             Expr(ADD(ADD(ADD(ADD(ADD('a: ',ID('a')),', b: '),ID('b')),', c: '),ID('c')));
[0x5606919aff20]             Declaration: ID('c'), Expr(ADD(ID('c'),1))
[0x5606919aff40]             === CONTINUE ===
[0x5606919b00f0]         Declaration: ID('b'), Expr(ADD(ID('b'),1))
[0x5606919b0110]         === CONTINUE ===
[0x5606919b02c0]     Declaration: ID('a'), Expr(ADD(ID('a'),1))
[0x5606919b02e0]     === CONTINUE ===
[0x5606919b03b0] Expr('================');
[0x5606919b0ca0] Function Declaration: ID('testFunc') args(ID('a'),ID('b'),ID('c'))
[0x5606919b0c10]         Expr(ADD(ADD(ADD(ADD(ADD('arg1: ',ID('a')),', arg2: '),ID('b')),', arg3: '),ID('c')));
[0x5606919b0e20] Function Call: ID('testFunc') args(14,12,15)
[0x5606919b0ee0] Expr('Nu e de slut');


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
Nu e de slut
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



"Nu e de slut"
```

# Code generation

I am thinking of inventing a bytecode language for this, 
for which I will compile my programs. After that I will
build a virtual machine for this type of bytecodes.
But I will start by implementing an interpreter for the
"real code" in text format. 

