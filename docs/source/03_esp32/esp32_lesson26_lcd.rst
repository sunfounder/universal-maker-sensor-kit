.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson26_lcd:

レッスン26: I2C LCD 1602
==================================

このレッスンでは、ESP32開発ボードを使用してI2Cインターフェースを備えた16x2液晶ディスプレイ（LCD）にメッセージを表示する方法を学びます。LiquidCrystal I2Cライブラリを使用してLCDを初期化し、画面の2行に「Hello world!」と「LCD Tutorial」を表示する方法を説明します。このチュートリアルは初心者に最適で、LCDインターフェースの実践的な経験を提供し、Arduinoプログラミングでの出力操作の理解を深めることができます。

必要な部品
--------------------------

このプロジェクトには以下の部品が必要です。

すべての部品が揃ったキットを購入すると便利です。リンクはこちら：

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

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_26_LCD1602_esp32_bb.png
    :width: 100%


コード
---------------------------

.. note::
   ライブラリをインストールするには、Arduino Library Managerを使用して **"LiquidCrystal I2C"**を検索し、インストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3c6bcc49-9030-4539-8220-4ff3c484814c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. ライブラリのインクルードとLCDの初期化:
   LiquidCrystal I2Cライブラリをインクルードして、LCDインターフェース用の関数とメソッドを提供します。その後、I2Cアドレス、列数、および行数を指定して、LiquidCrystal_I2Cクラスを使用してLCDオブジェクトを作成します。

   .. note::
      ライブラリをインストールするには、Arduino Library Managerを使用して **"LiquidCrystal I2C"**を検索し、インストールしてください。

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. セットアップ関数:
   ``setup()`` 関数は、ESP32開発ボードの起動時に一度だけ実行されます。この関数では、LCDを初期化し、クリアし、バックライトをオンにします。その後、LCDに2つのメッセージを表示します。

   .. code-block:: arduino

      void setup() {
        lcd.init();       // initialize the LCD
        lcd.clear();      // clear the LCD display
        lcd.backlight();  // Make sure backlight is on
      
        // Print a message on both lines of the LCD.
        lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
        lcd.print("LCD Tutorial");
      }