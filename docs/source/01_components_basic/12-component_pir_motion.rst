.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_pir_motion:

PIR-Bewegungsmodul (HC-SR501)
=====================================

.. image:: img/12_pir_module.png
    :width: 300
    :align: center

Der Passive Infrarot (PIR)-Bewegungssensor ist ein Sensor, der Bewegungen erkennt. Er wird häufig in Sicherheitssystemen und automatischen Beleuchtungssystemen verwendet. Der Sensor verfügt über zwei Schlitze, die Infrarotstrahlung erkennen. Wenn ein Objekt, wie zum Beispiel eine Person, vor dem Sensor vorbeigeht, erkennt der Sensor eine Veränderung der Infrarotstrahlung und löst ein Ausgangssignal aus.

Spezifikation
---------------------------
* Versorgungsspannung: 5V~20V
* Ausgang: Standardmäßig niedrig; wird hoch, wenn jemand vorbeigeht.
* Verzögerungszeit: 5~200s (einstellbar)
* Blockierzeit: 8s
* Erfassungsbereich: <120°, innerhalb von 7 Metern (einstellbar)
* Auslösemodus: L nicht wiederholbarer Auslösemode, H wiederholbarer Auslösemode
* PCB-Größe: 32 x 24mm
* Linsengröße: 23mm
* Betriebstemperatur: -15~+70℃

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **DO**: Digitalausgang. Standardmäßig niedrig; wird hoch, wenn jemand vorbeigeht.

Funktionsprinzip
---------------------------
Der PIR-Sensor ist in zwei Schlitze unterteilt, die mit einem Differenzverstärker verbunden sind. Immer wenn sich ein stationäres Objekt vor dem Sensor befindet, empfangen beide Schlitze die gleiche Menge an Strahlung und der Ausgang ist null. Sobald sich ein bewegliches Objekt vor dem Sensor befindet, empfängt einer der Schlitze mehr Strahlung als der andere, wodurch der Ausgang hoch oder niedrig schwankt. Diese Änderung der Ausgangsspannung ist das Ergebnis der Bewegungserkennung.

.. image:: img/12_pir_working_principle.jpg
    :width: 500
    :align: center

Nachdem das Sensormodul verdrahtet ist, gibt es eine einminütige Initialisierung. Während der Initialisierung wird das Modul in Abständen von 0~3 Mal auslösen. Danach befindet sich das Modul im Standby-Modus. Halten Sie Lichtquellen und andere Störquellen von der Oberfläche des Moduls fern, um Fehlfunktionen durch Störsignale zu vermeiden. Es ist auch besser, das Modul ohne zu viel Wind zu verwenden, da der Wind den Sensor ebenfalls stören kann.

.. image:: img/12_pir_module_back.png
    :width: 350
    :align: center

.. raw:: html

    <br/><br/>


Abstandseinstellung
^^^^^^^^^^^^^^^^^^^^
Durch Drehen des Potentiometers zur Abstandseinstellung im Uhrzeigersinn erhöht sich der Erfassungsbereich, und der maximale Erfassungsabstand beträgt etwa 0-7 Meter. Durch Drehen gegen den Uhrzeigersinn wird der Erfassungsbereich verkleinert, und der minimale Erfassungsabstand beträgt etwa 0-3 Meter.

Verzögerungseinstellung
^^^^^^^^^^^^^^^^^^^^^^^^^
Durch Drehen des Potentiometers zur Verzögerungseinstellung im Uhrzeigersinn erhöht sich die Erfassungsverzögerung. Die maximale Erfassungsverzögerung kann bis zu 300 Sekunden erreichen. Im Gegensatz dazu verkürzt sich die Verzögerung durch Drehen gegen den Uhrzeigersinn auf ein Minimum von 5 Sekunden.

Zwei Auslösemodi
^^^^^^^^^^^^^^^^^^^^
Durch Verwendung der Jumperkappe können verschiedene Modi ausgewählt werden.

* H: Wiederholbarer Auslösemodus. Nach der Erfassung eines menschlichen Körpers gibt das Modul ein hohes Signal aus. Während der anschließenden Verzögerungszeit bleibt das Ausgangssignal auf hohem Niveau, wenn sich jemand im Erfassungsbereich befindet.
* L: Nicht wiederholbarer Auslösemodus. Gibt ein hohes Signal aus, wenn ein menschlicher Körper erfasst wird. Nach der Verzögerung wechselt das Ausgangssignal automatisch von hoch auf niedrig.

Beispiel
---------------------------
* :ref:`uno_lesson12_pir_motion` (Arduino UNO)
* :ref:`esp32_lesson12_pir_motion` (ESP32)
* :ref:`pico_lesson12_pir_motion` (Raspberry Pi Pico)
* :ref:`pi_lesson12_pir_motion` (Raspberry Pi)

* :ref:`uno_lesson40_motion_triggered_relay` (Arduino UNO)
* :ref:`uno_iot_intrusion_alert_system` (Arduino UNO)
* :ref:`esp32_motion_triggered_relay` (ESP32)
* :ref:`esp32_iot_intrusion_alert_system` (ESP32)
