 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson23_ultrasonic:

Lektion 23: Ultraschallsensor-Modul (HC-SR04)
===============================================

In dieser Lektion lernen Sie, wie Sie ein ESP32-Entwicklungsboard verwenden, um Entfernungen mit einem Ultraschallsensor (HC-SR04) zu messen. Wir werden den Sensor einrichten, Daten lesen und die Entfernung in Zentimetern berechnen. Dieses Projekt ist ideal für Anfänger, die mit Mikrocontrollern und Sensoren arbeiten, und bietet praktische Erfahrungen in der Datenerfassung und seriellen Kommunikation. Sie entwickeln praktische Fähigkeiten in der Programmierung des ESP32 und erhalten Einblicke in die Ultraschallsensortechnologie.

Benötigte Komponenten
---------------------

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
-----------

.. image:: img/Lesson_23_Ultrasonic_esp32_bb.png
    :width: 100%

Code
----

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b5dbcdfa-3dc8-4f64-adf9-a3227e3f6044/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
------------

#. Pindeklaration:

   Beginnen Sie mit der Definition der Pins für den Ultraschallsensor. ``echoPin`` und ``trigPin`` werden als Integer deklariert und ihre Werte werden entsprechend der physischen Verbindung auf dem ESP32-Entwicklungsboard gesetzt.

   .. code-block:: arduino

      const int echoPin = 26;
      const int trigPin = 25;

#. ``setup()``-Funktion:

   Die ``setup()``-Funktion initialisiert die serielle Kommunikation, legt die Pin-Modi fest und druckt eine Nachricht, die anzeigt, dass der Ultraschallsensor bereit ist.
 
   .. code-block:: arduino
 
      void setup() {
        Serial.begin(9600);
        pinMode(echoPin, INPUT);
        pinMode(trigPin, OUTPUT);
        Serial.println("Ultrasonic sensor:");
      }

#. ``loop()``-Funktion:

   Die ``loop()``-Funktion liest die Entfernung vom Sensor und druckt sie auf den seriellen Monitor, dann wartet sie 400 Millisekunden, bevor sie wiederholt wird.

   .. code-block:: arduino

      void loop() {
        float distance = readDistance();
        Serial.print(distance);
        Serial.println(" cm");
        delay(400);
      }

#. ``readDistance()``-Funktion:

   Die ``readDistance()``-Funktion löst den Ultraschallsensor aus und berechnet die Entfernung basierend auf der Zeit, die das Signal benötigt, um zurückzukehren.

   Für weitere Details siehe das Arbeitsprinzip :ref:`principle <cpn_ultrasonic_principle>` des Ultraschallsensormoduls.

   .. code-block:: arduino

      float readDistance() {
        digitalWrite(trigPin, LOW);   // Set trig pin to low to ensure a clean pulse
        delayMicroseconds(2);         // Delay for 2 microseconds
        digitalWrite(trigPin, HIGH);  // Send a 10 microsecond pulse by setting trig pin to high
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);  // Set trig pin back to low
        float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
        return distance;
      }
