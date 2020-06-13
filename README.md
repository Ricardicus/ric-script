# Work in progress

Parsing layer complete,
will dig into the code generation or interpretation now. 
Not sure what target there will be yet.


test.ric contains a program with OK syntax.

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

[0x7fdcf6405940] Declaration: ID('a'), Expr(2)
[0x7fdcf64059a0] Expr(1337);
[0x7fdcf6405a00] Expr(1.337000);
[0x7fdcf6405b60] Expr(ADD(ADD(1335,1),1));
[0x7fdcf6405cc0] Expr(DIV(1337,ADD(1,2)));
[0x7fdcf6405d50] Declaration: ID('a'), Expr(1337)
[0x7fdcf6405dc0] Expr(ID('a'));
[0x7fdcf64060b0] Expr(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)));
[0x7fdcf6406150] Declaration: ID('b'), Expr(' hejsan!')
[0x7fdcf6406320] Expr(ADD(ADD('hello',' hello!'),ID('b')));
[0x7fdcf6406710] Expr(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')));
[0x7fdcf6406860] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x7fdcf64068d0] Expr(ID('b'));
[0x7fdcf6406a20] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x7fdcf6406a90] Expr(ID('b'));
[0x7fdcf6406b10] Expr('10.100000 > 10.000000: ');
[0x7fdcf6406cd0] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x7fdcf6406d40] Expr(ID('b'));
[0x7fdcf6406d80] Expr('10.100000 < 10.000000:');
[0x7fdcf6406f60] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x7fdcf6406fd0] Expr(ID('b'));
[0x7fdcf6407030] Expr('10.100000 <= 10.100000:');
[0x7fdcf6407200] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x7fdcf6407270] Expr(ID('b'));
[0x7fdcf64072d0] Expr('10.100000 >= 10.100000:');
[0x7fdcf64074a0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x7fdcf6407510] Expr(ID('b'));
[0x7fdcf6407570] Expr(5);
[0x7fdcf6407590] Expr('10.100000 >= 10.000000: ');
[0x7fdcf64077c0] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x7fdcf6407830] Expr(ID('b'));
[0x7fdcf6407890] Expr('10.100000 <= 10.000000:');
[0x7fdcf6407a60] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x7fdcf6407ad0] Expr(ID('b'));
[0x7fdcf6407cd0] if-statement - condition: [1] > [0]
[0x7fdcf6407ba0]     Declaration: ID('a'), Expr(1337)
[0x7fdcf6407c10]     Expr(ID('a'));
[0x7fdcf6407ee0] if-statement - condition: [ID('b')] > [0]
[0x7fdcf6407db0]     Declaration: ID('a'), Expr(1337)
[0x7fdcf6407e20]     Expr(ID('a'));
[0x7fdcf64080b0] Function Declaration: ID('foobar') args()
[0x7fdcf6407ff0]         Declaration: ID('b'), Expr('hello from foobar')
[0x7fdcf6408050]         Expr(ID('b'));
[0x7fdcf6408100] Function Call: ID('foobar') args()
[0x7fdcf6408190] Declaration: ID('i'), Expr(0)
[0x7fdcf6408450] if-statement - condition: [ID('i')] < [5]
[0x7fdcf6408360]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7fdcf64083d0]     Expr(ID('i'));
[0x7fdcf64083f0]     === CONTINUE ===
[0x7fdcf64084e0] Declaration: ID('a'), Expr(1338)
[0x7fdcf6408ca0] if-statement - condition: [ID('a')] == [1337]
[0x7fdcf6408770]     Expr(ADD('Now the variable is: ',ID('a')));
[0x7fdcf6408790]     Expr('yey!');
else-statment:
[0x7fdcf64087c0]     Expr(ADD('A variable was not 1337, it was: ',ID('a')));
[0x7fdcf6408b60]     Declaration: ID('a'), Expr(1337)
[0x7fdcf6408bd0]     Expr('Re-evaluating');
[0x7fdcf6408bf0]     === CONTINUE ===
[0x7fdcf6408d30] Declaration: ID('q'), Expr(0)
[0x7fdcf6409550] if-statement - condition: [ID('q')] < [4]
[0x7fdcf6408e70]     Declaration: ID('i'), Expr(0)
[0x7fdcf6409340]     if-statement - condition: [ID('i')] < [4]
[0x7fdcf64091a0]         Expr(ADD(ADD(ADD('q: ',ID('q')),', i: '),ID('i')));
[0x7fdcf64092c0]         Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x7fdcf64092e0]         === CONTINUE ===
[0x7fdcf6409460]     Declaration: ID('q'), Expr(ADD(ID('q'),1))
[0x7fdcf64094d0]     Expr(ID('q'));
[0x7fdcf64094f0]     === CONTINUE ===
[0x7fdcf64095c0] Expr('Nu e de slut');


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
q: 0, i: 0
q: 0, i: 1
q: 0, i: 2
q: 0, i: 3
1
q: 1, i: 0
q: 1, i: 1
q: 1, i: 2
q: 1, i: 3
2
q: 2, i: 0
q: 2, i: 1
q: 2, i: 2
q: 2, i: 3
3
q: 3, i: 0
q: 3, i: 1
q: 3, i: 2
q: 3, i: 3
4
Nu e de slut


```

# Code interpreter

I am now working on an interpreter for this baby script language

# Code generation

I am thinking of inventing a bytecode language for this, 
for which I will compile my programs. After that I will
build a virtual machine for this type of bytecodes.
But I will start by implementing an interpreter for the
"real code" in text format. 

