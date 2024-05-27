.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson07_speed:

Lesson 07: Infrared Speed Sensor Module
==========================================

In this lesson, you will learn how to use the Raspberry Pi Pico W to interface with an infrared speed sensor module. By connecting the sensor to GPIO 16, you will detect obstructions in real-time. The program monitors the sensor output, and when an obstruction is detected, it prints "Obstruction detected" to the console. If there's no obstruction, it prints "Unobstructed."

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
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_07_Speed_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 16 as an input pin to read the speed sensor
   speed_sensor = Pin(16, Pin.IN)
   
   while True:
       if speed_sensor.value() == 1:
           print("Obstruction detected")
       else:
           print("Unobstructed")
   
       time.sleep(0.1)  # Short delay to reduce CPU usage


Code Analysis
---------------------------

#. **Import Libraries**:

   This code begins by importing necessary libraries. The ``machine`` library is used to interact with the GPIO pins, and the ``time`` library is for adding delays in the program.

   .. code-block:: python

      from machine import Pin
      import time

#. **Sensor Configuration**:

   The infrared speed sensor is connected to GPIO 16. It's set as an input, meaning the Pi Pico W will read data from this pin.

   .. code-block:: python

      speed_sensor = Pin(16, Pin.IN)

#. **Main Loop**:

   The ``while True:`` loop creates an infinite loop. Inside this loop, the program continuously checks the sensor's value.
   
   If ``speed_sensor.value()`` is 1, it means the sensor detects an obstruction. If it is 0, then there is no obstruction.

   .. code-block:: python

      while True:
          if speed_sensor.value() == 1:
              print("Obstruction detected")
          else:
              print("Unobstructed")

#. **Delay to Reduce CPU Usage**:

   A short delay of 0.1 seconds is introduced in each iteration of the loop. This reduces the CPU usage by preventing the loop from running too rapidly.

   .. code-block:: python
     
      time.sleep(0.1)

#. **More**

   If an encoder is mounted on the motor, the rotational speed of the motor can be calculated by counting the number of times an obstruction passes the sensor within a specific period.

   .. image:: img/Lesson_07_Encoder_Disk.png
      :align: center
      :width: 20%