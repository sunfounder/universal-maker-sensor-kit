 .. _uno_lesson23_ultrasonic: .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!



Lektion 23: Ultraschallsensor-Modul (HC-SR04)
=================================================

In dieser Lektion lernen Sie, wie Sie mit einem Ultraschallsensor und Arduino Entfernungen messen. Wir werden den HC-SR04-Sensor mit dem Arduino Uno R4 Board verbinden und damit Entfernungen in Zentimetern berechnen und anzeigen. Dieses Projekt ist ideal für Anfänger und bietet praktische Erfahrungen mit der seriellen Kommunikation von Arduino und der Verarbeitung von Sensordaten. Sie erhalten wertvolle Einblicke in die Arbeit mit digitalen Signalen und das grundlegende Verständnis der Ultraschallmesstechnik.

Benötigte Komponenten
-------------------------

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

Sie können sie auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_23_ultrasonic_circuit_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/633ae8f5-4b15-4888-b4cb-b1eb24f3e2ef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

1. Pindeklaration:

   Beginnen Sie mit der Definition der Pins für den Ultraschallsensor. ``echoPin`` und ``trigPin`` werden als Integer deklariert und ihre Werte entsprechend der physischen Verbindung auf dem Arduino-Board festgelegt.

   .. code-block:: arduino

      const int echoPin = 3;
      const int trigPin = 4;

2. ``setup()``-Funktion:

   Die ``setup()``-Funktion initialisiert die serielle Kommunikation, legt die Pin-Modi fest und druckt eine Nachricht, um anzuzeigen, dass der Ultraschallsensor bereit ist.
 
   .. code-block:: arduino
 
      void setup() {
        Serial.begin(9600);
        pinMode(echoPin, INPUT);
        pinMode(trigPin, OUTPUT);
        Serial.println("Ultrasonic sensor:");
      }

3. ``loop()``-Funktion:

   Die ``loop()``-Funktion liest den Abstand vom Sensor und druckt ihn auf den seriellen Monitor, dann verzögert sie für 400 Millisekunden, bevor sie den Vorgang wiederholt.

   .. code-block:: arduino

      void loop() {
        float distance = readDistance();
        Serial.print(distance);
        Serial.println(" cm");
        delay(400);
      }

4. ``readDistance()``-Funktion:

   Die ``readDistance()``-Funktion löst den Ultraschallsensor aus und berechnet den Abstand basierend auf der Zeit, die das Signal benötigt, um zurückzukommen.

Weitere Einzelheiten finden Sie im Funktionsprinzip des Ultraschallsensormoduls unter :ref:`principle <cpn_ultrasonic_principle>`.

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
