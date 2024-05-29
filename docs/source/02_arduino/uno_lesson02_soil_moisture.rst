 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson02_soil_moisture:

Lektion 02: Kapazitives Bodenfeuchtemodul
============================================

In dieser Lektion lernen Sie, wie Sie einen kapazitiven Bodenfeuchtesensor an ein Arduino anschließen und seine Messwerte interpretieren. Das Projekt umfasst das Auslesen des analogen Ausgangs des Sensors mit dem Arduino und das Verständnis, dass niedrigere Messwerte höhere Bodenfeuchtigkeitswerte anzeigen. Sie sammeln praktische Erfahrungen im Umgang mit analogen Eingängen und der seriellen Kommunikation mit dem Arduino, indem Sie den bereitgestellten Code als praktisches Beispiel verwenden.

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

Sie können sie auch separat über die folgenden Links kaufen.

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
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_02_Capacitive_Soil_Moisture_Module_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa2c3492-576b-4039-bbfe-891ed87e72c9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

#. Definition des Sensorpins:

   Diese Codezeile deklariert eine Konstante vom Typ Integer ``sensorPin`` und weist ihr den Wert ``A0`` zu, der dem analogen Eingangspin entspricht, an den der Sensor angeschlossen ist.

   .. code-block:: arduino

      const int sensorPin = A0;

#. Setup-Funktion:

   Die Funktion ``setup()`` wird einmal ausgeführt, wenn das Programm startet. Sie initialisiert die serielle Kommunikation mit einer Baudrate von 9600. Diese Einrichtung ist notwendig, um Daten an den seriellen Monitor zu senden.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
      }

#. Loop-Funktion:

   Die Funktion ``loop()`` wird nach ``setup()`` kontinuierlich ausgeführt. Sie liest den Sensorwert vom Pin A0 mit ``analogRead()`` und gibt diesen Wert auf dem seriellen Monitor aus. Die Anweisung ``delay(500)`` pausiert die Schleife für 500 Millisekunden vor der nächsten Messung und steuert so die Datenaufnahmefrequenz.

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(A0));
        delay(500);
      }


