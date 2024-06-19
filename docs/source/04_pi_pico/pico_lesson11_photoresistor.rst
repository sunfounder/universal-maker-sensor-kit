.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson11_photoresistor:

レッスン11: フォトレジスタモジュール
=====================================

このレッスンでは、フォトレジスタモジュールをRaspberry Pi Pico Wに接続し、光の強度を測定する方法を学びます。フォトレジスタをアナログ入力に接続することで、異なる光レベルに対応するさまざまなアナログ値を読み取ることができます。このプロジェクトは初心者に最適で、Raspberry Pi Pico WでMicroPythonを使用してアナログ入力を活用する実践的な経験を提供します。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式揃ったキットを購入すると便利です。リンクはこちら：

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_11_photoresistor_module_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   import machine  # Hardware control library
   import time  # Time control library
   
   photoresistor = machine.ADC(26)  # Initialize ADC on pin 26
   
   while True:
       value = photoresistor.read_u16()  # Read analog value
       print(value)  # Print the value
   
       time.sleep_ms(200)  # Delay of 200 ms between reads

       
コード解析
---------------------------

1. **ライブラリのインポート**:

   コードは必要なライブラリをインポートすることから始まります。 ``machine``ライブラリはハードウェアコンポーネントを制御するために使用され、 ``time``ライブラリは遅延などの時間関連のタスクを管理するために使用されます。

   .. code-block:: python

      import machine  # Hardware control library
      import time  # Time control library

2. **フォトレジスタの初期化**:

   ここでは、フォトレジスタを初期化します。 ``machine.ADC``クラスを使用してピン26にADCオブジェクトを作成します。ここにフォトレジスタが接続されています。ADCオブジェクトはフォトレジスタからアナログ値を読み取るために使用されます。

   .. code-block:: python

      photoresistor = machine.ADC(26)  # Initialize ADC on pin 26

3. **フォトレジスタからの読み取り**:

   このループでは、 ``photoresistor.read_u16()``を使用してフォトレジスタからアナログ値を連続的に読み取ります。このメソッドは値を16ビットの符号なし整数として読み取ります。その後、値はコンソールに出力されます。

   .. code-block:: python

      while True:
          value = photoresistor.read_u16()  # Read analog value
          print(value)  # Print the value

4. **遅延の追加**:

   コードが速すぎて実行され、データでコンソールが溢れるのを防ぐために、各読み取りの後に200ミリ秒の遅延を``time.sleep_ms(200)``を使用して追加します。

   .. code-block:: python

      time.sleep_ms(200)  # Delay of 200 ms between reads