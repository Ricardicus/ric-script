.. image:: images/icon_small.png
   :width: 30px
   :height: 30px
   :scale: 50 %
   :align: right

Docker image
============

It is possible to play around with ric-script in a `docker <https://www.docker.com/get-started>`_ container.
Try this out:

.. code-block:: bash

  docker build -t node-ric-script:1.0 .
  docker run --rm -d -p 3002:3000 node-ric-script:1.0

Now go visit http://localhost:3002, here a little interpreter window (one for inputs, one for outputs) should be 
available to you.
