.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _esp32_bluetooth:

レッスン 44: Bluetooth
=================================

このプロジェクトでは、ESP32マイクロコントローラーを使用してシンプルなBluetooth Low Energy (BLE) シリアル通信アプリケーションを開発するためのガイドを提供します。
ESP32は、Wi-FiとBluetoothの接続機能を統合した強力なマイクロコントローラーであり、ワイヤレスアプリケーションの開発に理想的です。
BLEは、短距離通信向けに設計された低消費電力のワイヤレス通信プロトコルです。
このドキュメントでは、ESP32をBLEサーバーとして設定し、シリアル接続を介してBLEクライアントと通信する手順を説明します。




**Bluetooth機能について**

ESP32 WROOM 32Eは、Wi-FiとBluetoothの接続機能を1つのチップに統合したモジュールです。
このモジュールは、Bluetooth Low Energy (BLE)およびクラシックBluetoothプロトコルをサポートしています。

このモジュールは、Bluetoothクライアントまたはサーバーとして使用できます。
Bluetoothクライアントとして、他のBluetoothデバイスに接続し、それらとデータを交換できます。
Bluetoothサーバーとして、このモジュールは他のBluetoothデバイスにサービスを提供できます。

ESP32 WROOM 32Eは、Generic Access Profile (GAP)、Generic Attribute Profile (GATT)、およびSerial Port Profile (SPP)を含むさまざまなBluetoothプロファイルをサポートしています。
SPPプロファイルを使用すると、モジュールはBluetooth経由でシリアルポートをエミュレートし、他のBluetoothデバイスとシリアル通信を可能にします。

ESP32 WROOM 32EのBluetooth機能を使用するには、適切なソフトウェア開発キット (SDK) を使用してプログラムするか、Arduino IDEとESP32 BLEライブラリを使用する必要があります。
ESP32 BLEライブラリは、BLEを使用するための高レベルインターフェースを提供し、モジュールをBLEクライアントおよびサーバーとして使用する方法を示す例を含んでいます。

全体として、ESP32 WROOM 32EのBluetooth機能は、プロジェクトにワイヤレス通信を簡単かつ低消費電力で実装するための便利な方法を提供します。







**操作手順**

以下は、LightBlueアプリを使用してESP32とモバイルデバイス間でBluetooth通信を設定するためのステップバイステップの手順です：

#. iOSの場合は **App Store** から、Androidの場合は **Google Play** からLightBlueアプリをダウンロードします。

    .. image:: img/bluetooth_lightblue.png

#. ``universal-maker-sensor-kit\esp32\Lesson_44_Bluetooth``ディレクトリにある ``Lesson_44_Bluetooth.ino`` ファイルを開くか、コードをArduino IDEにコピーします。

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/3f42363e-1484-4c11-8d27-3a4d60b88a31/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. UUIDの競合を避けるために、|link_uuid| を使用して新しいUUIDを3つランダムに生成し、次のコード行に入力することをお勧めします。

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. 正しいボードとポートを選択し、 **Upload** ボタンをクリックします。

    .. image:: img/bluetooth_upload.png

#. コードのアップロードが成功したら、モバイルデバイスで **Bluetooth** をオンにし、 **LightBlue** アプリを開きます。

    .. image:: img/bluetooth_open.png

#. **Scan**ページで**ESP32-Bluetooth**を見つけて **CONNECT** をクリックします。表示されない場合は、ページを数回更新してみてください。 **"Connected to device!"** と表示されたら、Bluetooth接続は成功です。コードで設定した3つのUUIDが表示されるまでスクロールします。

    .. image:: img/bluetooth_connect.png
        :width: 800

#. **Receive** UUIDをクリックします。 **Data Format** の右側のボックスで適切なデータ形式（"HEX"、"UTF-8 String"、"Binary"など）を選択し、 **SUBSCRIBE** をクリックします。

    .. image:: img/bluetooth_read.png
        :width: 300

#. Arduino IDEに戻り、シリアルモニタを開き、ボーレートを115200に設定してから、「welcome」と入力してEnterキーを押します。

    .. image:: img/bluetooth_serial.png

#. LightBlueアプリに「welcome」メッセージが表示されます。

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. モバイルデバイスからシリアルモニタに情報を送信するには、Send UUIDをクリックし、データ形式を「UTF-8 String」に設定して、メッセージを書きます。

    .. image:: img/bluetooth_send.png

#. シリアルモニタにメッセージが表示されます。

    .. image:: img/bluetooth_receive.png

**動作原理**

このArduinoコードは、ESP32マイクロコントローラーを使用してBluetooth Low Energy (BLE) デバイスと通信するための設定を行います。

以下はコードの簡単な概要です：

