.. image:: images/icon_small.png
   :width: 30px
   :height: 30px
   :scale: 50 %
   :align: right

Making your own library functions
=================================

There is support for compiling your own code and integrating it in the ric-script interpreter. On Windows this is done with .dll files, on Linux .so and on iOSX .dylib.

Go to `src/sdk_lib <https://github.com/Ricardicus/ric-script/tree/master/src/sdk_lib>`_ and study the example there. Study in particual `ext_lib.c <https://github.com/Ricardicus/ric-script/tree/master/src/sdk_lib/ext_lib.c>`_. It is a Meson project, that can be built like this:

.. code-block:: bash

  cd src/sdk_lib
  meson builddir && cd builddir && ninja

Now the dynamic library is to be found in the build directory. What now is required, and I must remind you this is a work in progress, is a file named **ric_modules.txt**. In this file, you write the location of this file. It is best provided as an absolute path, but relative (containing a slash) also works.

Say you have build a library file here ``/my/home/is/here/builddir/libric_extended_lib_example.so.1.0.0``. Then
the file content of this **ric_modules.txt** (that is placed in the interpreters current working directory by they way) would look like this:

.. code-block:: bash

  $ cat ric_modules.txt
  /my/home/is/here/builddir/libric_extended_lib_example.so.1.0.0aa

You can see if you successfully loaded your dynamic library function by using the ``help()`` function available in the interactive mode. It can look like this, after reading a module named ``example_ric``:

.. code-block:: bash

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
  Nbr funcs : 1
  Version   : 0.1
    ric_example_print ( 1 )
  0
  >>