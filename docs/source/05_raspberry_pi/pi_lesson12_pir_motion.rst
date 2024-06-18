.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson12_pir_motion:

Lektion 12: PIR-Bewegungssensor-Modul (HC-SR501)
===================================================

In dieser Lektion lernen Sie, wie Sie einen Bewegungssensor mit dem Raspberry Pi einrichten und verwenden. Wir führen Sie durch den Anschluss eines digitalen Bewegungssensors an GPIO-Pin 17. Sie schreiben ein Python-Skript, das den Zustand des Sensors kontinuierlich überprüft, eine Nachricht ausgibt, wenn eine Bewegung erkannt wird, und eine andere, wenn der Bereich frei ist. Dieses praxisorientierte Tutorial konzentriert sich auf praktische Fähigkeiten in der elektronischen Schaltungstechnik und Python-Programmierung und ist perfekt für Anfänger, die reale Anwendungen des Raspberry Pi in Überwachungs- und Automatisierungsprojekten erkunden möchten.

Erforderliche Komponenten
-----------------------------

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
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_12_pir_module_Pi_bb.png
    :width: 100%

Code
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice
   from time import sleep

   # Initialize the motion sensor as a digital input device on GPIO pin 17
   motion_sensor = DigitalInputDevice(17)

   # Continuously monitor the state of the motion sensor
   while True:
       if motion_sensor.is_active:
           print("Somebody here!")
       else:
           print("Monitoring...")

       # Wait for 0.5 seconds before the next sensor check
       sleep(0.5)

Code-Analyse
---------------------------

#. Bibliotheken importieren
   
   Das Skript beginnt mit dem Import der Klasse ``DigitalInputDevice`` aus der gpiozero-Bibliothek zur Ansteuerung des Bewegungssensors und der Funktion ``sleep`` aus dem time-Modul, um Verzögerungen einzuführen.

   .. code-block:: python

      from gpiozero import DigitalInputDevice
      from time import sleep

#. Bewegungssensor initialisieren
   
   Ein ``DigitalInputDevice``-Objekt namens ``motion_sensor`` wird erstellt und mit dem GPIO-Pin 17 verbunden. Dies setzt voraus, dass der Bewegungssensor an diesen GPIO-Pin des Raspberry Pi angeschlossen ist.

   .. code-block:: python

      motion_sensor = DigitalInputDevice(17)

#. Kontinuierliche Überwachungsschleife implementieren
   
   - Das Skript verwendet eine ``while True:``-Schleife zur kontinuierlichen Überwachung.
   - Innerhalb der Schleife überprüft eine ``if``-Anweisung die Eigenschaft ``is_active`` des ``motion_sensor``. 
   - Wenn ``is_active`` ``True`` ist, wird angezeigt, dass eine Bewegung erkannt wurde, und "Jemand ist hier!" wird ausgegeben.
   - Wenn ``is_active`` ``False`` ist, was bedeutet, dass keine Bewegung erkannt wurde, wird "Überwachung..." ausgegeben.
   - Die Funktion ``sleep(0.5)`` wird verwendet, um die Schleife für 0,5 Sekunden zwischen den einzelnen Sensorüberprüfungen zu pausieren, wodurch die Verarbeitungslast verringert und die Häufigkeit der Sensorabfragen gesteuert wird.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if motion_sensor.is_active:
              print("Somebody here!")
          else:
              print("Monitoring...")
          sleep(0.5)

