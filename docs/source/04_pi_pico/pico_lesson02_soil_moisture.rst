
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson02_soil_moisture:

Lektion 02: Kapazitiver Bodenfeuchtesensor
===================================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi Pico W verwenden, um die Bodenfeuchtigkeit mithilfe eines kapazitiven Sensors und eines ADC (Analog-Digital-Wandlers) zu messen. Dieses für Anfänger geeignete Projekt führt Sie in die Handhabung analoger Signale in MicroPython ein.

Erforderliche Komponenten
------------------------------

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
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_02_Capacitive_Soil_Moisture_Module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import ADC
   import time
   
   # Initialize an ADC object on GPIO pin 26.
   # This is typically used for reading analog signals.
   sensor_AO = ADC(26)
   
   # Continuously read and print sensor data.
   while True:
       value = sensor_AO.read_u16()  # Read and convert analog value to 16-bit integer
       print("AO:", value)  # Print the analog value
   
       time.sleep_ms(200)  # Wait for 200 milliseconds before the next read

Codeanalyse
---------------------------

#. Importing Libraries:

   .. code-block:: python

      from machine import ADC
      import time

#. ADC-Konfiguration:

   .. code-block:: python

      sensor_AO = ADC(26)

   Dieser Code initialisiert ein ADC-Objekt am GPIO-Pin 26. ADC wird verwendet, um analoge Signale (von analogen Sensoren) in digitale Daten umzuwandeln, die der Mikrocontroller verarbeiten kann.

#. Lesen der Sensordaten in einer Schleife:

   .. code-block:: python
    
      while True:
          value = sensor_AO.read_u16()
          print("AO:", value)
          time.sleep_ms(200)

   The ``while True`` loop runs indefinitely, constantly reading data from the sensor. The ``read_u16()`` method reads the analog value and converts it to a 16-bit unsigned integer. The ``print`` statement displays this value. The ``time.sleep_ms(200)`` causes the loop to wait for 200 milliseconds before reading the sensor value again, preventing excessive data readings and console output.