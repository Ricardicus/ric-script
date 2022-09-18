" Vim syntax file
" Language:	ric-script
" Maintainer:	Rickard Hallerbäck <rickard.hallerback@gmail.com>
" Last Change:	2022 July 28

" Quit when a (custom) syntax file was already loaded
if exists("b:current_syntax")
  finish
endif

syn keyword	ricTodo	contained TODO FIXME XXX
" Avoid matching "text#text", used in /etc/disktab and /etc/gettytab
" Regular int like number with - + or nothing in front
"
syn match ricID     '[a-zA-ZåäöÅÄÖ0-9_]\+'
syn match ricNumber '\d\+' 
syn match ricNumber '[-+]\d\+' 

" Floating point number with decimal no E or e (+,-)
syn match ricNumber '\d\+\.\d*' 
syn match ricNumber '[-+]\d\+\.\d*'

" Floating point like number with E and no decimal point (+,-)
syn match ricNumber '[-+]\=\d[[:digit:]]*[eE][\-+]\=\d\+'
syn match ricNumber '\d[[:digit:]]*[eE][\-+]\=\d\+'

" Floating point like number with E and decimal point (+,-)
syn match ricNumber '[-+]\=\d[[:digit:]]*\.\d*[eE][\-+]\=\d\+' 
syn match ricNumber '\d[[:digit:]]*\.\d*[eE][\-+]\=\d\+' 
syn match	ricComment	"^#.*"
syn match	ricComment	"\s#.*"
syn match       ricKeywordMarks	"[@?!~]"
syn match       ricKeywordClass	";;"
syn match       ricKeywordDots	"\.\.\."
syn region	ricString	start=+"+ skip=+\\\\\|\\"+ end=+"+ oneline
syn region	ricString	start=+'+ skip=+\\\\\|\\'+ end=+'+ oneline

" Define the default highlighting.
" Only used when an item doesn't have highlighting yet
hi def link ricComment	Comment
hi def link ricTodo	Todo
hi def link ricString	String
hi def link ricKeywordDots Keyword
hi def link ricKeywordClass Keyword
hi def link ricKeywordMarks Keyword 
hi def link ricNumber Constant
hi def link ricID Identifier

hi ricID ctermfg=white

let b:current_syntax = "ric"

" vim: ts=8 sw=2
