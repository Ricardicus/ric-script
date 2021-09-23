cjson_inc = include_directories('.')

cjson_source_list = [
  'cJSON.c'
]

cjson_lib = static_library('cJSON',
  sources: cjson_source_list,
  include_directories : cjson_inc)

external_inc += [cjson_inc]
external_links += [cjson_lib]