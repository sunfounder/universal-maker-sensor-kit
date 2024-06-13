.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson37_trashcan:

Lesson 37: スマートゴミ箱
==================================

このプロジェクトでは、スマートゴミ箱のコンセプトに基づいています。主な目的は、物体が一定の距離（この場合は20cm）以内に近づいたときに自動的にゴミ箱の蓋を開けることです。この機能は、超音波距離センサーとサーボモーターを組み合わせて実現されます。センサーと物体の間の距離を継続的に測定し、物体が十分に近づくとサーボモーターが作動して蓋を開けます。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式キットを購入するのが便利です。こちらのリンクをご覧ください:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_37_smart_trashcan_uno_bb.png
    :width: 100%

コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f9aacc6c-809f-4fd2-9246-23bb4bdf78a2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

このプロジェクトは、物体とゴミ箱の間の距離をリアルタイムで監視することに基づいています。超音波センサーがこの距離を継続的に測定し、物体が20cm以内に接近すると、ゴミ箱はそれをゴミを捨てる意図と解釈し、自動的に蓋を開けます。この自動化により、通常のゴミ箱にスマートさと便利さが追加されます。

#. 初期設定と変数の宣言

   ここでは、 ``Servo`` ライブラリをインクルードし、使用する定数と変数を定義します。サーボと超音波センサーのピンを宣言し、距離測定値を保持するための配列 ``averDist`` も定義します。

   .. code-block:: arduino
       
      #include <Servo.h>
      Servo servo;
      const int servoPin = 9;
      const int openAngle = 0;
      const int closeAngle = 90;
      const int trigPin = 6;
      const int echoPin = 5;
      long distance, averageDistance;
      long averDist[3];
      const int distanceThreshold = 20;

#. ``setup()``関数

   ``setup()``関数では、シリアル通信を初期化し、超音波センサーのピンを設定し、サーボの初期位置を閉位置に設定します。

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
        servo.attach(servoPin);
        servo.write(closeAngle);
        delay(100);
      }

#. ``loop()``関数

   ``loop()``関数は、距離を継続的に測定し、その平均値を計算して、この平均距離に基づいてゴミ箱の蓋を開閉するかどうかを判断します。

   .. code-block:: arduino
   
      void loop() {
        for (int i = 0; i <= 2; i++) {
          distance = readDistance();
          averDist[i] = distance;
          delay(10);
        }
        averageDistance = (averDist[0] + averDist[1] + averDist[2]) / 3;
        Serial.println(averageDistance);
        if (averageDistance <= distanceThreshold) {
          servo.write(openAngle);
          delay(3500);
        } else {
          servo.write(closeAngle);
          delay(1000);
        }
      }

#. 距離読み取り関数

   この ``readDistance()`` 関数は、超音波センサーと実際に対話します。パルスを送信し、エコーを待ちます。エコーにかかる時間を使用して、センサーと前方の物体との距離を計算します。

   超音波センサーの原理については :ref:`cpn_ultrasonic_principle` を参照してください。

   .. code-block:: arduino
   
      float readDistance() {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        float distance = pulseIn(echoPin, HIGH) / 58.00;
        return distance;
      }