.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson03_flame:

レッスン03: 炎センサーモジュール
==================================

このレッスンでは、炎センサーをArduinoボードに統合して火の存在を検知する方法を学びます。炎センサーが炎を検知すると、Arduinoの内蔵LEDが点灯し、シリアルモニターに警告メッセージが送信される仕組みを見ていきます。逆に、炎がない場合はLEDが消灯し、異なるメッセージがモニターに表示されます。このプロジェクトは初心者に最適で、Arduinoプラットフォーム上でデジタル入力と出力を管理する方法を包括的に理解するのに役立ちます。センサー統合とリアルタイム応答メカニズムについて、実践的なアプローチを提供します。

必要なコンポーネント
---------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全体のキットを購入するのが便利です。リンクはこちらです:

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
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|


配線
---------------------------

.. image:: img/Lesson_03_flame_module_circuit_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/244b68c4-0c4d-46fb-b220-985d42f4efdc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. 最初のコード行は、炎センサーピンの定数整数宣言です。デジタルピン7を使用して炎センサーの出力を読み取ります。

   .. code-block:: arduino
   
      const int sensorPin = 7;

2. ``setup()``関数は、炎センサーピンを入力として初期化し、内蔵LEDピンを出力として初期化します。また、シリアルモニターにメッセージを表示するために9600ボーレートでシリアル通信を開始します。

   .. code-block:: arduino
   
      void setup() {
        pinMode(sensorPin, INPUT);     // Set the flame sensor pin as input
        pinMode(LED_BUILTIN, OUTPUT);  // Set the built-in LED pin as output
        Serial.begin(9600);            // Initialize the serial monitor at a baud rate of 9600
      }

3. ``loop()``関数では、炎センサーの状態を継続的にチェックします。センサーが炎を検知すると、内蔵LEDが点灯し、シリアルモニターにメッセージが表示されます。炎が検知されない場合は、LEDが消灯し、異なるメッセージが表示されます。このプロセスは100ミリ秒ごとに繰り返されます。

   .. note:: 
      炎の検出閾値は、炎センサーモジュールのポテンショメータを調整することで変更できます。

   .. code-block:: arduino
   
      void loop() {
        // Check if the sensor is detecting a fire
        if (digitalRead(sensorPin) == 0) {
          digitalWrite(LED_BUILTIN, HIGH);  // Turn on the built-in LED
          Serial.println("** Fire detected!!! **");
        } else {
          digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED
          Serial.println("No Fire detected");
        }
        delay(100);
      }
