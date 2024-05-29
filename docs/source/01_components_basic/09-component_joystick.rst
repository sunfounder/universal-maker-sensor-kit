 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_joystick:

Joystick-Modul
==========================

.. image:: img/09_joystick.png
    :width: 400
    :align: center

.. raw:: html

   <br/>

Ein Joystick-Modul ist ein Gerät, das die Bewegung eines Knopfes in zwei Richtungen messen kann: horizontal (X-Achse) und vertikal (Y-Achse). Ein Joystick-Modul kann zur Steuerung verschiedener Dinge wie Spiele, Roboter, Kameras usw. verwendet werden.

Spezifikation
---------------------------
* Versorgungsspannung: 3,3V oder 5V
* PCB-Größe: 34 x 26mm
* Ausgangssignaltyp: DO und AO
* Analoger Ausgang: X-, Y-, 2-Achsen-Analogausgang
* Digitaler Ausgang: Z, digitaler Ausgang

Pinbelegung
---------------------------
* **+5V**: Dies ist der positive Stromeingang von der Hauptsteuerung.
* **GND**: Masseanschluss.
* **VRX**: Analogausgang. X-Achsen-Analogausgangsspannung. Das Bewegen des Joysticks von links nach rechts führt dazu, dass sich die Ausgangsspannung von 0 auf VCC ändert. Wenn sich der Joystick in der Mittelstellung (Ruhezustand) befindet, wird etwa die Hälfte von VCC gelesen.
* **VRY**: Analogausgang. Y-Achsen-Analogausgangsspannung. Das Bewegen des Joysticks nach oben oder unten führt dazu, dass sich die Ausgangsspannung von 0 auf VCC ändert. Wenn sich der Joystick in der Mittelstellung (Ruhezustand) befindet, wird etwa die Hälfte von VCC gelesen.
* **SW**: Digitalausgang. Der Drucktastenschalter gibt standardmäßig ein schwebendes Signal aus.

.. tip::
    Zum Lesen des Drucktastenschalters wird ein Pull-up-Widerstand benötigt. Wenn der Joystick-Knopf gedrückt wird, wird der Schaltausgang LOW; andernfalls bleibt er HIGH. Stellen Sie sicher, dass der Eingangspin, der mit dem Schalter verbunden ist, entweder intern aktiviert oder ein externer Pull-up-Widerstand angeschlossen ist.

Funktionsprinzip
---------------------------
Ein Joystick arbeitet basierend auf der Widerstandsänderung von zwei Potentiometern (normalerweise 10 Kiloohm). Durch Ändern des Widerstands in x- und y-Richtungen erhält das Arduino unterschiedliche Spannungen, die in x- und y-Koordinaten umgewandelt werden. Der Prozessor benötigt eine ADC-Einheit, um die analogen Werte des Joysticks in digitale Werte umzuwandeln und die notwendigen Berechnungen durchzuführen.

Arduino-Boards haben sechs 10-Bit-ADC-Kanäle. Das bedeutet, dass die Referenzspannung des Arduino (5 Volt) in 1024 Segmente unterteilt ist. Wenn sich der Joystick entlang der X-Achse bewegt, steigt der ADC-Wert von 0 auf 1023, wobei der Wert 512 in der Mitte liegt. Das folgende Bild zeigt den ungefähren ADC-Wert basierend auf der Position des Joysticks.

.. image:: img/09_joystick_xy.png
    :width: 400
    :align: center

Schaltplan
---------------------------

.. image:: img/09_joystick_schematic.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

Beispiel
---------------------------
* :ref:`uno_lesson09_joystick` (Arduino UNO)
* :ref:`esp32_lesson09_joystick` (ESP32)
* :ref:`pico_lesson09_joystick` (Raspberry Pi Pico)
* :ref:`pi_lesson09_joystick` (Raspberry)
