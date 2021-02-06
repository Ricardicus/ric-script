.. image:: images/icon_small.png
   :width: 30px
   :height: 30px
   :scale: 50 %
   :align: right

Standard library
================

The language comes with some batteries included!
I will present some of them here

List of batteries
~~~~~~~~~~~~~~~~~

Using **help()** you get, as of today, the following output:

.. code-block::

	>> help()
	These are the functions I know:
	function-name (number-of-arguments)
	- exit ( 1 )
	- print ( 1 )
	- printf ( 1 )
	- append ( 2 )
	- len ( 1 )
	- contains ( 2 )
	- keys ( 1 )
	- isDefined ( 1 )
	- help ( 0 )
	- type ( 1 )
	- typeInText ( 1 )
	- list ( 1 )
	- data ( 1 )
	- text ( 1 )
	- parseInt ( 1 )
	- split ( 2 )
	- charCode ( 1 )
	- isFile ( 1 )
	- fileOpen ( 1 )
	- fileClose ( 1 )
	- fileWrite ( 2 )
	- fileRead ( 2 )
	- fileReadLines ( 1 )
	- input ( 1 )
	- pow ( 2 )
	- log ( 1 )
	- sqrt ( 1 )
	- sin ( 1 )
	- cos ( 1 )
	- tan ( 1 )
	- exp ( 1 )
	- abs ( 1 )
	- floor ( 1 )
	- ceil ( 1 )
	- randomInt ( 2 )
	- random ( 0 )
	- load ( 1 )
	- now ( 0 )
	- timeSeconds ( 1 )
	- timeMinutes ( 1 )
	- timeHours ( 1 )
	- timeDays ( 1 )
	- timeWeeks ( 1 )
	- timeMonths ( 1 )
	- timeYears ( 1 )
	- timeSecond ( 1 )
	- timeMinute ( 1 )
	- timeHour ( 1 )
	- timeDay ( 1 )
	- timeWeek ( 1 )
	- timeMonth ( 1 )
	- timeYear ( 1 )
	- xattrList ( 1 )
	- xattrGet ( 2 )
	- xattrSet ( 3 )
	- xattrFindKey ( 1 )
	- xattrRm ( 2 )
	- sleep ( 1 )
	- isDir ( 1 )
	- ls ( 1 )
	- rm ( 1 )
	- mkdir ( 1 )
	- find ( 1 )
	- cd ( 1 )
	- setTimeout ( 2 )
	- setInterval ( 2 )
	- socketServer ( 1 )
	- socketAccept ( 1 )
	- socketRead ( 2 )
	- socketWrite ( 2 )
	- socketClose ( 1 )
	- socketConnect ( 2 )

Due to the underlying structure, I have not been able to add function argument
names to the structure that handles the extended library.
All the extended library functions are implemented `here <https://github.com/Ricardicus/ric-script/tree/master/src/library>`_.

File io
~~~~~~~

You can do file IO, but only basic things as of today. More to come!
Here is an example of functions that do file IO:

.. code-block:: javascript

	- isFile ( 1 )
	- isDir ( 1 )
	- fileOpen ( 1 )
	- fileClose ( 1 )
	- fileWrite ( 2 )
	- fileRead ( 2 )
	- fileReadLines ( 1 )
	- isDir ( 1 )
	- ls ( 1 )
	- rm ( 1 )
	- mkdir ( 1 )
	- find ( 1 )
	- cd ( 1 )

**find** accepts a regular expression to search for a file, by its filename.
Using **isFile**, you can for example list all files in a directory like
this:

