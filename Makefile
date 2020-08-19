
# Author: Rickard Hallerbäck
#
# GNU Make is the goto build on most systems
# I work with.

all:
	make -C src
	@mv src/ric ric

clean: 
	make clean -C src

test: 
	make test -C tests

check:
ifeq (, which cpplint)
	@echo "install cpplint before attempting to make check"
else
	cpplint --exclude=src/y.tab.* --exclude=src/lex.yy.c \
--filter=-build/include_subdir,-build/header_guard,-legal/copyright,-build/include_what_you_use,\
-readability/casting,-build/include_subdir,-build/include_order,-readability/multiline_string \
--linelength=130 \
--verbose=5 --recursive src

endif

