.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson05_mpu6050:

レッスン 05: ジャイロスコープ＆加速度計モジュール (MPU6050)
==========================================================

このレッスンでは、Raspberry Pi Pico W を MPU6050 モジュールと組み合わせて使用する方法を学びます。このモジュールはジャイロスコープと加速度計を組み合わせたものです。MPU6050 を Raspberry Pi Pico W に接続し、MicroPython を使用してその加速度およびジャイロスコープのデータを読み取る方法を説明します。このレッスンでは、加速度計とジャイロスコープの X、Y、および Z の各値を継続的に表示するスクリプトの書き方を紹介します。

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
    *   - :ref:`cpn_mpu6050`
        - |link_mpu6050_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_05_mpu6050_circuit_bb.png
    :width: 100%

コード
---------------------------

.. note::

    * ``universal-maker-sensor-kit-main/pico/Lesson_05_MPU6050_Module`` のパスにある ``05_mpu6050_module.py`` ファイルを開くか、このコードを Thonny にコピーし、「現在のスクリプトを実行」をクリックするか、F5 キーを押して実行します。詳細なチュートリアルについては :ref:`open_run_code_py` を参照してください。

    * ここでは ``imu.py`` と ``vector3d.py`` を使用する必要があります。Pico W にアップロードされているか確認してください。詳細なチュートリアルについては :ref:`add_libraries_py` を参照してください。
    * 右下隅にある「MicroPython (Raspberry Pi Pico)」インタープリタをクリックするのを忘れないでください。

.. code-block:: python

   # Import libraries
   from imu import MPU6050
   from machine import I2C, Pin
   import time
   
   # Initialize I2C for MPU6050
   i2c = I2C(1, sda=Pin(20), scl=Pin(21), freq=400000)  # I2C bus 1, SDA pin 20, SCL pin 21, 400kHz
   
   # Create MPU6050 object
   mpu = MPU6050(i2c)
   
   # Main loop to read and print sensor data
   while True:
       # Print accelerometer data (x, y, z)
       print("-" * 50)
       print("x: %s, y: %s, z: %s" % (mpu.accel.x, mpu.accel.y, mpu.accel.z))
       time.sleep(0.1)
   
       # Print gyroscope data (x, y, z)
       print("X: %s, Y: %s, Y: %s" % (mpu.gyro.x, mpu.gyro.y, mpu.gyro.z))
       time.sleep(0.1)
   
       # Delay between readings
       time.sleep(0.5)


コード解析
---------------------------

#. ライブラリのインポートとI2Cの初期化
 
   コードは必要なライブラリをインポートすることから始まります。 ``imu`` ライブラリはMPU6050センサーの値を読み取るために使用され、 ``machine`` はRaspberry Pi Pico Wのハードウェア機能を制御します。I2Cはデータ通信のために特定のピン（SDAとSCL）を使用して初期化されます。

   ``imu`` ライブラリの詳細については |link_imu| を参照してください。

   .. code-block:: python

      from imu import MPU6050
      from machine import I2C, Pin
      import time

      i2c = I2C(1, sda=Pin(20), scl=Pin(21), freq=400000)

#. MPU6050オブジェクトの作成

   初期化されたI2Cを渡してMPU6050センサーのオブジェクトを作成します。このオブジェクトはセンサーデータにアクセスするために使用されます。

   .. code-block:: python

      mpu = MPU6050(i2c)

#. センサーデータの読み取りと表示のループ

   コードは無限ループに入り、加速度計とジャイロスコープのデータを継続的に読み取り、表示します。 ``time.sleep`` は連続する読み取りの間に遅延を作成するために使用されます。

   .. code-block:: python

      while True:
          print("-" * 50)
          print("x: %s, y: %s, z: %s" % (mpu.accel.x, mpu.accel.y, mpu.accel.z))
          time.sleep(0.1)
          print("X: %s, Y: %s, Y: %s" % (mpu.gyro.x, mpu.gyro.y, mpu.gyro.z))
          time.sleep(0.1)
          time.sleep(0.5)