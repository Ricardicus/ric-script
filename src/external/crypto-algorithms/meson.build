crypto_algos_inc = include_directories('.')

crypto_algos_source_list = [
  'aes.c',
  'arcfour.c',
  'base64.c',
  'blowfish.c',
  'des.c',
  'md2.c',
  'md5.c',
  'sha1.c',
  'rot-13.c',
  'sha256.c',
]

crypto_algos_lib = static_library('crypto_algos',
  sources: crypto_algos_source_list,
  include_directories : crypto_algos_inc)

external_inc += [crypto_algos_inc]
external_links += [crypto_algos_lib]
