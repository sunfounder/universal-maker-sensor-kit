.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pi_lesson19_dht11:

Lesson 19: Temperature and Humidity Sensor Module (DHT11)
====================================================================

In this lesson, you will learn how to connect and read data from a DHT11 temperature and humidity sensor using a Raspberry Pi. You will learn how to set up the sensor, read temperature in both Celsius and Fahrenheit, and obtain humidity readings. This project introduces you to working with external sensors, handling real-time data, and basic exception handling in Python. 

Required Components
---------------------------

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