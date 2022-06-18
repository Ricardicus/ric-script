# Exporting modules

Using this project, one can create shared libraries
that can be dynamically included in the language to
extend the language power and capability.

## Making your own library functions

There is support for compiling your own code and integrating it in the ric-script interpreter. On Windows this is done with .dll files, on Linux .so and on iOSX .dylib.

Study the example code there. Study in particual 'ext_lib.c'. This is a Meson project that can be built like this:

```BASH
meson builddir && cd builddir && ninja
```
## How it is done

Study the example translation unit 'ext_lib.c'.

In particular, these lines are the most important ones:

```C
MARK_EXPORT libFunction_t EXPORT_FUNCTION_LIST[] = {
  DECLARE_LIB_FUNCTION("ric_example_print", 1, ric_example_print)
  DECLARE_LIB_FUNCTION("example_class", 0, example_class_init)};

EXPORT_MODULE("example_ric");
```

The array *EXPORT_FUNCTION_LIST* contains the list of functions that are
to be exported. The *EXPORT_MODULE* defines the name of the module you have
chosen to export and it will be written into the shared library object.

In this particular example, only one function is exported. This function
takes 1 input argument, and will be called as *ric_example_print*. After a successful
build, and writing this shared object library path into a file called 'ric_modules.txt';
our interpreter *help* function gives us the following info:

```BASH
$ ric
You are running in interactive mode. Stop it by typing: 'quit'.
This is in it's very early stage... it only supports one liners!
>> help()
These are the functions I know:
function-name ( number-of-arguments)
- exit ( 1 )
- print ( 1 )
- printf ( 1 )
- append ( 2 )
...
- socketRead ( 2 )
- socketWrite ( 2 )
- socketClose ( 1 )
- socketConnect ( 2 )
These are the modules and functions I have loaded dynamically:
function-name ( number-of-arguments)
Module    : example_ric
Nbr funcs : 2
Version   : 0.1
  ric_example_print ( 1 )
  example_class ( 0 )
>>
```

And the function can be called like this:

```BASH
>> ric_example_print("Hejsan svejsan")
Hejsan svejsan
>> e = example_class()
>> e::add(1338)
example_class_add add::example_class: Added 1338 to member1. Member1: 1338
>> e::sub(1)
example_class_sub sub::example_class: substitute 1 to member1. Member1: 1337
```

This, of course, works even when interpreting scripts and not just in the interactive mode.

Note: The 'ric_modules.txt' file is a start. I want this to be better in the future, proper package handling without the manual effort of writing down paths here. But it is a start at least; and it works.

Happy hacking.. :)




