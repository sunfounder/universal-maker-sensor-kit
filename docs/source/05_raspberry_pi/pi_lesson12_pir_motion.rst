.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pi_lesson12_pir_motion:

レッスン 12: PIRモーションモジュール (HC-SR501)
===============================================

このレッスンでは、Raspberry Piを使用してモーションセンサーを設定し、使用する方法を学びます。デジタルモーションセンサーをGPIOピン17に接続する手順を説明します。Pythonスクリプトを作成してセンサーの状態を継続的にチェックし、動きを検知したときとエリアがクリアなときにメッセージを表示します。この実践的なチュートリアルは、電子回路とPythonプログラミングの実践的なスキルに焦点を当てており、Raspberry Piを使用したモニタリングおよび自動化プロジェクトの現実世界の応用を探求したい初心者に最適です。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

すべてのキットを購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_12_pir_module_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice
   from time import sleep

   # Initialize the motion sensor as a digital input device on GPIO pin 17
   motion_sensor = DigitalInputDevice(17)

   # Continuously monitor the state of the motion sensor
   while True:
       if motion_sensor.is_active:
           print("Somebody here!")
       else:
           print("Monitoring...")

       # Wait for 0.5 seconds before the next sensor check
       sleep(0.5)

コード分析
---------------------------

#. ライブラリのインポート
   
   スクリプトは、モーションセンサーとのインターフェースに使用するgpiozeroライブラリの ``DigitalInputDevice`` クラスと、遅延を導入するためのtimeモジュールから ``sleep`` 関数をインポートすることから始まります。

   .. code-block:: python

      from gpiozero import DigitalInputDevice
      from time import sleep

#. モーションセンサーの初期化
   
   ``DigitalInputDevice`` オブジェクトに名前 ``motion_sensor`` を付け、GPIOピン17に接続します。これは、モーションセンサーがRaspberry PiのこのGPIOピンに接続されていることを前提としています。

   .. code-block:: python

      motion_sensor = DigitalInputDevice(17)

#. 継続的な監視ループの実装
   
   - スクリプトは ``while True:`` ループを使用して継続的に監視します。
   - ループ内では、 ``if`` 文で``motion_sensor ``の`` is_active``プロパティをチェックします。
   - ``is_active``が ``True`` の場合、動きが検出されたことを示し、「誰かがいます！」と表示されます。
   - ``is_active``が ``False`` の場合、動きが検出されなかったことを示し、「監視中...」と表示されます。
   - ``sleep(0.5)``関数は、各センサーのチェックの間にループを0.5秒間一時停止させ、処理負荷を軽減し、センサーのポーリング頻度を制御します。

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if motion_sensor.is_active:
              print("Somebody here!")
          else:
              print("Monitoring...")
          sleep(0.5)

