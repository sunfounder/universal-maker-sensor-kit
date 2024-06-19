.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _eps32_lesson01_button:

レッスン01: ボタンモジュール
==================================

このレッスンでは、ESP32開発ボードを使用してボタンがLEDとどのように相互作用するかを学びます。ボタンを押すとLEDが点灯し、離すとLEDが消灯する仕組みを見ていきます。このプロジェクトは、入力および出力操作についての実践的な理解を提供するため、初心者に最適です。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

一式キットを購入すると便利です。リンクはこちら:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

または、以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_button`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_01_Button_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7286feaf-3b32-4ce8-959b-eccd6c99c4e1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. ピンの初期化
 
   ボタンとLEDのピンが定義され、初期化されます。 ``buttonPin``はボタンの状態を読み取るために入力として設定され、 ``ledPin``はLEDを制御するために出力として設定されます。
   
   .. code-block:: arduino

      const int buttonPin = 26;  // Pin number for the button
      const int ledPin = 25;     // Pin number for the LED
      int buttonState = 0;  // Variable to hold the current state of the button

#. セットアップ関数

   この関数は一度だけ実行され、ピンモードを設定します。 ``pinMode(buttonPin, INPUT)`` はボタンピンを入力として設定し、 ``pinMode(ledPin, OUTPUT)`` はLEDピンを出力として設定します。
   
   .. code-block:: arduino

      void setup() {
        pinMode(buttonPin, INPUT);  // Initialize buttonPin as an input pin
        pinMode(ledPin, OUTPUT);    // Initialize ledPin as an output pin
      }

#. メインループ関数

   これはプログラムの中心であり、ボタンの状態が連続して読み取られ、LEDの状態が制御されます。 ``digitalRead(buttonPin)``はボタンの状態を読み取ります。ボタンが押されている場合（状態はLOW）、 ``digitalWrite(ledPin, HIGH)``でLEDを点灯します。押されていない場合、LEDは消灯します（ ``digitalWrite(ledPin, LOW)``）。

   このプロジェクトで使用される:ref:`ボタンモジュール<cpn_button>`には内部プルアップ抵抗があり（その:ref:`回路図<cpn_button_sch>`を参照）、ボタンが押されると低レベルになり、離されると高レベルのままになります。
   
   .. code-block:: arduino

      void loop() {
        // Read the current state of the button
        buttonState = digitalRead(buttonPin);

        // Check if the button is pressed (LOW)
        if (buttonState == LOW) {
          digitalWrite(ledPin, HIGH);  // Turn the LED on
        } else {
          digitalWrite(ledPin, LOW);  // Turn the LED off
        }
      }
