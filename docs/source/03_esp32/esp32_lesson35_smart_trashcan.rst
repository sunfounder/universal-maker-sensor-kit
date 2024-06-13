.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _esp32_trashcan:

レッスン 35: スマートゴミ箱
==================================

このプロジェクトはスマートゴミ箱の概念に基づいています。
主な目的は、物体が設定された距離（この場合は20cm）以内に近づくと、ゴミ箱の蓋が自動的に開くようにすることです。
この機能は、超音波距離センサーとサーボモーターを組み合わせて実現します。
物体とセンサー間の距離は継続的に測定されます。
物体が十分に近い場合、サーボモーターが作動して蓋が開きます。



必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。こちらがリンクです：

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_35_smart_trashcan_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a4b1e0f2-4e01-4adc-9cb9-f984ca76dbfa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    コード解析
---------------------------

このプロジェクトは、ゴミ箱と物体の間の距離をリアルタイムで監視することに基づいています。超音波センサーがこの距離を継続的に測定し、物体が20cm以内に近づいた場合、ゴミ箱はそれをゴミを捨てる意図と解釈し、自動的に蓋を開きます。この自動化により、通常のゴミ箱にスマートさと便利さが追加されます。

#. 初期設定と変数の宣言

   ここでは、 ``ESP32Servo``ライブラリをインクルードし、使用する定数と変数を定義します。サーボと超音波センサーのピンが宣言されています。また、3つの距離測定値を保持する配列 ``averDist``もあります。

   .. code-block:: arduino
       
        #include <ESP32Servo.h>

        // Set up the servo motor parameters
        Servo servo;
        const int servoPin = 27;
        const int openAngle = 0;
        const int closeAngle = 90;

        // Define the minimum and maximum pulse widths for the servo
        const int minPulseWidth = 500; // 0.5 ms
        const int maxPulseWidth = 2500; // 2.5 ms


        // Set up the ultrasonic sensor parameters
        const int trigPin = 26;
        const int echoPin = 25;
        long distance, averageDistance;
        long averDist[3];

        // Distance threshold in centimeters
        const int distanceThreshold = 20;

#. ``setup()``関数

   ``setup()``関数はシリアル通信を初期化し、超音波センサーのピンを設定し、サーボを閉じた位置に初期設定します。

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

   ``loop()``関数は、距離を継続的に測定し、その平均値を計算し、この平均距離に基づいてゴミ箱の蓋を開閉する役割を担っています。

   .. code-block:: arduino
   
        void loop() {
            // Measure the distance three times
            for (int i = 0; i <= 2; i++) {
                distance = readDistance();
                averDist[i] = distance;
                delay(10);
            }

            // Calculate the average distance
            averageDistance = (averDist[0] + averDist[1] + averDist[2]) / 3;
            Serial.println(averageDistance);

            // Control the servo based on the averaged distance
            if (averageDistance <= distanceThreshold) {
                servo.attach(servoPin);  // Reattach the servo before sending a command
                delay(1);
                servo.write(openAngle);  // Rotate the servo to the open position
                delay(3500);
            } else {
                servo.write(closeAngle);  // Rotate the servo back to the closed position
                delay(1000);
                servo.detach();  // Detach the servo to save power when not in use
            }
        }
        

#. 距離測定関数

   この関数``readDistance()``は、実際に超音波センサーとやり取りを行います。パルスを送信し、エコーを待ちます。エコーの時間を使用して、センサーと前方の物体との距離を計算します。

   超音波センサーの原理については、:ref:`cpn_ultrasonic_principle` を参照してください。

   .. code-block:: arduino
   
        float readDistance() {
            // Send a pulse on the trigger pin of the ultrasonic sensor
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);

            // Measure the pulse width of the echo pin and calculate the distance value
            float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
            return distance;
        }

#. サーボ書き込み関数

    この関数は、角度値をパルス幅にマップし、 ``writeMicroseconds(pulseWidth)``関数を呼び出してサーボを特定の角度に動かします。

    .. code-block:: arduino
        
        // Function to make the servo work
        void servoWrite(int angle){
            int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
            servo.writeMicroseconds(pulseWidth);
        }
