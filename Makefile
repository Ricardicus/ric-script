CC = gcc

FLEXSPEC = lex.l
YACCSPEC = gram.y

AST_SOURCE = ast.c

.PHONY: lex yacc test

main: lex yacc
	$(CC) -o main main.c hashtable.c hooks.c y.tab.c lex.yy.c ast.c 

test: main
	@echo ""
	@echo "======================"
	@echo "AST of file 'test.ric'"
	@echo "======================"
	@echo ""
	@cat test.ric |./main -p
	@echo ""
	@echo "=========================================="
	@echo "Interpreration of file 'testInterpret.ric'"
	@echo "=========================================="
	@echo ""
	@cat testInterpret.ric|./main -i

lex: $(FLEXSPEC)
	flex $(FLEXSPEC)

yacc: $(YACCSPEC)
	yacc -dtv $(YACCSPEC)

clean:
	rm -f main lex.yy.c y.output y.tab.c y.tab.h *.o
