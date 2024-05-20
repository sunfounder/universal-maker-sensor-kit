.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pico_lesson13_potentiometer:

Lesson 13: Potentiometer Module
==================================

In this lesson, you'll learn how to use a potentiometer with the Raspberry Pi Pico W to measure analog values. The potentiometer, which is a variable resistor, lets you adjust the voltage that the Raspberry Pi Pico W reads on one of its analog input pins. By turning the knob of the potentiometer, you'll observe changes in the input value. This project offers a basic grasp of analog inputs and their application in electronic projects, making it an ideal entry point for beginners in electronics and MicroPython programming.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_13_potentiometer_module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine  # Hardware control library
   import time  # Time control library
   
   potentiometer = machine.ADC(26)  # Initialize ADC on pin 26
   
   while True:
       value = potentiometer.read_u16()  # Read analog value
       print(value)  # Print the value
   
       time.sleep_ms(200)  # Delay of 200 ms between reads


Code Analysis
---------------------------

#. Import Libraries

   First, the necessary libraries are imported. ``machine`` is for hardware control, and ``time`` is for managing delays.

   .. code-block:: python

      import machine  # Hardware control library
      import time     # Time control library

#. Initialize ADC (Analog to Digital Converter)

   The photoresistor is connected to pin 26 of the Pico W. This pin is initialized as an ADC pin to read analog values.

   .. code-block:: python

      potentiometer = machine.ADC(26)  # Initialize ADC on pin 26

#. Reading and Printing the Analog Value
   The code enters an infinite loop (``while True:``) where it continually reads the analog value from the photoresistor using ``potentiometer.read_u16()`` and prints it.

   .. code-block:: python

      while True:
          value = potentiometer.read_u16()  # Read analog value
          print(value)                      # Print the value

#. Adding a Delay

   To prevent the loop from running too fast, a delay of 200 milliseconds is introduced using ``time.sleep_ms(200)``. This gives a readable output and reduces processor load.

   .. code-block:: python

      time.sleep_ms(200)                # Delay of 200 ms between reads