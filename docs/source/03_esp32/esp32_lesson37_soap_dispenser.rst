.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_soap_dispenser:

Lektion 37: Automatischer Seifenspender
============================================

Das Projekt "Automatischer Seifenspender" verwendet ein Arduino Uno-Board zusammen 
mit einem Infrarot-Hindernisvermeidungssensor und einer Wasserpumpe. 
Der Sensor erkennt die Anwesenheit eines Objekts wie einer Hand, 
was die Wasserpumpe aktiviert, um Seife auszugeben.

Benötigte Komponenten
--------------------------------

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
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_power_module`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verdrahtung
---------------------------

.. image:: img/Lesson_37_Automatic_soap_dispenser_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f1923f60-5b82-497b-915f-ecc7ad46fea4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Code-Analyse
---------------------------

Die Hauptidee dieses Projekts besteht darin, ein berührungsloses Seifenspendersystem zu erstellen. Der Infrarot-Hindernisvermeidungssensor erkennt, wenn ein Objekt (wie eine Hand) nahe ist. Beim Erkennen eines Objekts sendet der Sensor ein Signal an das Arduino, das die Wasserpumpe aktiviert, um Seife auszugeben. Die Pumpe bleibt für eine kurze Zeit aktiv, gibt Seife ab und schaltet sich dann aus.

#. **Definition der Pins für den Sensor und die Pumpe**

    In diesem Codeausschnitt definieren wir die Arduino-Pins, die mit dem Sensor und der Pumpe verbunden sind. 
    Wir definieren Pin 7 als Sensorpin und verwenden die Variable ``sensorValue``, um die vom Sensor gelesenen Daten zu speichern. 
    Für die Wasserpumpe verwenden wir zwei Pins, 9 und 10.
    
    .. code-block:: arduino
   
        // Define the pin numbers for the Infrared obstacle avoidance sensor
        const int sensorPin = 35;
        int sensorValue;

        // Define pin numbers for the water pump
        const int pump1A = 19;
        const int pump1B = 21;

#. **Einrichten des Sensors und der Pumpe**

    In der ``setup()``-Funktion definieren wir die Modi für die verwendeten Pins. 
    Der Sensorpin wird auf ``INPUT`` gesetzt, da er zur Aufnahme von Daten vom Sensor verwendet wird. 
    Die Pumpenpins werden auf ``OUTPUT`` gesetzt, da sie Befehle an die Pumpe senden. 
    Wir stellen sicher, dass der Pin ``pump1B`` im ``LOW``-Zustand (aus) beginnt, 
    und starten die serielle Kommunikation mit einer Baudrate von 9600.

    .. code-block:: arduino
    
        void setup() {
            // Set the sensor pin as input
            pinMode(sensorPin, INPUT);

            // Initialize the pump pins as output
            pinMode(pump1A, OUTPUT);    
            pinMode(pump1B, OUTPUT);    

            // Keep pump1B low
            digitalWrite(pump1A, LOW); 
            digitalWrite(pump1B, LOW);  

            Serial.begin(9600);
        }

#. **Kontinuierliche Überprüfung des Sensors und Steuerung der Pumpe**

   In der ``loop()``-Funktion liest das Arduino ständig den Wert des Sensors mit ``digitalRead()`` und weist ihn ``sensorValue()`` zu. Anschließend wird dieser Wert zur Fehlerbehebung im seriellen Monitor angezeigt. Wenn der Sensor ein Objekt erkennt, beträgt ``sensorValue()`` 0. In diesem Fall wird ``pump1A`` auf ``HIGH`` gesetzt, wodurch die Pumpe aktiviert wird, und eine Verzögerung von 700 Millisekunden ermöglicht der Pumpe, Seife abzugeben. Die Pumpe wird dann durch Setzen von ``pump1A`` auf ``LOW`` deaktiviert, und eine Verzögerung von 1 Sekunde gibt dem Benutzer Zeit, seine Hand zu entfernen, bevor der Zyklus wiederholt wird.

   .. note:: 
   
      Wenn der Sensor nicht richtig funktioniert, justieren Sie den IR-Sender und -Empfänger, um sie parallel auszurichten. Außerdem können Sie den Erfassungsbereich mit dem eingebauten Potentiometer einstellen.

   .. code-block:: arduino
   
        void loop() {
            sensorValue = digitalRead(sensorPin);
            Serial.println(sensorValue);

            // If an object is detected, turn on the pump for a brief period, then turn it off
            if (sensorValue == 0) {  
                digitalWrite(pump1A, HIGH);
                delay(700);
                digitalWrite(pump1A, LOW);
                delay(1000);
            }
        }