* **必要なライブラリのインクルード**：コードは、ESP32でBluetooth Low Energy (BLE) を使用するために必要なライブラリをインクルードすることから始まります。

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **グローバル変数**：コードは、Bluetoothデバイス名（ ``bleName`` ）、受信テキストと最後のメッセージの時刻を追跡する変数、サービスと特性のUUID、および ``BLECharacteristic`` オブジェクト（ ``pCharacteristic`` ）を含む一連のグローバル変数を定義します。

    .. code-block:: arduino

        // Define the Bluetooth device name
        const char *bleName = "ESP32_Bluetooth";

        // Define the received text and the time of the last message
        String receivedText = "";
        unsigned long lastMessageTime = 0;

        // Define the UUIDs of the service and characteristics
        #define SERVICE_UUID           "your_service_uuid_here"
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

        // Define the Bluetooth characteristic
        BLECharacteristic *pCharacteristic;

* **セットアップ**： ``setup()`` 関数では、シリアルポートを115200のボーレートで初期化し、 ``setupBLE()`` 関数を呼び出してBluetooth BLEを設定します。

    .. code-block:: arduino
    
        void setup() {
            Serial.begin(115200);  // Initialize the serial port
            setupBLE();            // Initialize the Bluetooth BLE
        }
* **メインループ**： ``loop()`` 関数では、BLE経由で文字列が受信され（ ``receivedText`` が空でない場合）、最後のメッセージから少なくとも1秒が経過している場合、コードは受信した文字列をシリアルモニタに出力し、特性値を受信した文字列に設定し、通知を送信し、受信した文字列をクリアします。シリアルポートでデータが利用可能な場合、改行文字が見つかるまで文字列を読み取り、この文字列を特性値に設定し、通知を送信します。

    .. code-block:: arduino

        void loop() {
            // When the received text is not empty and the time since the last message is over 1 second
            // Send a notification and print the received text
            if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
                Serial.print("Received message: ");
                Serial.println(receivedText);
                pCharacteristic->setValue(receivedText.c_str());
                pCharacteristic->notify();
                receivedText = "";
            }

            // Read data from the serial port and send it to BLE characteristic
            if (Serial.available() > 0) {
                String str = Serial.readStringUntil('\n');
                const char *newValue = str.c_str();
                pCharacteristic->setValue(newValue);
                pCharacteristic->notify();
            }
        }

* **コールバック**：Bluetooth通信に関連するイベントを処理するために、2つのコールバッククラス（ ``MyServerCallbacks`` および ``MyCharacteristicCallbacks`` ）が定義されています。 ``MyServerCallbacks`` はBLEサーバーの接続状態（接続または切断）に関連するイベントを処理し、 ``MyCharacteristicCallbacks`` はBLE特性への書き込みイベントを処理します。接続されたデバイスがBLE経由でESP32に文字列を送信すると、それが ``receivedText`` に格納され、現在の時間が ``lastMessageTime`` に記録されます。

    .. code-block:: arduino

        // Define the BLE server callbacks
        class MyServerCallbacks : public BLEServerCallbacks {
            // Print the connection message when a client is connected
            void onConnect(BLEServer *pServer) {
            Serial.println("Connected");
            }
            // Print the disconnection message when a client is disconnected
            void onDisconnect(BLEServer *pServer) {
            Serial.println("Disconnected");
            }
        };

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                // When data is received, get the data and save it to receivedText, and record the time
                std::string value = pCharacteristic->getValue();
                receivedText = String(value.c_str());
                lastMessageTime = millis();
                Serial.print("Received: ");
                Serial.println(receivedText);
            }
        };

* **BLEの設定**： ``setupBLE()`` 関数では、BLEデバイスとサーバーを初期化し、サーバーのコールバックを設定し、定義されたUUIDを使用してBLEサービスを作成し、通知を送信するための特性とデータを受信するための特性を作成してサービスに追加し、特性のコールバックを設定します。最後に、サービスを開始し、サーバーが広告を開始します。

    .. code-block:: arduino

        // Initialize the Bluetooth BLE
        void setupBLE() {
            BLEDevice::init(bleName);                        // Initialize the BLE device
            BLEServer *pServer = BLEDevice::createServer();  // Create the BLE server
            // Print the error message if the BLE server creation fails
            if (pServer == nullptr) {
                Serial.println("Error creating BLE server");
                return;
            }
            pServer->setCallbacks(new MyServerCallbacks());  // Set the BLE server callbacks

            // Create the BLE service
            BLEService *pService = pServer->createService(SERVICE_UUID);
            // Print the error message if the BLE service creation fails
            if (pService == nullptr) {
                Serial.println("Error creating BLE service");
                return;
            }
            // Create the BLE characteristic for sending notifications
            pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
            pCharacteristic->addDecodeor(new BLE2902());  // Add the decodeor
            // Create the BLE characteristic for receiving data
            BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
           pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Set the BLE characteristic callbacks
            pService->start();                                                 // Start the BLE service
            pServer->getAdvertising()->start();                                // Start advertising
            Serial.println("Waiting for a client connection...");              // Wait for a client connection
        }

このコードは双方向通信を可能にします - BLE経由でデータの送受信が可能です。
ただし、LEDのオン/オフなどの特定のハードウェアと対話するためには、受信した文字列を処理して対応する追加のコードを追加する必要があります。
