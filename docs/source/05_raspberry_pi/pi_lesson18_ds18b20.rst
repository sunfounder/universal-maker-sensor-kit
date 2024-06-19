.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pi_lesson18_ds18b20:

レッスン18: 温度センサーモジュール (DS18B20)
================================================

このレッスンでは、Raspberry Piを使用してDS18B20温度センサーから温度データを読み取る方法を学びます。センサーのデバイスファイルを見つけ、その生データを読み取り、解析し、このデータを摂氏および華氏の温度に変換する方法を理解します。

Required Components
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_ds18b20`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_18_DS18B20_pi_bb.png
    :width: 100%


Code
---------------------------

.. note::
   DS18B20モジュールはonewireプロトコルを使用してRaspberry Piと通信します。コードを実行する前に、Raspberry Piのonewire機能を有効にする必要があります。このチュートリアルを参照してください：:ref:`pi_enable_1wire`.

.. code-block:: python

   import glob
   import time
   
   # Path to the directory containing device files for 1-wire devices
   base_dir = "/sys/bus/w1/devices/"
   
   # Finds the first device folder that starts with "28", specific to DS18B20
   device_folder = glob.glob(base_dir + "28*")[0]
   
   # Device file containing the temperature data
   device_file = device_folder + "/w1_slave"
   
   
   def read_temp_raw():
       # Reads raw temperature data from the sensor
       f = open(device_file, "r")
       lines = f.readlines()
       f.close()
       return lines
   
   
   def read_temp():
       # Parses the raw temperature data and converts it to Celsius and Fahrenheit
       lines = read_temp_raw()
       # Waits for a valid temperature reading
       while lines[0].strip()[-3:] != "YES":
           time.sleep(0.2)
           lines = read_temp_raw()
       equals_pos = lines[1].find("t=")
       if equals_pos != -1:
           temp_string = lines[1][equals_pos + 2 :]
           temp_c = float(temp_string) / 1000.0  # Convert to Celsius
           temp_f = temp_c * 9.0 / 5.0 + 32.0  # Convert to Fahrenheit
           return temp_c, temp_f
   
   
   try:
       # Main loop to continuously read and print temperature
       while True:
           temp_c, temp_f = read_temp()
           formatted_output = f"Temperature: {temp_c:.2f}°C / {temp_f:.2f}°F"
           print(formatted_output)
           time.sleep(1)  # Wait for 1 second between readings
   except KeyboardInterrupt:
       # Gracefully exit the program on CTRL+C
       print("Exit")




Code Analysis
---------------------------

#. 必要なライブラリのインポート

   ``glob`` ライブラリは温度センサーのデバイスフォルダを検索するために使用されます。 ``time`` ライブラリはプログラム内で遅延を実装するために使用されます。

   .. code-block:: python

      import glob
      import time

#. 温度センサーデバイスファイルの位置特定

   コードは "28" で始まるフォルダ名を探すことでDS18B20センサーのディレクトリを検索します。デバイスファイル ``w1_slave`` には温度データが含まれています。

   .. code-block:: python

      base_dir = "/sys/bus/w1/devices/"
      device_folder = glob.glob(base_dir + "28*")[0]
      device_file = device_folder + "/w1_slave"

#. 生の温度データの読み取り

   この関数はデバイスファイルを開き、その内容を読み取ります。生の温度データを文字列のリストとして返します。

   .. code-block:: python

      def read_temp_raw():
          f = open(device_file, "r")
          lines = f.readlines()
          f.close()
          return lines

#. 温度データの解析と変換

   ``read_temp`` 関数は ``read_temp_raw`` を呼び出して生データを取得します。有効な温度読み取りを待ってから、温度を抽出、解析し、摂氏と華氏に変換します。

   .. code-block:: python

      def read_temp():
          lines = read_temp_raw()
          while lines[0].strip()[-3:] != "YES":
              time.sleep(0.2)
              lines = read_temp_raw()
          equals_pos = lines[1].find("t=")
          if equals_pos != -1:
              temp_string = lines[1][equals_pos + 2 :]
              temp_c = float(temp_string) / 1000.0
              temp_f = temp_c * 9.0 / 5.0 + 32.0
              return temp_c, temp_f

#. メインプログラムループと正常終了

   ``try`` ブロックは温度を継続的に読み取り表示する無限ループを含みます。 ``except`` ブロックは KeyboardInterrupt をキャッチしてプログラムを正常に終了します。

   .. code-block:: python

      try:
          while True:
              temp_c, temp_f = read_temp()
              formatted_output = f"Temperature: {temp_c:.2f}°C / {temp_f:.2f}°F"
              print(formatted_output)
              time.sleep(1)
      except KeyboardInterrupt:
          print("Exit")