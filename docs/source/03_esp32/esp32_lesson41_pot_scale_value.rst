.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_potentiometer_scale_value:

レッスン41: ポテンショメータのスケール値
=============================================================

このプロジェクトでは、ポテンショメータの値を読み取り、I2Cインターフェースを備えたLCD 1620に表示することに焦点を当てます。
さらに、その値はシリアルモニタにも送信され、リアルタイムで監視できます。
このプロジェクトの特徴的な側面は、ポテンショメータの値をLCDに可変長バーとして表示することです。
バーの長さはポテンショメータの読み取り値に比例します。



必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全体のキットを購入するのが便利です。リンクはこちらです:

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
    *   - :ref:`cpn_potentiometer`
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_41_Potentiometer_scale_value_esp32_bb.png
    :width: 100%

コード
---------------------------

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/407cf491-e932-4334-a3f3-e04f7309c941/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

   コード解析
---------------------------

このプロジェクトの核心機能は、ポテンショメータの値を継続的に読み取り、その値をスケール範囲（0-16）にマップし、結果を数値およびグラフィカルにLCDに表示することです。実装では、読み取りの大きな変化が発生した場合にのみ表示を更新することで、表示の揺れを最小限に抑え、スムーズなビジュアル体験を維持します。

1. **ライブラリのインクルードと初期化**：

   .. code-block:: arduino
   
      // Required libraries for I2C and LCD operations
      #include <Wire.h>
      #include <LiquidCrystal_I2C.h>

      // Initialize LCD at I2C address 0x27 with 16 columns and 2 rows
      LiquidCrystal_I2C lcd(0x27, 16, 2);

   このセグメントでは、I2C通信とLCD制御に必要なライブラリを組み込みます。次に、I2Cアドレスが ``0x27`` で、 ``16列``と ``2行``の寸法を指定したLCDインスタンスを初期化します。

2. **変数の宣言**：

   .. code-block:: arduino
      // Variables to hold the potentiometer readings
      int lastRead = 0;     // Previous potentiometer value
      int currentRead = 0;  // Current potentiometer value

   変数 ``lastRead`` と ``currentRead`` は、異なる時点でのポテンショメータの読み取り値を追跡するために使用されます。

3. **setup()関数**：

   .. code-block:: arduino
   
      void setup() {
        lcd.init();          // Initiates the LCD
        lcd.backlight();     // Activates the LCD's backlight
        Serial.begin(9600);  // Commences serial communication at 9600 baud
      }

   この関数は、LCDを準備し、シリアル通信を開始して、プロジェクトの動作環境を整えます。

4. **メインループ**：

   .. code-block:: arduino
   
      void loop() {
         // Read the current potentiometer value
         int currentRead = analogRead(35);

         // Map the read value from 0-4096 to 0-16
         int barLength = map(currentRead, 0, 4096, 0, 16);

         // Update LCD only if the difference between current and last reading is greater than 2 to avoid jitter
         if (abs(lastRead - currentRead) > 2) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Value:");
            lcd.setCursor(7, 0);
            lcd.print(currentRead);
            Serial.println(currentRead);

            // Display a bar on the second row of LCD proportional to the potentiometer value
            for (int i = 0; i < barLength; i++) {
               lcd.setCursor(i, 1);
               lcd.print(char(255));
            }
         }
         // Update the last read value for the next iteration
         lastRead = currentRead;

         // Introduce a delay for a stable reading
         delay(200);
      }

   * ポテンショメータを読み取り、その値を視覚的表現に適したスケールに変換します。
   * 意味のある変化が検出されたときにのみLCDを更新し、数値と対応するバーグラフを表示します。
   * 読み取り値をシリアルモニタにも送信して外部から観察できるようにします。
   * 安定性と応答性を確保するために、繰り返し間に短い遅延を導入します。
