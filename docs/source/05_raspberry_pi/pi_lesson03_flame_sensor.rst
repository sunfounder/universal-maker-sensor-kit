.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson03_flame:

Lektion 03: Flammensensormodul
==================================

In dieser Lektion lernen Sie, wie Sie einen Flammensensor mit dem Raspberry Pi zur Feuermeldung verwenden. Wir zeigen Ihnen, wie Sie den Flammensensor an GPIO17 anschließen und ein Python-Skript schreiben, um dessen Ausgabe zu lesen. Sie lernen, zu erkennen, wann der Sensor eine Flamme detektiert, was durch eine Änderung des Sensorzustands angezeigt wird. Dieses praktische Projekt führt Sie in die Grundlagen der Sensoranbindung und Python-Programmierung auf dem Raspberry Pi ein und ist für Anfänger geeignet, die sich für sicherheitsrelevante Projekte interessieren.

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
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_03_flame_module_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import InputDevice
   import time

   # Connect the digital output of the flame sensor to GPIO17 on the Raspberry Pi
   flame_sensor = InputDevice(17)

   # Continuous loop to read from the sensor
   while True:
       # Check if the sensor is active (no flame detected)
       if flame_sensor.is_active:
           print("No flame detected.")
       else:
           # When the sensor is inactive (flame detected)
           print("Flame detected!")
       # Wait for 1 second before reading the sensor again
       time.sleep(1)


Code-Analyse
---------------------------

#. Bibliotheken importieren
   
   Das Skript beginnt mit dem Import der notwendigen Klassen aus der gpiozero-Bibliothek und dem time-Modul aus der Python-Standardbibliothek.

   .. code-block:: python

      from gpiozero import InputDevice
      import time

#. Initialisierung des Flammensensors
   
   Ein ``InputDevice``-Objekt namens ``flame_sensor`` wird erstellt, das den an GPIO-Pin 17 des Raspberry Pi angeschlossenen Flammensensor repräsentiert. Diese Konfiguration geht davon aus, dass der digitale Ausgang des Flammensensors an GPIO17 angeschlossen ist.

   .. code-block:: python

      flame_sensor = InputDevice(17)

#. Kontinuierliche Ausleseschleife
   
   - Das Skript verwendet eine ``while True:``-Schleife, um die Daten des Sensors kontinuierlich auszulesen. Diese Schleife läuft unendlich.
   - Innerhalb der Schleife überprüft eine ``if``-Anweisung den Zustand des Flammensensors mit der Eigenschaft ``is_active``.
   - Wenn ``flame_sensor.is_active`` ``True`` ist, zeigt dies an, dass keine Flamme erkannt wurde, und es wird "Keine Flamme erkannt." ausgegeben.
   - Wenn ``flame_sensor.is_active`` ``False`` ist, zeigt dies an, dass eine Flamme erkannt wurde, und es wird "Flamme erkannt!" ausgegeben.
   - Der Befehl ``time.sleep(1)`` pausiert die Schleife für 1 Sekunde zwischen jeder Sensorablesung, um zu verhindern, dass das Skript die CPU überlastet.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if flame_sensor.is_active:
              print("No flame detected.")
          else:
              print("Flame detected!")
          time.sleep(1)