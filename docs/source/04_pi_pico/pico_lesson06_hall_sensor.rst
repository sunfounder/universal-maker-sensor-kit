.. _pico_lesson06_hall_sensor:

Lesson 06: Hall Sensor Module
==================================

In this lesson, you will learn how to use the Raspberry Pi Pico W to measure magnetic fields with a Hall effect sensor. By connecting the sensor to the Pico W, you'll discover how to read analog values and interpret them to detect the presence and type of magnetic poles. This engaging project is perfect for those starting out, as it provides practical experience with analog input processing on the Raspberry Pi Pico W using MicroPython. You'll understand how to set up the sensor, read its data, and apply conditional logic to determine the magnetic pole type, enhancing your skills in electronics and programming.

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
    *   - :ref:`cpn_hall`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_06_Hall_Sensor_Module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine
   import utime
   
   # Initialize an ADC on GPIO pin 26 for Hall effect sensor readings.
   hall_sensor = machine.ADC(26)
   
   # Continuously monitor and process Hall sensor data.
   while True:
       # Read the analog value from the sensor and convert to a 16-bit integer.
       value = hall_sensor.read_u16()
       print(value, end="")  # Output the raw sensor value.
   
       # Detect and print the type of magnetic pole based on the sensor reading.
       if value >= 48000:
           print(" - South pole detected", end="")
       elif value <= 18000:
           print(" - North pole detected", end="")
   
       print()
   
       # Wait 200 milliseconds before the next sensor reading
       utime.sleep_ms(200)


Code Analysis
---------------------------


#. **Import Necessary Modules**:

   This section imports the required modules. ``machine`` is used for hardware interfaces, and ``utime`` provides timing functions.

   .. code-block:: python

      import machine
      import utime



#. **Initialize the Hall Sensor**:

   Here, we initialize an ADC (Analog-to-Digital Converter) on GPIO pin 26. This is where the Hall sensor is connected. The ``machine.ADC`` function is used to read analog values from the sensor.

   .. code-block:: python
   
      hall_sensor = machine.ADC(26)
   
   

#. **Main Loop for Sensor Reading**:

   In this loop, ``hall_sensor.read_u16()`` reads the sensor's analog value and converts it to a 16-bit integer. This loop will run indefinitely.

   .. code-block:: python

      while True:
          value = hall_sensor.read_u16()

#. **Processing Sensor Data**:

   After reading the value, the code checks whether it falls within certain thresholds to determine if a magnetic North or South pole is detected. The values ``48000`` and ``18000`` are threshold values that represent the presence of different magnetic poles. You can adjust the threshold values representing the South and North poles according to actual conditions.

   The Hall sensor module is equipped with a 49E linear Hall effect sensor, which can measure the polarity of the magnetic field's north and south poles as well as the relative strength of the magnetic field. If you place a magnet's south pole near the side marked with 49E (the side with text engraved on it), the value read by the code will increase linearly in proportion to the applied magnetic field strength. Conversely, if you place a north pole near this side, the value read by the code will decrease linearly in proportion to that magnetic field strength. For more details, please refer to :ref:`cpn_hall`.

   .. code-block:: python

      print(value, end="")
      if value >= 48000:
          print(" - South pole detected", end="")
      elif value <= 18000:
          print(" - North pole detected", end="")
      print()



#. **Delay Between Readings**:

   This line introduces a 200-millisecond delay before the next reading, using ``utime.sleep_ms``. This prevents the loop from running too quickly and flooding the output.

   .. code-block:: python

      utime.sleep_ms(200)
 
