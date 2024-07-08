
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_fun_direction_indicator:

レッスン53: 方向インジケーター
===========================================

このArduinoプロジェクトでは、OLEDディスプレイを初期化し、アナログピンA0とA1に接続されたジョイスティックから入力を読み取ります。ジョイスティックの位置を継続的に監視し、傾き方向を判断して、OLEDディスプレイに対応する矢印（上、下、左、右）または円（ジョイスティックが中心にある場合）を表示します。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

全キットを購入するのが便利です。リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称
        - キットに含まれるアイテム
        - リンク
    *   - ユニバーサルメーカセンサーキット
        - 94
        - |link_umsk|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネント紹介
        - 購入リンク

    *   - Arduino UNO R3またはR4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

配線
---------------------------

.. image:: img/Lesson_53_Direction_indicatorr_uno_bb.png
    :width: 100%

コード
---------------------------

.. note:: 
   ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、「Adafruit SSD1306」と「Adafruit GFX」を検索してインストールしてください。

.. raw:: html

    <iframe src="https://app.arduino.cc/sketches/c926f784-c6ac-4d4d-864c-d55aee9595b4?view-mode=embed" style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コード解析
---------------------------

#. 必要なライブラリのインクルード

   このプロジェクトでは、I2C通信のための``Wire.h``、グラフィックプリミティブのための``Adafruit_GFX.h``、およびOLEDディスプレイ制御のための``Adafruit_SSD1306.h``の3つのライブラリを使用します。
 
   .. code-block:: arduino
 
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

#. 定数の定義とOLEDディスプレイオブジェクトの作成

   OLEDディスプレイの寸法とアドレスの定数が定義されます。これらのパラメータを使用してOLEDディスプレイオブジェクトが作成されます。
 
   .. code-block:: arduino
     
      #define SCREEN_WIDTH 128  // OLEDディスプレイの幅（ピクセル単位）
      #define SCREEN_HEIGHT 64  // OLEDディスプレイの高さ（ピクセル単位）
      #define OLED_RESET -1  // リセットピン（Arduinoリセットピンを共有する場合は-1）
      #define SCREEN_ADDRESS 0x3C
      Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#. ジョイスティック用のピン定義としきい値

   ジョイスティックにはアナログピンA0とA1が使用され、ジョイスティックが中心にあるかどうかを判断するためのしきい値が定義されます。
 
   .. code-block:: arduino
 
      const int xPin = A0;  // VRXが接続されるピン
      const int yPin = A1;  // VRYが接続されるピン
      const int threshold = 50;  // ジョイスティックを中心と見なすしきい値
 
#. セットアップ関数：シリアル通信とOLEDディスプレイの初期化

   デバッグのためにシリアル通信が初期化され、OLEDディスプレイが初期化されてクリアされます。
 
   .. code-block:: arduino
 
      void setup() {
        Serial.begin(9600);
        if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
          Serial.println(F("SSD1306 allocation failed"));
          for (;;);
        }
        display.clearDisplay();
      }
 
#. メインループ：ジョイスティックの値を読み取り、方向を判断し、形状を表示

   メインループでは、ジョイスティックの値を読み取り、これらの値に基づいて方向を判断し、OLEDディスプレイに対応する形状を表示します。

   .. image:: img/Lesson_53_Code_Analysis.png
    :width: 85%

   .. raw:: html
   
       <br/><br/>
 
   .. code-block:: arduino
 
      void loop() {
        display.clearDisplay();
        int xValue = analogRead(xPin);
        int yValue = analogRead(yPin) * -1;
        Serial.print("X: ");
        Serial.print(xValue);
        Serial.print("|Y: ");
        Serial.println(-yValue);
  
        float yLine1 = line1(xValue);
        float yLine2 = line2(xValue);
  
        int relX = xValue - 512;
        int relY = -yValue - 512;
  
        if (abs(relX) < threshold && abs(relY) < threshold) {
          drawCircle();
        } else if (yValue > yLine1 && yValue > yLine2) {
          drawUpArrow();
        } else if (yValue < yLine1 && yValue < yLine2) {
          drawDownArrow();
        } else if (yValue < yLine1 && yValue > yLine2) {
          drawRightArrow();
        } else if (yValue > yLine1 && yValue < yLine2) {
          drawLeftArrow();
        }
  
        display.display();
        delay(80);
      }
 
#. ヘルパー関数：ラインの計算と形状の描画

   これらの関数は、方向判断に使用されるラインを計算し、OLEDディスプレイに形状を描画するのに役立ちます。
 
   .. code-block:: arduino
 
      float line1(float x) {
        return x - 1023;
      }
  
      float line2(float x) {
        return -x;
      }
  
      void drawUpArrow() {
        display.fillTriangle(49, 30, 64, 15, 79, 30, WHITE);
        display.fillRect(59, 30, 10, 20, WHITE);
      }
  
      void drawDownArrow() {
        display.fillTriangle(49, 36, 64, 51, 79, 36, WHITE);
        display.fillRect(59, 16, 10, 20, WHITE);
      }
  
      void drawRightArrow() {
        display.fillTriangle(70, 15, 85, 30, 70, 45, WHITE);
        display.fillRect(50, 25, 20, 10, WHITE);
      }
  
      void drawLeftArrow() {
        display.fillTriangle(60, 15, 45, 30, 60, 45, WHITE);
        display.fillRect(60, 25, 20, 10, WHITE);
      }
  
      void drawCircle() {
        display.fillCircle(64, 32, 10, WHITE);
        display.fillCircle(64, 32, 8, BLACK);
      }
  
**参考資料**

- |link_adafruit_gfx_graphics_library|
