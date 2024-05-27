.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson29_traffic_light_module:

Lesson 29: Traffic Light Module
==================================

In this lesson, you will learn to simulate traffic lights using a Raspberry Pi. You'll program the Raspberry Pi to control these LEDs in a sequence that resembles traffic lights: the red LED will be active for 3 seconds, the yellow LED will blink in a specific pattern, and then the green LED will turn on for 3 seconds. This project is a practical way to get started with GPIO interfacing and Python programming, suitable for those new to combining hardware and software with the Raspberry Pi.

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_traffic`
        - |link_traffic_light_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_29_Traffic_Light_Module_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import LED
   from time import sleep

   # Initialize LED pins
   red = LED(22)    # Red LED connected to GPIO pin 22
   yellow = LED(27) # Yellow LED connected to GPIO pin 27
   green = LED(17)  # Green LED connected to GPIO pin 17

   # LED control in a continuous loop
   try:
       while True:
           # Red LED cycle
           red.on()     # Turn on red LED
           sleep(3)     # Red LED on for 3 seconds
           red.off()    # Turn off red LED

           # Yellow LED blinking pattern
           yellow.on()  # Turn on yellow LED
           sleep(0.5)   # Yellow LED on for 0.5 second
           yellow.off() # Turn off yellow LED
           sleep(0.5)   # Off for 0.5 second
           yellow.on()  # Repeat blinking
           sleep(0.5)   # Yellow LED on for 0.5 second
           yellow.off() # Turn off yellow LED
           sleep(0.5)   # Off for 0.5 second
           yellow.on()  # Repeat blinking
           sleep(0.5)   # Yellow LED on for 0.5 second
           yellow.off() # Turn off yellow LED
           sleep(0.5)   # Off for 0.5 second

           # Green LED cycle
           green.on()   # Turn on green LED
           sleep(3)     # Green LED on for 3 seconds
           green.off()  # Turn off green LED

   except KeyboardInterrupt:
       # Turn off all LEDs and exit safely on keyboard interrupt
       red.off()
       yellow.off()
       green.off()



Code Analysis
---------------------------

#. Import Libraries
   
   The ``gpiozero`` library is imported to control the GPIO pins, and the ``time`` library's ``sleep`` function is used for timing delays.

   .. code-block:: python

      from gpiozero import LED
      from time import sleep

#. Initialize LED pins
   
   Here, each LED is associated with a specific GPIO pin on the Raspberry Pi using the ``LED`` class from the ``gpiozero`` library.

   .. code-block:: python

      red = LED(22)    # Red LED connected to GPIO pin 22
      yellow = LED(27) # Yellow LED connected to GPIO pin 27
      green = LED(17)  # Green LED connected to GPIO pin 17

#. LED Control Loop
   
   The ``while True:`` loop runs continuously, cycling through each LED. It turns each LED on and off in a specific pattern, using ``on()``, ``off()``, and ``sleep()`` functions.

   - Red LED is turned on for 3 seconds.
   - Yellow LED blinks: 0.5 seconds on, 0.5 seconds off, repeated three times.
   - Green LED is turned on for 3 seconds.

   .. code-block:: python

      try:
          while True:
              # Red LED cycle
              red.on()
              sleep(3)
              red.off()

              # Yellow LED blinking pattern
              # [The pattern is repeated three times]
              
              # Green LED cycle
              green.on()
              sleep(3)
              green.off()

#. Exception Handling
   
   The ``except`` block catches a ``KeyboardInterrupt`` (usually generated by pressing Ctrl+C). It ensures all LEDs are turned off before the program exits, preventing the LEDs from being left in an undefined state.

   .. code-block:: python

      except KeyboardInterrupt:
          red.off()
          yellow.off()
          green.off()