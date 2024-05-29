
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_bluetooth_traffic_light:

Lektion 47: Bluetooth-Verkehrsampel
=============================================================

Dieses Projekt ist darauf ausgelegt, eine Verkehrsampel (Rote, Gelbe, Grüne LEDs) mithilfe der Bluetooth-Kommunikation zu steuern. Der Benutzer kann einen Buchstaben ('R', 'Y' oder 'G') von einem Bluetooth-Gerät senden. Wenn der Arduino einen dieser Buchstaben empfängt, leuchtet die entsprechende LED auf, während sichergestellt wird, dass die anderen beiden LEDs ausgeschaltet sind.


Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten:

Ein ganzes Kit zu kaufen ist definitiv praktisch, hier ist der Link:

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

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_traffic`
        - \-
    *   - :ref:`cpn_jdy31`
        - \-


Verkabelung
---------------------------

.. image:: img/Lesson_47_Bluetooth_traffic_light_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5b9bd574-c807-4370-8e09-61f5f5a60b42/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


App und Bluetooth-Modul Verbindung
-----------------------------------------------
Wir können eine App namens "Serial Bluetooth Terminal" verwenden, um Nachrichten vom Bluetooth-Modul an den Arduino zu senden.

a. **Installieren von Serial Bluetooth Terminal**

   Gehen Sie zum Google Play, um |link_serial_bluetooth_terminal| herunterzuladen und zu installieren.


b. **Bluetooth verbinden**

   Schalten Sie zunächst **Bluetooth** auf Ihrem Smartphone ein.
   
      .. image:: img/09-app_1_shadow.png
         :width: 60%
         :align: center
   
   Gehen Sie auf Ihrem Smartphone zu den **Bluetooth-Einstellungen** und suchen Sie nach Namen wie **JDY-31-SPP**.
   
      .. image:: img/09-app_2_shadow.png
         :width: 60%
         :align: center
   
   Klicken Sie darauf und stimmen Sie der **Koppelanforderung** im Popup-Fenster zu. Wenn Sie nach einem Pairing-Code gefragt werden, geben Sie bitte "1234" ein.
   
      .. image:: img/09-app_3_shadow.png
         :width: 60%
         :align: center
   

c. **Kommunikation mit dem Bluetooth-Modul**

   Öffnen Sie das Serial Bluetooth Terminal. Verbinden Sie sich mit "JDY-31-SPP".

   .. image:: img/00-bluetooth_serial_4_shadow.png 

d. **Befehl senden**

   Verwenden Sie die Serial Bluetooth Terminal-App, um Befehle an den Arduino über Bluetooth zu senden. Senden Sie R, um das rote Licht einzuschalten, Y für gelb und G für grün.

   .. image:: img/16-R_shadow.png 
      :width: 85%
      :align: center

   .. image:: img/16-Y_shadow.png 
      :width: 85%
      :align: center

   .. image:: img/16-G_shadow.png 
      :width: 85%
      :align: center




Code Analyse
---------------------------


#. Initialisierung und Bluetooth-Setup

   .. code-block:: arduino

      // Set up Bluetooth module communication
      #include <SoftwareSerial.h>
      const int bluetoothTx = 3;
      const int bluetoothRx = 4;
      SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);
   
   Wir beginnen damit, die SoftwareSerial-Bibliothek einzuschließen, um uns bei der Bluetooth-Kommunikation zu helfen. Die TX- und RX-Pins des Bluetooth-Moduls werden dann definiert und mit den Pins 3 und 4 am Arduino verbunden. Schließlich initialisieren wir das ``bleSerial``-Objekt für die Bluetooth-Kommunikation.
#. LED Pin Definitionen

   .. code-block:: arduino

      // Pin numbers for each LED
      const int rledPin = 10;  //red
      const int yledPin = 11;  //yellow
      const int gledPin = 12;  //green

   Hier definieren wir, an welchen Arduino-Pins unsere LEDs angeschlossen sind. Die rote LED ist an Pin 10, die gelbe an 11 und die grüne an 12.

#. setup() Funktion

   .. code-block:: arduino

      void setup() {
         pinMode(rledPin, OUTPUT);
         pinMode(yledPin, OUTPUT);
         pinMode(gledPin, OUTPUT);

         Serial.begin(9600);
         bleSerial.begin(9600);
      }

   In der ``setup()`` Funktion setzen wir die LED-Pins als ``OUTPUT``. Wir starten auch die serielle Kommunikation sowohl für das Bluetooth-Modul als auch für die Standard-Seriellverbindung (mit dem Computer verbunden) mit einer Baudrate von 9600.

#. Hauptschleife() für Bluetooth-Kommunikation

   .. code-block:: arduino

      void loop() {
         while (bleSerial.available() > 0) {
            character = bleSerial.read();
            Serial.println(character);

            if (character == 'R') {
               toggleLights(rledPin);
            } else if (character == 'Y') {
               toggleLights(yledPin);
            } else if (character == 'G') {
               toggleLights(gledPin);
            }
         }
      }

   Innerhalb unserer Haupt- ``loop()`` überprüfen wir kontinuierlich, ob Daten vom Bluetooth-Modul verfügbar sind. Wenn wir Daten erhalten, lesen wir das Zeichen und zeigen es im Seriellen Monitor an. Abhängig vom empfangenen Zeichen (R, Y oder G) schalten wir die jeweilige LED mit der ``toggleLights()`` Funktion um.

#. Lichter umschalten Funktion

   .. code-block:: arduino

      void toggleLights(int targetLight) {
         digitalWrite(rledPin, LOW);
         digitalWrite(yledPin, LOW);
         digitalWrite(gledPin, LOW);

         digitalWrite(targetLight, HIGH);
      }

   Diese Funktion, ``toggleLights()``, schaltet zuerst alle LEDs aus. Nachdem sichergestellt wurde, dass sie alle aus sind, schaltet sie die angegebene Ziel-LED ein. Dies stellt sicher, dass jeweils nur eine LED eingeschaltet ist.
