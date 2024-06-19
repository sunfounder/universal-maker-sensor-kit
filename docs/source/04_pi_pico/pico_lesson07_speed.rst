.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson07_speed:

レッスン07: 赤外線速度センサーモジュール
==========================================

このレッスンでは、Raspberry Pi Pico W を使用して赤外線速度センサーモジュールとインターフェースする方法を学びます。センサーを GPIO 16 に接続することで、リアルタイムで障害物を検出します。プログラムはセンサーの出力を監視し、障害物が検出されると「障害物検出」とコンソールに表示します。障害物がない場合は「障害なし」と表示します。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

すべてのキットを購入するのは非常に便利です。リンクはこちらです。

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
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_07_Speed_pico_bb.png
    :width: 100%

コード
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 16 as an input pin to read the speed sensor
   speed_sensor = Pin(16, Pin.IN)
   
   while True:
       if speed_sensor.value() == 1:
           print("Obstruction detected")
       else:
           print("Unobstructed")
   
       time.sleep(0.1)  # Short delay to reduce CPU usage


コード解析
---------------------------

#. **ライブラリのインポート**:

   このコードは、必要なライブラリをインポートすることから始まります。 ``machine``ライブラリはGPIOピンと対話するために使用され、 ``time``ライブラリはプログラムに遅延を追加するために使用されます。

   .. code-block:: python

      from machine import Pin
      import time

#. **センサーの設定**:

   赤外線速度センサーはGPIO 16に接続されています。これは入力として設定されており、Pi Pico Wがこのピンからデータを読み取ります。

   .. code-block:: python

      speed_sensor = Pin(16, Pin.IN)

#. **メインループ**:

   ``while True:``ループは無限ループを作成します。このループの中で、プログラムはセンサーの値を継続的にチェックします。
   
   ``speed_sensor.value()``が1である場合、それはセンサーが障害物を検出したことを意味します。0の場合、障害物はありません。

   .. code-block:: python

      while True:
          if speed_sensor.value() == 1:
              print("Obstruction detected")
          else:
              print("Unobstructed")

#. **CPU使用率を減らすための遅延**:

   ループの各反復で0.1秒の短い遅延が導入されています。これにより、ループが急速に実行されるのを防ぎ、CPUの使用率を低減します。

   .. code-block:: python
     
      time.sleep(0.1)

#. **補足情報**:

   モーターにエンコーダーが取り付けられている場合、特定の期間内にセンサーを通過する障害物の数をカウントすることで、モーターの回転速度を計算できます。

   .. image:: img/Lesson_07_Encoder_Disk.png
      :align: center
      :width: 20%