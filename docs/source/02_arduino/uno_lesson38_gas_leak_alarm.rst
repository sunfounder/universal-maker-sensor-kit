 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson38_gas_leak_alarm:

Lektion 38: Gasaustrittsalarm
==================================

In diesem Projekt geht es darum, ein Szenario zur Erkennung von Gaslecks mit einem Arduino Uno Board zu simulieren. Durch die Verwendung eines MQ-2 Gassensors und einer RGB-LED wird kontinuierlich die Gaskonzentration gemessen. Überschreitet diese Konzentration einen vordefinierten Schwellenwert, wird ein Alarm (Summer) aktiviert und die RGB-LED leuchtet rot. Bleibt die Konzentration unter diesem Schwellenwert, bleibt der Alarm inaktiv und die LED leuchtet grün. Es ist wichtig zu beachten, dass diese Demo rein illustrativ ist und keine echten Gasleck-Erkennungssysteme ersetzen sollte.

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

Man kann sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_module_buy|
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verkabelung
---------------------------

.. image:: img/Lesson_38_Gas_leak_alarm_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/314a351a-9c54-4938-bb72-1471f1807adb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

Das Kernprinzip des Projekts besteht darin, die Gaskonzentration kontinuierlich zu überwachen. Wenn die gemessene Gaskonzentration einen bestimmten Schwellenwert überschreitet, wird ein Alarm ausgelöst und die LED wechselt die Farbe auf Rot. Dies dient als simuliertes Warnsystem und weist auf potenziell gefährliche Bedingungen hin. Sinkt die Konzentration unter den Schwellenwert, wird der Alarm deaktiviert und die LED wechselt zu Grün, was auf eine sichere Umgebung hinweist.

1. Definition von Konstanten und Variablen

   Diese Zeilen deklarieren und initialisieren die Pinnummern für verschiedene Komponenten. Der ``sensorPin`` bezeichnet den analogen Pin, an den der MQ-2 Gassensor angeschlossen ist. ``sensorValue`` ist eine Ganzzahlvariable, die den analogen Ausgang des Sensors speichert. Der ``buzzerPin`` gibt den digitalen Pin an, an den der Summer angeschlossen ist. Schließlich sind die ``RPin`` und ``GPin`` die Pins für die roten und grünen Kanäle der RGB-LED.

   .. code-block:: arduino
   
      // Define the pin numbers for the Gas Sensor
      const int sensorPin = A0;
      int sensorValue;
   
      // Define the pin number for the buzzer
      const int buzzerPin = 9;
   
      // Define pin numbers for the RGB LED
      const int RPin = 5;  // R channel of RGB LED
      const int GPin = 6;  // G channel of RGB LED
   
2. Initialisierung in ``setup()``

   Die Funktion ``setup()`` initialisiert die erforderlichen Einstellungen. Die serielle Kommunikation beginnt mit einer Baudrate von 9600, sodass wir die Sensordaten im seriellen Monitor anzeigen können. Die Pins für den Summer und die RGB-LED werden als ``OUTPUT`` gesetzt, was bedeutet, dass sie Signale an externe Komponenten senden.

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
   
        // Initialize the buzzer and RGB LED pins as output
        pinMode(buzzerPin, OUTPUT);
        pinMode(RPin, OUTPUT);
        pinMode(GPin, OUTPUT);
      }
   

3. Hauptschleife: Sensorlesen und Alarm auslösen

   Die Funktion ``loop()`` liest kontinuierlich den Ausgang des Gassensors. Die Messwerte werden dann im seriellen Monitor zur Beobachtung angezeigt. Abhängig vom Sensorwert können zwei Szenarien auftreten:
   
   - Wenn der Wert 300 überschreitet, wird der Summer mit ``tone()`` aktiviert und die RGB-LED leuchtet rot.
   - Wenn der Wert unter 300 liegt, wird der Summer mit ``noTone()`` stummgeschaltet und die LED leuchtet grün.
   
   Abschließend wird eine Verzögerung von 50 Millisekunden eingefügt, bevor die nächste Schleifeniteration beginnt, um die Lesehäufigkeit zu steuern und die CPU-Belastung zu reduzieren.

   .. code-block:: arduino
   
      void loop() {
        // Read the analog value of the gas sensor
        sensorValue = analogRead(sensorPin);
   
        // Print the sensor value to the serial monitor
        Serial.print("Analog output: ");
        Serial.println(sensorValue);
   
        // If the sensor value exceeds the threshold, trigger the alarm and make the RGB LED red
        if (sensorValue > 300) {
          tone(buzzerPin, 500, 300);
          digitalWrite(GPin, LOW);
          digitalWrite(RPin, HIGH);
        } else {
          // If the sensor value is below the threshold, turn off the alarm and make the RGB LED green
          noTone(buzzerPin);
          digitalWrite(RPin, LOW);
          digitalWrite(GPin, HIGH);
        }
   
        // Wait for 50 milliseconds before the next loop iteration
        delay(50);
      }
   
   
