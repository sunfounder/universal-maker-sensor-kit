.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson12_pir_motion:

Lektion 12: PIR-Bewegungssensormodul (HC-SR501)
==================================================

In dieser Lektion lernen Sie, wie Sie einen PIR (Passiv-Infrarot) Bewegungssensor mit einem Arduino Uno verwenden. Wir werden sehen, wie der Sensor Bewegung erkennt und ein Signal an den Arduino sendet, der daraufhin eine Reaktion auslöst. Dieses Projekt ist ideal für Anfänger, da es praktische Erfahrungen mit digitalen Eingängen, serieller Kommunikation und bedingter Programmierung auf der Arduino-Plattform bietet.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können die Komponenten auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_pir_motion`
        - \-

Verkabelung
---------------------------

.. image:: img/Lesson_12_pir_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75947bcf-8e55-4737-b1b7-f17b4a28e775/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

1. Einrichtung des PIR-Sensorpins. Der Pin für den PIR-Sensor ist als Pin 2 definiert.

   .. code-block:: arduino

      const int pirPin = 2;
      int state = 0;

2. Initialisierung des PIR-Sensors. In der ``setup()``-Funktion wird der PIR-Sensorpin als Eingang festgelegt. Dies ermöglicht es dem Arduino, den Zustand des PIR-Sensors zu lesen.

   .. code-block:: arduino

      void setup() {
        pinMode(pirPin, INPUT);
        Serial.begin(9600);
      }

3. Lesen vom PIR-Sensor und Anzeigen der Ergebnisse. In der ``loop()``-Funktion wird der Zustand des PIR-Sensors kontinuierlich gelesen.

   .. code-block:: arduino

      void loop() {
        state = digitalRead(pirPin);
        if (state == HIGH) {
          Serial.println("Somebody here!");
        } else {
          Serial.println("Monitoring...");
          delay(100);
        }
      }

   Wenn der Zustand ``HIGH`` ist, was bedeutet, dass eine Bewegung erkannt wurde, wird die Nachricht "Jemand ist hier!" auf dem seriellen Monitor ausgegeben. Andernfalls wird "Überwachen..." ausgegeben.
