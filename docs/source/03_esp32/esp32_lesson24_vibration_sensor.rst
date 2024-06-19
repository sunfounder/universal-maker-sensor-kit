.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson24_vibration_sensor:

レッスン24: 振動センサーモジュール (SW-420)
==============================================

このレッスンでは、ESP32開発ボードと振動センサー (SW-420) を使用して振動を検出する方法を学びます。センサーからデジタル出力を読み取り、条件文を使用してシリアルモニターにメッセージを表示する方法を説明します。センサーが振動を検出すると、「Detected vibration...」と表示され、振動を検出しない場合は「...」と表示されます。このプロジェクトはデジタル入力とシリアル通信を理解するための実践的な方法を提供し、エレクトロニクスやプログラミングの初心者に最適です。

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
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_24_Vibration_Sensor_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a64a9f69-b056-4b41-993e-3f77101091e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. 最初のコード行は振動センサーピンの定数整数宣言です。デジタルピン25を使用して振動センサーからの出力を読み取ります。

   .. code-block:: arduino
   
      const int sensorPin = 25;

2. ``setup()`` 関数では、シリアル通信を9600ボーレートで初期化し、振動センサーの読み取りをシリアルモニターに表示します。また、振動センサーピンを入力として設定します。

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);         // Start serial communication at 9600 baud rate
        pinMode(sensorPin, INPUT);  // Set the sensorPin as an input pin
      }

3. ``loop()`` 関数では、センサーが検出した振動を継続的にチェックします。センサーが振動を検出した場合、シリアルモニターに「Detected vibration...」と表示します。振動を検出しない場合は「...」と表示します。このループは100ミリ秒ごとに繰り返されます。

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