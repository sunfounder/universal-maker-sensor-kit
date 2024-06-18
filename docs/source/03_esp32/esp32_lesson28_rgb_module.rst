.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson28_rgb_module:

Lektion 28: RGB LED Modul
=============================

In dieser Lektion lernen Sie, wie Sie eine RGB-LED mit einem ESP32-Entwicklungsboard steuern. Wir werden die Nutzung verschiedener Farbkanäle zur Anzeige von Primärfarben und die Erstellung einer Sequenz von Regenbogenfarben behandeln. Dieses Projekt ist ideal für Anfänger in Elektronik und Programmierung und bietet praktische Erfahrungen mit Ausgabefunktionen und Farbmischung unter Verwendung des ESP32 und des RGB-LED-Moduls.

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
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
--------------

.. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png
    :width: 100%

Code
--------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a8796969-0aed-4037-8080-f62059cc2db5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
--------------

#. Der erste Abschnitt des Codes deklariert und initialisiert die Pins, an die jeder Farbkanal des RGB-LED-Moduls angeschlossen ist.

   .. code-block:: arduino

      const int rledPin = 25;  // pin connected to the red color channel
      const int gledPin = 26;   // pin connected to the green color channel
      const int bledPin = 27;  // pin connected to the blue color channel

2. The ``setup()`` function initializes these pins as OUTPUT. This means we are sending signals OUT from these pins to the RGB LED module.

   .. code-block:: arduino

      void setup() {
        pinMode(rledPin, OUTPUT);
        pinMode(gledPin, OUTPUT);
        pinMode(bledPin, OUTPUT);
      }

#. In der ``loop()``-Funktion wird die ``setColor()``-Funktion mit verschiedenen Parametern aufgerufen, um verschiedene Farben anzuzeigen. Die ``delay()``-Funktion wird nach dem Setzen jeder Farbe verwendet, um eine Pause von 1000 Millisekunden (oder 1 Sekunde) einzulegen, bevor zur nächsten Farbe übergegangen wird.

   .. code-block:: arduino

      void loop() {
        setColor(255, 0, 0);  // Set RGB LED color to red
        delay(1000);
        setColor(0, 255, 0);  // Set RGB LED color to green
        delay(1000);
        // The rest of the color sequence...
      }

#. Die ``setColor()``-Funktion verwendet die ``analogWrite()``-Funktion, um die Helligkeit jedes Farbkanals des RGB-LED-Moduls anzupassen. Die ``analogWrite()``-Funktion verwendet Pulsweitenmodulation (PWM), um unterschiedliche Spannungsausgaben zu simulieren. Durch Steuerung des PWM-Duty-Cycles (der prozentuale Anteil der Zeit, in der ein Signal innerhalb einer festen Periode HIGH ist) kann die Helligkeit jedes Farbkanals gesteuert werden, was die Mischung verschiedener Farben ermöglicht.

   .. code-block:: arduino

      void setColor(int R, int G, int B) {
        analogWrite(rledPin, R);  // Use PWM to control the brightness of the red color channel
        analogWrite(gledPin, G);  // Use PWM to control the brightness of the green color channel
        analogWrite(bledPin, B);  // Use PWM to control the brightness of the blue color channel
      }