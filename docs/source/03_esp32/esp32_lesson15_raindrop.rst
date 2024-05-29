 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson15_raindrop:

Lektion 15: Regentropfen-Erkennungsmodul
=============================================

In dieser Lektion lernen Sie, wie Sie einen Regentropfen-Erkennungssensor mit einem ESP32-Entwicklungsboard verwenden. Wir werden das Auslesen digitaler Signale vom Sensor, wenn er Regenwasser erkennt, und die Anzeige dieser Informationen im seriellen Monitor behandeln. Dieses Projekt bietet eine spannende Möglichkeit, digitale Eingaben und Ausgaben in der Mikrocontroller-Programmierung zu verstehen und ist ideal für Anfänger in Elektronik und Programmierung mit der ESP32-Plattform.

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
    *   - :ref:`cpn_raindrop`
        - |link_raindrop_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_15_Raindrop_Detection_Module_esp32_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5aff47ab-22c5-4500-bbe3-fefc55f6e40f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

1. Definition des Sensor-Pins

   Hier wird ein konstanter Integer namens ``sensorPin`` definiert und der Wert 25 zugewiesen. Dies entspricht dem digitalen Pin auf dem ESP32-Entwicklungsboard, an dem der Regentropfen-Erkennungssensor angeschlossen ist.

   .. code-block:: arduino
   
       const int sensorPin = 25;

2. Einstellen des Pin-Modus und Initialisierung der seriellen Kommunikation.

   In der ``setup()``-Funktion werden zwei wesentliche Schritte ausgeführt. Erstens wird mit ``pinMode()`` der ``sensorPin`` als Eingang festgelegt, wodurch wir digitale Werte vom Regentropfen-Sensor lesen können. Zweitens wird die serielle Kommunikation mit einer Baudrate von 9600 initialisiert.

   .. code-block:: arduino
   
       void setup() {
         pinMode(sensorPin, INPUT);
         Serial.begin(9600);
       }

3. Auslesen des digitalen Wertes und Senden an den seriellen Monitor.

   Die ``loop()``-Funktion liest den digitalen Wert vom Regentropfen-Sensor mit ``digitalRead()``. Dieser Wert (entweder HIGH oder LOW) wird im seriellen Monitor ausgegeben. Wenn Regentropfen erkannt werden, zeigt der serielle Monitor 0 an; wenn keine Regentropfen erkannt werden, zeigt er 1 an. Das Programm wartet dann 50 Millisekunden, bevor die nächste Messung durchgeführt wird.

   .. code-block:: arduino
   
       void loop() {
         Serial.println(digitalRead(sensorPin));
         delay(50);
       }

