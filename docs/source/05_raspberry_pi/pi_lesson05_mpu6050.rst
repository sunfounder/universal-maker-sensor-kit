.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson05_mpu6050:

レッスン05: ジャイロスコープ＆加速度計モジュール (MPU6050)
==========================================================

このレッスンでは、Raspberry Piと3軸ジャイロスコープと加速度計を統合したセンサーであるMPU6050のインターフェース方法を学びます。加速度、方向、および回転を測定する方法を探ります。このプロジェクトでは、センサーデータの読み取り、ハードウェアとの対話にPythonを使用する方法、およびI2C通信の基本を理解するための実践的な経験を提供します。また、センサーから三軸の加速度、回転速度、および温度を継続的に取得する方法も学びます。Raspberry Piを使用したセンサーとモーショントラッキングに興味のある初心者にとって理想的なスタートポイントです。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式揃ったキットを購入すると便利です。リンクはこちら:

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
    *   - :ref:`cpn_mpu6050`
        - |link_mpu6050_buy|


配線
---------------------------

.. image:: img/Lesson_05_mpu6050_pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   # Import the mpu6050 class and sleep function from respective modules.
   from mpu6050 import mpu6050
   from time import sleep
   
   # Initialize the MPU-6050 sensor with the I2C address 0x68.
   sensor = mpu6050(0x68)
   
   # Infinite loop to continuously read data from the sensor.
   while True:
       # Retrieve accelerometer data from the sensor.
       accel_data = sensor.get_accel_data()
       # Retrieve gyroscope data from the sensor.
       gyro_data = sensor.get_gyro_data()
       # Retrieve temperature data from the sensor.
       temp = sensor.get_temp()
   
       # Print accelerometer data.
       print("Accelerometer data")
       print("x: " + str(accel_data['x']))
       print("y: " + str(accel_data['y']))
       print("z: " + str(accel_data['z']))
   
       # Print gyroscope data.
       print("Gyroscope data")
       print("x: " + str(gyro_data['x']))
       print("y: " + str(gyro_data['y']))
       print("z: " + str(gyro_data['z']))
   
       # Print the temperature in Celsius.
       print("Temp: " + str(temp) + " C")
   
       # Pause for 0.5 seconds before the next read cycle.
       sleep(0.5)

 コード解析
---------------------------

#. インポート文

   ``mpu6050``クラスは ``mpu6050`` ライブラリからインポートされ、 ``sleep`` 関数は ``time`` モジュールからインポートされます。これらのインポートは、MPU-6050センサーとの対話とコード内での遅延を導入するために必要です。

   ``mpu6050``ライブラリの詳細については、|link_mpu6050_python_driver|をご覧ください。

   .. code-block:: python

      from mpu6050 import mpu6050
      from time import sleep

#. センサーの初期化

   I2Cアドレス0x68（MPU-6050センサーのデフォルトアドレス）で ``mpu6050`` クラスのインスタンスを作成します。このステップでセンサーがデータ読み取りのために初期化されます。

   .. code-block:: python

      sensor = mpu6050(0x68)

#. 連続読み取りのための無限ループ

   無限ループ（ ``while True`` ）を使用して、センサーから継続的にデータを読み取ります。これは、常に監視が必要なセンサーアプリケーションで一般的な手法です。

   .. code-block:: python

      while True:

#. センサーデータの読み取り

   ループ内で、 ``mpu6050`` クラスのインスタンスの ``get_accel_data`` 、 ``get_gyro_data`` 、および ``get_temp`` メソッドを使用して加速度計、ジャイロスコープ、および温度センサーからデータを読み取ります。これらのメソッドは、ユーザーフレンドリーな形式でセンサーデータを返します。

   .. code-block:: python

      accel_data = sensor.get_accel_data()
      gyro_data = sensor.get_gyro_data()
      temp = sensor.get_temp()

#. センサーデータの表示

   取得したデータを出力します。加速度計とジャイロスコープのデータは辞書値（x, y, z軸）としてアクセスされ、温度は摂氏値として直接出力されます。

   .. code-block:: python

      print("Accelerometer data")
      print("x: " + str(accel_data['x']))
      print("y: " + str(accel_data['y']))
      print("z: " + str(accel_data['z']))

      print("Gyroscope data")
      print("x: " + str(gyro_data['x']))
      print("y: " + str(gyro_data['y']))
      print("z: " + str(gyro_data['z']))

      print("Temp: " + str(temp) + " C")

#. 読み取り間の遅延

   最後に、 ``sleep(0.5)`` を使用して0.5秒の遅延が導入されます。この遅延は、Raspberry Piが継続的なデータ読み取りで過負荷になるのを防ぐために重要です。

   .. code-block:: python

      sleep(0.5)