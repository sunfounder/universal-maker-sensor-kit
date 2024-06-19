.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson08_ir_obstacle_avoidance:

レッスン08: 赤外線障害物回避センサーモジュール
====================================================

このレッスンでは、Arduino Unoを使用して赤外線障害物回避センサーを利用する方法を学びます。センサーからのデジタル信号を読み取って障害物を検出する方法を探ります。障害物が存在するとセンサーの赤色インジケーターライトが点灯し、Arduinoに低レベル信号を送信する様子を確認します。このレッスンはデジタル入力の読み取りとシリアル通信の練習に最適な初心者向けの実践的な内容です。

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
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|



配線
---------------------------

.. image:: img/Lesson_08_IR_obstacle_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/be83e63b-959c-4d9c-a27b-0be46291c1f8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. センサー接続用のピン番号を定義します:

   .. code-block:: arduino

     const int sensorPin = 2;

   センサーの出力ピンをArduinoのピン2に接続します。

2. シリアル通信を設定し、センサーピンを入力として定義します:

   .. code-block:: arduino

     void setup() {
       pinMode(sensorPin, INPUT);  
       Serial.begin(9600);
     }

   シリアル通信を9600ボーで初期化し、シリアルモニタに出力します。
   センサーピンを入力として設定し、入力信号を読み取ります。

3. センサー値を読み取り、シリアルモニターに出力します:

   .. code-block:: arduino

     void loop() {
       Serial.println(digitalRead(sensorPin));
       delay(50); 
     }
   
   ``digitalRead()``を使用してセンサーピンからデジタル値を継続的に読み取り、その値を ``Serial.println()``でシリアルモニタに出力します。
   表示を見やすくするために、出力間に50msの遅延を追加します。

   .. note:: 
   
      センサーが正常に動作しない場合は、IR送信機と受信機を平行に調整してください。また、内蔵のポテンショメーターを使用して検出範囲を調整することもできます。

