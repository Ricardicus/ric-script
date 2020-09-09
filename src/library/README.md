# This is where batteries are included

Here I implement functions implemented in the language
by default. I try to make some sort of partitioning
of functionality that makes sense to me. 
There is much that can be included here. 
I basically read arguments from the stack, then
push the return value I deem fit.
If there is anything wrong, a library function
returns a non-zero and the execution of the program
is aborted. In the parent directory there is a file
named **lib.c**, in this file I give functions a name
and specify the number of arguments the expect. 

They are registered there, in **../lib.c**, but implemented
here. 

