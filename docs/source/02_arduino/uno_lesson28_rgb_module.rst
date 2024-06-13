.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson28_rgb_module:

レッスン28: RGB LEDモジュール
==================================

このレッスンでは、Arduinoを使用してRGB LEDを制御する方法を学びます。LEDのセットアップから始め、基本色の表示や鮮やかな虹のスペクトルの作成に進みます。この実践的なプロジェクトは、Arduino環境での出力操作と色の混合についての実務経験を提供するため、初心者に最適です。

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
    *   - :ref:`cpn_rgb`
        - \-


配線
---------------------------

.. image:: img/Lesson_28_rgb_module_circuit_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/69d51b96-ad16-4c16-aa97-6dab559929d3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. コードの最初のセグメントでは、RGB LEDモジュールの各色チャネルに接続されているピンを宣言および初期化します。

   .. code-block:: arduino
       
      const int rledPin = 9;  // pin connected to the red color channel
      const int gledPin = 10;   // pin connected to the green color channel
      const int bledPin = 11;  // pin connected to the blue color channel

2. ``setup()`` 関数では、これらのピンをOUTPUTとして初期化します。これは、これらのピンからRGB LEDモジュールに信号を出力することを意味します。

   .. code-block:: arduino
   
      void setup() {
        pinMode(rledPin, OUTPUT);
        pinMode(gledPin, OUTPUT);
        pinMode(bledPin, OUTPUT);
      }

3. ``loop()`` 関数では、さまざまなパラメータを持つ ``setColor()`` 関数を呼び出して異なる色を表示します。各色を設定した後、次の色に移る前に1000ミリ秒（1秒）停止するために ``delay()`` 関数を使用します。

   .. code-block:: arduino
   
      void loop() {
        setColor(255, 0, 0);  // Set RGB LED color to red
        delay(1000);
        setColor(0, 255, 0);  // Set RGB LED color to green
        delay(1000);
        // The rest of the color sequence...
      }

4. ``setColor()`` 関数は ``analogWrite()`` 関数を使用して、RGB LEDモジュールの各色チャネルの明るさを調整します。 ``analogWrite()`` 関数は、パルス幅変調（PWM）を使用して変動する電圧出力をシミュレートします。PWMデューティサイクル（信号が一定期間内でHIGHである割合）を制御することで、各色チャネルの明るさを制御し、さまざまな色の混合が可能になります。

   .. code-block:: arduino

      void setColor(int R, int G, int B) {
        analogWrite(rledPin, R);  // Use PWM to control the brightness of the red color channel
        analogWrite(gledPin, G);  // Use PWM to control the brightness of the green color channel
        analogWrite(bledPin, B);  // Use PWM to control the brightness of the blue color channel
      }