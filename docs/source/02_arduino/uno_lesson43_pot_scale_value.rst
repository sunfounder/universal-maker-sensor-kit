
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_potentiometer_scale_value:

Lektion 43: Skalierter Wert des Potentiometers
=============================================================


Dieses Projekt konzentriert sich auf das Lesen des Werts eines Potentiometers und dessen Anzeige auf einem LCD 1620 mit einer I2C-Schnittstelle. 
Zusätzlich wird der Wert zur Live-Überwachung an den seriellen Monitor übertragen. 
Ein charakteristisches Merkmal dieses Projekts ist die grafische Darstellung des Wertes des Potentiometers auf dem LCD, 
die als variable Balkenlänge proportional zum Wert des Potentiometers dargestellt wird.


Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

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

Sie können sie auch separat von den untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_potentiometer`
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verkabelung
---------------------------

.. image:: img/Lesson_43_Potentiometer_scale_value_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/b51d7dac-b89b-4785-8620-907914fe983c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

Die Kernfunktionalität dieses Projekts besteht darin, den Wert des Potentiometers kontinuierlich auszulesen, ihn auf einen skalierten Bereich (0-16) abzubilden und das Ergebnis sowohl numerisch als auch grafisch auf dem LCD anzuzeigen. Die Implementierung minimiert Schwankungen, indem das Display nur aktualisiert wird, wenn signifikante Änderungen im Messwert auftreten, wodurch ein flüssiges visuelles Erlebnis gewährleistet wird.

1. **Einbindung und Initialisierung der Bibliotheken**:

   .. code-block:: arduino
   
      #include <Wire.h>
      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

   Dieses Segment bindet die erforderlichen Bibliotheken für die I2C-Kommunikation und die LCD-Steuerung ein. Dann initialisiert es eine LCD-Instanz mit der I2C-Adresse ``0x27`` und gibt ihre Abmessungen als ``16 columns`` und ``2 rows`` an.

2. **Variablendeklaration**:

   .. code-block:: arduino
   
      int lastRead = 0;     // Stores the last read value from the potentiometer
      int currentRead = 0;  // Holds the current read value from the potentiometer

   Die Variablen ``lastRead`` und ``currentRead`` werden verwendet, um die Messwerte des Potentiometers zu verschiedenen Zeitpunkten zu verfolgen.

3. **setup() Funktion**:

   .. code-block:: arduino
   
      void setup() {
        lcd.init();          // Initiates the LCD
        lcd.backlight();     // Activates the LCD's backlight
        Serial.begin(9600);  // Commences serial communication at 9600 baud
      }

   Diese Funktion bereitet das LCD vor und startet die serielle Kommunikation, um die Umgebung für den Betrieb des Projekts einzurichten.

4. **Haupt-Schleife**:

   .. code-block:: arduino
   
      void loop() {
        currentRead = analogRead(A0);
        int barLength = map(currentRead, 0, 1023, 0, 16);
        if (abs(lastRead - currentRead) > 2) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Value:");
          lcd.setCursor(7, 0);
          lcd.print(currentRead);
          Serial.println(currentRead);
          for (int i = 0; i < barLength; i++) {
            lcd.setCursor(i, 1);
            lcd.print(char(255));
          }
        }
        lastRead = currentRead;
        delay(200);
      }

   * Liest den Wert des Potentiometers und konvertiert ihn in einen für die visuelle Darstellung geeigneten Bereich.
   * Aktualisiert das LCD nur bei einer bedeutungsvollen Änderung, zeigt den numerischen Wert und ein entsprechendes Balkendiagramm an.
   * Sendet den Messwert auch an den seriellen Monitor zur externen Beobachtung.
   * Gewährleistet Stabilität und Reaktionsfähigkeit durch eine kurze Verzögerung zwischen den Iterationen.


