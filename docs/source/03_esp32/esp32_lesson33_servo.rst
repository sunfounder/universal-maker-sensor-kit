.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson33_servo:

レッスン33: サーボモーター (SG90)
===================================

このレッスンでは、ESP32開発ボードを使用してサーボモーターを制御する方法を学びます。サーボモーターを0度から180度までスキャンし、戻すプロセスをカバーし、サーボの動きを管理する実践的な経験を提供します。このプロジェクトは、モーター制御とロボティクスにおけるパルス幅変調（PWM）の使用を理解したい人に最適で、汎用性の高いESP32ボードを活用します。

必要な部品
--------------------------

このプロジェクトには以下の部品が必要です。

すべての部品が揃ったキットを購入すると便利です。リンクはこちら：

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

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_33_Servo_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/877c9719-5f1b-4df1-9d3b-9e9500a5df08/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. ライブラリのインクルード

   サーボモーターの操作を管理するためにESP32Servoライブラリをインクルードします。

   .. code-block:: arduino

     #include <ESP32Servo.h>

#. サーボとピンの定義

   サーボオブジェクトを作成し、サーボ制御用のピンを定義します。

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

     Servo myServo;
     const int servoPin = 25;

#. パルス幅の制限を設定

   サーボの動作範囲を制限するために最小および最大パルス幅を定義します。

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

     const int minPulseWidth = 500; // 0.5 ms
     const int maxPulseWidth = 2500; // 2.5 ms

#. セットアップ関数

   - サーボを定義されたピンに接続し、そのパルス幅の範囲を設定します。
   - サーボの標準PWM周波数である50Hzに設定します。

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

     void setup() {
       myServo.attach(servoPin, minPulseWidth, maxPulseWidth);
       myServo.setPeriodHertz(50);
     }

#. ループ関数

   - サーボの回転をループ内で制御し、0度から180度まで回転させ、再び0度に戻します。
   - ``writeMicroseconds()`` を使用して、パルス幅に基づいてサーボの位置を設定します。

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

      void loop() {
        // Rotate the servo from 0 to 180 degrees
        for (int angle = 0; angle <= 180; angle++) {
          int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
          myServo.writeMicroseconds(pulseWidth);
          delay(15);
        }
      
        // Rotate the servo from 180 to 0 degrees
        for (int angle = 180; angle >= 0; angle--) {
          int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
          myServo.writeMicroseconds(pulseWidth);
          delay(15);
        }
      }