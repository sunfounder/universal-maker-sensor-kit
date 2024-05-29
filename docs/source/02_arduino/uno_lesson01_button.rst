 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson01_button:

Lektion 01: Tastenmodul
==================================

In dieser Lektion lernen Sie, wie ein Taster mit einer LED über Arduino interagiert. Wir werden sehen, wie das Drücken des Tasters die LED einschaltet und das Loslassen sie ausschaltet. Dieses Projekt ist ideal für Anfänger, da es ein praktisches Verständnis der Ein- und Ausgangsoperationen auf der Arduino-Plattform vermittelt.

Benötigte Komponenten
---------------------------

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

Sie können sie auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_button`
        - \-

Verkabelung
---------------------------

.. image:: img/Lesson_01_Button_Module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2249707e-73aa-400b-8141-15424c291f44/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Codeanalyse
---------------------------

#. Initialisierung der Pins

   Die Pins für den Taster und die LED werden definiert und initialisiert. Der ``buttonPin`` wird als Eingang gesetzt, um den Zustand des Tasters zu lesen, und der ``ledPin`` wird als Ausgang gesetzt, um die LED zu steuern.

   .. note::
      Die meisten Arduino-Boards haben einen Pin, der mit einer eingebauten LED in Reihe mit einem Widerstand verbunden ist. Die Konstante ``LED_BUILTIN`` ist die Nummer des Pins, an den die eingebaute LED angeschlossen ist. Die meisten Boards haben diese LED an den digitalen Pin 13 angeschlossen.
   
   .. code-block:: arduino

      const int buttonPin = 12;        // Pin number for the button
      const int ledPin = LED_BUILTIN;  // Pin number for the LED
      int buttonState = 0;  // Variable to hold the current state of the button

#. Setup-Funktion

   Diese Funktion läuft einmal und richtet die Pin-Modi ein. ``pinMode(buttonPin, INPUT)`` konfiguriert den Taster-Pin als Eingang. ``pinMode(ledPin, OUTPUT)`` setzt den LED-Pin als Ausgang.
   
   .. code-block:: arduino

      void setup() {
        pinMode(buttonPin, INPUT);  // Initialize buttonPin as an input pin
        pinMode(ledPin, OUTPUT);    // Initialize ledPin as an output pin
      }

#. Hauptschleifenfunktion

   Dies ist der Kern des Programms, in dem der Tasterzustand kontinuierlich gelesen und der LED-Zustand gesteuert wird. ``digitalRead(buttonPin)`` liest den Zustand des Tasters. Wenn der Taster gedrückt wird (Zustand ist LOW), wird die LED mit ``digitalWrite(ledPin, HIGH)`` eingeschaltet. Wenn der Taster nicht gedrückt wird, wird die LED ausgeschaltet (``digitalWrite(ledPin, LOW)``).

   Das in diesem Projekt verwendete :ref:`button module<cpn_button>` hat einen internen Pull-up-Widerstand (siehe sein :ref:`schematic diagram<cpn_button_sch>`), wodurch der Taster im gedrückten Zustand auf einem niedrigen Pegel ist und im nicht gedrückten Zustand auf einem hohen Pegel bleibt.
   
   .. code-block:: arduino

      void loop() {
        // Read the current state of the button
        buttonState = digitalRead(buttonPin);

        // Check if the button is pressed (LOW)
        if (buttonState == LOW) {
          digitalWrite(ledPin, HIGH);  // Turn the LED on
        } else {
          digitalWrite(ledPin, LOW);  // Turn the LED off
        }
      }
