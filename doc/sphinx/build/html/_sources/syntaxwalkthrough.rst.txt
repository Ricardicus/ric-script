
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
	numberChars = ['0','1','2','3','4','5','6','7','8','9']

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
	  i = 0
	  . [ i < len(expr) ] {
	    ? [ isNumber(expr[i]) ] {
	      push( parseInt(expr[i]) )
	    } ~[ contains(operators, expr[i]) ] {
	      s = eval(expr[i])
	      push(s)
	    } ~[ contains(expr[i], "q") ] {
	      run = 0
	    } ~ {
	      print("Sorry, I don't understand this: " + expr[i])
	    }
	    i = i + 1
	    @
	  }
	  ? [ stack["head"] > 0 ] {
	    print(stack["data"][ stack["head"] - 1 ])
	  }
	  stack["head"] = 0
	  @
	}

Data types
~~~~~~~~~~

As of today the following types of data are supported:

- Integers

.. code-block:: bash

	a = 1337
	print(a)

**output**: 1337

- Floats

.. code-block:: bash

	a = 1337.0
	print(a)

**output**: 1337.000000

- Strings

.. code-block:: bash

	a = "Hello world!"
	print(a)
	a = 'Hello world!'

**output**:

.. code-block:: bash

	Hello world!
	Hello world!

- Function pointers

.. code-block:: bash

	# Function with function pointer as argument
	@ hej (a,b) {
		# arg1 should be a function pointer
		a( b )
	}

	hej(print, "hejsan")

**output**: hejsan

- Dictionary

.. code-block:: bash

	d = {"a" : "b", "c" : "d", "1337" : 1337}

	print(d)
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

**outputs**:

.. code-block:: bash

	{'a' : 'b', '1337' : 1337, 'c' : 'd'}
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

- List

.. code-block:: bash

	s = ["hej", 1337, "hejsan"]

	print(s)

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

	i = 0
	. [ i < len(h) ] {
	  print(h[i])
	  i = i + 1
	  @
	}

	append(h, "foo")
	append(h, "bar")

	h[0] = "Foobar! foo "

	print(h[0])

	i = 0
	. [ i < len(h) ] {
	  print(h[i])
	  i = i + 1
	  @
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

**outputs**:

.. code-block:: bash

	['hej',1337,'hejsan']
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

- Class pointer

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

	s = hej()
	print(s)

	s::setA(100)
	f = s::getA()
	print(f)

	print(s::getA())

**outputs**:

.. code-block:: bash

	<Class: 'hej'>
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
	  i = 0
	  . [ i < len(expr) ] {
	    ? [ isNumber(expr[i]) ] {
	      calc::push( parseInt(expr[i]) )
	    } ~[ contains(operators, expr[i]) ] {
	      s = calc::eval(expr[i])
	      calc::push(s)
	    } ~[ contains(expr[i], "q") ] {
	      run = 0
	    } ~ {
	      print("Sorry, I don't understad this: " + expr[i])
	    }
	    i = i + 1
	    @
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
**~**  The following condition will become a return spot
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



