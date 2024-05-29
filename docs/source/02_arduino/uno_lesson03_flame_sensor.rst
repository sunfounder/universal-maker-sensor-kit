 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson03_flame:

Lektion 03: Flammensensormodul
==================================

In dieser Lektion lernen Sie, wie Sie einen Flammensensor mit einem Arduino-Board integrieren, um das Vorhandensein von Feuer zu erkennen. Wir werden sehen, wie der Flammensensor, wenn er eine Flamme erkennt, die eingebaute LED des Arduino zum Leuchten bringt und eine Warnmeldung an den seriellen Monitor sendet. Umgekehrt bleibt die LED in Abwesenheit einer Flamme ausgeschaltet und eine andere Nachricht wird an den Monitor übermittelt. Dieses Projekt ist ein hervorragender Einstieg für Anfänger und bietet ein umfassendes Verständnis dafür, wie digitale Ein- und Ausgänge auf der Arduino-Plattform verwaltet werden. Es bietet einen praxisnahen Ansatz, um die Integration von Sensoren und Echtzeitreaktionsmechanismen in einem Arduino-basierten System zu erlernen.

Benötigte Komponenten
---------------------------

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
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_03_flame_module_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/244b68c4-0c4d-46fb-b220-985d42f4efdc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

1. Die erste Codezeile deklariert eine konstante Ganzzahl für den Flammensensor-Pin. Wir verwenden den digitalen Pin 7, um den Ausgang des Flammensensors zu lesen.

   .. code-block:: arduino
   
      const int sensorPin = 7;

2. Die Funktion ``setup()`` initialisiert den Flammensensor-Pin als Eingang und den Pin der eingebauten LED als Ausgang. Sie startet auch die serielle Kommunikation mit einer Baudrate von 9600, um Nachrichten an den seriellen Monitor zu senden.

   .. code-block:: arduino
   
      void setup() {
        pinMode(sensorPin, INPUT);     // Set the flame sensor pin as input
        pinMode(LED_BUILTIN, OUTPUT);  // Set the built-in LED pin as output
        Serial.begin(9600);            // Initialize the serial monitor at a baud rate of 9600
      }

3. Die Funktion ``loop()`` überprüft kontinuierlich den Status des Flammensensors. Wenn der Sensor eine Flamme erkennt, wird die eingebaute LED eingeschaltet und eine Nachricht an den seriellen Monitor gesendet. Wenn keine Flamme erkannt wird, bleibt die LED ausgeschaltet und eine andere Nachricht wird gesendet. Dieser Vorgang wiederholt sich alle 100 Millisekunden.

   .. note:: 
      Sie können den Schwellenwert für die Flammenerkennung anpassen, indem Sie das Potentiometer auf dem Flammensensor-Modul einstellen.

   .. code-block:: arduino
   
      void loop() {
        // Check if the sensor is detecting a fire
        if (digitalRead(sensorPin) == 0) {
          digitalWrite(LED_BUILTIN, HIGH);  // Turn on the built-in LED
          Serial.println("** Fire detected!!! **");
        } else {
          digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED
          Serial.println("No Fire detected");
        }
        delay(100);
      }
