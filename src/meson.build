# Building the interpreter

target_os = target_machine.system()

cc = meson.get_compiler('c')

includes = include_directories('.')
sources = ['main.c','hashtable.c','lib.c',
  'ast.c','hooks.c','eval.c','lex.yy.c','y.tab.c']

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

