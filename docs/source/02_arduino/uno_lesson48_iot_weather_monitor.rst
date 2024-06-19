.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _uno_iot_weather_monito:

レッスン48: ThingSpeakを使用したウェザーモニター
=============================================================

このプロジェクトでは、大気圧センサーを使用して温度と気圧のデータを収集します。収集されたデータは、ESP8266モジュールとWi-Fiネットワークを介して、一定時間間隔でThingSpeakクラウドプラットフォームに送信されます。

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
    *   - :ref:`cpn_esp8266`
        - \-
    *   - :ref:`cpn_bmp280`
        - \-

配線
---------------------------

.. image:: img/Lesson_48_Iot_weather_monitor_uno_bb.png
    :width: 100%

ThingSpeakの設定
-----------------------------

|link_thingspeak| ™は、クラウドでライブデータストリームを集約、可視化、分析できるIoT分析プラットフォームサービスです。ThingSpeakは、デバイスから投稿されたデータを即座に可視化する機能を提供します。MATLAB®コードをThingSpeakで実行できるため、データが到着するたびにオンラインで分析および処理を行うことができます。ThingSpeakは、分析が必要なIoTシステムのプロトタイピングおよび概念実証によく使用されます。

.. image:: img/signup_tsp_ml.png
    :width: 80% 
    :align: center

.. raw:: html
    
    <br/>  

**1) ThingSpeakアカウントの作成**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

まず最初に、ThingSpeakのアカウントを作成する必要があります。MATLABとの連携により、MathWorksの資格情報を使用して|link_thingspeak|にログインできます。

アカウントをお持ちでない場合は、MathWorksのアカウントを作成し、ThingSpeakアプリケーションにログインする必要があります。

.. image:: img/05-thingspeak_signup_shadow.png
    :width: 50%
    :align: center

**2) チャンネルの作成**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

ログイン後、「Channels」>「My Channels」に進み、「New Channel」をクリックして新しいチャンネルを作成し、データを保存します。

.. image:: img/05-thingspeak_channel_1_shadow.png
    :width: 95%
    :align: center

このプロジェクトでは、「 **Weather Monitor** 」というチャンネルを作成し、 **Field 1** に「 **Temperature** 」、 **Field 2** に「 **Atmospheric Pressure** 」を設定する必要があります。

.. image:: img/05-thingspeak_channel_2_shadow.png
    :width: 95%
    :align: center

.. raw:: html
    
    <br/>  

コード
--------------------------- 

#. ``universal-maker-sensor-kit\arduino_uno\Lesson_48_Iot_Weather_Monitor``のパスにある ``Lesson_48_Iot_Weather_Monitor.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

   .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャを使用して **"Adafruit BMP280"**を検索し、インストールしてください。

   .. raw:: html
      
      <iframe src=https://create.arduino.cc/editor/sunfounder01/59eeae43-5dcc-46d7-833f-65fd2bdb3603/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 使用するWiFiの ``mySSID`` と ``myPWD`` を入力する必要があります。

   .. code-block:: arduino

      String mySSID = "your_ssid";     // WiFi SSID
    String myPWD = "your_password";  // WiFi Password

#. また、ThingSpeakチャネルAPIキーを使用して ``myAPI`` を修正する必要があります。

   .. code-block:: arduino
    
      String myAPI = "xxxxxxxxxxxx";  // API Key

   .. image:: img/05-thingspeak_api_shadow.png
       :width: 80%
       :align: center
   
   
   ここには **あなたのユニークなAPIキーが表示され、これは秘密にしておく必要があります** 。

#. 正しいボードとポートを選択した後、 **アップロード** ボタンをクリックします。

#. シリアルモニタを開き（ボーレートを **9600** に設定）、接続成功などのプロンプトが表示されるのを待ちます。

   .. image:: img/05-ready_1_shadow.png
          :width: 95%

   .. image:: img/05-ready_2_shadow.png
          :width: 95%

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
