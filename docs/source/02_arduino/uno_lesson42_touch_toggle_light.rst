
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_touch_toggle_light:

Lektion 42: Touch-Schalter für Licht
========================================


Dieses Projekt ist eine einfache Umsetzung eines Verkehrslichtsteuerungssystems unter Verwendung eines Berührungssensors und eines Verkehrslicht-LED-Moduls. Die Aktivierung des Berührungssensors löst eine Sequenz aus, in der die LEDs in folgender Reihenfolge leuchten: Rot -> Gelb -> Grün.


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
    *   - :ref:`cpn_touch`
        - \-
    *   - :ref:`cpn_traffic`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verkabelung
---------------------------

.. image:: img/Lesson_42_Touch_toggle_light_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/f53d6cf6-ed27-49d3-b4d3-12f29b417a89/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

Die Funktionsweise dieses Projekts ist unkompliziert: Eine Berührungserkennung am Sensor löst die Beleuchtung der nächsten LED in der Sequenz (Rot -> Gelb -> Grün) aus, gesteuert durch die Variable ``currentLED``.
1. Pins und Startwerte definieren

   .. code-block:: arduino
   
      const int touchSensorPin = 2;  // Touch sensor pin
      const int rledPin = 7;         // Red LED pin
      const int yledPin = 8;         // Yellow LED pin
      const int gledPin = 9;         // Green LED pin
      int lastTouchState;            // Previous touch sensor state
      int currentTouchState;         // Current touch sensor state
      int currentLED = 0;            // Current LED: 0->Red, 1->Yellow, 2->Green
   
   Diese Zeilen definieren die Pin-Verbindungen für die Komponenten des Arduino-Boards und initialisieren die Zustände des Berührungssensors und der LEDs.

2. setup() Funktion

   .. code-block:: arduino
   
       void setup() {
         Serial.begin(9600);              // Initialize serial communication
         pinMode(touchSensorPin, INPUT);  // Set touch sensor pin as input
         // Configure LED pins as outputs
         pinMode(rledPin, OUTPUT);
         pinMode(yledPin, OUTPUT);
         pinMode(gledPin, OUTPUT);
         currentTouchState = digitalRead(touchSensorPin); // Read initial touch state
       }
   
   Diese Funktion konfiguriert das initiale Setup für den Arduino, definiert Eingangs- und Ausgangsmodi und startet die serielle Kommunikation zum Debuggen.

3. loop() Funktion

   .. code-block:: arduino
   
       void loop() {
         lastTouchState = currentTouchState;                        // Store the last state
         currentTouchState = digitalRead(touchSensorPin);           // Read new touch state
         if (lastTouchState == LOW && currentTouchState == HIGH) {  // Detect touch
           Serial.println("Sensor touched");
           turnAllLEDsOff();  // Turn off all LEDs
           // Activate the next LED in sequence
           switch (currentLED) {
             case 0:
               digitalWrite(rledPin, HIGH);
               currentLED = 1;
               break;
             case 1:
               digitalWrite(yledPin, HIGH);
               currentLED = 2;
               break;
             case 2:
               digitalWrite(gledPin, HIGH);
               currentLED = 0;
               break;
           }
         }
       }

   Die Schleife überwacht kontinuierlich den Berührungssensor, durchläuft die LEDs, wenn eine Berührung erkannt wird, und stellt sicher, dass jeweils nur eine LED eingeschaltet ist.

4. LEDs ausschalten Funktion

   .. code-block:: arduino
      
       void turnAllLEDsOff() {
         // Set all LED pins to LOW, turning them off
         digitalWrite(rledPin, LOW);
         digitalWrite(yledPin, LOW);
         digitalWrite(gledPin, LOW);
       }

   Diese Hilfsfunktion schaltet alle LEDs aus und hilft beim Durchlaufen des Zyklus.
