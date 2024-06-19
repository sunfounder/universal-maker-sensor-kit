
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _uno_bluetooth_lcd:

レッスン46: Bluetooth LCD
=============================================================

このプロジェクトでは、Arduino UNOボードに接続されたBluetoothモジュールを介してメッセージを受信し、それらのメッセージをLCD画面に表示します。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式キットを購入するのが便利です。こちらのリンクをご覧ください:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_jdy31`
        - \-

配線
---------------------------

.. image:: img/Lesson_46_Bluetooth_lcd_uno_bb.png
    :width: 100%

コード
---------------------------

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ae00239d-f273-4686-b01d-f20487892640/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

アプリとBluetoothモジュールの接続
-----------------------------------------------
"Serial Bluetooth Terminal"というアプリを使用して、BluetoothモジュールからArduinoにメッセージを送信できます。

a. **Serial Bluetooth Terminalのインストール**

   Google Playにアクセスして、|link_serial_bluetooth_terminal| をダウンロードしてインストールします。


b. **Bluetoothの接続**

   まず、スマートフォンで**Bluetooth**をオンにします。
   
      .. image:: img/09-app_1_shadow.png
         :width: 60%
         :align: center
   
   スマートフォンの **Bluetooth設定** に移動し、 **JDY-31-SPP** のような名前を探します。
   
      .. image:: img/09-app_2_shadow.png
         :width: 60%
         :align: center
   
   それをクリックした後、ポップアップウィンドウで **ペア** リクエストに同意します。ペアリングコードを求められた場合は、「1234」と入力してください。
   
      .. image:: img/09-app_3_shadow.png
         :width: 60%
         :align: center

c. **Bluetoothモジュールとの通信**

   Serial Bluetooth Terminalを開き、「JDY-31-SPP」に接続します。

   .. image:: img/00-bluetooth_serial_4_shadow.png 

d. **コマンドの送信**

   Serial Bluetooth Terminalアプリを使用して、Bluetooth経由でArduinoにメッセージを送信します。Bluetoothに送信されたメッセージはLCDに表示されます。

   .. image:: img/15-lcd_shadow.png
      :width: 100%
      :align: center



コード解析
---------------------------

.. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャを使用して**"LiquidCrystal I2C"**を検索し、ライブラリをインストールしてください。

#. LCDの設定

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

   このコードセグメントでは、LiquidCrystal_I2Cライブラリをインクルードし、I2Cアドレスを ``0x27`` としてLCDモジュールを初期化し、LCDが ``16`` 列と ``2`` 行であることを指定します。

#. Bluetooth通信の設定

   .. code-block:: arduino

      #include <SoftwareSerial.h>
      const int bluetoothTx = 3;
      const int bluetoothRx = 4;
      SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);

   ここでは、SoftwareSerialライブラリをインクルードし、JDY-31 Bluetoothモジュールがピン3（TX）とピン4（RX）を使用してArduinoと通信できるようにします。

#. 初期化

   .. code-block:: arduino

      void setup() {
         lcd.init();
         lcd.clear();
         lcd.backlight();

         Serial.begin(9600);
         bleSerial.begin(9600);
      }

   ``setup()``関数は、LCDを初期化し、既存のコンテンツをクリアします。また、LCDのバックライトをオンにします。シリアルモニタおよびBluetoothモジュールとの通信は、どちらもボーレート ``9600`` で開始されます。

#. メインループ

   .. code-block:: arduino

      void loop() {
         String data;

         if (bleSerial.available()) {
            data += bleSerial.readString();
            data = data.substring(0, data.length() - 2);
            Serial.print(data);

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(data);
         }

         if (Serial.available()) {
            bleSerial.write(Serial.read());
         }
      }

   これはArduinoプログラムのメインの動作ループです。Bluetoothモジュールおよびシリアルモニタからのデータの受信を継続的にチェックします。Bluetoothデバイスからデータが受信されると、それが処理され、シリアルモニタに表示され、LCDに表示されます。シリアルモニタにデータが入力されると、そのデータはBluetoothモジュールに送信されます。
