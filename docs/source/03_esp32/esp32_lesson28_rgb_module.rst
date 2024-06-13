.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson28_rgb_module:

Lesson 28: RGB LEDモジュール
==================================

このレッスンでは、ESP32開発ボードを使用してRGB LEDを制御する方法を学びます。異なる色チャンネルを使用して基本色を表示し、虹色のシーケンスを作成する方法をカバーします。このプロジェクトは、エレクトロニクスやプログラミングの初心者に最適で、ESP32とRGB LEDモジュールを使用した出力操作と色の混合に関する実践的な経験を提供します。

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
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a8796969-0aed-4037-8080-f62059cc2db5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. 最初のコードセグメントでは、RGB LEDモジュールの各色チャンネルに接続されているピンを宣言および初期化します。

   .. code-block:: arduino
       
      const int rledPin = 25;  // pin connected to the red color channel
      const int gledPin = 26;   // pin connected to the green color channel
      const int bledPin = 27;  // pin connected to the blue color channel

2. ``setup()`` 関数では、これらのピンをOUTPUTとして初期化します。つまり、これらのピンからRGB LEDモジュールに信号を出力します。

   .. code-block:: arduino
   
      void setup() {
        pinMode(rledPin, OUTPUT);
        pinMode(gledPin, OUTPUT);
        pinMode(bledPin, OUTPUT);
      }

3. ``loop()`` 関数では、 ``setColor()`` 関数が異なるパラメータで呼び出され、異なる色を表示します。各色を設定した後、``delay()`` 関数を使用して次の色に進む前に1000ミリ秒（1秒）待機します。

   .. code-block:: arduino
   
      void loop() {
        setColor(255, 0, 0);  // Set RGB LED color to red
        delay(1000);
        setColor(0, 255, 0);  // Set RGB LED color to green
        delay(1000);
        // The rest of the color sequence...
      }

4. ``setColor()`` 関数では、 ``analogWrite()`` 関数を使用してRGB LEDモジュールの各色チャンネルの明るさを調整します。 ``analogWrite()`` 関数はパルス幅変調（PWM）を使用して異なる電圧出力をシミュレートします。PWMデューティサイクル（固定期間内で信号がHIGHである割合）を制御することで、各色チャンネルの明るさを調整し、さまざまな色の混合が可能になります。

   .. code-block:: arduino

      void setColor(int R, int G, int B) {
        analogWrite(rledPin, R);  // Use PWM to control the brightness of the red color channel
        analogWrite(gledPin, G);  // Use PWM to control the brightness of the green color channel
        analogWrite(bledPin, B);  // Use PWM to control the brightness of the blue color channel
      }