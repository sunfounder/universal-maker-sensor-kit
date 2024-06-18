 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson19_dht11:
Lektion 19: Temperatur- und Feuchtigkeitssensor-Modul (DHT11)
====================================================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi Pico W mit einem DHT11-Temperatur- und Feuchtigkeitssensor verbinden. Sie werden die genaue Messung der Umgebungsbedingungen durch Aufzeichnung von Temperatur- und Feuchtigkeitsdaten erkunden. Dieses Tutorial bietet praktische Anleitungen zur Verwendung digitaler Sensoren mit dem Raspberry Pi Pico W, zum Programmieren mit MicroPython und zur Verwaltung der Echtzeitdatenverarbeitung.

Erforderliche Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten:

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_19_dht11_module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import dht
   import machine
   import time
   
   # Initialize DHT11 sensor on GPIO 16
   d = dht.DHT11(machine.Pin(16))
   
   # Continuously read and print temperature and humidity
   while True: 
       d.measure()    
       print("Temperature:" ,d.temperature())  # Print temperature
       print("Humidity:" ,d.humidity())  # Print humidity
       time.sleep_ms(1000)  # Read every second

Code-Analyse
---------------------------

#. Bibliotheken importieren:

   Der Code beginnt mit dem Importieren der erforderlichen Bibliotheken. ``dht`` ist für den DHT11-Sensor, ``machine`` für die Interaktion mit der Hardware und ``time`` für Verzögerungen in der Schleife zuständig.

   .. code-block:: python
      
      import dht
      import machine
      import time

#. Initialisierung des DHT11-Sensors:

   Der DHT11-Sensor wird initialisiert, indem der verbundene GPIO-Pin angegeben wird. Hier ist er mit GPIO 16 am Raspberry Pi Pico W verbunden. Dies geschieht mithilfe der Funktion ``machine.Pin``.

   .. code-block:: python

      d = dht.DHT11(machine.Pin(16))

#. Datenkontinuierlich lesen und ausgeben:

   Die Schleife ``while True`` ermöglicht es dem Programm, kontinuierlich Temperatur- und Luftfeuchtigkeitsdaten zu lesen. Innerhalb der Schleife wird ``d.temperature()`` aufgerufen, um eine neue Messung durchzuführen. ``d.measure()`` und ``d.humidity()`` werden verwendet, um die Temperatur- und Luftfeuchtigkeitsdaten abzurufen. Diese Werte werden dann ausgegeben. Die Schleife pausiert für eine Sekunde (``1000`` milliseconds) mithilfe von ``time.sleep_ms(1000)``, um sicherzustellen, dass die Daten jede Sekunde gelesen und ausgegeben werden.

   .. code-block:: python

      while True: 
          d.measure()    
          print("Temperature:" ,d.temperature())  # Print temperature
          print("Humidity:" ,d.humidity())  # Print humidity
          time.sleep_ms(1000)  # Read every second