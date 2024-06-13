.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson08_ir_obstacle_avoidance:

Lesson 08: 赤外線障害物回避センサーモジュール
====================================================

このレッスンでは、ESP32開発ボードを使用して赤外線障害物回避センサーの使い方を学びます。センサーが障害物を検出し、その出力信号をどのように変更するかを探ります。また、ESP32を使用してこれらの信号を読み取り、シリアルモニターに表示する方法も学びます。このプロジェクトは、センサーとデジタル入力処理に関する実践的な経験を積むための素晴らしい機会を提供し、インタラクティブなプロジェクトに興味がある初心者に最適です。

必要な部品
--------------------------

このプロジェクトには以下の部品が必要です。

全ての部品が揃ったキットを購入すると便利です。リンクはこちら：

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
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_08_Obstacle_Avoidance_Sensor_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e04a4a04-e707-46a1-aee5-488add646356/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. センサー接続用のピン番号を定義します：

   .. code-block:: arduino

     const int sensorPin = 25;

   センサーの出力ピンをピン25に接続します。

2. シリアル通信を設定し、センサーピンを入力として定義します：

   .. code-block:: arduino

     void setup() {
       pinMode(sensorPin, INPUT);  
       Serial.begin(9600);
     }

   シリアルモニターに出力するために、9600ボーのシリアル通信を初期化します。
   センサーピンを入力として設定し、入力信号を読み取ります。

3. センサーの値を読み取り、シリアルモニターに出力します：

   .. code-block:: arduino

     void loop() {
       Serial.println(digitalRead(sensorPin));
       delay(50); 
     }
   
   ``digitalRead()``を使用してセンサーピンからデジタル値を連続的に読み取り、 ``Serial.println()``を使用してその値をシリアルモニターに出力します。
   見やすくするために、出力間に50msの遅延を追加します。

   .. note:: 
   
      センサーが正しく動作しない場合は、赤外線送信機と受信機を平行に調整してください。さらに、内蔵のポテンショメーターを使用して検出範囲を調整できます。
