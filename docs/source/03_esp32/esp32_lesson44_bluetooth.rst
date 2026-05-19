.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_bluetooth:

Lektion 44: Bluetooth
=================================

Dieses Projekt bietet eine Anleitung zur Entwicklung einer einfachen Bluetooth Low Energy (BLE) seriellen Kommunikationsanwendung mit dem ESP32-Mikrocontroller. 
Der ESP32 ist ein leistungsstarker Mikrocontroller, der Wi-Fi und Bluetooth-Konnektivität integriert und somit ein idealer Kandidat für die Entwicklung drahtloser Anwendungen ist. 
BLE ist ein energiesparendes drahtloses Kommunikationsprotokoll, das für die Kurzstreckenkommunikation ausgelegt ist. Dieses Dokument behandelt die Schritte, 
um den ESP32 als BLE-Server einzurichten und über eine serielle Verbindung mit einem BLE-Client zu kommunizieren.

**Über die Bluetooth-Funktion**

Der ESP32 WROOM 32E ist ein Modul, das Wi-Fi- und Bluetooth-Konnektivität in einem einzigen Chip integriert. 
Es unterstützt sowohl Bluetooth Low Energy (BLE) als auch klassische Bluetooth-Protokolle.

Das Modul kann als Bluetooth-Client oder -Server verwendet werden. 
Als Bluetooth-Client kann das Modul sich mit anderen Bluetooth-Geräten verbinden und Daten mit ihnen austauschen. 
Als Bluetooth-Server kann das Modul anderen Bluetooth-Geräten Dienste anbieten.

Der ESP32 WROOM 32E unterstützt verschiedene Bluetooth-Profile, einschließlich des Generic Access Profile (GAP), 
des Generic Attribute Profile (GATT) und des Serial Port Profile (SPP). Das SPP-Profil ermöglicht es dem Modul, 
einen seriellen Port über Bluetooth zu emulieren, was eine serielle Kommunikation mit anderen Bluetooth-Geräten ermöglicht.

Um die Bluetooth-Funktion des ESP32 WROOM 32E zu nutzen, müssen Sie ihn mit einem geeigneten Software Development Kit (SDK) oder mit der Arduino IDE und der ESP32 BLE-Bibliothek programmieren. 
Die ESP32 BLE-Bibliothek bietet eine hochrangige Schnittstelle für die Arbeit mit BLE. Sie enthält Beispiele, die zeigen, wie das Modul als BLE-Client und -Server verwendet wird.

Insgesamt bietet die Bluetooth-Funktion des ESP32 WROOM 32E eine bequeme und energiesparende Möglichkeit, drahtlose Kommunikation in Ihren Projekten zu ermöglichen.

**Betriebsanleitung**

Hier sind die Schritt-für-Schritt-Anweisungen zur Einrichtung der Bluetooth-Kommunikation zwischen Ihrem ESP32 und Ihrem Mobilgerät mithilfe der LightBlue-App:

#. Laden Sie die LightBlue-App aus dem **App Store** (für iOS) oder von **Google Play** (für Android) herunter.

    .. image:: img/bluetooth_lightblue.png

#. Öffnen Sie die Datei ``Lesson_44_Bluetooth.ino`` im Verzeichnis ``universal-maker-sensor-kit\esp32\Lesson_44_Bluetooth`` oder kopieren Sie den Code in die Arduino IDE.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/3f42363e-1484-4c11-8d27-3a4d60b88a31/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

        
#. Um UUID-Konflikte zu vermeiden, wird empfohlen, drei neue UUIDs zufällig mit dem |link_uuid| zu generieren und sie in die folgenden Codezeilen einzufügen.

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. Wählen Sie das richtige Board und den richtigen Port aus und klicken Sie dann auf die Schaltfläche **Upload**.

    .. image:: img/bluetooth_upload.png

#. Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie **Bluetooth** auf Ihrem Mobilgerät ein und öffnen Sie die **LightBlue**-App.

    .. image:: img/bluetooth_open.png

#. Auf der **Scan**-Seite finden Sie **ESP32-Bluetooth** und klicken Sie auf **VERBINDEN**. Wenn es nicht angezeigt wird, versuchen Sie, die Seite ein paar Mal zu aktualisieren. Wenn **"Mit Gerät verbunden!"** erscheint, ist die Bluetooth-Verbindung erfolgreich. Scrollen Sie nach unten, um die drei im Code festgelegten UUIDs zu sehen.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Klicken Sie auf die **Empfangen** UUID. Wählen Sie das passende Datenformat im Feld rechts neben **Datenformat** aus, wie "HEX" für Hexadezimal, "UTF-8 String" für Zeichen oder "Binär" für Binär, usw. Klicken Sie dann auf **ABONNIEREN**.

    .. image:: img/bluetooth_read.png
        :width: 300

