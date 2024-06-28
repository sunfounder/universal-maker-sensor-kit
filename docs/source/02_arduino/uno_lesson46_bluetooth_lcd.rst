.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!


Lektion 46: Bluetooth LCD
=============================================================


Dieses Projekt ermöglicht den Empfang von Nachrichten über ein Bluetooth-Modul, das mit einem Arduino UNO-Board verbunden ist, und zeigt diese Nachrichten auf einem LCD-Bildschirm an.

Erforderliche Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist auf jeden Fall praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name    
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch separat von den folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_jdy31`
        - \-


Verkabelung
---------------------------

.. image:: img/Lesson_46_Bluetooth_lcd_uno_bb.png
    :width: 100%
Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen nach **"LiquidCrystal I2C"** und installieren diese.  

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ae00239d-f273-4686-b01d-f20487892640/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


App- und Bluetooth-Modulverbindung
-----------------------------------------------
Wir können eine App namens "Serial Bluetooth Terminal" verwenden, um Nachrichten vom Bluetooth-Modul an Arduino zu senden.

a. **Installieren Sie Serial Bluetooth Terminal**

   Gehen Sie zum Google Play Store, um |link_serial_bluetooth_terminal| herunterzuladen und zu installieren.


b. **Bluetooth verbinden**

   Schalten Sie zunächst **Bluetooth** auf Ihrem Smartphone ein.
   
      .. image:: img/09-app_1_shadow.png
         :width: 60%
         :align: center
   
   Navigieren Sie auf Ihrem Smartphone zu den **Bluetooth-Einstellungen** und suchen Sie nach Namen wie **JDY-31-SPP**.
   
      .. image:: img/09-app_2_shadow.png
         :width: 60%
         :align: center
   
   Klicken Sie darauf und stimmen Sie der **Koppelanfrage** im Popup-Fenster zu. Wenn Sie nach einem Pairing-Code aufgefordert werden, geben Sie bitte "1234" ein.
   
      .. image:: img/09-app_3_shadow.png
         :width: 60%
         :align: center
   

c. **Kommunikation mit dem Bluetooth-Modul**

   Öffnen Sie das Serial Bluetooth Terminal. Verbinden Sie sich mit "JDY-31-SPP".

   .. image:: img/00-bluetooth_serial_4_shadow.png 

d. **Befehl senden**

   Verwenden Sie die Serial Bluetooth Terminal-App, um Nachrichten an Arduino über Bluetooth zu senden. Die an Bluetooth gesendete Nachricht wird auf dem LCD angezeigt.

   .. image:: img/15-lcd_shadow.png
      :width: 100%
      :align: center



Code-Analyse
---------------------------


.. note:: 
      Verwenden Sie zum Installieren der Bibliothek den Arduino-Bibliotheksmanager und suchen Sie nach **"LiquidCrystal I2C"**. Installieren Sie dann die Bibliothek.  

#. Einrichten des LCD

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

   Dieser Codeabschnitt umfasst die LiquidCrystal_I2C-Bibliothek und initialisiert das LCD-Modul mit der I2C-Adresse ``0x27`` sowie der Angabe, dass das LCD ``16`` Spalten und ``2`` Zeilen hat.

#. Einrichtung der Bluetooth-Kommunikation

   .. code-block:: arduino

      #include <SoftwareSerial.h>
      const int bluetoothTx = 3;
      const int bluetoothRx = 4;
      SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);

   Hier wird die SoftwareSerial-Bibliothek eingebunden, um dem JDY-31-Bluetooth-Modul die Kommunikation mit dem Arduino über die Pins 3 (TX) und 4 (RX) zu ermöglichen.

#. Initialisierung

   .. code-block:: arduino

      void setup() {
         lcd.init();
         lcd.clear();
         lcd.backlight();

         Serial.begin(9600);
         bleSerial.begin(9600);
      }

   Die Funktion ``setup()`` initialisiert das LCD und löscht vorhandene Inhalte. Außerdem wird die Hintergrundbeleuchtung für das LCD eingeschaltet. Die Kommunikation wird mit dem seriellen Monitor und dem Bluetooth-Modul gestartet, beide mit einer Baudrate von ``9600``.

#. Hauptschleife

   .. code-block:: arduino

      void loop() {
         String data;

         if (bleSerial.available()) {
            data += bleSerial.readString();
            data = data.substring(0, data.length() - 2);
            Serial.print(data);

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(data);
         }

         if (Serial.available()) {
            bleSerial.write(Serial.read());
         }
      }

   Dies ist die Hauptoperationsschleife des Arduino-Programms. Es überprüft kontinuierlich eingehende Daten sowohl vom Bluetooth-Modul als auch vom seriellen Monitor. Wenn Daten vom Bluetooth-Gerät empfangen werden, werden sie verarbeitet, im seriellen Monitor angezeigt und auf dem LCD angezeigt. Wenn Daten im seriellen Monitor eingegeben werden, werden diese Daten an das Bluetooth-Modul gesendet.
