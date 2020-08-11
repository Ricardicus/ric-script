project('ric-script' , ['c'], version: '1.0.0', default_options: ['warning_level=3', 'werror=false'])

subdir('src')

# Copy binary to build directory
configure_file(input: join_paths('src','ric'),
  output: 'ric',
  copy: true
)