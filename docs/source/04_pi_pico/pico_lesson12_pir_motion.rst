.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson12_pir_motion:

Lesson 12: PIR Motion Module (HC-SR501)
============================================

In this lesson, you'll learn how to connect a PIR Motion Sensor to the Raspberry Pi Pico W. You'll discover how to configure the sensor for motion detection and use basic MicroPython code to react to movement. By monitoring the PIR sensor, you'll gain experience in managing digital inputs and creating a simple security measure or automation trigger.

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
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_12_pir_module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Initialize PIR sensor connected to pin 16 as input
   pir_sensor = Pin(16, Pin.IN)
   
   while True:
       # Check the PIR sensor value
       if pir_sensor.value() == 0:  
           print("Monitoring...")  # No motion detected
       else:
           print("Somebody here!")  # Motion detected
   
       time.sleep(0.1)  # Short delay of 0.1 seconds to reduce CPU usage

Code Analysis
---------------------------

#. Importing modules

   The ``machine`` module is imported to use the ``Pin`` class for GPIO pin control. The ``time`` module is imported for creating delays in the loop.

   .. code-block:: python

      from machine import Pin
      import time

#. Initializing the PIR sensor

   The PIR sensor is connected to GPIO pin 16 of the Raspberry Pi Pico W. It is set as an input device because it sends data to the microcontroller.

   .. code-block:: python

      # Initialize PIR sensor connected to pin 16 as input
      pir_sensor = Pin(16, Pin.IN)

#. Main loop

   The ``while True`` loop makes the code run continuously. Inside this loop, the PIR sensor's value is checked. If the value is ``0``, it means no motion is detected. Otherwise, motion is detected. A delay of 0.1 seconds is added to reduce CPU usage and prevent the code from running too fast.

   .. code-block:: python

      while True:
          # Check the PIR sensor value
          if pir_sensor.value() == 0:  
              print("Monitoring...")  # No motion detected
          else:
              print("Somebody here!")  # Motion detected

          time.sleep(0.1)  # Short delay of 0.1 seconds to reduce CPU usage