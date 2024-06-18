
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_iot_intrusion_alert_system:

Lektion 51: Einbruchsalarm-System mit Blynk
===================================================================



Dieses Projekt demonstriert ein einfaches Home-Einbruchserkennungssystem unter Verwendung eines passiven Infrarotsensors (PIR) (HC-SR501).
Wenn das System über die Blynk-App auf den Modus 'Abwesend' eingestellt ist, überwacht der PIR-Sensor Bewegungen.
Jede erkannte Bewegung löst eine Benachrichtigung in der Blynk-App aus und informiert den Benutzer über mögliche Eindringlinge.


Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten. 

Es ist definitiv bequem, ein ganzes Kit zu kaufen, hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch separat über die unten stehenden Links kaufen.

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
    *   - :ref:`cpn_pir_motion`
        - \-


Verkabelung
---------------------------

.. image:: img/Lesson_51_Iot_intrusion_alert_system_uno_bb.png
    :width: 100%


Blynk konfigurieren
-----------------------------

.. note::
    Wenn Sie mit Blynk nicht vertraut sind, wird dringend empfohlen, dass Sie zunächst diese beiden Tutorials lesen. :ref:`iot_blynk_start` ist eine Anleitung für Anfänger für Blynk, die erklärt, wie man ESP8266 konfiguriert und sich bei Blynk registriert. Und :ref:`uno_iot_Flame` ist ein einfaches Beispiel, aber die Beschreibung der Schritte wird detaillierter sein.

**1 Vorlage erstellen**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Zunächst müssen wir eine Vorlage auf Blynk erstellen. Befolgen Sie die unten stehenden Schritte, um eine **"Einbruchsalarm-System"**-Vorlage zu erstellen.

.. image:: img/02-create_template_shadow.png
    :width: 80%
    :align: center

**2 Datenstrom**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Erstellen Sie **Datenströme** vom Typ **Virtueller Pin** auf der Seite **Datenstrom**, um Daten von ESP8266 und Uno R4 Board zu empfangen.

* Erstellen Sie den virtuellen Pin V0 gemäß dem folgenden Diagramm: 

  Setzen Sie den Namen des **virtuellen Pins V0** auf **AwayMode**. Setzen Sie den **DATENTYP** auf **Integer** und MIN und MAX auf **0** und **1**.

  .. image:: img/02-datastream_1_shadow.png
      :width: 90%

* Erstellen Sie den virtuellen Pin V1 gemäß dem folgenden Diagramm: 

  Setzen Sie den Namen des **virtuellen Pins V1** auf **Aktueller Status**. Setzen Sie den **DATENTYP** auf **String**.

  .. image:: img/02-datastream_2_shadow.png
      :width: 90%

Stellen Sie sicher, dass Sie gemäß den oben genannten Schritten zwei virtuelle Pins eingerichtet haben.

.. image:: img/02-datastream_3_shadow.png
    :width: 100%


.. raw:: html
    
    <br/> 

**3 Ereignis**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Als nächstes werden wir ein **Ereignis** erstellen, das das Erkennen von Eindringlingen protokolliert und eine E-Mail-Benachrichtigung sendet.

.. note::
    Es wird empfohlen, es konsistent mit meinen Einstellungen zu halten, da Sie andernfalls möglicherweise den Code anpassen müssen, um das Projekt auszuführen. Stellen Sie sicher, dass der **EREIGNISCODE** als ``intrusion_detected`` festgelegt ist.

.. image:: img/02-event_1_shadow.png
    :width: 90%
    :align: center

Gehen Sie zur **Benachrichtigungen**-Seite und konfigurieren Sie die E-Mail-Einstellungen.

.. image:: img/02-event_2_shadow.png
    :width: 90%
    :align: center

.. raw:: html

    <br/> 
**4 Web-Dashboard konfigurieren**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Wir müssen auch das **Web-Dashboard** konfigurieren, um mit dem Einbruchsalarm-System interagieren zu können.

Ziehen Sie ein **Schalter-Widget** und ein **Label-Widget** auf die Seite des **Web-Dashboards**.

.. image:: img/02-web_dashboard_1_shadow.png
    :width: 100%
    :align: center

Auf der Einstellungsseite des **Schalter-Widgets** wählen Sie **Datenstrom** als **AwayMode (V0)** aus. Legen Sie **ONLABEL** und **OFFLABEL** fest, um "nicht zu Hause" anzuzeigen, wenn der Schalter eingeschaltet ist, und "zu Hause" wenn der Schalter ausgeschaltet ist.

.. image:: img/02-web_dashboard_2_shadow.png
    :width: 100%
    :align: center

Auf der Einstellungsseite des **Label-Widgets** wählen Sie **Datenstrom** als **Aktueller Status (V1)** aus.

.. image:: img/02-web_dashboard_3_shadow.png
    :width: 100%
    :align: center

**5 Vorlage speichern**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Zuletzt, denken Sie daran, die Vorlage zu speichern.

.. image:: img/02-save_template_shadow.png
    :width: 70%
    :align: center

.. raw:: html
    
    <br/>  


Code
----------------------- 

