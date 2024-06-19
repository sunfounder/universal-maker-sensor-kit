
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_bluetooth_traffic_light:

レッスン47: Bluetooth信号機
=============================================================

このプロジェクトは、Bluetooth通信を使用して信号機（赤、黄、緑のLED）を制御することを目的としています。ユーザーはBluetoothデバイスから文字（'R'、'Y'、または'G'）を送信できます。Arduinoがこれらの文字のいずれかを受信すると、対応するLEDが点灯し、他の2つのLEDが消灯します。

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
    *   - :ref:`cpn_traffic`
        - \-
    *   - :ref:`cpn_jdy31`
        - \-

配線
---------------------------

.. image:: img/Lesson_47_Bluetooth_traffic_light_uno_bb.png
    :width: 100%

コード
---------------------------

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5b9bd574-c807-4370-8e09-61f5f5a60b42/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

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

   Serial Bluetooth Terminalアプリを使用して、Bluetooth経由でArduinoにコマンドを送信します。赤色のライトを点灯させるには「R」、黄色には「Y」、緑色には「G」を送信します。

   .. image:: img/16-R_shadow.png 
      :width: 85%
      :align: center

   .. image:: img/16-Y_shadow.png 
      :width: 85%
      :align: center

   .. image:: img/16-G_shadow.png 
      :width: 85%
      :align: center

コード解析
---------------------------

#. 初期化とBluetooth設定

   .. code-block:: arduino

      // Set up Bluetooth module communication
      #include <SoftwareSerial.h>
      const int bluetoothTx = 3;
      const int bluetoothRx = 4;
      SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);
   
   まず、Bluetooth通信をサポートするためにSoftwareSerialライブラリをインクルードします。次に、BluetoothモジュールのTXおよびRXピンを定義し、Arduinoのピン3および4に割り当てます。最後に、Bluetooth通信のための``bleSerial``オブジェクトを初期化します。

#. LEDピンの定義

   .. code-block:: arduino

      // Pin numbers for each LED
      const int rledPin = 10;  //red
      const int yledPin = 11;  //yellow
      const int gledPin = 12;  //green

   ここでは、LEDが接続されているArduinoのピンを定義しています。赤色LEDはピン10、黄色はピン11、緑色はピン12に接続されています。

#. setup()関数

   .. code-block:: arduino

      void setup() {
         pinMode(rledPin, OUTPUT);
         pinMode(yledPin, OUTPUT);
         pinMode(gledPin, OUTPUT);

         Serial.begin(9600);
         bleSerial.begin(9600);
      }

   ``setup()``関数では、LEDピンを ``OUTPUT`` として設定します。また、Bluetoothモジュールおよびデフォルトのシリアル（コンピュータに接続されている）とのシリアル通信をボーレート9600で開始します。

#. Bluetooth通信のためのメインループ

   .. code-block:: arduino

      void loop() {
         while (bleSerial.available() > 0) {
            character = bleSerial.read();
            Serial.println(character);

            if (character == 'R') {
               toggleLights(rledPin);
            } else if (character == 'Y') {
               toggleLights(yledPin);
            } else if (character == 'G') {
               toggleLights(gledPin);
            }
         }
      }

   メインの ``loop()`` 内では、Bluetoothモジュールからデータが利用可能かどうかを継続的にチェックします。データを受信した場合、その文字を読み取り、シリアルモニタに表示します。受信した文字（R、Y、またはG）に応じて、 ``toggleLights()`` 関数を使用して対応するLEDを点灯します。

#. LED切り替え関数

   .. code-block:: arduino

      void toggleLights(int targetLight) {
         digitalWrite(rledPin, LOW);
         digitalWrite(yledPin, LOW);
         digitalWrite(gledPin, LOW);

         digitalWrite(targetLight, HIGH);
      }

   ``toggleLights()``関数は、まずすべてのLEDを消灯します。すべてが消灯していることを確認した後、指定されたターゲットLEDを点灯させます。これにより、常に1つのLEDのみが点灯するようにします。
