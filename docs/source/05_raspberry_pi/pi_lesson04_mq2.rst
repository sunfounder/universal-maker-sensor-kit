.. _pi_lesson04_mq2:

Lesson 04: Gas Sensor Module (MQ-2)
============================================

In this lesson, you will learn to use the MQ2 gas sensor with Raspberry Pi for gas detection. The course covers connecting the MQ2 sensor to the GPIO17 pin and programming the Raspberry Pi in Python to read the sensor output. You'll understand how to detect gas presence, with a low signal from the sensor indicating the detection of gas. This project offers a practical introduction to sensor usage and Python scripting on the Raspberry Pi, ideal for beginners interested in environmental monitoring and safety applications.

Required Components
---------------------------

* Raspberry Pi 5
* :ref:`cpn_gas`
* :ref:`cpn_breadboard`

Wiring
---------------------------

.. image:: img/Lesson_04_mq2_sensor_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice
   import time
 
   # Initialize MQ2 sensor on GPIO17
   mq2 = DigitalInputDevice(17)
 
   while True:
      # Detect gas presence (LOW signal indicates gas)
      if mq2.value == 0:
         print("Gas detected!")
      else:
         print("No gas detected.")
 
      # Delay between readings
      time.sleep(1)
 

Code Analysis
---------------------------

#. Importing Modules

   The ``machine`` and ``time`` modules are imported. ``machine`` is used for hardware interactions, and ``time`` is for handling time-related functions like delays.

   .. code-block:: python

      import machine
      import time

#. Initializing the MQ-2 Sensor

   An ADC object is created on GPIO pin 26, which connects to the MQ-2 gas sensor. This step is crucial for reading the analog signals from the sensor.

   .. code-block:: python

      mq2_AO = machine.ADC(26)

#. Reading Sensor Data in a Loop

   - The sensor value is read in a continuous loop. ``mq2_AO.read_u16()`` reads the analog value and converts it to a 16-bit integer.
   - The value is then printed to the console. This loop will run indefinitely, continuously reading and displaying the sensor data.
   - A delay of 200 milliseconds is introduced using ``time.sleep_ms(200)`` to prevent overwhelming the console with data.

   .. note:: 
   
     MQ2 is a heating-driven sensor that usually requires preheating before use. During the preheating period, the sensor typically reads high and gradually decreases until it stabilizes.

   .. code-block:: python

      while True:
          value = mq2_AO.read_u16()  # Read and convert analog value to 16-bit integer
          print("AO:", value)  # Print the analog value
          time.sleep_ms(200)  # Wait for 200 milliseconds before the next read