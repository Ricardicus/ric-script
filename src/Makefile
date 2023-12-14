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

# Set to nothing if not debugging
DEBUG_FLAGS = -g

RIC_SOURCES = \
	main \
	hashtable \
	hooks \
	ast \
	eval \
	lib \
	garbage \
	sync \
	dl \
	interpret \
	print \
	$(LIB_DIR)/libio \
	$(LIB_DIR)/libmath \
	$(LIB_DIR)/libstd \
	$(LIB_DIR)/libstring \
	$(LIB_DIR)/libload \
	$(LIB_DIR)/libos \
	$(LIB_DIR)/libtime \
	$(LIB_DIR)/libnet \
	$(LIB_DIR)/libctx \
	$(LIB_DIR)/libjson \
	$(LIB_DIR)/libbigint \
	$(LIB_DIR)/libcrypto 

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  RIC_SOURCES += $(LIB_DIR)/libxattr_linux
endif
ifeq ($(UNAME_S),Darwin)
  RIC_SOURCES += $(LIB_DIR)/libxattr_darwin
endif

RIC_OBJS = $(addsuffix .o, $(RIC_SOURCES))

DEFINES = YYERROR_VERBOSE 'TARGET_OS="linux"'
ifneq ($(DOCKER_MODE), )
	DEFINES += DOCKER_MODE
endif

LIBS = m pthread dl

CFLAGS = Wall \
	Werror \
	O2 \
	Wno-strict-aliasing \
	Wno-unused-result \
	Wno-unused-parameter \
	Wno-unused-command-line-argument

.PHONY: lex yacc test

EXTERNAL_INCS = $(addprefix external/, \
	cjson-1.7.14 mini-gmp-6.2.1 crypto-algorithms)
EXTERNAL_SRCS = $(addprefix external/, \
	cjson-1.7.14/cJSON.c mini-gmp-6.2.1/mini-gmp.c crypto-algorithms/*.c)

RULES = $(RIC_OBJS:.o=.d)

all: ric

-include $(RULES)

%.d: %.c
	@$(CC) -M -I. $(addprefix -I./, $(EXTERNAL_INCS)) \
	  -I$(LIB_DIR) $< > $@

%.o: %.c
	$(CC) -c -o $@ $< $(addprefix -, $(CFLAGS)) $(addprefix -I, . $(LIB_DIR)) \
	$(addprefix -l, $(LIBS)) $(DEBUG_FLAGS) $(addprefix -D, $(DEFINES)) \
	$(addprefix -I./, $(EXTERNAL_INCS))

ric: lex yacc $(RIC_OBJS) $(RULES)
	$(CC) -o $(@) $(YACCSOURCES) $(FLEXSOURCES) $(EXTERNAL_SRCS) \
	$(RIC_OBJS) $(addprefix -I, . $(LIB_DIR)) \
	$(addprefix -I./, $(EXTERNAL_INCS)) \
	$(addprefix -l, $(LIBS)) $(DEBUG_FLAGS) $(addprefix -D, $(DEFINES))

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
	rm -f ric $(RIC_OBJS) *.d $(LIB_DIR)/*.d



