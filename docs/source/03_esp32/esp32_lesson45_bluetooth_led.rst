.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_bluetooth_led:


Lesson 45: Bluetooth-gesteuerte RGB-LED
===============================================

Dieses Projekt ist eine Erweiterung eines vorherigen Projekts (:ref:`esp32_bluetooth`), 
das RGB-LED-Konfigurationen und benutzerdefinierte Befehle wie "led_off", "red", "green" usw. hinzufügt. Diese Befehle ermöglichen es, die RGB-LED durch das Senden von Befehlen von einem mobilen Gerät mit LightBlue zu steuern.

**Benötigte Komponenten**

In diesem Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch einzeln über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**Betriebsschritte**

#. Bauen Sie die Schaltung auf.

    .. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png

#. Öffnen Sie die Datei ``Lesson_45_Bluetooth_RGB.ino``, die sich im Verzeichnis ``universal-maker-sensor-kit\esp32\Lesson_45_Bluetooth_RGB`` befindet, oder kopieren Sie den Code in die Arduino IDE.

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/714bacdf-4ee6-4f6e-8ac3-04e328154d7a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Um UUID-Konflikte zu vermeiden, wird empfohlen, drei neue UUIDs zufällig zu generieren, indem Sie den |link_uuid| verwenden, der von der Bluetooth SIG bereitgestellt wird, und diese in den folgenden Codezeilen ausfüllen.

    .. note::
        Wenn Sie bereits drei neue UUIDs im Projekt :ref:`esp32_bluetooth` generiert haben, können Sie diese weiterverwenden.


    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png
#. Wählen Sie das richtige Board und den richtigen Port aus und klicken Sie dann auf die Schaltfläche **Upload**.

#. Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie **Bluetooth** auf Ihrem mobilen Gerät ein und öffnen Sie die **LightBlue**-App.

    .. image:: img/bluetooth_open.png

#. Suchen Sie auf der **Scan**-Seite nach **ESP32-Bluetooth** und klicken Sie auf **CONNECT**. Wenn Sie es nicht sehen, versuchen Sie die Seite ein paar Mal zu aktualisieren. Wenn **"Connected to device!"** erscheint, ist die Bluetooth-Verbindung erfolgreich. Scrollen Sie nach unten, um die drei im Code festgelegten UUIDs zu sehen.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Tippen Sie auf die Send UUID, stellen Sie das Datenformat auf "UTF-8 String" ein. Jetzt können Sie diese Befehle schreiben: "led_off", "red", "green", "blue", "yellow" und "purple", um zu sehen, ob die RGB-LED auf diese Anweisungen reagiert.

    .. image:: img/bluetooth_send_rgb.png
    

**Wie es funktioniert**

Dieser Code ist eine Erweiterung eines vorherigen Projekts (:ref:`esp32_bluetooth`), der RGB-LED-Konfigurationen und benutzerdefinierte Befehle wie "led_off", "red", "green" usw. hinzufügt. Diese Befehle ermöglichen es, die RGB-LED durch das Senden von Befehlen von einem mobilen Gerät mit LightBlue zu steuern.

Lassen Sie uns den Code Schritt für Schritt aufschlüsseln:

* Fügen Sie neue globale Variablen für die RGB-LED-Pins, PWM-Kanäle, Frequenz und Auflösung hinzu.

    .. code-block:: arduino

        ...

        // Define RGB LED pins
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        // Define PWM channels
        const int redChannel = 0;
        const int greenChannel = 1;
        const int blueChannel = 2;

        ...

* Innerhalb der ``setup()``-Funktion werden die PWM-Kanäle mit der vordefinierten Frequenz und Auflösung initialisiert. Die RGB-LED-Pins werden dann ihren jeweiligen PWM-Kanälen zugewiesen.

    .. code-block:: arduino
        
        void setup() {
            ...

            // Set up PWM channels
            ledcSetup(redChannel, freq, resolution);
            ledcSetup(greenChannel, freq, resolution);
            ledcSetup(blueChannel, freq, resolution);
            
            // Attach pins to corresponding PWM channels
            ledcAttachPin(redPin, redChannel);
            ledcAttachPin(greenPin, greenChannel);
            ledcAttachPin(bluePin, blueChannel);

        }

* Modifizieren Sie die Methode ``onWrite`` in der Klasse ``MyCharacteristicCallbacks``. Diese Funktion hört auf Daten, die über die Bluetooth-Verbindung empfangen werden. Basierend auf dem empfangenen String (wie ``"led_off"``, ``"red"``, ``"green"`` usw.) steuert sie die RGB-LED.

    .. code-block:: arduino

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = pCharacteristic->getValue();
                if (value == "led_off") {
                    setColor(0, 0, 0); // turn the RGB LED off
                    Serial.println("RGB LED turned off");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Red
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // green
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // blue
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // yellow
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // purple
                    Serial.println("purple");
                }
            }
        };

* Schließlich wird eine Funktion hinzugefügt, um die Farbe der RGB-LED festzulegen.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redChannel, red);
            ledcWrite(greenChannel, green);
            ledcWrite(blueChannel, blue);
        }

Zusammengefasst ermöglicht dieses Skript ein Fernsteuerungsmodell, bei dem der ESP32 als Bluetooth Low Energy (BLE) Server fungiert.

Der verbundene BLE-Client (z. B. ein Smartphone) kann String-Befehle senden, um die Farbe einer RGB-LED zu ändern. Der ESP32 gibt auch Feedback an den Client zurück, indem er den empfangenen String zurücksendet, sodass der Client weiß, welche Operation ausgeführt wurde.
