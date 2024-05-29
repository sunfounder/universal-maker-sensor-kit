 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson08_ir_obstacle_avoidance:

Lektion 08: IR-Hindernisvermeidungssensor-Modul
====================================================

In dieser Lektion lernen Sie, wie Sie mit einem Sensor und dem Raspberry Pi Hindernisse erkennen. Wir führen Sie durch den Anschluss eines digitalen Eingabesensors an GPIO-Pin 17. Sie lernen, wie Sie ein Python-Skript schreiben, das den Sensor kontinuierlich überwacht, um das Vorhandensein eines Hindernisses festzustellen. Das Programm gibt eine Meldung aus, die angibt, ob ein Hindernis erkannt wurde oder nicht. Dieses einfache, aber praktische Projekt ist eine hervorragende Möglichkeit, mit der GPIO-Interaktion und der Python-Programmierung zu beginnen, und eignet sich ideal für Anfänger, die sich für die Integration von Sensoren mit dem Raspberry Pi interessieren.

Benötigte Komponenten
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

Sie können sie auch einzeln über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_08_Obstacle_Avoidance_Sensor_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import InputDevice
   from time import sleep

   # Initialize the sensor as a digital input device on GPIO 17
   sensor = InputDevice(17)

   while True:
      if sensor.is_active:
         print("No obstacle detected")  # Prints when no obstacle is detected
      else:
         print("Obstacle detected")     # Prints when an obstacle is detected
      sleep(0.5)

Code-Analyse
---------------------------

#. Bibliotheken importieren

   Das Skript beginnt mit dem Import der Klasse ``InputDevice`` aus der gpiozero-Bibliothek zur Interaktion mit dem Sensor und der Funktion ``sleep`` aus dem Zeitmodul von Python, um die Ausführung zu pausieren.

   .. code-block:: python

      from gpiozero import InputDevice
      from time import sleep

#. Sensor initialisieren

   Ein ``InputDevice``-Objekt namens ``sensor`` wird erstellt und mit GPIO-Pin 17 verbunden. Diese Zeile geht davon aus, dass der Hindernissensor mit diesem spezifischen GPIO-Pin verbunden ist.

   .. code-block:: python

      sensor = InputDevice(17)

#. Implementierung der kontinuierlichen Überwachungsschleife

   - Das Skript verwendet eine ``while True:``-Schleife, um den Zustand des Sensors kontinuierlich zu überprüfen. Diese Schleife läuft unendlich, bis das Programm gestoppt wird.
   - Innerhalb der Schleife überprüft eine ``if``-Anweisung die Eigenschaft ``is_active`` des ``sensor``.
   - Wenn ``is_active`` ``True`` ist, bedeutet das, dass kein Hindernis erkannt wird, und "Kein Hindernis erkannt" wird ausgegeben.
   - Wenn ``is_active`` ``False`` ist, was bedeutet, dass ein Hindernis erkannt wird, wird "Hindernis erkannt" ausgegeben.
   - ``sleep(0.5)`` pausiert die Schleife für 0,5 Sekunden zwischen den Überprüfungen, was dazu beiträgt, die Verarbeitungslast des Skripts zu reduzieren und eine Verzögerung zwischen aufeinanderfolgenden Sensorabfragen bereitzustellen.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if sensor.is_active:
              print("No obstacle detected")
          else:
              print("Obstacle detected")
          sleep(0.5)

   .. note:: 
   
      Wenn der Sensor nicht richtig funktioniert, richten Sie den IR-Sender und -Empfänger parallel aus. Zusätzlich können Sie die Erkennungsreichweite mit dem eingebauten Potentiometer einstellen.
