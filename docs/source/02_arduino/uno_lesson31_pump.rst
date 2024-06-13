.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson31_pump:

レッスン31: 遠心ポンプ
==================================

このレッスンでは、Arduino Uno R3またはR4とL9110モーター制御ボードを使用して遠心ポンプを制御する方法を学びます。ポンプを一方向に起動し、特定の期間動作させ、停止させるためのセットアップとプログラミング方法を説明します。この実践的な経験は初心者に最適で、モーター操作の管理とArduinoプロジェクトにおける出力制御の基本的な理解を提供します。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
* Arduino UNO R3 or R4
* :ref:`cpn_pump`
* :ref:`cpn_l9110`

配線
---------------------------

.. image:: img/Lesson_31_pump_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f5fad7fa-4b2c-4630-a832-d3a5e077d9fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. モーター制御用に2つのピン（ ``motorB_1A`` と ``motorB_2A`` ）が定義されています。これらのピンは、L9110モーター制御ボードに接続され、モーターの方向と速度を制御します。
  
   .. code-block:: arduino
   
      const int motorB_1A = 9;
      const int motorB_2A = 10;

2. ピンの設定とモーターの制御:

   - ``setup()``関数では、これらのピンを``OUTPUT``として初期化します。これは、これらのピンがモーター制御ボードに信号を送信できることを意味します。

   - ``analogWrite()``関数を使用してモーターの速度を設定します。ここでは、一方のピンを``HIGH``にし、もう一方を``LOW``にすることで、ポンプを一方向に回転させます。5秒間の遅延の後、両方のピンを0に設定してモーターを停止させます。

   .. raw:: html

      <br/>
   
   .. code-block:: arduino
   
      void setup() {
         pinMode(motorB_1A, OUTPUT);  // set pump pin 1 as output
         pinMode(motorB_2A, OUTPUT);  // set pump pin 2 as output
         analogWrite(motorB_1A, HIGH); 
         analogWrite(motorB_2A, LOW);
         delay(5000);// wait for 5 seconds
         analogWrite(motorB_1A, 0);  // turn off the pump
         analogWrite(motorB_2A, 0);
      }
