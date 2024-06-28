.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson27_oled:

Lektion 27: OLED-Display-Modul (SSD1306)
============================================

In dieser Lektion lernen Sie, wie Sie ein Arduino Uno-Board programmieren, um ein OLED-Display (SSD1306) zu steuern. Wir werden die Verwendung der Adafruit SSD1306- und GFX-Bibliotheken abdecken, um Text, Zahlen und Scroll-Animationen auf dem Bildschirm anzuzeigen. Dieses Projekt ist ideal für diejenigen, die ihr Wissen über die Anzeige von Grafiken und Text auf kleinen Bildschirmen mit der Arduino-Umgebung erweitern möchten.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link: 

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

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_oled`
        - \-


Verdrahtung
---------------------------

.. image:: img/Lesson_27_OLED_circuit_uno_bb.png
    :width: 100%

Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen nach **"Adafruit SSD1306"** und **"Adafruit GFX"** und installieren Sie sie.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b2617291-5326-4d12-812b-78c45ced7516/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. **Bibliothekseinbindung und Initiale Definitionen**:
   Die notwendigen Bibliotheken für die Ansteuerung des OLEDs werden eingebunden. Anschließend werden Definitionen bezüglich der Abmessungen des OLEDs und der I2C-Adresse angegeben.

   - **Adafruit SSD1306**: Diese Bibliothek hilft bei der Ansteuerung des SSD1306 OLED-Displays. Sie stellt Methoden zum Initialisieren des Displays, zur Steuerung seiner Einstellungen und zur Anzeige von Inhalten bereit.
   - **Adafruit GFX Library**: Dies ist eine grundlegende Grafikbibliothek zum Anzeigen von Text, Erzeugen von Farben, Zeichnen von Formen usw. auf verschiedenen Bildschirmen, einschließlich OLEDs.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen nach **"Adafruit SSD1306"** und **"Adafruit GFX"** und installieren Sie sie.

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // OLED display width, in pixels
      #define SCREEN_HEIGHT 64  // OLED display height, in pixels

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **Bitmap-Daten**:
   Bitmap-Daten zur Anzeige eines benutzerdefinierten Symbols auf dem OLED-Bildschirm. Diese Daten stellen ein Bild in einem Format dar, das das OLED interpretieren kann.

   Sie können dieses Online-Tool namens |link_image2cpp| verwenden, das Ihr Bild in ein Array umwandeln kann.

   Das Schlüsselwort ``PROGMEM`` gibt an, dass das Array im Programmspeicher des Arduino-Mikrocontrollers gespeichert wird. Das Speichern von Daten im Programmspeicher(PROGMEM) anstelle von RAM kann für große Datenmengen hilfreich sein, die sonst zu viel Platz im RAM beanspruchen würden.

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **Setup-Funktion (Initialisierung und Anzeige)**:
   Die Funktion ``setup()`` initialisiert das OLED und zeigt eine Reihe von Mustern, Texten und Animationen an.

   .. code-block:: arduino

      void setup() {
         ...  // Serial initialization and OLED object initialization
         ...  // Displaying various text, numbers, and animations
      }