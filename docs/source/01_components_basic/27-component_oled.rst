.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_oled:

OLED-Displaymodul (SSD1306)
=================================

.. image:: img/27_OLED.png
    :width: 300
    :align: center

.. raw:: html

    <br/>

Ein OLED (Organic Light-Emitting Diode) Displaymodul ist ein Gerät, das Text, Grafiken und Bilder auf einem dünnen und flexiblen Bildschirm anzeigen kann, wobei organische Materialien verwendet werden, die Licht emittieren, wenn elektrischer Strom angelegt wird.

Das SSD1306 I2C OLED-Displaymodul steuert ein OLED-Display (Organic Light-Emitting Diode) mit dem leistungsstarken CMOS-OLED-Treibercontroller SSD1306. Dieser Controller verwaltet das gesamte RAM-Buffering und erfordert nur minimalen Aufwand vom angeschlossenen Mikrocontroller, wie zum Beispiel einem Arduino. OLED-Displays sind für ihre extrem leichte und potenziell flexible Natur bekannt und erzeugen hellere und schärfere Bilder im Vergleich zu herkömmlichen Displays, da sie nahezu papierdünn sind.

Der Hauptvorteil eines OLED-Displays besteht darin, dass es sein eigenes Licht emittiert und keine zusätzliche Hintergrundbeleuchtung benötigt. Daher haben OLED-Displays oft besseren Kontrast, Helligkeit und Betrachtungswinkel im Vergleich zu LCD-Displays.

Ein weiteres wichtiges Merkmal von OLED-Displays sind tiefschwarze Pegel. Da jedes Pixel in einem OLED-Display sein eigenes Licht emittiert, kann zur Erzeugung der schwarzen Farbe das einzelne Pixel ausgeschaltet werden.

Aufgrund des geringeren Stromverbrauchs (nur beleuchtete Pixel ziehen Strom) sind OLED-Displays auch in batteriebetriebenen Geräten wie Smartwatches, Gesundheitstrackern und anderen Wearables beliebt.

Pinbelegung
---------------------------
* **VIN**: Dies ist der Stromversorgungspin.
* **GND**: Gemeinsame Masse für Strom und Logik.
* **SCL**: Der serielle Taktpin für die I2C-Schnittstelle.
* **SDA**: Der serielle Datenpin für die I2C-Schnittstelle.

Beispiel
---------------------------
* :ref:`uno_lesson27_oled` (Arduino UNO)
* :ref:`esp32_lesson27_oled` (ESP32)
* :ref:`pico_lesson27_oled` (Raspberry Pi Pico)
* :ref:`pi_lesson27_oled` (Raspberry Pi)

* :ref:`uno_lesson41_heartrate_monitor` (Arduino UNO)
* :ref:`uno_digital_dice` (Arduino UNO)
* :ref:`esp32_heartrate_monitor` (ESP32)
* :ref:`esp32_digital_dice` (ESP32)
