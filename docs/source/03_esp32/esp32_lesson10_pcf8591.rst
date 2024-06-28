.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson10_pcf8591:

Lektion 10: PCF8591 ADC DAC Converter Modul
==============================================

In dieser Lektion lernen Sie, wie Sie das ESP32-Entwicklungsboard mit einem PCF8591 ADC DAC Converter Modul verbinden. Wir werden das Auslesen von analogen Werten vom Eingang AIN0, das Senden dieser Werte an den DAC (AOUT) und das Anzeigen sowohl der Rohwerte als auch der spannungsumgerechneten Messwerte im seriellen Monitor behandeln. Das Potentiometer des Moduls ist mit AIN0 über Jumperkappen verbunden, und die D2-LED auf dem Modul ist mit AOUT verbunden, sodass Sie sehen können, dass sich die Helligkeit der D2-LED ändert, wenn Sie das Potentiometer drehen.

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
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_10_PCF8591_Module_esp32_bb.png
    :width: 100%

Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"Adafruit PCF8591"** und installieren Sie sie. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f184da9-9ea5-4c8a-877e-a7a41abf8c15/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. **Bibliothek einbinden und Konstanten definieren**

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"Adafruit PCF8591"** und installieren Sie sie. 

   .. code-block:: arduino

      // Include Adafruit PCF8591 library
      #include <Adafruit_PCF8591.h>
      // Define the reference voltage for ADC conversion
      #define ADC_REFERENCE_VOLTAGE 3.3

   Dieser Abschnitt bindet die Adafruit PCF8591 Bibliothek ein, die Funktionen für die Interaktion mit dem PCF8591-Modul bereitstellt. Die ADC-Referenzspannung wird auf 3,3 Volt festgelegt, was die maximale Spannung ist, die der ADC messen kann.

#. **PCF8591-Modul einrichten**

   .. code-block:: arduino

      // Create an instance of the PCF8591 module
      Adafruit_PCF8591 pcf = Adafruit_PCF8591();
      void setup() {
        Serial.begin(9600);
        Serial.println("# Adafruit PCF8591 demo");
        if (!pcf.begin()) {
          Serial.println("# PCF8591 not found!");
          while (1) delay(10);
        }
        Serial.println("# PCF8591 found");
        pcf.enableDAC(true);
      }

   In der Setup-Funktion wird die serielle Kommunikation gestartet und eine Instanz des PCF8591-Moduls erstellt. Die Funktion ``pcf.begin()`` überprüft, ob das Modul korrekt angeschlossen ist. Wenn nicht, wird eine Fehlermeldung ausgegeben und das Programm angehalten. Wenn das Modul gefunden wird, wird der DAC aktiviert.

#. **Lesen vom ADC und Schreiben zum DAC**

   .. code-block:: arduino

      void loop() {
        AIN0 = pcf.analogRead(0);
        pcf.analogWrite(AIN0);
        Serial.print("AIN0: ");
        Serial.print(AIN0);
        Serial.print(", ");
        Serial.print(int_to_volts(AIN0, 8, ADC_REFERENCE_VOLTAGE));
        Serial.println("V");
        delay(500);
      }

   Die Loop-Funktion liest kontinuierlich den analogen Wert von AIN0 (analog input 0) des PCF8591-Moduls aus und schreibt diesen Wert zurück an den DAC. Außerdem druckt sie den Rohwert und den spannungsumgerechneten Wert von AIN0 auf den seriellen Monitor.

   Jumperkappen verbinden das Potentiometer des Moduls mit AIN0, und die D2-LED ist mit AOUT verbunden; bitte sehen Sie sich das Schaltbild des PCF8591-Moduls an :ref:`schematic <cpn_pcf8591_sch>` für Details. Die Helligkeit der LED ändert sich, wenn das Potentiometer gedreht wird.

#. **Funktion zur Umwandlung von Digital zu Spannung**

   .. code-block:: arduino

      float int_to_volts(uint16_t dac_value, uint8_t bits, float logic_level) {
        return (((float)dac_value / ((1 << bits) - 1)) * logic_level);
      }

   Diese Funktion wandelt den digitalen Wert zurück in die entsprechende Spannung um. Sie nimmt den digitalen Wert (``dac_value``), die Anzahl der Bits der Auflösung (``bits``) und die Spannung des Logikpegels (``logic_level``) als Argumente. Die verwendete Formel ist ein Standardansatz zur Umwandlung eines digitalen Wertes in die entsprechende Spannung.
