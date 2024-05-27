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

Lesson 44: Bluetooth
=================================

This project provides a guide to develop a simple Bluetooth Low Energy (BLE) serial communication application 
using the ESP32 microcontroller. The ESP32 is a powerful microcontroller that integrates Wi-Fi and Bluetooth 
connectivity, making it an ideal candidate for developing wireless applications. BLE is 
a low-power wireless communication protocol that is designed for short-range communication. 
This document will cover the steps to set up the ESP32 to act as a BLE server and communicate with a BLE client over a serial connection.


**About the Bluetooth Function**

The ESP32 WROOM 32E is a module that integrates Wi-Fi and Bluetooth connectivity into a single chip. 
It supports Bluetooth Low Energy (BLE) and Classic Bluetooth protocols.

The module can be used as a Bluetooth client or server. As a Bluetooth client, the module can connect to 
other Bluetooth devices and exchange data with them. As a Bluetooth server, the module can provide 
services to other Bluetooth devices.
s
The ESP32 WROOM 32E supports various Bluetooth profiles, including the Generic Access Profile (GAP), Generic Attribute Profile (GATT), 
and Serial Port Profile (SPP). The SPP profile allows the module to emulate a serial port over Bluetooth, 
enabling serial communication with other Bluetooth devices.

To use the Bluetooth function of the ESP32 WROOM 32E, you need to program it using an appropriate software 
development kit (SDK) or using the Arduino IDE with the ESP32 BLE library. 
The ESP32 BLE library provides a high-level interface for working with BLE. It includes examples that demonstrate 
how to use the module as a BLE client and server.

Overall, the Bluetooth function of the ESP32 WROOM 32E provides a convenient and low-power way to enable wireless 
communication in your projects.

**Operation Steps**

Here are the step-by-step instructions to set up Bluetooth communication between your ESP32 and mobile device using the LightBlue app:

#. Download the LightBlue app from the **App Store** (for iOS) or **Google Play** (for Android).

    .. image:: img/bluetooth_lightblue.png

#. Open the ``Lesson_44_Bluetooth.ino`` file located in the ``universal-maker-sensor-kit\esp32\Lesson_44_Bluetooth`` directory, or copy the code into the Arduino IDE.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/3f42363e-1484-4c11-8d27-3a4d60b88a31/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

        
#. To avoid UUID conflicts, it is recommended to randomly generate three new UUIDs using the |link_uuid|, and fill them in the following lines of code.

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. Select the correct board and port, then click the **Upload** button.

    .. image:: img/bluetooth_upload.png

#. After the code has been successfully uploaded, turn on **Bluetooth** on your mobile device and open the **LightBlue** app.

    .. image:: img/bluetooth_open.png

#. On the **Scan** page, find **ESP32-Bluetooth** and click **CONNECT**. If you don't see it, try refreshing the page a few times. When **"Connected to device!"** appears, the Bluetooth connection is successful. Scroll down to see the three UUIDs set in the code.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Click the **Receive** UUID. Select the appropriate data format in the box to the right of **Data Format**, such as "HEX" for hexadecimal, "UTF-8 String" for character, or "Binary" for binary, etc. Then click **SUBSCRIBE**.

    .. image:: img/bluetooth_read.png
        :width: 300

#. Go back to the Arduino IDE, open the Serial Monitor, set the baud rate to 115200, then type "welcome" and press Enter.

    .. image:: img/bluetooth_serial.png

#. You should now see the "welcome" message in the LightBlue app.

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. To send information from the mobile device to the Serial Monitor, click the Send UUID, set the data format to "UTF-8 String", and write a message.

    .. image:: img/bluetooth_send.png


#. You should see the message in the Serial Monitor.

    .. image:: img/bluetooth_receive.png

**How it works?**

This Arduino code is written for the ESP32 microcontroller and sets it up to communicate with a Bluetooth Low Energy (BLE) device. 

The following is a brief summary of the code:

* **Include necessary libraries**: The code begins by including necessary libraries for working with Bluetooth Low Energy (BLE) on the ESP32.

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **Global Variables**: The code defines a set of global variables including the Bluetooth device name (``bleName``), variables to keep track of received text and the time of the last message, UUIDs for the service and characteristics, and a ``BLECharacteristic`` object (``pCharacteristic``).
    
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

* **Setup**: In the ``setup()`` function, the serial port is initialized with a baud rate of 115200 and the ``setupBLE()`` function is called to set up the Bluetooth BLE.

    .. code-block:: arduino
    
        void setup() {
            Serial.begin(115200);  // Initialize the serial port
            setupBLE();            // Initialize the Bluetooth BLE
        }

* **Main Loop**: In the ``loop()`` function, if a string was received over BLE (i.e., ``receivedText`` is not empty) and at least 1 second has passed since the last message, the code prints the received string to the serial monitor, sets the characteristic value to the received string, sends a notification, and then clears the received string. If data is available on the serial port, it reads the string until a newline character is encountered, sets the characteristic value to this string, and sends a notification.

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

* **Callbacks**: Two callback classes (``MyServerCallbacks`` and ``MyCharacteristicCallbacks``) are defined to handle events related to Bluetooth communication. ``MyServerCallbacks`` is used to handle events related to the connection state (connected or disconnected) of the BLE server. ``MyCharacteristicCallbacks`` is used to handle write events on the BLE characteristic, i.e., when a connected device sends a string to the ESP32 over BLE, it's captured and stored in ``receivedText``, and the current time is recorded in ``lastMessageTime``.

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

* **Setup BLE**: In the ``setupBLE()`` function, the BLE device and server are initialized, the server callbacks are set, the BLE service is created using the defined UUID, characteristics for sending notifications and receiving data are created and added to the service, and the characteristic callbacks are set. Finally, the service is started and the server begins advertising.

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


Please note that this code allows for bidirectional communication - it can send and receive data via BLE. 
However, to interact with specific hardware like turning on/off an LED, additional code should be added to process 
the received strings and act accordingly.




