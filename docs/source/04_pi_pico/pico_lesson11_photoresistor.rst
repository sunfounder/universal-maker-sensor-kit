
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson11_photoresistor:
Lektion 11: Fotowiderstand-Modul
=========================================

In dieser Lektion lernen Sie, wie Sie ein Fotowiderstand-Modul mit dem Raspberry Pi Pico W verbinden, um die Lichtintensität zu messen. Durch die Verbindung des Fotowiderstands mit dem Analogeingang können Sie verschiedene Analogwerte lesen, die verschiedenen Lichtstufen entsprechen. Dieses Projekt eignet sich ideal für Anfänger und bietet praktische Erfahrungen in der Verwendung von Analogeingängen auf dem Raspberry Pi Pico W mit MicroPython.

Erforderliche Komponenten
----------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_11_photoresistor_module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine  # Hardware control library
   import time  # Time control library
   
   photoresistor = machine.ADC(26)  # Initialize ADC on pin 26
   
   while True:
       value = photoresistor.read_u16()  # Read analog value
       print(value)  # Print the value
   
       time.sleep_ms(200)  # Delay of 200 ms between reads


Codeanalyse
---------------------------

1. **Importieren der Bibliotheken**:

   Der Code beginnt mit dem Importieren der benötigten Bibliotheken. Die ``machine``-Bibliothek wird zur Steuerung von Hardwarekomponenten verwendet, und die ``time``-Bibliothek wird für die Verwaltung zeitbezogener Aufgaben wie Verzögerungen verwendet.

   .. code-block:: python

      import machine  # Hardware control library
      import time  # Time control library

2. **Initialisierung des Fotowiderstands**:

   Hier initialisieren wir den Fotowiderstand. Wir verwenden die Klasse ``machine.ADC``, um ein ADC-Objekt am Pin 26 zu erstellen, an dem der Fotowiderstand angeschlossen ist. Das ADC-Objekt wird verwendet, um die analogen Werte vom Fotowiderstand zu lesen.

   .. code-block:: python

      photoresistor = machine.ADC(26)  # Initialize ADC on pin 26

3. **Lesen vom Fotowiderstand**:

   In dieser Schleife liest der Code kontinuierlich den analogen Wert vom Fotowiderstand mit ``photoresistor.read_u16()``. Diese Methode liest den Wert als 16-Bit-Unsigned-Integer. Der Wert wird dann in der Konsole ausgegeben.

   .. code-block:: python

      while True:
          value = photoresistor.read_u16()  # Read analog value
          print(value)  # Print the value

4. **Hinzufügen einer Verzögerung**:

   Um zu verhindern, dass der Code zu schnell ausgeführt wird und die Konsole mit Daten überflutet, wird nach jeder Messung eine Verzögerung von 200 Millisekunden mit ``time.sleep_ms(200)`` eingefügt.

   .. code-block:: python

      time.sleep_ms(200)  # Delay of 200 ms between reads