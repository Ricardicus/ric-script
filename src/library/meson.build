library_inc = include_directories('.')

library_source_list = [
  'libio.c',
  'libmath.c',
  'libstd.c',
  'libstring.c',
  'libload.c',
  'libtime.c',
  'libctx.c',
  'libjson.c',
  'libbigint.c',
  'libcrypto.c',
  'libprioqueue.c'
]

ric_c_args = []  # Initialize if not already defined

target_os = target_machine.system()

# Handling windows NT vs. unix POSIX differences
if target_os == 'windows'
  library_source_list += ['libos_nt.c', 'libnet_nt.c']
  ric_c_args += ['-DNO_XATTR']
else
  library_source_list += ['libos.c', 'libnet.c']
endif

if target_os == 'darwin'
  library_source_list += ['libxattr_darwin.c']
elif target_os == 'linux'
  library_source_list += ['libxattr_linux.c']
else
  ric_c_args += ['-DNO_XATTR']
endif

# Try to find libcurl
libcurl_dep = dependency('libcurl', required : false)

if libcurl_dep.found()
  ric_c_args += ['-DRIC_SCRIPT_REQUESTS']
  library_source_list += ['librequests.c']
  deps += [libcurl_dep]
endif

library_sources = files(library_source_list)
