.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_water_level:

Wassersensor-Modul
=====================================

.. image:: img/25_water_leve_module.png
    :width: 450
    :align: center

.. raw:: html

   <br/>

Der Wassersensor ist ein kostengünstiges, benutzerfreundliches Gerät, das kompakt und leicht ist. Er verwendet freiliegende parallele Leiterbahnen, um die Größe von Wassertropfen oder das Volumen zu messen und so den Wasserstand zu bestimmen. Dieser Sensor wandelt Wasserstände mühelos in analoge Signale um, die von Programmen zur Auslösung von Wasserstandsalarms genutzt werden können. Sein geringer Stromverbrauch und seine hohe Empfindlichkeit sind ebenfalls bemerkenswerte Merkmale.

Spezifikation
---------------------------
* Versorgungsspannung: 3,3V oder 5V
* PCB-Größe: 22 x 60mm
* Betriebstemperaturbereich: 10℃ - 30℃
* Arbeitsfeuchtigkeitsbereich: 10% - 90%

Pinbelegung
---------------------------
* **V**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **G**: Masseanschluss.
* **A**: Analogausgang. Je höher der Wasserstand, desto größer die Ausgangsspannung.

Schaltplan
---------------------------

.. image:: img/25_water_leve_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson25_water_level` (Arduino UNO)
* :ref:`esp32_lesson25_water_level` (ESP32)
* :ref:`pico_lesson25_water_level` (Raspberry Pi Pico)
* :ref:`pi_lesson25_water_level` (Raspberry Pi)
