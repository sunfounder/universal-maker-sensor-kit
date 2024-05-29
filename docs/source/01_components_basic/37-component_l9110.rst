 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_l9110:

L9110 Motortreiber-Modul
=============================

Das L9110 Motortreiber-Modul eignet sich hervorragend zum Ansteuern von zwei Motoren gleichzeitig. Es enthält ein Paar unabhängiger L9110S-Treiberchips, wobei jeder Kanal einen konstanten Strom von bis zu 800 mA liefert.

Mit einem Spannungsbereich von 2,5 V bis 12 V passt das Modul problemlos zu 3,3 V und 5 V Mikrocontrollern.

Als eine effiziente Lösung erleichtert das L9110 Motortreiber-Modul die Motorsteuerung in einer Vielzahl von Anwendungen.
Dank seiner Zweikanal-Architektur ermöglicht es die unabhängige Steuerung von zwei Motoren – ideal für Projekte, bei denen der Betrieb von zwei Motoren entscheidend ist.

Durch seinen starken kontinuierlichen Stromausgang kann dieses Modul Motoren von klein bis mittelgroß problemlos antreiben und ist damit perfekt für diverse Robotik-, Automatisierungs- und motorzentrierte Projekte geeignet. Sein breiter Spannungsbereich bietet zudem Flexibilität und passt sich unterschiedlichen Stromversorgungskonfigurationen an.

Das Modul wurde benutzerfreundlich gestaltet und bietet intuitive Ein- und Ausgangsterminals, die die Verbindung zu Mikrocontrollern oder ähnlichen Steuergeräten erleichtern. Darüber hinaus wurde auf Sicherheit geachtet – integrierte Überstrom- und Übertemperaturschutzmechanismen erhöhen die Zuverlässigkeit und Sicherheit des Motorbetriebs.

.. image:: img/37_l9110_module.jpg
    :width: 80%
    :align: center
    
* **B-1A & B-1B(B-2A)**: Eingabepins zur Steuerung der Drehrichtung von Motor B.
* **A-1A & A-1B**: Eingabepins zur Steuerung der Drehrichtung von Motor A.
* **0A & OB(A)**: Ausgabepins von Motor A.
* **0A & OB(B)**: Ausgabepins von Motor B.
* **VCC**: Stromeingangspin (2,5V-12V).
* **GND**: Massepin.

**Eigenschaften**

* On-Board 2 L9110S Motortreiber-Chip
* Zweikanal-Motorsteuerung.
* Unabhängige Steuerung der Drehrichtung der Motoren.
* Hoher Stromausgang (800mA pro Kanal).
* Breiter Spannungsbereich (2.5V-12V).
* Kompaktes Design.
* Praktische Ein- und Ausgangsterminals.
* Eingebaute Schutzfunktionen.
* Vielseitige Anwendungen.
* PCB Größe: 29.2 mm x 23mm
* Betriebstemperatur: -20°C ~ 80°C
* Power-On LED-Anzeige


.. _cpn_l9110_principle:

**Funktionsprinzip**

Hier ist die Wahrheitstabelle für Motor B:

Diese Wahrheitstabelle zeigt die verschiedenen Zustände von Motor B basierend auf den Werten der Eingangspins B-1A und B-1B (B-2A). Sie gibt die Drehrichtung (im Uhrzeigersinn oder gegen den Uhrzeigersinn), das Bremsen oder Anhalten von Motor B an.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B (B-2A)
      - Zustand von Motor B
    * - 1
      - 0
      - Dreht im Uhrzeigersinn
    * - 0
      - 1
      - Dreht gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremst
    * - 1
      - 1
      - Stoppt

Hier ist die Wahrheitstabelle für Motor A:

Diese Wahrheitstabelle zeigt die verschiedenen Zustände von Motor A basierend auf den Werten der Eingangspins A-1A und A-1B. Sie gibt die Drehrichtung (im Uhrzeigersinn oder gegen den Uhrzeigersinn), das Bremsen oder Anhalten von Motor A an.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Zustand von Motor A
    * - 1
      - 0
      - Dreht im Uhrzeigersinn
    * - 0
      - 1
      - Dreht gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremst
    * - 1
      - 1
      - Stoppt

Beispiel
---------------------------
* :ref:`uno_lesson31_pump` (Arduino UNO)
* :ref:`esp32_lesson31_pump` (ESP32)
* :ref:`pico_lesson31_pump` (Raspberry Pi Pico)
* :ref:`pi_lesson31_pump` (Raspberry Pi)

* :ref:`uno_lesson34_motor` (Arduino UNO)
* :ref:`esp32_lesson34_motor` (ESP32)
* :ref:`pico_lesson34_motor` (Raspberry Pi Pico)
* :ref:`pi_lesson34_motor` (Raspberry Pi)

* :ref:`uno_lesson07_speed` (Arduino UNO)
* :ref:`pi_lesson07_speed` (Raspberry Pi)

* :ref:`uno_lesson39_soap_dispenser` (Arduino UNO)
* :ref:`uno_plant_monitor` (Arduino UNO)
* :ref:`esp32_soap_dispenser` (ESP32)
* :ref:`esp32_plant_monitor` (ESP32)
