.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson24_vibration_sensor:

Lektion 24: Vibrationssensor-Modul (SW-420)
==============================================

In dieser Lektion lernen Sie, wie Sie einen Vibrationssensor mit dem Raspberry Pi verwenden. Wir helfen Ihnen, den Sensor an GPIO-Pin 17 anzuschließen und führen Sie durch das Schreiben eines einfachen Python-Skripts. Dieses Skript überwacht den Sensor und gibt eine Nachricht aus, wann immer eine Vibration erkannt wird. Diese Lektion zielt darauf ab, Anfängern eine praktische Erfahrung im Anschluss eines einfachen Sensors an den Raspberry Pi und im Schreiben eines unkomplizierten Skripts zur Interaktion mit diesem zu bieten.

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
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_24_vibration_sensor_Pi_bb.png
    :width: 100%

Code
---------------------------

.. code-block:: python

   from gpiozero import InputDevice
   import time
   
   # Connect the digital output of the vibration sensor to GPIO17 on the Raspberry Pi
   vibration_sensor = InputDevice(17)
   
   # Continuous loop to read from the sensor
   while True:
       # Check if the sensor is active (no vibration detected)
       if vibration_sensor.is_active:
           print("Vibration detected!")
       else:
           # When the sensor is inactive (vibration detected)
           print("...")
       # Wait for 1 second before reading the sensor again
       time.sleep(1)

Code-Analyse
---------------------------

#. **Bibliotheken importieren**

   Zuerst importieren wir die notwendigen Bibliotheken: ``gpiozero`` zur Interaktion mit den GPIO-Pins und ``time`` zur Handhabung zeitbezogener Funktionen.

   .. code-block:: python

      from gpiozero import InputDevice
      import time

#. **Einrichten des Vibrationssensors**

   Wir initialisieren den Vibrationssensor, indem wir eine Instanz von ``InputDevice`` aus der ``gpiozero``-Bibliothek erstellen. Der Vibrationssensor ist mit GPIO-Pin 17 am Raspberry Pi verbunden.

   .. code-block:: python

      vibration_sensor = InputDevice(17)

#. **Kontinuierliche Überwachungsschleife**

   Eine ``while True``-Schleife wird für die kontinuierliche Überwachung verwendet. Diese Schleife läuft unendlich weiter, bis das Programm manuell gestoppt wird.

   .. code-block:: python

      while True:

#. **Überprüfung des Sensorstatus und Ausgabe**

   - Innerhalb der Schleife verwenden wir eine ``if``-Anweisung, um den Status des Vibrationssensors zu überprüfen. Wenn ``vibration_sensor.is_active`` ``True`` ist, bedeutet dies, dass keine Vibration erkannt wurde, und "Vibration erkannt!" wird ausgegeben.
   - Wenn ``vibration_sensor.is_active`` ``False`` ist, was auf eine Vibration hinweist, wird stattdessen "..." ausgegeben.
   - Diese Unterscheidung ist entscheidend, um zu verstehen, wie die Ausgabe des Sensors im Code interpretiert wird.

   .. code-block:: python

          if vibration_sensor.is_active:
              print("Vibration detected!")
          else:
              print("...")

#. **Verzögerung**

   Schließlich fügt ``time.sleep(1)`` eine Verzögerung von 1 Sekunde zwischen jeder Iteration der Schleife hinzu. Diese Verzögerung ist entscheidend, um zu verhindern, dass das Programm die CPU überlastet, und um die Ausgabe lesbar zu machen.

   .. code-block:: python

          time.sleep(1)

          