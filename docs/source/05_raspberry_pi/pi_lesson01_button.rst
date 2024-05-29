 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson01_button:

Lektion 01: Tastenmodul
==================================

In dieser Lektion lernen Sie die Grundlagen der Verwendung eines Tasters mit dem Raspberry Pi. Wir zeigen Ihnen, wie Sie einen Taster an GPIO-Pin 17 anschließen und ein einfaches Python-Skript schreiben, um dessen Zustand zu überwachen. Sie lernen, wie Sie den Raspberry Pi so programmieren, dass er erkennt, wenn der Taster gedrückt und losgelassen wird, und mit entsprechenden Meldungen reagiert. Dieses Einführungsprojekt ist eine ausgezeichnete Möglichkeit, sich mit der GPIO-Interaktion und grundlegenden Python-Skripten vertraut zu machen, und eignet sich gut für Anfänger, die ihre Reise in die Welt des Raspberry Pi und der Hardware-Programmierung beginnen.

Benötigte Komponenten
--------------------------

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

Sie können sie auch einzeln über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_button`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_01_Button_Module_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import Button

   # Initialize button connected to GPIO pin 17
   button = Button(17)

   # Continuously check the button state
   while True:
      if button.is_pressed:
         print("Button is pressed")  # Print when button is pressed
      else:
         print("Button is not pressed")  # Print when button is not pressed


Code-Analyse
---------------------------

#. Bibliothek importieren
   
   Importieren der Klasse ``Button`` aus der Bibliothek ``gpiozero`` für die Tastersteuerung.

   .. code-block:: python

      from gpiozero import Button

#. Taster initialisieren
   
   Erstellen eines ``Button``-Objekts, das mit GPIO-Pin 17 verbunden ist.

   .. code-block:: python

      button = Button(17)

#. Tasterzustand kontinuierlich überwachen
   
   Verwenden einer ``while True``-Schleife, um den Zustand des Tasters kontinuierlich zu überprüfen. Wenn der Taster gedrückt wird (``button.is_pressed``), wird "Button is pressed" ausgegeben. Andernfalls wird "Button is not pressed" ausgegeben.

   .. code-block:: python

      while True:
          if button.is_pressed:
              print("Button is pressed")
          else:
              print("Button is not pressed")