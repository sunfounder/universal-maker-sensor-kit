.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson15_raindrop:

レッスン15: 雨滴検出モジュール
=======================================

このレッスンでは、Raspberry Pi Pico Wを使用してピン16に接続された雨滴センサーを使用して雨滴を検出する方法を学びます。スクリプトは雨滴の兆候を継続的に監視し、検出された場合は「Raindrop detected!」と表示し、雨滴が検出されない場合は「Monitoring...」と表示します。このセッションでは、Raspberry Pi Pico Wを使用したデジタル入力の処理と、MicroPythonによる環境センサリングの理解を実践的に学ぶことができ、エレクトロニクスとプログラミングの初心者に最適です。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_raindrop`
        - |link_raindrop_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_15_raindrop_detection_module_bb.png
    :width: 100%

コード
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Initialize raindrop sensor connected to pin 16 as input
   raindrop_sensor = Pin(16, Pin.IN)
   
   while True:
       # Check the Raindrop sensor value
       if raindrop_sensor.value() == 0:  
           print("Raindrop detected!")  # Raindrop detected
       else:
           print("Monitoring...")  # No raindrop detected
   
       time.sleep(0.1)  # Short delay of 0.1 seconds to reduce CPU usage

コード解析
---------------------------

#. 雨滴センサーの初期化:

   雨滴センサーは ``machine`` モジュールの ``Pin`` クラスを使用して初期化され、ピン16が入力モードに設定されています。これにより、Raspberry Pi Pico Wがセンサーの出力を読み取ることができます。

   .. code-block:: python
   
       from machine import Pin
       raindrop_sensor = Pin(16, Pin.IN)

#. 継続的な監視ループ:

   継続的なwhileループを使用してセンサーを監視します。ループ内でセンサーの値をチェックします。値が0の場合、雨滴が検出され、「Raindrop detected!」と表示されます。それ以外の場合は、雨滴が検出されていないことを示すために「Monitoring...」と表示されます。

   .. code-block:: python
   
       while True:
           if raindrop_sensor.value() == 0:  
               print("Raindrop detected!")
           else:
               print("Monitoring...")

#. 遅延の導入:

   CPU使用率を下げるために、ループの各反復で0.1秒の遅延を挿入します。これにより、ループが高速で実行されすぎるのを防ぎます。

   .. code-block:: python
   
       time.sleep(0.1)