.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson04_mq2:

レッスン 04: ガスセンサーモジュール (MQ-2)
============================================

このレッスンでは、ESP32開発ボードを使用してMQ-2センサーでガス濃度を測定する方法を学びます。ガスセンサーのアナログ出力を読み取り、シリアルモニターに表示する方法を説明します。このプロジェクトは、電子工学の初心者に最適で、センサーとマイクロコントローラーの実践的な経験を提供しながら、アナログ信号処理とシリアル通信について学ぶことができます。

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|



配線
---------------------------

.. image:: img/Lesson_04_MQ2_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/79ef2209-7e92-4a53-81f2-1ba01214af31/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. 最初のコード行は、ガスセンサーのピン用の定数整数の宣言です。ガスセンサーからの出力を読み取るためにピン25を使用します。

   .. code-block:: arduino
   
      const int sensorPin = 25;

2. ``setup()`` 関数では、シリアル通信を9600ボーの速度で初期化します。これは、ガスセンサーの読み取り値をシリアルモニターに表示するために必要です。

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);  // シリアル通信を9600ボーで開始
      }

3. ``loop()`` 関数では、ガスセンサーからアナログ値を連続的に読み取り、シリアルモニターに表示します。 ``analogRead()`` 関数を使用してセンサーからアナログ値を読み取ります。その後、次の読み取りまで50ミリ秒待機します。この遅延により、シリアルモニターがデータを処理するための余裕が得られます。

   .. note:: 
   
     MQ2は加熱駆動型センサーで、使用前に予熱が必要です。予熱期間中、センサーは通常高い値を示し、徐々に安定するまで低下します。

   .. code-block:: arduino
   
      void loop() {
        Serial.print("Analog output: ");
        Serial.println(analogRead(sensorPin));  // Read the analog value of the gas sensor and print it to the serial monitor
        delay(50);                             // Wait for 50 milliseconds
      }


