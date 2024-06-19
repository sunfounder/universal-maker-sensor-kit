

.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _esp32_iot_intrusion_alert_system:

レッスン49: Blynkを使った侵入通知システム
=============================================================

このプロジェクトでは、PIRモーションセンサー（HC-SR501）を使用した簡単なホーム侵入検知システムを紹介します。
Blynkアプリでシステムを「不在」モードに設定すると、PIRセンサーが動きを監視します。
検出された動きは、Blynkアプリで通知をトリガーし、ユーザーに潜在的な侵入を警告します。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

全キットを購入すると便利です。リンクはこちら：

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

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_pir_motion`
        - \-

1. 回路の組み立て
--------------------

.. image:: img/Lesson_12_PIR_Module_esp32_bb.png
    :width: 100%
    :align: center

2. Blynkの設定
----------------------

**2.1 Blynkの初期設定**

#. |link_blynk| にアクセスして、 **START FREE** を選択します。

   .. image:: img/09_blynk_access.png
        :width: 90%

#. メールアドレスを入力して登録プロセスを開始します。

   .. image:: img/09_blynk_sign_in.png
        :width: 70%
        :align: center

#. メールで登録を確認します。

    .. image:: img/09_blynk_password.png
        :width: 90%

#. 確認後、 **Blynk Tour** が表示されます。スキップを選択することをお勧めします。 **Quick Start** が表示された場合もスキップを検討してください。
   
    .. image:: img/09_blynk_tour.png
        :width: 90%
**2.2 テンプレート作成**

#. 最初に、Blynkでテンプレートを作成します。以下の手順に従って、 **Intrusion Alert System** テンプレートを作成してください。

    .. image:: img/09_create_template_1_shadow.png
        :width: 700
        :align: center

#. テンプレートに名前を付け、 **ESP32** ハードウェアを選択し、 **Connection Type** を **WiFi** として選択し、 **Done** をクリックします。

    .. image:: img/09_create_template_2_shadow.png
        :width: 700
        :align: center

**2.3 データストリームの生成**

先ほど設定したテンプレートを開き、2つのデータストリームを作成しましょう。

#. **New Datastream** をクリックします。

    .. image:: img/09_blynk_new_datastream.png
        :width: 700
        :align: center

#. ポップアップで、 **Virtual Pin** を選択します。

    .. image:: img/09_blynk_datastream_virtual.png
        :width: 700
        :align: center

#. **Virtual Pin V0** を **AwayMode** と命名します。 **DATA TYPE** を **Integer** とし、 **MIN** と **MAX** の値を **0** と **1** に設定します。

    .. image:: img/09_create_template_shadow.png
        :width: 700
        :align: center

#. 同様に、もう一つの **Virtual Pin** データストリームを作成します。これを **Current Status** と命名し、 **DATA TYPE** を **String** に設定します。

    .. image:: img/09_datastream_1_shadow.png
        :width: 700
        :align: center

**2.4 イベントの設定**

次に、侵入が検知された場合にメール通知を送信するイベントを設定します。

#. **Add New Event** をクリックします。

    .. image:: img/09_blynk_event_add.png

#. イベントの名前と特定のコードを定義します。 **TYPE** には **Warning** を選択し、イベントが発生した際に送信されるメールの簡単な説明を記入します。また、通知頻度を調整することもできます。

    .. note::
        
        **EVENT CODE** を ``intrusion_detected`` に設定してください。これはコードに事前定義されているため、変更する場合はコードも調整する必要があります。

    .. image:: img/09_event_1_shadow.png
        :width: 700
        :align: center

#. **Notifications** セクションに移動し、通知をオンにしてメールの詳細を設定します。

    .. image:: img/09_event_2_shadow.png
        :width: 80%
        :align: center

.. raw:: html
    
    <br/> 

**2.5 Web ダッシュボードの微調整**

**Web ダッシュボード** が Intrusion Alert System と完全に連携するように調整します。

#. **Switch ウィジェット** と **Label ウィジェット** の両方を **Web ダッシュボード** にドラッグして配置します。

    .. image:: img/09_web_dashboard_1_shadow.png
        :width: 100%
        :align: center

#. ウィジェットにカーソルを合わせると、3つのアイコンが表示されます。設定アイコンを使用して、ウィジェットのプロパティを調整します。

    .. image:: img/09_blynk_dashboard_set.png
        :width: 100%
        :align: center

#. **Switch ウィジェット** の設定では、 **Datastream** を **AwayMode(V0)** に設定します。 **ONLABEL** と **OFFLABEL** をそれぞれ **"away"** と **"home"** に設定します。

    .. image:: img/09_web_dashboard_2_shadow.png
        :width: 100%
        :align: center

#. **Label ウィジェット** の設定では、 **Datastream** を **Current Status(V1)** に設定します。

    .. image:: img/09_web_dashboard_3_shadow.png
        :width: 100%
        :align: center
**2.6 テンプレートの保存**

最後に、テンプレートを保存することを忘れないでください。

    .. image:: img/09_save_template_shadow.png
        :width: 100%
        :align: center

**2.7 デバイスの作成**

#. 新しいデバイスを作成する時が来ました。

    .. image:: img/09_blynk_device_new.png
        :width: 700
        :align: center

#. **From template** をクリックして、新しいセットアップを開始します。

    .. image:: img/09_blynk_device_template.png
        :width: 700
        :align: center

#. その後、 **Intrusion Alert System** テンプレートを選択し、 **Create** をクリックします。

    .. image:: img/09_blynk_device_template2.png
        :width: 700
        :align: center

#. ここで、 ``Template ID``、 ``Device Name``、および ``AuthToken``が表示されます。これらをコードにコピーして、ESP32がBlynkと連携できるようにします。

    .. image:: img/09_blynk_device_code.png
        :width: 700
        :align: center

3. コードの実行
-----------------------------
#. コードを実行する前に、Arduino IDEの **Library Manager** から ``Blynk`` ライブラリをインストールしてください。

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#. ``universal-maker-sensor-kit\esp32\Lesson_49_Blynk_based_intrusion_system``ディレクトリにある ``Lesson_49_Blynk_based_intrusion_system.ino``ファイルを開きます。または、その内容をArduino IDEにコピーすることもできます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/987fb2fd-47e9-4a73-9020-6b2111eadd9c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. ``BLYNK_TEMPLATE_ID``、 ``BLYNK_TEMPLATE_NAME``、および ``BLYNK_AUTH_TOKEN``のプレースホルダーを自分のユニークなIDに置き換えます。

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. WiFiネットワークの ``ssid``と ``password``も入力する必要があります。

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. 正しいボード（ **ESP32 Dev Module**）とポートを選択し、 **Upload**ボタンをクリックします。

#. シリアルモニターを開き（ボーレートを115200に設定）、接続成功メッセージを待ちます。

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. 接続が成功すると、BlynkでスイッチをアクティブにすることでPIRモジュールの監視が開始されます。モーションが検出されると（状態が1になる）、"Somebody here!" と表示され、メールにアラートが送信されます。

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. コードの説明
-----------------------------

#. **設定 & ライブラリ**

   ここでは、Blynkの定数とクレデンシャルを設定します。また、ESP32とBlynkに必要なライブラリをインクルードします。

    .. code-block:: arduino

        /* Comment this out to disable prints and save space */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **WiFiの設定**

   WiFiのクレデンシャルを入力します。

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **PIRセンサーの設定**

   PIRセンサーが接続されているピンを設定し、状態変数を初期化します。

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **setup()関数**

   この関数は、PIRセンサーを入力として初期化し、シリアル通信を設定し、WiFiに接続し、Blynkを設定します。

   - ``timer.setInterval(1000L, myTimerEvent)``を使ってタイマー間隔を設定します。ここでは、 ``myTimerEvent()``関数を **1000ms**ごとに実行するように設定しています。 ``timer.setInterval(1000L, myTimerEvent)``の最初のパラメータを変更して、 ``myTimerEvent``の実行間隔を変更できます。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void setup() {

            pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input
            Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging
            
            // Configure Blynk and connect to WiFi
            Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
            
            timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
        }

#. **loop()関数**

   ループ関数は、BlynkとBlynkタイマー関数を連続的に実行します。

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }
#. **Blynkアプリとの連携**

   これらの関数は、デバイスがBlynkに接続されたとき、およびBlynkアプリ上の仮想ピンV0の状態が変化したときに呼び出されます。

   - デバイスがBlynkサーバーに接続されるたびに、またはネットワークの問題で再接続されるたびに、 ``BLYNK_CONNECTED()``関数が呼び出されます。 ``Blynk.syncVirtual()``コマンドは、指定された仮想ピンの値をリクエストし、 ``BLYNK_WRITE()``呼び出しを行います。

   - Blynkサーバー上の仮想ピンの値が変更されるたびに、 ``BLYNK_WRITE()``がトリガーされます。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
      
        // This function is called every time the device is connected to the Blynk.Cloud
        BLYNK_CONNECTED() {
            Blynk.syncVirtual(V0);
        }
      
        // This function is called every time the Virtual Pin 0 state changes
        BLYNK_WRITE(V0) {
            awayHomeMode = param.asInt();
            // additional logic
        }

#. **データ処理**

   毎秒、 ``myTimerEvent()`` 関数が ``sendData()`` を呼び出します。Blynkでアウェイモードが有効になっている場合、PIRセンサーをチェックし、動きが検出された場合はBlynkに通知を送信します。

   - ``Blynk.virtualWrite(V1, "Somebody in your house! Please check!");``を使用してラベルのテキストを変更します。

   - ``Blynk.logEvent("intrusion_detected");``を使用してBlynkにイベントを記録します。

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void myTimerEvent() {
           sendData();
        }

        void sendData() {
           if (awayHomeMode == 1) {
              state = digitalRead(sensorPin);  // Read the state of the PIR sensor

              Serial.print("state:");
              Serial.println(state);

              // If the sensor detects movement, send an alert to the Blynk app
              if (state == HIGH) {
                Serial.println("Somebody here!");
                Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
                Blynk.logEvent("intrusion_detected");
              }
           }
        }

**参考**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|