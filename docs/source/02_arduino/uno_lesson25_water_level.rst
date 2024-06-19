.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson25_water_level:

レッスン25: 水位センサーモジュール
=========================================

このレッスンでは、Arduinoを使用して水位を測定する方法を学びます。水位センサーが水の高さに応じて異なる電圧レベルを生成し、Arduinoがこれらの電圧レベルをどのように読み取るかを見ていきます。このプロジェクトは初心者に最適で、アナログセンサーの実践的な経験を提供し、Arduinoプラットフォームでのセンサーデータ処理の基本概念を紹介します。

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
    *   - :ref:`cpn_water_level`
        - \-



配線
---------------------------

.. image:: img/Lesson_25_Water_level_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/268011b0-8c0c-42b0-8d21-253a37de0dc8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **センサーピンの初期化**:

   水位センサーを使用する前に、定数変数を使用してピン番号を定義します。これにより、コードが読みやすく、変更しやすくなります。

   .. code-block:: arduino

      const int sensorPin = A0;

#. **シリアル通信の設定**:

   ``setup()`` 関数では、シリアル通信のボーレートを設定します。これは、Arduinoがコンピュータのシリアルモニターと通信するために重要です。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

#. **センサーデータの読み取りとシリアルモニターへの出力**:

   ``loop()`` 関数では、 ``analogRead()`` を使用してセンサーのアナログ値を継続的に読み取り、 ``Serial.println()`` を使用してシリアルモニターに出力します。 ``delay(100)`` 関数は、ループを繰り返す前にArduinoを100ミリ秒待機させ、データ読み取りと送信の速度を制御します。

   .. code-block:: arduino
    
      void loop() {
        Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
        delay(100);                             // Wait for 100 milliseconds
      }