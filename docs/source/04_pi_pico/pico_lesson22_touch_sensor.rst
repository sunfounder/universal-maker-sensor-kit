.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson22_touch_sensor:

レッスン22: タッチセンサーモジュール
======================================

このレッスンでは、タッチセンサーをRaspberry Pi Pico Wに接続してオンボードLEDを制御する方法を学びます。シンプルなPythonコードを使用して、タッチセンサーを入力デバイスとして設定します。センサーがタッチを検出すると、LEDを点灯させてタッチが検出されたことを視覚的に示します。逆に、タッチがない場合はLEDが消灯します。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

全てが揃ったキットを購入すると便利です。リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_touch`
        - |link_touch_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_22_touch_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 16 as an input pin to read the touch sensor state
   touch_sensor = Pin(16, Pin.IN)
   
   # Initialize the onboard LED of the Raspberry Pi Pico W
   led = Pin("LED", Pin.OUT)
   
   while True:
       if touch_sensor.value() == 1:
           led.value(1)  # Turn on the LED
           print("Touch detected!")
       else:
           led.value(0)  # Turn off the LED
           print("No touch detected")
   
       time.sleep(0.1)  # Short delay to reduce CPU usage


コード解析
---------------------------

#. **ピンの設定**:

   ここでは、必要なライブラリをインポートし、GPIOピンを設定します。タッチセンサーはGPIO 16に入力として接続され、オンボードLEDは出力として設定されます。

   .. code-block:: python

      from machine import Pin
      import time

      touch_sensor = Pin(16, Pin.IN)
      led = Pin("LED", Pin.OUT)

#. **メインループとタッチ検出**:

   無限ループ内で、コードはタッチセンサーの状態を常にチェックします。タッチが検出されると（値が1の場合）、LEDが点灯し、メッセージが表示されます。それ以外の場合はLEDが消灯し、別のメッセージが表示されます。CPU使用率を減らすために短い遅延が追加されています。

   .. code-block:: python

      while True:
          if touch_sensor.value() == 1:
              led.value(1)  # Turn on the LED
              print("Touch detected!")
          else:
              led.value(0)  # Turn off the LED
              print("No touch detected")

          time.sleep(0.1)  # Short delay to reduce CPU usage