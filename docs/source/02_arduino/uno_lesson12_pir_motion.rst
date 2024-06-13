.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！


.. _uno_lesson12_pir_motion:

レッスン12: PIRモーションモジュール (HC-SR501)
============================================

このレッスンでは、PIR（パッシブ赤外線）モーションセンサーをArduino Unoで使用する方法を学びます。センサーが動きを検出し、Arduinoに信号を送信する仕組みを確認し、その信号に基づいて反応を引き起こします。このプロジェクトは、デジタル入力、シリアル通信、条件プログラミングの実践を通じて初心者に最適な教材です。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式をまとめて購入すると便利です。リンクはこちら：

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
    *   - :ref:`cpn_pir_motion`
        - \-


配線
---------------------------

.. image:: img/Lesson_12_pir_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75947bcf-8e55-4737-b1b7-f17b4a28e775/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. PIRセンサーピンの設定。PIRセンサーのピンは2番ピンとして定義されています。

   .. code-block:: arduino

      const int pirPin = 2;
      int state = 0;

2. PIRセンサーの初期化。 ``setup()`` 関数内で、PIRセンサーピンを入力として設定します。これにより、ArduinoがPIRセンサーの状態を読み取ることができます。

   .. code-block:: arduino

      void setup() {
        pinMode(pirPin, INPUT);
        Serial.begin(9600);
      }

3. PIRセンサーからの読み取りと結果の表示。 ``loop()`` 関数内で、PIRセンサーの状態を連続して読み取ります。

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

   状態が ``HIGH``、つまり動きが検出された場合、"Somebody here!"というメッセージがシリアルモニターに表示されます。それ以外の場合は、"Monitoring..." が表示されます。

