 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson31_pump:

Lektion 31: Zentrifugalpumpe
==================================

In dieser Lektion lernen Sie, wie Sie eine Zentrifugalpumpe mit einem ESP32-Entwicklungsboard und einer L9110-Motorsteuerungsplatine steuern. Wir werden den Aufbau und die Verwendung von zwei Pins zur Steuerung des Motors behandeln, wodurch die Pumpe für 5 Sekunden in eine Richtung dreht, bevor sie abgeschaltet wird. Dieses Projekt bietet praktische Erfahrungen im Umgang mit Motorsteuerungen und dem Verständnis digitaler Signale in der Mikrocontroller-Programmierung und ist daher ideal für Anfänger in der Elektronik und Programmierung.

Benötigte Komponenten
-------------------------

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verdrahtung
--------------

.. image:: img/Lesson_31_Pump_esp32_bb.png
    :width: 100%


Code
----------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b1b98b14-d067-4cba-8c3f-a04a8ad5e0c7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
-----------------

1. Zwei Pins werden für die Steuerung des Motors definiert, nämlich ``motorB_1A`` und ``motorB_2A``. Diese Pins werden mit der L9110-Motorsteuerungsplatine verbunden, um die Richtung und Geschwindigkeit des Motors zu steuern.
  
   .. code-block:: arduino
   
      const int motorB_1A = 26;
      const int motorB_2A = 25;

2. Konfiguration der Pins und Steuerung des Motors:

   - Die ``setup()``-Funktion initialisiert die Pins als ``OUTPUT``, was bedeutet, dass sie Signale an die Motorsteuerungsplatine senden können.

   - Die ``analogWrite()``-Funktion wird verwendet, um die Motorgeschwindigkeit einzustellen. Hier wird ein Pin auf ``HIGH`` und der andere auf ``LOW`` gesetzt, wodurch die Pumpe in eine Richtung dreht. Nach einer Verzögerung von 5 Sekunden werden beide Pins auf 0 gesetzt, wodurch der Motor abgeschaltet wird.

   .. raw:: html

      <br/>
   
   .. code-block:: arduino
   
      void setup() {
         pinMode(motorB_1A, OUTPUT);  // set pump pin 1 as output
         pinMode(motorB_2A, OUTPUT);  // set pump pin 2 as output
         analogWrite(motorB_1A, HIGH); 
         analogWrite(motorB_2A, LOW);
         delay(5000);// wait for 5 seconds
         analogWrite(motorB_1A, 0);  // turn off the pump
         analogWrite(motorB_2A, 0);
      }
