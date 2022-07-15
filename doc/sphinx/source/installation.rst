.. image:: /images/icon_small.png
   :width: 30px
   :height: 30px
   :scale: 50 %
   :align: right

Installation
============

I have support for building it on Windows, OSX and Linux today.

Linux & OSX
~~~~~~~~~~~

On Linux or mac use meson or GNU make.
You need `Meson <https://mesonbuild.com/index.html>`_ and `Python3 <https://www.python.org/>`_.

.. code-block:: bash

	git clone https://github.com/Ricardicus/ric-script
	cd ric-script
	# on linux or mac
	make
	# or, with meson:
	python3 -m venv venv
	source venv/bin/activate
	pip install -r requirements.txt
	meson builddir
	cd builddir
	ninja
	# Now the interpreter binary 'ric' will be found under
	# the folder 'src'
	For windows only meson works:

Windows
~~~~~~~

On Window, only the Meson installation works. You also need to make some additional steps.
You need to install `Meson <https://mesonbuild.com/index.html>`_ and `Python3 <https://www.python.org/>`_.

.. code-block:: bash

	git clone https://github.com/Ricardicus/ric-script
	cd ric-script
	# on windows
	python3 -m venv venv
	venv\Source\activate
	pip install -r requirements.txt
	mkdir install
	meson builddir --prefix %cd%\install
	cd builddir
	ninja
	# Ignore the warnings...
	ninja install
	# Now you have built the program!
	# You find it under ..\install\bin\ric.exe
