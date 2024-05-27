.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_lesson05_mpu6050:

Lesson 05: Gyroscope & Accelerometer Module (MPU6050)
==========================================================

In this lesson, you will learn how to connect the MPU6050 accelerometer and gyroscope sensor to an ESP32 Development Board. We will go through setting up the Adafruit_MPU6050 library, initializing the sensor, and configuring its accelerometer and gyro ranges. You'll also learn how to read acceleration, rotation, and temperature data from the sensor and display these values on the serial monitor. This project is ideal for those interested in exploring motion tracking and orientation sensing in their projects, providing a practical experience in working with advanced sensors on the Arduino-compatible ESP32 platform.

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

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_mpu6050`
        - |link_mpu6050_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_05_MPU6050_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9464e05b-2cab-4185-bf6d-983e907dd279/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. The code starts by including the necessary libraries and creating an object for the MPU6050 sensor. This code uses the Adafruit_MPU6050 library, Adafruit_Sensor library, and Wire library. The ``Adafruit_MPU6050`` library is used to interact with the MPU6050 sensor and retrieve acceleration, rotation, and temperature data. The ``Adafruit_Sensor`` library provides a common interface for various types of sensors. The ``Wire`` library is used for I2C communication, which is necessary to communicate with the MPU6050 sensor.

   .. note:: 
       To install the library, use the Arduino Library Manager and search for **"Adafruit MPU6050"** and install it. 
   
   .. code-block:: arduino
   
      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      Adafruit_MPU6050 mpu;
   
2. The ``setup()`` function initializes the serial communication and checks if the sensor is detected. If the sensor is not found, the Arduino enters an infinite loop with a "Failed to find MPU6050 chip" message. If found, the accelerometer range, gyro range, and filter bandwidth are set, and a delay is added for stability.

   .. code-block:: arduino
   
      void setup(void) {
        // Initialize the serial communication
        Serial.begin(9600);
   
        // Check if the MPU6050 sensor is detected
        if (!mpu.begin()) {
          Serial.println("Failed to find MPU6050 chip");
          while (1) {
            delay(10);
          }
        }
        Serial.println("MPU6050 Found!");
   
        // set accelerometer range to +-8G
        mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
   
        // set gyro range to +- 500 deg/s
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);
   
        // set filter bandwidth to 21 Hz
        mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
   
        // Add a delay for stability
        delay(100);
      }

3. In the ``loop()`` function, the program creates events to store the sensor readings and then retrieves the readings. The acceleration, rotation, and temperature values are then printed to the serial monitor.

   .. code-block:: arduino
   
      void loop() {
        // Get new sensor events with the readings
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
   
        // Print out the acceleration, rotation, and temperature readings
        // ...
   
        // Add a delay to avoid flooding the serial monitor
        delay(1000);
      }
