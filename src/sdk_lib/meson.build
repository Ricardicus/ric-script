project('ric_extended_lib', 'c',
  version : '1.0.0',
  license : 'GPL')

cc = meson.get_compiler('c')

# Adding flags for the parser to be more verbose
ric_c_args = ['-DYYERROR_VERBOSE']
ric_links = []
ext_c_args = []

target_os = target_machine.system()

includes = [
  include_directories('.'),
  include_directories('..'),
  include_directories(
    join_paths('..', 'library')
  )
]

library_sources = [
  join_paths('..','library','libio.c'),
  join_paths('..','library','libmath.c'),
  join_paths('..','library','libstd.c'),
  join_paths('..','library','libstring.c'),
  join_paths('..','library','libload.c'),
  join_paths('..','library','libtime.c'),
  join_paths('..','library','libctx.c')
]

# Handling windows NT vs. unix POSIX differences
if ( target_os == 'windows' )
  library_sources += [
    join_paths('..','library','libos_nt.c'),
    join_paths('..','library','libnet_nt.c')
  ]
  ric_c_args += ['-DNO_XATTR'] 
else
  library_sources += [
    join_paths('..','library','libos.c'),
    join_paths('..','library','libnet.c')
  ]
endif

if ( target_os == 'darwin' ) 
  library_sources += [
    join_paths('..','library','libxattr_darwin.c')
  ]
elif ( target_os == 'linux' )
  library_sources += [
    join_paths('..','library','libxattr_linux.c')
  ]
endif

sources = [
'ext_lib.c',
join_paths('..','hashtable.c'),
join_paths('..','lib.c'),
join_paths('..','garbage.c'),
join_paths('..','ast.c'),
join_paths('..','hooks.c'),
join_paths('..','eval.c'),
join_paths('..','lex.yy.c'),
join_paths('..','y.tab.c'),
  library_sources]

deps = []

links = []

# Multithreading
thread_dep = dependency('threads')
deps += [thread_dep]

if ( target_os == 'windows' )
  # Make lex not use unistd
  ric_c_args += ['-DYY_NO_UNISTD_H']

  compiler = meson.get_compiler('c')
  dep = compiler.find_library('ws2_32', required: true)

  deps += [dep]

  dep = compiler.find_library('wsock32', required: true)

  deps += [dep]
  # Regexp
  ric_links += [pcre_lib]
  includes += [pcre_inc]

  # Adding windows specific translation units 
  sources += [join_paths('..','sync_nt.c'), join_paths('..','dl_nt.c')]
else
  # Math as depencendy, not needed in MSVC but needed elsewhere
  mathlib = cc.find_library('m', required: true)
  deps += [mathlib]

  # Dynamic lib as depencendy
  dllib = cc.find_library('dl', required: true)
  deps += [dllib]

  # Silence some warnings
  ric_c_args += ['-Wno-unused-parameter', '-Wno-unused-function']

  # Adding POSIX translation units (for darwin, linux etc.)
  sources += [join_paths('..','sync.c'), join_paths('..','dl.c')]
endif

if ( target_os == 'windows' )
	ext_c_args += ['-DWIN']
endif

shared_library('ric_extended_lib_example',
  sources,
  c_args: [ext_c_args],
  dependencies: [deps],
  version : '1.0.0', include_directories: [includes])



