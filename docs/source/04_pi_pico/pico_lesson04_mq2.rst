.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson04_mq2:

レッスン04: ガスセンサーモジュール (MQ-2)
============================================

このレッスンでは、Raspberry Pi Pico W を使用してガスセンサーモジュール (MQ-2) からデータを読み取る方法を学びます。MicroPython を使って、MQ-2 センサーからのアナログ信号を処理するために GPIO ピン 26 に ADC を設定する手順を説明します。環境中のガスの存在を理解するために、センサーデータを継続的に監視して印刷する実践的な経験を得ることができます。

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
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_04_mq2_sensor_circuit_bb.png
    :width: 100%

コード
---------------------------

.. code-block:: python

   import machine
   import utime
   
   # Initialize an ADC object on GPIO pin 26.
   # This is typically used for reading analog signals.
   mq2_AO = machine.ADC(26)
   
   # Continuously read and print sensor data.
   while True:
       value = mq2_AO.read_u16()  # Read and convert analog value to 16-bit integer
       print("AO:", value)  # Print the analog value
   
       utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read

コード解析
---------------------------

#. ライブラリのインポート:

   コードは必要なライブラリをインポートすることから始まります。 ``machine`` はハードウェアとのやり取りに使用され、 ``utime`` は時間関連のタスクを処理します。

   .. code-block:: python

      import machine
      import utime

#. MQ-2 センサーの初期化:

   ADC オブジェクトが GPIO ピン 26 に作成され、MQ-2 センサーからのアナログ信号を読み取ります。MQ-2 センサーは、空気中のガス濃度に応じて変化するアナログ信号を出力します。

   .. code-block:: python

      mq2_AO = machine.ADC(26)

#. センサーデータをループで読み取る:

   プログラムのメインループでは、センサーからアナログ値を継続的に読み取ります。 ``read_u16`` メソッドはアナログ値を読み取り、16ビットの整数に変換します。この値が印刷されます。ループには遅延 (``utime.sleep_ms(200)``) が含まれており、200 ミリ秒待機してから再びセンサー値を読み取ります。この遅延は、センサーとマイクロコントローラーが急速な読み取りに圧倒されないようにするために重要です。

   .. note::

     MQ-2 は加熱駆動型センサーであり、使用前に通常予熱が必要です。予熱期間中、センサーは通常高い値を読み取り、安定するまで徐々に減少します。

   .. code-block:: python

      while True:
          value = mq2_AO.read_u16()  # Read and convert analog value to 16-bit integer
          print("AO:", value)  # Print the analog value
          utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read