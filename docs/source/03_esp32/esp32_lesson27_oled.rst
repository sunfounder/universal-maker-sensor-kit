.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson27_oled:

Lektion 27: OLED Display Modul (SSD1306)
===========================================

In dieser Lektion lernen Sie, wie Sie ein OLED-Display mit einem ESP32-Entwicklungsboard und den Adafruit SSD1306 und GFX Bibliotheken einrichten und nutzen. Wir werden die Anzeige von Text in verschiedenen Größen, das Invertieren der Textfarben, das Erstellen von scrollenden Textanimationen und das Rendern von benutzerdefinierten Bitmap-Grafiken behandeln. Dieses Projekt bietet eine gründliche Einführung in fortgeschrittene Display-Techniken und ist ideal für Personen, die ihre Fähigkeiten in der Entwicklung interaktiver Elektronik mit Mikrocontrollern verbessern möchten.

Benötigte Komponenten
-------------------------

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
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------

.. image:: img/Lesson_27_oled_esp32_bb.png
    :width: 100%

Code
-------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/33f2fdd0-af4e-4438-bacf-982894bb8ac4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------

#. **Bibliothekseinbindung und Initiale Definitionen**:
   Die notwendigen Bibliotheken für die Schnittstelle mit dem OLED-Display werden eingebunden. Danach werden Definitionen bezüglich der Abmessungen des OLEDs und der I2C-Adresse bereitgestellt.

   - **Adafruit SSD1306**: Diese Bibliothek ist für die Schnittstelle mit dem SSD1306 OLED-Display konzipiert. Sie bietet Methoden zur Initialisierung des Displays, Steuerung seiner Einstellungen und Anzeige von Inhalten.
   - **Adafruit GFX Bibliothek**: Dies ist eine grundlegende Grafikbibliothek zur Anzeige von Text, Erzeugung von Farben, Zeichnen von Formen usw. auf verschiedenen Bildschirmen, einschließlich OLEDs.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager, suchen Sie nach **"Adafruit SSD1306"** und **"Adafruit GFX"** und installieren Sie sie.

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // OLED display width, in pixels
      #define SCREEN_HEIGHT 64  // OLED display height, in pixels

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

#. **Bitmap-Daten**:
   Bitmap-Daten zur Anzeige eines benutzerdefinierten Icons auf dem OLED-Bildschirm. Diese Daten stellen ein Bild in einem Format dar, das das OLED interpretieren kann.

   Sie können dieses Online-Tool namens |link_image2cpp| verwenden, das Ihr Bild in ein Array umwandeln kann.

   Das ``PROGMEM``-Schlüsselwort zeigt an, dass das Array im Programmspeicher des Arduino-Mikrocontrollers gespeichert wird. Das Speichern von Daten im Programmspeicher (PROGMEM) anstelle von RAM kann bei großen Datenmengen hilfreich sein, die sonst zu viel Platz im RAM einnehmen würden.

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

#. **Setup-Funktion (Initialisierung und Anzeige)**:
   Die ``setup()``-Funktion initialisiert das OLED und zeigt eine Reihe von Mustern, Texten und Animationen an.

   .. code-block:: arduino

      void setup() {
         ...  // Serial initialization and OLED object initialization
         ...  // Displaying various text, numbers, and animations
      }