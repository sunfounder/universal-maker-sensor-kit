.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson25_water_level:

Lektion 25: Wasserstandssensor-Modul
=========================================

In dieser Lektion lernen Sie, wie Sie Wasserstände mit Arduino messen. Wir werden uns ansehen, wie ein Wasserstandssensor unterschiedliche Spannungspegel basierend auf der Wasserhöhe erzeugen kann und wie der Arduino diese Spannungspegel liest. Dieses Projekt ist ideal für Anfänger, da es praktische Erfahrungen mit analogen Sensoren vermittelt und grundlegende Konzepte zur Verarbeitung von Sensordaten auf der Arduino-Plattform einführt.

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_water_level`
        - \-


Verkabelung
---------------------------

.. image:: img/Lesson_25_Water_level_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/268011b0-8c0c-42b0-8d21-253a37de0dc8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. **Initialisierung des Sensor-Pins**:

   Bevor der Wasserstandssensor verwendet wird, wird die Pin-Nummer mit einer Konstanten definiert. Dies macht den Code lesbarer und leichter zu ändern.

   .. code-block:: arduino

      const int sensorPin = A0;

#. **Einrichten der seriellen Kommunikation**:

   In der ``setup()``-Funktion wird die Baudrate für die serielle Kommunikation festgelegt. Dies ist wichtig, damit der Arduino mit dem seriellen Monitor des Computers kommunizieren kann.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

#. **Lesen der Sensordaten und Ausgabe an den seriellen Monitor**:

   The ``loop()`` function continuously reads the sensor's analog value using ``analogRead()`` and outputs it to the serial monitor using ``Serial.println()``. The ``delay(100)`` function makes the Arduino wait for 100 milliseconds before repeating the loop, controlling the rate of data reading and transmission.

   .. code-block:: arduino
    
      void loop() {
        Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
        delay(100);                             // Wait for 100 milliseconds
      }
