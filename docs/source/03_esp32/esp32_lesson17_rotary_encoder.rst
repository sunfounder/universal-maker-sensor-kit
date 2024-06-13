.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_lesson17_rotary_encoder:

Lesson 17: ロータリーエンコーダーモジュール
===========================================

このレッスンでは、ESP32開発ボードとロータリーエンコーダーモジュールを使用して、回転方向とカウント、およびボタンの押下を検出する方法を学びます。エンコーダーが時計回りと反時計回りの回転をどのように信号化し、それに応じてカウンターを増減するかを探ります。さらに、エンコーダーモジュールのボタン押下を検出する方法も理解します。このプロジェクトは、ロータリーエンコーダーの管理とデジタル入力の読み取りに関する実践的な経験を提供し、ESP32およびArduinoプログラミングでのスキルを向上させます。

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
    *   - :ref:`cpn_rotary_encoder`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
 

配線
---------------------------

.. image:: img/Lesson_17_Rotary_Encoder_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0ba81725-2139-4c8c-9575-c4d343be6708/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **セットアップと初期化**

   .. code-block:: arduino

      void setup() {
        pinMode(CLK, INPUT);
        pinMode(DT, INPUT);
        pinMode(SW, INPUT_PULLUP);
        Serial.begin(9600);
        lastStateCLK = digitalRead(CLK);
      }

   setup関数では、エンコーダーのCLKとDTに接続されているデジタルピンを入力として設定します。ボタンに接続されているSWピンは内部プルアップ抵抗を使用して入力として設定されます。これにより、外部プルアップ抵抗は不要となります。シリアル通信は9600ボーで開始され、シリアルモニタでのデータ視覚化が可能になります。CLKピンの初期状態が読み取られ、保存されます。

#. **メインループ：エンコーダーとボタンの状態読み取り**

   .. code-block:: arduino

      void loop() {
        currentStateCLK = digitalRead(CLK);
        if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {
          if (digitalRead(DT) != currentStateCLK) {
            counter--;
            currentDir = "CCW";
          } else {
            counter++;
            currentDir = "CW";
          }
          Serial.print("Direction: ");
          Serial.print(currentDir);
          Serial.print(" | Counter: ");
          Serial.println(counter);
        }
        lastStateCLK = currentStateCLK;
        int btnState = digitalRead(SW);
        if (btnState == LOW) {
          if (millis() - lastButtonPress > 50) {
            Serial.println("Button pressed!");
          }
          lastButtonPress = millis();
        }
        delay(1);
      }

   ループ関数では、プログラムがCLKピンの現在の状態を継続的に読み取ります。状態に変化があった場合、それは回転が発生したことを意味します。回転の方向は、CLKピンとDTピンの状態を比較することで決定されます。異なる場合は反時計回り（CCW）の回転を示し、同じ場合は時計回り（CW）を示します。エンコーダーのカウントはそれに応じて増減されます。この情報はシリアルモニタに送信されます。

   ボタンの状態はSWピンから読み取られます。LOW（押されている）場合、最後にボタンが押されてからの経過時間をチェックすることでデバウンス機構が実装されます。50ミリ秒以上経過している場合、有効な押下と見なし、メッセージがシリアルモニタに送
