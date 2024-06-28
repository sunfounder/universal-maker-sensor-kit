
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_digital_dice:

Lektion 44: Digitales Würfelspiel
=============================================================


Dieses Programm simuliert das Würfeln mit einem OLED-Display. 
Die Simulation wird durch Schütteln des Erschütterungsschalters ausgelöst, was dazu führt, dass das Display die Zahlen 1 bis 6 durchläuft, 
ähnlich wie beim Würfeln mit einem Würfel. 
Das Display stoppt nach kurzer Zeit und zeigt eine zufällig ausgewählte Zahl an, die das Ergebnis des Würfelwurfs darstellt.



Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch separat von den untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verkabelung
---------------------------

.. image:: img/Lesson_44_Digital_dice_uno_bb.png
    :width: 100%


Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen nach **"LiquidCrystal I2C"** und installieren diese.  

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/70e73ef9-2968-4845-befd-23185286fd93/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code-Analyse
---------------------------

Eine umfassende Analyse des Codes:

1. Initialisierung von Variablen:

   ``vibPin``: Digitaler Pin, der mit dem Erschütterungssensor verbunden ist.

2. Volatile Variablen:

   ``rolling``: Eine volatile Flagge, die den Würfelstatus anzeigt. Sie ist als volatile gekennzeichnet, da sie sowohl im Interrupt-Service-Routine als auch im Hauptprogramm verwendet wird.

3. ``setup()``:

   Konfiguriert den Eingangsmodus des Erschütterungssensors.
   Weist dem Sensor einen Interrupt zu, um die Funktion rollDice bei Zustandsänderung auszulösen.
   Initialisiert das OLED-Display.

4. ``loop()``:

   Überprüft kontinuierlich, ob ``rolling`` wahr ist, und zeigt während dieses Zustands eine zufällige Zahl zwischen 1 und 6 an. Das Würfeln endet, wenn der Sensor länger als 500 Millisekunden geschüttelt wurde.

5. ``rollDice()``:

   Die Interrupt-Service-Routine für den Erschütterungssensor. Sie initiiert den Würfelwurf, wenn der Sensor geschüttelt wird, indem sie die aktuelle Zeit aufzeichnet.

6. ``displayNumber()``:

   Zeigt eine ausgewählte Zahl auf dem OLED-Bildschirm an.
