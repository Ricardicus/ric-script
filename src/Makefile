# Author: Rickard Hallerbäck
#
# Builds the interpreter from scratch.
# If bison is installed, sources for
# a LALR-parser is generated anew. If not,
# I have included sources generated on my own
# system. The LARL-parser and scanner is
# defined by FLEXSPEC and YACCSPEC.
# Yacc generated the parser, flex the scanner.

CC = gcc

FLEXSPEC = lex.l
YACCSPEC = gram.y

# Bison generated sources
YACCSOURCES = y.tab.c
FLEXSOURCES = lex.yy.c

# sources to the implementation of the library
# are placed in this folder
LIB_DIR = library

RIC_SOURCES = \
	main \
	hashtable \
	hooks \
	ast \
	eval \
	lib \
	$(LIB_DIR)/libio \
	$(LIB_DIR)/libmath \
	$(LIB_DIR)/libstd \
	$(LIB_DIR)/libstring


RIC_OBJS = $(addsuffix .o, $(RIC_SOURCES))

CFLAGS = Wall Werror O2 Wno-strict-aliasing Wno-unused-result Wno-unused-parameter

.PHONY: lex yacc test

%.o: %.c
	$(CC) -c -o $@ $^ $(addprefix -, $(CFLAGS)) $(addprefix -I, . $(LIB_DIR))

ric: lex yacc $(RIC_OBJS)
	$(CC) -o $(@) $(YACCSOURCES) $(FLEXSOURCES) $(RIC_OBJS) $(addprefix -I, . $(LIB_DIR))

test: ric
	@echo ""
	@echo "============================================"
	@echo "Content of file 'samples/example.ric'"
	@echo "============================================"
	@cat ../samples/example.ric
	@echo "============================================"
	@echo "Interpretation of file 'samples/example.ric'"
	@echo "============================================"
	@./ric -pi ../samples/example.ric

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


