.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson21_vl53l0x:

レッスン21: 飛行時間マイクロ-LIDAR距離センサー (VL53L0X)
====================================================================

このレッスンでは、Raspberry Pi Pico Wを使用してVL53L0X飛行時間マイクロ-LIDAR距離センサーで距離を測定する方法を学びます。Raspberry Pi Pico Wとセンサーの間でI2C通信を設定する手順を説明し、センサーの設定を最適な性能に調整する方法を探ります。また、測定タイミングバジェットとVCSELパルス期間を調整して精度と範囲を向上させる方法も学びます。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

以下のリンクからキット全体を購入するのが便利です:

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
    *   - :ref:`cpn_VL53L0X`
        - |link_vl53l0x_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_21_vl53l0x_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   import time
   from machine import Pin, I2C
   from vl53l0x import VL53L0X
   
   print("setting up i2c")
   id = 0
   sda = Pin(20)
   scl = Pin(21)
   
   i2c = I2C(id=id, sda=sda, scl=scl)
   
   print(i2c.scan())
   
   # print("creating vl53lox object")
   # Create a VL53L0X object
   tof = VL53L0X(i2c)
   
   # Pre: 12 to 18 (initialized to 14 by default)
   # Final: 8 to 14 (initialized to 10 by default)
   
   # the measuting_timing_budget is a value in ms, the longer the budget, the more accurate the reading.
   budget = tof.measurement_timing_budget_us
   print("Budget was:", budget)
   tof.set_measurement_timing_budget(40000)
   
   # Sets the VCSEL (vertical cavity surface emitting laser) pulse period for the
   # given period type (VL53L0X::VcselPeriodPreRange or VL53L0X::VcselPeriodFinalRange)
   # to the given value (in PCLKs). Longer periods increase the potential range of the sensor.
   # Valid values are (even numbers only):
   
   # tof.set_Vcsel_pulse_period(tof.vcsel_period_type[0], 18)
   tof.set_Vcsel_pulse_period(tof.vcsel_period_type[0], 12)
   
   # tof.set_Vcsel_pulse_period(tof.vcsel_period_type[1], 14)
   tof.set_Vcsel_pulse_period(tof.vcsel_period_type[1], 8)
   
   while True:
       # Start ranging
       print(tof.ping() - 50, "mm")
   
       time.sleep_ms(100)  # Short delay of 0.1 seconds to reduce CPU usage

コード解析
---------------------------

#. **I2Cインターフェースの設定**:

   このコードは、必要なモジュールをインポートし、I2C通信を初期化することから始まります。 ``machine`` モジュールを使用して、Raspberry Pi Pico Wの正しいピンを使用してI2Cを設定します。

   ``vl53l0x`` ライブラリの詳細については、 |link_micropython_vl53l0x_driver| をご覧ください。

   .. code-block:: python

      import time
      from machine import Pin, I2C
      from vl53l0x import VL53L0X

      print("setting up i2c")
      id = 0
      sda = Pin(20)
      scl = Pin(21)
      i2c = I2C(id=id, sda=sda, scl=scl)
      print(i2c.scan())

#. **VL53L0Xオブジェクトの作成**:

   ``VL53L0X`` クラスのオブジェクトが作成されます。このオブジェクトは、VL53L0Xセンサーとの対話に使用されます。

   .. code-block:: python

      tof = VL53L0X(i2c)

#. **測定タイミングバジェットの設定**:

   測定タイミングバジェットが設定されます。これは、センサーが測定を実行するのにかかる時間を決定します。タイミングバジェットが長いほど、読み取りがより正確になります。

   .. code-block:: python

      budget = tof.measurement_timing_budget_us
      print("Budget was:", budget)
      tof.set_measurement_timing_budget(40000)

#. **VCSELパルス期間の設定**:

   ここでは、VCSEL（垂直共振器面発光レーザー）のパルス期間が設定されます。これにより、センサーの範囲と精度が影響を受けます。

   .. code-block:: python

      tof.set_Vcsel_pulse_period(tof.vcsel_period_type[0], 12)
      tof.set_Vcsel_pulse_period(tof.vcsel_period_type[1], 8)

#. **連続測定ループ**:

   センサーは継続的に距離を測定し、それを出力します。 ``VL53L0X`` クラスの ``ping()`` メソッドを使用して、距離をミリメートル単位で取得します。CPU使用率を減らすために小さな遅延が追加されています。

   .. code-block:: python

      while True:
          print(tof.ping() - 50, "mm")
          time.sleep_ms(100)