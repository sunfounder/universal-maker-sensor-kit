.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_max30102:

Pulsoximeter- und Herzfrequenzsensormodul (MAX30102)
===============================================================

.. image:: img/14_gy_max30102_module.png
    :width: 200
    :align: center

.. raw:: html

   <br/>

Der MAX30102 ist ein fortschrittliches Sensormodul zur Überwachung der Herzfrequenz und des Sauerstoffgehalts im Blut (SpO2). Hergestellt von Maxim Integrated, kombiniert er Pulsoximetrie und Herzfrequenzüberwachung in einem kompakten Gehäuse und ist damit eine beliebte Wahl für tragbare Gesundheits- und Fitnessanwendungen.

Spezifikation
---------------------------
* Chiptyp: MAX30102
* LED-Spitzenwellenlänge: 660nm/880nm
* Versorgungsspannung: 3,3V oder 5V
* Erkennungssignaltyp: Optisches Reflexionssignal (PPG)
* Ausgangsschnittstelle: I2C-Schnittstelle
* PCB-Größe: 14 x 14mm
* Betriebstemperatur: -40 ~ +85℃

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **SCL**: Serieller Taktpin für die I2C-Schnittstelle.
* **SDA**: Serieller Datenpin für die I2C-Schnittstelle.
* **INT**: Der Interrupt-Pin des IC.

Funktionsprinzip
---------------------------

Der MAX30102 ist ein Sensor, der einen Pulsoximeter und einen Herzfrequenzmesser kombiniert. Es handelt sich um einen optischen Sensor, der die Absorption des pulsierenden Bluts durch einen Photodetektor nach dem Aussenden von Licht mit zwei Wellenlängen von zwei LEDs – einer roten und einer infraroten – misst. Diese spezielle LED-Farbkombination ermöglicht das Ablesen der Daten mit der Fingerspitze.

Der MAX30102 funktioniert, indem beide Lichter auf den Finger oder das Ohrläppchen (oder im Wesentlichen überall dort, wo die Haut nicht zu dick ist, damit beide Lichter das Gewebe leicht durchdringen können) gerichtet werden und die Menge des reflektierten Lichts mit einem Photodetektor gemessen wird. Diese Methode der Pulserkennung durch Licht wird als Photoplethysmogramm bezeichnet.

Die Funktionsweise des MAX30102 lässt sich in zwei Teile unterteilen: Herzfrequenzmessung und Pulsoximetrie (Messung des Sauerstoffgehalts im Blut).

Herzfrequenzmessung
^^^^^^^^^^^^^^^^^^^^^^^^^^
Das sauerstoffreiche Hämoglobin (HbO2) im arteriellen Blut hat die Eigenschaft, IR-Licht zu absorbieren. Je röter das Blut (je höher der Hämoglobingehalt), desto mehr IR-Licht wird absorbiert. Wenn das Blut bei jedem Herzschlag durch den Finger gepumpt wird, ändert sich die Menge des reflektierten Lichts, wodurch eine sich ändernde Wellenform am Ausgang des Photodetektors entsteht. Durch kontinuierliches Bestrahlen mit Licht und Ablesen der Photodetektorwerte erhält man schnell eine Herzfrequenz (HR)-Pulsanzeige.

Pulsoximetrie
^^^^^^^^^^^^^^^^^^^^
Die Pulsoximetrie basiert auf dem Prinzip, dass die Menge des absorbierten roten und infraroten Lichts je nach Sauerstoffgehalt im Blut variiert.

Beispiel
---------------------------
* :ref:`uno_lesson14_max30102` (Arduino UNO)
* :ref:`esp32_lesson14_max30102` (ESP32)
* :ref:`pico_lesson14_max30102` (Raspberry Pi Pico)
* :ref:`pi_lesson14_max30102` (Raspberry Pi)

* :ref:`uno_lesson41_heartrate_monitor` (Arduino UNO)
* :ref:`esp32_heartrate_monitor` (ESP32)
