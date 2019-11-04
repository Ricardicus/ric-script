CC = gcc

FLEXSPEC = lex.l
YACCSPEC = gram.y

AST_SOURCE = ast.c

.PHONY: lex yacc test

main: lex yacc
	$(CC) -c $(AST_SOURCE) -o $(subst .c,.o,$(AST_SOURCE))
	$(CC) -c lex.yy.c
	$(CC) -c y.tab.c ast.c
	$(CC) -o main y.tab.o lex.yy.o $(subst .c,.o,$(AST_SOURCE))

test: main
	cat test.ric | ./main

lex: $(FLEXSPEC)
	flex $(FLEXSPEC)

yacc: $(YACCSPEC)
	yacc -dtv $(YACCSPEC)

clean:
	rm -f lex.yy.c y.output y.tab.c y.tab.h *.o
