.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson26_lcd:

Lektion 26: I2C LCD 1602
==================================

In dieser Lektion lernen Sie, wie man ein 16x2-LCD mit I2C-Schnittstelle und Arduino einrichtet und Nachrichten darauf anzeigt. Wir behandeln die Grundlagen der Verwendung der LiquidCrystal I2C-Bibliothek zur Initialisierung des LCDs, zur Anzeige von Text und zur Steuerung der Hintergrundbeleuchtung. Sie werden sehen, wie man "Hello world!" und "LCD Tutorial" auf dem Display ausgibt und erhalten so eine praktische Einführung in die Schnittstellenprogrammierung von LCDs mit Arduino. Dieses Tutorial ist perfekt für Anfänger geeignet, da es eine praxisnahe Lektion zur Steuerung elektronischer Anzeigen bietet.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


Verdrahtung
---------------------------

.. image:: img/Lesson_26_I2C_lcd_circuit_uno_bb.png
    :width: 100%

Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen nach **"LiquidCrystal I2C"** und installieren diese.  

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/48a64786-bcfc-4497-a12d-495c283e09ce/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

1. Einbindung der Bibliothek und Initialisierung des LCD:
   Die LiquidCrystal I2C-Bibliothek wird eingebunden, um Funktionen und Methoden für die LCD-Ansteuerung bereitzustellen. Anschließend wird ein LCD-Objekt mit der LiquidCrystal_I2C-Klasse erstellt, wobei die I2C-Adresse, die Anzahl der Spalten und die Anzahl der Zeilen angegeben werden.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen nach **"LiquidCrystal I2C"** und installieren diese.  

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Setup-Funktion:
   Die ``setup()``-Funktion wird einmal ausgeführt, wenn das Arduino startet. In dieser Funktion wird das LCD initialisiert, gelöscht und die Hintergrundbeleuchtung eingeschaltet. Danach werden zwei Nachrichten auf dem LCD angezeigt.

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