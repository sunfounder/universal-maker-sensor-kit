.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson02_soil_moisture:

レッスン02: 容量性土壌湿度モジュール
============================================

このレッスンでは、容量性土壌湿度センサーをArduinoに接続し、その読み取り値を解釈する方法を学びます。このプロジェクトでは、センサーのアナログ出力をArduinoで読み取り、低い読み取り値が高い土壌湿度を示すことを理解します。提供されたコードを使用して、Arduinoでアナログ入力とシリアル通信を実践的に学ぶことができます。

必要なコンポーネント
---------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全体のキットを購入するのが便利です。リンクはこちらです:

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

このプロジェクトでは、以下のコンポーネントが必要です。

全体のキットを購入するのが便利です。リンクはこちらです:

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

このプロジェクトでは、以下のコンポーネントが必要です。

全体のキットを購入するのが便利です。リンクはこちらです:

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
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|


配線
---------------------------

.. image:: img/Lesson_02_Capacitive_Soil_Moisture_Module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa2c3492-576b-4039-bbfe-891ed87e72c9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. センサーピンの定義:

   このコード行は定数整数 ``sensorPin`` を宣言し、センサーが接続されているアナログ入力ピン``A0``の値を割り当てます。

   .. code-block:: arduino

      const int sensorPin = A0;

#. セットアップ関数:

   ``setup()`` 関数はプログラムが開始されると一度実行されます。シリアル通信を9600ボーレートで初期化します。このセットアップは、データをシリアルモニターに送信するために必要です。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
      }

#. ループ関数:

   ``loop()`` 関数は ``setup()`` の後に連続して実行されます。 ``analogRead()`` を使用してピンA0からセンサー値を読み取り、この値をシリアルモニターに表示します。 ``delay(500)`` 文はループを500ミリ秒一時停止し、次の読み取りまでのデータ取得速度を制御します。

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(A0));
        delay(500);
      }

