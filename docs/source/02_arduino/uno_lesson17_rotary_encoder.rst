 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson17_rotary_encoder:

Lektion 17: Drehgeber-Modul
==================================

In dieser Lektion lernen Sie, wie Sie einen Drehgeber mit einem Arduino Uno überwachen und steuern. Wir werden das Verfolgen der Drehrichtung (im Uhrzeigersinn oder gegen den Uhrzeigersinn), das Zählen der Umdrehungen und das Erkennen von Tastendrücken auf dem Drehgebermodul behandeln. Dieses Projekt ist ideal für diejenigen, die ihr Verständnis von Drehgebern und Ein-/Ausgabeoperationen mit Arduino vertiefen möchten und bietet praktische Einblicke in physische Steuerungssysteme.

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
    *   - :ref:`cpn_rotary_encoder`
        - \-

* Arduino UNO R3 or R4
* :ref:`cpn_rotary_encoder`

Verkabelung
---------------------------

.. image:: img/Lesson_17_Rotary_encoder_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d72d6a5f-72c7-4f94-ad4e-f7dc83b127de/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

#. **Setup und Initialisierung**

   .. code-block:: arduino

      void setup() {
        pinMode(CLK, INPUT);
        pinMode(DT, INPUT);
        pinMode(SW, INPUT_PULLUP);
        Serial.begin(9600);
        lastStateCLK = digitalRead(CLK);
      }

   In der Setup-Funktion werden die digitalen Pins, die mit den CLK- und DT-Anschlüssen des Encoders verbunden sind, als Eingänge definiert. Der SW-Pin, der mit dem Taster verbunden ist, wird als Eingang mit internem Pull-up-Widerstand definiert. Dadurch entfällt die Notwendigkeit eines externen Pull-up-Widerstands. Die serielle Kommunikation wird mit einer Baudrate von 9600 gestartet, um die Datenvisualisierung auf dem seriellen Monitor zu ermöglichen. Der Anfangszustand des CLK-Pins wird gelesen und gespeichert.

#. **Hauptschleife: Lesen des Encoders und des Tasterzustands**

   .. code-block:: arduino

      void loop() {
        currentStateCLK = digitalRead(CLK);
        if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {
          if (digitalRead(DT) != currentStateCLK) {
            counter--;
            currentDir = "CCW";
          } else {
            counter++;
            currentDir = "CW";
          }
          Serial.print("Direction: ");
          Serial.print(currentDir);
          Serial.print(" | Counter: ");
          Serial.println(counter);
        }
        lastStateCLK = currentStateCLK;
        int btnState = digitalRead(SW);
        if (btnState == LOW) {
          if (millis() - lastButtonPress > 50) {
            Serial.println("Button pressed!");
          }
          lastButtonPress = millis();
        }
        delay(1);
      }

   In der Loop-Funktion liest das Programm kontinuierlich den aktuellen Zustand des CLK-Pins. Wenn sich der Zustand ändert, bedeutet dies, dass eine Drehung stattgefunden hat. Die Drehrichtung wird durch Vergleich der Zustände der CLK- und DT-Pins bestimmt. Wenn sie unterschiedlich sind, bedeutet dies eine Drehung gegen den Uhrzeigersinn (CCW); andernfalls erfolgt die Drehung im Uhrzeigersinn (CW). Der Zähler des Encoders wird entsprechend erhöht oder verringert. Diese Information wird dann an den seriellen Monitor gesendet.

   Der Zustand des Tasters wird vom SW-Pin gelesen. Wenn er LOW (gedrückt) ist, wird ein Entprellmechanismus implementiert, indem die seit dem letzten Tastendruck vergangene Zeit überprüft wird. Wenn mehr als 50 Millisekunden vergangen sind, wird dies als gültiger Druck betrachtet und eine Nachricht an den seriellen Monitor gesendet. Das `delay(1)` am Ende hilft beim Entprellen.