 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_ir_obstacle:

IR-Hinderniserkennungssensor-Modul
=====================================

.. image:: img/08_IR_obstacle_module.png
    :width: 400
    :align: center

.. raw:: html

   <br/>

Dieses Modul kann sich an Umgebungslicht anpassen und enthält ein Paar Infrarot-Sende- und Empfangsröhren. Die Senderröhre sendet Infrarotlicht mit einer bestimmten Frequenz aus, und wenn die Erkennungsrichtung auf ein Hindernis (reflektierende Oberfläche) trifft, nimmt die Empfangsröhre das reflektierte Infrarotlicht auf. Nach der Verarbeitung durch die Vergleicherschaltung leuchtet die grüne Anzeige auf, und gleichzeitig erzeugt die Signalausgabeschnittstelle ein digitales Signal (ein Niedrigpegelsignal). Die Erkennungsentfernung kann mit einem Potentiometerknopf eingestellt werden.

Spezifikation
---------------------------
* Versorgungsspannung: 3,3V - 5V
* PCB-Größe: 32 x 14mm
* Ausgangssignaltyp: Digitalausgang
* Erkennungswinkel: 35°
* Erkennungsentfernung: 2～30cm

Pinbelegung
---------------------------
* **VCC**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **OUT**: Digitalausgang. Gibt ein hohes Signal aus, wenn kein Hindernis vorhanden ist, und ein niedriges Signal, wenn ein Hindernis erkannt wird. Die Erkennungsentfernung der Hindernisse kann durch das Potentiometer am Modul eingestellt werden.

Funktionsprinzip
---------------------------
Ein Hinderniserkennungssensor besteht hauptsächlich aus einem Infrarotsender, einem Infrarotempfänger und einem Potentiometer. Entsprechend der reflektierenden Eigenschaft eines Objekts schwächt sich der ausgesendete Infrarotstrahl ohne Hindernis mit zunehmender Entfernung ab und verschwindet schließlich. Wenn ein Hindernis vorhanden ist, wird der Strahl bei Kontakt mit dem Hindernis zum Infrarotempfänger zurück reflektiert. Der Infrarotempfänger erkennt dieses Signal und bestätigt ein Hindernis davor. Der Erkennungsbereich kann durch das eingebaute Potentiometer angepasst werden.

.. image:: img/08_IR_obstacle_module_1.png
    :width: 600
    :align: center

.. raw:: html

   <br/>

Schaltplan
---------------------------

.. image:: img/08_ir_obstacle_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson08_ir_obstacle_avoidance` (Arduino UNO)
* :ref:`esp32_lesson08_ir_obstacle_avoidance` (ESP32)
* :ref:`pico_lesson08_ir_obstacle_avoidance` (Raspberry Pi Pico)
* :ref:`pi_lesson08_ir_obstacle_avoidance` (Raspberry Pi)

* :ref:`uno_lesson39_soap_dispenser` (Arduino UNO)
* :ref:`esp32_soap_dispenser` (ESP32)
