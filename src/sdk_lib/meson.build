project('ric_extended_lib', 'c',
  version : '1.0.0',
  license : 'GPL')

sources = ['ext_lib.c']
includes = [include_directories('.'), include_directories('..')]

shared_library('ric_extended_lib_example', sources,
  version : '1.0.0', include_directories: [includes])



