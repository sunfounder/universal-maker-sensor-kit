.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_ultrasonic:

Ultraschallsensormodul (HC-SR04)
=====================================

.. image:: img/23_ultrasonic.png
    :width: 350
    :align: center

.. raw:: html

   <br/>

Das Ultraschallmodul (HC-SR04) ist ein Sensor, der Entfernungen zwischen 2 cm und 400 cm mittels Ultraschallwellen messen kann. Es wird häufig in Robotik- und Automatisierungsprojekten verwendet, um Objekte zu erkennen und Entfernungen zu messen. Das Modul besteht aus einem Ultraschallsender und -empfänger, die zusammenarbeiten, um Ultraschallwellen zu senden und zu empfangen.


.. _cpn_ultrasonic_principle:

Funktionsprinzip
---------------------------
Das Modul enthält Ultraschallsender, -empfänger und eine Steuerschaltung. Die grundlegenden Prinzipien sind wie folgt:

#. Verwenden Sie ein IO-Flip-Flop, um ein Hochpegelsignal von mindestens 10 µs zu verarbeiten.

#. Das Modul sendet automatisch acht 40 kHz Impulse und erkennt, ob ein Pulsrücksignal zurückkehrt.

#. Wenn das Signal zurückkehrt, wird der Hochpegel ausgegeben. Die Dauer des Hochpegelsignals ist die Zeit vom Senden der Ultraschallwelle bis zu deren Rückkehr. Hier gilt: Testentfernung = (Hochzeit x Schallgeschwindigkeit (340 m/s)) / 2.

Das Zeitdiagramm ist unten dargestellt.

.. image:: img/23_ultrasonic_principle.png

Sie müssen nur einen kurzen 10 µs Impuls für den Trigger-Eingang liefern, um die Messung zu starten. Das Modul sendet dann einen 8-Zyklen-Ultraschallimpuls mit 40 kHz aus und erhöht sein Echo. Sie können die Entfernung durch das Zeitintervall zwischen dem Senden des Triggersignals und dem Empfang des Echosignals berechnen.

.. note::
    Es wird empfohlen, einen Messzyklus von über 60 ms zu verwenden, um Kollisionen zwischen dem Triggersignal und dem Echosignal zu verhindern.


Formel: 
    - µs / 58 = Zentimeter 
    - µs / 148 = Zoll
    - Entfernung = Hochpegelsignalzeit \* Schallgeschwindigkeit (340 m/s) / 2; 


Beispiel
---------------------------
* :ref:`uno_lesson23_ultrasonic` (Arduino UNO)
* :ref:`esp32_lesson23_ultrasonic` (ESP32)
* :ref:`pico_lesson23_ultrasonic` (Raspberry Pi Pico)
* :ref:`pi_lesson23_ultrasonic` (Raspberry Pi)

* :ref:`uno_lesson37_trashcan` (Arduino UNO)

* :ref:`esp32_trashcan` (ESP32)
