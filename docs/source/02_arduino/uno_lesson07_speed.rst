.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson07_speed:

レッスン07: 赤外線速度センサーモジュール
==========================================

このレッスンでは、Arduino Unoを使用して速度センサーモジュールでモーターの速度を測定する方法を学びます。モーターとセンサーのセットアップ、Arduinoのプログラミングによる毎秒回転数の計算、およびデータの表示について説明します。このプロジェクトは、リアルタイムデータ処理とモーター制御の実践的な経験を提供するため、中級学習者に最適です。

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
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-


配線
---------------------------

.. image:: img/Lesson_07_speed_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d705c03-2813-4e71-8ec6-1208684358c9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. ピンの設定と変数の初期化。このセクションでは、モーターと速度センサーのピンを定義します。また、モーターの速度を測定および計算するために使用される変数を初期化します。

   .. code-block:: arduino

      // Define the sensor and motor pins
      const int sensorPin = 11;
      const int motorB_1A = 9;
      const int motorB_2A = 10;
      
      // Define variables for measuring speed
      unsigned long start_time = 0;
      unsigned long end_time = 0;
      int steps = 0;
      float steps_old = 0;
      float temp = 0;
      float rps = 0;

#. ``setup()``関数での初期化。このセクションでは、シリアル通信の設定、ピンモードの構成、および初期モーター速度の設定を行います。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        pinMode(sensorPin, INPUT);
        pinMode(motorB_1A, OUTPUT);
        pinMode(motorB_2A, OUTPUT);
        analogWrite(motorB_1A, 160);
        analogWrite(motorB_2A, 0);
      }

#. ``loop()``関数でのモーター速度の測定。このセクションでは、モーターのステップを1秒間測定します。これらのステップを使用して毎秒回転数（rps）を計算し、その結果をシリアルモニターに表示します。

   ``millis()``関数は、Arduinoボードが現在のプログラムの実行を開始してから経過したミリ秒数を返します。

   .. code-block:: arduino

      void loop() {
        start_time = millis();
        end_time = start_time + 1000;
        while (millis() < end_time) {
          if (digitalRead(sensorPin)) {
            steps = steps + 1;
            while (digitalRead(sensorPin))
              ;
          }
        }
        temp = steps - steps_old;
        steps_old = steps;
        rps = (temp / 20);
        Serial.print("rps:");
        Serial.println(rps);
      }