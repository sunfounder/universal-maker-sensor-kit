.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson03_flame:

Lektion 03: Flammensensor-Modul
==================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi Pico W verwenden, um mit einem Flammensensor Feuer zu erkennen. Wenn der Sensor eine Flamme erkennt, wird die integrierte LED des Raspberry Pi Pico W eingeschaltet und eine Meldung zur Feuererkennung angezeigt. Wenn kein Feuer erkannt wird, bleibt die LED aus und zeigt eine andere Meldung an. Dieses Projekt führt in die Arbeit mit externen Sensoren ein und bietet praktische Erfahrungen im Umgang mit digitalen Ein- und Ausgängen am Raspberry Pi Pico W mit MicroPython.

Erforderliche Komponenten
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

Sie können sie auch separat von den folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_03_flame_module_circuit_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 16 as an input pin to read the flame sensor state
   flame_sensor = Pin(16, Pin.IN)
   
   # Initialize the onboard LED of the Raspberry Pi Pico W
   led = Pin("LED", Pin.OUT)
   
   while True:
       if flame_sensor.value() == 0:
           led.value(1)  # Turn on the LED
           print("** Fire detected!!! **")
       else:
           led.value(0)  # Turn off the LED
           print("No Fire detected")
   
       time.sleep(0.1)  # Short delay to reduce CPU usage

Codeanalyse
---------------------------

#. Importieren der benötigten Module

   Dieser Teil des Codes importiert die erforderlichen Module. ``machine`` wird für die Interaktion mit den GPIO-Pins verwendet, und ``time`` bietet Funktionen für Verzögerungen.
   
   .. code-block:: python

      from machine import Pin
      import time

#. Initialisieren des Flammensensors und der LED

   Konfiguriert den Flammensensor und die integrierte LED. Pin 16 wird als Eingang zum Lesen des Flammensensors konfiguriert, und die integrierte LED wird als Ausgang festgelegt.
   
   .. code-block:: python

      flame_sensor = Pin(16, Pin.IN)
      led = Pin("LED", Pin.OUT)

#. Die Haupt-Schleife

   - Eine Endlosschleife überprüft den Zustand des Flammensensors. Wenn der Sensor eine Flamme erkennt (Wert 0), wird die LED eingeschaltet und eine Meldung ausgegeben. Andernfalls wird die LED ausgeschaltet und eine andere Meldung ausgegeben.
   - Eine Verzögerung von 0,1 Sekunden reduziert die CPU-Auslastung.

   .. raw :: html
      
      <br/>
   
   .. code-block:: python

      while True:
          if flame_sensor.value() == 0:
              led.value(1)
              print("** Fire detected!!! **")
          else:
              led.value(0)
              print("No Fire detected")
          time.sleep(0.1)