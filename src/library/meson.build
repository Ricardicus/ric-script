library_inc = include_directories('.')

library_source_list = [
  'libio.c',
  'libmath.c',
  'libstd.c',
  'libstring.c',
  'libload.c',
  'libtime.c'
]

target_os = target_machine.system()

# Handling windows NT vs. unix POSIX differences
if ( target_os == 'windows' )
  library_source_list += ['libos_nt.c']
  add_global_arguments('-DNO_XATTR', language: 'c')
else
  library_source_list += ['libos.c', 'libxattr.c']
endif

library_sources = files(library_source_list)
