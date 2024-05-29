 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_buzzer:

Passiver Summer-Modul
==========================

.. image:: img/32_passive_buzzer_module.png
    :width: 350
    :align: center

.. raw:: html

    <br/>

Der passive Summer ist ein Gerät, das Geräusche erzeugt, wenn ein elektrisches Signal angelegt wird. Er wird als passiv bezeichnet, weil er keinen internen Oszillator hat, um selbstständig Töne zu erzeugen. Stattdessen ist er auf ein externes Signal von einem Mikrocontroller wie dem Arduino angewiesen, um Töne zu erzeugen. Das passive Summer-Modul ist eine kleine elektronische Komponente, die einen passiven Summer und einige zusätzliche Schaltungen enthält, die die Verwendung mit Arduino erleichtern.

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromversorgungseingang von der Hauptsteuerung. 
* **GND**: Erdungsanschluss.
* **I/O**: Über diesen Pin können Sie Steuersignale senden, um den Ton und die Frequenz des Summers zu steuern.

Schaltplan
---------------------------

.. image:: img/32_passive_buzzer_module_schematic.png
    :width: 80%
    :align: center

.. raw:: html

    <br/>

Beispiel
---------------------------
* :ref:`uno_lesson32_passive_buzzer` (Arduino UNO)
* :ref:`esp32_lesson32_passive_buzzer` (ESP32)
* :ref:`pico_lesson32_passive_buzzer` (Raspberry Pi Pico)
* :ref:`pi_lesson32_passive_buzzer` (Raspberry Pi)

* :ref:`uno_lesson38_gas_leak_alarm` (Arduino UNO)
* :ref:`esp32_gas_leak_alarm` (ESP32)
