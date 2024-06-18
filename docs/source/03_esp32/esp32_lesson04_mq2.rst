.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson04_mq2:

Lektion 04: Gassensormodul (MQ-2)
============================================

In dieser Lektion lernen Sie, wie Sie mit einem MQ-2-Sensor und einem ESP32-Entwicklungsboard Gaskonzentrationen messen. Wir werden das analoge Ausgangssignal des Gassensors auslesen und es auf dem seriellen Monitor anzeigen. Dieses Projekt ist ideal für Elektronikanfänger, da es praktische Erfahrungen mit Sensoren und Mikrocontrollern bietet und gleichzeitig das Verständnis für die Verarbeitung analoger Signale und die serielle Kommunikation vermittelt.

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_04_MQ2_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/79ef2209-7e92-4a53-81f2-1ba01214af31/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

1. Die erste Codezeile ist eine Konstante Deklaration für den Gassensor-Pin. Wir verwenden den Pin 25, um den Ausgang des Gassensors zu lesen.

   .. code-block:: arduino
   
      const int sensorPin = 25;

2. In der ``setup()``-Funktion initialisieren wir die serielle Kommunikation mit einer Baudrate von 9600. Dies ist notwendig, um die Messwerte des Gassensors auf dem seriellen Monitor anzuzeigen.

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

3. Die ``loop()``-Funktion liest kontinuierlich den analogen Wert des Gassensors und gibt ihn auf dem seriellen Monitor aus. Wir verwenden die Funktion ``analogRead()``, um den analogen Wert vom Sensor zu lesen. Anschließend warten wir 50 Millisekunden vor der nächsten Messung. Diese Verzögerung gibt dem seriellen Monitor etwas Zeit, um die Daten zu verarbeiten.

   .. note:: 
   
     Der MQ2 ist ein heizungsbetriebener Sensor, der normalerweise vor der Verwendung vorgeheizt werden muss. Während der Vorheizphase liest der Sensor typischerweise hohe Werte und nimmt allmählich ab, bis er sich stabilisiert.

   .. code-block:: arduino
   
      void loop() {
        Serial.print("Analog output: ");
        Serial.println(analogRead(sensorPin));  // Read the analog value of the gas sensor and print it to the serial monitor
        delay(50);                             // Wait for 50 milliseconds
      }


      