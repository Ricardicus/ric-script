# External resources

I wanted to implement some regular expression handling in RicScript and
realized that no library corresponding to the POSIX <regex.h> was to be
found on Windows. Since I aim to have this project cross-platform, I cannot
solely rely on POSIX and I don't want to reinvent the wheel.
So here we go folks, projects to power my projects. 

- pcre-8.00
  A library for regexp that builds on Windows. I integrated it in meson.
- mini-gmp-6.2.1
  GMP lightweight version enables big number arithmetic
- cjson-1.7.15
  JSON parser library

