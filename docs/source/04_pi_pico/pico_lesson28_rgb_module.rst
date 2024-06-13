.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson28_rgb_module:

レッスン28: RGB LEDモジュール
==================================

このレッスンでは、Raspberry Pi Pico Wを使用してRGB LEDを制御する方法を学びます。各色チャンネルのGPIOピンにPWM（パルス幅変調）を設定し、赤、緑、青の成分の強度を調整することで、さまざまな色を作成する方法を発見します。このプロジェクトは、初心者にPWMと色の混合についての実践的な経験を提供し、Raspberry Pi Pico WとMicroPythonを使用して楽しくインタラクティブにエレクトロニクスとプログラミングの基礎を探求する良い機会です。さらに、割り込みを処理して安全にLEDをオフにする方法も学びます。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

全セットを購入するのが便利です。リンクはこちら：

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

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_28_RGB_LED_Module_pico_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   from time import sleep
   
   # Initialize PWM for each color channel of an RGB LED
   red = PWM(Pin(26))  # Red channel on GPIO pin 26
   green = PWM(Pin(27))  # Green channel on GPIO pin 27
   blue = PWM(Pin(28))  # Blue channel on GPIO pin 28
   
   # Set 1000 Hz frequency for all channels
   red.freq(1000)
   green.freq(1000)
   blue.freq(1000)
   
   
   # Function to set RGB LED color
   def set_color(r, g, b):
       red.duty_u16(r)  # Red intensity
       green.duty_u16(g)  # Green intensity
       blue.duty_u16(b)  # Blue intensity
   
   
   try:
       while True:
           set_color(65535, 0, 0)  # Red
           sleep(1)
           set_color(0, 65535, 0)  # Green
           sleep(1)
           set_color(0, 0, 65535)  # Blue
           sleep(1)
   except KeyboardInterrupt:
       set_color(0, 0, 0)  # Turn off RGB LED on interrupt


コード分析
---------------------------

#. ライブラリのインポート

   ``machine`` モジュールは PWM クラスと Pin クラスを使用するためにインポートされます。 ``time`` モジュールは、遅延を作成するために ``sleep`` 関数を使用するためにインポートされます。

   .. code-block:: python

      from machine import Pin, PWM
      from time import sleep

#. RGB LED の PWM 初期化

   RGB LED には 3 つのチャンネル（赤、緑、青）があり、それぞれが個別の PWM 信号で制御されます。PWM 信号は GPIO ピン 26、27、および 28 に接続されています。

   .. code-block:: python

      red = PWM(Pin(26))  # Red channel on GPIO pin 26
      green = PWM(Pin(27))  # Green channel on GPIO pin 27
      blue = PWM(Pin(28))  # Blue channel on GPIO pin 28

#. PWM 信号の周波数設定

   PWM 信号の周波数は、3 つのチャンネルすべてで 1000 Hz に設定されています。

   .. code-block:: python

      red.freq(1000)
      green.freq(1000)
      blue.freq(1000)

#. set_color 関数の定義

   この関数は、RGB LED の色を設定します。 ``duty_u16`` メソッドは、各色チャンネルのデューティサイクルを設定し、その色の強度を決定します。

   .. code-block:: python

      def set_color(r, g, b):
          red.duty_u16(r)
          green.duty_u16(g)
          blue.duty_u16(b)

#. メインプログラムループ

   無限ループを使用して LED の色を変更します。 ``set_color`` 関数を異なる値で呼び出して赤、緑、青の色を表示します。各色は 1 秒間表示されます。

   .. code-block:: python

      try:
          while True:
              set_color(65535, 0, 0)  # Red
              sleep(1)
              set_color(0, 65535, 0)  # Green
              sleep(1)
              set_color(0, 0, 65535)  # Blue
              sleep(1)
      except KeyboardInterrupt:
          set_color(0, 0, 0)  # Turn off RGB LED on interrupt