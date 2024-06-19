.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson06_hall_sensor:

レッスン06: ホールセンサーモジュール
==================================

このレッスンでは、ホールセンサーを使用して、ESP32開発ボードで磁場の極性を検出する方法を学びます。センサーからのアナログ信号を読み取り、それを解釈して南極と北極を区別する方法を説明します。このプロジェクトは、センサーとESP32プラットフォームでの信号処理に関する実践的な経験を提供する、電子工学の初心者に最適です。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

部品一式を購入するのが便利です。こちらのリンクをご利用ください。

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
    *   - :ref:`cpn_hall`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_06_Hall_Sensor_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/48094da0-b2f8-4af6-ad59-38504a201cbf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. ホールセンサーの設定

   .. code-block:: arduino

      const int hallSensorPin = 25;  // Pin connected to the Hall sensor output
      void setup() {
        Serial.begin(9600);             // Initialize serial communication at 9600 bps
        pinMode(hallSensorPin, INPUT);  // Set hall sensor pin as input
      }

   ホールセンサーの出力はESP32開発ボードのピン25に接続されています。 ``setup()``関数では、データをシリアルモニターに表示するためにシリアル通信を9600bpsで初期化します。 ``pinMode()``関数は、25を入力ピンとして設定します。

2. ホールセンサーからの読み取りと極性の判定

   ホールセンサーモジュールには49Eリニアホール効果センサーが搭載されており、磁場の南極と北極の極性および磁場の相対強度を測定できます。磁石の南極を49Eと刻印された側（テキストが刻まれている側）に近づけると、コードで読み取られる値は加えられた磁場強度に比例して線形に増加します。逆に、北極を近づけると、その磁場強度に比例して値が線形に減少します。詳細については :ref:`cpn_hall` を参照してください。

   .. code-block:: arduino

      void loop() {
        int sensorValue = analogRead(hallSensorPin);  // Read analog value from Hall sensor
        Serial.print(sensorValue);                    // Output raw sensor value to Serial Monitor
        delay(200);                                   // Delay for 200 milliseconds

        // Determine magnetic pole based on sensor value
        if (sensorValue >= 2600) {
          Serial.print(" - South pole detected");  // South pole detected if value >= 2600
        } else if (sensorValue <= 1200) {
          Serial.print(" - North pole detected");  // North pole detected if value <= 1200
        }

        Serial.println();  // New line for next output
      }

