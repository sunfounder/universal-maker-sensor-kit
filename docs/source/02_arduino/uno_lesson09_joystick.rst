.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _uno_lesson09_joystick:

レッスン 09: ジョイスティックモジュール
=======================================

このレッスンでは、Arduino Unoを使ってジョイスティックモジュールから値を読み取る方法を学びます。ジョイスティックのX軸とY軸をArduinoに接続し、それらの値をシリアルモニタに表示する方法を探ります。さらに、ジョイスティックのスイッチボタンの使用方法についても説明します。このプロジェクトは、Arduinoプラットフォームでのアナログ入力とデジタル入力の実践的な経験を提供する初心者に最適です。

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|


配線
---------------------------

.. image:: img/Lesson_09_joystick_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/82313b82-4ac8-407c-9b65-3e7d548e6520/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. ピンの定義:

   .. code-block:: arduino
   
      const int xPin = A0;  //the VRX attach to
      const int yPin = A1;  //the VRY attach to
      const int swPin = 8;  //the SW attach to

   ジョイスティックピン用の定数を定義します。 ``xPin`` と ``yPin`` はジョイスティックのX軸とY軸用のアナログピン、 ``swPin`` はジョイスティックのスイッチ用のデジタルピンです。

#. セットアップ関数:

   .. code-block:: arduino
   
      void setup() {
        pinMode(swPin, INPUT_PULLUP);
        Serial.begin(9600);
      }

   ``swPin``をプルアップ抵抗付きの入力として初期化し、スイッチの機能を確保します。シリアル通信を9600ボーで開始します。

#. メインループ:

   .. code-block:: arduino
   
      void loop() {
        Serial.print("X: ");
        Serial.print(analogRead(xPin));  // print the value of VRX
        Serial.print("|Y: ");
        Serial.print(analogRead(yPin));  // print the value of VRY
        Serial.print("|Z: ");
        Serial.println(digitalRead(swPin));  // print the value of SW
        delay(50);
      }

   ジョイスティックの軸とスイッチからの値を継続的に読み取り、シリアルモニタに出力します。読み取り間に50msの遅延を追加します。
