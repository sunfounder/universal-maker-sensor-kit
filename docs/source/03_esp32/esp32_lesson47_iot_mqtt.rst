.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_iot_mqtt:

Lektion 47: IoT-Kommunikation mit MQTT
==========================================

Dieses Projekt konzentriert sich auf die Nutzung von MQTT, einem beliebten Kommunikationsprotokoll im Bereich des Internets der Dinge (IoT). MQTT ermöglicht es IoT-Geräten, Daten mithilfe eines Publish/Subscribe-Modells auszutauschen, wobei Geräte über Themen (Topics) kommunizieren.

In diesem Projekt erkunden wir die Implementierung von MQTT, indem wir eine Schaltung mit einer LED, einem Taster und einem Thermistor aufbauen. Der ESP32-WROOM-32E-Mikrocontroller wird verwendet, um eine Verbindung zum WLAN herzustellen und mit einem MQTT-Broker zu kommunizieren. Der Code ermöglicht es dem Mikrocontroller, bestimmte Themen zu abonnieren, Nachrichten zu empfangen und die LED basierend auf den empfangenen Informationen zu steuern. Darüber hinaus demonstriert das Projekt das Veröffentlichen von Temperaturdaten des Thermistors in einem bestimmten Thema, wenn der Taster gedrückt wird.

**Benötigte Komponenten**

In diesem Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name    
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch einzeln über die folgenden Links kaufen.

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

**Code-Upload**

#. Bauen Sie die Schaltung auf.

    .. note:: 
        Beim Herstellen einer Verbindung zum WLAN können nur die Pins 36, 39, 34, 35, 32, 33 für das analoge Lesen verwendet werden. Bitte stellen Sie sicher, dass der Thermistor an diese bestimmten Pins angeschlossen ist.

    .. image:: img/Lesson_01_Button_Module_esp32_bb.png

#. Verbinden Sie dann den ESP32-WROOM-32E mit dem USB-Kabel mit dem Computer.


#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``Lesson_47_MQTT.ino`` im Verzeichnis ``universal-maker-sensor-kit\esp32\Lesson_47_MQTT`` oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf die Schaltfläche **Upload**.
    * :ref:`unknown_com_port`
    * Die Bibliothek ``PubSubClient`` wird hier verwendet und kann über den **Library Manager** installiert werden.

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3f33a562-ebaa-48ed-a3ba-ae11e0b9706f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Suchen Sie die folgenden Zeilen und passen Sie sie mit Ihrem ``<SSID>`` und ``<PASSWORD>`` an.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Suchen Sie die nächste Zeile und passen Sie Ihren ``unique_identifier`` an. Stellen Sie sicher, dass Ihr ``unique_identifier`` wirklich einzigartig ist, da identische IDs, die versuchen, sich beim selben MQTT-Broker anzumelden, zu einem Anmeldefehler führen können.

    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";  

**Topic-Abonnement**

#. Um Störungen durch Nachrichten anderer Teilnehmer zu vermeiden, können Sie einen ungewöhnlichen oder seltenen String festlegen. Ersetzen Sie einfach das aktuelle Topic ``SF/LED`` durch Ihren gewünschten Topic-Namen.

    .. note:: 
        Sie haben die Freiheit, das Topic auf beliebige Zeichen zu setzen. Jedes MQTT-Gerät, das dasselbe Topic abonniert hat, kann dieselbe Nachricht empfangen. Sie können auch gleichzeitig mehrere Topics abonnieren.

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

#. Ändern Sie die Funktionalität, um auf das abonnierte Topic zu reagieren. Im bereitgestellten Code wird, wenn eine Nachricht auf dem Topic ``SF/LED`` empfangen wird, überprüft, ob die Nachricht ``on`` oder ``off`` ist. Abhängig von der empfangenen Nachricht ändert sich der Ausgangszustand, um den LED-Status zu steuern.

    .. note::
       Sie können es für jedes abonniertes Topic anpassen und mehrere if-Anweisungen schreiben, um auf mehrere Topics zu reagieren.

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

#. Nachdem Sie das richtige Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf die Schaltfläche **Upload**.

#. Öffnen Sie den seriellen Monitor. Wenn die folgende Information ausgegeben wird, bedeutet dies, dass die Verbindung zum MQTT-Server erfolgreich hergestellt wurde.

    .. code-block:: 

        WiFi connected
        IP address: 
        192.168.18.77
        Attempting MQTT connection...connected

**Nachrichtenübermittlung über HiveMQ**

HiveMQ ist eine Messaging-Plattform, die als MQTT-Broker fungiert und eine schnelle, effiziente und zuverlässige Datenübertragung zu IoT-Geräten ermöglicht.

Unser Code nutzt den von HiveMQ bereitgestellten MQTT-Broker. Wir haben die Adresse des HiveMQ MQTT-Brokers im Code wie folgt eingefügt:


    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";

#. Öffnen Sie nun |link_hivemq| in Ihrem Webbrowser.

#. Verbinden Sie den Client mit dem Standard-Öffentlichkeits-Proxy.

    .. image:: img/sp230512_092258.png

#. Veröffentlichen Sie eine Nachricht im abonnierten Topic. In diesem Projekt können Sie ``on`` oder ``off`` veröffentlichen, um Ihre LED zu steuern.

    .. image:: img/sp230512_140234.png

**Nachrichtenübermittlung an MQTT**

Wir können den Code auch nutzen, um Informationen an das Topic zu senden. 
In dieser Demonstration haben wir eine Funktion programmiert, die eine einfache Nachricht an das Topic sendet, wenn Sie die Taste drücken.

#. Klicken Sie auf **Add New Topic Subscription**.

    .. image:: img/sp230512_092341.png

#. Füllen Sie die gewünschten Topics aus und klicken Sie auf **Subscribe**. Im Code senden wir eine Nachricht an das Topic ``SF/TEMP``.

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

#. Daher können wir dieses Topic auf HiveMQ überwachen und die Informationen anzeigen, die Sie veröffentlicht haben.

    .. image:: img/sp230512_154342.png
