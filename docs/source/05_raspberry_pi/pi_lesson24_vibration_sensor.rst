.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson24_vibration_sensor:

Lesson 24: Vibration Sensor Module (SW-420)
==============================================

In this lesson, you will learn how to use a vibration sensor with the Raspberry Pi. We'll help you connect the sensor to GPIO pin 17 and guide you through writing a simple Python script. This script will monitor the sensor and print a message whenever vibration is detected. This lesson is focused on giving beginners a hands-on experience in connecting a simple sensor to the Raspberry Pi and writing a straightforward script to interact with it. 

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
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_24_vibration_sensor_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import InputDevice
   import time
   
   # Connect the digital output of the vibration sensor to GPIO17 on the Raspberry Pi
   vibration_sensor = InputDevice(17)
   
   # Continuous loop to read from the sensor
   while True:
       # Check if the sensor is active (no vibration detected)
       if vibration_sensor.is_active:
           print("Vibration detected!")
       else:
           # When the sensor is inactive (vibration detected)
           print("...")
       # Wait for 1 second before reading the sensor again
       time.sleep(1)


Code Analysis
---------------------------

#. **Importing Libraries**

   First, we import necessary libraries: ``gpiozero`` for interacting with the GPIO pins, and ``time`` for handling time-related functions.

   .. code-block:: python

      from gpiozero import InputDevice
      import time

#. **Setting Up the Vibration Sensor**

   We initialize the vibration sensor by creating an instance of ``InputDevice`` from the ``gpiozero`` library. The vibration sensor is connected to GPIO pin 17 on the Raspberry Pi.

   .. code-block:: python

      vibration_sensor = InputDevice(17)

#. **Continuous Monitoring Loop**

   A ``while True`` loop is used for continuous monitoring. This loop will run indefinitely until the program is manually stopped.

   .. code-block:: python

      while True:

#. **Sensor State Check and Output**

   - Inside the loop, we use an ``if`` statement to check the state of the vibration sensor. If ``vibration_sensor.is_active`` is ``True``, it means no vibration is detected, and "Vibration detected!" is printed.
   - If ``vibration_sensor.is_active`` is ``False``, indicating vibration, "..." is printed instead.
   - This distinction is crucial for understanding how the sensor's output is interpreted in the code.

   .. code-block:: python

          if vibration_sensor.is_active:
              print("Vibration detected!")
          else:
              print("...")

#. **Delay**

   Finally, ``time.sleep(1)`` adds a 1-second delay between each iteration of the loop. This delay is crucial to prevent the program from overloading the CPU and to make the output readable.

   .. code-block:: python

          time.sleep(1)

