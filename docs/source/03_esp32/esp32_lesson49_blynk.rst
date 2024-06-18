

.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_iot_intrusion_alert_system:

Lektion 49: Blynk-basiertes Einbruchmeldesystem
=============================================================

Dieses Projekt demonstriert ein einfaches Einbruchmeldesystem für zu Hause unter Verwendung eines PIR-Bewegungssensors (HC-SR501). 
Wenn das System über die Blynk-App auf den "Abwesenheitsmodus" eingestellt ist, überwacht der PIR-Sensor Bewegungen. 
Jede erkannte Bewegung löst eine Benachrichtigung in der Blynk-App aus, die den Benutzer auf einen möglichen Einbruch aufmerksam macht.

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

Sie können sie auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_pir_motion`
        - \-


1. Schaltungsaufbau
--------------------

.. image:: img/Lesson_12_PIR_Module_esp32_bb.png
    :width: 100%
    :align: center

2. Blynk Konfiguration
----------------------

**2.1 Initialisierung von Blynk**

#. Navigieren Sie zur |link_blynk| und wählen Sie **START FREE**. 

   .. image:: img/09_blynk_access.png
        :width: 90%

#. Geben Sie Ihre E-Mail-Adresse ein, um den Registrierungsprozess zu starten.

   .. image:: img/09_blynk_sign_in.png
        :width: 70%
        :align: center

#. Bestätigen Sie Ihre Registrierung über Ihre E-Mail.

    .. image:: img/09_blynk_password.png
        :width: 90%


#. Nach der Bestätigung erscheint der **Blynk-Tour**. Es wird empfohlen, "Überspringen" auszuwählen. Wenn auch **Schnellstart** angezeigt wird, sollten Sie diesen ebenfalls überspringen.
   
    .. image:: img/09_blynk_tour.png
        :width: 90%

**2.2 Erstellen einer Vorlage**

#. Erstellen Sie zuerst eine Vorlage in Blynk. Befolgen Sie die folgenden Anweisungen, um die Vorlage **Intrusion Alert System** zu erstellen.

    .. image:: img/09_create_template_1_shadow.png
        :width: 700
        :align: center

#. Weisen Sie der Vorlage einen Namen zu, wählen Sie **ESP32** Hardware aus und wählen Sie als **Verbindungstyp** **WiFi**. Klicken Sie dann auf **Fertig**.

    .. image:: img/09_create_template_2_shadow.png
        :width: 700
        :align: center

**2.3 Erstellen eines Datenstroms**

Öffnen Sie die gerade eingerichtete Vorlage, und erstellen Sie zwei Datenströme.

#. Klicken Sie auf **Neuer Datenstrom**.

    .. image:: img/09_blynk_new_datastream.png
        :width: 700
        :align: center

#. Wählen Sie im Popup **Virtueller Pin**.

    .. image:: img/09_blynk_datastream_virtual.png
        :width: 700
        :align: center

#. Benennen Sie den **Virtuellen Pin V0** als **AwayMode**. Setzen Sie den **DATENTYP** auf **Integer** mit **MIN** und **MAX** Werten von **0** und **1**.

    .. image:: img/09_create_template_shadow.png
        :width: 700
        :align: center

#. Erstellen Sie auf ähnliche Weise einen weiteren **Virtuellen Pin** Datenstrom. Benennen Sie ihn **Current Status** und setzen Sie den **DATENTYP** auf **String**.

    .. image:: img/09_datastream_1_shadow.png
        :width: 700
        :align: center

**2.4 Einrichten eines Ereignisses**

Als nächstes richten wir ein Ereignis ein, das eine E-Mail-Benachrichtigung sendet, wenn ein Einbruch erkannt wird.

#. Klicken Sie auf **Neues Ereignis hinzufügen**.

    .. image:: img/09_blynk_event_add.png

#. Definieren Sie den Namen des Ereignisses und seinen spezifischen Code. Wählen Sie für **TYP** **Warnung** und schreiben Sie eine kurze Beschreibung für die zu sendende E-Mail, wenn das Ereignis eintritt. Sie können auch einstellen, wie oft Sie benachrichtigt werden möchten.

    .. note::
        
        Stellen Sie sicher, dass der **EREIGNISCODE** auf ``intrusion_detected`` gesetzt ist. Dies ist im Code vordefiniert, sodass Änderungen auch eine Anpassung des Codes erfordern würden.

    .. image:: img/09_event_1_shadow.png
        :width: 700
        :align: center

#. Gehen Sie zum Abschnitt **Benachrichtigungen**, um Benachrichtigungen zu aktivieren und E-Mail-Details einzurichten.

    .. image:: img/09_event_2_shadow.png
        :width: 80%
        :align: center

.. raw:: html
    
    <br/> 

**2.5 Feinabstimmung des Web-Dashboards**

Stellen Sie sicher, dass das **Web-Dashboard** perfekt mit dem Einbruchmeldesystem interagiert.

#. Ziehen Sie einfach sowohl das **Schalter-Widget** als auch das **Beschriftungs-Widget** auf das **Web-Dashboard**.

    .. image:: img/09_web_dashboard_1_shadow.png
        :width: 100%
        :align: center

#. Wenn Sie über ein Widget fahren, erscheinen drei Symbole. Verwenden Sie das Einstellungssymbol, um die Eigenschaften des Widgets anzupassen.

    .. image:: img/09_blynk_dashboard_set.png
        :width: 100%
        :align: center

#. Wählen Sie in den Einstellungen des **Schalter-Widgets** **Datenstrom** als **AwayMode(V0)**. Setzen Sie **ONLABEL** und **OFFLABEL** auf **"away"** bzw. **"home"**.

    .. image:: img/09_web_dashboard_2_shadow.png
        :width: 100%
        :align: center

#. Wählen Sie in den Einstellungen des **Beschriftungs-Widgets** **Datenstrom** als **Current Status(V1)**.

    .. image:: img/09_web_dashboard_3_shadow.png
        :width: 100%
        :align: center

**2.6 Speichern der Vorlage**

Vergessen Sie zuletzt nicht, Ihre Vorlage zu speichern.

    .. image:: img/09_save_template_shadow.png
        :width: 100%
        :align: center


**2.7 Erstellung eines Geräts**

#. Jetzt ist es an der Zeit, ein neues Gerät zu erstellen.

    .. image:: img/09_blynk_device_new.png
        :width: 700
        :align: center

#. Klicken Sie auf **Aus Vorlage**, um eine neue Einrichtung zu starten.

    .. image:: img/09_blynk_device_template.png
        :width: 700
        :align: center

#. Wählen Sie dann die Vorlage **Intrusion Alert System** und klicken Sie auf **Erstellen**.

    .. image:: img/09_blynk_device_template2.png
        :width: 700
        :align: center

#. Hier sehen Sie die ``Template ID``, den ``Gerätenamen`` und das ``AuthToken``. Diese müssen Sie in Ihren Code einfügen, damit das ESP32 mit Blynk arbeiten kann.

    .. image:: img/09_blynk_device_code.png
        :width: 700
        :align: center

3. Code-Ausführung
-----------------------------
#. Bevor Sie den Code ausführen, stellen Sie sicher, dass Sie die ``Blynk``-Bibliothek aus dem **Bibliotheks-Manager** der Arduino IDE installiert haben.

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#. Öffnen Sie die Datei ``Lesson_49_Blynk_based_intrusion_system.ino``, die sich im Verzeichnis ``universal-maker-sensor-kit\esp32\Lesson_49_Blynk_based_intrusion_system`` befindet. Sie können den Inhalt auch in die Arduino IDE kopieren.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/987fb2fd-47e9-4a73-9020-6b2111eadd9c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Ersetzen Sie die Platzhalter für ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME`` und ``BLYNK_AUTH_TOKEN`` durch Ihre eigenen eindeutigen IDs.

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. Sie müssen auch die ``ssid`` und das ``password`` Ihres WiFi-Netzwerks eingeben.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. Wählen Sie das richtige Board (**ESP32 Dev Module**) und den richtigen Port aus und klicken Sie dann auf die Schaltfläche **Hochladen**.

#. Öffnen Sie den Serial Monitor (stellen Sie die Baudrate auf 115200 ein) und warten Sie auf eine erfolgreiche Verbindungsnachricht.

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. Nach einer erfolgreichen Verbindung wird durch Aktivieren des Schalters in Blynk das Überwachungsmodul des PIR-Sensors gestartet. Wenn eine Bewegung erkannt wird (Status 1), erscheint die Nachricht "Somebody here!" und es wird eine Warnung an Ihre E-Mail gesendet.

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. Code-Erklärung
-----------------------------

#. **Konfiguration & Bibliotheken**

   Hier richten Sie die Blynk-Konstanten und Anmeldeinformationen ein. Außerdem binden Sie die notwendigen Bibliotheken für den ESP32 und Blynk ein.

    .. code-block:: arduino

        /* Comment this out to disable prints and save space */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **WiFi-Einrichtung**

   Geben Sie Ihre WiFi-Anmeldeinformationen ein.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **PIR-Sensor-Konfiguration**

   Legen Sie den Pin fest, an dem der PIR-Sensor angeschlossen ist, und initialisieren Sie die Zustandsvariablen.

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **setup() Funktion**

   Diese Funktion initialisiert den PIR-Sensor als Eingang, richtet die serielle Kommunikation ein, stellt die Verbindung zum WiFi her und konfiguriert Blynk.

   - Wir verwenden ``timer.setInterval(1000L, myTimerEvent)``, um das Timer-Intervall in ``setup()`` festzulegen. Hier stellen wir ein, dass die Funktion ``myTimerEvent()`` alle **1000ms** ausgeführt wird. Sie können den ersten Parameter von ``timer.setInterval(1000L, myTimerEvent)`` ändern, um das Intervall zwischen den Ausführungen von ``myTimerEvent`` zu ändern.

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
#. **loop() Funktion**

   Die loop-Funktion führt kontinuierlich Blynk- und Blynk-Timer-Funktionen aus.

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }

#. **Interaktion mit der Blynk-App**

   Diese Funktionen werden aufgerufen, wenn das Gerät eine Verbindung zu Blynk herstellt und wenn sich der Zustand des virtuellen Pins V0 in der Blynk-App ändert.

   - Jedes Mal, wenn das Gerät eine Verbindung zum Blynk-Server herstellt oder aufgrund schlechter Netzwerkbedingungen neu verbindet, wird die Funktion ``BLYNK_CONNECTED()`` aufgerufen. Der Befehl ``Blynk.syncVirtual()`` fordert einen einzelnen Wert des virtuellen Pins an. Der angegebene virtuelle Pin wird den Aufruf ``BLYNK_WRITE()`` durchführen.

   - Jedes Mal, wenn sich der Wert eines virtuellen Pins auf dem BLYNK-Server ändert, wird ``BLYNK_WRITE()`` ausgelöst.

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

#. **Datenverarbeitung**

   Jede Sekunde ruft die Funktion ``myTimerEvent()`` die Funktion ``sendData()`` auf. Wenn der Abwesenheitsmodus in Blynk aktiviert ist, überprüft sie den PIR-Sensor und sendet eine Benachrichtigung an Blynk, wenn eine Bewegung erkannt wird.

   - Wir verwenden ``Blynk.virtualWrite(V1, "Somebody in your house! Please check!");``, um den Text eines Labels zu ändern.

   - Verwenden Sie ``Blynk.logEvent("intrusion_detected");``, um ein Ereignis in Blynk zu protokollieren.

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

**Referenzen**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|
