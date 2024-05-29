 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson06_hall_sensor:

Lektion 06: Hall-Sensormodul
==================================

In dieser Lektion lernen Sie, wie ein Hall-Sensor magnetische Felder mit einem Arduino erkennt. Wir werden untersuchen, wie man das analoge Signal des Sensors mit dem Arduino Uno liest und die Werte interpretiert, um die Polarität eines Magnetfeldes zu bestimmen. Sie werden die Funktionsweise des Hall-Sensors verstehen und erfahren, wie das Arduino-Board diese Messwerte in Echtzeit verarbeitet und anzeigt.

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
    *   - :ref:`cpn_hall`
        - \-

Verkabelung
---------------------------

.. image:: img/Lesson_06_hall_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fc459930-a030-4a1d-b998-e57a6a4f2e78/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

1. Einrichtung des Hall-Sensors

   .. code-block:: arduino

      const int hallSensorPin = A0;  // Pin A0 connected to the Hall sensor output
      void setup() {
        Serial.begin(9600);             // Initialize serial communication at 9600 bps
        pinMode(hallSensorPin, INPUT);  // Set hall sensor pin as input
      }

   Der Ausgang des Hall-Sensors ist mit Pin A0 des Arduino verbunden. Die Funktion ``setup()`` wird verwendet, um die serielle Kommunikation mit 9600 Bit pro Sekunde (bps) zu initialisieren, um Daten auf dem seriellen Monitor anzuzeigen. Die Funktion ``pinMode()`` wird verwendet, um A0 als Eingangspin zu konfigurieren.

2. Auslesen des Hall-Sensors und Bestimmen der Polarität

   Das Hall-Sensormodul ist mit einem 49E linearen Hall-Effekt-Sensor ausgestattet, der die Polarität der magnetischen Nord- und Südpolen sowie die relative Stärke des Magnetfeldes messen kann. Wenn Sie den Südpol eines Magneten in die Nähe der Seite mit der Aufschrift 49E (die Seite mit eingraviertem Text) bringen, erhöht sich der vom Code gelesene Wert linear in Proportion zur angelegten Magnetfeldstärke. Umgekehrt, wenn Sie einen Nordpol in die Nähe dieser Seite bringen, verringert sich der vom Code gelesene Wert linear in Proportion zur Magnetfeldstärke. Weitere Details finden Sie unter :ref:`cpn_hall`.

   .. code-block:: arduino

      void loop() {
        int sensorValue = analogRead(hallSensorPin);  // Read analog value from Hall sensor
        Serial.print(sensorValue);                    // Output raw sensor value to Serial Monitor
        delay(200);                                   // Delay for 200 milliseconds

        // Determine magnetic pole based on sensor value
        if (sensorValue >= 700) {
          Serial.print(" - South pole detected");  // South pole detected if value >= 700
        } else if (sensorValue <= 300) {
          Serial.print(" - North pole detected");  // North pole detected if value <= 300
        }

        Serial.println();  // New line for next output
      }

