.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pico_lesson25_water_level:

Lesson 25: Water Level Sensor Module
=========================================

In this lesson, you will learn how to use the Raspberry Pi Pico W to measure water levels with a water level sensor. You'll understand how to connect the sensor to the board, read its analog output using MicroPython, and interpret these readings to determine water levels. This practical session is aimed at developing your skills in sensor integration and data acquisition with the Raspberry Pi Pico W.

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
    *   - :ref:`cpn_water_level`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_25_Water_Level_Sensor_Module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine
   import utime
   
   # Initialize an ADC object on GPIO pin 26.
   # This is typically used for reading analog signals.
   water_level_sensor = machine.ADC(26)
   
   # Continuously read and print sensor data.
   while True:
       value = water_level_sensor.read_u16()  # Read and convert analog value to 16-bit integer
       print("AO:", value)  # Print the analog value
   
       utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read

Code Analysis
---------------------------

#. Importing Libraries

   Here, we import necessary libraries: ``machine`` for hardware interactions and ``utime`` for time-based functions.

   .. code-block:: python

      import machine
      import utime

#. Initializing the Water Level Sensor

   An ADC object is created on GPIO pin 26 to read analog signals from the water level sensor. ADC is crucial for converting the sensor's analog signals to digital format that the microcontroller can process.

   .. code-block:: python

      # Initialize an ADC object on GPIO pin 26.
      water_level_sensor = machine.ADC(26)

#. Reading and Printing Sensor Data

   The ``while True`` loop enables continuous reading of the sensor data. ``read_u16`` method converts the analog signal to a 16-bit integer. The value is printed, and the loop pauses for 200 milliseconds using ``utime.sleep_ms(200)`` to prevent rapid firing.

   .. code-block:: python

      while True:
          value = water_level_sensor.read_u16()  # Read and convert analog value to 16-bit integer
          print("AO:", value)  # Print the analog value

          utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read