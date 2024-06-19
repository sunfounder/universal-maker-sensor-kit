.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

... _esp32_lesson07_speed:

レッスン07: 赤外線速度センサーモジュール
==========================================

このレッスンでは、ESP32開発ボードと速度センサーモジュールを使用して障害物を検出する方法を学びます。センサーが障害物を検出すると高信号を送り、道がクリアになると低信号を送る仕組みを見ていきます。このプロジェクトは、ESP32プラットフォームを使用して、センサーの統合と基本的な入出力操作を実践的に理解するための理想的なものです。

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|


配線
---------------------------

.. image:: img/Lesson_07_Speed_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/bdf494c6-c0b1-4dbd-89bc-ce671db41bbb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. センサーピンの定義

   センサーピンは定数整数として宣言され、ESP32のピン番号25に設定されます。

   .. code-block:: arduino

      const int sensorPin = 25;

#. セットアップ関数

   この関数はシリアル通信を9600ボーレートで初期化し、sensorPinを入力として設定します。

   .. code-block:: arduino
    
      void setup() {
        Serial.begin(9600);
        pinMode(sensorPin, INPUT);
      }

#. ループ関数

   ループ関数はセンサーピンの状態を継続的にチェックします。
   センサーピンがHIGHを読み取ると、シリアルモニタに「障害物検出」と表示します。
   センサーピンがLOWの場合、「障害物なし」と表示します。

   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == HIGH) {
          Serial.println("Obstruction detected");
        } else {
          Serial.println("Unobstructed");
        }
      }

#. さらに

   モーターにエンコーダーが取り付けられている場合、特定の期間内にセンサーを通過する障害物の回数を数えることで、モーターの回転速度を計算することができます。

   .. image:: img/Lesson_07_Encoder_Disk.png
      :align: center
      :width: 20%