#. Öffnen Sie die Datei ``Lesson_51_Intrusion_alert_system.ino`` im Pfad ``universal-maker-sensor-kit\arduino_uno\Lesson_51_Intrusion_alert_system``, oder kopieren Sie diesen Code in die **Arduino IDE**.

   .. raw:: html
       
       <iframe src=https://create.arduino.cc/editor/sunfounder01/e94c0b5e-1fcd-46aa-bc95-0395efee1d32/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Erstellen Sie ein Blynk-Gerät mit der Vorlage "Einbruchsalarm-System". Ersetzen Sie dann ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME`` und ``BLYNK_AUTH_TOKEN`` durch Ihre eigenen.

   .. code-block:: arduino
    
      #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
      #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
      #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. Geben Sie auch die ``ssid`` und ``password`` des WLANs ein, das Sie verwenden.

   .. code-block:: arduino

    char ssid[] = "your_ssid";
    char pass[] = "your_password";

#. Wählen Sie nach Auswahl des richtigen Boards und Ports die Schaltfläche **Hochladen**.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie auf eine Meldung, z. B. eine erfolgreiche Verbindung.

   .. image:: img/02-ready_1_shadow.png
    :width: 80%
    :align: center

   .. note::

       Wenn die Meldung "ESP antwortet nicht" angezeigt wird, wenn Sie eine Verbindung herstellen, befolgen Sie diese Schritte.

       * Make sure the 9V battery is plugged in.
       * Reset the ESP8266 module by connecting the pin RST to GND for 1 second, then unplug it.
       * Press the reset button on the R4 board.

       Manchmal müssen Sie die oben genannten Operationen 3-5 Mal wiederholen, bitte haben Sie Geduld.

Code-Analyse
---------------------------

#. **Konfiguration & Bibliotheken**

   Hier werden Konstanten und Anmeldeinformationen für Blynk eingerichtet. Erforderliche Bibliotheken für das ESP8266 WiFi-Modul und Blynk werden eingebunden.

   .. code-block:: arduino

      #define BLYNK_TEMPLATE_ID "TMPxxxx"
      #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
      #define BLYNK_AUTH_TOKEN "xxxxxx-"
      #define BLYNK_PRINT Serial

      #include <ESP8266_Lib.h>
      #include <BlynkSimpleShieldEsp8266.h>

#. **WiFi-Einrichtung**

   Konfigurieren Sie die WiFi-Anmeldeinformationen und richten Sie die Software-Serial-Kommunikation mit dem ESP01-Modul ein.

   .. code-block:: arduino

      char ssid[] = "your_ssid";
      char pass[] = "your_password";

      SoftwareSerial EspSerial(2, 3);
      #define ESP8266_BAUD 115200
      ESP8266 wifi(&EspSerial);

#. **PIR-Sensor-Konfiguration**

   Definieren Sie den Pin, an dem der PIR-Sensor angeschlossen ist, und initialisieren Sie Zustandsvariablen.

   .. code-block:: arduino

      const int sensorPin = 8;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **setup() Funktion**

   Diese initialisiert den PIR-Sensor als Eingang, richtet die serielle Kommunikation ein, verbindet sich mit WiFi und konfiguriert Blynk.

   - Wir verwenden ``timer.setInterval(1000L, myTimerEvent)``, um das Timerintervall in setup() festzulegen. Hier setzen wir die Ausführung der Funktion ``myTimerEvent()`` alle **1000ms**. Sie können den ersten Parameter von ``timer.setInterval(1000L, myTimerEvent)`` ändern, um das Intervall zwischen den Ausführungen von ``myTimerEvent`` zu ändern.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

      void setup() {
         pinMode(sensorPin, INPUT);
         Serial.begin(115200);
         EspSerial.begin(ESP8266_BAUD);
         delay(10);
         Blynk.config(wifi, BLYNK_AUTH_TOKEN);
         Blynk.connectWiFi(ssid, pass);
         timer.setInterval(1000L, myTimerEvent);
      }

#. **loop() Funktion**

   Die loop Funktion führt wiederholt Blynk und die Blynk Timer-Funktionen aus.

   .. code-block:: arduino

      void loop() {
         Blynk.run();
         timer.run();
      }

#. **Interaktion mit der Blynk-App**

   Diese Funktionen werden aufgerufen, wenn das Gerät sich mit Blynk verbindet und wenn sich der Zustand des virtuellen Pins V0 in der Blynk-App ändert.

   - Jedes Mal, wenn das Gerät eine Verbindung zum Blynk-Server herstellt oder sich aufgrund schlechter Netzwerkbedingungen erneut verbindet, wird die Funktion ``BLYNK_CONNECTED()`` aufgerufen. Der Befehl ``Blynk.syncVirtual()`` fordert einen einzigen Wert des virtuellen Pins an. Der angegebene virtuelle Pin wird den Aufruf ``BLYNK_WRITE()`` durchführen. Bitte beachten Sie |link_blynk_syncing| für weitere Details.

   - Immer wenn sich der Wert eines virtuellen Pins auf dem BLYNK-Server ändert, wird ``BLYNK_WRITE()`` ausgelöst. Weitere Details unter |link_blynk_write|.

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

   - Wir verwenden ``Blynk.virtualWrite(V1, "Jemand ist in Ihrem Haus! Bitte überprüfen!");`` um den Text eines Labels zu ändern.

   - Verwenden Sie ``Blynk.logEvent("Einbruch erkannt");`` um ein Ereignis in Blynk zu protokollieren.

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


**Referenz**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|