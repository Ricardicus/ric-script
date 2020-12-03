# Building the interpreter

target_os = target_machine.system()

cc = meson.get_compiler('c')

# Adding flags for the parser to be more verbose
ric_c_args = ['-DYYERROR_VERBOSE']
ric_links = []

# Getting external projects
subdir('external')

# Fetching the library sources
subdir('library')

includes = [include_directories('.'), library_inc]

sources = ['main.c','hashtable.c','lib.c', 'garbage.c',
  'ast.c','hooks.c','eval.c',
  'lex.yy.c','y.tab.c',
  library_sources]

deps = []

links = []

if ( target_os == 'windows' )
	# Make lex not use unistd
  ric_c_args += ['-DYY_NO_UNISTD_H']

  compiler = meson.get_compiler('c')
  dep = compiler.find_library('ws2_32', required: true)

  deps += [dep]

  # Regexp
  ric_links += [pcre_lib]
  includes += [pcre_inc]
else
	# Math as depencendy, not needed in MSVC but needed elsewhere
	mathlib = cc.find_library('m', required: true)
	deps = [mathlib]

  # Silence some warnings
  ric_c_args += ['-Wno-unused-parameter', '-Wno-unused-function']
endif

interpreter = executable('ric',
  sources: [sources],
  dependencies: deps,
  c_args: [ric_c_args],
  link_with: [ric_links],
  include_directories: [includes],
  install: true
)

