.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pi_lesson28_rgb_module:

レッスン28: RGBモジュール
==================================

このレッスンでは、Raspberry Piを使ってRGB LEDモジュールを制御する方法を学びます。Pythonを使用してLEDの色を赤、緑、青、黄に変更し、最後にLEDを消灯する方法を学びます。このプロジェクトは、RGB LEDとGPIOインターフェースの基本を学ぶためのシンプルな入門編で、Raspberry PiとPythonプログラミングを始める初心者に最適です。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全てが揃ったキットを購入すると便利です。リンクはこちらです：

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_28_RGB_LED_Module_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import RGBLED  
   from time import sleep  
   from colorzero import Color  

   # GPIO pin assignments for the RGB LED
   red_pin = 22
   green_pin = 27
   blue_pin = 17

   # Initialize the RGB LED with red, green, and blue components connected to their respective GPIO pins
   led = RGBLED(red=red_pin, green=green_pin, blue=blue_pin)

   # Set the LED to red color (red: 100%, green: 0%, blue: 0%) and wait for 1 second
   led.color = (1, 0, 0)
   sleep(1)

   # Set the LED to green color (red: 0%, green: 100%, blue: 0%) and wait for 1 second
   led.color = (0, 1, 0)
   sleep(1)

   # Set the LED to blue color (red: 0%, green: 0%, blue: 100%) and wait for 1 second
   led.color = (0, 0, 1)
   sleep(1)

   # Set the LED to yellow color using the Color class and wait for 1 second
   led.color = Color('yellow')
   sleep(1)

   # Turn the LED off
   led.off()



コード解析
---------------------------

#. ライブラリのインポート
   
   スクリプトは、RGB LEDを制御するためにgpiozeroから ``RGBLED`` クラスを、遅延のためにtimeモジュールから ``sleep`` 関数を、カラー定義のためにcolorzeroから ``Color`` クラスをインポートすることから始まります。

   .. code-block:: python

      from gpiozero import RGBLED  
      from time import sleep  
      from colorzero import Color  

#. RGB LEDの初期化
   
   - RGB LEDの各色コンポーネントのGPIOピンが定義されます。
   - 赤、緑、青のコンポーネントがそれぞれGPIOピン22、27、17に接続されたRGB LEDを初期化します。

   .. code-block:: python

      red_pin = 22
      green_pin = 27
      blue_pin = 17
      led = RGBLED(red=red_pin, green=green_pin, blue=blue_pin)

#. LEDの色を設定
   
   - LEDの色を赤、緑、青の順に設定し、それぞれ1秒間のポーズを入れます。
   - 色はタプル（赤、緑、青）で表され、各値は0から1の間で強度を示します。

   .. code-block:: python

      led.color = (1, 0, 0)
      sleep(1)
      led.color = (0, 1, 0)
      sleep(1)
      led.color = (0, 0, 1)
      sleep(1)

#. Colorクラスの使用
   
   スクリプトは、colorzeroの ``Color`` クラスを使用してLEDを名前付きの色（ ``yellow`` ）に設定し、1秒待機する方法を示します。

   事前定義された色を直接使用するだけでなく、さまざまな方法で色を定義することもできます。詳細については、|link_gpiozero_color|を参照してください。

   .. code-block:: python

      led.color = Color('yellow')
      sleep(1)

#. LEDを消灯
   
   最後に、スクリプトは ``led.off()`` を使用してLEDを消灯します。

   .. code-block:: python

      led.off()
