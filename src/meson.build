# Building the interpreter

# Adding flags for the parser to be more verbose
add_global_arguments('-DYYERROR_VERBOSE', language: 'c')

# Fetching the library sources
subdir('library')

target_os = target_machine.system()

cc = meson.get_compiler('c')

includes = [include_directories('.'), library_inc]

sources = ['main.c','hashtable.c','lib.c', 'garbage.c',
  'ast.c','hooks.c','eval.c',
  'lex.yy.c','y.tab.c',
  library_sources]

deps = []

if ( target_os == 'windows' )
	# Make lex not use unistd
	add_global_arguments('-DYY_NO_UNISTD_H', language : 'c')
else
	# Math as depencendy, not needed in MSVC but needed elsewhere
	mathlib = cc.find_library('m', required: true)
	deps = [mathlib]
endif

interpreter = executable('ric',
  sources: [sources],
  dependencies: deps,
  include_directories: [includes]
)

