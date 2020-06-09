project('ric-script' , ['c'], version: '1.0.0', default_options: ['warning_level=3', 'werror=false'])

cc = meson.get_compiler('c')

m_dep = cc.find_library('m', required: true)

includes = include_directories('.')
sources = ['main.c','hashtable.c','ast.c','hooks.c','eval.c','lex.yy.c','y.tab.c']

network = executable('main',
  sources: [sources],
  dependencies: m_dep,
  include_directories: [includes]
)
