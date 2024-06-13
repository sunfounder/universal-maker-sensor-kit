.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pi_lesson26_lcd:

レッスン26: I2C LCD 1602
==================================

このレッスンでは、Raspberry Piを使用してLCDスクリーンにテキストを表示する基本を学びます。I2Cインターフェースを使用して標準のLCDをRaspberry Piに接続する方法から始めます。Raspberry PiのモデルやI2Cアドレスなど、簡単なパラメータでLCDを設定する方法を学びます。その後、「Hello World!」のようなメッセージを画面に表示するための基本的なPythonスクリプトの書き方を説明します。このシンプルなプロジェクトは初心者向けで、ハードウェアをRaspberry Piに接続し、基本的なPythonプログラミングの基礎を提供します。

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


配線
---------------------------

.. image:: img/Lesson_26_LCD1602_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   import time
   from LCD import LCD

   # Initialize the LCD with specific parameters: Raspberry Pi revision, I2C address, and backlight status
   lcd = LCD(2, 0x27, True)  # Using Raspberry Pi revision 2, I2C address 0x27, backlight enabled

   # Display messages on the LCD
   lcd.message("Hello World!", 1)        # Display 'Hello World!' on line 1
   lcd.message("    - Sunfounder", 2)    # Display '    - Sunfounder' on line 2

   # Keep the messages displayed for 5 seconds
   time.sleep(5)

   # Clear the LCD display
   lcd.clear()

コード解析
---------------------------

#. ライブラリのインポート
   
   遅延を作成するための ``time`` モジュールと、LCDを制御するための ``LCD`` モジュールをインポートします。

   ``LCD``ライブラリの詳細については、|link_lcd1602_python_driver_pi|を参照してください。

   .. code-block:: python

      import time
      from LCD import LCD

#. LCDの初期化
   
   特定のパラメータを使用して ``LCD`` オブジェクトを作成します。Raspberry Piのリビジョン、LCDのI2Cアドレス、およびバックライトの状態です。この場合、Raspberry Piのリビジョン2（およびそれ以降）、I2Cアドレス0x27、バックライトは有効です。

   .. code-block:: python

      lcd = LCD(2, 0x27, True)

#. LCDにメッセージを表示
   
   ``LCD``オブジェクトの ``message`` メソッドを使用してLCDにテキストを表示します。最初の引数はテキスト、2番目の引数は行番号です。

   .. code-block:: python

      lcd.message("Hello World!", 1)
      lcd.message("    - Sunfounder", 2)

#. メッセージを表示したままにする
   
   プログラムを5秒間一時停止し、この間LCDにメッセージを表示します。

   .. code-block:: python

      time.sleep(5)

#. LCDディスプレイをクリアする
   
   遅延の後、 ``LCD`` オブジェクトの ``clear`` メソッドを使用してディスプレイをクリアします。

   .. code-block:: python

      lcd.clear()

