.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！


.. _uno_lesson13_potentiometer:

レッスン13: ポテンショメーターモジュール
==========================================

このレッスンでは、Arduino Unoを使用してポテンショメーターのアナログ値を読み取る方法を学びます。ポテンショメーターをピンA0に接続し、Arduinoでその値を0から1023まで測定します。このチュートリアルでは、回路の設定、センサーの読み取りコードの作成、シリアルモニターへの表示方法を順を追って説明します。アナログ入力とシリアル通信の実践経験を提供するため、初心者に最適なプロジェクトです。

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_sensor_module_buy|


配線
---------------------------

.. image:: img/Lesson_13_potentiometer_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ce0f8eac-f28f-4168-be2c-bcaabb1b4c78/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. これはポテンショメーターがArduinoボードに接続されるピン番号を定義するコードです。

   .. code-block:: arduino

      const int sensorPin = A0;

#. ``setup()``関数は、Arduinoが電源を入れられたときやリセットされたときに一度だけ実行される特別な関数です。このプロジェクトでは、 ``Serial.begin(9600)`` コマンドが9600ボーのレートでシリアル通信を開始します。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  
      }

#. ``loop()``関数は、プログラムが繰り返し実行されるメイン関数です。この関数では、 ``analogRead()`` 関数を使用してポテンショメーターからアナログ値を読み取り、 ``Serial.println()`` を使用してシリアルモニターに表示します。 ``delay(50)`` コマンドは、次の読み取りを行う前にプログラムを50ミリ秒待機させます。

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));  
        delay(50);
      }
