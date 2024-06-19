
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _uno_iot_flame:

レッスン50: Blynkを使用した火災警報システム
============================================================

この章では、Blynkを使用して家庭用火災警報システムのデモを作成する手順を案内します。火炎センサーを利用して、家庭内の火災を検出することができます。検出された値をBlynkに送信することで、インターネットを介してリモートで家庭の監視が可能になります。火災が発生した場合、Blynkはメールで迅速に通知します。

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
    *   - :ref:`cpn_flame`
        - \-

配線
---------------------------

.. image:: img/Lesson_50_Iot_flame_alert_system_uno_bb.png
    :width: 100%

Blynkの設定
-----------------------------

**1 テンプレートの作成**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

まず、Blynkにテンプレートを作成する必要があります。以下の手順に従って、 **"Flame Alert System"** テンプレートを作成してください。

.. image:: img/01-create_template_1_shadow.png
    :width: 70%
    :align: center

**HARDWARE** が **ESP8266** に設定されていることと、 **CONNECT TYPE** が **WiFi** に設定されていることを確認してください。

.. image:: img/01-create_template_2_shadow.png
    :width: 70%
    :align: center

.. raw:: html
    
    <br/>  

**2 データストリーム**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Datastream** ページで、タイプが **Virtual Pin** の **Datastream** を作成し、火炎センサーモジュールの値を取得します。

.. image:: img/01-datastream_1_shadow.png
    :width: 90%
    :align: center

**Virtual Pin** の名前を ``flame_sensor_value`` に設定します。 **DATA TYPE** を **Integer** に設定し、MIN と MAX を **0** と **1** に設定します。

.. image:: img/01-datastream_2_shadow.png
    :width: 90%
    :align: center

.. raw:: html
    
    <br/> 

**3 イベント**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

次に、火炎検出を記録し、メール通知を送信する **イベント** を作成します。

.. image:: img/01-event_1_shadow.png
    :width: 80%
    :align: center

.. note::
    設定を一貫性のあるものにすることをお勧めします。そうしないと、プロジェクトを実行するためにコードを修正する必要があるかもしれません。

**EVENT NAME** を ``flame_detection_alert`` に設定します。同時に、イベントトリガーの **DESCRIPTION** を設定して、送信されるメールの内容をカスタマイズできます。また、イベントトリガーの頻度制限を以下で設定できます。

.. image:: img/01-event_2_shadow.png
    :width: 80%
    :align: center

**Notifications** ページに移動し、メール設定を行います。

.. image:: img/01-event_3_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/> 

**4 Webダッシュボード**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

次に、Unoボードから送信されたセンサーデータを表示するために、 **Webダッシュボード** を設定する必要があります。

**Webダッシュボード**ページに **ラベルウィジェット** をドラッグアンドドロップします。

.. image:: img/01-web_dashboard_1_shadow.png
    :width: 100%
    :align: center

**ラベルウィジェット**の設定ページで、 **Datastream** を **flame_sensor_value(V0)** に設定します。次に、データの値に応じて **ウィジェット背景** の色を変えるように設定します。表示される値が1のときは緑色、0のときは赤色で表示されます。

.. image:: img/01-web_dashboard_2_shadow.png
    :width: 100%
    :align: center

.. image:: img/01-web_dashboard_3_shadow.png
    :width: 100%
    :align: center

.. raw:: html
    
    <br/> 

**5 テンプレートの保存**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

最後に、テンプレートを保存することを忘れないでください。

.. image:: img/01-save_template_shadow.png
    :width: 70%
    :align: center

テンプレートを編集する必要がある場合は、右上の編集ボタンをクリックしてください。

.. image:: img/01-save_template_2_shadow.png
    :width: 70%
    :align: center

.. raw:: html
    
    <br/> 

コード
----------------------- 

#. ``universal-maker-sensor-kit\arduino_uno\Lesson_50_Flame_alert_system`` パスにある ``Lesson_50_Flame_alert_system.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

   .. raw:: html
       
       <iframe src=https://create.arduino.cc/editor/sunfounder01/ef829dd7-337d-475d-908b-d118c6a93eef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Flame Detection Alertテンプレートを使用してBlynkデバイスを作成します。次に、 ``BLYNK_TEMPLATE_ID`` 、 ``BLYNK_TEMPLATE_NAME`` 、および ``BLYNK_AUTH_TOKEN`` を自分のものに置き換えます。

   .. code-block:: arduino
    
      #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
      #define BLYNK_TEMPLATE_NAME "Flame Alert System"
      #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"
   
   .. image:: img/01-create_device_1_shadow.png
    :width: 80%
    :align: center

   .. image:: img/01-create_device_2_shadow.png
    :width: 80%
    :align: center

   .. image:: img/01-create_device_3_shadow.png
    :width: 80%
    :align: center

   .. image:: img/01-create_device_4_shadow.png
    :width: 80%
    :align: center

#. 使用しているWiFiの ``ssid`` と ``password`` を入力する必要があります。

   .. code-block:: arduino

    char ssid[] = "your_ssid";
    char pass[] = "your_password";

#. 正しいボードとポートを選択した後、 **Upload** ボタンをクリックします。

