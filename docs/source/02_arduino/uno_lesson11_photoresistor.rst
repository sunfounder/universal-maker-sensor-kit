.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！


.. _uno_lesson11_photoresistor:

レッスン11: フォトレジスターモジュール
========================================

このレッスンでは、Arduino Unoを使用してフォトレジスターセンサーで光の強さを測定する方法を学びます。センサーからのアナログ値を読み取り、表示する方法をカバーします。これらの値は、センサーが検出する光の量を反映します。このプロジェクトは、センサーの取り扱いやArduinoプラットフォームでのアナログ入力の理解を実践するのに最適な初心者向けの教材です。また、センサーデータをシリアルモニターに出力することで、シリアル通信のスキルも向上させることができます。

必要なコンポーネント
-----------------------------

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_sensor_module_buy|


配線
---------------------------

.. image:: img/Lesson_11_photoresistor_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ac4664d2-2f44-4d5f-9cf4-a82eadc74d3e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **センサーピンとシリアル通信の設定**

   setup関数でセンサーピンを定義し、シリアル通信を初期化します。フォトレジスターはアナログピンA0に接続されています。

   .. code-block:: arduino

      const int sensorPin = A0;  // Pin connected to the photoresistor

      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

#. **センサーデータの読み取りと表示**

   loop関数では、センサーからのアナログ値を連続して読み取り、シリアルモニターに表示します。また、読み取り値を安定させるために短い遅延を追加します。

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));  // Read and print the analog value
        delay(50);                              // Short delay to stabilize readings
      }




