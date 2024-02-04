.. _pi_lesson08_ir_obstacle_avoidance:

Lesson 08: IR Obstacle Avoidance Sensor Module
====================================================

In this lesson, you will learn how to detect obstacles using a sensor with the Raspberry Pi. We will guide you through connecting a digital input sensor to GPIO pin 17. You'll learn how to write a Python script that continuously monitors the sensor to determine the presence of an obstacle. The program will output a message indicating whether an obstacle is detected or not. This straightforward yet practical project is an excellent way to get started with GPIO interfacing and Python programming, making it ideal for beginners interested in exploring sensor integration with the Raspberry Pi.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_08_Obstacle_Avoidance_Sensor_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import InputDevice
   from time import sleep

   # Initialize the sensor as a digital input device on GPIO 17
   sensor = InputDevice(17)

   while True:
      if sensor.is_active:
         print("No obstacle detected")  # Prints when no obstacle is detected
      else:
         print("Obstacle detected")     # Prints when an obstacle is detected
      sleep(0.5)

Code Analysis
---------------------------

#. Importing Libraries
   
   The script begins by importing the ``InputDevice`` class from the gpiozero library for interacting with the sensor, and the ``sleep`` function from Python's time module for pausing execution.

   .. code-block:: python

      from gpiozero import InputDevice
      from time import sleep

#. Initializing the Sensor
   
   An ``InputDevice`` object named ``sensor`` is created, connected to GPIO pin 17. This line assumes that the obstacle sensor is connected to this specific GPIO pin.

   .. code-block:: python

      sensor = InputDevice(17)

#. Implementing the Continuous Monitoring Loop
   
   - The script uses a ``while True:`` loop to continuously check the sensor's state. This loop will run indefinitely until the program is stopped.
   - Inside the loop, an ``if`` statement checks the ``is_active`` property of the ``sensor``. 
   - If ``is_active`` is ``True``, it indicates no obstacle is detected, and "No obstacle detected" is printed.
   - If ``is_active`` is ``False``, indicating an obstacle is detected, "Obstacle detected" is printed.
   - ``sleep(0.5)`` pauses the loop for 0.5 seconds between each check, which helps in reducing the script's processing demand and provides a delay between consecutive sensor readings.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if sensor.is_active:
              print("No obstacle detected")
          else:
              print("Obstacle detected")
          sleep(0.5)

   .. note:: 
   
      If the sensor is not working properly, adjust the IR transmitter and receiver to make them parallel. Additionally, you can adjust the detection range using the built-in potentiometer.