.. code-block:: javascript

	#!/usr/bin/ric
	# A script to demonstrate how one can list files using ric-script

	@ printUsage() {
	  print("usage: " + args[0] + " " + args[1] + " directory")
	}

	@ listFiles(folder, indent) {
	  ( ls(folder) ... file ) {
	    fullfile = folder + "/" + file
	    ? [ isFile(fullfile) ] {
	      printf(" " * indent)
	      print(file)
	    } ~ {
	      ? [ file != '.' ] {
	      ? [ file != '..'] {
	        printf(" " * indent)
	        print(file)
	        listFiles(fullfile, indent + 1)
	      }}
	    }
	  }
	}

	# argument checking
	? [ len(args) < 3 ] {
	  printUsage()
	  exit(1)
	}

	? [ isDir(args[2]) ] {
	  # print folder structure
	  listFiles(args[2], 0)
	} ~ {
	  # not a folder given
	  printUsage()
	  exit(1)
	}

You can read and write data to a file like this:

.. code-block:: javascript

	fp = fileOpen(fileCheck)

	# A file has been opened
	content = "Hello World!\nThis is a message :)\n"
	fileWrite(fp, content)
	
	# Closing the file
	fileClose(fp)
	
	# Opening the file, and print its contents
	fp = fileOpen(fileCheck)
	print(fileReadLines(fp))
	fileClose(fp)

**outputs:**

.. code-block:: bash

	['Hello World!
	','This is a message :)
	']

Socket
~~~~~~

Here is an example of how you can create a web server in ric-script:

.. code-block:: bash

	#!/usr/bin/ric
	# Example of how to use the built in
	# socket interface in ric script.
	# This is an echo-server.

	reads = 10

	@ usage () {
	  print("usage: " + args[0] + " " + args[1] + " port")
	  exit(1) 
	}

	? [ len(args) < 3 ] {
	  usage()
	}

	s = socketServer(args[2])
	? [ s < 0 ] {
	  print("Failed to create the socket, sorry..")
	  exit(1)
	}

	i = 0
	. [ i < reads ] {
	  t = socketAccept(s)
	  ? [ t > 0 ] {
	    in = socketRead(t, 50)
	    print("read " + len(in) + " bytes: " + in)
	    socketWrite(t, in)
	    socketClose(t)
	  }
	  i = i + 1
	  @
	}

	socketClose(s)

Here is an example of how you can create a client in ric-script:

.. code-block:: bash

	#!/usr/bin/ric
	# Example of how to use the built in
	# socket interface in ric script.
	# This is a client program.

	sends = 10

	@ usage () {
	  print("usage: " + args[0] + " " + args[1] + " host port content-to-write")
	  exit(1) 
	}

	? [ len(args) < 5 ] {
	  usage()
	}

	i = 0
	. [ i < sends ] {
	  print("Opening connection to host: " + args[2] + ":" + args[3])
	  s = socketConnect(args[2], args[3])
	  ? [ s < 0 ] {
	    print("Failed to create the socket, sorry.. error code: " + s)
	    exit(1)
	  }

	  t = socketWrite(s, args[4])
	  ? [ t > 0 ] {
	    in = socketRead(s, 50)
	    print("read " + len(in) + " bytes: " + in)
	  } ~ {
	    print("Failed to write to host...")
	  }
	  socketClose(s)
	  sleep(1)
	  i = i + i
	  @
	}

Math
~~~~

You got some math functions at hand and they accept both integers and doubles.


.. code-block:: bash

	- pow ( 2 )
	- log ( 1 )
	- sqrt ( 1 )
	- sin ( 1 )
	- cos ( 1 )
	- tan ( 1 )
	- exp ( 1 )
	- abs ( 1 )
	- floor ( 1 )
	- ceil ( 1 )

