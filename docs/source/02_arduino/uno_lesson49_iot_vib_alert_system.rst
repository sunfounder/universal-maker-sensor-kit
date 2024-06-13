
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _uno_iot_vib_alert_system:

Lesson 49: IFTTTを使用した振動アラートシステム
=====================================================

このプロジェクトでは、Arduinoボード（Uno R4またはR3）とESP8266モジュール、振動センサー（SW-420）を使用して振動検知システムを構築します。振動が検出されると、システムはIFTTTサーバーにHTTPリクエストを送信し、通知やメールの送信などのさまざまなアクションをトリガーします。

短時間での過剰なアラートを避けるため、システムは最小限2分（120000ミリ秒）間隔でHTTPリクエストを送信するようにプログラムされています。この間隔はユーザーのニーズに応じて調整可能です。

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
    *   - :ref:`cpn_vibration`
        - \-

配線
---------------------------

.. image:: img/Lesson_49_Iot_vibration_alert_system_uno_bb.png
    :width: 100%

IFTTTの設定
-----------------------------

|link_ifttt| は、2011年に設立された民間企業で、オンラインデジタルオートメーションプラットフォームを提供しています。これらのプラットフォームは、クロスプラットフォームのifステートメントを視覚的に作成するインターフェースを提供し、2020年現在、1,800万人のユーザーが利用しています。

.. image:: img/04-ifttt_intro.png
    :width: 100%

IFTTTは「If This Then That」の略です。基本的に、特定の条件が満たされると、別の何かが起こります。「if this」部分はトリガーと呼ばれ、「then that」部分はアクションと呼ばれます。スマートホームデバイス、ソーシャルメディア、配達アプリなどを連携させ、自動化タスクを実行できます。

.. image:: img/04-ifttt_intro_2A.png
    :width: 100% 

**1) IFTTTのサインアップ**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

ブラウザに「https://ifttt.com」と入力し、ページ中央にある「Get started」ボタンをクリックします。情報を入力してアカウントを作成します。

.. image:: img/04-ifttt_signup.png
    :width: 90%
    :align: center

「Back」をクリックしてクイックスタートを終了し、IFTTTのホームページに戻り、ページをリフレッシュして再度ログインします。

.. image:: img/04-ifttt_signup_2.png
    :width: 90%
    :align: center

**2) アプレットの作成**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

「Create」をクリックしてアプレットの作成を開始します。

.. image:: img/04-ifttt_create_applet_1_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/>  

**If This trigger**

「If This」の横にある「Add」をクリックしてトリガーを追加します。

.. image:: img/04-ifttt_create_applet_2_shadow.png
    :width: 80%
    :align: center

「webhook」を検索し、「Webhooks」をクリックします。

.. image:: img/04-ifttt_create_applet_3_shadow.png
    :width: 80%
    :align: center

次の画像に示されているページで「Receive a web request」をクリックします。

.. image:: img/04-ifttt_create_applet_4_shadow.png
    :width: 80%
    :align: center

「Event Name」を「vibration_detected」に設定します。

.. image:: img/04-ifttt_create_applet_5_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/>  

**Then That action**

「Then That」の横にある「Add」をクリックしてアクションを追加します。

.. image:: img/04-ifttt_create_applet_6_shadow.png
    :width: 80%
    :align: center

「email」を検索し、「Email」をクリックします。

.. image:: img/04-ifttt_create_applet_7_shadow.png
    :width: 80%
    :align: center

次の画像に示されているページで「Send me a email」をクリックします。

.. image:: img/04-ifttt_create_applet_8_shadow.png
    :width: 80%
    :align: center

振動が検出されたときに送信されるメールの件名と内容を設定します。

参考として、件名は「[ESP-01] Detected vibration!!!」、内容は「Detected vibration, please confirm the situation promptly! {{OccurredAt}}」に設定します。メールを送信する際に、 ``{{OccurredAt}}`` はイベントが発生した時間に自動的に置き換えられます。

.. image:: img/04-ifttt_create_applet_9_shadow.png
    :width: 80%
    :align: center

次のステップに従って、アプレットの作成を完了します。

.. image:: img/04-ifttt_create_applet_10_shadow.png
    :width: 80%
    :align: center

.. image:: img/04-ifttt_create_applet_11_shadow.png
    :width: 80%
    :align: center

.. image:: img/04-ifttt_create_applet_12_shadow.png
    :width: 50%
    :align: center

.. raw:: html
    
    <br/>  

コード
----------------------- 

#. ``universal-maker-sensor-kit\arduino_uno\Lesson_49_Vibration_alert_system``のパスにある ``Lesson_49_Vibration_alert_system.ino`` ファイルを開くか、このコードを **Arduino IDE**にコピーします。

   .. raw:: html
       
        <iframe src=https://create.arduino.cc/editor/sunfounder01/35a75e1c-6b2a-407d-9724-f83ad50a4a41/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 使用するWiFiの ``mySSID`` と ``myPWD`` を入力する必要があります。

   .. code-block:: arduino

      String mySSID = "your_ssid";     // WiFi SSID
    String myPWD = "your_password";  // WiFi Password

