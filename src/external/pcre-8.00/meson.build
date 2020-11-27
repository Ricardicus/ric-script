pcre_sources = [
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

pcre_inc = include_directories('.')

# Adding flags for the parser to be more verbose
pcre_args = ['-DNEWLINE=-1','-DLINK_SIZE=2','-DMAX_NAME_SIZE=32',
  '-DMAX_NAME_COUNT=10000', '-DMATCH_LIMIT=10000000','-DMATCH_LIMIT_RECURSION=10000000',
  '-DPOSIX_MALLOC_THRESHOLD=10']

pcre_lib = library('pcre',
	sources : pcre_sources, 
	c_args : [pcre_args],
	link_with: [],
	include_directories : [pcre_inc])

pcre_demo = executable('demo',
	sources: 'pcredemo.c',
	link_with: pcre_lib,
	include_directories : [pcre_inc])

