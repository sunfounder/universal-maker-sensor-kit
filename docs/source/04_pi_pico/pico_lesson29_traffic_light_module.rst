 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson29_traffic_light_module:

Lektion 29: Verkehrsampelmodul
==================================

In dieser Lektion lernst du, ein Verkehrsampelsystem mit dem Raspberry Pi Pico W zu erstellen. Du programmierst den Pico W, um drei LEDs - rot, gelb und grün - zu steuern, und simulierst damit eine echte Verkehrsampel. Dieses Projekt bietet eine praktische Einführung in die Verwendung von Pulsweitenmodulation (PWM) zur Steuerung der Helligkeit von LEDs und grundlegende Steuerstrukturen in MicroPython. Es ist ideal für Anfänger, die die digitale Signalverarbeitung erkunden und Selbstvertrauen beim Codieren auf der Plattform des Raspberry Pi Pico W gewinnen möchten.

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

Sie können sie auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_traffic`
        - |link_traffic_light_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verdrahtung
---------------------------

.. image:: img/Lesson_29_Traffic_Light_Module_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   import time
   
   # Initialize pins for LEDs
   red = PWM(Pin(26), freq=1000)  #  red LED
   yellow = PWM(Pin(27), freq=1000)  #  yellow LED
   green = PWM(Pin(28), freq=1000)  # green LED
   
   
   # Function to set the brightness of an LED (0-100%)
   def set_brightness(led, brightness):
       if brightness < 0 or brightness > 100:
           raise ValueError("Brightness should be between 0 and 100")
       led.duty_u16(int(brightness / 100 * 65535))
   
   
   try:
       # Example sequence
       while True:
           
           # Green light for 5 seconds
           set_brightness(green, 100)
           time.sleep(5)
           set_brightness(green, 0)
   
           # Blink Yellow light
           set_brightness(yellow, 100)
           time.sleep(0.5)
           set_brightness(yellow, 0)
           time.sleep(0.5)
           set_brightness(yellow, 100)
           time.sleep(0.5)
           set_brightness(yellow, 0)
           time.sleep(0.5)
           set_brightness(yellow, 100)
           time.sleep(0.5)
           set_brightness(yellow, 0)
           time.sleep(0.5)
           
           # Red light for 5 seconds
           set_brightness(red, 100)
           time.sleep(5)
           set_brightness(red, 0)
           
   except KeyboardInterrupt:
       # Turn off RGB LED on interrupt
       set_brightness(red, 0)
       set_brightness(yellow, 0)
       set_brightness(green, 0)


Codeanalyse
---------------------------

#. Bibliotheken importieren

   Die Bibliothek ``machine`` wird zur Steuerung von Hardwarekomponenten verwendet, und ``time`` dient zur Erzeugung von Verzögerungen.

   .. code-block:: python

      from machine import Pin, PWM
      import time

#. Initialisierung der LED-Pins

   Hier initialisieren wir die Pins, die mit den LEDs verbunden sind. PWM wird verwendet, um die Helligkeit der LEDs zu steuern.

   .. code-block:: python

      red = PWM(Pin(26), freq=1000)  #  red LED
      yellow = PWM(Pin(27), freq=1000)  #  yellow LED
      green = PWM(Pin(28), freq=1000)  # green LED

#. Definition der Funktion zur Einstellung der Helligkeit

   .. note::
      Da die Pins des Raspberry Pi Pico nur eine maximale Spannung von 3,3V ausgeben können, erscheint die grüne LED gedimmt.

   Diese Funktion setzt die Helligkeit der LEDs. Sie nimmt zwei Parameter an: die LED und den gewünschten Helligkeitswert (0-100%). Die Methode ``duty_u16`` wird verwendet, um den PWM-Tastgrad festzulegen.

   .. code-block:: python

      def set_brightness(led, brightness):
          if brightness < 0 or brightness > 100:
              raise ValueError("Brightness should be between 0 and 100")
          led.duty_u16(int(brightness / 100 * 65535))

#. Hauptschleife und Verkehrsampelabfolge

   Die Schleife ``while True`` lässt den Code kontinuierlich laufen. Sie steuert die Abfolge der Verkehrsampel: grün, gelb (blinkend) und rot.

   .. code-block:: python

      try:
          while True:
              # Green light for 5 seconds
              set_brightness(green, 100)
              time.sleep(5)
              set_brightness(green, 0)
              ...

#. Behandlung des Tastaturabbruchs

   Der Block ``except KeyboardInterrupt`` wird verwendet, um eine manuelle Unterbrechung (wie Ctrl+C) zu behandeln. Er schaltet alle LEDs aus, wenn das Skript unterbrochen wird.

   .. code-block:: python

      except KeyboardInterrupt:
          set_brightness(red, 0)
          set_brightness(yellow, 0)
          set_brightness(green, 0)