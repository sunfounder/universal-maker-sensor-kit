.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson21_vl53l0x:

Lesson 21: Time of Flight Micro-LIDAR Distance Sensor (VL53L0X)
====================================================================

In this lesson, you'll learn how to use the Raspberry Pi to connect with a Time of Flight Micro-LIDAR Distance Sensor (VL53L0X). You'll be guided through setting up the sensor, initializing I2C communication, and measuring distances in real-time. This project will enhance your comprehension of connecting hardware with the Raspberry Pi and utilizing Python for practical applications. Additionally, you'll delve into adjusting measurement parameters to meet varying accuracy and speed needs.

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
    *   - :ref:`cpn_VL53L0X`
        - |link_vl53l0x_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_21_vl53l0x_pi_bb.png
    :width: 100%


Install Library
---------------------------

.. note::
    The adafruit-circuitpython-vl53l0x library relies on Blinka, so please ensure that Blinka has been installed. To install libraries, refer to :ref:`install_blinka`.

Before installing the library, please make sure that the virtual Python environment is activated:

.. code-block:: bash

   source ~/env/bin/activate

Install adafruit-circuitpython-vl53l0x library:

.. code-block:: bash

   pip3 install adafruit-circuitpython-vl53l0x


Code
---------------------------

.. note::
   - Please ensure that you have installed the Python library required for running the code according to the "Install Library" steps.
   - Before running the code, please make sure that you have activated the virtual Python environment with blinka installed. You can activate the virtual environment using a command like this:

     .. code-block:: bash
  
        source ~/env/bin/activate

   - Find the code for this lesson in ``universal-maker-sensor-kit-main/pi/`` directory, or directly copy and paste the code below. Execute the code by running the following commands in terminal:

     .. code-block:: bash
  
        python 21_vl53l0x_module.py


.. code-block:: python

   # SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
   # SPDX-License-Identifier: MIT
   
   # Simple demo of the VL53L0X distance sensor.
   # Will print the sensed range/distance every second.
   import time
   
   import board
   import busio
   
   import adafruit_vl53l0x
   
   # Initialize I2C bus and sensor.
   i2c = busio.I2C(board.SCL, board.SDA)
   vl53 = adafruit_vl53l0x.VL53L0X(i2c)
   
   # Optionally adjust the measurement timing budget to change speed and accuracy.
   # See the example here for more details:
   #   https://github.com/pololu/vl53l0x-arduino/blob/master/examples/Single/Single.ino
   # For example a higher speed but less accurate timing budget of 20ms:
   # vl53.measurement_timing_budget = 20000
   # Or a slower but more accurate timing budget of 200ms:
   # vl53.measurement_timing_budget = 200000
   # The default timing budget is 33ms, a good compromise of speed and accuracy.
   
   try:
       # Main loop will read the range and print it every second.
       while True:
           print("Range: {0}mm".format(vl53.range))
           time.sleep(1.0)
   except KeyboardInterrupt:
       print("Exit")  # Exit on CTRL+C

Code Analysis
---------------------------

#. **Importing Libraries**

   .. code-block:: python
   
       import time
       import board
       import busio
       import adafruit_vl53l0x

   - ``time``: Used for implementing delays.
   - ``board``: Provides access to the physical pins on the Raspberry Pi.
   - ``busio``: Manages I2C communication between the Pi and the sensor.
   - ``adafruit_vl53l0x``: The specific library for the VL53L0X sensor. For more detail about the ``adafruit_vl53l0x`` library, please refer to |link_Adafruit_CircuitPython_VL53L0X|.

   .. raw:: html
      
      <br/>

#. **Initializing the Sensor**

   .. code-block:: python
   
       # Initialize I2C bus and sensor.
       i2c = busio.I2C(board.SCL, board.SDA)
       vl53 = adafruit_vl53l0x.VL53L0X(i2c)

   - This sets up the I2C communication using SCL (clock line) and SDA (data line) pins.
   - The VL53L0X sensor is then initialized with this I2C bus.

   .. raw:: html
      
      <br/>

#. **Configuration (Optional)**

   .. code-block:: python
   
       # Optionally adjust the measurement timing budget...
       # vl53.measurement_timing_budget = 20000
       # ...

   This part of the code, which is commented out, allows for adjusting the sensor's timing budget, affecting the balance between speed and accuracy.

#. **Main Loop**

   .. code-block:: python
      
       try:
           while True:
               print("Range: {0}mm".format(vl53.range))
               time.sleep(1.0)
       except KeyboardInterrupt:
           print("Exit")

   - In an infinite loop, the sensor's range is read and printed every second.
   - The loop can be exited with a CTRL+C interrupt, which is handled by the KeyboardInterrupt exception.