 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson08_ir_obstacle_avoidance:

Lektion 08: IR-Hindernisvermeidungssensormodul
====================================================

In dieser Lektion lernen Sie, wie Sie einen Infrarot-Hindernisvermeidungssensor mit einem ESP32-Entwicklungsboard verwenden. Wir werden untersuchen, wie der Sensor Hindernisse erkennt und sein Ausgangssignal ändert. Sie lernen auch, wie Sie diese Signale mit dem ESP32 auslesen und auf dem seriellen Monitor anzeigen. Dieses Projekt bietet Anfängern eine großartige Gelegenheit, praktische Erfahrungen mit Sensoren und der Verarbeitung digitaler Eingaben auf der ESP32-Plattform zu sammeln, und ist somit ideal für diejenigen, die interaktive Projekte entwickeln möchten.

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
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_08_Obstacle_Avoidance_Sensor_Module_esp32_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e04a4a04-e707-46a1-aee5-488add646356/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

1. Definition der Pinnummer für den Sensoranschluss:

   .. code-block:: arduino

     const int sensorPin = 25;

   Verbinden Sie den Ausgangspin des Sensors mit Pin 25.

2. Einrichtung der seriellen Kommunikation und Definition des Sensorpins als Eingang:

   .. code-block:: arduino

     void setup() {
       pinMode(sensorPin, INPUT);  
       Serial.begin(9600);
     }

   Initialisieren Sie die serielle Kommunikation mit einer Baudrate von 9600, um Daten auf dem seriellen Monitor anzuzeigen.
   Setzen Sie den Sensorpin als Eingang, um das Eingangssignal zu lesen.

3. Auslesen des Sensorwerts und Ausgabe auf dem seriellen Monitor:

   .. code-block:: arduino

     void loop() {
       Serial.println(digitalRead(sensorPin));
       delay(50); 
     }
   
   Lesen Sie kontinuierlich den digitalen Wert vom Sensorpin mit ``digitalRead()`` und geben Sie den Wert mit ``Serial.println()`` auf dem seriellen Monitor aus.
   Fügen Sie eine Verzögerung von 50 ms zwischen den Ausgaben hinzu, um die Anzeige zu verbessern.

   .. note:: 
   
      Wenn der Sensor nicht richtig funktioniert, richten Sie den IR-Sender und -Empfänger parallel aus. Zusätzlich können Sie die Erkennungsreichweite mit dem eingebauten Potentiometer einstellen.

