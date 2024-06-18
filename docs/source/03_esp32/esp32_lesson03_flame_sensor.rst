.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson03_flame:

Lektion 03: Flammensensormodul
==================================

In dieser Lektion lernen Sie, wie Sie einen Flammensensor mit einem ESP32-Entwicklungsboard verbinden, um Brände zu erkennen. Wir werden die Reaktion des Sensors auf Feuer untersuchen und wie er eine Warnmeldung auslöst. Dieses Projekt ist ideal für Anfänger, die mit Sensoren und ESP32 arbeiten und praktische Erfahrungen im Überwachen von Umweltfaktoren mit grundlegenden elektronischen Komponenten sammeln möchten.

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
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_03_Flame_Sensor_Module_esp32_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/82f965f6-4213-4c23-88db-4257cf12d920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. **Definition des Sensorpins**:

   Der Pin, an den der Flammensensor angeschlossen ist, wird als ganzzahlige Konstante definiert.
 
   .. code-block:: arduino

      const int sensorPin = 25;

#. **Setup-Funktion**:

   Diese Funktion läuft einmal, wenn der ESP32 startet. Sie initialisiert den Sensorpin als Eingang und beginnt die serielle Kommunikation mit einer Baudrate von 9600 zur Ausgabe.
 
   .. code-block:: arduino

      void setup() {
        pinMode(sensorPin, INPUT);
        Serial.begin(9600);
      }

#. **Loop-Funktion**:

   Der Kern des Programms prüft kontinuierlich den Zustand des Flammensensors. Wenn der Sensor eine Flamme erkennt (Rückgabewert 0), wird eine Feuerwarnmeldung ausgegeben. Andernfalls wird angezeigt, dass kein Feuer erkannt wurde. Die Überprüfung erfolgt alle 100 Millisekunden.
 
   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == 0) {
          Serial.println("** Fire detected!!! **");
        } else {
          Serial.println("No Fire detected");
        }
        delay(100);
      }
