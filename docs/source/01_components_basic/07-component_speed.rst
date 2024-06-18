.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_speed:

Infrarot-Geschwindigkeitssensor-Modul
========================================

.. image:: img/07_speed_sensor_module.png
    :width: 300
    :align: center

Das Infrarot-Geschwindigkeitssensor-Modul ist ein IR-Zähler, der einen IR-Sender und -Empfänger hat. Wenn ein Hindernis zwischen diesen Sensoren platziert wird, wird ein Signal an den Mikrocontroller gesendet. Das Modul kann in Verbindung mit einem Mikrocontroller zur Motorgeschwindigkeitsmessung, Impulszählung, Positionsbegrenzung usw. verwendet werden.

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang (3,3V oder 5V) von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **OUT**: Digitalausgang. Wenn der Geschwindigkeitssensor blockiert ist, gibt er ein hohes Signal aus; wenn er nicht blockiert ist, gibt er ein niedriges Signal aus.

Funktionsprinzip
---------------------------

Das Geschwindigkeitssensor-Modul wird hauptsächlich verwendet, um Änderungen der Drehzahl oder Geschwindigkeit zu erkennen. Wenn ein Objekt am H2010-Sensor vorbeifährt, erzeugt es ein Impulssignal. Der integrierte LM393-Komparator im Modul vergleicht dieses Impulssignal mit einem voreingestellten Schwellenwert und erzeugt ein stabiles Hochpegelausgangssignal.

Das Infrarot-Geschwindigkeitssensor-Modul verfügt über eine H2010-Photodiode, die aus einem Fototransistor und einem Infrarot-Lichtsender besteht, die in einem 10 cm breiten schwarzen Kunststoffgehäuse verpackt sind.

.. image:: img/07_speed_sensor_module_2.png
    :width: 200
    :align: center

Im Betrieb sendet die Infrarot-Leuchtdiode kontinuierlich Infrarotlicht (unsichtbares Licht), und das lichtempfindliche Triod wird leitend, wenn es dieses empfängt.

.. image:: img/07_speed_sensor_module_3.png
    :width: 900
    :align: center

.. raw:: html

   <br/>

Schaltplan
---------------------------

.. image:: img/07_speed_sensor_module_schematic.png
    :width: 900%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson07_speed` (Arduino UNO)
* :ref:`esp32_lesson07_speed` (ESP32)
* :ref:`pico_lesson07_speed` (Raspberry Pi Pico)
* :ref:`pi_lesson07_speed` (Raspberry Pi)
