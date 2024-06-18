.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_touch:

Touch-Sensormodul
==========================

.. image:: img/22_touch_sensor_moudle.png
    :width: 200
    :align: center

Der Touch-Schalter-Sensor (auch Touch-Button oder Touch-Schalter genannt) wird häufig zur Steuerung von Geräten verwendet (z.B. berührbare Lampe). Er hat die gleiche Funktion wie ein Knopf und wird in vielen neuen Geräten anstelle des Knopfs verwendet, da er das Produkt optisch ansprechender macht.

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **IO**: Digitalausgang. Hoher Pegel bei Berührung, niedriger Pegel ohne Berührung.

Funktionsprinzip
---------------------------
Dieses Modul ist ein kapazitiver Touch-Schalter auf Basis eines Touch-Sensor-ICs (TTP223B). Im Normalzustand gibt das Modul ein niedriges Signal aus und verbraucht wenig Strom; wenn ein Finger die entsprechende Position berührt, gibt das Modul ein hohes Signal aus und wird wieder niedrig, nachdem der Finger losgelassen wird.

So funktioniert der kapazitive Touch-Schalter:

Ein kapazitiver Touch-Schalter besteht aus verschiedenen Schichten - einer oberen Isolierschicht, gefolgt von einer Berührungsplatte, einer weiteren Isolierschicht und dann einer Erdungsplatte.

.. image:: img/22_touch_sensor_moudle_principle.jpeg
    :width: 400
    :align: center

.. raw:: html

    <br/>

In der Praxis kann ein kapazitiver Sensor auf einer doppelseitigen Leiterplatte hergestellt werden, wobei eine Seite als Berührungssensor und die gegenüberliegende Seite als Erdungsplatte des Kondensators dient. Wenn Spannung an diese Platten angelegt wird, laden sich die beiden Platten auf. Im Gleichgewichtszustand haben die Platten die gleiche Spannung wie die Stromquelle.

Die Berührungsdetektionsschaltung enthält einen Oszillator, dessen Frequenz von der Kapazität des Touchpads abhängt. Wenn ein Finger in die Nähe des Touchpads kommt, führt die zusätzliche Kapazität zu einer Änderung der Frequenz dieses internen Oszillators. Die Detektionsschaltung verfolgt die Oszillatorfrequenz in festgelegten Intervallen, und wenn die Verschiebung den Schwellenwert überschreitet, löst die Schaltung ein Tastenereignis aus.

Schaltplan
---------------------------

.. image:: img/22_touch_sensor_moudle_schematic.png
    :width: 100%
    :align: center

.. raw:: html

    <br/>

Beispiel
---------------------------
* :ref:`uno_lesson22_touch_sensor` (Arduino UNO)
* :ref:`esp32_lesson22_touch_sensor` (ESP32)
* :ref:`pico_lesson22_touch_sensor` (Raspberry Pi Pico)
* :ref:`pi_lesson22_touch_sensor` (Raspberry Pi)

* :ref:`uno_touch_toggle_light` (Arduino UNO)
* :ref:`esp32_touch_toggle_light` (ESP32)
