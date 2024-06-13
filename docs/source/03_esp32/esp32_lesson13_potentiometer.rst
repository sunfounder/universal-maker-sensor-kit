.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson13_potentiometer:

Lesson 13: ポテンショメーターモジュール
==================================

このレッスンでは、ESP32開発ボードを使用してポテンショメーターのアナログ値を読み取る方法を学びます。ポテンショメーターモジュールを25番ピンに接続し、シリアルモニタで変化するアナログ値（0〜4095）を観察します。このプロジェクトは、アナログ入力とシリアル通信の理解を深めるための実践的な経験を提供し、初心者がESP32ボードの機能を探るのに最適な演習です。

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

    *   - ESP32 & 開発ボード
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_13_Potentiometer_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/80644221-74b4-4df5-804e-236fdc4ab30e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. このコード行は、ESP32開発ボードに接続されているポテンショメータのピン番号を定義します。

   .. code-block:: arduino

      const int sensorPin = 25;

#. ``setup()``関数は、ESP32開発ボードが電源投入またはリセットされたときに一度だけ実行される特別な関数です。このプロジェクトでは、 ``Serial.begin(9600)``コマンドが9600ボーの速度でシリアル通信を開始します。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  
      }

#. ``loop()``関数は、プログラムが繰り返し実行されるメイン関数です。この関数では、 ``analogRead()``関数を使用してポテンショメータからアナログ値を読み取り、 ``Serial.println()``を使用してシリアルモニタに出力します。 ``delay(50)``コマンドは、次の読み取りを行う前にプログラムを50ミリ秒待機させます。

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));  
        delay(50);
      }

