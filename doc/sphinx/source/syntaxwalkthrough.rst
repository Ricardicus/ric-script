
.. image:: images/icon_small.png
   :width: 30px
   :height: 30px
   :scale: 50 %
   :align: right

Syntax walkthrough
==================

I have some inspiration from Javascript, Python and BASH.
Here are some examples that try to demonstrate the language syntax.

I will give some samples here to demonstrate some of the syntax.

Declarations: functions and variables
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The langauge is dynamically typed, so no types are given.
As you will see, both control flow and function declarations
depend on the symbol **@**.

Below is an implementation of an RPN calculator. You will see the
declaration of a **map** and two of the **list** sort.

.. code-block:: bash

	#!/usr/bin/ric
	# RPN calculator implementation in ric-script
	stack = {"head" : 0, "data" : []}
	operators = ["+", "*", "-", "/"]
	numberChars = [ (10 ... i) { text(i) } ]

	@ isNumber(num) {
	  isNr = 1
	  i = 0
	  . [ i < len(num) ] {
	    ? [ contains( numberChars, num[i] ) ] {
	      i = i + 1
	      @
	    } ~ {
	      isNr = 0
	    }
	  }
	  -> isNr
	}

	@ pop() {
	  head = stack["head"]
	  ? [ head == 0 ] {
	    print("Too few arguments on the stack. Goodbye!")
	    exit(2)
	  }
	  head = head - 1
	  val = stack["data"][head]
	  stack["head"] = head
	  -> val
	}

	@ push (val) {
	  head = stack["head"]
	  ? [ head >= len(stack["data"]) ] {
	    append(stack["data"], val)
	  } ~ {
	    stack["data"][head] = val
	  }
	  stack["head"] = head + 1
	}

	@ eval (op) {
	  ? [ op == '+' ] {
	    -> pop() + pop()
	  } ~[ op == '-' ] {
	    tmp = pop()
	    -> pop() - tmp
	  } ~[ op == '*' ] {
	    -> pop() * pop()
	  } ~[ op == '/' ] {
	    tmp = pop()
	    -> pop() / tmp
	  } ~ {
	    -> 0
	  }
	}

	print("RPN Calculator (quit by typing 'q'):")

	run = 1
	. [ run ] {
	  in = input(">> ")
	  expr = split(in, " ")
	  ( expr ... e ) {
	    ? [ isNumber(e) ] {
	      push( parseInt(e) )
	    } ~[ contains(operators, e) ] {
	      s = eval(e)
	      push(s)
	    } ~[ contains(e, "q") ] {
	      run = 0
	    } ~ {
	      print("Sorry, I don't understand this: " + e)
	    }
	  }
	  ? [ stack["head"] > 0 ] {
	    print(stack["data"][ stack["head"] - 1 ])
	  }
	  stack["head"] = 0
	  @
	}


Data types
~~~~~~~~~~

To find out the type of value a variable is referencing, the functions
**type** and **typeInText** can be used. Each type of value is associated with 
a number, and you can also get a text representation of it.

As of today the following types of data are supported:

Integers
########

.. code-block:: bash

	a = 1337
	print(a)
	print(typeInText(a) + " (" + type(a) + ")")

**output**:

.. code-block:: bash

	1337
	i32 (1)

Floats
######

.. code-block:: bash

	a = 1337.0
	print(a)
	print(typeInText(a) + " (" + type(a) + ")")

**output**:

.. code-block:: bash

	1337.000000
	double (2)

Strings
#######

.. code-block:: bash

	a = "Hello world!"
	print(a)
	a = 'Hello world!'
	print(typeInText(a) + " (" + type(a) + ")")

	# Advanced indexing [e (start)]:[e (end)][:[e (offset)]]
	a = "hejsan"
	print(a[:])
	print(a[:3])
	a = "hheejjssaann"
	print(a[::2])
	a = " ddrraakkcciiRR"
	print(a[1::-2])

**output**:

