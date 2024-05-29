 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson07_speed:

Lektion 07: Infrarot-Geschwindigkeitssensormodul
=====================================================

In dieser Lektion lernen Sie, wie Sie die Motorgeschwindigkeit mit einem Geschwindigkeitssensormodul und einem Arduino Uno messen. Wir behandeln den Aufbau des Motors und des Sensors, das Programmieren des Arduino zur Berechnung der Umdrehungen pro Sekunde und die Anzeige der Daten. Dieses Projekt ist ideal für fortgeschrittene Lernende, da es praktische Erfahrungen mit der Echtzeitdatenverarbeitung und der Motorsteuerung auf der Arduino-Plattform bietet.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

Verkabelung
---------------------------

.. image:: img/Lesson_07_speed_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d705c03-2813-4e71-8ec6-1208684358c9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

#. Festlegen der Pins und Initialisieren von Variablen. Hier definieren wir die Pins für den Motor und den Geschwindigkeitssensor. Wir initialisieren auch Variablen, die zur Messung und Berechnung der Motordrehzahl verwendet werden.

   .. code-block:: arduino

      // Define the sensor and motor pins
      const int sensorPin = 11;
      const int motorB_1A = 9;
      const int motorB_2A = 10;
      
      // Define variables for measuring speed
      unsigned long start_time = 0;
      unsigned long end_time = 0;
      int steps = 0;
      float steps_old = 0;
      float temp = 0;
      float rps = 0;

#. Initialisierung in der ``setup()``-Funktion. In diesem Abschnitt wird die serielle Kommunikation eingerichtet, die Modi der Pins konfiguriert und die anfängliche Motordrehzahl festgelegt.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        pinMode(sensorPin, INPUT);
        pinMode(motorB_1A, OUTPUT);
        pinMode(motorB_2A, OUTPUT);
        analogWrite(motorB_1A, 160);
        analogWrite(motorB_2A, 0);
      }

#. Messung der Motordrehzahl in der ``loop()``-Funktion. In diesem Segment werden die Schritte des Motors für eine Dauer von 1 Sekunde gemessen. Diese Schritte werden dann verwendet, um die Umdrehungen pro Sekunde (rps) zu berechnen, die anschließend auf dem seriellen Monitor angezeigt werden.

   ``millis()`` gibt die Anzahl der Millisekunden zurück, die seit dem Start des aktuellen Programms auf dem Arduino-Board vergangen sind.

   .. code-block:: arduino

      void loop() {
        start_time = millis();
        end_time = start_time + 1000;
        while (millis() < end_time) {
          if (digitalRead(sensorPin)) {
            steps = steps + 1;
            while (digitalRead(sensorPin))
              ;
          }
        }
        temp = steps - steps_old;
        steps_old = steps;
        rps = (temp / 20);
        Serial.print("rps:");
        Serial.println(rps);
      }