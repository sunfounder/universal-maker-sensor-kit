.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson04_mq2:

レッスン04: ガスセンサーモジュール (MQ-2)
============================================

このレッスンでは、Arduino Unoを使用してMQ-2ガスセンサーでガス濃度を測定する方法を学びます。センサーが0から1023までのアナログ出力値を読み取り、空気中のガス濃度を表す仕組みについて探求します。このプロジェクトは、環境センシングとArduinoでのアナログ信号処理を理解するために重要であり、センサーの取り扱いやその出力の解釈に関する優れた入門書です。正確な測定のためにセンサーの予熱の重要性についても説明し、データの視覚化のためのシリアル通信の基本についても掘り下げます。このレッスンは、Arduinoや環境モニタリングプロジェクトに興味のある初心者に最適です。

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|


配線
---------------------------

.. image:: img/Lesson_04_mq2_sensor_circuit_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6af3295c-28dd-4319-8f26-587930ffd2ef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. 最初のコード行はガスセンサーピンの定数整数宣言です。アナログピンA0を使用してガスセンサーの出力を読み取ります。

   .. code-block:: arduino
   
      const int sensorPin = A0;

2. ``setup()``関数では、9600ボーのボーレートでシリアル通信を初期化します。これは、ガスセンサーからの読み取り値をシリアルモニターに表示するために必要です。

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

3. ``loop()``関数では、ガスセンサーからのアナログ値を連続的に読み取り、それをシリアルモニターに表示します。 ``analogRead()`` 関数を使用してセンサーからのアナログ値を読み取ります。その後、次の読み取りまで50ミリ秒待ちます。この遅延は、シリアルモニターがデータを処理するための余裕を与えます。

   .. note:: 
   
     MQ2は加熱駆動のセンサーであり、使用前に予熱が必要です。予熱期間中、センサーは通常高い値を読み取り、徐々に安定するまで減少します。

   .. code-block:: arduino
   
      void loop() {
        Serial.print("Analog output: ");
        Serial.println(analogRead(sensorPin));  // Read the analog value of the gas sensor and print it to the serial monitor
        delay(50);                             // Wait for 50 milliseconds
      }


