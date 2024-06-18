.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_servo:

Servomotor (SG90)
==========================

.. image:: img/33_servo.png
    :width: 300
    :align: center

Servomotoren sind Geräte, die sich auf einen bestimmten Winkel oder eine bestimmte Position drehen können. Sie können verwendet werden, um Roboterarme, Lenkräder, Kameragimbals usw. zu bewegen. Servomotoren haben drei Drähte: Stromversorgung, Masse und Signal. Der Stromversorgungsdraht ist normalerweise rot und sollte mit dem 5V-Pin des Arduino-Boards verbunden werden. Der Masse-Draht ist normalerweise schwarz oder braun und sollte mit einem Masse-Pin des Boards verbunden werden. Der Signaldraht ist normalerweise gelb oder orange und sollte mit einem PWM-Pin des Boards verbunden werden.

Pinbelegung
---------------------------
* Brauner Draht: GND
* Oranger Draht: Signaldraht, verbunden mit dem PWM-Pin der Hauptplatine.
* Roter Draht: VCC

Prinzip
---------------------------
Ein Servo besteht im Allgemeinen aus folgenden Teilen: Gehäuse, Welle, Getriebesystem, Potentiometer, Gleichstrommotor und eingebetteter Platine.

So funktioniert es:

* Der Mikrocontroller sendet PWM-Signale an das Servo, und die eingebettete Platine im Servo empfängt die Signale über den Signaldraht und steuert den Motor im Inneren, damit dieser sich dreht.
* Dadurch treibt der Motor das Getriebesystem an, das die Welle nach der Reduzierung der Geschwindigkeit bewegt.
* Die Welle und das Potentiometer des Servos sind miteinander verbunden.
* Wenn sich die Welle dreht, treibt sie das Potentiometer an, sodass das Potentiometer ein Spannungssignal an die eingebaute Platine ausgibt.
* Die Platine bestimmt dann die Drehrichtung und -geschwindigkeit basierend auf der aktuellen Position, sodass sie genau an der definierten Position stoppen und dort halten kann.

.. image:: img/33_servo_internal.png
    :width: 450
    :align: center

.. raw:: html

    <br/>

.. _cpn_servo_pulse:

**Arbeitsimpuls**

Der Winkel wird durch die Dauer eines Impulses bestimmt, der auf den Steuerdraht angewendet wird. Dies wird als Pulsweitenmodulation bezeichnet.

* Das Servo erwartet alle 20 ms einen Impuls. Die Länge des Impulses bestimmt, wie weit sich das Servo dreht.
* Beispielsweise bewirkt ein 1,5 ms Impuls, dass das Servo in die 90-Grad-Position (Neutralstellung) dreht.
* Wenn ein Impuls an ein Servo gesendet wird, der kürzer als 1,5 ms ist, dreht sich das Servo in eine Position und hält seine Ausgangswelle um einige Grad gegen den Uhrzeigersinn von der Neutralstellung.
* Wenn der Impuls breiter als 1,5 ms ist, tritt das Gegenteil ein.
* Die minimale und maximale Impulsbreite, die das Servo in eine gültige Position bringt, sind von jedem Servo abhängig.
* Im Allgemeinen beträgt die Impulsbreite etwa 0,5 ms ~ 2,5 ms.

.. image:: img/33_servo_duty.png
    :width: 90%
    :align: center

.. raw:: html

    <br/>

Beispiel
---------------------------
* :ref:`uno_lesson33_servo` (Arduino UNO)
* :ref:`esp32_lesson33_servo` (ESP32)
* :ref:`pico_lesson33_servo` (Raspberry Pi Pico)
* :ref:`pi_lesson33_servo` (Raspberry Pi)

* :ref:`uno_lesson37_trashcan` (Arduino UNO)
* :ref:`esp32_trashcan` (ESP32)
