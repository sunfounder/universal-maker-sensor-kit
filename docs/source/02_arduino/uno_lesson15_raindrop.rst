 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson15_raindrop:

Lektion 15: Regensensor-Modul
=======================================

In dieser Lektion lernen Sie, wie Sie ein Regensensor-Modul mit einem Arduino verwenden. Wir werden sehen, wie der Sensor Regen erkennt, indem er Änderungen im Widerstand misst, die durch Regentropfen verursacht werden, die auf seiner nickelbeschichteten Oberfläche Schaltkreise schließen.

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
    *   - :ref:`cpn_raindrop`
        - |link_raindrop_sensor_module_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_15_raindrop_detection_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/856a64c8-ecb6-455e-97e6-186cb8d159ea/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

1. Definition des Sensorpins

   Hier wird ein konstanter Integer namens ``sensorPin`` definiert und mit dem Wert 7 belegt. Dies entspricht dem digitalen Pin auf dem Arduino-Board, an dem der Regensensor angeschlossen ist.

   .. code-block:: arduino
   
       const int sensorPin = 7;

2. Einstellen des Pin-Modus und Initialisierung der seriellen Kommunikation.

   In der ``setup()``-Funktion werden zwei wesentliche Schritte durchgeführt. Erstens wird mit ``pinMode()`` der ``sensorPin`` als Eingang festgelegt, um digitale Werte vom Regensensor lesen zu können. Zweitens wird die serielle Kommunikation mit einer Baudrate von 9600 initialisiert.

   .. code-block:: arduino
   
       void setup() {
         pinMode(sensorPin, INPUT);
         Serial.begin(9600);
       }

3. Lesen des digitalen Wertes und Senden an den seriellen Monitor. 

   Die ``loop()``-Funktion liest den digitalen Wert vom Regensensor mit ``digitalRead()``. Dieser Wert (entweder HIGH oder LOW) wird auf dem seriellen Monitor angezeigt. Wenn Regentropfen erkannt werden, zeigt der serielle Monitor 0 an; wenn keine Regentropfen erkannt werden, zeigt er 1 an. Das Programm wartet dann 50 Millisekunden, bevor die nächste Messung durchgeführt wird.

   .. code-block:: arduino
   
       void loop() {
         Serial.println(digitalRead(sensorPin));
         delay(50);
       }

