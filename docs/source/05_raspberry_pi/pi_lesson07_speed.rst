.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson07_speed:

Lektion 07: Infrarot-Geschwindigkeitssensormodul
=====================================================

In dieser Lektion lernen Sie, wie Sie die Drehgeschwindigkeit mit einem Raspberry Pi und einem einfachen Sensor messen. Wir werden einen digitalen Eingabesenor an den GPIO-Pin 17 anschließen und Python verwenden, um dessen Zustandsänderungen zu überwachen. Der Schwerpunkt liegt darauf, die Umdrehungen pro Sekunde zu berechnen, indem die Sensoraktivierungen über einen bestimmten Zeitraum gezählt werden. Sie werden eine Python-Funktion schreiben, um diese Daten genau zu erfassen und in eine messbare Geschwindigkeit umzuwandeln. Dieses praktische Projekt ist eine einfache, aber praxisnahe Einführung in die Sammlung und Analyse realer Daten mit dem Raspberry Pi und ideal für Anfänger, die sich für angewandte Python-Programmierung und Hardware-Interaktion interessieren.

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
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_07_Speed_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice
   from time import time

   # Initialize the sensor
   sensor = DigitalInputDevice(17)  # Assuming the sensor is connected to GPIO17

   def calculate_rps(sample_time=1, steps_per_revolution=20):
       """
       Calculate Revolutions Per Second (RPS)

       :param sample_time: Sampling time in seconds
       :param steps_per_revolution: Number of steps in each complete revolution
       :return: Revolutions per second
       """
       start_time = time()
       end_time = start_time + sample_time
       steps = 0
       last_state = False

       while time() < end_time:
           current_state = sensor.is_active
           if current_state and not last_state:
               # Detect a transition from inactive to active state
               steps += 1
           last_state = current_state

       # Calculate RPS
       rps = steps / steps_per_revolution
       return rps

   # Example usage
   print("Measuring RPS...")

   try:
       while True:
           rps = calculate_rps()  # Default sampling for 1 second
           print(f"RPS: {rps}")
   except KeyboardInterrupt:
       # Safely exit the program when a keyboard interrupt is detected
       pass


Code-Analyse
---------------------------

#. Bibliotheken importieren

   Das Skript beginnt mit dem Import von ``DigitalInputDevice`` aus gpiozero für die Sensorinteraktion und ``time`` für das Zeitmanagement.

   .. code-block:: python

      from gpiozero import DigitalInputDevice
      from time import time

#. Sensor initialisieren

   Ein ``DigitalInputDevice``-Objekt namens ``sensor`` wird erstellt und mit GPIO-Pin 17 verbunden. Diese Konfiguration geht davon aus, dass der digitale Sensor an GPIO17 angeschlossen ist.

   .. code-block:: python

      sensor = DigitalInputDevice(17)

#. Definition der Funktion ``calculate_rps``

   - Diese Funktion berechnet die Umdrehungen pro Sekunde (RPS) eines rotierenden Objekts.
   - ``sample_time`` ist die Dauer in Sekunden, für die die Ausgabe des Sensors abgetastet wird.
   - ``steps_per_revolution`` repräsentiert die Anzahl der Sensoraktivierungen pro vollständiger Umdrehung.
   - Die Funktion verwendet eine while-Schleife, um die Anzahl der Schritte (Sensoraktivierungen) innerhalb der Abtastzeit zu zählen.
   - Sie erkennt Übergänge vom inaktiven zum aktiven Zustand und erhöht entsprechend die ``steps``-Anzahl.
   - RPS wird als Anzahl der Schritte geteilt durch ``steps_per_revolution`` berechnet.

   .. raw:: html

      <br/>

   .. code-block:: python

      def calculate_rps(sample_time=1, steps_per_revolution=20):
          """
          Calculate Revolutions Per Second (RPS)
      
          :param sample_time: Sampling time in seconds
          :param steps_per_revolution: Number of steps in each complete revolution
          :return: Revolutions per second
          """
          start_time = time()
          end_time = start_time + sample_time
          steps = 0
          last_state = False
      
          while time() < end_time:
              current_state = sensor.is_active
              if current_state and not last_state:
                  # Detect a transition from inactive to active state
                  steps += 1
              last_state = current_state
      
          # Calculate RPS
          rps = steps / steps_per_revolution
          return rps

#. Hauptschleife ausführen

   - Das Skript geht dann in eine Endlosschleife, in der ``calculate_rps`` aufgerufen wird, um die RPS zu berechnen und auszugeben.
   - Die Schleife läuft unendlich, bis eine Tastaturunterbrechung (Strg+C) erkannt wird.
   - Ein ``try-except``-Block wird verwendet, um die Unterbrechung sauber zu behandeln und einen sicheren Programmabbruch zu ermöglichen.

   .. code-block:: python

      try:
          while True:
              rps = calculate_rps()  # Default sampling for 1 second
              print(f"RPS: {rps}")
      except KeyboardInterrupt:
          pass

