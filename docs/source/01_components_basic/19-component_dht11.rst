.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_dht11:

Temperatur- und Feuchtigkeitssensormodul (DHT11)
================================================

.. image:: img/19_dht11_module.png
    :width: 360
    :align: center

.. raw:: html

   <br/>

Der digitale Temperatur- und Feuchtigkeitssensor DHT11 ist ein Kombisensor, der einen kalibrierten digitalen Signalausgang für Temperatur und Feuchtigkeit enthält. Die Technologie der speziellen digitalen Modulsammlung und die Temperatur- und Feuchtigkeitssensortechnologie werden angewendet, um eine hohe Zuverlässigkeit und hervorragende Langzeitstabilität des Produkts zu gewährleisten.

Spezifikation
---------------------------
* Versorgungsspannung: 3,3V - 5V
* Ausgangssignaltyp: Digitalausgang
* Temperaturmessbereich: 0-50℃ ± 2℃
* Feuchtigkeitsmessbereich: 20-90%RH ± 5%RH
* Temperaturgenauigkeit: ±2°C
* Feuchtigkeitsgenauigkeit: ±5% RH

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **S**: Datenpin, verwendet für die Datenübertragung.

Funktionsprinzip
---------------------------
Es sind nur drei Pins verfügbar: VCC, GND und DATA. Der Kommunikationsprozess beginnt damit, dass die DATA-Leitung Startsignale an den DHT11 sendet und dieser die Signale empfängt und ein Antwortsignal zurücksendet. Dann empfängt der Host das Antwortsignal und beginnt, 40-Bit-Feuchtigkeits- und Temperaturdaten zu empfangen (8-Bit-Feuchtigkeitswert ganzzahlig + 8-Bit-Feuchtigkeitswert dezimal + 8-Bit-Temperaturwert ganzzahlig + 8-Bit-Temperaturwert dezimal + 8-Bit-Prüfsumme).

.. image:: img/19_dht11_module_2.png
    :width: 300
    :align: center

.. raw:: html
    
    <br/>

Schaltplan
---------------------------

.. csv-table:: 
   :widths: 30, 70

   |dht11_module|, |dht11_module_schematic|
   |dht11_module_withLED|, |dht11_module_withLED_schematic|

.. |dht11_module| image:: img/19_dht11_module.png
   :width: 100px

.. |dht11_module_withLED| image:: img/19_dht11_module_withLED.png
   :width: 150px

.. |dht11_module_schematic| image:: img/19_dht11_module_schematic.png
   :width: 360px
   
.. |dht11_module_withLED_schematic| image:: img/19_dht11_module_withLED_schematic.png
   :width: 360px

Beispiel
---------------------------
* :ref:`uno_lesson19_dht11` (Arduino UNO)
* :ref:`esp32_lesson19_dht11` (ESP32)
* :ref:`pico_lesson19_dht11` (Raspberry Pi Pico)
* :ref:`pi_lesson19_dht11` (Raspberry Pi)

* :ref:`uno_plant_monitor` (Arduino UNO)
* :ref:`esp32_plant_monitor` (ESP32)
* :ref:`esp32_adafruit_io` (ESP32)
