.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson18_ds18b20:

Lesson 18: Temperature Sensor Module (DS18B20)
================================================

In this lesson, you'll learn how to integrate and read temperature data from DS18B20 sensors using the Raspberry Pi Pico W. You'll begin by setting up a OneWire bus on the GPIO pin and scanning for DS18X20 devices. The main focus of the lesson is continuously reading and displaying temperature measurements from these sensors. 

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
    *   - :ref:`cpn_ds18b20`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_18_DS18B20_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import onewire
   import time, ds18x20
   
   # Initialize the OneWire bus on GPIO pin 12
   ow = onewire.OneWire(Pin(12))
   
   # Create a DS18X20 instance using the OneWire bus
   ds = ds18x20.DS18X20(ow)
   
   # Scan for DS18X20 devices on the bus and print their addresses
   roms = ds.scan()
   print('found devices:', roms)
   
   # Continuously read and print temperature data from the sensors
   while True:
       # Start the temperature conversion process
       ds.convert_temp()
       # Wait for the conversion to complete (750 ms for DS18X20)
       time.sleep_ms(750)
       
       # Read and print the temperature from each sensor found on the bus
       for rom in roms:
           print(ds.read_temp(rom))
       
       # Wait for a short period before the next reading (1000 ms)
       time.sleep_ms(1000)



Code Analysis
---------------------------

#. Importing Libraries

   The code begins by importing necessary libraries. ``machine`` is used for controlling GPIO pins, ``onewire`` for the OneWire communication protocol, ``ds18x20`` for the specific temperature sensor, and ``time`` for delays.

   Regarding OneWire in MicroPython, you can refer to |link_micropython_onewire_driver|.

   .. code-block:: python

      from machine import Pin
      import onewire
      import time, ds18x20

#. Initializing OneWire Bus

   A OneWire bus is initialized on GPIO pin 12. This sets up the communication between the Raspberry Pi Pico W and the DS18B20 sensor.

   .. code-block:: python

      ow = onewire.OneWire(Pin(12))

#. Creating DS18X20 Instance

   A DS18X20 instance is created using the OneWire bus. This instance is used to interact with the temperature sensor.

   .. code-block:: python

      ds = ds18x20.DS18X20(ow)

#. Scanning for Devices

   The code scans for DS18X20 devices on the OneWire bus and prints their addresses. This is important for identifying the connected sensors.

   .. code-block:: python

      roms = ds.scan()
      print('found devices:', roms)

#. Reading Temperature Data

   - The main loop of the program continuously reads temperature data from the sensor.
   - It starts the temperature conversion process and waits for it to complete, which takes about 750 milliseconds.
   - It then reads and prints the temperature from each sensor found on the bus.
   - The loop pauses for 1000 milliseconds before repeating.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          ds.convert_temp()
          time.sleep_ms(750)
          for rom in roms:
              print(ds.read_temp(rom))
          time.sleep_ms(1000)