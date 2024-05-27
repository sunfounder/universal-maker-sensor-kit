.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson22_touch_sensor:

Lesson 22: Touch Sensor Module
==================================

In this lesson, you'll learn how to connect a touch sensor to the Raspberry Pi Pico W in order to control an onboard LED. By using straightforward Python code, you'll configure the touch sensor as an input device. When the sensor detects a touch, it will send a signal to turn on the LED, providing a visual indication that a touch has been detected. Conversely, when there's no touch, the LED stays off. 

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
    *   - :ref:`cpn_touch`
        - |link_touch_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_22_touch_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 16 as an input pin to read the touch sensor state
   touch_sensor = Pin(16, Pin.IN)
   
   # Initialize the onboard LED of the Raspberry Pi Pico W
   led = Pin("LED", Pin.OUT)
   
   while True:
       if touch_sensor.value() == 1:
           led.value(1)  # Turn on the LED
           print("Touch detected!")
       else:
           led.value(0)  # Turn off the LED
           print("No touch detected")
   
       time.sleep(0.1)  # Short delay to reduce CPU usage


Code Analysis
---------------------------

#. **Setting up the pins**:

   Here, we import necessary libraries and set up GPIO pins. The touch sensor is connected to GPIO 16 as an input, and the onboard LED is configured as an output.

   .. code-block:: python

      from machine import Pin
      import time

      touch_sensor = Pin(16, Pin.IN)
      led = Pin("LED", Pin.OUT)

#. **Main loop and touch detection**:

   In an infinite loop, the code constantly checks the state of the touch sensor. If a touch is detected (value equals 1), the LED is turned on and a message is printed. Otherwise, the LED remains off, and a different message is printed. A short delay is added to reduce CPU usage.

   .. code-block:: python

      while True:
          if touch_sensor.value() == 1:
              led.value(1)  # Turn on the LED
              print("Touch detected!")
          else:
              led.value(0)  # Turn off the LED
              print("No touch detected")

          time.sleep(0.1)  # Short delay to reduce CPU usage