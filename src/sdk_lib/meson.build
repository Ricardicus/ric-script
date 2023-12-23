project('ric_extended_lib', 'c',
  version : '1.0.0',
  license : 'GPL')

cc = meson.get_compiler('c')

# Adding flags for the parser to be more verbose
ric_c_args = ['-DYYERROR_VERBOSE']
ric_links = []
ext_c_args = []

target_os = target_machine.system()
ric_c_args += [''.join(['-DTARGET_OS="',target_os,'"'])]

includes = [
  include_directories('.'),
  include_directories('..'),
  include_directories(
    join_paths('..', 'library')
  ),
  include_directories(
    join_paths('..', 'external', 'cjson-1.7.14')
  ),
  include_directories(
    join_paths('..', 'external', 'crypto-algorithms')
  ),
  include_directories(
    join_paths('..', 'external', 'mini-gmp-6.2.1')
  )
]

library_sources = [
  join_paths('..','library','libio.c'),
  join_paths('..','library','libmath.c'),
  join_paths('..','library','libstd.c'),
  join_paths('..','library','libstring.c'),
  join_paths('..','library','libload.c'),
  join_paths('..','library','libtime.c'),
  join_paths('..','library','libctx.c'),
  join_paths('..','library','libjson.c'),
  join_paths('..','library','libcrypto.c'),
  join_paths('..','library','libprioqueue.c'),
  join_paths('..','library','libbigint.c'),
  join_paths('..','external','cjson-1.7.14',
    'cJSON.c'),
  join_paths('..','external','mini-gmp-6.2.1',
    'mini-gmp.c'),
  join_paths('..','external','crypto-algorithms','md5.c'),
  join_paths('..','external','crypto-algorithms','base64.c'),
  join_paths('..','external','crypto-algorithms','blowfish.c'),
  join_paths('..','external','crypto-algorithms','sha256.c'),

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
join_paths('..','prioqueue.c'),
join_paths('..','ast.c'),
join_paths('..','hooks.c'),
join_paths('..','print.c'),
join_paths('..','interpret.c'),
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
  # PCRE
  pcre_sources_list = [
    'pcre_compile.c',
    'pcre_config.c',
    'pcre_dfa_exec.c',
    'pcre_exec.c',
    'pcre_fullinfo.c',
    'pcre_get.c',
    'pcre_globals.c',
    'pcre_info.c',
    'pcre_maketables.c',
    'pcre_newline.c',
    'pcre_ord2utf8.c',
    'pcre_refcount.c',
    'pcre_study.c',
    'pcre_tables.c',
    'pcre_try_flipped.c',
    'pcre_ucd.c',
    'pcre_valid_utf8.c',
    'pcre_version.c',
    'pcre_chartables.c',
    'pcre_xclass.c'
  ]

  pcre_sources = []

  foreach pcre_source : pcre_sources_list
    pcre_sources += [join_paths('..','external','pcre-8.00', pcre_source)]
  endforeach

  pcre_inc = include_directories(
    join_paths('..','external','pcre-8.00')
    )

  # Adding flags for the parser to be more verbose
  pcre_args = ['-DNEWLINE=-1','-DLINK_SIZE=2','-DMAX_NAME_SIZE=32',
    '-DMAX_NAME_COUNT=10000', '-DMATCH_LIMIT=10000000','-DMATCH_LIMIT_RECURSION=10000000',
    '-DPOSIX_MALLOC_THRESHOLD=10','-D_WIN32']

  pcre_lib = shared_library('pcre',
    sources : pcre_sources, 
    c_args : [pcre_args],
    link_with: [],
    include_directories : [pcre_inc],
    install: true)

  ric_links += [pcre_lib]

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
  c_args: [ext_c_args, ric_c_args],
  dependencies: [deps],
  link_with: [ric_links],
  version : '1.0.0', include_directories: [includes])