.. code-block:: bash

	Hello world!
	Hello world!
	text (3)
	"hejsan"
	"hej"
	"hejsan",
	"Rickard"

Function pointers
#################

.. code-block:: bash

	# Function with function pointer as argument
	@ hej (a,b) {
		# arg1 should be a function pointer
		a( b )
	}

	hej(print, "hejsan")
	print(typeInText(hej) + " (" + type(hej) + ")")

**output**:

.. code-block::

	hejsan
	function-pointer (5)

Dictionary
##########

A dictionary maps a string to any type of references.

.. code-block:: bash

	d = {"a" : "b", "c" : "d", "1337" : 1337}

	print(d)
	print(typeInText(d) + " (" + type(d) + ")")
	print(d["a"])
	print(d["c"])
	print(d["1337"] - 1 + 1)

	d["e"] = "f"
	print(d["e"])

	d["e"] = "hej"
	print(d["e"])

	d = {}

	print(d)

	d["a"] = { "a" : 1, "b" : 2 }

	print(d["a"])

	@ foo(a) {
	  print(a)
	}

	foo(d)

	s = {"a": {"b": {"c": {"d": "e"}}}}
	print(s["a"]["b"]["c"]["d"])

	@ foobar () {
	  print("foobar")
	}

	s["foobar"] = foobar
	s["foobar"]()

	# Checking stdlib 'contains' function
	print(contains(s, "foobar"))
	print(contains(s, "barfoo"))

	# Checkoing stdlib 'keys' function
	print(keys(s))
	print(keys(d))
	print(keys(d["a"]))

	# For each loop, iterating over the keys
	( s ... key ) {
	  print(key)
	  print(s[key])
	}

	# Constructing lists with a for each loop
	print([(
	  10 ... i
	) {
	  text(i * 10)
	}])

	# Constructing lists, in a complex fashion
	# all 'lonely' expressions are put on the stack
	# and all on the stack is put into the list
	print([(
	  5 ... i
	) {
	  a = [i+1, i+2, i+3]
	  text(a[0])
	  text(a[1])
	  text(a[2])
	}])


**outputs**:

.. code-block:: bash

	{'a' : 'b', '1337' : 1337, 'c' : 'd'}
	dictionary (8)
	b
	d
	1337
	f
	hej
	{}
	{'a' : 1, 'b' : 2}
	{'a' : {'a' : 1, 'b' : 2}}
	e
	foobar
	1
	0
	['a','foobar']
	['a']
	['a','b']
	a
	{'b' : {'c' : {'d' : 'e'}}}
	foobar
	<Function: 'foobar'>
	['0','10','20','30','40','50','60','70','80','90']
	['1','2','3','2','3','4','3','4','5','4','5','6','5','6','7']

List
####

The list data type is implemented as a linked list
and can hold any type of expressions.

.. code-block:: bash

	s = ["hej", 1337, "hejsan"]

	print(s)
	print(typeInText(s) + " (" + type(s) + ")")

	print(s[0])
	print(s[1])
	print(s[2])

	a = 1337

	q = [a, s]

	print(q)

	print(q[0])
	print(q[1])

	print(q[1][0])
	print(q[1][1])
	print(q[1][2])

	f = [1337, q]

	print(f[1][1][0])
	print(f[1][1][1])
	print(f[1][1][2])

	h = ["foo"]

	append(h, "bar")

	print(h)

	print( len(h) )

	# For each loop
	( h ... entry ) {
		print(entry)
	}

	append(h, "foo")
	append(h, "bar")

	h[0] = "Foobar! foo "

	print(h[0])

	# For each loop
	( h ... entry ) {
		print(entry)
	}

	print(h)

	s = [ "hejsan" ]
	s = [s, "hej"]
	print(s)

	@ foo () {
	  print("foo")
	}

	@ bar () {
	  print("bar")
	}

	s = [foo, bar]
	s[0]()
	s[1]()

	# Testing libstd 'contains' function
	s = ["foobar", 1337]
	print(contains(s, 1338))
	print(contains(s, 1337))
	print(contains(s, "barfoo"))
	print(contains(s, "foobar"))

	# Testing libstring 'split' function
	s = "hejsan hoppsan falleralera"
	v = split(s, " ")
	print(v)

	# List multiplication
	s = ["hejsan", 1, 3, 4]
	s2 = 2 * s
	s3 = s * 3

	print(s)
	print(s2)
	print(s3)

	# Some indexing with [e (start)]:[e (end)]
	@ aNumber (a) { -> a }
	big = [(100 ... i) { i }]
	small = [(5 ... i) {i}]
	print(big[40:50])
	print(big[:aNumber(4)])
	print(small[:])
	print(small[2:])
	print(small[1:2])
	print(small[:len(small)])
	print(small[1:-2])

	# Some advanced indexing with offset [e (start)]:[e (end)]:[e (offset)]
	print(small[::1])
	print(small[::-1])
	print(big[90:-1:-2])

