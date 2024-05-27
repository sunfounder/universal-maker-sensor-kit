.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_lesson06_hall_sensor:

Lesson 06: Hall Sensor Module
==================================

In this lesson, you will learn how to use a Hall sensor with an ESP32 Development Board to detect the polarity of a magnetic field. We'll cover reading analog signals from the sensor and interpreting them to differentiate between south and north poles. This project is ideal for beginners in electronics, providing practical experience with sensors and signal processing on the ESP32 platform.

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

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_hall`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_06_Hall_Sensor_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/48094da0-b2f8-4af6-ad59-38504a201cbf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Setting up the Hall Sensor

   .. code-block:: arduino

      const int hallSensorPin = 25;  // Pin connected to the Hall sensor output
      void setup() {
        Serial.begin(9600);             // Initialize serial communication at 9600 bps
        pinMode(hallSensorPin, INPUT);  // Set hall sensor pin as input
      }

   The hall sensor's output is connected to pin 25 on the ESP32 Development Board. The ``setup()`` function is used to initialize serial communication at 9600 bits per second (bps) for displaying data on the serial monitor. The ``pinMode()`` function is used to configure 25 as an input pin.

2. Reading from the Hall Sensor and Determining Polarity

   The Hall sensor module is equipped with a 49E linear Hall effect sensor, which can measure the polarity of the magnetic field's north and south poles as well as the relative strength of the magnetic field. If you place a magnet's south pole near the side marked with 49E (the side with text engraved on it), the value read by the code will increase linearly in proportion to the applied magnetic field strength. Conversely, if you place a north pole near this side, the value read by the code will decrease linearly in proportion to that magnetic field strength. For more details, please refer to :ref:`cpn_hall`.

   .. code-block:: arduino

      void loop() {
        int sensorValue = analogRead(hallSensorPin);  // Read analog value from Hall sensor
        Serial.print(sensorValue);                    // Output raw sensor value to Serial Monitor
        delay(200);                                   // Delay for 200 milliseconds

        // Determine magnetic pole based on sensor value
        if (sensorValue >= 2600) {
          Serial.print(" - South pole detected");  // South pole detected if value >= 2600
        } else if (sensorValue <= 1200) {
          Serial.print(" - North pole detected");  // North pole detected if value <= 1200
        }

        Serial.println();  // New line for next output
      }

