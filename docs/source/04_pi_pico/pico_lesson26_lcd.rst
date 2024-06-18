.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson26_lcd:
Lesson 26: I2C LCD 1602
==================================

In dieser Lektion lernen Sie, wie Sie ein I2C LCD 1602 Display mit einem Raspberry Pi Pico W verbinden. Sie erfahren, wie Sie die I2C-Kommunikation einrichten, Nachrichten auf dem LCD mithilfe von MicroPython anzeigen und löschen.


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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. note:: 
   Um sicherzustellen, dass das LCD-Modul ordnungsgemäß funktioniert, versorgen Sie es bitte mit dem VBUS-Pin am Pico.

.. image:: img/Lesson_26_LCD1602_Module_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import I2C, Pin
   from lcd1602 import LCD
   import time
   
   # Initialize I2C communication;
   # Set SDA to pin 20, SCL to pin 21, and frequency to 400kHz
   i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)
   
   # Create an LCD object for interfacing with the LCD1602 display
   lcd = LCD(i2c)
   
   # Display the first message on the LCD
   # Use '\n' to create a new line.
   string = "SunFounder\n    LCD Tutorial"
   lcd.message(string)
   # Wait for 2 seconds
   time.sleep(2)
   # Clear the display
   lcd.clear()
   
   # Display the second message on the LCD
   string = "Hello\n  World!"
   lcd.message(string)
   # Wait for 5 seconds
   time.sleep(5)
   # Clear the display before exiting
   lcd.clear()

Code-Analyse
---------------------------

#. Einrichten der I2C-Kommunikation

   Das ``machine``-Modul wird verwendet, um die I2C-Kommunikation einzurichten. Dabei werden die SDA (Serial Data) und SCL (Serial Clock) Pins definiert (Pin 20 und 21) sowie die I2C-Frequenz (400 kHz).

   .. code-block:: python
      
      from machine import I2C, Pin
      i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)

#. Initialisierung des LCD-Displays

   Die Klasse ``LCD`` aus dem Modul ``lcd1602`` wird instanziiert. Diese Klasse übernimmt die Kommunikation mit dem LCD-Display über I2C. Ein ``LCD``-Objekt wird mithilfe des ``i2c``-Objekts erstellt.

   Für weitere Anwendungen der ``lcd1602``-Bibliothek siehe bitte ``lcd1602.py``.

   .. code-block:: python
      
      from lcd1602 import LCD
      lcd = LCD(i2c)

#. Anzeigen von Nachrichten auf dem LCD

   Die Methode ``message`` des ``LCD``-Objekts wird verwendet, um Text auf dem Bildschirm anzuzeigen. Das ``\n``-Zeichen erstellt eine neue Zeile auf dem LCD. Die Funktion ``time.sleep()`` pausiert die Ausführung für eine bestimmte Anzahl von Sekunden.

   .. code-block:: python
      
      string = "SunFounder\n    LCD Tutorial"
      lcd.message(string)
      time.sleep(2)
      lcd.clear()

#. Löschen des Displays

   Die Methode ``clear`` des ``LCD``-Objekts wird aufgerufen, um den Text vom Display zu löschen.

   .. code-block:: python
      
      lcd.clear()

#. Anzeigen einer zweiten Nachricht

   Eine neue Nachricht wird angezeigt, gefolgt von einer Verzögerung und anschließendem Löschen des Bildschirms erneut.

   .. code-block:: python
      
      string = "Hello\n  World!"
      lcd.message(string)
      time.sleep(5)
      lcd.clear()