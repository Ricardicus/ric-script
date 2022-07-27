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
syn match	ricComment	"^#.*" 
syn match	ricComment	"\s#.*"
syn match       ricKeywordMarks	"[@?!]"
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

let b:current_syntax = "ric"

" vim: ts=8 sw=2
