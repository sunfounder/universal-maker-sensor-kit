.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson01_button:

レッスン01: ボタンモジュール
==================================

このレッスンでは、Raspberry Pi Pico Wを使用してボタンを介してオンボードLEDを操作する方法を学びます。ボタンを押すとLEDが点灯し、ボタンを離すとLEDが消灯します。このプロジェクトは、MicroPythonを使用してRaspberry Pi Pico Wの入出力操作を体験する初心者に最適です。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

全キットを購入するのが便利です。以下のリンクをご参照ください。

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
    *   - :ref:`cpn_button`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_01_Button_Module_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 2 as an input pin to read the button state
   button = Pin(2, Pin.IN)
   
   # Initialize the onboard LED of the Raspberry Pi Pico W
   led = Pin('LED', Pin.OUT)
   
   while True:
       if button.value() == 0:  # Check if the button is pressed
           led.value(1)  # Turn on the LED
       else:
           led.value(0)  # Turn off the LED
   
       time.sleep(0.1)  # Short delay to reduce CPU usage
       
コード解析
---------------------------

#. モジュールのインポート

   ``machine`` モジュールはGPIOピンと対話するためにインポートされ、 ``time`` モジュールはタイミングを処理するために使用されます。

   .. code-block:: python

      from machine import Pin
      import time

#. ボタンの設定

   GPIO 2は入力ピンとして設定されます。これに接続された押しボタンの状態を読み取ります。

   .. code-block:: python

      button = Pin(2, Pin.IN)

#. LEDの設定

   オンボードLEDは出力ピンとして設定され、プログラムで点灯や消灯を制御できるようにします。

   .. code-block:: python

      led = Pin('LED', Pin.OUT)

#. メインループ

   - 無限ループを使用してボタンの状態を継続的にチェックします。
   - ボタンが押されている場合（ ``button.value() == 0`` ）、LEDを点灯させます。それ以外の場合は消灯します。
   - CPU使用率を減らすために0.1秒の短い遅延が追加されます。

   このプロジェクトで使用されている :ref:`ボタンモジュール<cpn_button>` には内部プルアップ抵抗が内蔵されており（その :ref:`回路図<cpn_button_sch>` を参照）、ボタンが押されると低レベルになり、離されると高レベルのままになります。

   .. code-block:: python

      while True:
          if button.value() == 0:  # Check if the button is pressed
              led.value(1)  # Turn on the LED
          else:
              led.value(0)  # Turn off the LED
          time.sleep(0.1)  # Short delay to reduce CPU usage