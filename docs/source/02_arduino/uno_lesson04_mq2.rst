 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson04_mq2:

Lektion 04: Gassensormodul (MQ-2)
============================================

In dieser Lektion lernen Sie, wie Sie den MQ-2 Gassensor mit einem Arduino Uno verwenden, um Gaskonzentrationen zu messen. Wir werden untersuchen, wie der Sensor analoge Ausgangswerte im Bereich von 0 bis 1023 liest, die die Konzentration von Gasen in der Luft darstellen. Dieses Projekt ist essenziell für das Verständnis der Umwelterfassung und der Verarbeitung von analogen Signalen mit Arduino und bietet eine großartige Einführung in die Arbeit mit Sensoren und die Interpretation ihrer Ausgaben. Wir werden die Wichtigkeit des Vorheizens des Sensors für genaue Messungen besprechen und die Grundlagen der seriellen Kommunikation zur Datenvisualisierung erläutern. Diese Lektion ist ideal für Anfänger, die an Arduino- und Umweltüberwachungsprojekten interessiert sind.

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_04_mq2_sensor_circuit_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6af3295c-28dd-4319-8f26-587930ffd2ef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

1. Die erste Codezeile deklariert eine konstante Ganzzahl für den Gassensor-Pin. Wir verwenden den analogen Pin A0, um den Ausgang des Gassensors zu lesen.

   .. code-block:: arduino
   
      const int sensorPin = A0;

2. Die Funktion ``setup()`` dient zur Initialisierung der seriellen Kommunikation mit einer Baudrate von 9600. Dies ist notwendig, um die Messwerte des Gassensors auf dem seriellen Monitor anzuzeigen.

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

3. Die Funktion ``loop()`` liest kontinuierlich den Analogwert des Gassensors und gibt ihn auf dem seriellen Monitor aus. Wir verwenden die Funktion ``analogRead()``, um den Analogwert des Sensors zu lesen. Danach warten wir 50 Millisekunden vor der nächsten Messung. Diese Verzögerung gibt dem seriellen Monitor etwas Zeit, die Daten zu verarbeiten.

   .. note:: 
   
     Der MQ2 ist ein heizbetriebener Sensor, der normalerweise vor dem Gebrauch vorgeheizt werden muss. Während der Vorheizphase liest der Sensor normalerweise hohe Werte, die allmählich abnehmen, bis sie sich stabilisieren.

   .. code-block:: arduino
   
      void loop() {
        Serial.print("Analog output: ");
        Serial.println(analogRead(sensorPin));  // Read the analog value of the gas sensor and print it to the serial monitor
        delay(50);                             // Wait for 50 milliseconds
      }


