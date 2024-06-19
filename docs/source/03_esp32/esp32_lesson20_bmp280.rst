.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson20_bmp280:

レッスン20: 温度、湿度、気圧センサー (BMP280)
====================================================================

このレッスンでは、ESP32開発ボードを使用してBMP280センサーで大気圧、温度、およびおおよその高度を測定する方法を学びます。センサーをAdafruit BMP280ライブラリとインターフェースし、読み取り値をシリアルモニタに表示する方法を説明します。このチュートリアルは、環境センサーとデータロギングの理解を深めたい方に最適です。

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
    *   - :ref:`cpn_bmp280`
        - |link_bmp280_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_20_bmp280_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/25c4b695-7d09-47f5-9385-61d239afa214/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. ライブラリのインクルードと初期化。必要なライブラリがインクルードされ、I2Cインターフェースを使用してBMP280センサーが初期化されます。

   .. note::
      ライブラリをインストールするには、Arduino Library Managerを使用して **"Adafruit BMP280"**を検索し、インストールしてください。

   - Adafruit BMP280ライブラリ: このライブラリは、BMP280センサー用の使いやすいインターフェースを提供し、温度、気圧、および高度を読み取ることができます。
   - Wire.h: I2C通信に使用します。

   .. raw:: html
    
    <br/>

   .. code-block:: arduino
    
      #include <Wire.h>
      #include <Adafruit_BMP280.h>
      #define BMP280_ADDRESS 0x76
      Adafruit_BMP280 bmp;  // use I2C interface

2. ``setup()`` 関数はシリアル通信を初期化し、BMP280センサーをチェックして、デフォルト設定でセンサーをセットアップします。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        while (!Serial) delay(100);
        Serial.println(F("BMP280 test"));
        unsigned status;
        status = bmp.begin(BMP280_ADDRESS);
        // ... (rest of the setup code)

3. ``loop()`` 関数は、BMP280センサーから温度、気圧、および高度のデータを読み取ります。このデータはシリアルモニタに出力されます。

   .. code-block:: arduino

      void loop() {
        // ... (read and print temperature, pressure, and altitude data)
        delay(2000);  // 2-second delay between readings.
      }
