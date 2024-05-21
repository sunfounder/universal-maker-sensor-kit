.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pi_lesson20_bmp280:

Lesson 20: Temperature, Humidity & Pressure Sensor (BMP280)
====================================================================

In this lesson, you will learn how to connect and read data from a BMP280 sensor that measures temperature, humidity, and pressure using a Raspberry Pi. You'll set up the sensor and write a Python script to measure environmental data including temperature, atmospheric pressure, and altitude.

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
    *   - :ref:`cpn_bmp280`
        - |link_bmp280_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_20_bmp280_pi_bb.png
    :width: 100%


Install Library
---------------------------

.. note::
    The adafruit-circuitpython-bmp280 library relies on Blinka, so please ensure that Blinka has been installed. To install libraries, refer to :ref:`install_blinka`.

Before installing the library, please make sure that the virtual Python environment is activated:

.. code-block:: bash

   source ~/env/bin/activate

Install adafruit-circuitpython-bmp280 library:

.. code-block:: bash

   pip install adafruit-circuitpython-bmp280


Run the Code
---------------------------

.. note::
   - Please ensure that you have installed the Python library required for running the code according to the "Install Library" steps.
   - Before running the code, please make sure that you have activated the virtual Python environment with blinka installed. You can activate the virtual environment using a command like this:

     .. code-block:: bash
  
        source ~/env/bin/activate

   - Find the code for this lesson in ``universal-maker-sensor-kit-main/pi/`` directory, or directly copy and paste the code below. Execute the code by running the following commands in terminal:

     .. code-block:: bash
  
        python 22_touch_sensor_module.py



.. code-block:: python

   import time
   import board
   
   import adafruit_bmp280
   
   # Create sensor object, communicating over the board's default I2C bus
   i2c = board.I2C()  # uses board.SCL and board.SDA
   bmp280 = adafruit_bmp280.Adafruit_BMP280_I2C(i2c,address=0x76)
   
   # change this to match the location's pressure (hPa) at sea level
   bmp280.sea_level_pressure = 1013.25
   
   try:
      while True:
         print("\nTemperature: %0.1f C" % bmp280.temperature)
         print("Pressure: %0.1f hPa" % bmp280.pressure)
         print("Altitude = %0.2f meters" % bmp280.altitude)
         time.sleep(2)
   except KeyboardInterrupt:
       print("Exit")  # Exit on CTRL+C


Code Analysis
---------------------------

#. Setting up the sensor

   Import necessary libraries and create an object to interact with the BMP280 sensor. ``board.I2C()`` sets up the I2C communication. ``adafruit_bmp280.Adafruit_BMP280_I2C(i2c, address=0x76)`` initializes the BMP280 sensor with its I2C address.

   For more detail about the ``adafruit_bmp280`` library, please refer to |link_Adafruit_CircuitPython_BMP280|.

   .. code-block:: python

      import time
      import board
      import adafruit_bmp280
      i2c = board.I2C()
      bmp280 = adafruit_bmp280.Adafruit_BMP280_I2C(i2c, address=0x76)

#. Configuring sea-level pressure

   Set the ``sea_level_pressure`` property of the BMP280 object. This value is needed to calculate altitude.

   .. code-block:: python

      bmp280.sea_level_pressure = 1013.25

#. Reading data in a loop

   Use a ``while True`` loop to continuously read data from the sensor. ``bmp280.temperature``, ``bmp280.pressure``, and ``bmp280.altitude`` read the temperature, pressure, and altitude, respectively. ``time.sleep(2)`` pauses the loop for 2 seconds.

   .. code-block:: python

      try:
         while True:
            print("\nTemperature: %0.1f C" % bmp280.temperature)
            print("Pressure: %0.1f hPa" % bmp280.pressure)
            print("Altitude = %0.2f meters" % bmp280.altitude)
            time.sleep(2)
      except KeyboardInterrupt:
         print("Exit")

#. Handling interruptions

   The ``try`` and ``except KeyboardInterrupt:`` block allows the program to exit gracefully when you press CTRL+C.

   .. code-block:: python

      try:
         # while loop code here
      except KeyboardInterrupt:
         print("Exit")