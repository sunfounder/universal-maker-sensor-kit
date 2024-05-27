.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson05_mpu6050:

Lesson 05: Gyroscope & Accelerometer Module (MPU6050)
==========================================================

In this lesson, you'll learn how to interface the Raspberry Pi with the MPU6050, a sensor that integrates a 3-axis gyroscope and accelerometer. You'll explore how to measure acceleration, orientation, and rotation. This project offers hands-on experience with reading sensor data, utilizing Python for hardware interaction, and grasping I2C communication fundamentals. You will also learn to continuously capture acceleration in three axes, rotational speed, and temperature from the sensor. It's an ideal starting point for beginners eager to delve into sensors and motion tracking using the Raspberry Pi.

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
    *   - :ref:`cpn_mpu6050`
        - |link_mpu6050_buy|


Wiring
---------------------------

.. image:: img/Lesson_05_mpu6050_pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   # Import the mpu6050 class and sleep function from respective modules.
   from mpu6050 import mpu6050
   from time import sleep
   
   # Initialize the MPU-6050 sensor with the I2C address 0x68.
   sensor = mpu6050(0x68)
   
   # Infinite loop to continuously read data from the sensor.
   while True:
       # Retrieve accelerometer data from the sensor.
       accel_data = sensor.get_accel_data()
       # Retrieve gyroscope data from the sensor.
       gyro_data = sensor.get_gyro_data()
       # Retrieve temperature data from the sensor.
       temp = sensor.get_temp()
   
       # Print accelerometer data.
       print("Accelerometer data")
       print("x: " + str(accel_data['x']))
       print("y: " + str(accel_data['y']))
       print("z: " + str(accel_data['z']))
   
       # Print gyroscope data.
       print("Gyroscope data")
       print("x: " + str(gyro_data['x']))
       print("y: " + str(gyro_data['y']))
       print("z: " + str(gyro_data['z']))
   
       # Print the temperature in Celsius.
       print("Temp: " + str(temp) + " C")
   
       # Pause for 0.5 seconds before the next read cycle.
       sleep(0.5)
   

Code Analysis
---------------------------

#. Import Statements

   The ``mpu6050`` class is imported from the ``mpu6050`` library, and the ``sleep`` function is imported from the ``time`` module. These imports are necessary for interacting with the MPU-6050 sensor and introducing delays in the code.

   For more information about the ``mpu6050`` library, please visit |link_mpu6050_python_driver|.

   .. code-block:: python

      from mpu6050 import mpu6050
      from time import sleep

#. Sensor Initialization

   An instance of the ``mpu6050`` class is created with the I2C address 0x68 (the default address of the MPU-6050 sensor). This step initializes the sensor for data reading.

   .. code-block:: python

      sensor = mpu6050(0x68)

#. Infinite Loop for Continuous Reading

   An infinite loop (``while True``) is used to continuously read data from the sensor. This is a common practice for sensor-based applications where constant monitoring is required.

   .. code-block:: python

      while True:

#. Reading Sensor Data

   Inside the loop, data from the accelerometer, gyroscope, and temperature sensor is read using the ``get_accel_data``, ``get_gyro_data``, and ``get_temp`` methods of the ``mpu6050`` class instance. These methods return the sensor data in a user-friendly format.

   .. code-block:: python

      accel_data = sensor.get_accel_data()
      gyro_data = sensor.get_gyro_data()
      temp = sensor.get_temp()

#. Printing Sensor Data

   The retrieved data is then printed out. Accelerometer and gyroscope data are accessed as dictionary values (x, y, z axes), and temperature is directly printed as a Celsius value.

   .. code-block:: python

      print("Accelerometer data")
      print("x: " + str(accel_data['x']))
      print("y: " + str(accel_data['y']))
      print("z: " + str(accel_data['z']))

      print("Gyroscope data")
      print("x: " + str(gyro_data['x']))
      print("y: " + str(gyro_data['y']))
      print("z: " + str(gyro_data['z']))

      print("Temp: " + str(temp) + " C")

#. Delay Between Readings

   Finally, a half-second delay is introduced using ``sleep(0.5)``. This delay is crucial to prevent overwhelming the Raspberry Pi with continuous data readings.

   .. code-block:: python

      sleep(0.5)