project('ric_extended_lib', 'c',
  version : '1.0.0',
  license : 'GPL')

ext_c_args = []

target_os = target_machine.system()

sources = ['ext_lib.c']
includes = [include_directories('.'), include_directories('..')]

if ( target_os == 'windows' )
	ext_c_args += ['-DWIN']
endif

shared_library('ric_extended_lib_example', sources,
  c_args: [ext_c_args],
  version : '1.0.0', include_directories: [includes])



