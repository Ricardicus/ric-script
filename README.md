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

[0x561c7fc653b0] Declaration: ID('x'), Expr(1.337000)
[0x561c7fc65450] Declaration: ID('sovtid'), Expr(100)
[0x561c7fc654f0] Declaration: ID('a'), Expr(1.337000)
[0x561c7fc65590] Declaration: ID('neg'), Expr(-12)
[0x561c7fc65a90] Declaration: ID('t'), Expr(ADD(ADD(ADD(ADD('hejsan: ',ID('a')),'hej monica hej monica process san'),ID('a')),'tja'))
[0x561c7fc65b20] Function Declaration: ID('foobar') args()
[0x561c7fc67840] Function Declaration: ID('foobar') args(ID('a'),ID('b'),ID('c'))
[0x561c7fc65d80]         Function Call: ID('print') args(ID('t'))
[0x561c7fc65e20]         Declaration: ID('dsadsa'), Expr(312321)
[0x561c7fc65ec0]         Declaration: ID('dsa'), Expr(321)
[0x561c7fc65f60]         Declaration: ID('aaa'), Expr(1337)
[0x561c7fc66210]         Function Declaration: ID('foofoo') args(ID('q'),ID('r'),ID('e'))
[0x561c7fc66180]                 Declaration: ID('dsa'), Expr(32)
[0x561c7fc66340]         Function Declaration: ID('fo') args()
[0x561c7fc662b0]                 Declaration: ID('dsadsadsa'), Expr(1443)
[0x561c7fc665a0]         if-statement - condition: [ID('dsa')] == [ID('aaa')]
        else-if-statement - condition: [ID('dsa')] == [23]
[0x561c7fc66640]         Declaration: ID('i'), Expr(0)
[0x561c7fc668d0]         if-statement - condition: [ID('i')] < [10]
[0x561c7fc66840]             Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x561c7fc66860]             === CONTINUE ===
[0x561c7fc66a20]         if-statement - condition: [ID('dsa')] < [ID('dsa')]
[0x561c7fc66e50]         if-statement - condition: [ID('dsa')] <= [23]
        else-if-statement - condition: [ID('dsa')] <= [2]
[0x561c7fc66ca0]                 Function Call: ID('print') args(ID('dsa'))
        else-if-statement - condition: [ID('dsadsa')] <= [32]
[0x561c7fc670b0]         if-statement - condition: [ID('id')] == [2]
        else-statment:
[0x561c7fc67010]             Function Call: ID('print') args(ID('dsa'))
[0x561c7fc677b0]         if-statement - condition: [ID('dsa')] <= [23]
        else-if-statement - condition: [ID('dsa')] <= [2]
[0x561c7fc67330]                 Function Call: ID('print') args(ID('dsa'))
        else-if-statement - condition: [ID('dsadsa')] <= [32]
[0x561c7fc675e0]                 Function Call: ID('print') args(ID('dsa'),1337,1337.000000)
        else-statment:
[0x561c7fc67710]             Function Call: ID('print') args(ID('sa'))
[0x561c7fc67d80] Declaration: ID('q'), Expr(ADD(ADD(SUB(SUB(ADD(123,ID('d')),MUL(32,4)),2),MOD(MUL(2,ADD(1,2)),2)),1))



==========================================
Interpreration of file 'testInterpret.ric'
==========================================

cat testInterpret.ric|./main -p


PROGRAM:

[0x5626f382d3b0] Declaration: ID('a'), Expr(2)
[0x5626f382d410] Expr(1337);
[0x5626f382d470] Expr(1.337000);
[0x5626f382d5d0] Expr(ADD(ADD(1335,1),1));
[0x5626f382d730] Expr(DIV(1337,ADD(1,2)));
[0x5626f382d7d0] Declaration: ID('a'), Expr(1337)
[0x5626f382d850] Expr(ID('a'));
[0x5626f382db50] Expr(ADD(ADD(DIV(ID('a'),2),DIV(1337,2)),MOD(1337,2)));
[0x5626f382dc90] Declaration: ID('b'), Expr(' hejsan!')
[0x5626f382de50] Expr(ADD(ADD('hello',' hello!'),ID('b')));
[0x5626f382e210] Expr(ADD(ADD(ADD(ADD(ADD('hello ','1337.7000'),' '),'14'),' '),ID('a')));
[0x5626f382e390] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hello']))
[0x5626f382e410] Expr(ID('b'));
[0x5626f382e590] Declaration: ID('b'), Expr(Conditional(['hello'] == ['hi']))
[0x5626f382e610] Expr(ID('b'));
[0x5626f382e6d0] Expr('10.100000 > 10.000000: ');
[0x5626f382e890] Declaration: ID('b'), Expr(Conditional([10.100000] > [10.000000]))
[0x5626f382e910] Expr(ID('b'));
[0x5626f382e970] Expr('10.100000 < 10.000000:');
[0x5626f382eb70] Declaration: ID('b'), Expr(Conditional([10.100000] < [10.000000]))
[0x5626f382ebf0] Expr(ID('b'));
[0x5626f382ecb0] Expr('10.100000 <= 10.100000:');
[0x5626f382ee70] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.100000]))
[0x5626f382eef0] Expr(ID('b'));
[0x5626f382efb0] Expr('10.100000 >= 10.100000:');
[0x5626f382f170] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.100000]))
[0x5626f382f1f0] Expr(ID('b'));
[0x5626f382f250] Expr(5);
[0x5626f382f310] Expr('10.100000 >= 10.000000: ');
[0x5626f382f510] Declaration: ID('b'), Expr(Conditional([10.100000] >= [10.000000]))
[0x5626f382f590] Expr(ID('b'));
[0x5626f382f650] Expr('10.100000 <= 10.000000:');
[0x5626f382f810] Declaration: ID('b'), Expr(Conditional([10.100000] <= [10.000000]))
[0x5626f382f890] Expr(ID('b'));
[0x5626f382fac0] if-statement - condition: [1] > [0]
[0x5626f382f970]     Declaration: ID('a'), Expr(1337)
[0x5626f382f9f0]     Expr(ID('a'));
[0x5626f382fd10] if-statement - condition: [ID('b')] > [0]
[0x5626f382fbc0]     Declaration: ID('a'), Expr(1337)
[0x5626f382fc40]     Expr(ID('a'));
[0x5626f382ff60] Function Declaration: ID('foobar') args()
[0x5626f382fe90]         Declaration: ID('b'), Expr('hello from foobar')
[0x5626f382fed0]         Expr(ID('b'));
[0x5626f382ffc0] Function Call: ID('foobar') args()
[0x5626f3830060] Declaration: ID('i'), Expr(0)
[0x5626f3830370] if-statement - condition: [ID('i')] < [5]
[0x5626f3830260]     Declaration: ID('i'), Expr(ADD(ID('i'),1))
[0x5626f38302e0]     Expr(ID('i'));
[0x5626f3830300]     === CONTINUE ===
[0x5626f3830410] Declaration: ID('a'), Expr(1338)
[0x5626f3830d90] if-statement - condition: [ID('a')] == [1337]
[0x5626f38306f0]     Expr(ADD('Now the variable is: ',ID('a')));
[0x5626f3830750]     Expr('yey!');
else-statment:
[0x5626f3830810]     Expr(ADD('A variable was not 1337, it was: ',ID('a')));
[0x5626f3830bd0]     Declaration: ID('a'), Expr(1337)
[0x5626f3830c90]     Expr('Re-evaluating');
[0x5626f3830cf0]     === CONTINUE ===
[0x5626f3830e10] Expr('Nu e de slut');


cat testInterpret.ric|./main -i
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

