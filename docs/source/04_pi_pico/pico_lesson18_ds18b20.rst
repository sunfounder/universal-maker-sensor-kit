.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson18_ds18b20:

レッスン18: 温度センサーモジュール (DS18B20)
================================================

このレッスンでは、Raspberry Pi Pico Wを使用してDS18B20センサーから温度データを取得する方法を学びます。GPIOピンにOneWireバスを設定し、DS18X20デバイスをスキャンすることから始めます。このレッスンの主な焦点は、これらのセンサーから温度測定値を継続的に読み取り、表示することです。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全キットを購入すると便利です。リンクはこちらです：

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
    *   - :ref:`cpn_ds18b20`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_18_DS18B20_bb.png
    :width: 100%

コード
---------------------------

.. code-block:: python

   from machine import Pin
   import onewire
   import time, ds18x20
   
   # Initialize the OneWire bus on GPIO pin 12
   ow = onewire.OneWire(Pin(12))
   
   # Create a DS18X20 instance using the OneWire bus
   ds = ds18x20.DS18X20(ow)
   
   # Scan for DS18X20 devices on the bus and print their addresses
   roms = ds.scan()
   print('found devices:', roms)
   
   # Continuously read and print temperature data from the sensors
   while True:
       # Start the temperature conversion process
       ds.convert_temp()
       # Wait for the conversion to complete (750 ms for DS18X20)
       time.sleep_ms(750)
       
       # Read and print the temperature from each sensor found on the bus
       for rom in roms:
           print(ds.read_temp(rom))
       
       # Wait for a short period before the next reading (1000 ms)
       time.sleep_ms(1000)



Code Analysis
---------------------------

#. インポートするライブラリ

   コードは必要なライブラリをインポートすることから始まります。 ``machine`` はGPIOピンの制御に使用され、 ``onewire`` はOneWire通信プロトコルに使用され、 ``ds18x20``  は特定の温度センサーに使用され、 ``time`` は遅延処理に使用されます。

   MicroPythonにおけるOneWireの詳細については、|link_micropython_onewire_driver| を参照してください。

   .. code-block:: python

      from machine import Pin
      import onewire
      import time, ds18x20

#. OneWireバスの初期化

   GPIOピン12でOneWireバスを初期化します。これにより、Raspberry Pi Pico WとDS18B20センサー間の通信が設定されます。

   .. code-block:: python

      ow = onewire.OneWire(Pin(12))

#. DS18X20インスタンスの作成

   OneWireバスを使用してDS18X20インスタンスを作成します。このインスタンスを使用して温度センサーと対話します。

   .. code-block:: python

      ds = ds18x20.DS18X20(ow)

#. デバイスのスキャン

   コードはOneWireバス上のDS18X20デバイスをスキャンして、そのアドレスを表示します。これは接続されたセンサーを特定するために重要です。

   .. code-block:: python

      roms = ds.scan()
      print('found devices:', roms)

#. 温度データの読み取り

   - プログラムのメインループは、センサーから温度データを継続的に読み取ります。
   - 温度変換プロセスを開始し、完了するまで約750ミリ秒待ちます。
   - バス上の各センサーから温度を読み取り、表示します。
   - ループは1000ミリ秒の間隔で繰り返されます。

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          ds.convert_temp()
          time.sleep_ms(750)
          for rom in roms:
              print(ds.read_temp(rom))
          time.sleep_ms(1000)