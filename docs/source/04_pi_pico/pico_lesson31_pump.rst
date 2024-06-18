 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson31_pump:
Lesson 31: Zentrifugalpumpe
==================================

In dieser Lektion lernen Sie, wie Sie eine Zentrifugalpumpe mit dem Raspberry Pi Pico W und einem L9110-Motorsteuerungsboard betreiben. Wir führen Sie durch den Prozess der Konfiguration von zwei PWM (Pulsweitenmodulation) Pins zur Steuerung des Motors. Sie richten die Pumpe ein, um für 5 Sekunden zu laufen und dann auszuschalten. Diese praktische Übung bietet eine wertvolle Gelegenheit, sich mit Motorsteuerungsmechanismen und PWM-Signalen vertraut zu machen, die in der Mikrocontroller-Programmierung entscheidend sind. 

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten. 

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

Sie können sie auch einzeln von den folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_31_Pump_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   import time
   
   pump_a = PWM(Pin(26), freq=1000)
   pump_b = PWM(Pin(27), freq=1000)
   
   # turn on pump
   pump_a.duty_u16(0)
   pump_b.duty_u16(65535)  # speed(0-65535)
   
   time.sleep(5)
   
   # turn off pump
   pump_a.duty_u16(0)
   pump_b.duty_u16(0)


Codeanalyse
---------------------------

#. Bibliotheken importieren

   - Das Modul ``machine`` wird importiert, um mit den GPIO-Pins und den PWM-Funktionen des Raspberry Pi Pico W zu interagieren.
   - Das Modul ``time`` wird verwendet, um Verzögerungen im Code zu erzeugen.

   .. raw:: html

      <br/>

   .. code-block:: python

      from machine import Pin, PWM
      import time

#. Initialisierung von PWM-Objekten

   - Zwei PWM-Objekte, ``pump_a`` und ``pump_b``, werden erstellt. Sie entsprechen den GPIO-Pins 26 und 27.
   - Die Frequenz für PWM wird auf 1000 Hz eingestellt, eine gängige Frequenz für die Motorsteuerung.

   .. raw:: html

      <br/>

   .. code-block:: python

      pump_a = PWM(Pin(26), freq=1000)
      pump_b = PWM(Pin(27), freq=1000)

#. Einschalten der Pumpe

   - ``pump_a.duty_u16(0)`` setzt die Tastverhältnis des Pins ``pump_a`` auf 0, während ``pump_b.duty_u16(65535)`` das Tastverhältnis des Pins ``pump_b`` auf 65535 setzt und den Motor mit voller Geschwindigkeit laufen lässt. Für weitere Details siehe :ref:`the working principle of L9110 <cpn_l9110_principle>`.
   - Die Pumpe läuft für 5 Sekunden, gesteuert durch ``time.sleep(5)``.

   .. raw:: html

      <br/>

   .. code-block:: python

      # turn on pump
      pump_a.duty_u16(0)
      pump_b.duty_u16(65535)  # speed(0-65535)
      time.sleep(5)

#. Ausschalten der Pumpe

   Sowohl ``pump_a`` als auch ``pump_b`` werden auf ein Tastverhältnis von 0 gesetzt, wodurch der Motor gestoppt wird.

   .. code-block:: python

      # turn off pump
      pump_a.duty_u16(0)
      pump_b.duty_u16(0)