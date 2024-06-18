.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_hall:

Hallsensor-Modul
=====================================

.. image:: img/06_hall_sensor_module.png
    :width: 300
    :align: center

.. raw:: html

   <br/>

Das Hallsensor-Modul ist ein berührungsloser Magnetsensor, der ein elektrisches Signal proportional zum angelegten Magnetfeld erzeugt. Es kann sowohl die Nord- als auch die Südpolung eines Magnetfelds sowie die relative Stärke des Feldes messen. Es wird zur Erkennung von Magnetfeldern verwendet und fungiert wie ein Magnetdetektor, der nahegelegene Magnete identifizieren kann. Dieser Sensor ist in verschiedenen Projekten nützlich, wie z.B. beim Entwickeln von Türalarmsystemen oder beim Messen der Geschwindigkeit rotierender Objekte.

Funktionsprinzip
---------------------------

Das Funktionsprinzip des Hallsensor-Moduls basiert auf dem |link_hall_effect|, entdeckt von Edwin Hall. Einfach ausgedrückt: Wenn Strom durch einen Leiter (wie einen Draht) fließt und sich ein Magnetfeld darum befindet, drückt das Magnetfeld die beweglichen Elektronen im Leiter zur Seite. Dadurch entsteht ein Spannungsunterschied über den Leiter - dies ist der Hall-Effekt.

Im Hallsensor-Modul beeinflusst das Magnetfeld die Elektronen im Halbleitermaterial im Inneren des Sensors, wenn sich ein Magnet nähert. Dies ändert die Spannung über den Sensor, die der Sensor erkennt. Der Arduino kann diese Spannungsänderung lesen und verstehen, ob sich ein Magnet in der Nähe befindet und wie stark sein Magnetfeld ist.

.. image:: img/06_hall_49e.jpg
    :width: 60%
    :align: center

.. raw:: html

   <br/>

Das Hallsensor-Modul ist mit einem 49E-Linearen Hall-Effekt-Sensor ausgestattet, der sowohl die Nord- als auch die Südpolung eines Magnetfelds sowie die relative Stärke des Feldes messen kann. Der Ausgangspin liefert eine analoge Darstellung, die das Vorhandensein und die Stärke eines Magnetfelds sowie dessen Polarität (Nord oder Süd) anzeigt. Wenn kein Magnetfeld vorhanden ist, gibt der 49E eine Spannung von etwa der Hälfte der Versorgungsspannung aus. Wenn der Südpol eines Magneten nahe der beschrifteten Seite des 49E (die Seite mit dem Text) platziert wird, steigt die Ausgangsspannung proportional zur Stärke des angelegten Magnetfelds linear an. Umgekehrt sinkt die Ausgangsspannung linear, wenn ein Nordpol in der Nähe dieser Seite platziert wird.

Beispielsweise beträgt die Ausgangsspannung des 49E bei einer Versorgungsspannung von 5V und ohne Magnetfeld etwa 2,5V. In diesem Szenario würde das Platzieren des Südpols eines starken Magneten in der Nähe die Ausgangsspannung auf etwa 4,2V erhöhen; während das Platzieren des Nordpols in der Nähe die Spannung je nach Stärke des Magnetfelds auf etwa 0,86V senken würde.

Beispiel
---------------------------
* :ref:`uno_lesson06_hall_sensor` (Arduino UNO)
* :ref:`esp32_lesson06_hall_sensor` (ESP32)
* :ref:`pico_lesson06_hall_sensor` (Raspberry Pi Pico)
* :ref:`pi_lesson06_hall_sensor` (Raspberry Pi Pi)
