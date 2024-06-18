.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson24_vibration_sensor:

Lektion 24: Vibrationssensormodul (SW-420)
============================================================

In dieser Lektion lernen Sie, wie Sie Vibrationen mit einem ESP32-Entwicklungsboard und einem Vibrationssensor (SW-420) erkennen. Wir werden das Lesen des digitalen Ausgangs vom Sensor und die Verwendung von bedingten Anweisungen zum Anzeigen von Nachrichten auf dem seriellen Monitor behandeln. Wenn der Sensor Vibrationen erkennt, wird "Detected vibration..." angezeigt; andernfalls wird "..." ausgegeben. Dieses Projekt bietet eine praktische Möglichkeit, digitale Eingänge und serielle Kommunikation zu verstehen und ist ideal für Anfänger in Elektronik und Programmierung.

Benötigte Komponenten
-----------------------------------

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
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
------------------------

.. image:: img/Lesson_24_Vibration_Sensor_Module_esp32_bb.png
    :width: 100%

Code
-----------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a64a9f69-b056-4b41-993e-3f77101091e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
----------------------

1. Die erste Codezeile ist eine Konstante Integer-Deklaration für den Vibrationssensor-Pin. Wir verwenden den digitalen Pin 25, um den Ausgang des Vibrationssensors zu lesen.

   .. code-block:: arduino
   
      const int sensorPin = 25;

2. In der ``setup()``-Funktion initialisieren wir die serielle Kommunikation mit einer Baudrate von 9600, um die Messwerte vom Vibrationssensor auf dem seriellen Monitor anzuzeigen. Wir setzen auch den Vibrationssensor-Pin als Eingang.

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);         // Start serial communication at 9600 baud rate
        pinMode(sensorPin, INPUT);  // Set the sensorPin as an input pin
      }

3. Die ``loop()``-Funktion überprüft kontinuierlich, ob Vibrationen vom Sensor erkannt werden. Wenn der Sensor eine Vibration erkennt, wird "Detected vibration..." auf dem seriellen Monitor angezeigt. Wenn keine Vibration erkannt wird, wird "..." angezeigt. Die Schleife wiederholt sich alle 100 Millisekunden.

   .. code-block:: arduino
   
      void loop() {
        if (digitalRead(sensorPin)) {               // Check if there is any vibration detected by the sensor
          Serial.println("Detected vibration...");  // Print "Detected vibration..." if vibration detected
        } 
        else {
          Serial.println("...");  // Print "..." otherwise
        }
        // Add a delay to avoid flooding the serial monitor
        delay(100);
      }