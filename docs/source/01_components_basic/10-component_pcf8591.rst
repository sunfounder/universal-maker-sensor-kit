.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_pcf8591:

PCF8591 ADC-DAC-Wandlermodul
=====================================

.. image:: img/10_pcf8591_module.png
    :width: 35%
    :align: center

.. raw:: html

   <br/>

Der PCF8591 ist ein einkanaliges, einversorgtes, stromsparendes 8-Bit-CMOS-Datenerfassungsgerät mit vier analogen Eingängen, einem analogen Ausgang und einer seriellen I2C-Bus-Schnittstelle. Drei Adresspins A0, A1 und A2 werden zur Programmierung der Hardwareadresse verwendet, sodass bis zu acht Geräte ohne zusätzliche Hardware am I2C-Bus angeschlossen werden können. Adresse, Steuerung und Daten werden seriell über den zweidirektionalen I2C-Bus übertragen.

Zu den Funktionen des Geräts gehören analoge Eingangsmultiplexung, On-Chip-Track-and-Hold-Funktion, 8-Bit-Analog-Digital-Wandlung und 8-Bit-Digital-Analog-Wandlung. Die maximale Umwandlungsrate wird durch die maximale Geschwindigkeit des I2C-Bus bestimmt.

Funktionsprinzip
---------------------------

**Adressierung:**

Jedes PCF8591-Gerät in einem I2C-Bus-System wird durch das Senden einer gültigen Adresse an das Gerät aktiviert. Die Adresse besteht aus einem festen und einem programmierbaren Teil. Der programmierbare Teil muss entsprechend den Adresspins A0, A1 und A2 eingestellt werden. Die Adresse muss immer als erstes Byte nach der Startbedingung im I2C-Bus-Protokoll gesendet werden. Das letzte Bit des Adressbytes ist das Lese/Schreib-Bit, das die Richtung der folgenden Datenübertragung festlegt (siehe unten).

.. image:: img/10_pcf8591_addressing.png
   :width: 60%

**Steuerbyte:**

Das zweite Byte, das an ein PCF8591-Gerät gesendet wird, wird in seinem Steuerregister gespeichert und ist erforderlich, um die Gerätefunktion zu steuern. Das obere Nibble des Steuerregisters wird zum Aktivieren des analogen Ausgangs und zum Programmieren der analogen Eingänge als Single-Ended- oder Differenzeingänge verwendet. Das untere Nibble wählt einen der durch das obere Nibble definierten analogen Eingangskanäle aus. Wenn das Auto-Increment-Flag gesetzt ist, wird die Kanalnummer nach jeder A/D-Wandlung automatisch inkrementiert. Siehe die Abbildung unten.

.. image:: img/10_pcf8591_byte.png
   :width: 80%

.. _cpn_pcf8591_sch:

Schaltplan
---------------------------

.. image:: img/10_pcf8591_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson10_pcf8591` (Arduino UNO)
* :ref:`esp32_lesson10_pcf8591` (ESP32)
* :ref:`pico_lesson10_pcf8591` (Raspberry Pi Pico)
* :ref:`pi_lesson10_pcf8591` (Raspberry Pi)

* :ref:`pi_lesson02_soil_moisture` (Raspberry Pi)
* :ref:`pi_lesson09_joystick` (Raspberry Pi)
* :ref:`pi_lesson11_photoresistor` (Raspberry Pi)
* :ref:`pi_lesson13_potentiometer` (Raspberry Pi)
* :ref:`pi_lesson25_water_level` (Raspberry Pi)
