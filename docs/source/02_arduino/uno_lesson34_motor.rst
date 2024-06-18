 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson34_motor:

Lektion 34: TT Motor
==================================

In dieser Lektion lernen Sie, wie Sie einen Motor mit einem Arduino Uno R3 oder R4 und einem L9110-Motorsteuerungsboard steuern. Wir behandeln die Definition von Motorpins und die Einstellung ihrer Geschwindigkeit durch Programmierung. Diese Anleitung führt Sie durch den Prozess des Anschließens und Steuerns eines Motors und demonstriert die grundlegenden Prinzipien der Motorsteuerung in Arduino-Projekten. Diese Lektion richtet sich an Anfänger und bietet einen praktischen Ansatz zum Verständnis von Ausgabeoperationen auf der Arduino-Plattform.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist auf jeden Fall praktisch, ein ganzes Kit zu kaufen, hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch separat über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-


Verkabelung
---------------------------

.. image:: img/Lesson_34_tt_motor_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/89894de5-2114-4056-a064-0c495c6de447/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

1. Der erste Teil des Codes definiert die Motorsteuerungspins. Diese sind mit dem L9110-Motorsteuerungsboard verbunden.

   .. code-block:: arduino
   
      // Define the motor pins
      const int motorB_1A = 9;
      const int motorB_2A = 10;

2. Die ``setup()``-Funktion initialisiert die Motorsteuerungspins als Ausgänge mit der ``pinMode()``-Funktion. Dann wird ``analogWrite()`` verwendet, um die Geschwindigkeit des Motors einzustellen. Der an ``analogWrite()`` übergebene Wert kann von 0 (aus) bis 255 (volle Geschwindigkeit) reichen. Eine ``delay()``-Funktion wird dann verwendet, um den Code für 5000 Millisekunden (oder 5 Sekunden) anzuhalten, danach wird die Motorgeschwindigkeit auf 0 (aus) gesetzt.

   .. code-block:: arduino
   
      void setup() {
        pinMode(motorB_1A, OUTPUT);  // set motor pin 1 as output
        pinMode(motorB_2A, OUTPUT);  // set motor pin 2 as output
   
        analogWrite(motorB_1A, 255);  // set motor speed (0-255)
        analogWrite(motorB_2A, 0);
   
        delay(5000);
   
        analogWrite(motorB_1A, 0);  
        analogWrite(motorB_2A, 0);
      }
