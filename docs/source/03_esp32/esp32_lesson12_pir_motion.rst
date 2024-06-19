.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_lesson12_pir_motion:

レッスン12: PIRモーションモジュール (HC-SR501)
=============================================

このレッスンでは、PIR（パッシブ赤外線）モーションセンサーをESP32開発ボードで使用する方法を学びます。センサーからのデジタル入力を読み取って動きを検出し、対応するメッセージをシリアルモニタに出力する方法を学びます。センサーが誰かの存在を検出した際にESP32ボードが「Somebody here!」と表示するための設定とプログラミングについて説明します。

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
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_12_PIR_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/62dbb20a-775e-415b-9032-1db0f0506faf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. PIRセンサーのピンを設定します。PIRセンサーのピンは25番ピンに定義されています。

   .. code-block:: arduino

      const int pirPin = 25;
      int state = 0;

2. PIRセンサーの初期化。 ``setup()``関数でPIRセンサーピンを入力として設定します。これにより、ArduinoがPIRセンサーの状態を読み取ることができます。

   .. code-block:: arduino

      void setup() {
        pinMode(pirPin, INPUT);
        Serial.begin(9600);
      }

3. PIRセンサーからの読み取りと結果の表示。 ``loop()``関数でPIRセンサーの状態を連続的に読み取ります。

   .. code-block:: arduino

      void loop() {
        state = digitalRead(pirPin);
        if (state == HIGH) {
          Serial.println("Somebody here!");
        } else {
          Serial.println("Monitoring...");
          delay(100);
        }
      }

   状態が ``HIGH`` である場合、すなわち動きが検出された場合は、「Somebody here!」というメッセージがシリアルモニタに表示されます。それ以外の場合は「Monitoring...」と表示されます。

