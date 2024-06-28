.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson14_max30102:

Lektion 14: Pulsoximeter und Herzfrequenzsensor-Modul (MAX30102)
====================================================================

In dieser Lektion lernen Sie, wie Sie mit einem ESP32-Entwicklungsboard und dem MAX30102 Pulsoximeter- und Herzfrequenzsensor Ihre Herzfrequenz messen können. Wir werden die Einrichtung des Sensors, das Auslesen von Infrarotwerten und die genaue Berechnung der Schläge pro Minute (BPM) behandeln. Dieses Projekt ist ideal für alle, die sich für Gesundheitssysteme interessieren und eine wertvolle Einführung in die Arbeit mit biomedizinischen Sensoren mithilfe des ESP32 erhalten möchten.

.. warning::
    Dieses Projekt misst die Herzfrequenz optisch. Diese Methode ist kompliziert und anfällig für falsche Messungen. Verwenden Sie sie daher **NICHT** für tatsächliche medizinische Diagnosen.

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
    *   - :ref:`cpn_max30102`
        - |link_max30102_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_14_MAX30102_esp32_bb.png
    :width: 100%

Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"SparkFun MAX3010x"** und installieren Sie sie.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a59539a0-dab1-414e-a195-3d221a61c9a9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

1. **Einbinden von Bibliotheken & Initialisierung globaler Variablen**:

   Die wesentlichen Bibliotheken werden importiert, das Sensorobjekt wird instanziiert und globale Variablen für die Datenverwaltung werden festgelegt.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"SparkFun MAX3010x"** und installieren Sie sie.
   
   .. code-block:: arduino
    
      #include <Wire.h>
      #include "MAX30105.h"
      #include "heartRate.h"
      MAX30105 particleSensor;
      // ... (weitere globale Variablen)

2. **Setup-Funktion & Sensorinitialisierung**:

   Die serielle Kommunikation wird mit einer Baudrate von 9600 initialisiert. Die Verbindung des Sensors wird überprüft und bei Erfolg wird eine Initialisierungssequenz ausgeführt. Wenn der Sensor nicht erkannt wird, wird eine Fehlermeldung angezeigt.
   
   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
          Serial.println("MAX30102 not found.");
          while (1) ;  // Infinite loop if sensor not detected.
        }
        // ... (further setup)

3. **Auslesen des IR-Wertes & Überprüfung auf Herzschlag**:

   Der IR-Wert, der den Blutfluss anzeigt, wird vom Sensor abgerufen. Die Funktion ``checkForBeat()`` prüft, ob basierend auf diesem Wert ein Herzschlag erkannt wird.

   .. code-block:: arduino

      long irValue = particleSensor.getIR();
      if (checkForBeat(irValue) == true) {
          // ... (heartbeat detected actions)
      }

4. **Berechnung der Schläge pro Minute (BPM)**:

   Nach Erkennung eines Herzschlags wird der BPM basierend auf der Zeitdifferenz seit dem letzten erkannten Herzschlag berechnet. Der Code stellt auch sicher, dass der BPM-Wert innerhalb eines realistischen Bereichs liegt, bevor der Durchschnitt aktualisiert wird.

   .. code-block:: arduino

      long delta = millis() - lastBeat;
      beatsPerMinute = 60 / (delta / 1000.0);
      if (beatsPerMinute < 255 && beatsPerMinute > 20) {
          // ... (store and average BPM)
      }

5. **Ausgabe der Werte auf dem seriellen Monitor**:

   Der IR-Wert, der aktuelle BPM und der durchschnittliche BPM werden auf dem seriellen Monitor ausgegeben. Zusätzlich prüft der Code, ob der IR-Wert zu niedrig ist, was auf das Fehlen eines Fingers hindeutet.

   .. code-block:: arduino

      //Print the IR value, current BPM value, and average BPM value to the serial monitor
      Serial.print("IR=");
      Serial.print(irValue);
      Serial.print(", BPM=");
      Serial.print(beatsPerMinute);
      Serial.print(", Avg BPM=");
      Serial.print(beatAvg);

      if (irValue < 50000)
        Serial.print(" No finger?");