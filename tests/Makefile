# Requires pytest to be installed

include ../Makefile

.PHONY: meson

test: meson
ifeq (, $(shell which pytest))
	@echo "Error: pytest not installed"
else
	pytest
endif

meson:
ifeq (, $(shell which meson))
	@echo "Error: Meson is not installed"
else
	 @cd ..;meson builddir;cd builddir;ninja
endif

