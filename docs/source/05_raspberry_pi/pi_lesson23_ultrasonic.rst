.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pi_lesson23_ultrasonic:

Lesson 23: Ultrasonic Sensor Module (HC-SR04)
================================================

In this lesson, you'll learn how to connect an ultrasonic distance sensor to a Raspberry Pi and write a Python script for reading distance measurements. We'll guide you through the process of wiring the sensor's trigger pin to GPIO 17 and the echo pin to GPIO 27. The provided Python code will assist you in measuring distances and displaying them in centimeters. 

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_23_ultrasonic_sensor_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   #!/usr/bin/env python3
   from gpiozero import DistanceSensor
   from time import sleep

   # Initialize the DistanceSensor using GPIO Zero library
   # Trigger pin is connected to GPIO 17, Echo pin to GPIO 27
   sensor = DistanceSensor(echo=27, trigger=17)

   try:
       # Main loop to continuously measure and report distance
       while True:
           dis = sensor.distance * 100  # Measure distance and convert from meters to centimeters
           print('Distance: {:.2f} cm'.format(dis))  # Print the distance with two decimal precision
           sleep(0.3)  # Wait for 0.3 seconds before the next measurement

   except KeyboardInterrupt:
       # Handle KeyboardInterrupt (Ctrl+C) to gracefully exit the loop
       pass



Code Analysis
---------------------------

#. Importing Libraries
   
   The script begins by importing ``DistanceSensor`` from the gpiozero library for the ultrasonic sensor, and ``sleep`` from the time module for timing control.

   .. code-block:: python

      from gpiozero import DistanceSensor
      from time import sleep

#. Initializing the Distance Sensor
   
   A ``DistanceSensor`` object named ``sensor`` is created with ``echo`` and ``trigger`` pins connected to GPIO 27 and GPIO 17, respectively. These pins are used to send and receive the ultrasonic signals for distance measurement.

   .. code-block:: python

      sensor = DistanceSensor(echo=27, trigger=17)

#. Implementing the Continuous Monitoring Loop
   
   - A ``try`` block with an infinite loop (``while True:``) is used to continuously measure the distance.
   - Within the loop, ``sensor.distance`` gives the measured distance in meters, which is then converted to centimeters and stored in ``dis``.
   - The distance is printed with two decimal points of precision using the ``format`` method.
   - ``sleep(0.3)`` adds a 0.3-second delay between each measurement to control the frequency of readings and reduce CPU load.

   .. raw:: html

      <br/>

   .. code-block:: python

      try:
          while True:
              dis = sensor.distance * 100
              print('Distance: {:.2f} cm'.format(dis))
              sleep(0.3)

#. Handling KeyboardInterrupt for Graceful Exit
   
   The ``except`` block is used to catch a KeyboardInterrupt (typically Ctrl+C). When this occurs, the script exits the loop gracefully without any additional actions.

   .. code-block:: python

      except KeyboardInterrupt:
          pass