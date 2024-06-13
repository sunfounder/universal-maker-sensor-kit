.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson26_lcd:

レッスン 26: I2C LCD 1602
==================================

このレッスンでは、Raspberry Pi Pico WにI2C LCD 1602ディスプレイを接続する方法を学びます。I2C通信の設定方法、MicroPythonを使用してLCDにメッセージを表示およびクリアする方法を理解します。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

キット全体を購入すると便利です。リンクはこちら：

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. note::
   LCDモジュールが正常に動作するようにするために、PicoのVBUSピンを使用して電源を供給してください。

.. image:: img/Lesson_26_LCD1602_Module_pico_bb.png
    :width: 100%

コード
---------------------------

.. code-block:: python

   from machine import I2C, Pin
   from lcd1602 import LCD
   import time
   
   # Initialize I2C communication;
   # Set SDA to pin 20, SCL to pin 21, and frequency to 400kHz
   i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)
   
   # Create an LCD object for interfacing with the LCD1602 display
   lcd = LCD(i2c)
   
   # Display the first message on the LCD
   # Use '\n' to create a new line.
   string = "SunFounder\n    LCD Tutorial"
   lcd.message(string)
   # Wait for 2 seconds
   time.sleep(2)
   # Clear the display
   lcd.clear()
   
   # Display the second message on the LCD
   string = "Hello\n  World!"
   lcd.message(string)
   # Wait for 5 seconds
   time.sleep(5)
   # Clear the display before exiting
   lcd.clear()


コード解析
---------------------------

#. I2C通信の設定

   ``machine``モジュールを使用してI2C通信を設定します。SDA（シリアルデータ）ピンとSCL（シリアルクロック）ピン（それぞれピン20と21）が定義され、I2Cの周波数（400kHz）が設定されます。

   .. code-block:: python
      
      from machine import I2C, Pin
      i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)

#. LCDディスプレイの初期化

   ``lcd1602``モジュールの ``LCD``クラスをインスタンス化します。このクラスはI2Cを介してLCDディスプレイとの通信を処理します。 ``i2c``オブジェクトを使用して ``LCD``オブジェクトが作成されます。

   ``lcd1602``ライブラリの使用法については、 ``lcd1602.py``を参照してください。

   .. code-block:: python
      
      from lcd1602 import LCD
      lcd = LCD(i2c)

#. LCDへのメッセージ表示

   ``LCD``オブジェクトの ``message``メソッドを使用して、画面にテキストを表示します。 ``\n`` 文字はLCD上で改行を作成します。  ``time.sleep()``関数は、指定された秒数だけ実行を一時停止します。

   .. code-block:: python
      
      string = "SunFounder\n    LCD Tutorial"
      lcd.message(string)
      time.sleep(2)
      lcd.clear()

#. ディスプレイのクリア

   ``LCD``オブジェクトの ``clear`` メソッドを呼び出して、ディスプレイからテキストを消去します。

   .. code-block:: python
      
      lcd.clear()

#. 2つ目のメッセージ表示

   新しいメッセージが表示され、遅延の後、再度画面がクリアされます。

   .. code-block:: python
      
      string = "Hello\n  World!"
      lcd.message(string)
      time.sleep(5)
      lcd.clear()