.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_relay:

5V Relaismodul
==========================

.. image:: img/30_relay_module.png
    :width: 300
    :align: center

.. raw:: html

    <br/>

5V Relaismodule sind Geräte, die Hochspannungs- oder Hochstromgeräte ein- und ausschalten können, indem sie ein 5V Signal vom Arduino verwenden. Sie können verwendet werden, um Geräte wie Lichter, Ventilatoren, Motoren, Magnetspulen usw. zu steuern. Das 5V Relais hat drei Hochspannungsklemmen (NC, C und NO), die mit dem zu steuernden Gerät verbunden werden. Die andere Seite hat drei Niederspannungsanschlüsse (Ground, Vcc und Signal), die mit dem Arduino verbunden werden.

Funktionsprinzip
---------------------------
Ein Relais ist ein Gerät, das eine Verbindung zwischen zwei oder mehr Punkten oder Geräten in Reaktion auf das angelegte Eingangssignal herstellt. Mit anderen Worten, Relais bieten eine Isolierung zwischen dem Controller und den Geräten, die entweder mit Wechselstrom (AC) oder Gleichstrom (DC) betrieben werden können. Sie empfangen jedoch Signale von einem Mikrocontroller, der mit Gleichstrom arbeitet, weshalb ein Relais erforderlich ist, um die Lücke zu überbrücken. Relais sind äußerst nützlich, wenn man eine große Menge Strom oder Spannung mit einem kleinen elektrischen Signal steuern muss.

Jedes Relais besteht aus 5 Teilen:

.. image:: img/30_relay_2.jpeg
    :width: 500
    :align: center

Elektromagnet - Er besteht aus einem Eisenkern, der mit einer Drahtspule umwickelt ist. Wenn Strom durchfließt, wird er magnetisch. Daher wird er Elektromagnet genannt.

Anker - Der bewegliche Magnetstreifen wird als Anker bezeichnet. Wenn Strom durch die Spule fließt, wird sie magnetisiert und erzeugt ein Magnetfeld, das verwendet wird, um die normalerweise offenen (N/O) oder normalerweise geschlossenen (N/C) Kontakte zu schließen oder zu öffnen. Der Anker kann sowohl mit Gleichstrom (DC) als auch mit Wechselstrom (AC) bewegt werden.

Feder - Wenn kein Strom durch die Spule des Elektromagneten fließt, zieht die Feder den Anker weg, sodass der Stromkreis nicht geschlossen werden kann.

Satz von elektrischen Kontakten - Es gibt zwei Kontaktpunkte:

* Normalerweise offen - verbunden, wenn das Relais aktiviert ist, und getrennt, wenn es inaktiv ist.
* Normalerweise geschlossen - nicht verbunden, wenn das Relais aktiviert ist, und verbunden, wenn es inaktiv ist.

Gehäuse - Dies besteht typischerweise aus Kunststoff und bietet strukturelle Unterstützung und Schutz für das Relais.

Das Funktionsprinzip eines Relais ist einfach. Wenn Strom an das Relais angelegt wird, fließt der Strom durch die Steuerwicklung; dadurch wird der Elektromagnet magnetisiert. Dann wird der Anker von der Spule angezogen und zieht den beweglichen Kontakt nach unten, sodass er mit den normalerweise offenen Kontakten verbunden wird. So wird der Stromkreis mit der Last aktiviert. Zum Unterbrechen des Stromkreises wird der bewegliche Kontakt unter der Kraft der Feder zu den normalerweise geschlossenen Kontakten gezogen. Auf diese Weise kann das Ein- und Ausschalten des Relais den Zustand eines Lastkreises steuern.

Schaltplan
---------------------------

.. image:: img/30_relay_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

    <br/>

Beispiel
---------------------------
* :ref:`uno_lesson30_relay_module` (Arduino UNO)
* :ref:`esp32_lesson30_relay_module` (ESP32)
* :ref:`pico_lesson30_relay_module` (Raspberry Pi Pico)
* :ref:`pi_lesson30_relay_module` (Raspberry Pi)

* :ref:`uno_lesson40_motion_triggered_relay` (Arduino UNO)
* :ref:`esp32_motion_triggered_relay` (ESP32)
