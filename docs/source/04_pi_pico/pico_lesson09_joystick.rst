.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson09_joystick:

レッスン09: ジョイスティックモジュール
=======================================

このレッスンでは、Raspberry Pi Pico Wを使用してジョイスティックモジュールとインターフェースし、データを読み取る方法を学びます。ジョイスティックのX軸とY軸からアナログ値を初期化して読み取る方法、およびそのスイッチからデジタル入力を処理する方法を探求します。このレッスンは初心者に最適で、Raspberry Pi Pico Wでのアナログおよびデジタル入力の読み取りと解釈に実践的な経験を提供します。

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_09_Jostick_Module_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   import machine  # Import hardware control module
   import time  # Import time module
   
   # Initialize X and Y axes of the joystick
   x_joystick = machine.ADC(27)
   y_joystick = machine.ADC(26)
   
   # Initialize joystick switch with pull-up resistor
   z_switch = machine.Pin(22, machine.Pin.IN, machine.Pin.PULL_UP)
   
   while True:  # Continuous reading loop
       x_value = x_joystick.read_u16()  # Read X-axis value
       y_value = y_joystick.read_u16()  # Read Y-axis value
       z_value = z_switch.value()  # Read switch state
   
       # Print joystick values and switch state
       print("X: ", x_value, " Y: ", y_value)
       print("SW: ", z_value)
   
       time.sleep_ms(200)  # Loop every 200 milliseconds


コード解析
---------------------------

#. ライブラリのインポート

   ``machine``および ``time``モジュールは、ハードウェア制御と時間関数のためにインポートされます。

   .. code-block:: python

      import machine  # Import hardware control module
      import time  # Import time module

#. ジョイスティック軸の初期化

   ジョイスティックのX軸とY軸はそれぞれアナログピン（27と26）に接続されています。これらのピンはADC（アナログ-デジタルコンバータ）オブジェクトとして初期化されます。

   .. code-block:: python

      x_joystick = machine.ADC(27)
      y_joystick = machine.ADC(26)

#. ジョイスティックスイッチの初期化

   ジョイスティックのスイッチはピン22に接続されています。これはプルアップ抵抗付きの入力として設定されています。ボタンが押されていないときは高（1）を読み取り、押されたときは低（0）を読み取ります。

   .. code-block:: python

      z_switch = machine.Pin(22, machine.Pin.IN, machine.Pin.PULL_UP)

#. メインループ

   - 無限ループはジョイスティックの値を継続的に読み取ります。
   - ``read_u16``メソッドを使用して、X軸とY軸から16ビットの値を読み取ります。
   - ``value()``メソッドを使用して、スイッチの状態を読み取ります。
   - 値は印刷され、ループは200ミリ秒間一時停止します。

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:  # Continuous reading loop
          x_value = x_joystick.read_u16()  # Read X-axis value
          y_value = y_joystick.read_u16()  # Read Y-axis value
          z_value = z_switch.value()  # Read switch state

          # Print joystick values and switch state
          print("X: ", x_value, " Y: ", y_value)
          print("SW: ", z_value)

          time.sleep_ms(200)  # Loop every 200 milliseconds