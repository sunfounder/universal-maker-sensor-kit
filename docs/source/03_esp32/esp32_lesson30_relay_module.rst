.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson30_relay_module:

Lektion 30: Relaismodul
==========================

In dieser Lektion lernen Sie, wie Sie ein Ein-Kanal-Relaismodul mit einem ESP32-Entwicklungsboard steuern. Wir werden das Ein- und Ausschalten des Relais in einer Schleife behandeln, wobei zwischen jedem Zustandswechsel eine Verzögerung von 3 Sekunden liegt. Dieses Projekt bietet praktische Erfahrungen mit digitalen Ausgangsoperationen in eingebetteten Systemen und ist ideal für Anfänger, die sich mit dem ESP32 und Relaismodulen vertraut machen möchten.

Benötigte Komponenten
------------------------

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-

Verdrahtung
--------------

.. image:: img/Lesson_30_Relay_esp32_bb.png
    :width: 100%

Code
--------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a0035890-76ca-4a85-9f21-9df01717d906/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
----------------

#. Einrichtung des Relais-Pins:

   - Das Relaismodul ist an Pin 25 des ESP32-Entwicklungsboards angeschlossen. Dieser Pin wird als ``relayPin`` definiert, um die Referenz im Code zu erleichtern.

   .. raw:: html

      <br/>

   .. code-block:: arduino
    
      const int relayPin = 25;

#. Konfiguration des Relais-Pins als Ausgang:

   - In der ``setup()``-Funktion wird der Relais-Pin mit der Funktion ``pinMode()`` als ``OUTPUT`` festgelegt. Dies bedeutet, dass das Arduino Signale (entweder HIGH oder LOW) an diesen Pin sendet.

   .. raw:: html

      <br/>

   .. code-block:: arduino

      void setup() {
        pinMode(relayPin, OUTPUT);
      }

#. Umschalten des Relais EIN und AUS:

   - In der ``loop()``-Funktion wird das Relais zuerst mit ``digitalWrite(relayPin, LOW)`` in den AUS-Zustand versetzt. Es verbleibt 3 Sekunden in diesem Zustand (``delay(3000)``).
   - Dann wird das Relais mit ``digitalWrite(relayPin, HIGH)`` in den EIN-Zustand versetzt. Auch hier verbleibt es 3 Sekunden in diesem Zustand.
   - Dieser Zyklus wiederholt sich unendlich.

   .. raw:: html

      <br/>

   .. code-block:: arduino

      void loop() {
        digitalWrite(relayPin, LOW);
        delay(3000);

        digitalWrite(relayPin, HIGH);
        delay(3000);
      }