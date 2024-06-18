.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_heartrate_monitor:

Lektion 39: Herzfrequenzmonitor
==================================

Dieses Arduino-Projekt zielt darauf ab, einen einfachen Herzfrequenzmonitor mithilfe eines MAX30102 Pulsoximeter-Sensors und eines SSD1306 OLED-Displays zu bauen. Der Code misst die Herzfrequenz, indem er die Zeit zwischen Herzschlägen bestimmt. Durch die Aufnahme von vier Messungen wird deren Durchschnitt berechnet und die resultierende durchschnittliche Herzfrequenz auf einem OLED-Bildschirm angezeigt. Wenn der Sensor keinen Finger erkennt, sendet er eine Aufforderung an den Benutzer, seinen Finger korrekt auf den Sensor zu legen.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_max30102`
        - |link_max30102_module_buy|
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verdrahtung
---------------------------

.. image:: img/Lesson_39_Heart_rate_monitor_esp32_bb.png
    :width: 100%


Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, öffnen Sie den Arduino Library Manager, suchen Sie nach **"SparkFun MAX3010x"**, **"Adafruit SSD1306"** und **"Adafruit GFX"**, und installieren Sie diese.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1da3c9e2-e205-4af9-8741-43f7ea19bec8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Code-Analyse
---------------------------

Das Hauptprinzip hinter diesem Projekt besteht darin, die Pulsation des Blutflusses durch einen Finger mithilfe des MAX30102 Sensors zu erfassen. 
Wenn das Blut durch den Körper pumpt, verursacht es winzige Veränderungen im Blutvolumen in den Gefäßen der Fingerspitze. 
Durch das Durchleuchten des Fingers und Messen der Menge an Licht, die absorbiert oder zurückreflektiert wird, 
erkennt der Sensor diese minimalen Volumenänderungen. 
Das Zeitintervall zwischen aufeinanderfolgenden Pulsen wird dann verwendet, um die Herzfrequenz in Schlägen pro Minute (BPM) zu berechnen. 
Dieser Wert wird dann über vier Messungen gemittelt und auf dem OLED-Bildschirm angezeigt.

1. **Bibliothekseinbindungen und erste Deklarationen**:

   Der Code beginnt mit dem Einbinden der notwendigen Bibliotheken für das OLED-Display, den MAX30102 Sensor und die Herzfrequenzberechnung. Außerdem werden die Konfiguration des OLED-Displays und die Variablen für die Herzfrequenzberechnung deklariert.

   .. note:: 
      Um die Bibliothek zu installieren, öffnen Sie den Arduino Library Manager, suchen Sie nach **"SparkFun MAX3010x"**, **"Adafruit SSD1306"** und **"Adafruit GFX"**, und installieren Sie diese.

   .. code-block:: arduino

      #include <Adafruit_GFX.h>  // OLED  libraries
      #include <Adafruit_SSD1306.h>
      #include <Wire.h>
      #include "MAX30105.h"   // MAX3010x library
      #include "heartRate.h"  // Heart rate  calculating algorithm

      // ... Variables and OLED configuration

   In diesem Projekt haben wir auch ein paar Bitmaps erstellt. 
   Das ``PROGMEM``-Schlüsselwort kennzeichnet, dass das Array im Programmspeicher des Mikrocontrollers gespeichert wird. 
   Das Speichern von Daten im Programmspeicher (PROGMEM) anstelle von RAM kann hilfreich sein für große Datenmengen, 
   die sonst zu viel Platz im RAM beanspruchen würden.


   .. code-block:: arduino

      static const unsigned char PROGMEM beat1_bmp[] = {...}

      static const unsigned char PROGMEM beat2_bmp[] = {...}

2. **Setup-Funktion**:

   Initialisiert die I2C-Kommunikation, startet die serielle Kommunikation, initialisiert das OLED-Display 
   und richtet den MAX30102 Sensor ein.

   .. code-block:: arduino

      void setup() {
          Wire.setClock(400000);
          Serial.begin(9600);
          display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
          // ... Rest of the setup code

3. **Hauptschleife**:

   Die Kernfunktionalität befindet sich hier. Der IR-Wert wird vom Sensor gelesen. 
   Wenn ein Finger erkannt wird (IR-Wert größer als 50.000), prüft das Programm, ob ein Herzschlag erkannt wird. 
   Wenn ein Herzschlag erkannt wird, 
   zeigt der OLED-Bildschirm die BPM an und das Zeitintervall zwischen den Herzschlägen wird zur Berechnung der BPM verwendet. 
   Andernfalls wird der Benutzer aufgefordert, seinen Finger auf den Sensor zu legen.
   
   Wir haben auch zwei Bitmaps mit Herzschlägen vorbereitet, 
   und durch das Wechseln zwischen diesen beiden Bitmaps können wir einen dynamischen visuellen Effekt erzielen.

   .. code-block:: arduino

      void loop() {
        // Get IR value from sensor
        long irValue = particleSensor.getIR();  
      
        //If a finger is detected
        if (irValue > 50000) {
      
          // Check if a beat is detected
          if (checkForBeat(irValue) == true) {

            // Update OLED display
            // Calculate the BPM
      
            // Calculate the average BPM
            //Print the IR value, current BPM value, and average BPM value to the serial monitor

            // Update OLED display
            
          }
        }
        else {
          // ... Prompt to place the finger on the sensor
        }
      }
      

