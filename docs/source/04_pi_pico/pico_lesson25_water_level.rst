.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson25_water_level:

Lesson 25: Wasserstands-Sensor-Modul
=========================================

In diesem Lektion lernen Sie, wie Sie mit dem Raspberry Pi Pico W Wasserstände mithilfe eines Wasserstandsensors messen können. Sie werden verstehen, wie Sie den Sensor mit dem Board verbinden, seine analoge Ausgabe mit MicroPython lesen und diese Messwerte interpretieren, um Wasserstände zu bestimmen. Diese praktische Sitzung zielt darauf ab, Ihre Fähigkeiten in der Sensorintegration und Datenerfassung mit dem Raspberry Pi Pico W zu entwickeln.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten. 

Es ist definitiv praktisch, ein ganzes Set zu kaufen. Hier ist der Link: 

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
    *   - :ref:`cpn_water_level`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_25_Water_Level_Sensor_Module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine
   import utime
   
   # Initialize an ADC object on GPIO pin 26.
   # This is typically used for reading analog signals.
   water_level_sensor = machine.ADC(26)
   
   # Continuously read and print sensor data.
   while True:
       value = water_level_sensor.read_u16()  # Read and convert analog value to 16-bit integer
       print("AO:", value)  # Print the analog value
   
       utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read

Codeanalyse
---------------------------

#. Importieren von Bibliotheken

   Hier importieren wir die erforderlichen Bibliotheken: ``machine`` für Hardware-Interaktionen und ``utime`` für zeitbasierte Funktionen.

   .. code-block:: python

      import machine
      import utime

#. Initialisierung des Wasserstandssensors

   Es wird ein ADC-Objekt am GPIO-Pin 26 erstellt, um analoge Signale vom Wasserstandssensor zu lesen. ADC ist entscheidend für die Umwandlung der analogen Signale des Sensors in ein digitales Format, das der Mikrocontroller verarbeiten kann.

   .. code-block:: python

      # Initialize an ADC object on GPIO pin 26.
      water_level_sensor = machine.ADC(26)

#. Lesen und Drucken der Sensordaten

   Die Schleife ``while True`` ermöglicht ein kontinuierliches Lesen der Sensordaten. Die Methode ``read_u16`` wandelt das analoge Signal in eine 16-Bit-Integer um. Der Wert wird gedruckt, und die Schleife pausiert für 200 Millisekunden mit ``utime.sleep_ms(200)``, um schnelles Auslösen zu verhindern.

   .. code-block:: python

      while True:
          value = water_level_sensor.read_u16()  # Read and convert analog value to 16-bit integer
          print("AO:", value)  # Print the analog value

          utime.sleep_ms(200)  # Wait for 200 milliseconds before the next read