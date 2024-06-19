.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson23_ultrasonic:

レッスン23: 超音波センサーモジュール (HC-SR04)
================================================

このレッスンでは、ESP32開発ボードを使用して超音波センサー（HC-SR04）で距離を測定する方法を学びます。センサーのセットアップ、データの読み取り、および距離をセンチメートル単位で計算する方法を説明します。このプロジェクトは、マイクロコントローラーやセンサーを扱う初心者に最適で、データ取得とシリアル通信の実践的な経験を提供します。ESP32のプログラミングスキルを向上させ、超音波センサー技術を理解するための基礎を築くことができます。

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_23_Ultrasonic_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b5dbcdfa-3dc8-4f64-adf9-a3227e3f6044/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. ピン宣言:

   まず、超音波センサー用のピンを定義します。 ``echoPin`` と ``trigPin`` は整数として宣言され、ESP32開発ボードでの物理接続に対応する値が設定されます。

   .. code-block:: arduino

      const int echoPin = 26;
      const int trigPin = 25;

2. ``setup()`` 関数:

   ``setup()`` 関数はシリアル通信を初期化し、ピンモードを設定し、超音波センサーの準備ができていることを示すメッセージを表示します。
 
   .. code-block:: arduino
 
      void setup() {
        Serial.begin(9600);
        pinMode(echoPin, INPUT);
        pinMode(trigPin, OUTPUT);
        Serial.println("Ultrasonic sensor:");
      }

3. ``loop()`` 関数:

   ``loop()`` 関数はセンサーから距離を読み取り、その値をシリアルモニターに表示し、400ミリ秒待機してから繰り返します。

   .. code-block:: arduino

      void loop() {
        float distance = readDistance();
        Serial.print(distance);
        Serial.println(" cm");
        delay(400);
      }

4. ``readDistance()`` 関数:

   ``readDistance()`` 関数は超音波センサーをトリガーし、信号が反射して戻るまでの時間に基づいて距離を計算します。

   詳細については、超音波センサーモジュールの動作 :ref:`原理 <cpn_ultrasonic_principle>` を参照してください。

   .. code-block:: arduino

      float readDistance() {
        digitalWrite(trigPin, LOW);   // Set trig pin to low to ensure a clean pulse
        delayMicroseconds(2);         // Delay for 2 microseconds
        digitalWrite(trigPin, HIGH);  // Send a 10 microsecond pulse by setting trig pin to high
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);  // Set trig pin back to low
        float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
        return distance;
      }
