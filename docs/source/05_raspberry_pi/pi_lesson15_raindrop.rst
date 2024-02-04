.. _pi_lesson15_raindrop:

Lesson 15: Raindrop Detection Module
=======================================

In this lesson, you will learn how to detect rain using a digital rain sensor with Raspberry Pi. We will guide you through connecting a rain sensor to GPIO pin 17 on your Raspberry Pi. You'll learn how to program the Raspberry Pi using Python to continuously monitor the sensor. The program will identify whether it's raining or not and display a message accordingly. This practical project is an excellent introduction to environmental sensing, GPIO interfacing, and Python programming, making it ideal for beginners interested in weather-related projects using Raspberry Pi.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_raindrop`
        - |link_raindrop_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_15_raindrop_detection_module_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice  
   from time import sleep  

   # Initialize the sensor as a digital input device on GPIO pin 17
   rain_sensor = DigitalInputDevice(17)

   while True:  # Infinite loop to continuously check the sensor status
       if rain_sensor.is_active:  # Check if the sensor is active (no rain)
           print("No rain detected.")  # Print message for no rain detected
       else:
           print("Rain detected!")  # Print message for rain detected
       sleep(1)  # Wait for 1 second before next check


Code Analysis
---------------------------

#. Importing Libraries
   
   The script starts with importing ``DigitalInputDevice`` from gpiozero for interfacing with the rain sensor, and ``sleep`` from the time module for implementing delays.

   .. code-block:: python

      from gpiozero import DigitalInputDevice  
      from time import sleep  

#. Initializing the Rain Sensor
   
   A ``DigitalInputDevice`` object named ``rain_sensor`` is created, connected to GPIO pin 17. This line configures the rain sensor to communicate with the Raspberry Pi through this GPIO pin.

   .. code-block:: python

      rain_sensor = DigitalInputDevice(17)

#. Implementing Continuous Monitoring Loop
   
   - An infinite loop (``while True:``) is set up to continuously monitor the rain sensor.
   - Inside the loop, an ``if`` statement checks the ``is_active`` property of the ``rain_sensor``.
   - If ``is_active`` is ``True``, it indicates no rain is detected, and "No rain detected." is printed.
   - If ``is_active`` is ``False``, it indicates rain is detected, and "Rain detected!" is printed.
   - ``sleep(1)`` pauses the loop for 1 second between each check, controlling the frequency of sensor polling and reducing CPU usage.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if rain_sensor.is_active:
              print("No rain detected.")
          else:
              print("Rain detected!")
          sleep(1)

