.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson04_mq2:

レッスン 04: ガスセンサーモジュール (MQ-2)
============================================

このレッスンでは、Raspberry Piを使用してMQ2ガスセンサーでガスを検出する方法を学びます。このコースでは、MQ2センサーをGPIO17ピンに接続し、PythonでRaspberry Piをプログラミングしてセンサー出力を読み取る方法をカバーします。ガスの存在を検出する方法を理解し、センサーからの低信号がガスの検出を示します。このプロジェクトは、Raspberry Piでのセンサーの使用とPythonスクリプトの実践的な入門編を提供し、環境監視や安全アプリケーションに興味のある初心者に最適です。

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
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_04_mq2_sensor_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice
   import time
 
   # Initialize MQ2 sensor on GPIO17
   mq2 = DigitalInputDevice(17)
 
   while True:
      # Detect gas presence (LOW signal indicates gas)
      if mq2.value == 0:
         print("Gas detected!")
      else:
         print("No gas detected.")
 
      # Delay between readings
      time.sleep(1)

 

コード解析
---------------------------

#. ライブラリのインポート

   .. code-block:: python
      
      from gpiozero import DigitalInputDevice
      import time

   このセクションでは、必要なライブラリをインポートします。 ``gpiozero`` はRaspberry PiのGPIOピンと対話するために使用され、 ``time`` は遅延などの時間関連のタスクを処理するために使用されます。

#. MQ2センサーの初期化

   .. code-block:: python

      mq2 = DigitalInputDevice(17)

   ここでは、MQ2センサーをRaspberry PiのGPIOピン17にデジタル入力デバイスとして初期化します。このためにgpiozeroの ``DigitalInputDevice`` クラスを使用します。

#. センサー読み取り用の無限ループ

   .. code-block:: python

      while True:
         if mq2.value == 0:
            print("Gas detected!")
         else:
            print("No gas detected.")
         time.sleep(1)

   このセグメントでは:

   .. note::
      MQ-2センサーモジュールのDOピンは可燃性ガスの存在を示します。ガス濃度がモジュール上のポテンショメータで設定された閾値を超えると、D0はLOWになり、そうでない場合はHIGHのままです。
   
   - ``while True``を使用して無限ループを作成します。このループはプログラムが手動で停止されるまで実行され続けます。
   - ループ内で、 ``mq2.value`` を使用してMQ2センサーの値を確認します。値が0の場合はガスの存在を示し、「ガスが検出されました！」と表示されます。そうでない場合は「ガスは検出されませんでした。」と表示されます。
   - ``time.sleep(1)``は各読み取りの間に1秒の遅延を作り、センサーのチェック頻度と出力メッセージの頻度を減らします。
