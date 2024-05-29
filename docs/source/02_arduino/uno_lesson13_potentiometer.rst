 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson13_potentiometer:

Lektion 13: Potentiometer-Modul
==================================

In dieser Lektion lernen Sie, wie Sie den Analogwert eines Potentiometers mit einem Arduino Uno auslesen. Wir werden das Potentiometer an Pin A0 anschließen und den Arduino verwenden, um seinen Wert von 0 bis 1023 zu messen. Dieses Tutorial führt Sie durch den Aufbau der Schaltung, das Schreiben des Codes zum Auslesen des Sensors und das Anzeigen der Messwerte auf dem seriellen Monitor. Es ist ein großartiges Projekt für Anfänger, das praktische Erfahrungen mit analogen Eingängen und serieller Kommunikation auf der Arduino-Plattform bietet.

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_sensor_module_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_13_potentiometer_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ce0f8eac-f28f-4168-be2c-bcaabb1b4c78/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

#. Diese Codezeile definiert die Pinnummer, an die das Potentiometer auf dem Arduino-Board angeschlossen ist.

   .. code-block:: arduino

      const int sensorPin = A0;

#. Die ``setup()``-Funktion ist eine spezielle Funktion in Arduino, die nur einmal ausgeführt wird, wenn der Arduino eingeschaltet oder zurückgesetzt wird. In diesem Projekt startet der Befehl ``Serial.begin(9600)`` die serielle Kommunikation mit einer Baudrate von 9600.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  
      }

#. Die ``loop()``-Funktion ist die Hauptfunktion, in der das Programm wiederholt ausgeführt wird. In dieser Funktion liest die ``analogRead()``-Funktion den analogen Wert vom Potentiometer und gibt ihn mit ``Serial.println()`` auf dem seriellen Monitor aus. Der Befehl ``delay(50)`` lässt das Programm 50 Millisekunden warten, bevor die nächste Messung vorgenommen wird.

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));  
        delay(50);
      }

