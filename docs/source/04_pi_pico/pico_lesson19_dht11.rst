.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson19_dht11:

Lesson 19: Temperature and Humidity Sensor Module (DHT11)
====================================================================

このレッスンでは、Raspberry Pi Pico Wを使用してDHT11温湿度センサに接続する方法を学びます。環境条件の正確な測定を行い、温度と湿度のデータを記録します。このチュートリアルは、Raspberry Pi Pico Wでデジタルセンサを使用する実践的なガイダンスを提供し、MicroPythonでプログラミングし、リアルタイムのデータ処理を管理する方法を学ぶのに役立ちます。

Required Components
--------------------------

このプロジェクトでは、以下の部品が必要です。

すべての部品を含むキットを購入すると便利です。以下のリンクを参照してください：

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_19_dht11_module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import dht
   import machine
   import time
   
   # Initialize DHT11 sensor on GPIO 16
   d = dht.DHT11(machine.Pin(16))
   
   # Continuously read and print temperature and humidity
   while True: 
       d.measure()    
       print("Temperature:" ,d.temperature())  # Print temperature
       print("Humidity:" ,d.humidity())  # Print humidity
       time.sleep_ms(1000)  # Read every second

Code Analysis
---------------------------

#. ライブラリのインポート:

   コードは必要なライブラリをインポートすることから始まります。 ``dht`` はDHT11センサ用、 ``machine`` はハードウェアとの対話用、 ``time`` はループ内の遅延を追加するために使用されます。

   .. code-block:: python
      
      import dht
      import machine
      import time

#. DHT11センサの初期化:

   DHT11センサは、接続されたGPIOピンを指定して初期化されます。ここでは、Raspberry Pi Pico WのGPIO 16に接続されています。これは、 ``machine.Pin`` 関数を使用して行います。

   .. code-block:: python

      d = dht.DHT11(machine.Pin(16))

#. データの読み取りと表示をループで行う:

   ``while True`` ループは、プログラムが温度と湿度のデータを継続的に読み取ることを可能にします。ループ内では、 ``d.measure()`` を呼び出して新しい測定を行います。 ``d.temperature()`` と ``d.humidity()`` を使用して、それぞれ温度と湿度のデータを取得します。これらの値は表示されます。ループは ``time.sleep_ms(1000)`` を使用して1秒（ ``1000`` ミリ秒）停止し、データが毎秒読み取られて表示されるようにします。

   .. code-block:: python

      while True: 
          d.measure()    
          print("Temperature:" ,d.temperature())  # Print temperature
          print("Humidity:" ,d.humidity())  # Print humidity
          time.sleep_ms(1000)  # Read every second