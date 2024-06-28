.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson27_oled:

レッスン27: OLEDディスプレイモジュール (SSD1306)
=================================================

このレッスンでは、Arduino UnoボードをプログラムしてOLEDディスプレイ（SSD1306）を制御する方法を学びます。Adafruit SSD1306とGFXライブラリを使用して、テキスト、数字、およびスクロールアニメーションを画面に表示する方法を説明します。このプロジェクトは、Arduino環境を使用して小型スクリーンにグラフィックとテキストを表示する知識を深めたい人に最適です。

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

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_oled`
        - \-


配線
---------------------------

.. image:: img/Lesson_27_OLED_circuit_uno_bb.png
    :width: 100%


コード
---------------------------

.. note:: 
   ライブラリをインストールするには、Arduino Library Managerを使用し、 **"Adafruit SSD1306"**と **"Adafruit GFX"** を検索してインストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b2617291-5326-4d12-812b-78c45ced7516/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. **ライブラリのインクルードと初期定義**:
   OLEDとのインターフェース用の必要なライブラリをインクルードします。その後、OLEDの寸法とI2Cアドレスに関する定義を行います。

   - **Adafruit SSD1306**: このライブラリはSSD1306 OLEDディスプレイとのインターフェースを助けるために設計されています。ディスプレイの初期化、設定の制御、およびコンテンツの表示に役立つメソッドを提供します。
   - **Adafruit GFX Library**: これは、テキストの表示、色の生成、形の描画など、さまざまなスクリーン（OLEDを含む）に対応するコアグラフィックスライブラリです。

   .. note:: 
      ライブラリをインストールするには、Arduino Library Managerを使用し、 **"Adafruit SSD1306"**と **"Adafruit GFX"** を検索してインストールしてください。

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
   OLEDスクリーンにカスタムアイコンを表示するためのビットマップデータ。このデータは、OLEDが解釈できるフォーマットで画像を表します。

   オンラインツール |link_image2cpp| を使用して、画像を配列に変換できます。

   ``PROGMEM`` キーワードは、配列がArduinoマイクロコントローラのプログラムメモリに格納されることを示します。データが多い場合、RAMではなくプログラムメモリ（PROGMEM）にデータを格納することが役立ちます。

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **セットアップ関数（初期化と表示）**:
   ``setup()`` 関数はOLEDを初期化し、一連のパターン、テキスト、およびアニメーションを表示します。

   .. code-block:: arduino

      void setup() {
         ...  // Serial initialization and OLED object initialization
         ...  // Displaying various text, numbers, and animations
      }