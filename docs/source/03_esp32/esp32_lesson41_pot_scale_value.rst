 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_potentiometer_scale_value:

Lektion 41: Potentiometer-Wert skalieren
=============================================================

Dieses Projekt konzentriert sich auf das Auslesen des Potentiometerwerts und dessen Anzeige auf einem LCD 1602 mit I2C-Schnittstelle. 
Zusätzlich wird der Wert an den seriellen Monitor übertragen, um eine Echtzeitüberwachung zu ermöglichen. 
Ein besonderes Merkmal dieses Projekts ist die grafische Darstellung des Potentiometerwerts auf dem LCD, 
die als variabel lange Leiste proportional zum Potentiometerwert angezeigt wird.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_potentiometer`
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verdrahtung
---------------------------

.. image:: img/Lesson_41_Potentiometer_scale_value_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/407cf491-e932-4334-a3f3-e04f7309c941/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

   
Code-Analyse
---------------------------

Die Kernfunktionalität dieses Projekts besteht darin, den Potentiometerwert kontinuierlich zu lesen, ihn auf einen skalierten Bereich (0-16) zu übertragen und das Ergebnis sowohl numerisch als auch grafisch auf dem LCD anzuzeigen. Die Implementierung minimiert das Flimmern, indem das Display nur bei signifikanten Änderungen des Werts aktualisiert wird, um eine reibungslose visuelle Darstellung zu gewährleisten.

1. **Einbindung der Bibliotheken und Initialisierung**:

   .. code-block:: arduino
   
      // Required libraries for I2C and LCD operations
      #include <Wire.h>
      #include <LiquidCrystal_I2C.h>

      // Initialize LCD at I2C address 0x27 with 16 columns and 2 rows
      LiquidCrystal_I2C lcd(0x27, 16, 2);

   Dieser Abschnitt bindet die erforderlichen Bibliotheken für die I2C-Kommunikation und die Steuerung des LCDs ein. Anschließend wird eine LCD-Instanz mit der I2C-Adresse ``0x27`` und den Abmessungen ``16 Spalten`` und ``2 Zeilen`` initialisiert.

2. **Variablendeklaration**:

   .. code-block:: arduino
   
      // Variables to hold the potentiometer readings
      int lastRead = 0;     // Previous potentiometer value
      int currentRead = 0;  // Current potentiometer value
      
   Die Variablen ``lastRead`` und ``currentRead`` werden verwendet, um die Potentiometerwerte zu verschiedenen Zeitpunkten zu verfolgen.

3. **setup() Funktion**:

   .. code-block:: arduino
   
      void setup() {
        lcd.init();          // Initiates the LCD
        lcd.backlight();     // Activates the LCD's backlight
        Serial.begin(9600);  // Commences serial communication at 9600 baud
      }

   Diese Funktion bereitet das LCD vor und startet die serielle Kommunikation, um die Umgebung für den Betrieb des Projekts einzurichten.

4. **Hauptschleife**:

   .. code-block:: arduino
   
      void loop() {
         // Read the current potentiometer value
         int currentRead = analogRead(35);

         // Map the read value from 0-4096 to 0-16
         int barLength = map(currentRead, 0, 4096, 0, 16);

         // Update LCD only if the difference between current and last reading is greater than 2 to avoid jitter
         if (abs(lastRead - currentRead) > 2) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Value:");
            lcd.setCursor(7, 0);
            lcd.print(currentRead);
            Serial.println(currentRead);

            // Display a bar on the second row of LCD proportional to the potentiometer value
            for (int i = 0; i < barLength; i++) {
               lcd.setCursor(i, 1);
               lcd.print(char(255));
            }
         }
         // Update the last read value for the next iteration
         lastRead = currentRead;

         // Introduce a delay for a stable reading
         delay(200);
      }

   * Liest den Potentiometerwert und wandelt ihn in eine für die visuelle Darstellung geeignete Skala um.
   * Aktualisiert das LCD nur bei einer signifikanten Änderung des Werts und zeigt den numerischen Wert sowie eine entsprechende Leiste an.
   * Sendet den Wert auch an den seriellen Monitor zur externen Beobachtung.
   * Gewährleistet Stabilität und Reaktionsfähigkeit durch eine kurze Verzögerung zwischen den Iterationen.
