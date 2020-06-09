# Work in progress

Parsing layer complete,
will dig into the code generation or interpretation now. 
Not sure what target there will be yet.


test.ric contains a program with OK syntax.

# make test

Will input test.ric into the program and let it output the AST.
Like this:

```
cat test.ric | ./main -p

PROGRAM:

Declaration: ID('x'), Expr(1.337000)
Declaration: ID('sovtid'), Expr(100)
Declaration: ID('a'), Expr(1.337000)
Declaration: ID('neg'), Expr(-12)
Declaration: ID('t'), Expr(ADD(ADD(ADD(ADD('hejsan: ',ID('a')),'hej monica hej monica process san'),ID('a')),'tja'))
Function Declaration: ID('foobar') args(ID('a'),ID('b'),ID('c'))
        Function Call: ID('print') args(ID('t'))
        Declaration: ID('dsadsa'), Expr(312321)
        Declaration: ID('dsa'), Expr(321)
        Declaration: ID('aaa'), Expr(1337)
        Function Declaration: ID('foofoo') args(ID('q'),ID('r'),ID('e'))
                Declaration: ID('dsa'), Expr(32)
        Function Declaration: ID('fo') args()
                Declaration: ID('dsadsadsa'), Expr(1443)
        if-statement - condition: [ID('dsa')] == [ID('aaa')]
        else-if-statement - condition: [ID('dsa')] == [23]
        if-statement - condition: [ID('dsa')] < [ID('dsa')]
        if-statement - condition: [ID('dsa')] <= [23]
        else-if-statement - condition: [ID('dsa')] <= [2]
                Function Call: ID('print') args(ID('dsa'))
        else-if-statement - condition: [ID('dsadsa')] <= [32]
        if-statement - condition: [ID('id')] == [2]
        else-statment:
            Function Call: ID('print') args(ID('dsa'))
        if-statement - condition: [ID('dsa')] <= [23]
        else-if-statement - condition: [ID('dsa')] <= [2]
                Function Call: ID('print') args(ID('dsa'))
        else-if-statement - condition: [ID('dsadsa')] <= [32]
                Function Call: ID('print') args(ID('dsa'),1337,1337.000000)
        else-statment:
            Function Call: ID('print') args(ID('sa'))
Declaration: ID('q'), Expr(ADD(ADD(SUB(SUB(ADD(123,ID('d')),MUL(32,4)),2),MOD(MUL(2,ADD(1,2)),2)),1))


```

# Code interpreter

I am now working on an interpreter for this baby script language

```
cat testInterpret.ric |./main -i 

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

```
