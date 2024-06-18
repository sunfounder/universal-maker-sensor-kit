.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_flame:

Flammensensor-Modul
==========================

.. image:: img/03_flame_module.png
    :width: 400
    :align: center

.. raw:: html

   <br/>

.. tip::
   Halten Sie einen bestimmten Abstand zwischen dem Sensor und der Flamme, um Schäden durch hohe Temperaturen zu vermeiden.

.. note::
   **Hinweis**: Aufgrund eines Produktionsfehlers können einige der Flammensensoren in unseren Kits die 3-Pin-Version sein, die über keinen AO (Analogausgang) verfügt. Diese Version ist für die meisten Projekte geeignet und beeinträchtigt die allgemeine Verwendung nicht. Falls Sie dennoch die 4-Pin-Version benötigen, kontaktieren Sie bitte unseren Kundenservice unter service@sunfounder.com. Wir werden Ihnen kostenlos einen Ersatz zur Verfügung stellen, um Ihren Anforderungen gerecht zu werden.

Der Flammensensor ist ein Sensor, der das Vorhandensein von Feuer oder Flammen erkennen kann. Der Flammensensor arbeitet auf der Basis von Infrarotstrahlung. Die IR-Photodiode erkennt die IR-Strahlung von jedem heißen Körper. Dieser Wert wird dann mit einem Sollwert verglichen. Sobald die Strahlung den Schwellenwert erreicht, ändert der Sensor entsprechend seinen Ausgang. Er wird häufig in Brandmeldesystemen in Haushalten und Industrie eingesetzt.

Der Flammensensor arbeitet nach dem Prinzip der Infrarot (IR)-Erkennung. Der Sensor verfügt über einen IR-Empfänger, der die von Flammen ausgestrahlte IR-Strahlung erkennt. Wenn Feuer brennt, sendet es eine kleine Menge Infrarotlicht aus, dieses Licht wird von der Photodiode (IR-Empfänger) auf dem Sensormodul empfangen. Dann verwenden wir einen Operationsverstärker, um eine Spannungsänderung über dem IR-Empfänger zu überprüfen, sodass bei Branderkennung der Ausgangspin (DO) 0V (LOW) liefert und bei Nicht-Erkennung 5V (HIGH) anliegt.

Spezifikation
---------------------------
* Versorgungsspannung: 3,3V - 5V
* PCB-Größe: 31 x 14mm
* Ausgangssignaltyp: DO und AO
* Erkennungswinkel: 60 Grad

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **DO**: Digitalausgang. Es zeigt das Vorhandensein einer Flamme an. Wenn die Infrarotstrahlung den Schwellenwert (eingestellt durch das Potentiometer) überschreitet, wird DO LOW; andernfalls bleibt es HIGH.
* **AO**: Analogausgang. Es erzeugt eine Ausgangsspannung, die umgekehrt proportional zur Intensität der Infrarotstrahlung (Flammengröße) ist. Daher führt höhere Infrarotstrahlung zu einer niedrigeren Spannung, während geringere Infrarotstrahlung zu einer höheren Spannung führt.

Schaltplan
---------------------------

.. image:: img/03_flame_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson03_flame` (Arduino UNO)
* :ref:`esp32_lesson03_flame` (ESP32)
* :ref:`pico_lesson03_flame` (Raspberry Pi Pico)
* :ref:`pi_lesson03_flame` (Raspberry Pi)
* :ref:`uno_iot_flame` (Arduino UNO)
