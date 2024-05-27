.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson03_flame:

Lesson 03: Flame Sensor Module
==================================


In this lesson, you will learn to use a flame sensor with Raspberry Pi for fire detection. We'll show you how to connect the flame sensor to GPIO17 and write a Python script to read its output. You'll learn to identify when the sensor detects a flame, indicated by a change in the sensor's state. This practical project introduces you to the basics of sensor interfacing and Python coding on the Raspberry Pi, suitable for beginners interested in building safety-related projects.

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
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_03_flame_module_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import InputDevice
   import time

   # Connect the digital output of the flame sensor to GPIO17 on the Raspberry Pi
   flame_sensor = InputDevice(17)

   # Continuous loop to read from the sensor
   while True:
       # Check if the sensor is active (no flame detected)
       if flame_sensor.is_active:
           print("No flame detected.")
       else:
           # When the sensor is inactive (flame detected)
           print("Flame detected!")
       # Wait for 1 second before reading the sensor again
       time.sleep(1)


Code Analysis
---------------------------

#. Importing Libraries
   
   The script starts by importing the necessary classes from the gpiozero library and the time module from Python's standard library.

   .. code-block:: python

      from gpiozero import InputDevice
      import time

#. Initializing the Flame Sensor
   
   An ``InputDevice`` object named ``flame_sensor`` is created, representing the flame sensor connected to GPIO pin 17 of the Raspberry Pi. This setup assumes that the digital output of the flame sensor is connected to GPIO17.

   .. code-block:: python

      flame_sensor = InputDevice(17)

#. Continuous Reading Loop
   
   - The script uses a ``while True:`` loop to continuously read the sensor's data. This loop will run indefinitely.
   - Inside the loop, an ``if`` statement checks the state of the flame sensor using the ``is_active`` property.
   - If ``flame_sensor.is_active`` is ``True``, it indicates no flame is detected, and "No flame detected." is printed.
   - If ``flame_sensor.is_active`` is ``False``, it indicates a flame is detected, and "Flame detected!" is printed.
   - The ``time.sleep(1)`` command pauses the loop for 1 second between each sensor reading, preventing the script from overloading the CPU.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if flame_sensor.is_active:
              print("No flame detected.")
          else:
              print("Flame detected!")
          time.sleep(1)