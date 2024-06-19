.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson27_oled:

レッスン27: OLEDディスプレイモジュール (SSD1306)
=================================================

このレッスンでは、Adafruit SSD1306およびGFXライブラリを使用して、ESP32開発ボードでOLEDディスプレイをセットアップし、利用する方法を学びます。異なるサイズのテキストの表示、テキストの色の反転、スクロールテキストアニメーションの作成、およびカスタムビットマップグラフィックの描画をカバーします。このプロジェクトは、インタラクティブな電子機器をマイクロコントローラーで開発するスキルを向上させたい人に最適な、ディスプレイ技術の高度な紹介を提供します。

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
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_27_oled_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/33f2fdd0-af4e-4438-bacf-982894bb8ac4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. **ライブラリのインクルードと初期定義**:
   OLEDとインターフェースするための必要なライブラリをインクルードします。その後、OLEDの寸法とI2Cアドレスに関する定義が提供されます。

   - **Adafruit SSD1306**: このライブラリはSSD1306 OLEDディスプレイとのインターフェースを支援するために設計されており、ディスプレイの初期化、設定の制御、コンテンツの表示方法を提供します。
   - **Adafruit GFX Library**: これは、テキストの表示、色の生成、形状の描画など、さまざまな画面上でのグラフィック操作のためのコアライブラリです。

   .. note:: 
      ライブラリをインストールするには、Arduino Library Managerを使用して **"Adafruit SSD1306"** および **"Adafruit GFX"** を検索し、インストールしてください。

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // OLED display width, in pixels
      #define SCREEN_HEIGHT 64  // OLED display height, in pixels

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **ビットマップデータ**:
   OLEDスクリーンにカスタムアイコンを表示するためのビットマップデータ。このデータは、OLEDが解釈できる形式で画像を表します。

   オンラインツール|link_image2cpp|を使用して、画像を配列に変換できます。

   ``PROGMEM``キーワードは、配列がArduinoマイクロコントローラーのプログラムメモリに格納されていることを示します。プログラムメモリ（PROGMEM）にデータを格納することは、大量のデータをRAMではなくプログラムメモリに保存するために役立ちます。

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **セットアップ関数（初期化と表示）**:
   ``setup()`` 関数はOLEDを初期化し、一連のパターン、テキスト、およびアニメーションを表示します。

   .. code-block:: arduino

      void setup() {
         ...  // Serial initialization and OLED object initialization
         ...  // Displaying various text, numbers, and animations
      }