.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_raindrop:

Regensensor-Modul
==========================

.. image:: img/15_raindrop_detection_module.png
    :width: 400
    :align: center

Das Regensensor-Modul ist ein Wettersensor, der das Vorhandensein und die Intensität von Regen erkennt. Es besteht aus einer Regensensorplatine mit gedruckten Leiterbahnen, die normalerweise mit einem Komparatormodul gekoppelt ist. Wenn Regentropfen auf die Sensorplatine treffen, entsteht ein leitender Pfad zwischen den Leiterbahnen, der den Widerstand verändert. Diese Änderung wird dann in ein analoges oder digitales Signal umgewandelt, um die Regenintensität anzuzeigen.

Spezifikation
---------------------------
* Versorgungsspannung: 3,3V - 5V
* PCB-Größe: 32 x 14mm
* Ausgangssignaltyp: DO und AO

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **DO**: Digitalausgang. Gibt ein niedriges Signal aus, wenn Regentropfen erkannt werden, und ein hohes Signal, wenn es trocken ist.
* **AO**: Analogausgang. Je mehr Regenwasser, desto kleiner der Analogausgangswert.

Funktionsprinzip
---------------------------
Ein Regensensor ist im Grunde eine Platine, auf der Nickel in Form von Linien aufgetragen ist. Er funktioniert nach dem Prinzip des Widerstands. Wenn kein Regentropfen auf der Platine ist, ist der Widerstand hoch, sodass wir eine hohe Spannung gemäß V=IR erhalten. Wenn ein Regentropfen vorhanden ist, verringert sich der Widerstand, da Wasser ein Leiter für Elektrizität ist und das Vorhandensein von Wasser die Nickellinien parallel verbindet, wodurch der Widerstand und der Spannungsabfall über die Platine verringert werden. Je intensiver der Regen, desto niedriger der Widerstand.

Schaltplan
---------------------------

.. image:: img/15_raindrop_detection_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson15_raindrop` (Arduino UNO)
* :ref:`esp32_lesson15_raindrop` (ESP32)
* :ref:`pico_lesson15_raindrop` (Raspberry Pi Pico)
* :ref:`pi_lesson15_raindrop` (Raspberry Pi)
