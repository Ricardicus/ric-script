minigmp_inc = include_directories('.')

minigmp_source_list = [
  'mini-gmp.c'
]

minigmp_args = [
  '-DMINI_GMP_DONT_USE_FLOAT_H'
]

minigmp_lib = static_library('minigmp',
  sources: minigmp_source_list,
  include_directories : minigmp_inc,
  c_args: minigmp_args)

external_inc += [minigmp_inc]
external_links += [minigmp_lib]
