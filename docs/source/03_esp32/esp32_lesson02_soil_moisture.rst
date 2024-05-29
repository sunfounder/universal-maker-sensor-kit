 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson02_soil_moisture:

Lektion 02: Kapazitiver Bodenfeuchtesensor
==============================================

In dieser Lektion lernen Sie, wie Sie einen kapazitiven Bodenfeuchtesensor mit einem ESP32-Entwicklungsboard verwenden, um den Feuchtigkeitsgehalt des Bodens zu messen. Wir werden den Sensor an Pin 25 anschließen, seinen analogen Wert auslesen und diese Werte interpretieren, um den Feuchtigkeitsgehalt des Bodens zu bestimmen. Dieses Projekt ist ideal für Anfänger, da es praktische Erfahrungen im Umgang mit Sensoren und dem Verständnis analoger Eingaben auf der ESP32-Plattform bietet.

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
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_02_Capacitive_Soil_Moisture_Module_esp32_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ab3dd759-5698-477c-b837-0c3719a09b8d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. Definition des Sensorpins:

   Diese Codezeile deklariert eine Konstante ``sensorPin`` und weist ihr den Wert ``25`` zu, an dem der Sensor angeschlossen ist.

   .. code-block:: arduino

      const int sensorPin = 25;

#. Setup-Funktion:

   Die ``setup()``-Funktion wird einmal beim Programmstart ausgeführt. Sie initialisiert die serielle Kommunikation mit 9600 Baud. Diese Einrichtung ist notwendig, um Daten an den seriellen Monitor zu senden.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
      }

#. Loop-Funktion:

   Die ``loop()``-Funktion läuft kontinuierlich nach der ``setup()``. Sie liest den Sensorwert von Pin A0 mit ``analogRead()`` aus und gibt diesen Wert auf dem seriellen Monitor aus. Die Anweisung ``delay(500)`` pausiert die Schleife für 500 Millisekunden vor der nächsten Messung, wodurch die Datenakquisitionsrate gesteuert wird.

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));
        delay(500);
      }