#. イベント名とAPIキーを含めた ``URL`` を修正する必要があります。

   .. code-block:: arduino
    
      String URL = "/trigger/vibration_detected/with/key/xxxxxxxxxxxxxxxxxx";

   .. image:: img/04-ifttt_apikey_1_shadow.png
       :width: 80%
       :align: center
   
   .. image:: img/04-ifttt_apikey_2_shadow.png
       :width: 80%
       :align: center

   ここには **あなたのユニークなAPIキーが表示され、これは秘密にしておく必要があります**。イベント名を ``vibration_detected`` として入力します。最終的なURLはウェブページの下部に表示されます。このURLをコピーしてください。

   .. image:: img/04-ifttt_apikey_3_shadow.png
       :width: 80%
       :align: center

   .. image:: img/04-ifttt_apikey_4_shadow.png
       :width: 80%
       :align: center

#. 正しいボードとポートを選択した後、 **アップロード** ボタンをクリックします。

#. シリアルモニタを開き（ボーレートを **9600** に設定）、接続成功などのプロンプトが表示されるのを待ちます。

   .. image:: img/04-ready_shadow.png
          :width: 95%


コード解析
---------------------------

キットに付属しているESP8266モジュールは、すでにATファームウェアが書き込まれています。したがって、ESP8266モジュールはATコマンドを通じて制御できます。このプロジェクトでは、ソフトウェアシリアルを使用してArduino UnoボードとESP8266モジュール間の通信を可能にします。Arduino Unoボードは、ネットワーク接続とリクエスト送信のためにESP8266モジュールにATコマンドを送信します。詳細は|link_esp8266_at|をご参照ください。

Unoボードはセンサー値を読み取り、ESP8266モジュールにATコマンドを送信します。ESP8266モジュールはネットワークに接続し、IFTTTサーバーにリクエストを送信します。

#. ArduinoとESP8266間のシリアル通信のためにSoftwareSerialライブラリを含める

   .. code-block:: arduino
   
     #include <SoftwareSerial.h>      
     SoftwareSerial espSerial(2, 3);  

#. WiFiの認証情報とIFTTTサーバーの詳細を設定する

   .. code-block:: arduino
   
     String mySSID = "your_ssid";     
     String myPWD = "your_password";  
     String myHOST = "maker.ifttt.com";
     String myPORT = "80";
     String URL = "/trigger/xxx/with/key/xxxx";  

#. 振動センサーとアラート頻度制御のための変数を定義する

   .. code-block:: arduino
   
     unsigned long lastAlertTime = 0;                
     const unsigned long postingInterval = 120000L;
     const int sensorPin = 7;

#. ``setup()``でシリアル通信、ESP8266モジュールの初期化とWiFiへの接続を行う

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);
        espSerial.begin(115200);
      
        // Initialize the ESP8266 module
        sendATCommand("AT+RST", 1000, DEBUG);   //Reset the ESP8266 module
        sendATCommand("AT+CWMODE=1", 1000, DEBUG);  //Set the ESP mode as station mode
        sendATCommand("AT+CWJAP=\"" + mySSID + "\",\"" + myPWD + "\"", 3000, DEBUG);  //Connect to WiFi network
      
        while (!espSerial.find("OK")) {
          //Wait for connection
        }
      }

#. ``loop()``で振動を検知し、時間間隔が経過している場合はアラートを送信する

   .. code-block:: arduino
   
      void loop() {
      
        if (digitalRead(sensorPin)) {
          if (lastAlertTime == 0 || millis() - lastAlertTime > postingInterval) {
            Serial.println("Detected vibration!!!");
            sendAlert();  //Send an HTTP request to IFTTT server
          } else {
            Serial.print("Detected vibration!!! ");
            Serial.println("Since an email has been sent recently, no warning email will be sent this time to avoid bombarding your inbox.");
          }
        } else {
          if (DEBUG) {
            Serial.println("Detecting...");
          }
        }
        delay(500);
      }

#. sendAlert()でHTTPリクエストを構築し、ESP8266経由で送信する

   .. code-block:: arduino
   
     void sendAlert() {
   
       String sendData = "GET " + URL + " HTTP/1.1" + "\r\n";
       sendData += "Host: maker.ifttt.com\r\n";
       
       sendATCommand("AT+CIPMUX=0",1000,DEBUG);                           
       sendATCommand("AT+CIPSTART=...",3000,DEBUG);  
       sendATCommand("AT+CIPSEND=" + String(sendData.length()),1000,DEBUG);   
       espSerial.println(sendData);
      
     }  

#. ATコマンドの送信を処理するsendATCommand()

   この関数はESP8266にATコマンドを送信し、応答を収集します。
   
   .. code-block:: arduino
   
      void sendATCommand(String command, const int timeout, boolean debug) {
        // Print and send command
        Serial.print("AT Command ==> ");
        Serial.print(command);
        Serial.println();
        espSerial.println(command);  // Send the AT command
      
        // Get the response from the ESP8266 module
        String response = "";
        long int time = millis();
        while ((time + timeout) > millis()) {  // Wait for the response until the timeout
          while (espSerial.available()) {
            char c = espSerial.read();
            response += c;
          }
        }
      
        // Print response if debug mode is on
        if (debug) {
          Serial.println(response);
          Serial.println("--------------------------------------");
        }

**参考**

* |link_esp8266_at|
* |link_ifttt_welcome|
* |link_ifttt_webhook_faq|