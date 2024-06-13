.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson03_flame:

レッスン03：火炎センサーモジュール
==================================

このレッスンでは、Raspberry Pi Pico Wを使用して火炎センサーで火を検知する方法を学びます。センサーが火を検知すると、Raspberry Pi Pico WのオンボードLEDが点灯し、火災検知を示すメッセージを表示します。火災が検知されない場合、LEDは消灯し、別のメッセージが表示されます。このプロジェクトは、外部センサーの使用方法を紹介し、MicroPythonを使用してRaspberry Pi Pico Wのデジタル入出力を処理する実践的な経験を提供します。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。リンクはこちらです：

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
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_03_flame_module_circuit_bb.png
    :width: 100%

コード
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 16 as an input pin to read the flame sensor state
   flame_sensor = Pin(16, Pin.IN)
   
   # Initialize the onboard LED of the Raspberry Pi Pico W
   led = Pin("LED", Pin.OUT)
   
   while True:
       if flame_sensor.value() == 0:
           led.value(1)  # Turn on the LED
           print("** Fire detected!!! **")
       else:
           led.value(0)  # Turn off the LED
           print("No Fire detected")
   
       time.sleep(0.1)  # Short delay to reduce CPU usage

コード解析
---------------------------

#. 必要なモジュールのインポート

   この部分では、必要なモジュールをインポートします。 ``machine`` はGPIOピンとのやり取りに使用され、 ``time`` は遅延機能を提供します。
   
   .. code-block:: python

      from machine import Pin
      import time

#. 火炎センサーとLEDの初期化

   火炎センサーとオンボードLEDを設定します。ピン16を入力ピンとして火炎センサーを読み取り、オンボードLEDを出力として設定します。
   
   .. code-block:: python

      flame_sensor = Pin(16, Pin.IN)
      led = Pin("LED", Pin.OUT)

#. メインループ

   - 無限ループで火炎センサーの状態をチェックします。センサーが火を検知した場合（値が0）、LEDを点灯し、メッセージを表示します。そうでない場合、LEDを消灯し、別のメッセージを表示します。
   - 0.1秒の遅延がCPU使用率を減らします。

   .. raw:: html
      
      <br/>
   
   .. code-block:: python

      while True:
          if flame_sensor.value() == 0:
              led.value(1)
              print("** Fire detected!!! **")
          else:
              led.value(0)
              print("No Fire detected")
          time.sleep(0.1)