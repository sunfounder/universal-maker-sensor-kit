.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_motion_triggered_relay:

Lektion 38: Bewegungsaktiviertes Relais
=================================================

Dieses Projekt zielt darauf ab, ein relaisgesteuertes Licht mit einem Passiv-Infrarot-Sensor (PIR) zu steuern. 
Wenn der PIR-Sensor eine Bewegung erkennt, wird das Relais aktiviert und das Licht eingeschaltet. 
Das Licht bleibt 5 Sekunden nach der letzten erkannten Bewegung eingeschaltet.

.. warning::

    Zur Demonstration verwenden wir ein Relais, um ein RGB-LED-Modul zu steuern. 
    In realen Szenarien ist dies jedoch möglicherweise nicht die praktischste Vorgehensweise.
    
    **Während Sie das Relais in tatsächlichen Anwendungen mit anderen Geräten verbinden können, ist bei der Arbeit mit HOHER Wechselspannung äußerste Vorsicht geboten. Unsachgemäßer oder falscher Gebrauch kann zu schweren Verletzungen oder sogar zum Tod führen. Daher ist es nur für Personen gedacht, die mit HOHER Wechselspannung vertraut und sachkundig sind. Sicherheit hat immer oberste Priorität.**

Benötigte Komponenten
--------------------------

In diesem Projekt benötigen wir die folgenden Komponenten. 

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verdrahtung
---------------------------

.. image:: img/Lesson_38_Motion_triggered_relay_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5a29dc43-f362-434e-9e5a-f32dcd41b952/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code-Analyse
---------------------------

Das Projekt dreht sich um die Fähigkeit des PIR-Bewegungssensors, Bewegungen zu erkennen. Wenn eine Bewegung erkannt wird, sendet der Sensor ein Signal an das Arduino, das das Relaismodul auslöst, welches wiederum ein Licht aktiviert. Das Licht bleibt für eine bestimmte Dauer (in diesem Fall 5 Sekunden) nach der letzten erkannten Bewegung eingeschaltet, um sicherzustellen, dass der Bereich für kurze Zeit beleuchtet bleibt, auch wenn die Bewegung aufhört.

1. **Initiale Einrichtung und Variablendeklarationen**

    In diesem Abschnitt definieren wir Konstanten und Variablen, die im gesamten Code verwendet werden. Wir richten die Relais- und PIR-Pins ein und eine Verzögerungskonstante für Bewegungen. Außerdem haben wir eine Variable, um die Zeit der letzten erkannten Bewegung zu verfolgen, und eine Flagge, um zu überwachen, ob eine Bewegung erkannt wurde.

    .. code-block:: arduino
   
        // Define the pin number for the relay
        const int relayPin = 19;

        // Define the pin number for the PIR sensor
        const int pirPin = 18;

        // Motion delay threshold in milliseconds
        const unsigned long MOTION_DELAY = 5000;

        unsigned long lastMotionTime = 0;  // Timestamp of the last motion detection
        bool motionDetected = false;       // Flag to track if motion is detected
        
   

2. **Konfiguration der Pins in der setup() Funktion**

    In der ``setup()``-Funktion konfigurieren wir die Pin-Modi für das Relais und den PIR-Sensor. Wir initialisieren auch das Relais, sodass es zu Beginn ausgeschaltet ist.

    .. code-block:: arduino
    
        void setup() {
            pinMode(relayPin, OUTPUT);    // Set relayPin as an output pin
            pinMode(pirPin, INPUT);       // Set the PIR pin as an input
            digitalWrite(relayPin, LOW);  // Turn off the relay initially
        }

3. **Hauptlogik in der loop() Funktion**

    Die ``loop()``-Funktion enthält die Hauptlogik. Wenn der PIR-Sensor eine Bewegung erkennt, sendet er ein ``HIGH``-Signal, schaltet das Relais ein und aktualisiert die ``lastMotionTime``. Wenn innerhalb der angegebenen Verzögerung (in diesem Fall 5 Sekunden) keine Bewegung festgestellt wird, wird das Relais ausgeschaltet.
    
    Dieser Ansatz stellt sicher, dass das Licht auch bei sporadischen oder kurzen Bewegungen mindestens 5 Sekunden nach der letzten erkannten Bewegung eingeschaltet bleibt, wodurch eine konstante Beleuchtungsdauer gewährleistet wird.

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
    
   
