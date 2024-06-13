.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson30_relay_module:

Lesson 30: リレーモジュール
==================================

このレッスンでは、ESP32開発ボードを使用して1チャンネルリレーモジュールを制御する方法を学びます。リレーをオンとオフにするループを作成し、各状態変更の間に3秒の遅延を入れる方法をカバーします。このプロジェクトは、組み込みシステムでのデジタル出力操作に関する実践的な経験を提供し、ESP32とリレーモジュールの世界に入る初心者に最適です。

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-


配線
---------------------------

.. image:: img/Lesson_30_Relay_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a0035890-76ca-4a85-9f21-9df01717d906/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. リレーピンの設定:

   - リレーモジュールはESP32開発ボードのピン25に接続されています。このピンはコード内で参照しやすいように``relayPin``として定義されています。

   .. raw:: html

      <br/>

   .. code-block:: arduino
    
      const int relayPin = 25;

#. リレーピンを出力として設定:

   - ``setup()``関数内で、リレーピンは ``pinMode()`` 関数を使用してOUTPUTとして設定されます。これにより、ArduinoはこのピンにHIGHまたはLOWの信号を送信します。

   .. raw:: html

      <br/>

   .. code-block:: arduino

      void setup() {
        pinMode(relayPin, OUTPUT);
      }

#. リレーのオンとオフの切り替え:

   - ``loop()``関数内で、リレーは最初に ``digitalWrite(relayPin, LOW)``を使用してオフの状態に設定されます。この状態で3秒間（ ``delay(3000)`` ）保持されます。
   - 次に、リレーは ``digitalWrite(relayPin, HIGH)``を使用してオンの状態に設定されます。この状態も3秒間保持されます。
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