# Building the interpreter

target_os = target_machine.system()

cc = meson.get_compiler('c')

# Adding flags for the parser to be more verbose
ric_c_args = ['-DYYERROR_VERBOSE']

# Getting external projects
external_links = []
external_inc = []

deps = []
links = []

subdir('library')

includes = [include_directories('.'), library_inc, external_inc]

sources = ['main.c','hashtable.c','lib.c', 'garbage.c',
  'ast.c', 'hooks.c', 'eval.c', 'interpret.c', 'print.c',
  'prioqueue.c', 'lex.yy.c', 'y.tab.c',
  library_sources]

# Multithreading
thread_dep = dependency('threads')
deps += [thread_dep]

target_os = target_machine.system()
ric_c_args += [''.join(['-DTARGET_OS="',target_os,'"'])]

if ( target_os == 'windows' )
	# Make lex not use unistd
  ric_c_args += ['-DYY_NO_UNISTD_H']

  compiler = meson.get_compiler('c')
  dep = compiler.find_library('ws2_32', required: true)

  deps += [dep]

  dep = compiler.find_library('wsock32', required: true)

  deps += [dep]

  # Adding windows specific translation units 
  sources += ['stdin_nt.c', 'sync_nt.c', 'dl_nt.c']
else
	# Math as depencendy, not needed in MSVC but needed elsewhere
	mathlib = cc.find_library('m', required: true)
	deps += [mathlib]

  # Dynamic lib as depencendy
  dllib = cc.find_library('dl', required: true)
  deps += [dllib]

  # Silence some warnings
  ric_c_args += ['-Wno-unused-parameter', '-Wno-unused-function', '-Wno-sign-compare']

  # Adding POSIX translation units (for darwin, linux etc.)
  sources += ['stdin.c', 'sync.c', 'dl.c']
endif

subdir('external')

interpreter = executable('ric',
  sources: [sources],
  dependencies: deps,
  c_args: [ric_c_args],
  link_with: [external_links],
  include_directories: [includes, external_inc],
  install: true
)

