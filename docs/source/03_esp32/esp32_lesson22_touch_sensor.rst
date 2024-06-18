.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson22_touch_sensor:

Lektion 22: Berührungssensor-Modul
======================================

In dieser Lektion lernen Sie, wie Sie einen Berührungssensor mit einem ESP32-Entwicklungsboard verwenden. Wir werden sehen, wie das Berühren des Sensors ein Signal an den ESP32 sendet und eine Reaktion auslöst, die über die serielle Kommunikation angezeigt wird. Dieses Projekt ist ideal für Anfänger und bietet praktische Erfahrung mit digitalen Eingängen und serieller Ausgabe auf der ESP32-Plattform. Sie entwickeln ein grundlegendes Verständnis dafür, wie Sensoren mit Mikrocontrollern interagieren, was für den Bau interaktiver Hardwareprojekte unerlässlich ist.

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
    *   - :ref:`cpn_touch`
        - |link_touch_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_22_Touch_Sensor_Module_esp32_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f3fd3d61-1d6b-46b8-8e62-e3c91e262830/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. **Einrichtung des Pins und der seriellen Kommunikation**

   - Der Berührungssensor ist an Pin 25 des ESP32 angeschlossen, und dieser Pin ist als Eingang konfiguriert.
   - Mit ``Serial.begin(9600);`` wird die serielle Kommunikation mit einer Baudrate von 9600 Bit pro Sekunde initialisiert.
   
   .. raw:: html
      
      <br/>

   .. code-block:: arduino

      const int sensorPin = 25;

      void setup() {
        pinMode(sensorPin, INPUT);     // Set the sensor pin as input
        Serial.begin(9600);            // Start the serial communication
      }

#. **Auslesen des Sensors und Senden der Daten an den seriellen Monitor**

   - Die ``loop()``-Funktion prüft kontinuierlich den Zustand des Berührungssensors.
   - ``digitalRead(sensorPin)`` liest den digitalen Wert (1 oder 0) vom Sensor-Pin.
   - Wenn der Sensor berührt wird (Wert 1), wird "Touch detected!" an den seriellen Monitor gesendet.
   - Wenn der Sensor nicht berührt wird (Wert 0), wird "No touch detected..." gesendet.
   - Das ``delay(100);`` hilft beim Entprellen des Sensors und verhindert mehrfache schnelle Auslesungen.

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == 1) {  // If the sensor is touched
          Serial.println("Touch detected!");
        } else {
          Serial.println("No touch detected...");
        }
        delay(100);  // Wait for a short period to avoid rapid reading of the sensor
      }