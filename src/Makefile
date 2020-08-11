CC = gcc

FLEXSPEC = lex.l
YACCSPEC = gram.y

YACCSOURCES = y.tab.c
FLEXSOURCES = lex.yy.c
RIC_SOURCES = main hashtable hooks ast eval lib

RIC_OBJS = $(addsuffix .o, $(RIC_SOURCES))

CFLAGS = Wall Werror O2 Wno-strict-aliasing Wno-unused-result

.PHONY: lex yacc test

%.o: %.c
	$(CC) -c -o $@ $^ $(addprefix -, $(CFLAGS))

ric: lex yacc $(RIC_OBJS)
	$(CC) -o $(@) $(YACCSOURCES) $(FLEXSOURCES) $(RIC_OBJS) 

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
ifeq (, $(shell which flex))
	@echo "flex is not installed, not generating new lexer"
else
	flex $(FLEXSPEC)
endif

yacc: $(YACCSPEC)
ifeq (, $(shell which yacc))
	@echo "yacc is not installed, not generating new parser"
else
	yacc -dtv $(YACCSPEC)
endif

clean:
	@rm -f ric *.o