#. Gehen Sie zurück zur Arduino IDE, öffnen Sie den Serial Monitor, stellen Sie die Baudrate auf 115200 ein, geben Sie "welcome" ein und drücken Sie Enter.

    .. image:: img/bluetooth_serial.png

#. Sie sollten nun die Nachricht "welcome" in der LightBlue-App sehen.

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. Um Informationen vom Mobilgerät an den Serial Monitor zu senden, klicken Sie auf die Sende-UUID, stellen Sie das Datenformat auf "UTF-8 String" ein und schreiben Sie eine Nachricht.

    .. image:: img/bluetooth_send.png


#. Sie sollten die Nachricht im Serial Monitor sehen.

    .. image:: img/bluetooth_receive.png

**Wie funktioniert das?**

Dieser Arduino-Code ist für den ESP32-Mikrocontroller geschrieben und richtet ihn für die Kommunikation mit einem Bluetooth Low Energy (BLE)-Gerät ein.

Hier ist eine kurze Zusammenfassung des Codes:

* **Notwendige Bibliotheken einbinden**: Der Code beginnt mit dem Einbinden der notwendigen Bibliotheken für die Arbeit mit Bluetooth Low Energy (BLE) auf dem ESP32.

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **Globale Variablen**: Der Code definiert eine Reihe von globalen Variablen, einschließlich des Bluetooth-Gerätenamens (``bleName``), Variablen zur Verfolgung des empfangenen Textes und der Zeit der letzten Nachricht, UUIDs für den Dienst und die Charakteristiken sowie ein ``BLECharacteristic``-Objekt (``pCharacteristic``).

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
* **Setup**: In der Funktion ``setup()`` wird der serielle Port mit einer Baudrate von 115200 initialisiert und die Funktion ``setupBLE()`` aufgerufen, um das Bluetooth BLE einzurichten.

    .. code-block:: arduino
    
        void setup() {
            Serial.begin(115200);  // Initialize the serial port
            setupBLE();            // Initialize the Bluetooth BLE
        }

* **Hauptschleife**: In der Funktion ``loop()`` wird, wenn ein String über BLE empfangen wurde (d.h. ``receivedText`` nicht leer ist) und mindestens eine Sekunde seit der letzten Nachricht vergangen ist, der empfangene String im seriellen Monitor ausgegeben, der Charakteristikwert auf den empfangenen String gesetzt, eine Benachrichtigung gesendet und der empfangene String gelöscht. Wenn Daten auf dem seriellen Port verfügbar sind, wird der String bis zum Zeilenumbruch gelesen, der Charakteristikwert auf diesen String gesetzt und eine Benachrichtigung gesendet.

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

* **Callbacks**: Zwei Callback-Klassen (``MyServerCallbacks`` und ``MyCharacteristicCallbacks``) werden definiert, um Ereignisse im Zusammenhang mit der Bluetooth-Kommunikation zu behandeln. ``MyServerCallbacks`` wird verwendet, um Ereignisse im Zusammenhang mit dem Verbindungsstatus (verbunden oder getrennt) des BLE-Servers zu behandeln. ``MyCharacteristicCallbacks`` wird verwendet, um Schreibereignisse auf der BLE-Charakteristik zu behandeln, d.h. wenn ein verbundenes Gerät einen String über BLE an den ESP32 sendet, wird dieser erfasst und in ``receivedText`` gespeichert, und die aktuelle Zeit wird in ``lastMessageTime`` aufgezeichnet.

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
* **BLE Einrichten**: In der Funktion ``setupBLE()`` werden das BLE-Gerät und der Server initialisiert, die Server-Callbacks gesetzt, der BLE-Service mit der definierten UUID erstellt, Charakteristiken zum Senden von Benachrichtigungen und zum Empfangen von Daten erstellt und dem Service hinzugefügt sowie die Charakteristik-Callbacks gesetzt. Schließlich wird der Service gestartet und der Server beginnt mit dem Werben.

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

Bitte beachten Sie, dass dieser Code eine bidirektionale Kommunikation ermöglicht - er kann Daten über BLE senden und empfangen. 
Um jedoch mit spezifischer Hardware wie dem Ein- und Ausschalten einer LED zu interagieren, sollte zusätzlicher Code hinzugefügt werden, um die empfangenen Zeichenfolgen zu verarbeiten und entsprechend zu handeln.
