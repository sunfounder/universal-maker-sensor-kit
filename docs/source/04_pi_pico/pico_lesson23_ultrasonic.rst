.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson23_ultrasonic:

Lesson 23: Ultrasonic Sensor Module (HC-SR04)
================================================

In this lesson, you will learn how to measure distances using the Raspberry Pi Pico W and an HC-SR04 ultrasonic sensor. You'll find out how to connect the sensor to the Pico W and write a MicroPython script to control it. The lesson will cover calculating distances based on the time it takes for ultrasonic waves to reflect back from objects. This practical project provides insights into working with sensors, handling digital signals, and basic calculations in MicroPython, suitable for those interested in hardware interfacing with the Raspberry Pi Pico W.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_23_ultrasonic_sensor_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine  # Import machine module for hardware control
   import time  # Import time module for delays
   
   # Define pin numbers for ultrasonic sensor's TRIG and ECHO pins
   TRIG = machine.Pin(17, machine.Pin.OUT)  # TRIG pin set as output
   ECHO = machine.Pin(16, machine.Pin.IN)  # ECHO pin set as input
   
   
   def distance():
       # Function to calculate distance in centimeters
       TRIG.low()  # Set TRIG low
       time.sleep_us(2)  # Wait for 2 microseconds
       TRIG.high()  # Set TRIG high
       time.sleep_us(10)  # Wait for 10 microseconds
       TRIG.low()  # Set TRIG low again
   
       # Wait for ECHO pin to go high
       while not ECHO.value():
           pass
   
       time1 = time.ticks_us()  # Record time when ECHO goes high
   
       # Wait for ECHO pin to go low
       while ECHO.value():
           pass
   
       time2 = time.ticks_us()  # Record time when ECHO goes low
   
       # Calculate the duration of the ECHO pin being high
       during = time.ticks_diff(time2, time1)
   
       # Return the calculated distance (using speed of sound)
       return during * 340 / 2 / 10000  # Distance in centimeters
   
   
   # Main loop
   while True:
       dis = distance()  # Get distance from sensor
       print("Distance: %.2f cm" % dis)  # Print distance
       time.sleep_ms(300)  # Wait for 300 milliseconds before next measurement


Code Analysis
---------------------------

#. **Importing libraries**

   The ``machine`` and ``time`` modules are imported for accessing hardware-specific functions and time-related functions, respectively.

   .. code-block:: python

      import machine
      import time

#. **Pin setup for HC-SR04**

   Two GPIO pins are defined for the HC-SR04 sensor: ``TRIG`` is an output pin to trigger the ultrasonic pulse, and ``ECHO`` is an input pin to receive the reflected pulse.

   .. code-block:: python

      TRIG = machine.Pin(17, machine.Pin.OUT)
      ECHO = machine.Pin(16, machine.Pin.IN)

#. **Distance measurement function**

   The ``distance`` function triggers the ultrasonic pulse and calculates the distance based on the time taken for the echo to return. It uses time-based functions to measure the duration of the echo.

   For more details, please refer to the working :ref:`principle <cpn_ultrasonic_principle>` of the ultrasonic sensor module.

   .. code-block:: python

      def distance():
          TRIG.low()
          time.sleep_us(2)
          TRIG.high()
          time.sleep_us(10)
          TRIG.low()

          while not ECHO.value():
              pass

          time1 = time.ticks_us()

          while ECHO.value():
              pass

          time2 = time.ticks_us()
          during = time.ticks_diff(time2, time1)
          return during * 340 / 2 / 10000

#. **Main loop**

   The main loop continuously calls the ``distance`` function and prints the measured distance. It waits for 300 milliseconds between each measurement to prevent sensor saturation.

   .. code-block:: python
    
      while True:
          dis = distance()
          print("Distance: %.2f cm" % dis)
          time.sleep_ms(300)