Extended File Attributes (xattr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

On POSIX systems, let's say not Windows, you can get and set extended file attributes.

.. code-block:: bash

	- xattrList ( 1 )
	- xattrGet ( 2 )
	- xattrSet ( 3 )
	- xattrFindKey ( 1 )
	- xattrRm ( 2 )

**xattrFindKey** accepts a regular expression of a x-attribute key, and finds
a file that has that key.

Here is an example of how to set, get and list x-attributes in ric-script:

.. code-block:: javascript

	file = "requirements.txt"
	s = xattrList(file)
	print("xattr's of '" + file + "':")
	print(s)

	print("Setting some xattributes")

	xattrSet(file, "user.owner", "Rickard")
	xattrSet(file, "user.master", "Rickard of course")

	print("xattr's of '" + file + "' and values:")
	s = xattrList(file)
	i = 0
	. [ i < len(s) ] {
	  val = xattrGet(file, s[i])
	  print("    - '" + s[i] + "': '" + val + "'")
	  i = i + 1
	  @
	}

	print("Searching for user.* keyed files")
	s = xattrFindKey("user\.*")
	i = 0
	. [ i < len(s) ] {
	  print(s[i])
	  i = i + 1
	  @
	}

	print("Removing xattributes I just set")
	s = xattrList(file)
	i = 0
	. [ i < len(s) ] {
	  xattrRm(file, s[i])
	  i = i + 1
	  @
	}

	s = xattrList(file)
	print("xattr's of '" + file + "':")
	print(s)

**outputs**:

.. code-block:: bash

	xattr's of 'requirements.txt':
	[]
	Setting some xattributes
	xattr's of 'requirements.txt' and values:
	    - 'user.owner': 'Rickard'
	    - 'user.master': 'Rickard of course'
	Searching for user.* keyed files
	./requirements.txt
	Removing xattributes I just set
	xattr's of 'requirements.txt':
	[]

This was at least what I got on my system. Who knows what x-attrs you have on yours :)

Time
~~~~

I have added support for handling time-values.
The main point of entry is **now**:


.. code-block:: bash

	- now ( 0 )
	- timeSeconds ( 1 )
	- timeMinutes ( 1 )
	- timeHours ( 1 )
	- timeDays ( 1 )
	- timeWeeks ( 1 )
	- timeMonths ( 1 )
	- timeYears ( 1 )
	- timeSecond ( 1 )
	- timeMinute ( 1 )
	- timeHour ( 1 )
	- timeDay ( 1 )
	- timeWeek ( 1 )
	- timeMonth ( 1 )
	- timeYear ( 1 )

The functions are made to extract values from a given moment.
I have not done so much work in this area, it would be nice
with a function that creates a 'date-time' object based on input.
Feel free to contribute!

Threads
~~~~~~~

Inspired by Javascript, you can create new contexts with the functions


.. code-block:: bash

	- setTimeout ( 2 )
	- setInterval ( 2 )
	- sleep ( 1 )

Here is an example of how they can be used, for demonstration:

.. code-block:: javascript

	#!/usr/bin/ric
	# This program shows how you can create
	# different types of thread contexts in
	# ricscript. It is inspired by Javascript.
	# You can do function calls by timeouts
	# over intervals.
	# The interval thread stops if the function
	# returns a non-zero value.
	a = 1

	@ iterate () {
	  ? [ a > 10 ] {
	    -> 1
	  }
	  a = a + 1
	}

	@ end () {
	  print("Hi, the shared variable now holds value: " + a)
	}

	print("Hi I am gonna start some threads...")
	print("I have set a variable, named 'a', to: " + a)
	print("In 10 seconds, I will read its value again.")
	print("By the time, a thread running with an interval")
	print("will increment this variables value with each iteration.")
	print("Let's begin...")

	setTimeout(end, 10)
	setInterval(iterate, 1)

	print("I have now launched the threads!")
	print("They are running in a separate context.")
	print("I will return with an update...")
	print("...")

**outputs**

.. code-block:: bash

	Hi I am gonna start some threads...
	I have set a variable, named 'a', to: 1
	In 10 seconds, I will read its value again.
	By the time, a thread running with an interval
	will increment this variables value with each iteration.
	Let's begin...
	I have now launched the threads!
	They are running in a separate context.
	I will return with an update...
	...
	Hi, the shared variable now holds value: 10

