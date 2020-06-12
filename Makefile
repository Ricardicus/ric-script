CC = gcc

FLEXSPEC = lex.l
YACCSPEC = gram.y

YACCSOURCES = y.tab.c
FLEXSOURCES = lex.yy.c 
RIC_SOURCES = main.c hashtable.c hooks.c ast.c eval.c

.PHONY: lex yacc test

ric: lex yacc
	$(CC) -o $(@) $(YACCSOURCES) $(FLEXSOURCES) $(RIC_SOURCES) 

test: ric
	@echo ""
	@echo "======================"
	@echo "AST of file 'test.ric'"
	@echo "======================"
	@echo ""
	@./ric -p test.ric
	@echo ""
	@echo "=========================================="
	@echo "Interpreration of file 'testInterpret.ric'"
	@echo "=========================================="
	@echo ""
	@./ric -p testInterpret.ric
	@./ric -i testInterpret.ric

lex: $(FLEXSPEC)
	flex $(FLEXSPEC)

yacc: $(YACCSPEC)
	yacc -dtv $(YACCSPEC)

clean:
	rm -f main lex.yy.c y.output y.tab.c y.tab.h *.o
