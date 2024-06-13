.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson27_oled:

レッスン 27: OLEDディスプレイモジュール (SSD1306)
================================================

このレッスンでは、Raspberry Pi Pico Wを使用してOLEDディスプレイモジュール（SSD1306）にテキストやグラフィックを表示する方法を学びます。I2C通信を設定し、MicroPythonを使用してPico Wをプログラムし、OLEDディスプレイを制御します。簡単なテキストメッセージを表示する練習を行います。


必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. note:: 
   OLEDモジュールが正常に動作するためには、PicoのVBUSピンを使用して電源を供給してください。

.. image:: img/Lesson_27_oled_pico_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from machine import Pin, I2C
   import ssd1306
   import time
   
   # setup the I2C communication
   i2c = I2C(0, sda=Pin(20), scl=Pin(21))
   
   # Set up the OLED display (128x64 pixels) on the I2C bus
   # SSD1306_I2C is a subclass of FrameBuffer. FrameBuffer provides support for graphics primitives.
   # http://docs.micropython.org/en/latest/pyboard/library/framebuf.html
   oled = ssd1306.SSD1306_I2C(128, 64, i2c)
   
   # Clear the display by filling it with white and then showing the update
   oled.fill(1)
   oled.show()
   time.sleep(1)  # Wait for 1 second
   
   # Clear the display again by filling it with black
   oled.fill(0)
   oled.show()
   time.sleep(1)  # Wait for another second
   
   # Display text on the OLED screen
   oled.text('Hello,', 0, 0)  # Display "Hello," at position (0, 0)
   oled.text('sunfounder.com', 0, 16)  # Display "sunfounder.com" at position (0, 16)
   
   # The following line sends what to show to the display
   oled.show()

コード解析
---------------------------

#. **I2C通信の初期化**:

   このコードセグメントは、I2C通信プロトコルを設定します。I2Cはデバイス間の通信に使用される標準的なプロトコルで、SDA（データライン）とSCL（クロックライン）の2本のラインを使用します。
   
   .. code-block:: python

      from machine import Pin, I2C
      i2c = I2C(0, sda=Pin(20), scl=Pin(21))

#. **OLEDディスプレイの設定**:

   ここでは、I2Cプロトコルを使用してSSD1306 OLEDディスプレイを初期化します。パラメータの128と64は、それぞれディスプレイの幅と高さをピクセル単位で定義しています。

   ``ssd1306``ライブラリの詳細については、|link_micropython_ssd1306_driver|をご参照ください。

   .. code-block:: python

      import ssd1306
      oled = ssd1306.SSD1306_I2C(128, 64, i2c)

#. **ディスプレイのクリア**:

   ディスプレイは、白（1）で塗りつぶしてから ``oled.show()`` で更新することによりクリアされます。 ``time.sleep(1)`` コマンドで1秒の遅延を追加します。その後、黒（0）で塗りつぶして再度ディスプレイをクリアします。

   SSD1306_I2Cは、グラフィックプリミティブをサポートするFrameBufferのサブクラスです。その他のパターンを表示したい場合は、|link_FrameBuffer_doc|をご参照ください。

   .. code-block:: python
      
      oled.fill(1)
      oled.show()
      time.sleep(1)
      oled.fill(0)
      oled.show()
      time.sleep(1)

#. **テキストの表示**:

   ``oled.text``メソッドを使用して、画面にテキストを表示します。パラメータは、表示するテキストと画面上のx、y座標です。最後に ``oled.show()`` でディスプレイを更新してテキストを表示します。

   .. code-block:: python

      oled.text('Hello,', 0, 0)
      oled.text('sunfounder.com', 0, 16)
      oled.show()