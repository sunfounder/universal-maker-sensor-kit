.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pico_lesson24_vibration_sensor:

Lesson 24: Vibration Sensor Module (SW-420)
==============================================

In this lesson, you will learn to connect and use a SW-420 Vibration Sensor Module with a Raspberry Pi Pico W. The course guides you through setting up the vibration sensor on GPIO 16 and writing a MicroPython script to monitor vibrations. You will write a loop to continually check the sensor's output, displaying a message when vibrations are detected. This practical exercise introduces you to working with external sensors on the Raspberry Pi Pico W, enhancing your understanding of hardware interfacing and programming in MicroPython.

Required Components
--------------------------

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_24_vibration_module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Initialize GPIO 16 as an input pin for the vibration sensor
   vibration_sensor = Pin(16, Pin.IN)
   
   # Continuously check the vibration sensor's state
   while True:
       # If the sensor detects vibration (value is 1), print a message
       if vibration_sensor.value() == 1:
           print("Vibration detected!")
       # If no vibration is detected, print ellipses
       else:
           print("...")
   
       # Pause for 0.1 seconds to lower the demand on the CPU
       time.sleep(0.1)


Code Analysis
---------------------------

#. Importing Required Libraries

   .. code-block:: python

      from machine import Pin
      import time

   This imports the ``machine`` module for hardware related operations and ``time`` module for handling time-related tasks.

#. Initializing the Vibration Sensor

   .. code-block:: python
 
      # Initialize GPIO 16 as an input pin for the vibration sensor
      vibration_sensor = Pin(16, Pin.IN)
 
   Here, GPIO 16 is set up as an input pin. The ``Pin`` class from the ``machine`` module is used to interact with the GPIO pins. ``Pin.IN`` configures it as an input.

#. Continuous Sensor Monitoring

   .. code-block:: python

      # Continuously check the vibration sensor's state
      while True:

   A ``while True`` loop is used to create an endless loop for continuously checking the sensor's state.

#. Checking Sensor State and Responding

   .. code-block:: python

          # If the sensor detects vibration (value is 1), print a message
          if vibration_sensor.value() == 1:
              print("Vibration detected!")
          # If no vibration is detected, print ellipses
          else:
              print("...")

   Within the loop, ``vibration_sensor.value()`` checks the current state of the sensor. If it returns ``1``, it indicates vibration is detected, and a message is printed. Otherwise, ellipses are printed.

#. Managing CPU Usage

   .. code-block:: python

          # Pause for 0.1 seconds to lower the demand on the CPU
          time.sleep(0.1)

   ``time.sleep(0.1)`` pauses the loop for 0.1 seconds. This is important to prevent the script from consuming too much CPU time.