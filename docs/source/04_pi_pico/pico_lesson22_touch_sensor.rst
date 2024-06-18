 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson22_touch_sensor:
Lektion 22: Touch-Sensor-Modul
==================================

In dieser Lektion lernen Sie, wie Sie einen Touch-Sensor mit dem Raspberry Pi Pico W verbinden, um eine LED an Bord zu steuern. Mit einfachem Python-Code konfigurieren Sie den Touch-Sensor als Eingabegerät. Wenn der Sensor eine Berührung erkennt, sendet er ein Signal, um die LED einzuschalten und signalisiert so visuell, dass eine Berührung erkannt wurde. Im Gegensatz dazu bleibt die LED aus, wenn keine Berührung erfolgt.

Benötigte Komponenten
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

Sie können sie auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_touch`
        - |link_touch_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_22_touch_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Set GPIO 16 as an input pin to read the touch sensor state
   touch_sensor = Pin(16, Pin.IN)
   
   # Initialize the onboard LED of the Raspberry Pi Pico W
   led = Pin("LED", Pin.OUT)
   
   while True:
       if touch_sensor.value() == 1:
           led.value(1)  # Turn on the LED
           print("Touch detected!")
       else:
           led.value(0)  # Turn off the LED
           print("No touch detected")
   
       time.sleep(0.1)  # Short delay to reduce CPU usage


Code-Analyse
---------------------------

#. **Einrichten der Pins**:

   Hier importieren wir die erforderlichen Bibliotheken und richten die GPIO-Pins ein. Der Touch-Sensor ist mit GPIO 16 als Eingang verbunden, und die eingebaute LED ist als Ausgang konfiguriert.

   .. code-block:: python

      from machine import Pin
      import time

      touch_sensor = Pin(16, Pin.IN)
      led = Pin("LED", Pin.OUT)

#. **Hauptschleife und Berührungserkennung**:

   In einer Endlosschleife überprüft der Code ständig den Zustand des Touch-Sensors. Wenn eine Berührung erkannt wird (Wert gleich 1), wird die LED eingeschaltet und eine Nachricht wird gedruckt. Andernfalls bleibt die LED aus, und eine andere Nachricht wird gedruckt. Eine kurze Verzögerung wird hinzugefügt, um die CPU-Nutzung zu reduzieren.

   .. code-block:: python

      while True:
          if touch_sensor.value() == 1:
              led.value(1)  # Turn on the LED
              print("Touch detected!")
          else:
              led.value(0)  # Turn off the LED
              print("No touch detected")

          time.sleep(0.1)  # Short delay to reduce CPU usage