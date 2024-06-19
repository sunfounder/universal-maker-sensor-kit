.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson25_water_level:

レッスン25: 水位センサーモジュール
=========================================

このレッスンでは、ESP32開発ボードを使用して水位センサーを読み取る方法を学びます。センサーのアナログ値を継続的に監視し、シリアルモニタに表示する方法を説明します。このプロジェクトは、センサーの統合とアナログデータの読み取りを理解するための絶好の機会を提供し、エレクトロニクスとマイクロコントローラープログラミングの初心者に最適です。

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
    *   - :ref:`cpn_water_level`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_25_Water_Level_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f312bfd8-5583-4d54-a116-35e32d957ef6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **センサーピンの初期化**:

   水位センサーを使用する前に、定数変数を使用してピン番号を定義します。これにより、コードが読みやすくなり、変更も容易になります。

   .. code-block:: arduino

      const int sensorPin = 25;

#. **シリアル通信の設定**:

   ``setup()`` 関数では、シリアル通信のボーレートを設定します。これは、Arduinoがコンピュータのシリアルモニタと通信するために重要です。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

#. **センサーデータの読み取りとシリアルモニタへの出力**:

   ``loop()`` 関数では、 ``analogRead()`` を使用してセンサーのアナログ値を継続的に読み取り、 ``Serial.println()`` を使用してシリアルモニタに出力します。 ``delay(100)`` 関数は、ループを繰り返す前にArduinoを100ミリ秒待機させ、データの読み取りと送信の速度を制御します。

   .. code-block:: arduino
    
      void loop() {
        Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
        delay(100);                             // Wait for 100 milliseconds
      }