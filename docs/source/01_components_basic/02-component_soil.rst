.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_soil:

Kapazitiver Bodenfeuchtesensor
=====================================

.. image:: img/02_soil_mositure_module.png
    :width: 600
    :align: center

.. raw:: html

   <br/>

Der Bodenfeuchtesensor ist ein Sensor, der in der Landwirtschaft zur Messung des Feuchtigkeitsgehalts des Bodens verwendet wird. Er hilft Landwirten, die Bodenfeuchtigkeit zu überwachen und den optimalen Zeitpunkt zur Bewässerung ihrer Pflanzen zu bestimmen.
Dieser kapazitive Bodenfeuchtesensor unterscheidet sich von den auf dem Markt erhältlichen resistiven Sensoren, indem er das Prinzip der kapazitiven Induktion zur Erkennung der Bodenfeuchtigkeit nutzt. Dadurch wird das Problem der leichten Korrosion bei resistiven Sensoren vermieden und die Lebensdauer des Sensors erheblich verlängert.

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **AUOT**: Analogausgang. Je höher der Feuchtigkeitsgehalt des Bodens, desto niedriger der Analogausgangswert.

Funktionsprinzip
---------------------------

Dieser kapazitive Bodenfeuchtesensor unterscheidet sich von den meisten resistiven Sensoren auf dem Markt, da er das Prinzip der kapazitiven Induktion zur Erkennung der Bodenfeuchtigkeit nutzt. Dadurch wird das Problem der hohen Korrosionsanfälligkeit resistiver Sensoren vermieden und die Lebensdauer erheblich verlängert.

Er besteht aus korrosionsbeständigen Materialien und hat eine hervorragende Lebensdauer. Stecken Sie ihn in den Boden um die Pflanzen und überwachen Sie die Bodenfeuchtigkeit in Echtzeit. Das Modul enthält einen integrierten Spannungsregler, der den Betrieb in einem Spannungsbereich von 3,3 bis 5,5 V ermöglicht. Es ist ideal für Mikrocontroller mit 3,3 V und 5 V Versorgungsspannung.

Das Hardware-Schaltbild des kapazitiven Bodenfeuchtesensors ist unten dargestellt.

.. image:: img/02_soil_schematic_2.png
    :width: 90%
    :align: center

.. raw:: html

   <br/>

Es gibt einen festen Frequenzoszillator, der mit einem 555-Timer-IC gebaut ist. Das erzeugte Rechtecksignal wird dann an den Sensor wie ein Kondensator angelegt. Für das Rechtecksignal hat der Kondensator jedoch eine bestimmte Reaktanz oder, um es einfach auszudrücken, einen Widerstand mit einem rein ohmschen Widerstand (10k-Widerstand an Pin 3), um einen Spannungsteiler zu bilden.

Je höher die Bodenfeuchtigkeit, desto höher die Kapazität des Sensors. Dadurch hat das Rechtecksignal eine geringere Reaktanz, was die Spannung auf der Signalleitung reduziert, und der Wert des analogen Eingangs durch den Mikrocontroller wird kleiner.

Beispiel
---------------------------
* :ref:`uno_lesson02_soil_moisture` (Arduino UNO)
* :ref:`esp32_lesson02_soil_moisture` (ESP32)
* :ref:`pico_lesson02_soil_moisture` (Raspberry Pi Pico)
* :ref:`pi_lesson02_soil_moisture` (Raspberry Pi Pi)

* :ref:`uno_plant_monitor` (Arduino UNO)
* :ref:`esp32_plant_monitor` (ESP32)
