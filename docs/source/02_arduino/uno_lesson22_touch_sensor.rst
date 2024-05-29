 .. _uno_lesson22_touch_sensor: .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!



Lektion 22: Berührungssensor-Modul
======================================

In dieser Lektion lernen Sie, wie Sie einen Berührungssensor mit einem Arduino Uno integrieren. Wir konzentrieren uns darauf, Eingaben vom Berührungssensor zu lesen, der mit dem Arduino verbunden ist, und wie diese Eingaben den Programmablauf beeinflussen. Sie erfahren, wie Sie bedingte Anweisungen verwenden, um Berührungsereignisse zu erkennen und mit entsprechenden Aktionen und Nachrichten zu reagieren. Dieses Projekt ist hervorragend für Anfänger geeignet und bietet ein klares Verständnis für die Arbeit mit digitalen Eingängen und grundlegenden Arduino-Programmierkonzepten.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link: 

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

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_touch`
        - |link_touch_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_22_touch_sensor_moudle_circuit_uno_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a0d962e5-5d21-4f26-88db-c38f8e9fb90c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. Festlegen der erforderlichen Variablen. Wir beginnen mit der Definition der Pinnummer, an die der Berührungssensor angeschlossen ist.

   .. code-block:: arduino

      const int sensorPin = 7;

#. Initialisierung in der ``setup()``-Funktion. Hier geben wir an, dass der Sensorpin als Eingang verwendet wird, die integrierte LED als Ausgang verwendet wird und wir die serielle Kommunikation starten, um Nachrichten an den seriellen Monitor zu senden.

   .. code-block:: arduino

      void setup() {
        pinMode(sensorPin, INPUT);
        pinMode(LED_BUILTIN, OUTPUT);
        Serial.begin(9600);
      }

#. Kontinuierlich prüft der Arduino, ob der Berührungssensor aktiviert ist. Bei Berührung wird die LED eingeschaltet und eine "Touch detected!"-Nachricht gesendet. Bei keiner Berührung wird die LED ausgeschaltet und eine "No touch detected..."-Nachricht gesendet. Eine Verzögerung wird eingeführt, um zu verhindern, dass der Sensor zu schnell ausgelesen wird.

   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == 1) {
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.println("Touch detected!");
        } else {
          digitalWrite(LED_BUILTIN, LOW);
          Serial.println("No touch detected...");
        }
        delay(100);
      }