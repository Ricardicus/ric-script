.. image:: /images/icon_small.png
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

.. code-block:: text

	>> help()
	These are the functions I know:
	function-name ( number-of-arguments)
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
	- jsonLoad ( 1 )
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
	- osName ( 0 )
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

.. code-block:: python

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

.. code-block:: python

	#!/usr/bin/ric
	# A script to demonstrate how one can list files using ric-script

	@ printUsage() {
	  print("usage: " + args[0] + " " + args[1] + " directory")
	}

	@ listFiles(folder, indent) {
	  . ( ls(folder) ... file ) {
	    fullfile = folder + "/" + file
	    ? [ isFile(fullfile) ] {
	      printf(" " * indent)
	      print(file)
	    } ~ {
	      ? [ file != '.' && file != '..'] {
	        printf(" " * indent)
	        print(file)
	        listFiles(fullfile, indent + 1)
	      }
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

.. code-block:: python

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

.. code-block:: python

	['Hello World!
	','This is a message :)
	']

Sockets
~~~~~~~

Here is an example of how sockets can be used, making a socket server and a socket client for demonstration:

.. code-block:: bash

  #!/usr/bin/ric
  # Example of how to use the built in
  # socket interface in ric script.
  # This is an echo-server.

  reads = 10
  sends = 10

  @ usage () {
    print("usage: " + args[0] + " " + args[1] + " host port content-to-write")
    exit(1) 
  }

  ? [ len(args) < 5 ] {
    usage()
  }

  @ clientThread () {
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
        print("Sent " + t + " bytes to server.")
      }
      socketClose(s)
      sleep(1)
      i += 1
      @
    }
  }

  @ serverThread () {
    s = socketServer(args[3])
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
      i += 1
      @
    }

    socketClose(s)
  }

  # Start server thread immediately
  setTimeout(serverThread, 0)
  # Start client server one second later
  setTimeout(clientThread, 1)






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


Big integers
~~~~~~~~~~~~

One can do math with integers that are larger than 64 bits. These are called big integers and are constructed via the **bigInt** call.

.. code-block:: python

	# Calculate a ridiculously large number ( 81 to the power of 500 ).
	print( pow(bigInt(81), 500) )

This will output (scroll to the right to see the whole number):

.. code-block:: python

	1747871251722651609659974619164660570529062487435188517811888011810686266227275489291486469864681111075608950696145276588771368435875508647514414202093638481872912380089977179381529628478320523519319142681504424059410890214500500647813935818925701905402605484098137956979368551025825239411318643997916523677044769662628646406540335627975329619264245079750470862462474091105444437355302146151475348090755330153269067933091699479889089824650841795567478606396975664557143737657027080403239977757865296846740093712377915770536094223688049108023244139183027962484411078464439516845227961935221269814753416782576455507316073751985374046064592546796043150737808314501684679758056905948759246368644416151863138085276603595816410945157599742077617618911601185155602080771746785959359879490191933389965271275403127925432247963269675912646103156343954375442792688936047041533537523137941310690833949767764290081333900380310406154723157882112449991673819054110440001

Extended File Attributes (xattr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

On POSIX systems, let's say not Windows, you can get and set extended file attributes.

.. code-block:: python

	- xattrList ( 1 )
	- xattrGet ( 2 )
	- xattrSet ( 3 )
	- xattrFindKey ( 1 )
	- xattrRm ( 2 )

**xattrFindKey** accepts a regular expression of a x-attribute key, and finds
a file that has that key.

Here is an example of how to set, get and list x-attributes in ric-script:

.. code-block:: python

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
	  i += 1
	  @
	}

	print("Searching for user.* keyed files")
	s = xattrFindKey("user\.*")
	i = 0
	. [ i < len(s) ] {
	  print(s[i])
	  i += 1
	  @
	}

	print("Removing xattributes I just set")
	s = xattrList(file)
	i = 0
	. [ i < len(s) ] {
	  xattrRm(file, s[i])
	  i += 1
	  @
	}

	s = xattrList(file)
	print("xattr's of '" + file + "':")
	print(s)

**outputs**:

.. code-block:: python

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


.. code-block:: python

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


.. code-block:: python

	- setTimeout ( 2 )
	- setInterval ( 2 )
	- sleep ( 1 )
