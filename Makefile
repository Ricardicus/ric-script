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


