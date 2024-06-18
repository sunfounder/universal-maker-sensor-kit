.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson26_lcd:

Lektion 26: I2C LCD 1602
==================================

In dieser Lektion lernen Sie die Grundlagen der Textanzeige auf einem LCD-Bildschirm mithilfe eines Raspberry Pi. Wir beginnen damit, Ihnen zu zeigen, wie Sie ein standardmäßiges LCD über die I2C-Schnittstelle an den Raspberry Pi anschließen. Sie lernen, wie Sie das LCD mit einfachen Parametern wie dem Raspberry Pi-Modell und der I2C-Adresse einrichten. Anschließend führen wir Sie durch das Schreiben eines einfachen Python-Skripts, um Nachrichten wie „Hello World!“ auf dem Bildschirm anzuzeigen. Dieses unkomplizierte Projekt richtet sich an Anfänger und bietet eine grundlegende Einführung in die Hardware-Integration mit dem Raspberry Pi und die grundlegende Python-Programmierung.

Erforderliche Komponenten
----------------------------

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_26_LCD1602_Pi_bb.png
    :width: 100%

Code
---------------------------

.. code-block:: python

   import time
   from LCD import LCD

   # Initialize the LCD with specific parameters: Raspberry Pi revision, I2C address, and backlight status
   lcd = LCD(2, 0x27, True)  # Using Raspberry Pi revision 2, I2C address 0x27, backlight enabled

   # Display messages on the LCD
   lcd.message("Hello World!", 1)        # Display 'Hello World!' on line 1
   lcd.message("    - Sunfounder", 2)    # Display '    - Sunfounder' on line 2

   # Keep the messages displayed for 5 seconds
   time.sleep(5)

   # Clear the LCD display
   lcd.clear()

Code-Analyse
---------------------------

#. Bibliotheken importieren
   
   Importieren Sie das ``time``-Modul für Verzögerungen und das ``LCD``-Modul zur Steuerung des LCDs.

   Weitere Informationen zur ``LCD``-Bibliothek finden Sie unter |link_lcd1602_python_driver_pi|.

   .. code-block:: python

      import time
      from LCD import LCD

#. Initialisierung des LCD
   
   Erstellen Sie ein ``LCD``-Objekt mit spezifischen Parametern: die Raspberry Pi-Revision, die I2C-Adresse des LCDs und den Hintergrundbeleuchtungsstatus. In diesem Fall Raspberry Pi-Revision 2 (und höher), I2C-Adresse 0x27 und Hintergrundbeleuchtung aktiviert.

   .. code-block:: python

      lcd = LCD(2, 0x27, True)

#. Nachrichten auf dem LCD anzeigen
   
   Verwenden Sie die ``message``-Methode des ``LCD``-Objekts, um Text auf dem LCD anzuzeigen. Das erste Argument ist der Text und das zweite Argument die Zeilennummer.

   .. code-block:: python

      lcd.message("Hello World!", 1)
      lcd.message("    - Sunfounder", 2)

#. Nachrichten auf dem LCD anzeigen lassen
   
   Pausieren Sie das Programm für 5 Sekunden, um die Nachrichten während dieser Zeit auf dem LCD zu halten.

   .. code-block:: python

      time.sleep(5)

#. Das LCD-Display löschen
   
   Löschen Sie nach der Verzögerung das Display mit der ``clear``-Methode des ``LCD``-Objekts.

   .. code-block:: python

      lcd.clear()

