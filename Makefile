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
	@echo "============================================"
	@echo "Content of file 'samples/example.ric'"
	@echo "============================================"
	@cat samples/example.ric
	@echo "============================================"
	@echo "Interpretation of file 'samples/example.ric'"
	@echo "============================================"
	@./ric -pi samples/example.ric

lex: $(FLEXSPEC)
	flex $(FLEXSPEC)

yacc: $(YACCSPEC)
	yacc -dtv $(YACCSPEC)

clean:
	rm -f main lex.yy.c y.output y.tab.c y.tab.h *.o
