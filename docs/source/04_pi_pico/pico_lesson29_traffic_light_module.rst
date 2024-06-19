.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson29_traffic_light_module:

レッスン29: 交通信号モジュール
==================================

このレッスンでは、Raspberry Pi Pico Wを使用して交通信号システムを作成する方法を学びます。Pico Wをプログラムして、赤、黄、緑の3つのLEDを制御し、実際の交通信号を模倣します。このプロジェクトは、LEDの明るさ制御のためのパルス幅変調（PWM）の使用と、MicroPythonの基本的な制御構造の実践的な紹介を提供します。デジタル信号処理を探求し、Raspberry Pi Pico Wプラットフォームでのコーディングに自信をつけたい初心者に最適です。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

全体のキットを購入すると便利です。リンクはこちら:

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
    *   - :ref:`cpn_traffic`
        - |link_traffic_light_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_29_Traffic_Light_Module_pico_bb.png
    :width: 100%

コード
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   import time
   
   # Initialize pins for LEDs
   red = PWM(Pin(26), freq=1000)  #  red LED
   yellow = PWM(Pin(27), freq=1000)  #  yellow LED
   green = PWM(Pin(28), freq=1000)  # green LED
   
   
   # Function to set the brightness of an LED (0-100%)
   def set_brightness(led, brightness):
       if brightness < 0 or brightness > 100:
           raise ValueError("Brightness should be between 0 and 100")
       led.duty_u16(int(brightness / 100 * 65535))
   
   
   try:
       # Example sequence
       while True:
           
           # Green light for 5 seconds
           set_brightness(green, 100)
           time.sleep(5)
           set_brightness(green, 0)
   
           # Blink Yellow light
           set_brightness(yellow, 100)
           time.sleep(0.5)
           set_brightness(yellow, 0)
           time.sleep(0.5)
           set_brightness(yellow, 100)
           time.sleep(0.5)
           set_brightness(yellow, 0)
           time.sleep(0.5)
           set_brightness(yellow, 100)
           time.sleep(0.5)
           set_brightness(yellow, 0)
           time.sleep(0.5)
           
           # Red light for 5 seconds
           set_brightness(red, 100)
           time.sleep(5)
           set_brightness(red, 0)
           
   except KeyboardInterrupt:
       # Turn off RGB LED on interrupt
       set_brightness(red, 0)
       set_brightness(yellow, 0)
       set_brightness(green, 0)


コード解析
---------------------------

#. ライブラリのインポート

   ``machine``ライブラリはハードウェアコンポーネントを制御するために使用され、 ``time`` ライブラリは遅延を作成するために使用されます。

   .. code-block:: python

      from machine import Pin, PWM
      import time

#. LEDピンの初期化

   ここでは、LEDに接続されたピンを初期化します。PWMはLEDの明るさを制御するために使用されます。

   .. code-block:: python

      red = PWM(Pin(26), freq=1000)  #  red LED
      yellow = PWM(Pin(27), freq=1000)  #  yellow LED
      green = PWM(Pin(28), freq=1000)  # green LED

#. 明るさ設定関数の定義

   .. note::
      Raspberry Pi Picoのピンは最大電圧3.3Vしか出力できないため、緑色LEDは暗く見えます。

   この関数はLEDの明るさを設定します。2つのパラメータ、LEDと希望する明るさレベル（0-100%）を取ります。 ``duty_u16`` メソッドを使用してPWMデューティサイクルを設定します。

   .. code-block:: python

      def set_brightness(led, brightness):
          if brightness < 0 or brightness > 100:
              raise ValueError("Brightness should be between 0 and 100")
          led.duty_u16(int(brightness / 100 * 65535))

#. メインループと交通信号シーケンス

   ``while True``ループはコードを連続的に実行します。これは交通信号のシーケンス（緑、黄色（点滅）、赤）を制御します。

   .. code-block:: python

      try:
          while True:
              # Green light for 5 seconds
              set_brightness(green, 100)
              time.sleep(5)
              set_brightness(green, 0)
              ...

#. キーボード割り込みの処理

   ``except KeyboardInterrupt``ブロックは手動の割り込み（Ctrl+Cなど）を処理するために使用されます。スクリプトが中断されたときにすべてのLEDを消灯します。

   .. code-block:: python

      except KeyboardInterrupt:
          set_brightness(red, 0)
          set_brightness(yellow, 0)
          set_brightness(green, 0)