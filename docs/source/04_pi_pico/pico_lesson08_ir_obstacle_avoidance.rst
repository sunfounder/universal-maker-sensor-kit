.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson08_ir_obstacle_avoidance:

レッスン08: 赤外線障害物回避センサーモジュール
====================================================

このレッスンでは、Raspberry Pi Pico W と赤外線障害物回避センサーモジュールの使用方法を学びます。センサーのセットアップと、障害物を検出するためにその値を継続的に読み取るMicroPythonスクリプトの作成について説明します。センサーデータの変化を監視することで、基本的な障害物検出の方法を理解することができます。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全セットを購入するのが便利です。以下のリンクをご覧ください：

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
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_08_Obstacle_Avoidance_Sensor_Module_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Initialize obstacle avoidance sensor connected to pin 16 as input
   obstacle_avoidance_sensor = Pin(16, Pin.IN)
   
   while True:
       # Read and print the value of the obstacle avoidance sensor
       print(obstacle_avoidance_sensor.value())
   
       # Wait for 0.1 seconds before the next read
       time.sleep(0.1)


コード解析
---------------------------

#. ライブラリのインポート

   ``machine``モジュールはGPIOピンと対話するためにインポートされ、 ``time`` モジュールは遅延を追加するために使用されます。

   .. code-block:: python

      from machine import Pin
      import time

#. センサーの設定
   
   障害物回避センサーはGPIOピン16に入力デバイスとして設定されています。 ``Pin.IN`` パラメータはピンを入力として設定します。

   .. code-block:: python

      obstacle_avoidance_sensor = Pin(16, Pin.IN)

#. ループでセンサーデータを読み取る

   ``while True:``ループはセンサーの出力を継続的にチェックします。センサーが障害物を検出すると、 ``0`` を返し、それが表示されます。 ``time.sleep(0.1)``は読み取りを管理しやすくするために小さな遅延を追加します。

   .. code-block:: python

      while True:
          print(obstacle_avoidance_sensor.value())
          time.sleep(0.1)

   .. note:: 
   
      センサーが正常に動作しない場合は、赤外線送信機と受信機を平行に調整してください。また、内蔵のポテンショメーターを使用して検出範囲を調整することもできます。

