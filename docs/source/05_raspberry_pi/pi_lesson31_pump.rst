.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pi_lesson31_pump:

Lesson 31: Centrifugal Pump
==================================

In this lesson, you will learn how to control a pump using a Raspberry Pi. You'll learn how to write a Python script to activate the pump, control its speed, and then stop it after a set period. This project provides a basic understanding of pump control through GPIO interfacing and Python programming, making it a suitable starting point for beginners interested in Raspberry Pi and simple pump applications.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-


Wiring
---------------------------

.. image:: img/Lesson_31_Pump_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import Motor
   from time import sleep
   
   # Define pump pins
   pump = Motor(forward=17, backward=27)  # Using Raspberry Pi GPIO pin numbers
   
   # Activate the pump
   pump.forward(speed=1)  # Set pump speed, range is 0 to 1
   sleep(5)               # Run the pump for 5 seconds
   
   # Deactivate the pump
   pump.stop()            # Stop the pump



Code Analysis
---------------------------

#. Import Libraries
   
   The ``gpiozero`` library is used for controlling the motor, and the ``time`` library's ``sleep`` function is for delays.

   .. code-block:: python

      from gpiozero import Motor
      from time import sleep

#. Define Pump Pins
   
   A ``Motor`` object is created with two GPIO pins: one for forward and one for backward operation. In this case, GPIO 17 and 27 are used.

   .. code-block:: python

      pump = Motor(forward=17, backward=27)

#. Activate the pump
   
   The motor is activated in the forward direction with a specified speed using ``pump.forward(speed=1)``. The speed parameter ranges from 0 (stopped) to 1 (full speed). The motor runs for 5 seconds, as defined by ``sleep(5)``.

   .. code-block:: python

      pump.forward(speed=1)
      sleep(5)

#. Deactivate the pump
   
   The motor is stopped using ``pump.stop()``. This is essential for safely halting the motor's operation after the required duration.

   .. code-block:: python

      pump.stop()