**outputs**:

.. code-block:: bash

	['hej',1337,'hejsan']
	list (7)
	hej
	1337
	hejsan
	[1337,['hej',1337,'hejsan']]
	1337
	['hej',1337,'hejsan']
	hej
	1337
	hejsan
	hej
	1337
	hejsan
	['foo','bar']
	2
	foo
	bar
	Foobar! foo
	Foobar! foo
	bar
	foo
	bar
	['Foobar! foo ','bar','foo','bar']
	[['hejsan'],'hej']
	foo
	bar
	0
	1
	0
	1
	['hejsan','hoppsan','falleralera']
	['hejsan',1,3,4]
	['hejsan',1,3,4,'hejsan',1,3,4]
	['hejsan',1,3,4,'hejsan',1,3,4,'hejsan',1,3,4]
	[40,41,42,43,44,45,46,47,48,49]
	[0,1,2,3]
	[0,1,2,3,4]
	[2,3,4]
	[1]
	[0,1,2,3,4]
	[1,2]
	[0,1,2,3,4]
	[4,3,2,1,0]
	[98,96,94,92,90]


Raw data
########

Raw data is a list with values that fit into 8 bits.
This list is implemented as an array in C, and not like
a linked list like the 'list' datastructure. 
It can be constructed using strings or lists, and if it is
printed, it will be printed like it contains chars.

.. code-block:: bash

	s = [102,111,111,98,97,114]
	s = data(s)

	print(typeInText(s) + " (" + type(s) + ")")
	print(s[0])
	print(len(s))
	print(s)

**outputs**:

.. code-block:: bash

	data (11)
	102
	6
	foobar

Class pointer
#############

.. code-block:: bash

	;; hej ;; {
		a = 1337
		@ hej () {
		  print("hello")
		  print("my member 'a' has value: " + a)
		  a = a + 1
		  print("Now 'a' is: " + a)
		}
		@ setA(newA) {
		  print("Wanting to set 'a' to: " + newA)
		  a = newA
		}
		@ getA() {
		  -> a
		}
	}

	print(hej)
	print(typeInText(hej) + " (" + type(hej) + ")")

	s = hej()
	print(s)

	s::setA(100)
	f = s::getA()
	print(f)

	print(s::getA())

**outputs**:

.. code-block:: bash

	<Class: 'hej'>
	class (9)
	hello
	my member 'a' has value: 1337
	Now 'a' is: 1338
	hej
	<Class object: 'hej'>
	Wanting to set 'a' to: 100
	100
	100

Class declarations
~~~~~~~~~~~~~~~~~~

Below is an implementation of an RPN calculator implemented using a class.

