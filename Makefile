CC = gcc

FLEXSPEC = lex.l
YACCSPEC = gram.y

YACCSOURCES = y.tab.c
FLEXSOURCES = lex.yy.c 
RIC_SOURCES = main.c hashtable.c hooks.c ast.c eval.c

.PHONY: lex yacc test

main: lex yacc
	$(CC) -o main $(YACCSOURCES) $(FLEXSOURCES) $(RIC_SOURCES) 

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
