.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_vibration:

Vibrationssensormodul (SW-420)
=====================================

.. image:: img/24_sw420_vibration_module.png
    :width: 400
    :align: center

Der SW-420-Vibrationssensor ist ein Modul, das Vibrationen oder Erschütterungen auf einer Oberfläche erkennt. Er kann für verschiedene Zwecke verwendet werden, wie z.B. das Erkennen von Türklopfen, Maschinenfehlern, Autokollisionen oder Alarmsystemen. Er arbeitet in einem Spannungsbereich von 3,3 V bis 5 V und verfügt über drei Peripheriegeräte: zwei LEDs (eine für den Betriebsstatus und die andere für den Sensorausgang) und ein Potentiometer, das zur Einstellung des Vibrationsschwellwerts verwendet werden kann.

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **DO**: Digitalausgang. Während des normalen Betriebs gibt der Sensor ein Logik-Tief-Signal aus. Bei Erkennung einer Vibration gibt der Sensor ein Logik-Hoch-Signal aus.

Funktionsprinzip
---------------------------
Das SW-420-Vibrationssensormodul besteht aus einem SW-420-Vibrationsschalter und einem LM393-Spannungskomparator. Ein SW-420-Vibrationsschalter ist ein Gerät, das eine Feder und einen Stab in einem Rohr enthält. Wenn der Schalter einer Vibration ausgesetzt wird, berührt die Feder den Stab und schließt den Stromkreis. Der Vibrationssensor im Modul erkennt diese Schwingungen und wandelt sie in elektrische Signale um. Der LM393-Komparatorchip vergleicht diese Signale dann mit einer Referenzspannung, die vom Potentiometer eingestellt wird. Wenn die Amplitude des Signals diese Referenzspannung überschreitet, geht der Ausgang des Komparators auf hoch (1), andernfalls auf niedrig (0).

Schaltplan
---------------------------

.. image:: img/24_sw420_vibration_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson24_vibration_sensor` (Arduino UNO)
* :ref:`esp32_lesson24_vibration_sensor` (ESP32)
* :ref:`pico_lesson24_vibration_sensor` (Raspberry Pi Pico)
* :ref:`pi_lesson24_vibration_sensor` (Raspberry Pi)

* :ref:`uno_digital_dice` (Arduino UNO)
* :ref:`uno_iot_vib_alert_system` (Arduino UNO)
* :ref:`esp32_digital_dice` (ESP32)
