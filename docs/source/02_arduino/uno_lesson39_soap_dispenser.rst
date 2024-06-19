.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson39_soap_dispenser:

レッスン39: 自動石鹸ディスペンサー
=====================================

このプロジェクトでは、Arduino Unoボードを使用して、赤外線障害物回避センサーと水ポンプを組み合わせた自動石鹸ディスペンサーを作成します。センサーが手などの物体を検出すると、水ポンプが作動して石鹸を分配します。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式キットを購入するのが便利です。こちらのリンクをご覧ください:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_power_module`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_39_Automatic_soap_dispenser_uno_bb.png
    :width: 100%

コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/47ef3a59-afe1-40a8-9b36-1ff5db59af15/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

このプロジェクトの主なアイデアは、手を使わずに石鹸を分配するシステムを作成することです。赤外線障害物回避センサーは、物体（手など）が近くにあると検出します。物体を検出すると、センサーはArduinoに信号を送り、Arduinoは水ポンプを作動させて石鹸を分配します。ポンプは短時間作動し、その後停止します。

#. **センサーとポンプのピンの定義**

   このコードスニペットでは、センサーとポンプに接続するArduinoのピンを定義します。ピン7をセンサーピンとして定義し、このセンサーから読み取ったデータを格納するために ``sensorValue`` 変数を使用します。水ポンプにはピン9と10を使用します。
   
   .. code-block:: arduino
   
      const int sensorPin = 7;
      int sensorValue;
      const int pump1A = 9;
      const int pump1B = 10;

#. **センサーとポンプの設定**

   ``setup()``関数では、使用するピンのモードを定義します。センサーピンは ``INPUT`` として設定し、センサーからデータを受信します。ポンプピンは``OUTPUT``として設定し、ポンプにコマンドを送信します。 ``pump1B`` ピンは ``LOW`` 状態（オフ）で開始し、シリアル通信はボーレート9600で開始します。

   .. code-block:: arduino
   
      void setup() {
        pinMode(sensorPin, INPUT);
        pinMode(pump1A, OUTPUT);    
        pinMode(pump1B, OUTPUT);    
        digitalWrite(pump1B, LOW);  
        Serial.begin(9600);
      }

#. **センサーの連続監視とポンプの制御**

   ``loop()``関数では、Arduinoがセンサーの値を ``digitalRead()`` を使用して継続的に読み取り、その値を ``sensorValue()`` に割り当てます。この値はデバッグのためにシリアルモニタに表示されます。センサーが物体を検出すると、 ``sensorValue()`` は0になります。この場合、 ``pump1A`` が ``HIGH`` に設定され、ポンプが作動します。700ミリ秒の遅延によりポンプが石鹸を分配し、その後 ``pump1A`` を ``LOW`` に設定してポンプを停止します。1秒の遅延により、ユーザーが手を移動させる時間が確保され、サイクルが繰り返されます。

   .. note:: 
   
      センサーが正常に動作しない場合、IR送信機と受信機を平行に調整してください。また、内蔵ポテンショメータを使用して検出範囲を調整できます。

   .. code-block:: arduino
   
      void loop() {
        sensorValue = digitalRead(sensorPin);
        Serial.println(sensorValue);
        if (sensorValue == 0) {  
          digitalWrite(pump1A, HIGH);
          delay(700);
          digitalWrite(pump1A, LOW);
          delay(1000);
        }
      }
