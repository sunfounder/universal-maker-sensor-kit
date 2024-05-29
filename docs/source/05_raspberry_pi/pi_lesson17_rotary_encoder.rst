 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson17_rotary_encoder:

Lektion 17: Drehgeber-Modul
==================================

In dieser Lektion lernen Sie, wie Sie einen Drehgeber mit einem Raspberry Pi verbinden und programmieren. Wir bieten Ihnen Schritt-für-Schritt-Anleitungen zum Schreiben eines Python-Skripts, das die Position und den Tasterzustand des Drehgebers überwacht und die Ausgaben in der Konsole anzeigt.

Erforderliche Komponenten
-----------------------------

In diesem Projekt benötigen wir die folgenden Komponenten.

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_rotary_encoder`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_17_Rotary_encoder_Pi_bb.png
    :width: 100%

Code
---------------------------

.. code-block:: python

   from gpiozero import RotaryEncoder, Button  
   from time import sleep  

   # Initialize the rotary encoder on GPIO pins 17(CLK) and 27(DT) with wrap-around at max_steps of 16
   encoder = RotaryEncoder(a=17, b=27, wrap=True, max_steps=16)
   # Initialize the rotary encoder's SW pin on GPIO pin 22
   button = Button(22)

   last_rotary_value = 0  # Variable to store the last value of rotary encoder

   try:
       while True:  # Infinite loop to continuously monitor the encoder
           current_rotary_value = encoder.steps  # Read current step count from rotary encoder

           # Check if the rotary encoder value has changed
           if last_rotary_value != current_rotary_value:
               print("Result =", current_rotary_value)  # Print the current value
               last_rotary_value = current_rotary_value  # Update the last value

           # Check if the rotary encoder is pressed
           if button.is_pressed:
               print("Button pressed!")  # Print message on button press
               button.wait_for_release()  # Wait until button is released

           sleep(0.1)  # Short delay to prevent excessive CPU usage

   except KeyboardInterrupt:
       print("Program terminated")  # Print message when program is terminated via keyboard interrupt


Code-Analyse
---------------------------

#. Bibliotheken importieren
   
   Das Skript beginnt mit dem Import der Klassen ``RotaryEncoder`` und ``Button`` aus der gpiozero-Bibliothek zur Ansteuerung des Drehgebers sowie der Funktion ``sleep`` aus dem time-Modul zur Implementierung von Verzögerungen.

   .. code-block:: python

      from gpiozero import RotaryEncoder, Button  
      from time import sleep  

#. Initialisierung des Drehgebers und Tasters
   
   - Diese Zeile initialisiert ein ``RotaryEncoder``-Objekt aus der ``gpiozero``-Bibliothek. Der Drehgeber ist mit den GPIO-Pins 17 und 27 verbunden. 
   - Der Parameter ``wrap=True`` bedeutet, dass der Wert des Drehgebers nach Erreichen von ``max_steps`` (in diesem Fall 16) zurückgesetzt wird, was ein Verhalten wie bei einem kreisförmigen Zifferblatt nachahmt.
   - Hier wird ein ``Button``-Objekt erstellt, das mit dem GPIO-Pin 22 verbunden ist. Dieses Objekt wird verwendet, um zu erkennen, wann der Drehgeber gedrückt wird.

   .. code-block:: python

      encoder = RotaryEncoder(a=17, b=27, wrap=True, max_steps=16)
      button = Button(22)

#. Implementierung der Überwachungsschleife
   
   - Eine Endlosschleife (``while True:``) wird verwendet, um den Drehgeber kontinuierlich zu überwachen.
   - Der aktuelle Wert des Drehgebers wird ausgelesen und mit seinem zuletzt aufgezeichneten Wert verglichen. Bei einer Änderung wird der neue Wert ausgegeben.
   - Das Skript überprüft, ob der Drehgeber gedrückt wird. Bei Erkennung eines Tastendrucks wird eine Nachricht ausgegeben und gewartet, bis der Drehgeber losgelassen wird.
   - Ein ``sleep(0.1)`` wird eingefügt, um eine kurze Verzögerung hinzuzufügen und eine übermäßige CPU-Auslastung zu verhindern.

   .. raw:: html

      <br/>

   .. code-block:: python

      last_rotary_value = 0

      try:
          while True:
              current_rotary_value = encoder.steps
              if last_rotary_value != current_rotary_value:
                  print("Result =", current_rotary_value)
                  last_rotary_value = current_rotary_value

              if button.is_pressed:
                  print("Button pressed!")
                  button.wait_for_release()

              sleep(0.1)

      except KeyboardInterrupt:
          print("Program terminated")