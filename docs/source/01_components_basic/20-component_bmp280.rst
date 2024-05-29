 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_bmp280:

Temperatur-, Feuchtigkeits- und Drucksensor (BMP280)
===============================================================

.. image:: img/20_bmp280.png
    :width: 200
    :align: center

.. raw:: html

    <br/>

Der BMP280, entwickelt von Bosch Sensortec, ist ein hochpräzises, energiesparendes digitales Sensormodul zur Messung von barometrischem Druck und Temperatur. Aufgrund seiner geringen Größe und überlegenen Leistung wird er häufig in mobilen Geräten, zur Wetterüberwachung, Höhenabschätzungen und in verschiedenen anderen Anwendungen eingesetzt, die genaue atmosphärische Druck- und Temperaturdaten erfordern.

Spezifikation
---------------------------
* Versorgungsspannung: 3,3V oder 5V
* PCB-Größe: 15 x 11mm
* Betriebstemperaturbereich: -40 ~ +85℃
* Luftdruckmessbereich: 300 ~ 1100hPa
* Schnittstelle: I2C (bis zu 3,4MHz), SPI (bis zu 10MHz)

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **SCL**: Serieller Taktpin für die I2C-Schnittstelle.
* **SDA**: Serieller Datenpin für die I2C-Schnittstelle.
* **CSB**: Der Chip-Select-Pin des Moduls. Wenn Sie mit dem Gerät über SPI kommunizieren, können Sie diesen Pin verwenden, um eines der verbundenen Geräte auszuwählen, wenn mehrere Geräte im selben Bus verbunden sind.
* **SDO**: Serieller Datenausgangspin des Moduls. Ein Ausgangssignal an einem Gerät, bei dem Daten an ein anderes SPI-Gerät gesendet werden.

Schaltplan
---------------------------

.. image:: img/20_bmp280_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson20_bmp280` (Arduino UNO)
* :ref:`esp32_lesson20_bmp280` (ESP32)
* :ref:`pico_lesson20_bmp280` (Raspberry Pi Pico)
* :ref:`pi_lesson20_bmp280` (Raspberry Pi)
* :ref:`uno_iot_weather_monito` (Arduino UNO)