 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson10_pcf8591:

Lektion 10: PCF8591 ADC DAC Converter Modul
===============================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi Pico W mit dem PCF8591 ADC DAC Converter Modul unter Verwendung von MicroPython verbinden. Sie werden eine I2C-Verbindung herstellen, das PCF8591-Modul initialisieren und analoge Werte von seinen Kanälen lesen. Diese praktische Sitzung vertieft Ihr Verständnis für Analog-Digital-Wandlung und I2C-Kommunikation auf dem Raspberry Pi Pico W. Der Potentiometer des Moduls ist über Jumperkappen mit AIN0 verbunden, und die D2-LED auf dem Modul ist mit AOUT verbunden, sodass Sie sehen können, dass sich die Helligkeit der D2-LED ändert, wenn Sie den Potentiometer drehen.

Benötigte Komponenten
--------------------------

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

Sie können sie auch separat von den unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_10_PCF8591_Module_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import I2C, Pin
   import time
   from PCF8591 import PCF8591
   
   # Setup I2C connection on pins 20 (SDA) and 21 (SCL)
   i2c = I2C(0, sda=Pin(20), scl=Pin(21))
   
   # Initialize the PCF8591 module at address 0x48
   pcf8591 = PCF8591(0x48, i2c)  # Adjust the address if needed
   
   # Check if the PCF8591 module is connected
   if pcf8591.begin():
       print("PCF8591 found")
   
   # Main loop to read analog values
   while True:
       # Read and print the analog value from channel AIN0
       AIN0 = pcf8591.analog_read(PCF8591.AIN0)
       print("AIN0 ", AIN0)  # PCF8591.CHANNEL_0 can also be used
       # Additional channels can be read by uncommenting the following lines
       # print("AIN1 ", pcf8591.analog_read(PCF8591.AIN1))
       # print("AIN2 ", pcf8591.analog_read(PCF8591.AIN2))
       # print("AIN3 ", pcf8591.analog_read(PCF8591.AIN3))
   
       # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
       pcf8591.analog_write(AIN0)
   
       # Wait for 0.2 seconds before the next read
       time.sleep(0.2)


Code-Analyse
---------------------------

#. Einbinden von Bibliotheken und Einrichten von I2C

   - Das ``machine``-Modul wird importiert, um I2C-Kommunikation und die Klasse ``Pin`` zu verwenden.
   - Das ``time``-Modul wird importiert, um Verzögerungen im Programm hinzuzufügen.
   - Die ``PCF8591``-Bibliothek wird importiert, um eine einfache Interaktion mit dem PCF8591-Modul zu ermöglichen. Weitere Informationen zur ``PCF8591``-Bibliothek finden Sie unter |link_PCF8591_micropython_library|.

   .. raw:: html

      <br/>

   .. code-block:: python

      from machine import I2C, Pin
      import time
      from PCF8591 import PCF8591

#. Initialisierung der I2C-Verbindung

   Die I2C-Kommunikation wird unter Verwendung der SDA (Serial Data) und SCL (Serial Clock) Pins initialisiert. Der Raspberry Pi Pico W verwendet dafür GPIO 20 und 21.

   .. code-block:: python

      i2c = I2C(0, sda=Pin(20), scl=Pin(21))

#. Initialisierung des PCF8591-Moduls

   Das PCF8591-Modul wird mit seiner I2C-Adresse (0x48) initialisiert. Diese Adresse muss je nach Konfiguration des Moduls angepasst werden.

   .. code-block:: python

      pcf8591 = PCF8591(0x48, i2c)  # Adjust the address if needed

#. Überprüfung der Verbindung

   Das Programm überprüft, ob das PCF8591-Modul korrekt verbunden ist.

   .. code-block:: python

      if pcf8591.begin():
          print("PCF8591 found")

#. Hauptschleife zum Lesen analoger Werte

   - Das Programm tritt in eine Endlosschleife ein und liest kontinuierlich den analogen Wert vom Kanal AIN0.
   - Die Funktion ``analog_read`` wird verwendet, um den Wert von einem angegebenen Kanal zu lesen.
   - Die Funktion ``analog_write`` wird verwendet, um den Wert nach AOUT zu schreiben.
   - Jumperkappen verbinden den Potentiometer des Moduls mit AIN0, und die LED D2 ist mit AOUT verbunden. Die Helligkeit der LED ändert sich daher, wenn der Potentiometer gedreht wird. Bitte beachten Sie das PCF8591-Modul :ref:`Schaltbild <cpn_pcf8591_sch>` für Details.
   - Eine Verzögerung von 0,2 Sekunden wird zwischen den Lesevorgängen hinzugefügt, um die Ausgabe zu stabilisieren.

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          # Read and print the analog value from channel AIN0
          AIN0 = pcf8591.analog_read(PCF8591.AIN0)
          print("AIN0 ", AIN0)  # PCF8591.CHANNEL_0 can also be used
          # Additional channels can be read by uncommenting the following lines
          # print("AIN1 ", pcf8591.analog_read(PCF8591.AIN1))
          # print("AIN2 ", pcf8591.analog_read(PCF8591.AIN2))
          # print("AIN3 ", pcf8591.analog_read(PCF8591.AIN3))
      
          # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
          pcf8591.analog_write(AIN0)
      
          # Wait for 0.2 seconds before the next read
          time.sleep(0.2)
