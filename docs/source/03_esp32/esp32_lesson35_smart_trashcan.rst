.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_trashcan:

Lektion 35: Intelligenter Mülleimer
=======================================

Dieses Projekt dreht sich um das Konzept eines intelligenten Mülleimers. 
Das Hauptziel besteht darin, dass sich der Deckel des Mülleimers automatisch öffnet, 
wenn sich ein Objekt auf eine festgelegte Entfernung (in diesem Fall 20 cm) nähert. 
Diese Funktion wird durch die Verwendung eines Ultraschallsensors in Kombination mit einem Servomotor erreicht. 
Der Abstand zwischen dem Objekt und dem Sensor wird kontinuierlich gemessen. 
Wenn das Objekt nah genug ist, wird der Servomotor ausgelöst, um den Deckel zu öffnen.

Benötigte Komponenten
-------------------------

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verkabelung
--------------

.. image:: img/Lesson_35_smart_trashcan_esp32_bb.png
    :width: 100%

Code
-------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a4b1e0f2-4e01-4adc-9cb9-f984ca76dbfa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------

Das Projekt basiert auf der Echtzeitüberwachung des Abstands zwischen einem Objekt und einem Mülleimer. Ein Ultraschallsensor misst diesen Abstand kontinuierlich, und wenn sich ein Objekt auf 20 cm nähert, interpretiert der Mülleimer dies als Absicht, Abfall zu entsorgen, und öffnet automatisch den Deckel. Diese Automatisierung verleiht einem herkömmlichen Mülleimer Intelligenz und Komfort.

#. Initiale Einrichtung und Variablendeklaration

   Hier binden wir die Bibliothek ``ESP32Servo`` ein und definieren die Konstanten und Variablen, die wir verwenden werden. Die Pins für das Servo und den Ultraschallsensor werden deklariert. Wir haben auch ein Array ``averDist``, um die drei Distanzmessungen zu speichern.

   .. code-block:: arduino
       
        #include <ESP32Servo.h>

        // Set up the servo motor parameters
        Servo servo;
        const int servoPin = 27;
        const int openAngle = 0;
        const int closeAngle = 90;

        // Define the minimum and maximum pulse widths for the servo
        const int minPulseWidth = 500; // 0.5 ms
        const int maxPulseWidth = 2500; // 2.5 ms


        // Set up the ultrasonic sensor parameters
        const int trigPin = 26;
        const int echoPin = 25;
        long distance, averageDistance;
        long averDist[3];

        // Distance threshold in centimeters
        const int distanceThreshold = 20;

#. Funktion ``setup()``

   Die Funktion ``setup()`` initialisiert die serielle Kommunikation, konfiguriert die Pins des Ultraschallsensors und setzt die Ausgangsposition des Servos auf die geschlossene Position.

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
        servo.attach(servoPin);
        servo.write(closeAngle);
        delay(100);
      }

#. Funktion ``loop()``

   Die Funktion ``loop()`` ist dafür verantwortlich, kontinuierlich den Abstand zu messen, den Durchschnitt zu berechnen und dann zu entscheiden, ob der Deckel des Mülleimers basierend auf diesem Durchschnittsabstand geöffnet oder geschlossen wird.

   .. code-block:: arduino
   
        void loop() {
            // Measure the distance three times
            for (int i = 0; i <= 2; i++) {
                distance = readDistance();
                averDist[i] = distance;
                delay(10);
            }

            // Calculate the average distance
            averageDistance = (averDist[0] + averDist[1] + averDist[2]) / 3;
            Serial.println(averageDistance);

            // Control the servo based on the averaged distance
            if (averageDistance <= distanceThreshold) {
                servo.attach(servoPin);  // Reattach the servo before sending a command
                delay(1);
                servo.write(openAngle);  // Rotate the servo to the open position
                delay(3500);
            } else {
                servo.write(closeAngle);  // Rotate the servo back to the closed position
                delay(1000);
                servo.detach();  // Detach the servo to save power when not in use
            }
        }

#. Funktion zur Abstandsmessung

   Diese Funktion, ``readDistance()``, interagiert tatsächlich mit dem Ultraschallsensor. Sie sendet einen Impuls und wartet auf ein Echo. Die Zeit, die für das Echo benötigt wird, wird dann verwendet, um den Abstand zwischen dem Sensor und einem Objekt davor zu berechnen.

   Sie können sich auf das :ref:`cpn_ultrasonic_principle` des Ultraschallsensors beziehen.

   .. code-block:: arduino
   
        float readDistance() {
            // Send a pulse on the trigger pin of the ultrasonic sensor
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);

            // Measure the pulse width of the echo pin and calculate the distance value
            float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
            return distance;
        }

#. Servo-Schreibfunktion

    Diese Funktion ordnet den Winkelwert der Pulsbreite zu und ruft die Funktion ``writeMicroseconds(pulseWidth)`` auf, um das Servo auf einen bestimmten Winkel zu bewegen.

    .. code-block:: arduino
        
        // Function to make the servo work
        void servoWrite(int angle){
            int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
            servo.writeMicroseconds(pulseWidth);
        }
