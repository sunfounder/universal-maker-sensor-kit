.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson02_soil_moisture:

Lesson 02: Capacitive Soil Moisture Module
============================================

In this lesson, you'll learn how to use the Raspberry Pi Pico W to measure soil moisture levels using a capacitive sensor and an ADC (Analog to Digital Converter). This beginner-friendly project will introduce you to handling analog signals in MicroPython. 

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
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_02_Capacitive_Soil_Moisture_Module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import ADC
   import time
   
   # Initialize an ADC object on GPIO pin 26.
   # This is typically used for reading analog signals.
   sensor_AO = ADC(26)
   
   # Continuously read and print sensor data.
   while True:
       value = sensor_AO.read_u16()  # Read and convert analog value to 16-bit integer
       print("AO:", value)  # Print the analog value
   
       time.sleep_ms(200)  # Wait for 200 milliseconds before the next read

Code Analysis
---------------------------

#. Importing Libraries:

   .. code-block:: python

      from machine import ADC
      import time

#. ADC Setup:

   .. code-block:: python

      sensor_AO = ADC(26)

   This code initializes an ADC object on GPIO pin 26. ADC is used to convert analog signals (from analog sensors) to digital data that the microcontroller can process.

#. Reading Sensor Data in a Loop:

   .. code-block:: python
    
      while True:
          value = sensor_AO.read_u16()
          print("AO:", value)
          time.sleep_ms(200)

   The ``while True`` loop runs indefinitely, constantly reading data from the sensor. The ``read_u16()`` method reads the analog value and converts it to a 16-bit unsigned integer. The ``print`` statement displays this value. The ``time.sleep_ms(200)`` causes the loop to wait for 200 milliseconds before reading the sensor value again, preventing excessive data readings and console output.