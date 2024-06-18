 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson20_bmp280:
Lektion 20: Temperatur-, Luftfeuchtigkeits- und Drucksensor (BMP280)
========================================================================

In dieser Lektion lernst du, wie du den Temperatur-, Luftfeuchtigkeits- und Drucksensor BMP280 mit dem Raspberry Pi Pico W unter Verwendung von MicroPython verbindest. Du erhältst praktische Erfahrung in der Einrichtung der I2C-Kommunikation, der Konfiguration des BMP280-Sensors für die Wetterüberwachung sowie dem Abrufen von Temperatur- und Druckdaten. Am Ende dieses Tutorials kannst du Umweltdaten in Echtzeit auf deiner Konsole anzeigen.

Erforderliche Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

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

Du kannst sie auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_bmp280`
        - |link_bmp280_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verdrahtung
---------------------------

.. image:: img/Lesson_20_bmp280_bb.png
    :width: 100%


Code
---------------------------

.. note::

    * Öffnen Sie die Datei ``20_bmp280_module.py`` im Pfad ``universal-maker-sensor-kit-main/pico/Lesson_20_BMP280_Module`` oder kopieren Sie diesen Code in Thonny und klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie einfach F5, um es auszuführen. Für detaillierte Anleitungen lesen Sie bitte :ref:`open_run_code_py`.
    
    * Hier müssen Sie die Dateien ``bmp280.py`` verwenden. Bitte überprüfen Sie, ob sie auf dem Pico W hochgeladen wurden. Für eine detaillierte Anleitung siehe :ref:`add_libraries_py`.
    
    * Vergessen Sie nicht, auf den Interpreter "MicroPython (Raspberry Pi Pico)" in der unteren rechten Ecke zu klicken.

.. code-block:: python

   from machine import I2C, Pin
   import bmp280
   import time
   
   # Initialize I2C communication
   i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=100000)
   
   # Configure BMP280 sensor
   bmp = bmp280.BMP280(i2c)
   bmp.oversample(bmp280.BMP280_OS_HIGH)
   
   while True:
       # Set sensor to weather monitoring mode
       bmp.use_case(bmp280.BMP280_CASE_WEATHER)
   
       # Print temperature and pressure data
       print("tempC: {}".format(bmp.temperature))
       print("pressure: {}Pa".format(bmp.pressure))
   
       # Read data every second
       time.sleep_ms(1000)

Codeanalyse
---------------------------

#. **Importieren von Bibliotheken und Initialisieren der I2C-Kommunikation**:

   Dieser Abschnitt des Codes importiert erforderliche Bibliotheken und initialisiert die I2C-Kommunikation. Das Modul ``machine`` wird verwendet, um mit Hardwarekomponenten wie I2C und Pins zu interagieren. Die Bibliothek ``bmp280`` wird importiert, um mit dem BMP280-Sensor zu interagieren.

   Weitere Informationen zur Bibliothek ``bmp280`` finden Sie unter |link_micropython_bmp280_driver|.

   .. code-block:: python

      from machine import I2C, Pin
      import bmp280
      import time

      # Initialize I2C communication
      i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=100000)

#. **Konfigurieren des BMP280-Sensors**:

   Hier wird der BMP280-Sensor konfiguriert. Ein Objekt ``bmp`` wird erstellt, um mit dem Sensor zu interagieren. Die Oversampling-Einstellung wird für eine höhere Genauigkeit angepasst.

   .. code-block:: python

      # Configure BMP280 sensor
      bmp = bmp280.BMP280(i2c)
      bmp.oversample(bmp280.BMP280_OS_HIGH)

#. **Lesen und Anzeigen von Sensordaten in einer Schleife**:

   Der Sensor wird in einer Endlosschleife kontinuierlich gelesen. In jeder Iteration wird der Sensor auf den Wetterüberwachungsmodus eingestellt, die Temperatur und der Druck werden gelesen und gedruckt. Das ``time.sleep_ms(1000)`` stellt sicher, dass die Schleife einmal pro Sekunde ausgeführt wird.

   .. code-block:: python

      while True:
          # Set sensor to weather monitoring mode
          bmp.use_case(bmp280.BMP280_CASE_WEATHER)

          # Print temperature and pressure data
          print("tempC: {}".format(bmp.temperature))
          print("pressure: {}Pa".format(bmp.pressure))

          # Read data every second
          time.sleep_ms(1000)