.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson04_mq2:

Lesson 04: Gas Sensor Module (MQ-2)
============================================

In this lesson, you'll learn how to use the Raspberry Pi Pico W to read data from a gas sensor module (MQ-2) using MicroPython. We'll guide you through setting up an ADC on GPIO pin 26 to process analog signals from the MQ-2 sensor. You'll gain practical experience in continuously monitoring and printing sensor data to understand the presence of gases in the environment.

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
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_04_mq2_sensor_circuit_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine
   import utime
   
   # Initialize an ADC object on GPIO pin 26.
   # This is typically used for reading analog signals.
   mq2_AO = machine.ADC(26)
   
   # Continuously read and print sensor data.
   while True:
       value = mq2_AO.read_u16()  # Read and convert analog value to 16-bit integer
       print("AO:", value)  # Print the analog value
   
       utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read

Code Analysis
---------------------------

#. Importing Libraries:

   The code begins by importing necessary libraries: ``machine`` for hardware interactions, and ``utime`` for handling time-related tasks.

   .. code-block:: python

      import machine
      import utime

#. Initializing the MQ-2 Sensor:

   An ADC object is created on GPIO pin 26 to read analog signals from the MQ-2 sensor. The MQ-2 sensor outputs an analog signal which varies with the concentration of gas in the air.

   .. code-block:: python

      mq2_AO = machine.ADC(26)

#. Reading Sensor Data in a Loop:

   The main loop of the program continuously reads the analog value from the sensor. The ``read_u16`` method is used to read the analog value and convert it to a 16-bit integer. This value is then printed out. The loop includes a delay (``utime.sleep_ms(200)``) to wait for 200 milliseconds before reading the sensor value again. This delay is crucial to prevent overwhelming the sensor and the microcontroller with rapid readings.

   .. note:: 
   
     MQ2 is a heating-driven sensor that usually requires preheating before use. During the preheating period, the sensor typically reads high and gradually decreases until it stabilizes.

   .. code-block:: python

      while True:
          value = mq2_AO.read_u16()  # Read and convert analog value to 16-bit integer
          print("AO:", value)  # Print the analog value
          utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read