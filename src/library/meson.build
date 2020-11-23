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
  library_source_list += ['libos.c']
endif

if ( target_os == 'darwin' ) 
  library_source_list += ['libxattr_darwin.c']
elif ( target_os == 'linux' )
  library_source_list += ['libxattr_linux.c']
endif

library_sources = files(library_source_list)