#. シリアルモニターを開き（ボーレートを115200に設定）、接続成功などのプロンプトが表示されるのを待ちます。

   .. image:: img/01-ready_1_shadow.png
    :width: 80%
    :align: center

   .. note::

       接続時に ``ESP is not responding`` というメッセージが表示された場合、次の手順に従ってください。

       * 9Vバッテリーが接続されていることを確認してください。
       * RSTピンを1秒間GNDに接続してから外すことで、ESP8266モジュールをリセットしてください。
       * R4ボードのリセットボタンを押してください。

       上記の操作を3〜5回繰り返す必要がある場合がありますので、忍耐強く行ってください。

#. これで、Blynkは火炎センサーから読み取ったデータを表示します。ラベルウィジェットでは、火炎センサーが読み取った値が表示されます。表示される値が1のとき、ラベルの背景が緑色で表示されます。表示される値が0のとき、ラベルの背景が赤色で表示され、Blynkから警告メールが送信されます。

   .. image:: img/01-ready_2_shadow.png
    :width: 80%
    :align: center

#. モバイルデバイスでBlynkを使用する場合は、:ref:`blynk_mobile`を参照してください。

コード解析
---------------------------

1. **ライブラリの初期化**

   始める前に、Arduino、ESP8266 WiFiモジュール、およびBlynkアプリ間の通信のために必要なライブラリと設定を行います。このコードは、必要なライブラリを設定し、ArduinoとESP8266モジュールの間でソフトウェアシリアル接続を構成し、データ送信のための適切なボーレートを設定します。
   
   .. code-block:: arduino
   
       //Set debug prints on Serial Monitor
       #define BLYNK_PRINT Serial
   
       #include <ESP8266_Lib.h>               // Library for ESP8266
       #include <BlynkSimpleShieldEsp8266.h>  // Library for Blynk
   
       // Software Serial on Uno
       #include <SoftwareSerial.h>
       SoftwareSerial EspSerial(2, 3);  // RX, TX
       #define ESP8266_BAUD 115200      // Set the ESP8266 baud rate
       ESP8266 wifi(&EspSerial);

2. **BlynkとWiFiの設定**

   このプロジェクトがBlynkアプリと通信するためには、Wi-Fiネットワークに接続する必要があります。ここでクレデンシャルを指定します。
   
   .. code-block:: arduino

      // Template ID, Device Name and Auth Token are provided by the Blynk Cloud
      // See the Device Info tab, or Template settings
      #define BLYNK_TEMPLATE_ID "TMPxxxxxx"
      #define BLYNK_TEMPLATE_NAME "Flame Alert System"
      #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxx" 
      
      // Your WiFi credentials.
      // Set password to "" for open networks.
      char ssid[] = "your_ssid";
      char pass[] = "your_password";

3. **センサーピンとタイマーの宣言**

   火炎センサーのピン番号を定義します。
   Blynkライブラリには組み込みのタイマーがあり、タイマーオブジェクトを作成します。詳細は |link_blynk_timer_intro| を参照してください。

   .. code-block:: arduino

       const int sensorPin = 8;
       BlynkTimer timer;

4. **setup()関数**

   センサーのピンモードの設定、シリアル通信の初期化、BlynkTimerの設定、およびBlynkアプリへの接続などの初期設定をこの関数で行います。

   - ``timer.setInterval(1000L, myTimerEvent)``を使用してsetup()でタイマー間隔を設定します。ここでは**1000ms**ごとに ``myTimerEvent()`` 関数を実行するように設定しています。 ``timer.setInterval(1000L, myTimerEvent)`` の最初のパラメータを変更して ``myTimerEvent`` の実行間隔を変更できます。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

       void setup() {
         pinMode(sensorPin, INPUT);
         Serial.begin(115200);
         EspSerial.begin(ESP8266_BAUD);
         delay(1000);
         timer.setInterval(1000L, myTimerEvent);
         Blynk.config(wifi,BLYNK_AUTH_TOKEN);
         Blynk.connectWiFi(ssid, pass);
       }

5. **loop()関数**

   メインループでは、Blynkおよびタイマーサービスを継続的に実行します。

   .. code-block:: arduino

       void loop() {
         Blynk.run();
         timer.run();
       }

6. **myTimerEvent()およびsendData()関数**

   .. code-block:: arduino
 
       void myTimerEvent() {
         // Please don't send more that 10 values per second.
         sendData();  // Call function to send sensor data to Blynk app
       }

   ``sendData()``関数は、火炎センサーから値を読み取り、それをBlynkに送信します。火炎が検出された場合（値が0）、Blynkアプリに ``flame_detection_alert`` イベントを送信します。

   - ``Blynk.virtualWrite(vPin, value)``を使用してデータをBlynkの仮想ピンV0に送信します。詳細は |link_blynk_virtualWrite| を参照してください。

   - ``Blynk.logEvent("event_code")``を使用してBlynkにイベントを記録します。詳細は |link_blynk_logEvent| を参照してください。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
       
      void sendData() {
        int data = digitalRead(sensorPin);
        Blynk.virtualWrite(V0, data);  // send data to virtual pin V0 on Blynk
        Serial.print("flame:");
        Serial.println(data);  // Print flame status on Serial Monitor
        if (data == 0) {
          Blynk.logEvent("flame_alert");  // log flame alert event if sensor detects flame
        }
      }

**参照**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|