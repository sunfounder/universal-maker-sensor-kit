.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson24_vibration_sensor:

レッスン24: 振動センサーモジュール (SW-420)
==============================================

このレッスンでは、Arduino Unoを使用して振動センサーで振動を検出する方法を学びます。センサーが振動をArduinoに知らせ、それをトリガーとしてメッセージを表示する仕組みを探ります。このプロジェクトは初心者に最適で、Arduinoにおけるデジタル入力処理とシリアル通信を理解するのに役立ちます。センサーデータの読み取りとスケッチにおける条件ロジックの実装を実践的に学べます。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|



配線
---------------------------

.. image:: img/Lesson_24_vibration_module_circuit_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a04cb423-f55b-465a-bef3-100260eef067/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. 最初のコード行は、振動センサーピンの定数整数宣言です。デジタルピン7を使用して振動センサーの出力を読み取ります。

   .. code-block:: arduino
   
      const int sensorPin = 7;

2. ``setup()`` 関数では、シリアル通信を9600ボーで初期化して、振動センサーからの読み取り結果をシリアルモニターに表示します。また、振動センサーピンを入力として設定します。

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);         // Start serial communication at 9600 baud rate
        pinMode(sensorPin, INPUT);  // Set the sensorPin as an input pin
      }

3. ``loop()`` 関数では、センサーが検出した振動を継続的にチェックします。センサーが振動を検出した場合、シリアルモニターに「Detected vibration...」と表示されます。振動が検出されない場合は、「...」と表示されます。このループは100ミリ秒ごとに繰り返されます。

   .. code-block:: arduino
   
      void loop() {
        if (digitalRead(sensorPin)) {               // Check if there is any vibration detected by the sensor
          Serial.println("Detected vibration...");  // Print "Detected vibration..." if vibration detected
        } 
        else {
          Serial.println("...");  // Print "..." otherwise
        }
        // Add a delay to avoid flooding the serial monitor
        delay(100);
      }