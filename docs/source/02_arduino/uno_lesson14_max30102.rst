 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson14_max30102:

Lektion 14: Pulsoximeter und Herzfrequenzsensormodul (MAX30102)
====================================================================

In dieser Lektion lernen Sie, wie Sie die Herzfrequenz mit einem MAX30102-Sensor und einem Arduino Uno messen. Sie lernen, den Sensor einzurichten, Infrarotwerte zu lesen, den BPM zu berechnen und die Messwerte über die Zeit zu mitteln. Dieses Projekt ist perfekt für alle, die sich für Gesundheitsüberwachung mit Arduino interessieren und dabei Hardware-Interfacing und Software-Logik kombinieren möchten.

.. warning::
    Dieses Projekt erfasst die Herzfrequenz optisch. Diese Methode ist schwierig und kann falsche Messwerte liefern. Verwenden Sie sie daher **NICHT** für tatsächliche medizinische Diagnosen.

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_max30102`
        - |link_max30102_module_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_14_max30102_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/448258fd-5114-4b94-b3fc-9c2fcc308899/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

1. **Bibliotheken einbinden & globale Variablen initialisieren**:

   Die notwendigen Bibliotheken werden importiert, das Sensorobjekt wird instanziiert und globale Variablen zur Datenverwaltung werden festgelegt.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"SparkFun MAX3010x"** und installieren Sie diese. 
   
   .. code-block:: arduino
    
      #include <Wire.h>
      #include "MAX30105.h"
      #include "heartRate.h"
      MAX30105 particleSensor;
      // ... (other global variables)

2. **Setup-Funktion & Sensorinitialisierung**:

   Die serielle Kommunikation wird mit einer Baudrate von 9600 initialisiert. Die Verbindung des Sensors wird überprüft, und bei Erfolg wird eine Initialisierungssequenz ausgeführt. Eine Fehlermeldung wird angezeigt, wenn der Sensor nicht erkannt wird.
   
   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
          Serial.println("MAX30102 not found.");
          while (1) ;  // Infinite loop if sensor not detected.
        }
        // ... (further setup)

3. **IR-Wert lesen & Herzschlag prüfen**:

   Der IR-Wert, der den Blutfluss anzeigt, wird vom Sensor abgerufen. Die Funktion ``checkForBeat()`` bewertet, ob basierend auf diesem Wert ein Herzschlag erkannt wird.

   .. code-block:: arduino

      long irValue = particleSensor.getIR();
      if (checkForBeat(irValue) == true) {
          // ... (heartbeat detected actions)
      }

4. **Schläge pro Minute (BPM) berechnen**:

   Bei der Erkennung eines Herzschlags wird der BPM-Wert basierend auf der Zeitdifferenz seit dem letzten erkannten Herzschlag berechnet. Der Code stellt auch sicher, dass der BPM-Wert innerhalb eines realistischen Bereichs liegt, bevor der Durchschnittswert aktualisiert wird.

   .. code-block:: arduino

      long delta = millis() - lastBeat;
      beatsPerMinute = 60 / (delta / 1000.0);
      if (beatsPerMinute < 255 && beatsPerMinute > 20) {
          // ... (store and average BPM)
      }
      

5. **Werte auf dem seriellen Monitor ausgeben**:

   Der IR-Wert, der aktuelle BPM-Wert und der durchschnittliche BPM-Wert werden auf dem seriellen Monitor ausgegeben. Zusätzlich überprüft der Code, ob der IR-Wert zu niedrig ist, was auf das Fehlen eines Fingers hindeutet.

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