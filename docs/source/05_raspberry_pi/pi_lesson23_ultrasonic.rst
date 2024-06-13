.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson23_ultrasonic:

レッスン23: 超音波センサーモジュール (HC-SR04)
================================================

このレッスンでは、超音波距離センサーをRaspberry Piに接続し、距離測定を行うためのPythonスクリプトを書く方法を学びます。センサーのトリガーピンをGPIO 17に、エコーピンをGPIO 27に配線する手順を説明します。提供されたPythonコードを使用して距離を測定し、センチメートル単位で表示します。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全てが揃ったキットを購入すると便利です。リンクはこちらです：

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_23_ultrasonic_sensor_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   #!/usr/bin/env python3
   from gpiozero import DistanceSensor
   from time import sleep

   # Initialize the DistanceSensor using GPIO Zero library
   # Trigger pin is connected to GPIO 17, Echo pin to GPIO 27
   sensor = DistanceSensor(echo=27, trigger=17)

   try:
       # Main loop to continuously measure and report distance
       while True:
           dis = sensor.distance * 100  # Measure distance and convert from meters to centimeters
           print('Distance: {:.2f} cm'.format(dis))  # Print the distance with two decimal precision
           sleep(0.3)  # Wait for 0.3 seconds before the next measurement

   except KeyboardInterrupt:
       # Handle KeyboardInterrupt (Ctrl+C) to gracefully exit the loop
       pass

コード解析
---------------------------

#. ライブラリのインポート
   
   スクリプトは、超音波センサーのためにgpiozeroライブラリから ``DistanceSensor`` を、タイミング制御のためにtimeモジュールから ``sleep`` をインポートすることから始まります。

   .. code-block:: python

      from gpiozero import DistanceSensor
      from time import sleep

#. 距離センサーの初期化
   
   ``DistanceSensor``オブジェクト ``sensor`` が作成され、 ``echo`` ピンと ``trigger`` ピンがそれぞれGPIO 27とGPIO 17に接続されます。これらのピンは、距離測定のために超音波信号の送受信に使用されます。

   .. code-block:: python

      sensor = DistanceSensor(echo=27, trigger=17)

#. 継続的な監視ループの実装
   
   - 無限ループ（ ``while True:`` ）を持つ``try``ブロックが使用され、継続的に距離を測定します。
   - ループ内で、 ``sensor.distance`` はメートル単位で測定された距離を返し、それをセンチメートルに変換して ``dis`` に保存します。
   - 距離は ``format`` メソッドを使用して小数点以下2桁の精度で表示されます。
   - ``sleep(0.3)``は各測定の間に0.3秒の遅延を追加し、読み取りの頻度を制御してCPUの負荷を軽減します。

   .. raw:: html

      <br/>

   .. code-block:: python

      try:
          while True:
              dis = sensor.distance * 100
              print('Distance: {:.2f} cm'.format(dis))
              sleep(0.3)

#. 優雅な終了のためのKeyboardInterruptの処理
   
   ``except``ブロックはKeyboardInterrupt（通常はCtrl+C）をキャッチするために使用されます。これが発生すると、追加のアクションを取ることなくスクリプトはループを正常に終了します。

   .. code-block:: python

      except KeyboardInterrupt:
          pass