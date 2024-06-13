.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _uno_lesson30_relay_module:

レッスン30: リレーモジュール
==================================

このレッスンでは、リレーとArduino Unoを使用して交通信号モジュールを制御する方法を学びます。リレーを使って交通信号モジュールの赤色ライトをオン・オフする方法を紹介します。このプロジェクトは、Arduino初心者に最適で、外部モジュールの制御とリレー操作の基本的な理解を得るための実践的な経験を提供します。

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_traffic`
        - |link_traffic_light_module_buy|

配線
---------------------------

.. image:: img/Lesson_30_relay_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/304bb1cc-7b9e-4290-b63a-baec5ed90521/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. リレーピンの設定:

   - リレーモジュールはArduinoのピン6に接続されます。このピンはコード内で ``relayPin`` として定義されています。

   .. raw:: html

      <br/>

   .. code-block:: arduino
    
      const int relayPin = 6;

#. リレーピンを出力として設定:

   - ``setup()``関数内で、リレーピンは ``pinMode()`` 関数を使用してOUTPUTとして設定されます。これにより、ArduinoはこのピンにHIGHまたはLOWの信号を送ることができます。

   .. raw:: html

      <br/>

   .. code-block:: arduino

      void setup() {
        pinMode(relayPin, OUTPUT);
      }

#. リレーのオン・オフ切り替え:

   - ``loop()``関数内で、リレーは最初に ``digitalWrite(relayPin, LOW)`` を使用してオフの状態に設定されます。この状態で3秒間（ ``delay(3000)`` ）維持されます。
   - 次に、リレーは ``digitalWrite(relayPin, HIGH)`` を使用してオンの状態に設定されます。この状態も3秒間維持されます。
   - このサイクルは無限に繰り返されます。

   .. raw:: html

      <br/>

   .. code-block:: arduino

      void loop() {
        digitalWrite(relayPin, LOW);
        delay(3000);

        digitalWrite(relayPin, HIGH);
        delay(3000);
      }