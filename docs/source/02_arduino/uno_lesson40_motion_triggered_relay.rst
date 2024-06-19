.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson40_motion_triggered_relay:

レッスン40: モーション検知リレー
==================================

このArduinoプロジェクトは、パッシブ赤外線（PIR）センサーを使用してリレー操作のライトを制御することを目的としています。PIRセンサーが動きを検知すると、リレーが作動し、ライトが点灯します。ライトは最後に検知された動きから5秒間点灯し続けます。

.. warning::
    このデモンストレーションでは、リレーを使用してRGB LEDモジュールを制御しますが、実際のシナリオでは必ずしも最も実用的なアプローチではありません。
    
    **実際のアプリケーションでは、リレーを他の家電製品に接続できますが、高電圧の交流電圧を扱う際には極めて慎重を要します。不適切または誤った使用は重傷や死亡につながる可能性があります。したがって、高電圧の交流電圧に精通し、知識のある人を対象としています。常に安全を最優先してください。**

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
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_40_Motion_triggered_relay_uno_bb.png
    :width: 100%

コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1678870f-2731-4a6c-826d-2433214c4be4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

このプロジェクトは、PIRモーションセンサーの動きを検知する能力に基づいています。動きを検知すると、Arduinoに信号が送られ、リレーモジュールが作動してライトが点灯します。ライトは最後に検知された動きから指定された時間（この場合は5秒）点灯し続け、動きが停止しても短時間エリアが照明されます。

1. **初期設定と変数の宣言**

   このセグメントでは、コード全体で使用される定数と変数を定義します。リレーとPIRピンを設定し、動きの遅延定数を設定します。最後に、最後に検知された動きの時間を追跡する変数と、動きが検知されたかどうかを監視するフラグを持ちます。

   .. code-block:: arduino
   
      // Define the pin number for the relay
      const int relayPin = 9;
   
      // Define the pin number for the PIR sensor
      const int pirPin = 8;
   
      // Motion delay threshold in milliseconds
      const unsigned long MOTION_DELAY = 5000;
   
      unsigned long lastMotionTime = 0;  // Timestamp of the last motion detection
      bool motionDetected = false;       // Flag to track if motion is detected

2. **setup()関数でのピンの設定**

   ``setup()``関数では、リレーとPIRセンサーのピンモードを設定します。また、最初にリレーがオフになっていることを確認します。

   .. code-block:: arduino
   
      void setup() {
        pinMode(relayPin, OUTPUT);    // Set relayPin as an output pin
        pinMode(pirPin, INPUT);       // Set the PIR pin as an input
        digitalWrite(relayPin, LOW);  // Turn off the relay initially
      }

3. **loop()関数でのメインロジック**

   ``loop()``関数には主要なロジックが含まれています。PIRセンサーが動きを検知すると、 ``HIGH`` 信号を送信し、リレーをオンにして ``lastMotionTime`` を更新します。指定された遅延時間（この場合は5秒）内に動きがなければ、リレーがオフになります。
   
   このアプローチは、動きが断続的または短時間であっても、最後の動き検知後少なくとも5秒間ライトが点灯し続けることを保証し、一貫した照明時間を提供します。

   .. code-block:: arduino
   
      void loop() {
        if (digitalRead(pirPin) == HIGH) {
          lastMotionTime = millis();     // Update the last motion time
          digitalWrite(relayPin, HIGH);  // Turn on the relay (and hence the light)
          motionDetected = true;
        }
   
        // If motion was detected earlier and 5 seconds have elapsed, turn off the relay
        if (motionDetected && (millis() - lastMotionTime >= MOTION_DELAY)) {
          digitalWrite(relayPin, LOW);  // Turn off the relay
          motionDetected = false;
        }
      }

   
   