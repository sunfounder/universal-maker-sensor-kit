.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson16_ds1306:

Lektion 16: Echtzeituhrmodul (DS1302)
==================================================

In dieser Lektion lernen Sie, wie Sie ein Echtzeituhrmodul (RTC) mit einem ESP32-Entwicklungsboard einrichten und verwenden. Wir werden die Integration des DS1302 RTC-Moduls, das Verständnis seiner Funktionen und die Programmierung des ESP32 zur Anzeige des aktuellen Datums und der Uhrzeit behandeln. Außerdem erfahren Sie, wie Sie Situationen handhaben, in denen das RTC-Modul seine Datums- und Uhrzeiteinstellungen verloren hat und automatisch auf die Kompilierungszeit Ihres Sketches eingestellt wird. Dieses Projekt ist ideal für diejenigen, die ihr Verständnis für zeitbezogene Funktionen in Mikrocontroller-Projekten erweitern möchten.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

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

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_rtc_ds1302`
        - |link_ds1302_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_16_DS1302_esp32_bb.png
    :width: 100%

Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"Rtc by Makuna"** und installieren Sie sie.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/12a5464b-7a6e-48e1-b43e-ca585cb9e310/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. Initialisierung und Bibliotheks-Einbindung

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"Rtc by Makuna"** und installieren Sie sie.

   Hier werden die notwendigen Bibliotheken für das DS1302 RTC-Modul eingebunden.

   .. code-block:: arduino

      #include <ThreeWire.h>
      #include <RtcDS1302.h>

#. Pins definieren und RTC-Instanz erstellen

   Pins für die Kommunikation werden definiert und eine Instanz der RTC erstellt.

   .. code-block:: arduino

      const int IO = 27;    // DAT
      const int SCLK = 14;  // CLK
      const int CE = 26;    // RST

      ThreeWire myWire(IO, SCLK, CE));
      RtcDS1302<ThreeWire> Rtc(myWire);

#. ``setup()``-Funktion

   Diese Funktion initialisiert die serielle Kommunikation und richtet das RTC-Modul ein. Verschiedene Überprüfungen werden durchgeführt, um sicherzustellen, dass die RTC korrekt läuft.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
      
        Serial.print("compiled: ");
        Serial.print(__DATE__);
        Serial.println(__TIME__);
      
        Rtc.Begin();
      
        RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
        printDateTime(compiled);
        Serial.println();
      
        if (!Rtc.IsDateTimeValid()) {
          // Common Causes:
          //    1) first time you ran and the device wasn't running yet
          //    2) the battery on the device is low or even missing
      
          Serial.println("RTC lost confidence in the DateTime!");
          Rtc.SetDateTime(compiled);
        }
      
        if (Rtc.GetIsWriteProtected()) {
          Serial.println("RTC was write protected, enabling writing now");
          Rtc.SetIsWriteProtected(false);
        }
      
        if (!Rtc.GetIsRunning()) {
          Serial.println("RTC was not actively running, starting now");
          Rtc.SetIsRunning(true);
        }
      
        RtcDateTime now = Rtc.GetDateTime();
        if (now < compiled) {
          Serial.println("RTC is older than compile time!  (Updating DateTime)");
          Rtc.SetDateTime(compiled);
        } else if (now > compiled) {
          Serial.println("RTC is newer than compile time. (this is expected)");
        } else if (now == compiled) {
          Serial.println("RTC is the same as compile time! (not expected but all is fine)");
        }
      }

#. ``loop()``-Funktion

   Diese Funktion holt periodisch das aktuelle Datum und die Uhrzeit von der RTC und gibt sie im seriellen Monitor aus. Es wird auch überprüft, ob die RTC weiterhin ein gültiges Datum und eine gültige Uhrzeit beibehält.

   .. code-block:: arduino

      void loop() {
        RtcDateTime now = Rtc.GetDateTime();
      
        printDateTime(now);
        Serial.println();
      
        if (!now.IsValid()) {
          // Common Causes:
          //    1) the battery on the device is low or even missing and the power line was disconnected
          Serial.println("RTC lost confidence in the DateTime!");
        }
      
        delay(5000);  // five seconds
      }

#. Datum- und Uhrzeitausgabe-Funktion

   Eine Hilfsfunktion, die ein ``RtcDateTime``-Objekt entgegennimmt und das formatierte Datum und die Uhrzeit im seriellen Monitor ausgibt.

   .. code-block:: arduino

      void printDateTime(const RtcDateTime& dt) {
        char datestring[20];
      
        snprintf_P(datestring,
                   countof(datestring),
                   PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
                   dt.Month(),
                   dt.Day(),
                   dt.Year(),
                   dt.Hour(),
                   dt.Minute(),
                   dt.Second());
        Serial.print(datestring);
      }