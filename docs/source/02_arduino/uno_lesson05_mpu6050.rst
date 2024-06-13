.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson05_mpu6050:

レッスン 05: ジャイロスコープ & 加速度計モジュール (MPU6050)
==========================================================

このレッスンでは、Arduinoを使用してMPU6050センサーで加速度、回転、温度を測定する方法を学びます。センサーの初期化、範囲の設定、データの読み取り、およびシリアルモニターへの表示方法について探求します。このプロジェクトは、モーションセンサーを扱い、それをArduinoに統合するための実践的なアプローチを提供し、エレクトロニクスやセンサーデータの取り扱いに興味がある人に最適です。

必要なコンポーネント
--------------------------

このプロジェクトには以下のコンポーネントが必要です。

キット全体を購入するのが便利です。こちらのリンクからどうぞ:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_mpu6050`
        - |link_mpu6050_buy|


配線
---------------------------

.. image:: img/Lesson_05_mpu6050_circuit_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b0efe80d-c89d-402e-a213-a778c404565b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. コードは必要なライブラリをインクルードし、MPU6050センサー用のオブジェクトを作成することから始まります。このコードでは、Adafruit_MPU6050ライブラリ、Adafruit_Sensorライブラリ、およびWireライブラリを使用します。 ``Adafruit_MPU6050`` ライブラリはMPU6050センサーと対話し、加速度、回転、温度データを取得するために使用されます。 ``Adafruit_Sensor`` ライブラリは、さまざまなタイプのセンサーに共通のインターフェースを提供します。 ``Wire`` ライブラリはI2C通信に使用され、MPU6050センサーと通信するために必要です。

   .. note:: 
       ライブラリをインストールするには、Arduinoライブラリマネージャを使用し、 **"Adafruit MPU6050"**を検索してインストールします。
   
   .. code-block:: arduino
   
      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      Adafruit_MPU6050 mpu;
   
2. ``setup()``関数では、シリアル通信を初期化し、センサーが検出されているかを確認します。センサーが見つからない場合、Arduinoは「MPU6050チップの検出に失敗しました」というメッセージと共に無限ループに入ります。見つかった場合は、加速度計の範囲、ジャイロの範囲、およびフィルターバンド幅を設定し、安定のために遅延を追加します。

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

3. ``loop()``関数では、プログラムはセンサーの読み取り値を格納するイベントを作成し、その後読み取りを行います。加速度、回転、温度の値がシリアルモニターに表示されます。

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
