 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson30_relay_module:

Lesson 30: Relaismodul
==================================

In dieser Lektion lernen Sie, wie Sie ein Relaismodul mit einem Raspberry Pi steuern. Sie lernen, wie Sie ein einfaches Python-Skript schreiben, um das Relais in Intervallen von einer Sekunde ein- und auszuschalten. Dieses Projekt ist eine praktische Einführung in die Verwendung von GPIO-Pins zur Steuerung externer Geräte und vermittelt ein grundlegendes Verständnis dafür, wie Relais in elektronischen Schaltungen funktionieren. Es ist eine einfache und informative Übung, die sich gut für Anfänger eignet, die mit dem Raspberry Pi und der Hardwaresteuerung beginnen.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist auf jeden Fall praktisch, ein ganzes Kit zu kaufen. Hier ist der Link: 

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verdrahtung
---------------------------

.. image:: img/Lesson_30_Relay_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import OutputDevice
   from time import sleep

   # Replace with your GPIO pin number
   relay_pin = 17  # Example using GPIO17

   # Initialize relay object
   relay = OutputDevice(relay_pin)

   try:
      while True:
         # Turn on the relay
         relay.on()
         sleep(1)  # Relay remains on for 1 second

         # Turn off the relay
         relay.off()
         sleep(1)  # Relay remains off for 1 second

   except KeyboardInterrupt:
      # Capture Ctrl+C and safely close the program
      relay.off()
      print("Program interrupted by user")


Code-Analyse
---------------------------

#. Importieren von Bibliotheken
   
   Importieren Sie die Bibliothek ``gpiozero`` zur Steuerung der GPIO-Pins und die Bibliothek ``time`` für Zeitverzögerungen.

   .. code-block:: python

      from gpiozero import OutputDevice
      from time import sleep

#. Initialisieren des Relais
   
   Definieren Sie den GPIO-Pin, der mit dem Relais verbunden ist, und initialisieren Sie ein ``OutputDevice``-Objekt mit diesem Pin.

   .. code-block:: python

      relay_pin = 17  # Example using GPIO17
      relay = OutputDevice(relay_pin)

#. Steuerung des Relais in einer Schleife
   
   Die ``while True:``-Schleife schaltet das Relais kontinuierlich ein und aus. ``relay.on()`` und ``relay.off()`` werden zur Steuerung des Relais verwendet, und ``sleep(1)`` erzeugt eine Verzögerung von einer Sekunde zwischen jedem Zustand.

   .. code-block:: python

      try:
          while True:
              relay.on()
              sleep(1)  # Relay remains on for 1 second
              relay.off()
              sleep(1)  # Relay remains off for 1 second

#. Ausnahmebehandlung
   
   Der ``except``-Block fängt eine ``KeyboardInterrupt``-Ausnahme (Ctrl+C) ab. Er stellt sicher, dass das Relais ausgeschaltet wird und das Programm sicher beendet wird.

   .. code-block:: python

      except KeyboardInterrupt:
          relay.off()
          print("Program interrupted by user")