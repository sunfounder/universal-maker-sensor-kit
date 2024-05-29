 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_gas:

Gas-/Rauchsensormodul (MQ2)
=====================================

.. image:: img/04_mq2_gas_module.png
    :width: 350
    :align: center

.. tip::
   Der MQ2 ist ein sensor, der durch Heizung betrieben wird und normalerweise vor der Verwendung vorgeheizt werden muss. Während der Vorheizphase zeigt der Sensor typischerweise hohe Werte an, die allmählich abnehmen, bis sie sich stabilisieren.

Der MQ-2-Sensor ist ein vielseitiger Gassensor, der eine breite Palette von Gasen erkennen kann, darunter Alkohol, Kohlenmonoxid, Wasserstoff, Isobutan, Flüssiggas, Methan, Propan und Rauch. Er ist bei Anfängern aufgrund seiner niedrigen Kosten und einfachen Handhabung beliebt.

Funktionsprinzip
---------------------------
Der MQ-2-Sensor arbeitet nach dem Prinzip der Widerstandsänderung in Gegenwart verschiedener Gase. Wenn das Zielgas mit dem erhitzten MOS (Metalloxid-Halbleiter)-Material in Kontakt kommt, werden Oxidations- oder Reduktionsreaktionen ausgelöst, die den Widerstand des MOS-Materials verändern. **Es ist bemerkenswert, dass der MQ2-Gassensor in der Lage ist, mehrere Gase zu erkennen, aber nicht zwischen ihnen unterscheiden kann.** Dies ist eine häufige Eigenschaft der meisten Gassensoren.

Der Sensor verfügt über ein eingebautes Potentiometer, mit dem Sie den Schwellenwert des digitalen Ausgangs (D0) einstellen können. Wenn die Gaskonzentration in der Luft einen bestimmten Schwellenwert überschreitet, ändert sich der Widerstand des Sensors. Diese Widerstandsänderung wird dann in ein elektrisches Signal umgewandelt, das von einem Arduino-Board gelesen werden kann.

Kalibrierung des MQ2-Gassensors
----------------------------------
Da der MQ2 ein heizgetriebener Sensor ist, kann die Kalibrierung des Sensors abweichen, wenn er über einen längeren Zeitraum gelagert wird.
Bei der ersten Verwendung nach längerer Lagerung (einem Monat oder länger) muss der Sensor 24-48 Stunden vollständig vorgeheizt werden, um maximale Genauigkeit zu gewährleisten.
Wenn der Sensor kürzlich verwendet wurde, dauert es nur 5-10 Minuten, um vollständig aufzuheizen. Während der Aufwärmphase zeigt der Sensor typischerweise hohe Werte an, die allmählich abnehmen, bis sie sich stabilisieren.

Spezifikation
---------------------------
* Modell: MQ2
* Versorgungsspannung: 5V
* PCB-Größe: 32 x 20mm
* Ausgangssignaltyp: DO und AO
* Erkennungskonzentration: 300 bis 10000 ppm
* Vorheizdauer: über 24 Stunden (beim ersten Mal)
* Erkennbares Gas: LPG, Alkohol, Propan, Wasserstoff, CO und sogar Methan

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **DO**: Digitalausgang. Es zeigt das Vorhandensein von brennbaren Gasen an. Wenn die Gaskonzentration den Schwellenwert (wie durch das Potentiometer eingestellt) überschreitet, wird D0 LOW; andernfalls ist es HIGH.
* **AO**: Analogausgang. Es erzeugt eine analoge Ausgangsspannung, die proportional zur Gaskonzentration ist, sodass eine höhere Konzentration zu einer höheren Spannung und eine niedrigere Konzentration zu einer niedrigeren Spannung führt.

Beispiel
---------------------------
* :ref:`uno_lesson04_mq2` (Arduino UNO)
* :ref:`esp32_lesson04_mq2` (ESP32)
* :ref:`pico_lesson04_mq2` (Raspberry Pi Pico)
* :ref:`pi_lesson04_mq2` (Raspberry Pi)

* :ref:`uno_lesson38_gas_leak_alarm` (Arduino UNO)
* :ref:`esp32_gas_leak_alarm` (ESP32)
