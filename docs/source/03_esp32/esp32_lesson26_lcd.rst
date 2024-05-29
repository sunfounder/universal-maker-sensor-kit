 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson26_lcd:

Lektion 26: I2C LCD 1602
==============================

In dieser Lektion lernen Sie, wie Sie ein 16x2-Liquid-Crystal-Display (LCD) mit einer I2C-Schnittstelle mithilfe eines ESP32-Entwicklungsboards einrichten und Nachrichten darauf anzeigen. Wir werden die Initialisierung des LCDs mit der LiquidCrystal I2C-Bibliothek behandeln und anschließend "Hello world!" und "LCD Tutorial" auf zwei separaten Zeilen des Bildschirms anzeigen. Dieses Tutorial ist ideal für Anfänger und bietet praktische Erfahrung mit LCD-Schnittstellen sowie ein besseres Verständnis der Ausgabefunktionen in der Arduino-Programmierung.

Benötigte Komponenten
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

Sie können sie auch einzeln über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------

.. image:: img/Lesson_26_LCD1602_esp32_bb.png
    :width: 100%

Code
--------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3c6bcc49-9030-4539-8220-4ff3c484814c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
-------------------

1. Bibliothekseinbindung und LCD-Initialisierung:
   Die LiquidCrystal I2C-Bibliothek wird eingebunden, um Funktionen und Methoden für die LCD-Interfacing bereitzustellen. Anschließend wird ein LCD-Objekt mithilfe der LiquidCrystal_I2C-Klasse erstellt, wobei die I2C-Adresse, die Anzahl der Spalten und die Anzahl der Zeilen angegeben werden.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager, suchen Sie nach **"LiquidCrystal I2C"** und installieren Sie sie.  

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Setup-Funktion:
   Die ``setup()``-Funktion wird einmal ausgeführt, wenn das ESP32-Entwicklungsboard startet. In dieser Funktion wird das LCD initialisiert, gelöscht und die Hintergrundbeleuchtung eingeschaltet. Anschließend werden zwei Nachrichten auf dem LCD angezeigt.

   .. code-block:: arduino

      void setup() {
        lcd.init();       // initialize the LCD
        lcd.clear();      // clear the LCD display
        lcd.backlight();  // Make sure backlight is on
      
        // Print a message on both lines of the LCD.
        lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
        lcd.print("LCD Tutorial");
      }