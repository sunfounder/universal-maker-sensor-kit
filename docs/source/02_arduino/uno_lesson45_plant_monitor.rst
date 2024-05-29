 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_plant_monitor:

Lektion 45: Pflanzenüberwachung
=============================================================


Dieses Projekt automatisiert die Bewässerung von Pflanzen intelligent, indem es eine Wasserpumpe auslöst, 
wann immer der Feuchtigkeitsgehalt des Bodens unter einen vorbestimmten Schwellenwert fällt. 
Es verfügt außerdem über ein LCD-Display, das die Temperatur, Luftfeuchtigkeit und Bodenfeuchtigkeit anzeigt 
und den Benutzern wertvolle Einblicke in die Umgebungsbedingungen der Pflanze bietet.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_power_module`
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_dht11`
        - \-

Verkabelung
---------------------------

.. image:: img/Lesson_45_Plant_monitor_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/700a51fb-6bb3-46c0-b0eb-5b03a6eb681e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Code-Analyse
---------------------------



Der Code ist strukturiert, um die Bewässerung von Pflanzen nahtlos zu verwalten, indem er Umgebungsparameter überwacht:

1. Bibliothekseinbindungen und Konstanten/Variablen:

   Integrieren Sie die Bibliotheken ``Wire.h``, ``LiquidCrystal_I2C.h`` und ``DHT.h`` für die Funktionalität.
   Geben Sie Pin-Belegungen und Einstellungen für den DHT11-Sensor, den Bodenfeuchtigkeitssensor und die Wasserpumpe an.

2. ``setup()``:

   Konfigurieren Sie die Pin-Modi für den Feuchtigkeitssensor und die Pumpe.
   Deaktivieren Sie zunächst die Pumpe.
   Initialisieren und beleuchten Sie das LCD.
   Aktivieren Sie den DHT-Sensor.

3. ``loop()``:

   Messen Sie Luftfeuchtigkeit und Temperatur über den DHT-Sensor.
   Schätzen Sie die Bodenfeuchtigkeit durch den Bodenfeuchtigkeitssensor ein.
   Zeigen Sie die Temperatur und Luftfeuchtigkeit auf dem LCD an und zeigen Sie dann die Bodenfeuchtigkeit an.
   Bewertung der Bodenfeuchtigkeit, um über die Aktivierung der Wasserpumpe zu entscheiden; wenn die Bodenfeuchtigkeit unter 500 liegt (einstellbarer Schwellenwert), lassen Sie die Pumpe 1 Sekunde lang laufen.


