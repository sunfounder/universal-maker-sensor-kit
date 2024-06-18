.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson22_touch_sensor:

Lektion 22: Berührungssensor-Modul
==================================

In dieser Lektion lernen Sie, wie Sie einen Berührungssensor mit dem Raspberry Pi verbinden und programmieren, indem Sie Python verwenden. Der Fokus liegt darauf, den Sensor an GPIO-Pin 17 einzurichten und ein einfaches Skript zu schreiben, um Berührungs- und Loslassereignisse zu erkennen und darauf zu reagieren. Diese praktische Sitzung zielt darauf ab, die Grundlagen der Sensorintegration und der Ereignisbehandlung in Python zu vermitteln, und bietet Ihnen die Fähigkeiten, die für fortgeschrittenere, sensorbasierte Projekte erforderlich sind. Es ist ein idealer Einstiegspunkt für diejenigen, die neu im Umgang mit Elektronik und dem Raspberry Pi sind.

Erforderliche Komponenten
--------------------------

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_touch`
        - |link_touch_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_22_touch_Pi_bb.png
    :width: 100%

Code
---------------------------

.. code-block:: python

   from gpiozero import Button
   from signal import pause

   # Function called when the sensor is touched
   def touched():
       # Print a message indicating the sensor is touched
       print("Touched!")  

   # Function called when the sensor is not touched
   def not_touched():
       # Print a message indicating the sensor is not touched
       print("Not touched!")  

   # Initialize a Button object for the touch sensor
   # GPIO 17: pin connected to the sensor
   # pull_up=None: disable internal pull-up/pull-down resistors
   # active_state=True: high voltage is considered the active state
   touch_sensor = Button(17, pull_up=None, active_state=True)

   # Assign functions to sensor events
   touch_sensor.when_pressed = touched
   touch_sensor.when_released = not_touched

   pause()  # Keep the program running to detect touch events

Code-Analyse
---------------------------

#. Bibliotheken importieren
   
   Das Skript beginnt mit dem Import der Klasse ``Button`` aus der gpiozero-Bibliothek zur Ansteuerung des Berührungssensors und ``pause`` aus dem signal-Modul, um das Programm am Laufen zu halten und auf Ereignisse zu reagieren.

   .. code-block:: python

      from gpiozero import Button
      from signal import pause

#. Callback-Funktionen definieren
   
   Zwei Funktionen, ``touched`` und ``not_touched``, werden definiert, um Berührungs- und Loslassereignisse des Sensors zu verarbeiten. Jede Funktion gibt eine Nachricht aus, die den Zustand des Sensors anzeigt.

   .. code-block:: python

      def touched():
          print("Touched!")  

      def not_touched():
          print("Not touched!")  

#. Initialisierung des Berührungssensors
   
   Ein ``Button``-Objekt namens ``touch_sensor`` wird für den Berührungssensor an GPIO-Pin 17 erstellt. Der Parameter ``pull_up`` ist auf ``None`` gesetzt, um interne Pull-up/Pull-down-Widerstände zu deaktivieren, und ``active_state`` ist auf ``True`` gesetzt, um hohe Spannung als aktiven Zustand zu betrachten.

   .. code-block:: python

      touch_sensor = Button(17, pull_up=None, active_state=True)

#. Funktionen den Sensorereignissen zuweisen
   
   Das Ereignis ``when_pressed`` des ``touch_sensor`` wird mit der Funktion ``touched`` verknüpft, und das Ereignis ``when_released`` wird mit der Funktion ``not_touched`` verknüpft. Diese Konfiguration ermöglicht es dem Skript, auf Berührungs- und Loslassereignisse des Sensors zu reagieren.

   .. code-block:: python

      touch_sensor.when_pressed = touched
      touch_sensor.when_released = not_touched

#. Das Programm am Laufen halten
   
   Die Funktion ``pause()`` wird aufgerufen, um das Programm unendlich laufen zu lassen. Dies ist notwendig, um Berührungssensorereignisse kontinuierlich zu überwachen und darauf zu reagieren.

   .. code-block:: python

      pause()