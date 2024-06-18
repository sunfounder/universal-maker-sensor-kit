
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_iot_vib_alert_system:

Lektion 49: Vibrationswarnsystem mit IFTTT
=====================================================

Dieses Projekt richtet ein Vibrationserkennungssystem mit einem Arduino-Board (Uno R4 oder R3), einem ESP8266-Modul und einem Vibrationsensor (SW-420) ein. Wenn eine Vibration erkannt wird, sendet das System eine HTTP-Anfrage an einen IFTTT-Server, wodurch verschiedene Aktionen wie das Senden einer Benachrichtigung oder einer E-Mail ausgelöst werden können.

Um übermäßige Warnungen innerhalb eines kurzen Zeitraums zu vermeiden, wurde das System so programmiert, dass diese HTTP-Anfragen in einem Mindestintervall von 2 Minuten (120.000 Millisekunden) gesendet werden. Dieses Intervall könnte je nach den Bedürfnissen des Benutzers angepasst werden.

Erforderliche Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

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

Verkabelung
---------------------------

.. image:: img/Lesson_49_Iot_vibration_alert_system_uno_bb.png
    :width: 100%

Konfigurieren von IFTTT
-----------------------------

|link_ifttt| ist ein privates kommerzielles Unternehmen, das im Jahr 2011 gegründet wurde und Online-Digitalautomatisierungsplattformen betreibt, die es als Dienstleistung anbietet. Ihre Plattformen bieten Benutzern eine visuelle Schnittstelle zum Erstellen plattformübergreifender if-Statements, die bis 2020 18 Millionen Menschen nutzen.

.. image:: img/04-ifttt_intro.png
    :width: 100%

IFTTT steht für "If This Then That". Grundsätzlich, wenn bestimmte Bedingungen erfüllt sind, wird etwas anderes passieren. Der "wenn dies" Teil wird Auslöser genannt und der "dann das" Teil wird Aktion genannt. Es verbindet Smart-Home-Geräte, soziale Medien, Liefer-Apps und mehr, um automatisierte Aufgaben auszuführen.

.. image:: img/04-ifttt_intro_2A.png
    :width: 100%
**1) Anmelden bei IFTTT**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Geben Sie "https://ifttt.com" in Ihren Browser ein und klicken Sie auf die Schaltfläche "Loslegen", die sich in der Mitte der Seite befindet. Füllen Sie das Formular mit Ihren Informationen aus, um ein Konto zu erstellen.

.. image:: img/04-ifttt_signup.png
    :width: 90%
    :align: center

Klicken Sie auf "Zurück", um das Schnellstartfenster zu verlassen, kehren Sie zur IFTTT-Startseite zurück, aktualisieren Sie die Seite und melden Sie sich erneut an.

.. image:: img/04-ifttt_signup_2.png
    :width: 90%
    :align: center


**2) Erstellen des Applets**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Klicken Sie auf "Erstellen", um mit der Erstellung des Applets zu beginnen.

.. image:: img/04-ifttt_create_applet_1_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/>  

**Wenn dieser Auslöser**

Klicken Sie neben "Wenn dies" auf "Hinzufügen", um einen Auslöser hinzuzufügen.

.. image:: img/04-ifttt_create_applet_2_shadow.png
    :width: 80%
    :align: center

Suchen Sie nach "Webhook" und klicken Sie auf "Webhooks".

.. image:: img/04-ifttt_create_applet_3_shadow.png
    :width: 80%
    :align: center

Klicken Sie auf "Eine Webanforderung empfangen" auf der in folgendem Bild gezeigten Seite.

.. image:: img/04-ifttt_create_applet_4_shadow.png
    :width: 80%
    :align: center

Setzen Sie den "Ereignisnamen" auf "vibration_detected".

.. image:: img/04-ifttt_create_applet_5_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/>  
**Dann diese Aktion**

Klicken Sie auf "Hinzufügen" neben "Dann das", um eine Aktion hinzuzufügen.

.. image:: img/04-ifttt_create_applet_6_shadow.png
    :width: 80%
    :align: center

Suchen Sie nach "E-Mail" und klicken Sie auf "E-Mail".

.. image:: img/04-ifttt_create_applet_7_shadow.png
    :width: 80%
    :align: center

Klicken Sie auf "Sende mir eine E-Mail" auf der Seite, die im folgenden Bild gezeigt wird.

.. image:: img/04-ifttt_create_applet_8_shadow.png
    :width: 80%
    :align: center

Legen Sie den Betreff und den Inhalt der E-Mail fest, die bei Erkennung von Vibrationen gesendet werden sollen.

Als Referenz ist der Betreff auf "[ESP-01] Vibration erkannt!!!" festgelegt und der Inhalt auf "Vibration erkannt, bitte bestätigen Sie die Situation umgehend! {{OccurredAt}}". Beim Senden einer E-Mail wird ``{{OccurredAt}}`` automatisch durch die Zeit ersetzt, zu der das Ereignis aufgetreten ist.

.. image:: img/04-ifttt_create_applet_9_shadow.png
    :width: 80%
    :align: center

