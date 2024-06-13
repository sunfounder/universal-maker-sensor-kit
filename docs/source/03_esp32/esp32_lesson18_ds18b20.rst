.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson18_ds18b20:

Lesson 18: 温度センサーモジュール (DS18B20)
================================================

このレッスンでは、ESP32開発ボードを使用してDS18B20温度センサーモジュールから温度データを読み取る方法を学びます。DallasTemperatureライブラリを使用してセンサーとインターフェースし、シリアルモニタに摂氏および華氏単位で温度を表示します。

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
    *   - :ref:`cpn_ds18b20`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_18_DS18B20_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/08628842-3743-431f-871e-51b51ae1851f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. ライブラリのインクルード

   OneWireおよびDallasTemperatureライブラリのインクルードにより、DS18B20センサーとの通信が可能になります。

   .. code-block:: arduino

      #include <OneWire.h>
      #include <DallasTemperature.h>

#. センサーデータピンの定義

   DS18B20はArduinoのデジタルピン25に接続されています。

   .. code-block:: arduino

      #define ONE_WIRE_BUS 25

#. センサーの初期化

   OneWireインスタンスおよびDallasTemperatureオブジェクトが作成され、初期化されます。

   .. code-block:: arduino

      OneWire oneWire(ONE_WIRE_BUS);	
      DallasTemperature sensors(&oneWire);

#. セットアップ関数

   ``setup()``関数では、センサーの初期化とシリアル通信の設定を行います。

   .. code-block:: arduino

      void setup(void)
      {
         sensors.begin();	// Start up the library
         Serial.begin(9600);
      }

#. メインループ

   ``loop()``関数では、プログラムが温度の読み取りを要求し、摂氏および華氏でシリアルモニタに表示します。

   .. code-block:: arduino

      void loop(void)
      { 
         sensors.requestTemperatures();
         Serial.print("Temperature: ");
         Serial.print(sensors.getTempCByIndex(0));
         Serial.print("℃ | ");
         Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
         Serial.println("℉");
         delay(500);
      }