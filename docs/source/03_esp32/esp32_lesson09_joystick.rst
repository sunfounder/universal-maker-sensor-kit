.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson09_joystick:

Lesson 09: ジョイスティックモジュール
======================================

このレッスンでは、ESP32開発ボードを使用してジョイスティックモジュールから値を読み取る方法を学びます。ジョイスティックのX軸およびY軸の動きとスイッチの位置を測定し、それらを解釈する方法をカバーします。これらの入力をESP32に統合することで、アナログおよびデジタル信号の処理に関する洞察を得ることができます。このプロジェクトは初心者に最適で、インタラクティブなハードウェアコンポーネントからデータを読み取り、処理する実践的な経験を提供します。

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_09_Jostick_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6a9f54fb-a117-48f2-bca0-fd43bdd45b51/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. ピン定義:
   
   .. code-block:: arduino
   
      const int xPin = 27;  //the VRX attach to
      const int yPin = 26;  //the VRY attach to
      const int swPin = 25;  //the SW attach to

   ジョイスティックのピン用の定数が定義されています。 ``xPin`` および ``yPin`` はジョイスティックのX軸およびY軸のためのアナログピンです。 ``swPin`` はジョイスティックのスイッチ用のデジタルピンです。

#. セットアップ関数:

   .. code-block:: arduino
   
      void setup() {
        pinMode(swPin, INPUT_PULLUP);
        Serial.begin(9600);
      }

   ``swPin``をプルアップ抵抗を使用した入力として初期化し、スイッチの機能に不可欠です。9600ボーのシリアル通信を開始します。

#. メインループ:

   .. code-block:: arduino
   
      void loop() {
        Serial.print("X: ");
        Serial.print(analogRead(xPin));  // print the value of VRX
        Serial.print("|Y: ");
        Serial.print(analogRead(yPin));  // print the value of VRY
        Serial.print("|Z: ");
        Serial.println(digitalRead(swPin));  // print the value of SW
        delay(50);
      }

   ジョイスティックの軸およびスイッチから値を連続的に読み取り、50msの遅延を挟んでシリアルモニタに出力します。