Führen Sie die Erstellung des Applets gemäß den folgenden Schritten durch.

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
Code
----------------------- 


#. Öffnen Sie die Datei ``Lesson_49_Vibration_alert_system.ino`` im Pfad ``universal-maker-sensor-kit\arduino_uno\Lesson_49_Vibration_alert_system``, oder kopieren Sie diesen Code in die **Arduino IDE**.

   .. raw:: html
       
        <iframe src=https://create.arduino.cc/editor/sunfounder01/35a75e1c-6b2a-407d-9724-f83ad50a4a41/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Geben Sie das ``mySSID`` und ``myPWD`` des WiFi-Netzwerks ein, das Sie verwenden. 

   .. code-block:: arduino

    String mySSID = "your_ssid";     // WiFi SSID
    String myPWD = "your_password";  // WiFi Password

#. Ändern Sie auch die ``URL`` mit dem Ereignisnamen, den Sie festgelegt haben, und Ihrem API-Schlüssel.

   .. code-block:: arduino
    
      String URL = "/trigger/vibration_detected/with/key/xxxxxxxxxxxxxxxxxx";

   .. image:: img/04-ifttt_apikey_1_shadow.png
       :width: 80%
       :align: center
   
   .. image:: img/04-ifttt_apikey_2_shadow.png
       :width: 80%
       :align: center

   Hier finden Sie **Ihren eindeutigen API-Schlüssel, den Sie privat halten müssen**. Geben Sie den Ereignisnamen als ``vibration_detected`` ein. Ihre endgültige URL wird am unteren Rand der Webseite angezeigt. Kopieren Sie diese URL.

   .. image:: img/04-ifttt_apikey_3_shadow.png
       :width: 80%
       :align: center

   .. image:: img/04-ifttt_apikey_4_shadow.png
       :width: 80%
       :align: center

#. Nach Auswahl des richtigen Boards und Ports klicken Sie auf die **Upload**-Schaltfläche.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf **9600** eingestellt) und warten Sie auf eine Meldung wie eine erfolgreiche Verbindung.

   .. image:: img/04-ready_shadow.png
          :width: 95%


Codeanalyse
---------------------------

Das ESP8266-Modul, das mit dem Kit geliefert wird, ist bereits mit AT-Firmware vorprogrammiert. Daher kann das ESP8266-Modul über AT-Befehle gesteuert werden. In diesem Projekt verwenden wir SoftwareSerial, um die Kommunikation zwischen dem Arduino Uno-Board und dem ESP8266-Modul zu ermöglichen. Das Arduino Uno-Board sendet AT-Befehle an das ESP8266-Modul für die Netzwerkverbindung und den Versand von Anfragen. Sie können sich auf |link_esp8266_at| beziehen.

Das Uno-Board liest die Sensorwerte und sendet AT-Befehle an das ESP8266-Modul. Das ESP8266-Modul verbindet sich mit einem Netzwerk und sendet Anfragen an IFTTT-Server. 

#. Schließen Sie die SoftwareSerial-Bibliothek für die serielle Kommunikation zwischen Arduino und ESP8266 ein.

   .. code-block:: arduino
   
     #include <SoftwareSerial.h>      
     SoftwareSerial espSerial(2, 3);  

#. Konfigurieren Sie WiFi-Anmeldeinformationen und IFTTT-Serverdetails.

   .. code-block:: arduino
   
     String mySSID = "your_ssid";     
     String myPWD = "your_password";  
     String myHOST = "maker.ifttt.com";
     String myPORT = "80";
     String URL = "/trigger/xxx/with/key/xxxx";  

#. Definiere Variablen für den Vibrationssensor und die Steuerung der Alarmfrequenz

   .. code-block:: arduino
   
     unsigned long lastAlertTime = 0;                
     const unsigned long postingInterval = 120000L;
     const int sensorPin = 7;

#. In ``setup()``, initialisiere die serielle Kommunikation, das ESP8266-Modul und verbinde mit WiFi

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

#. In ``loop()``, erkenne Vibrationen und sende Alarm, wenn Zeitintervall abgelaufen ist

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

#. sendeAlarm() konstruiert die HTTP-Anfrage und sendet sie über ESP8266

   .. code-block:: arduino
   
     void sendAlert() {
   
       String sendData = "GET " + URL + " HTTP/1.1" + "\r\n";
       sendData += "Host: maker.ifttt.com\r\n";
       
       sendATCommand("AT+CIPMUX=0",1000,DEBUG);                           
       sendATCommand("AT+CIPSTART=...",3000,DEBUG);  
       sendATCommand("AT+CIPSEND=" + String(sendData.length()),1000,DEBUG);   
       espSerial.println(sendData);
      
     }  

#. Umgang mit AT-Befehlen in sendeATBefehl()

   Diese Funktion sendet AT-Befehle an das ESP8266 und sammelt die Antworten. 
   
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



**Referenz**

* |link_esp8266_at|
* |link_ifttt_welcome|
* |link_ifttt_webhook_faq|