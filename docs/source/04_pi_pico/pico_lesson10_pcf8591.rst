.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson10_pcf8591:

レッスン10: PCF8591 ADC DAC コンバータモジュール
=================================================

このレッスンでは、MicroPython を使用して Raspberry Pi Pico W と PCF8591 ADC DAC コンバータモジュールを接続する方法を学びます。I2C 接続を確立し、PCF8591 モジュールを初期化し、そのチャンネルからアナログ値を読み取ります。このハンズオンセッションを通じて、アナログ-デジタル変換と Raspberry Pi Pico W 上での I2C 通信についての理解を深めることができます。モジュールのポテンショメータはジャンパーキャップを使用して AIN0 に接続され、モジュールの D2 LED は AOUT に接続されているため、ポテンショメータを回すと D2 LED の明るさが変化することがわかります。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

すべてを揃えたキットを購入すると便利です。こちらのリンクをご覧ください：

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
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_10_PCF8591_Module_bb.png
    :width: 100%


コード
---------------------------

.. note::

    * ``universal-maker-sensor-kit-main/pico/Lesson_10_PCF8591_Module`` のパスにある ``10_pcf8591_module.py`` ファイルを開くか、このコードを Thonny にコピーし、「現在のスクリプトを実行」をクリックするか、F5 キーを押して実行します。詳細なチュートリアルについては :ref:`open_run_code_py` を参照してください。

    * ここでは ``PCF8591.py`` を使用する必要があります。Pico W にアップロードされているか確認してください。詳細なチュートリアルについては :ref:`add_libraries_py` を参照してください。
    * 右下隅にある「MicroPython (Raspberry Pi Pico)」インタープリタをクリックするのを忘れないでください。

.. code-block:: python

   from machine import I2C, Pin
   import time
   from PCF8591 import PCF8591
   
   # Setup I2C connection on pins 20 (SDA) and 21 (SCL)
   i2c = I2C(0, sda=Pin(20), scl=Pin(21))
   
   # Initialize the PCF8591 module at address 0x48
   pcf8591 = PCF8591(0x48, i2c)  # Adjust the address if needed
   
   # Check if the PCF8591 module is connected
   if pcf8591.begin():
       print("PCF8591 found")
   
   # Main loop to read analog values
   while True:
       # Read and print the analog value from channel AIN0
       AIN0 = pcf8591.analog_read(PCF8591.AIN0)
       print("AIN0 ", AIN0)  # PCF8591.CHANNEL_0 can also be used
       # Additional channels can be read by uncommenting the following lines
       # print("AIN1 ", pcf8591.analog_read(PCF8591.AIN1))
       # print("AIN2 ", pcf8591.analog_read(PCF8591.AIN2))
       # print("AIN3 ", pcf8591.analog_read(PCF8591.AIN3))
   
       # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
       pcf8591.analog_write(AIN0)
   
       # Wait for 0.2 seconds before the next read
       time.sleep(0.2)

コード解析
---------------------------

#. ライブラリのインポートとI2Cの設定

   - ``machine`` モジュールをインポートしてI2C通信と ``Pin`` クラスを使用します。
   - ``time`` モジュールをインポートしてプログラムに遅延を追加します。
   - ``PCF8591`` ライブラリをインポートしてPCF8591モジュールとの簡単なやり取りを行います。 ``PCF8591`` ライブラリの詳細については、|link_PCF8591_micropython_library|をご覧ください。

   .. raw:: html

      <br/>

   .. code-block:: python

      from machine import I2C, Pin
      import time
      from PCF8591 import PCF8591

#. I2C接続の初期化

   I2C通信はSDA（シリアルデータ）とSCL（シリアルクロック）ピンを使用して初期化されます。Raspberry Pi Pico WではGPIO 20と21が使用されます。

   .. code-block:: python

      i2c = I2C(0, sda=Pin(20), scl=Pin(21))

#. PCF8591モジュールの初期化

   PCF8591モジュールは、そのI2Cアドレス（0x48）で初期化されます。このアドレスはモジュールの設定に応じて調整が必要な場合があります。

   .. code-block:: python

      pcf8591 = PCF8591(0x48, i2c)  # Adjust the address if needed

#. 接続の確認

   プログラムはPCF8591モジュールが正しく接続されているかを確認します。

   .. code-block:: python

      if pcf8591.begin():
          print("PCF8591 found")

#. アナログ値を読み取るメインループ

   - プログラムは無限ループに入り、チャンネルAIN0からアナログ値を継続的に読み取ります。
   - ``analog_read`` 関数を使用して指定されたチャンネルから値を読み取ります。
   - ``analog_write`` 関数を使用して値をAOUTに書き込みます。
   - ジャンパーキャップはモジュールのポテンショメータをAIN0にリンクし、D2 LEDはAOUTに接続されています。そのため、ポテンショメータを回すとLEDの明るさが変わります。詳細については、PCF8591モジュールの :ref:`回路図 <cpn_pcf8591_sch>` を参照してください。
   - 読み取りの間に0.2秒の遅延を追加して出力を安定させます。

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          # Read and print the analog value from channel AIN0
          AIN0 = pcf8591.analog_read(PCF8591.AIN0)
          print("AIN0 ", AIN0)  # PCF8591.CHANNEL_0 can also be used
          # Additional channels can be read by uncommenting the following lines
          # print("AIN1 ", pcf8591.analog_read(PCF8591.AIN1))
          # print("AIN2 ", pcf8591.analog_read(PCF8591.AIN2))
          # print("AIN3 ", pcf8591.analog_read(PCF8591.AIN3))
      
          # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
          pcf8591.analog_write(AIN0)
      
          # Wait for 0.2 seconds before the next read
          time.sleep(0.2)
