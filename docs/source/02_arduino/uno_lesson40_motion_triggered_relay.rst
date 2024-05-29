 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson40_motion_triggered_relay:

Lektion 40: Bewegungsaktiviertes Relais
=============================================

Dieses Arduino-Projekt zielt darauf ab, ein relaisgesteuertes Licht mithilfe eines passiven Infrarotsensors (PIR) zu steuern. Wenn der PIR-Sensor eine Bewegung erkennt, wird das Relais aktiviert und das Licht eingeschaltet. Das Licht bleibt 5 Sekunden lang eingeschaltet, nachdem die letzte Bewegung erkannt wurde.

.. warning::
    Als Demonstration verwenden wir ein Relais, um ein RGB-LED-Modul zu steuern. In realen Szenarien ist dies möglicherweise nicht der praktischste Ansatz.
    
    **Obwohl Sie das Relais in tatsächlichen Anwendungen an andere Geräte anschließen können, ist äußerste Vorsicht geboten, wenn Sie mit hoher Wechselspannung (AC) arbeiten. Unsachgemäße oder falsche Verwendung kann zu schweren Verletzungen oder sogar zum Tod führen. Daher ist es für Personen gedacht, die mit hoher Wechselspannung vertraut und sachkundig sind. Sicherheit hat immer Vorrang.**

Benötigte Komponenten
--------------------------

In diesem Projekt benötigen wir die folgenden Komponenten. 

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

Sie können sie auch separat über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_40_Motion_triggered_relay_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1678870f-2731-4a6c-826d-2433214c4be4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

Das Projekt dreht sich um die Fähigkeit des PIR-Bewegungssensors, Bewegungen zu erkennen. Wenn eine Bewegung erkannt wird, wird ein Signal an das Arduino gesendet, das das Relaismodul auslöst, welches wiederum ein Licht aktiviert. Das Licht bleibt für eine festgelegte Dauer (in diesem Fall 5 Sekunden) nach der letzten erkannten Bewegung eingeschaltet, um sicherzustellen, dass der Bereich für kurze Zeit beleuchtet bleibt, auch wenn die Bewegung aufhört.
1. **Initiale Einrichtung und Variablendeklarationen**

   In diesem Abschnitt werden Konstanten und Variablen definiert, die im gesamten Code verwendet werden. Wir legen die Pins für das Relais und den PIR-Sensor sowie eine Verzögerungskonstante für die Bewegung fest. Außerdem gibt es eine Variable, die die Zeit der letzten Bewegungserkennung speichert, und eine Flagge, die überwacht, ob eine Bewegung erkannt wird.

   .. code-block:: arduino
   
      // Define the pin number for the relay
      const int relayPin = 9;
   
      // Define the pin number for the PIR sensor
      const int pirPin = 8;
   
      // Motion delay threshold in milliseconds
      const unsigned long MOTION_DELAY = 5000;
   
      unsigned long lastMotionTime = 0;  // Timestamp of the last motion detection
      bool motionDetected = false;       // Flag to track if motion is detected
   
   

2. **Konfiguration der Pins in der setup()-Funktion**

   In der ``setup()``-Funktion konfigurieren wir die Pin-Modi für das Relais und den PIR-Sensor. Außerdem initialisieren wir das Relais zu Beginn auf ausgeschaltet.

   .. code-block:: arduino
   
      void setup() {
        pinMode(relayPin, OUTPUT);    // Set relayPin as an output pin
        pinMode(pirPin, INPUT);       // Set the PIR pin as an input
        digitalWrite(relayPin, LOW);  // Turn off the relay initially
      }

3. **Hauptlogik in der loop()-Funktion**

   Die ``loop()``-Funktion enthält die Hauptlogik. Wenn der PIR-Sensor eine Bewegung erkennt, sendet er ein ``HIGH``-Signal, das Relais wird eingeschaltet und die ``lastMotionTime`` wird aktualisiert. Wenn für die festgelegte Verzögerung (in diesem Fall 5 Sekunden) keine Bewegung erkannt wird, wird das Relais ausgeschaltet.
   
   Dieser Ansatz stellt sicher, dass das Licht mindestens 5 Sekunden nach der letzten erkannten Bewegung eingeschaltet bleibt, auch wenn die Bewegung sporadisch oder kurz ist, um eine konsistente Beleuchtungsdauer zu gewährleisten.

   .. code-block:: arduino
   
      void loop() {
        if (digitalRead(pirPin) == HIGH) {
          lastMotionTime = millis();     // Update the last motion time
          digitalWrite(relayPin, HIGH);  // Turn on the relay (and hence the light)
          motionDetected = true;
        }
   
        // If motion was detected earlier and 5 seconds have elapsed, turn off the relay
        if (motionDetected && (millis() - lastMotionTime >= MOTION_DELAY)) {
          digitalWrite(relayPin, LOW);  // Turn off the relay
          motionDetected = false;
        }
      }

   
   