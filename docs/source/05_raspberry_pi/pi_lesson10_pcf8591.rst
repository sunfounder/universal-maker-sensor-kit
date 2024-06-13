.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pi_lesson10_pcf8591:

レッスン 10: PCF8591 ADC DAC コンバータモジュール
==============================================

.. note::
   Raspberry Piにはアナログ入力機能がないため、アナログ信号を処理するには :ref:`cpn_pcf8591` のようなモジュールが必要です。

このレッスンでは、Raspberry Piを使用してPCF8591モジュールとやり取りし、アナログからデジタル、デジタルからアナログへの変換方法を学びます。入力AIN0からアナログ値を読み取り、これらの値をDAC（AOUT）に送信する方法をカバーします。モジュールのポテンショメータはジャンパーキャップを使用してAIN0に接続されており、モジュール上のD2 LEDはAOUTに接続されているため、ポテンショメータを回すとD2 LEDの明るさが変わる様子が確認できます。

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
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. note::
   このプロジェクトでは、PCF8591モジュールのAIN0ピンを使用しており、これはジャンパーキャップを介してモジュールのポテンショメータに接続されています。 **モジュール上のジャンパーキャップが正しく配置されていることを確認してください。** 詳細については、PCF8591モジュールの :ref:`schematic <cpn_pcf8591_sch>` を参照してください。

.. image:: img/Lesson_10_PCF8591_pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: Python

   import PCF8591 as ADC  # Import the library for the PCF8591 module
   import time  # Import the time library for adding delays
   
   # Initialize the PCF8591 module at I2C address 0x48.
   # This address is used for communication with the Raspberry Pi.
   ADC.setup(0x48)
   
   try:
       while True:  # Start an infinite loop to continuously monitor the sensor.
           # Read the analog value from the potentiometer connected to AIN0.
           # Channel range from 0 to 3 represents AIN0 to AIN3.
           # The potentiometer's rotation alters the voltage, which is read by the PCF8591.
           potentiometer_value = ADC.read(0)
           print(potentiometer_value)
   
           # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
           # LED won't light up below 80, so convert '0-255' to '80-255'
           # As the potentiometer is adjusted, the LED's brightness varies proportionally.
           tmp = potentiometer_value*(255-80)/255+80
           ADC.write(tmp)
   
           # Add a short delay of 0.2 seconds to make the loop more manageable.
           time.sleep(0.2)
   
   except KeyboardInterrupt:
       # If a KeyboardInterrupt (CTRL+C) is detected, exit the loop and end the program.
       print("Exit")


コード解析
---------------------------

1. **ライブラリのインポート**:

   スクリプトは必要なライブラリのインポートから始まります。 ``PCF8591`` ライブラリはADC/DACモジュールとのやり取りに使用され、 ``time`` は遅延を作成するために使用されます。

   .. code-block:: python

      import PCF8591 as ADC  # Import the library for the PCF8591 module
      import time  # Import the time library for adding delays

2. **PCF8591モジュールの初期化**:

   PCF8591モジュールはI²Cアドレス0x48で初期化されます。このステップは、Raspberry Piとモジュール間の通信を設定するために重要です。

   .. code-block:: python

      ADC.setup(0x48)  # Initialize the PCF8591 module at I2C address 0x48

3. **ポテンショメータからの読み取りとLEDへの書き込み**:

   ``try``ブロック内で、継続的な ``while True`` ループがAIN0に接続されたポテンショメータから値を読み取り、AOUTに接続されたDACにこの値を書き込みます。ジャンパーキャップがモジュールのポテンショメータをAIN0にリンクし、D2 LEDがAOUTに接続されています。詳細については、PCF8591モジュールの :ref:`schematic <cpn_pcf8591_sch>` を参照してください。ポテンショメータを回すと、LEDの明るさが変わります。

   - ``ADC.read(channel)``を使用して、特定のチャネルのアナログ入力を読み取ります。チャネル範囲は0から3で、AIN0からAIN3を表します。

   - ``ADC.write(Value)``を使用して、AOUTピンのアナログ出力を設定します。値の範囲は0から255です。

   .. raw:: html

      <br/>

   .. code-block:: python

      try:
          while True:  # Start an infinite loop to continuously monitor the sensor.
              potentiometer_value = ADC.read(0)
              print(potentiometer_value)
              tmp = potentiometer_value*(255-80)/255+80
              ADC.write(tmp)
              time.sleep(0.2)

4. **キーボード割り込みの処理**:

   ``KeyboardInterrupt``（CTRL+Cを押すなど）により、エラーを生成せずにループから優雅に終了できます。

   .. code-block:: python

      except KeyboardInterrupt:
          print("Exit")