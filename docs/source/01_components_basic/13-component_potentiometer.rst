.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_potentiometer:

Potentiometermodul
==========================

.. image:: img/13_potentiomete_module.png
    :width: 300
    :align: center

.. raw:: html

   <br/>

Das Potentiometermodul ist ein elektronisches Bauteil, dessen Widerstand sich je nach Position des Drehknopfes ändert. Es kann für verschiedene Zwecke verwendet werden, wie z.B. zur Lautstärkeregelung eines Lautsprechers, zur Helligkeitssteuerung einer LED oder zur Geschwindigkeitsregelung eines Motors.

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **AO**: Analogausgang.

Funktionsprinzip
---------------------------
Ein Potentiometer ist ebenfalls ein Widerstandselement mit drei Anschlüssen, dessen Widerstandswert entsprechend einer regelmäßigen Variation angepasst werden kann.

Potentiometer gibt es in verschiedenen Formen, Größen und Werten, aber sie haben alle folgende Gemeinsamkeiten:

- Sie haben drei Anschlüsse (oder Verbindungspunkte).
- Sie verfügen über einen Knopf, eine Schraube oder einen Schieber, der bewegt werden kann, um den Widerstand zwischen dem mittleren Anschluss und einem der äußeren Anschlüsse zu variieren.
- Der Widerstand zwischen dem mittleren Anschluss und einem der äußeren Anschlüsse variiert von 0 Ω bis zum maximalen Widerstand des Potentiometers, je nachdem wie der Knopf, die Schraube oder der Schieber bewegt wird.

Hier ist das Schaltsymbol des Potentiometers.

.. image:: img/13_potentiometer_symbol_2.png
    :width: 200
    :align: center

Die Funktionen des Potentiometers in der Schaltung sind wie folgt:

#. Als Spannungsteiler
    Ein Potentiometer ist ein kontinuierlich verstellbarer Widerstand. Wenn Sie die Achse oder den Schieber des Potentiometers verstellen, wird der bewegliche Kontakt auf dem Widerstand gleiten. In diesem Fall kann eine Spannung abhängig von der an das Potentiometer angelegten Spannung und dem Winkel, um den sich der bewegliche Arm gedreht hat, oder der zurückgelegten Strecke ausgegeben werden.

#. Als veränderbarer Widerstand (Rheostat)
    Wenn das Potentiometer als veränderbarer Widerstand verwendet wird, verbinden Sie den mittleren Anschluss und einen der anderen beiden Anschlüsse in der Schaltung. Auf diese Weise erhalten Sie einen sanft und kontinuierlich veränderbaren Widerstandswert innerhalb des Verstellbereichs des beweglichen Kontakts.

#. Als Stromregler
    Wenn das Potentiometer als Stromregler fungiert, muss der Schiebekontaktanschluss als einer der Ausgangsanschlüsse verbunden sein.


Schaltplan
---------------------------

.. image:: img/13_potentiomete_module_schematic.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson13_potentiometer` (Arduino UNO)
* :ref:`esp32_lesson13_potentiometer` (ESP32)
* :ref:`pico_lesson13_potentiometer` (Raspberry Pi Pico)
* :ref:`pi_lesson13_potentiometer` (Raspberry Pi)

* :ref:`uno_potentiometer_scale_value` (Arduino UNO)
* :ref:`esp32_potentiometer_scale_value` (ESP32)
