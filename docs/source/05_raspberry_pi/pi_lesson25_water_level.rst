.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pi_lesson25_water_level:

レッスン25: 水位センサーモジュール
=========================================

.. note::
   Raspberry Piにはアナログ入力機能がないため、アナログ信号を処理するためには :ref:`cpn_pcf8591` のようなモジュールが必要です。

このレッスンでは、水位センサーを使用してRaspberry Piから読み取る方法を学びます。水位センサーモジュールをPCF8591に接続してアナログからデジタルへの変換を行い、Pythonを使ってリアルタイムでその出力を監視する方法を説明します。

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
    *   - :ref:`cpn_water_level`
        - \-
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|


配線
---------------------------

.. image:: img/Lesson_25_Water_Level_Sensor_Module_pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   import PCF8591 as ADC  # Import PCF8591 module
   import time  # Import time for delay
   
   ADC.setup(0x48)  # Initialize PCF8591 at address 0x48
   
   try:
       while True:  # Continuously read and print
           print(ADC.read(1))  # Read from Water level sensor module at AIN1
           time.sleep(0.2)  # Delay of 0.2 seconds
   except KeyboardInterrupt:
       print("Exit")  # Exit on CTRL+C


コード解析
---------------------------


1. **ライブラリのインポート**:

   このセクションでは、必要なPythonライブラリをインポートします。 ``PCF8591`` ライブラリはPCF8591モジュールとの対話に使用され、 ``time`` ライブラリはコード内の遅延を実装するために使用されます。

   .. code-block:: python

      import PCF8591 as ADC  # Import PCF8591 module
      import time  # Import time for delay

2. **PCF8591モジュールの初期化**:

   ここでは、PCF8591モジュールを初期化します。アドレス ``0x48`` はPCF8591モジュールのI²Cアドレスです。これにより、Raspberry Piがモジュールと通信できるようになります。

   .. code-block:: python

      ADC.setup(0x48)  # Initialize PCF8591 at address 0x48

3. **メインループとデータ読み取り**:

   ``try``ブロックには、連続的に水位センサーモジュールからデータを読み取るループが含まれています。 ``ADC.read(1)`` 関数は、PCF8591モジュールのチャネル1（AIN1）に接続されたセンサーからアナログ入力をキャプチャします。 ``time.sleep(0.2)`` を取り入れることで、各読み取りの間に0.2秒の一時停止が作成されます。これにより、Raspberry PiのCPU使用率が低減され、過剰なデータ処理の負担を避けるとともに、端末が急速にスクロールする情報で溢れるのを防ぎ、出力の監視と分析が容易になります。

   .. code-block:: python

      try:
          while True:  # Continuously read and print
              print(ADC.read(1))  # Read from Water level sensor module at AIN1
              time.sleep(0.2)  # Delay of 0.2 seconds

4. **キーボード割り込みの処理**:

   ``except``ブロックは、キーボード割り込み（CTRL+Cなど）をキャッチするように設計されています。この割り込みが発生すると、スクリプトは「exit」と表示して実行を停止します。これは、Pythonで連続実行するスクリプトを正常に終了する一般的な方法です。

   .. code-block:: python

      except KeyboardInterrupt:
          print("exit")  # Exit on CTRL+C