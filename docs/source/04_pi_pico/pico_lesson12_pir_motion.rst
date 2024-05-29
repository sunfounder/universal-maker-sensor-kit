 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson12_pir_motion:

Lektion 12: PIR-Bewegungssensor (HC-SR501)
==============================================

In dieser Lektion lernen Sie, wie Sie einen PIR-Bewegungssensor mit dem Raspberry Pi Pico W verbinden. Sie erfahren, wie Sie den Sensor für die Bewegungserkennung konfigurieren und grundlegenden MicroPython-Code verwenden, um auf Bewegungen zu reagieren. Durch die Überwachung des PIR-Sensors erhalten Sie Erfahrung im Umgang mit digitalen Eingängen und können eine einfache Sicherheitsmaßnahme oder Automatisierungsauslöser erstellen.

Benötigte Komponenten
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

Sie können sie auch einzeln über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_pir_motion`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_12_pir_module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Initialize PIR sensor connected to pin 16 as input
   pir_sensor = Pin(16, Pin.IN)
   
   while True:
       # Check the PIR sensor value
       if pir_sensor.value() == 0:  
           print("Monitoring...")  # No motion detected
       else:
           print("Somebody here!")  # Motion detected
   
       time.sleep(0.1)  # Short delay of 0.1 seconds to reduce CPU usage

Code Analysis
---------------------------

#. Importieren von Modulen

   Das ``machine``-Modul wird importiert, um die ``Pin``-Klasse für die Steuerung der GPIO-Pins zu verwenden. Das ``time``-Modul wird importiert, um Verzögerungen in der Schleife zu erzeugen.

   .. code-block:: python

      from machine import Pin
      import time

#. Initialisierung des PIR-Sensors

   Der PIR-Sensor ist mit GPIO-Pin 16 des Raspberry Pi Pico W verbunden. Er wird als Eingabegerät festgelegt, da er Daten an den Mikrocontroller sendet.

   .. code-block:: python

      # Initialize PIR sensor connected to pin 16 as input
      pir_sensor = Pin(16, Pin.IN)

#. Hauptschleife

   Die ``while True``-Schleife lässt den Code kontinuierlich laufen. Innerhalb dieser Schleife wird der Wert des PIR-Sensors überprüft. Wenn der Wert ``0`` ist, bedeutet dies, dass keine Bewegung erkannt wurde. Andernfalls wurde eine Bewegung erkannt. Eine Verzögerung von 0,1 Sekunden wird hinzugefügt, um die CPU-Auslastung zu reduzieren und zu verhindern, dass der Code zu schnell ausgeführt wird.

   .. code-block:: python

      while True:
          # Check the PIR sensor value
          if pir_sensor.value() == 0:  
              print("Monitoring...")  # No motion detected
          else:
              print("Somebody here!")  # Motion detected
          time.sleep(0.1)  # Short delay of 0.1 seconds to reduce CPU usage