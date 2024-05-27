.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson20_bmp280:

Lesson 20: Temperature, Humidity & Pressure Sensor (BMP280)
====================================================================

In this lesson, you'll learn how to connect the BMP280 temperature, humidity, and pressure sensor to the Raspberry Pi Pico W using MicroPython. You'll get practical experience in setting up I2C communication, configuring the BMP280 sensor for weather monitoring, and obtaining temperature and pressure data. By the end of this tutorial, you'll be able to view real-time environmental data on your console.

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_bmp280`
        - |link_bmp280_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_20_bmp280_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import I2C, Pin
   import bmp280
   import time
   
   # Initialize I2C communication
   i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=100000)
   
   # Configure BMP280 sensor
   bmp = bmp280.BMP280(i2c)
   bmp.oversample(bmp280.BMP280_OS_HIGH)
   
   while True:
       # Set sensor to weather monitoring mode
       bmp.use_case(bmp280.BMP280_CASE_WEATHER)
   
       # Print temperature and pressure data
       print("tempC: {}".format(bmp.temperature))
       print("pressure: {}Pa".format(bmp.pressure))
   
       # Read data every second
       time.sleep_ms(1000)


Code Analysis
---------------------------

#. **Importing Libraries and Initializing I2C Communication**:

   This code segment imports necessary libraries and initializes I2C communication. The ``machine`` module is used to interact with the hardware components like I2C and pins. The ``bmp280`` library is imported to interact with the BMP280 sensor.

   For more information about the ``bmp280`` library, please visit |link_micropython_bmp280_driver|.

   .. code-block:: python

      from machine import I2C, Pin
      import bmp280
      import time

      # Initialize I2C communication
      i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=100000)

#. **Configuring the BMP280 Sensor**:

   Here, the BMP280 sensor is configured. An object ``bmp`` is created to interact with the sensor. The oversampling setting is adjusted for higher accuracy.

   .. code-block:: python

      # Configure BMP280 sensor
      bmp = bmp280.BMP280(i2c)
      bmp.oversample(bmp280.BMP280_OS_HIGH)

#. **Reading and Displaying Sensor Data in a Loop**:

   The sensor is continuously read in an infinite loop. Each iteration sets the sensor to weather monitoring mode, reads the temperature and pressure, and prints them. The ``time.sleep_ms(1000)`` ensures the loop runs once every second.

   .. code-block:: python

      while True:
          # Set sensor to weather monitoring mode
          bmp.use_case(bmp280.BMP280_CASE_WEATHER)

          # Print temperature and pressure data
          print("tempC: {}".format(bmp.temperature))
          print("pressure: {}Pa".format(bmp.pressure))

          # Read data every second
          time.sleep_ms(1000)