.. code-block:: bash

	#!/usr/bin/ric
	# RPN calculator implementation in ric-script
	;; RPN ;; {
	  stack = {"head" : 0, "data" : []}
	  operators = ["+", "*", "-", "/"]

	  @ pop() {
	    head = stack["head"]
	    ? [ head == 0 ] {
	      print("Too few arguments on the stack. Goodbye!")
	      exit(2)
	    }
	    head = head - 1
	    val = stack["data"][head]
	    stack["head"] = head
	    -> val
	  }

	  @ push (val) {
	    head = stack["head"]
	    ? [ head >= len(stack["data"]) ] {
	      append(stack["data"], val)
	    } ~ {
	      stack["data"][head] = val
	    }
	    stack["head"] = head + 1
	  }

	  @ eval (op) {
	    tmp = pop()
	    ? [ op == '+' ] {
	      -> tmp + pop()
	    } ~[ op == '-' ] {
	      -> pop() - tmp
	    } ~[ op == '*' ] {
	      -> tmp * pop()
	    } ~[ op == '/' ] {
	      -> pop() / tmp
	    } ~ {
	      print("Error: operator '" + op + "' is not supported")
	      exit(1)
	    }
	  }

	  @ printResult() {
	    ? [ stack["head"] > 0 ] {
	      print(stack["data"][ stack["head"] - 1 ])
	    }
	  }

	  @ getOperators() {
	    -> operators
	  }

	  @ reset () {
	    stack["head"] = 0
	  }
	}

	@ isNumber(num) {
	  numberChars = ['0','1','2','3','4','5','6','7','8','9']
	  isNr = 1
	  i = 0
	  . [ i < len(num) ] {
	    ? [ contains( numberChars, num[i] ) ] {
	      i = i + 1
	      @
	    } ~ {
	      isNr = 0
	    }
	  }
	  -> isNr
	}

	print("RPN Calculator (quit by typing 'q'):")

	calc = RPN()
	operators = calc::getOperators()
	run = 1
	. [ run ] {
	  in = input(">> ")
	  expr = split(in, " ")
	  ( expr ... e ) {
	    ? [ isNumber(e) ] {
	      calc::push( parseInt(e) )
	    } ~[ contains(operators, e) ] {
	      s = calc::eval(e)
	      calc::push(s)
	    } ~[ contains(e, "q") ] {
	      run = 0
	    } ~ {
	      print("Sorry, I don't understand this: " + e)
	    }
	  }
	  calc::printResult()
	  calc::reset()
	  @
	}

Control flow
~~~~~~~~~~~~

In this language, the symbols **?**, **.**, **~** and **@** are of importance for control flow.

====== ==================================================
Symbol Description
====== ==================================================
**.**  The following condition will become a return spot
**~**  The following condition will be an 'elif' or 'else' if no condition is provided
**@**  I will return to the last return spot
**?**  The following condition is simply a condition
====== ==================================================

As an example, this is interesting, you can write code like this:

.. code-block:: bash

	# A funny feature with this language
	a = 1338

	. [ a == 1337 ] {
	  print("Now the variable is: " + a)
	  print("yey!")
	} ~ {
	  print("A variable was not 1337, it was: " + a)
	  a = 1337
	  print("Re-evaluating")
	  @
	}

**outputs**:

.. code-block:: bash

	A variable was not 1337, it was: 1338
	Re-evaluating
	Now the variable is: 1337
	yey!


For-each looping
~~~~~~~~~~~~~~~~

For looping you can use the control flow structures used above,
but there is also a for-each structure in the language.
It works for dictionaries, lists, integers and strings.

.. code-block:: bash

	# For-eaching
	# Integers
	limit = 10
	( limit ... i ) {
	  print(i)
	}

	# Dictionary
	dict = {"a" : 1, "b" : 2, "c" : 3}
	( dict ... key ) {
	  print(key + ": " + dict[key])
	}

	# Strings
	string = "Hello world!"
	( string ... c ) {
	  print(c)
	}

	# Lists
	list = ["a", 2, "b", 4]
	( list ... entry ) {
	  print(entry)
	}

**outputs**:

.. code-block:: bash

	0
	1
	2
	3
	4
	5
	6
	7
	8
	9
	a: 1
	b: 2
	c: 3
	H
	e
	l
	l
	o

	w
	o
	r
	l
	d
	!
	a
	2
	b
	4