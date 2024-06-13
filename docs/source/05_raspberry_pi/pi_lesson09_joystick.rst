.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson09_joystick:

レッスン 09: ジョイスティックモジュール
========================================

.. note::
   Raspberry Piにはアナログ入力機能がないため、アナログ信号を処理するには :ref:`cpn_pcf8591` のようなモジュールが必要です。

このレッスンでは、PCF8591 ADCを使用してジョイスティックモジュールとインターフェースする方法を学びます。ジョイスティックのアナログ出力からX軸とY軸の位置を読み取り、ボタンの押下を検出できるようになります。このセットアップにより、Raspberry Piでアナログ入力とデジタル入力の両方を処理する方法が示されます。

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|


配線
---------------------------

.. note::
   このプロジェクトでは、PCF8591モジュールのAIN0ピンを使用しています。このピンは、ジャンパキャップを通してモジュールのポテンショメータに接続されています。 **データ干渉を防ぐため、ジャンパキャップをモジュールから外してください。**  詳細については、PCF8591モジュールの :ref:`schematic <cpn_pcf8591_sch>` を参照してください。

.. image:: img/Lesson_09_Jostick_Module_pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   import PCF8591 as ADC  # Import ADC module for analog input
   import time  # Import time module for creating delay
   from gpiozero import Button  # Import Button for button input
   
   ADC.setup(0x48)  # Set up PCF8591 module at I2C address 0x48
   
   button = Button(17)  # Initialize button connected to GPIO 17
   
   try:
       while True:  # Loop continuously
           print("x:", ADC.read(0))  # Read analog value from channel AIN0
           print("y:", ADC.read(1))  # Read analog value from channel AIN1
           print("sw:", button.is_active)  # Check if button is pressed
           time.sleep(0.2)  # Wait for 0.2 seconds before next loop
   except KeyboardInterrupt:
       print("Exit")  # End program on keyboard interrupt


コード解析
---------------------------

1. **ライブラリのインポート**:

   スクリプトは、プロジェクトに必要なライブラリをインポートすることから始まります。

   .. code-block:: python

      import PCF8591 as ADC  # Import ADC module for analog input
      import time  # Import time module for creating delay
      from gpiozero import Button  # Import Button for button input

2. **PCF8591モジュールのセットアップ**:

   PCF8591モジュールはI2Cアドレス0x48に設定されており、Raspberry Piと通信できるようにします。

   .. code-block:: python

      ADC.setup(0x48)  # Set up PCF8591 module at I2C address 0x48

3. **ボタンの初期化**:

   ボタンはRaspberry PiのGPIOピン17に接続され、初期化されます。

   .. code-block:: python

      button = Button(17)  # Initialize button connected to GPIO 17

4. **メインループ**:

   スクリプトの主な部分は無限ループで、PCF8591の2つのチャネル（AIN0とAIN1）からアナログ値を継続的に読み取り、ボタンが押されているかどうかを確認します。 ``AIN0`` と ``AIN1`` はジョイスティックのX軸とY軸のアナログピンです。

   .. code-block:: python

      try:
          while True:  # Loop continuously
              print("x:", ADC.read(0))  # Read analog value from channel AIN0
              print("y:", ADC.read(1))  # Read analog value from channel AIN1
              print("sw:", button.is_active)  # Check if button is pressed
              time.sleep(0.2)  # Wait for 0.2 seconds before next loop

5. **割り込み処理**:

   スクリプトはキーボード割り込み（CTRL+C）を使用して正常に終了できます。これは、Pythonで無限ループを停止する一般的な方法です。

   .. code-block:: python

      except KeyboardInterrupt:
          print("Exit")  # End program on keyboard interrupt