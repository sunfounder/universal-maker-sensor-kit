
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson33_servo:

Lektion 33: Servomotor (SG90)
==================================

In dieser Lektion lernen Sie, wie Sie mit Arduino einen Servomotor steuern und ihn von 0 bis 180 Grad und wieder zurück drehen lassen. Wir werden die Verwendung der Servo-Bibliothek, die Definition und Verwendung von Variablen zur Servosteuerung sowie die Implementierung einer For-Schleife für eine schrittweise Bewegung behandeln. Dieses Projekt ist ideal für Anfänger, da es praktische Erfahrungen in der Motorsteuerung und den grundlegenden Programmierprinzipien von Arduino vermittelt.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist auf jeden Fall praktisch, ein ganzes Kit zu kaufen, hier ist der Link: 

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


Verdrahtung
---------------------------

.. image:: img/Lesson_33_servo_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/12bb5427-6260-4b46-88a7-4b98f9db3ace/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analyse
---------------------------

1. Hier wird die ``Servo``-Bibliothek eingebunden, die eine einfache Steuerung des Servomotors ermöglicht. Der Pin, der mit dem Servo verbunden ist, sowie der anfängliche Winkel des Servos werden ebenfalls definiert.

   .. code-block:: arduino

      #include <Servo.h>
      const int servoPin = 9;  // Define the servo pin
      int angle = 0;           // Initialize the angle variable to 0 degrees
      Servo servo;             // Create a servo object

2. Die ``setup()``-Funktion läuft einmal, wenn das Arduino startet. Der Servo wird mit der Funktion ``attach()`` an den definierten Pin angeschlossen.

   .. code-block:: arduino

      void setup() {
        servo.attach(servoPin);
      }

3. Die Hauptschleife enthält zwei ``for``-Schleifen. Die erste Schleife erhöht den Winkel von 0 auf 180 Grad, und die zweite Schleife verringert den Winkel von 180 auf 0 Grad. Der Befehl ``servo.write(angle)`` setzt den Servo auf den angegebenen Winkel. Der Befehl ``delay(15)`` bewirkt, dass der Servo 15 Millisekunden wartet, bevor er sich zum nächsten Winkel bewegt, was die Geschwindigkeit der Scanbewegung steuert.

   .. code-block:: arduino

      void loop() {
        // scan from 0 to 180 degrees
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }
        // now scan back from 180 to 0 degrees
        for (angle = 180; angle > 0; angle--) {
          servo.write(angle);
          delay(15);
        }
      }