.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson22_touch_sensor:

Lesson 22: タッチセンサーモジュール
=====================================

このレッスンでは、ESP32開発ボードを使用してタッチセンサーを使う方法を学びます。センサーに触れることでESP32に信号が送られ、シリアル通信を通じて応答が表示される仕組みを確認します。このプロジェクトは初心者に最適で、ESP32プラットフォームでのデジタル入力とシリアル出力の実践的な経験を提供します。センサーがマイクロコントローラーとどのように相互作用するかを理解することは、インタラクティブなハードウェアプロジェクトを構築するための基本となります。

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
    *   - :ref:`cpn_touch`
        - |link_touch_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_22_Touch_Sensor_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f3fd3d61-1d6b-46b8-8e62-e3c91e262830/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **ピンの設定とシリアル通信の初期化**

   - タッチセンサーはESP32のピン25に接続され、このピンは入力として設定されます。
   - ``Serial.begin(9600);`` はシリアル通信を毎秒9600ビットのボーレートで初期化します。
   
   .. raw:: html
      
      <br/>

   .. code-block:: arduino

      const int sensorPin = 25;

      void setup() {
        pinMode(sensorPin, INPUT);     // Set the sensor pin as input
        Serial.begin(9600);            // Start the serial communication
      }

#. **センサーの読み取りとシリアルモニタへのデータ送信**

   - ``loop()`` 関数はタッチセンサーの状態を継続的にチェックします。
   - ``digitalRead(sensorPin)`` はセンサーピンからデジタル値（1または0）を読み取ります。
   - センサーに触れた場合（値が1）、シリアルモニタに "Touch detected!" と表示します。
   - 触れていない場合（値が0）、シリアルモニタに "No touch detected..." と表示します。
   - ``delay(100);`` はセンサーのデバウンスを助け、急速な読み取りを防ぎます。

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == 1) {  // If the sensor is touched
          Serial.println("Touch detected!");
        } else {
          Serial.println("No touch detected...");
        }
        delay(100);  // Wait for a short period to avoid rapid reading of the sensor
      }