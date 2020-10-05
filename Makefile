# Author: Rickard Hallerbäck

all:
	make -C src
	@mv src/ric ric

clean:
	make clean -C src

test:
	make test -C tests

install: all
	cp ric /usr/local/bin

uninstall:
ifeq (, which ric)
	@echo "ric-script has not been installed"
else
	rm $(shell which ric)
endif

cpplint:
ifeq (, which $@)
	@echo "install cpplint before attempting to make cpplint"
else
	cpplint --exclude=src/y.tab.* --exclude=src/lex.yy.c \
--filter=-build/include_subdir,-build/header_guard,-legal/copyright,-build/include_what_you_use,\
-readability/casting,-build/include_subdir,-build/include_order,-readability/multiline_string \
--linelength=130 \
--verbose=5 --recursive src

endif

