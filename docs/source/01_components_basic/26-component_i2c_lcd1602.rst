 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_i2c_lcd1602:

I2C LCD 1602
==========================

.. image:: img/26_i2c_lcd.png
    :width: 90%
    :align: center

.. raw:: html

   <br/>

Ein I2C LCD1602 ist ein Gerät, das Text und Zeichen auf einem 16x2 (16 Spalten und 2 Reihen) Flüssigkristalldisplay (LCD) unter Verwendung des I2C-Protokolls anzeigen kann. Sie können ein I2C LCD1602 verwenden, um Informationen aus Ihren Arduino-Projekten anzuzeigen, wie z.B. Sensordaten, Nachrichten, Menüs usw. Das I2C-Modul hat einen eingebauten PCF8574 I2C-Chip, der serielle I2C-Daten in Paralleldaten für das LCD-Display umwandelt.

* |link_PCF8574_Datasheet|

Funktionsprinzip
---------------------------
Ein I2C LCD1602 besteht aus einem normalen LCD1602 und einem I2C-Modul, das an der Rückseite des LCD angebracht ist. Das I2C-Modul ist ein Chip, der die I/O-Ports des Arduino mit dem I2C-Protokoll erweitern kann. Das I2C-Protokoll ist ein serielles Kommunikationsprotokoll, das zwei Leitungen verwendet: SDA (serielle Daten) und SCL (serielle Uhr). Das I2C-Protokoll ermöglicht es mehreren Geräten, über nur zwei Leitungen und eindeutige Adressen miteinander zu kommunizieren.

Das I2C-Modul wandelt die Signale vom Arduino in Befehle für das LCD um. Das LCD verfügt über 16x2 Zellen, die Zeichen oder Symbole anzeigen können. Jede Zelle besteht aus 5x8 Punkten, die durch Anlegen einer Spannung ein- oder ausgeschaltet werden können. Das LCD kann verschiedene Zeichen oder Symbole anzeigen, indem verschiedene Kombinationen von Punkten ein- oder ausgeschaltet werden.

.. image:: img/26_ic2_lcd_2.png
    :width: 500
    :align: center

.. raw:: html

    <br/><br/>

**I2C-Adresse**

Die Standardadresse ist grundsätzlich 0x27, in einigen Fällen kann sie 0x3F sein.

Nehmen wir die Standardadresse 0x27 als Beispiel, die Geräteadresse kann durch Überbrücken der A0/A1/A2-Pads geändert werden; im Standardzustand ist A0/A1/A2 1, und wenn das Pad überbrückt wird, ist A0/A1/A2 0.

.. image:: img/26_i2c_address.jpg
    :width: 600
    :align: center

.. raw:: html

    <br/>

**Hintergrundbeleuchtung/Kontrast**

Die Hintergrundbeleuchtung kann durch einen Jumper aktiviert werden, durch Entfernen des Jumpers wird die Hintergrundbeleuchtung deaktiviert. Das blaue Potentiometer auf der Rückseite dient zur Einstellung des Kontrasts (das Verhältnis der Helligkeit zwischen dem hellsten Weiß und dem dunkelsten Schwarz).

.. image:: img/26_back_lcd1602.jpg
    :width: 600
    :align: center

.. raw:: html

    <br/>


* **Kurzschlusskappe**: Die Hintergrundbeleuchtung kann durch diese Kappe aktiviert werden, durch Entfernen der Kappe wird die Hintergrundbeleuchtung deaktiviert.
* **Potentiometer**: Wird zur Einstellung des Kontrasts verwendet (die Klarheit des angezeigten Textes), der im Uhrzeigersinn erhöht und gegen den Uhrzeigersinn verringert wird.

.. note::
    Nachdem das LCD verdrahtet ist, sollten Sie den Arduino einschalten und den Kontrast durch Drehen des Potentiometers am I2C-Modul einstellen, bis die erste Reihe von Rechtecken erscheint, um den ordnungsgemäßen Betrieb des LCD sicherzustellen.

Beispiel
---------------------------
* :ref:`uno_lesson26_lcd` (Arduino UNO)
* :ref:`esp32_lesson26_lcd` (ESP32)
* :ref:`pico_lesson26_lcd` (Raspberry Pi Pico)
* :ref:`pico_lesson26_lcd` (Raspberry Pi)

* :ref:`uno_potentiometer_scale_value` (Arduino UNO)
* :ref:`uno_plant_monitor` (Arduino UNO)
* :ref:`uno_bluetooth_lcd` (Arduino UNO)
* :ref:`esp32_potentiometer_scale_value` (ESP32)
* :ref:`esp32_plant_monitor` (ESP32)
* :ref:`esp32_iot_owm` (ESP32)
