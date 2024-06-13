.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson29_traffic_light_module:

レッスン29: 交通信号モジュール
==================================

このレッスンでは、Arduinoを使用してミニLED交通信号を制御する方法を学びます。Arduino Unoをプログラムして、緑、黄色、赤のライトを順番に点灯させ、実際の交通信号をシミュレートします。このプロジェクトは、Arduinoプラットフォームでのライトシーケンスとタイミング制御の実務経験を提供するため、初心者に最適です。

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
    *   - :ref:`cpn_traffic`
        - |link_traffic_light_module_buy|
    * Arduino UNO R3 or R4
    * :ref:`cpn_traffic`
配線
---------------------------

.. image:: img/Lesson_29_traffic_light_circuit_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/48f3abf4-1a9c-405f-9247-7dbd61e64f75/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. 操作を行う前に、LEDが接続されているピンの定数を定義します。これにより、コードが読みやすく、変更が容易になります。

  .. code-block:: arduino

     const int rledPin = 9;  //red
     const int yledPin = 8;  //yellow
     const int gledPin = 7;  //green

2. 次に、LEDピンのピンモードを指定します。すべて ``OUTPUT`` に設定されており、これによりピンに電圧を送ることができます。

  .. code-block:: arduino

     void setup() {
       pinMode(rledPin, OUTPUT);
       pinMode(yledPin, OUTPUT);
       pinMode(gledPin, OUTPUT);
     }

3. ここでは、交通信号のサイクルロジックが実装されています。操作のシーケンスは次の通りです：

    * 緑色LEDを5秒間点灯させます。
    * 黄色LEDを3回点滅させます（各点滅は0.5秒間続きます）。
    * 赤色LEDを5秒間点灯させます。
    
  .. code-block:: arduino

     void loop() {
       digitalWrite(gledPin, HIGH);
       delay(5000);
       digitalWrite(gledPin, LOW);
       
       digitalWrite(yledPin, HIGH);
       delay(500);
       digitalWrite(yledPin, LOW);
       delay(500);
       digitalWrite(yledPin, HIGH);
       delay(500);
       digitalWrite(yledPin, LOW);
       delay(500);
       digitalWrite(yledPin, HIGH);
       delay(500);
       digitalWrite(yledPin, LOW);
       delay(500);
       
       digitalWrite(rledPin, HIGH);
       delay(5000);
       digitalWrite(rledPin, LOW);
     }

