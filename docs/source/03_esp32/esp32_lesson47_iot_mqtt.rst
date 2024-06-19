.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_iot_mqtt:

レッスン47: MQTTを用いたIoT通信
=========================================

このプロジェクトでは、モノのインターネット（IoT）分野で人気のある通信プロトコルであるMQTTを使用します。MQTTは、デバイスがトピックを介してデータを交換するためのパブリッシュ/サブスクライブモデルを提供します。

このプロジェクトでは、LED、ボタン、サーミスタを含む回路を構築し、MQTTの実装を探ります。ESP32-WROOM-32Eマイクロコントローラを使用してWiFiに接続し、MQTTブローカーと通信します。このコードは、マイクロコントローラが特定のトピックをサブスクライブし、メッセージを受信し、受信した情報に基づいてLEDを制御できるようにします。また、プロジェクトでは、ボタンを押したときにサーミスタからの温度データを指定されたトピックに公開する方法も示します。

**必要なコンポーネント**

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

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_button`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**コードのアップロード**

#. 回路を構築します。

    .. note:: 
        WiFiに接続する際には、36、39、34、35、32、33のピンのみがアナログ読み取りに使用できます。サーミスタがこれらの指定されたピンに接続されていることを確認してください。

    .. image:: img/Lesson_01_Button_Module_esp32_bb.png

#. その後、USBケーブルを使用してESP32-WROOM-32Eをコンピュータに接続します。

#. コードを開きます。

    * ``universal-maker-sensor-kit\esp32\Lesson_47_MQTT`` ディレクトリにある ``Lesson_47_MQTT.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **Upload** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``PubSubClient`` ライブラリが使用されますので、 **Library Manager** からインストールしてください。

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3f33a562-ebaa-48ed-a3ba-ae11e0b9706f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 以下の行を見つけて、 ``<SSID>`` と ``<PASSWORD>`` で修正します。

    .. code-block:: Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";
 
#. 次の行を見つけて、 ``unique_identifier`` を修正します。 ``unique_identifier`` が真にユニークであることを保証してください。同じIDを使用して同じMQTTブローカーにログインしようとすると、ログインに失敗する可能性があります。

    .. code-block:: Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";

**トピックサブスクリプション**

#. 他の参加者が送信したメッセージの干渉を避けるために、あまり一般的でない文字列に設定することをお勧めします。現在のトピック ``SF/LED`` を希望のトピック名に置き換えるだけです。

    .. note:: 
        トピックを任意の文字に設定する自由があります。同じトピックをサブスクライブしているMQTTデバイスは同じメッセージを受信できます。また、複数のトピックを同時にサブスクライブすることも可能です。

    .. code-block::  Arduino
        :emphasize-lines: 9

        void reconnect() {
            // Loop until we're reconnected
            while (!client.connected()) {
                Serial.print("Attempting MQTT connection...");
                // Attempt to connect
                if (client.connect(unique_identifier)) {
                    Serial.println("connected");
                    // Subscribe
                    client.subscribe("SF/LED");
                } else {
                    Serial.print("failed, rc=");
                    Serial.print(client.state());
                    Serial.println(" try again in 5 seconds");
                    // Wait 5 seconds before retrying
                    delay(5000);
                }
            }
        }

#. サブスクライブしたトピックに応答するように機能を変更します。提供されたコードでは、 ``SF/LED``  トピックでメッセージを受信した場合、メッセージが ``on`` または ``off`` であるかどうかを確認します。受信したメッセージに応じて、LEDのオンまたはオフの状態を制御します。

    .. note::
       サブスクライブしている任意のトピックに対応するように変更でき、複数のトピックに対応するために複数のif文を書くこともできます。

    .. code-block::  arduino
        :emphasize-lines: 15

        void callback(char* topic, byte* message, unsigned int length) {
            Serial.print("Message arrived on topic: ");
            Serial.print(topic);
            Serial.print(". Message: ");
            String messageTemp;

            for (int i = 0; i < length; i++) {
                Serial.print((char)message[i]);
                messageTemp += (char)message[i];
            }
            Serial.println();

            // If a message is received on the topic "SF/LED", you check if the message is either "on" or "off".
            // Changes the output state according to the message
            if (String(topic) == "SF/LED") {
                Serial.print("Changing state to ");
                if (messageTemp == "on") {
                    Serial.println("on");
                    digitalWrite(ledPin, HIGH);
                } else if (messageTemp == "off") {
                    Serial.println("off");
                    digitalWrite(ledPin, LOW);
                }
            }
        }

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、 **Upload** ボタンをクリックします。

#. シリアルモニターを開き、以下の情報が表示された場合、MQTTサーバーへの接続が成功したことを示します。

    .. code-block:: 

        WiFi connected
        IP address: 
        192.168.18.77
        Attempting MQTT connection...connected

**HiveMQを介したメッセージの公開**

HiveMQは、MQTTブローカーとして機能するメッセージングプラットフォームであり、IoTデバイスへのデータ転送を迅速かつ効率的、信頼性の高いものにします。

私たちのコードは、特にHiveMQが提供するMQTTブローカーを利用しています。以下のようにコードにHiveMQ MQTTブローカーのアドレスを含めました：

    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";

#. 現在、Webブラウザで |link_hivemq| を開きます。

#. クライアントをデフォルトのパブリックプロキシに接続します。

    .. image:: img/sp230512_092258.png

#. サブスクライブしているトピックにメッセージを公開します。このプロジェクトでは、LEDを制御するために ``on`` または ``off`` を公開できます。

    .. image:: img/sp230512_140234.png

**MQTTへのメッセージの公開**

コードを使用してトピックに情報を公開することもできます。このデモでは、ボタンを押すとトピックにシンプルなメッセージを送信する機能をコーディングしました。

#. **Add New Topic Subscription** をクリックします。

    .. image:: img/sp230512_092341.png

#. フォローしたいトピックを入力し、 **Subscribe**  をクリックします。このコードでは、 ``SF/TEMP`` トピックにメッセージを送信します。

    .. code-block::  Arduino
        :emphasize-lines: 14

        void loop() {
            if (!client.connected()) {
                reconnect();
            }
            client.loop();

            // if the button pressed, publish the temperature to topic "SF/TEMP"
            if (digitalRead(buttonPin)) {
                    long now = millis();
                    if (now - lastMsg > 5000) {
                    lastMsg = now;
                    char tempString[8];
                    strcpy(tempString,"hello");
                    client.publish("SF/TEMP", tempString);
                }
            }
        }

#. したがって、HiveMQでこのトピックを監視し、公開された情報を確認できます。

    .. image:: img/sp230512_154342.png
