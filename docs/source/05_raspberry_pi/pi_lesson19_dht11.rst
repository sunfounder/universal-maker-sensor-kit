.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson19_dht11:

Lesson 19: Temperature and Humidity Sensor Module (DHT11)
====================================================================

In this lesson, you will learn how to connect and read data from a DHT11 temperature and humidity sensor using a Raspberry Pi. You will learn how to set up the sensor, read temperature in both Celsius and Fahrenheit, and obtain humidity readings. This project introduces you to working with external sensors, handling real-time data, and basic exception handling in Python. 

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_19_dht11_module_pi_bb_bb.png
    :width: 100%


Install Library
---------------------------

.. note::
    The adafruit-circuitpython-dht library relies on Blinka, so please ensure that Blinka has been installed. To install libraries, refer to :ref:`install_blinka`.

Before installing the library, please make sure that the virtual Python environment is activated:

.. code-block:: bash

   source ~/env/bin/activate

Install adafruit-circuitpython-dht library:

.. code-block:: bash

   pip install adafruit-circuitpython-dht

Code
---------------------------

.. note::
   - Please ensure that you have installed the Python library required for running the code according to the "Install Library" steps.
   - Before running the code, please make sure that you have activated the virtual Python environment with blinka installed. You can activate the virtual environment using a command like this:

     .. code-block:: bash
  
        source ~/env/bin/activate

   - Find the code for this lesson in ``universal-maker-sensor-kit-main/pi/`` directory, or directly copy and paste the code below. Execute the code by running the following commands in terminal:

     .. code-block:: bash
  
        python 19_dht11_module.py


.. code-block:: python

   import time
   import board
   import adafruit_dht
   
   # Initial the dht device, with data pin connected to:
   dhtDevice = adafruit_dht.DHT11(board.D17)
   
   while True:
       try:
           # Print the values to the serial port
           temperature_c = dhtDevice.temperature
           temperature_f = temperature_c * (9 / 5) + 32
           humidity = dhtDevice.humidity
           print(
               "Temp: {:.1f} F / {:.1f} C    Humidity: {}% ".format(
                   temperature_f, temperature_c, humidity
               )
           )
   
       except RuntimeError as error:
           # Errors happen fairly often, DHT's are hard to read, just keep going
           print(error.args[0])
           time.sleep(2.0)
           continue
       except Exception as error:
           dhtDevice.exit()
           raise error
   
       time.sleep(2.0)


Code Analysis
---------------------------

#. Importing Libraries:

   The code begins by importing necessary libraries. ``time`` for handling delays, ``board`` for accessing Raspberry Pi GPIO pins, and ``adafruit_dht`` for interacting with the DHT11 sensor. For more detail about the ``adafruit_dht`` library, please refer to |Adafruit_CircuitPython_DHT|.

   .. code-block:: python
    
      import time
      import board
      import adafruit_dht

#. Initializing the Sensor:

   The DHT11 sensor is initialized with the data pin connected to GPIO 17 of the Raspberry Pi. This setup is crucial for the sensor to communicate with the Raspberry Pi.

   .. code-block:: python

      dhtDevice = adafruit_dht.DHT11(board.D17)

#. Reading Sensor Data in a Loop:

   The ``while True`` loop allows the program to continuously check the sensor for new data. 

   .. code-block:: python

      while True:

#. Try-Except Blocks:

   Within the loop, a try-except block is used to handle potential runtime errors. Reading from DHT sensors can often result in errors due to timing issues or sensor quirks.

   .. code-block:: python

      try:
          # Sensor data reading code here
      except RuntimeError as error:
          # Handling common sensor reading errors
          print(error.args[0])
          time.sleep(2.0)
          continue
      except Exception as error:
          # Handling other exceptions and exiting
          dhtDevice.exit()
          raise error

#. Reading and Printing Sensor Data:

   The temperature and humidity are read from the sensor and converted into human-readable formats. The temperature is also converted from Celsius to Fahrenheit.

   .. code-block:: python

      temperature_c = dhtDevice.temperature
      temperature_f = temperature_c * (9 / 5) + 32
      humidity = dhtDevice.humidity
      print("Temp: {:.1f} F / {:.1f} C    Humidity: {}% ".format(temperature_f, temperature_c, humidity))

#. Handling Read Errors:

   The DHT11 sensor can often return errors, so the code uses a try-except block to handle these. If an error occurs, the program waits for 2 seconds before attempting to read from the sensor again.

   .. code-block:: python

      except RuntimeError as error:
          print(error.args[0])
          time.sleep(2.0)
          continue

#. General Exception Handling:

   Any other exceptions that might occur are handled by safely exiting the sensor and re-raising the error. This ensures the program doesn't continue in an unstable state.

   .. code-block:: python

      except Exception as error:
          dhtDevice.exit()
          raise error

#. Delay Between Readings:

   A 2-second delay is added at the end of the loop to avoid constant polling of the sensor, which can lead to erroneous readings.

   .. code-block:: python

      time.sleep(2.0)