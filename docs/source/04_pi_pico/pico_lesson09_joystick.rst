 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson09_joystick:
Lesson 09: Joystick-Modul
==================================

In dieser Lektion lernst du, wie du mit dem Raspberry Pi Pico W ein Joystick-Modul verbindest und dessen Daten ausliest. Du wirst lernen, wie man analoge Werte der X- und Y-Achsen des Joysticks initialisiert und ausliest sowie digitale Eingaben von seinem Schalter mit MicroPython verarbeitet. Diese Lektion ist ideal für Anfänger und bietet praktische Erfahrung im Lesen und Interpretieren analoger und digitaler Eingaben auf dem Raspberry Pi Pico W.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten. 

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Du kannst sie auch separat von den unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_09_Jostick_Module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine  # Import hardware control module
   import time  # Import time module
   
   # Initialize X and Y axes of the joystick
   x_joystick = machine.ADC(27)
   y_joystick = machine.ADC(26)
   
   # Initialize joystick switch with pull-up resistor
   z_switch = machine.Pin(22, machine.Pin.IN, machine.Pin.PULL_UP)
   
   while True:  # Continuous reading loop
       x_value = x_joystick.read_u16()  # Read X-axis value
       y_value = y_joystick.read_u16()  # Read Y-axis value
       z_value = z_switch.value()  # Read switch state
   
       # Print joystick values and switch state
       print("X: ", x_value, " Y: ", y_value)
       print("SW: ", z_value)
   
       time.sleep_ms(200)  # Loop every 200 milliseconds

Codeanalyse
---------------------------

#. Bibliotheken importieren

   Die Module ``machine`` und ``time`` werden für die Hardwaresteuerung und Zeitfunktionen importiert.

   .. code-block:: python

      import machine  # Import hardware control module
      import time  # Import time module

#. Initialisiere Joystick-Achsen

   Die X- und Y-Achsen des Joysticks sind an die analogen Pins (27 bzw. 26) angeschlossen. Diese Pins werden als ADC (Analog-Digital-Umsetzer)-Objekte initialisiert.

   .. code-block:: python

      x_joystick = machine.ADC(27)
      y_joystick = machine.ADC(26)

#. Initialisiere Joystick-Schalter

   Der Joystick-Schalter ist an Pin 22 angeschlossen. Er wird als Eingang mit einem Pull-up-Widerstand konfiguriert. Wenn die Taste nicht gedrückt ist, liest sie hoch (1), und wenn sie gedrückt ist, liest sie niedrig (0).

   .. code-block:: python

      z_switch = machine.Pin(22, machine.Pin.IN, machine.Pin.PULL_UP)

#. Hauptschleife

   - Eine Endlosschleife liest kontinuierlich Werte vom Joystick.
   - Die Methode ``read_u16`` wird verwendet, um 16-Bit-Werte von den X- und Y-Achsen zu lesen.
   - Die Methode ``value()`` wird verwendet, um den Zustand des Schalters zu lesen.
   - Die Werte werden dann gedruckt, und die Schleife pausiert für 200 Millisekunden.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:  # Continuous reading loop
          x_value = x_joystick.read_u16()  # Read X-axis value
          y_value = y_joystick.read_u16()  # Read Y-axis value
          z_value = z_switch.value()  # Read switch state

          # Print joystick values and switch state
          print("X: ", x_value, " Y: ", y_value)
          print("SW: ", z_value)

          time.sleep_ms(200)  # Loop every 200 milliseconds