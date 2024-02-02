.. _cpn_rotary_encoder:

Rotary Encoder Module
=====================================

.. image:: img/17_rotary_encoder.png
    :width: 35%
    :align: center

.. raw:: html

   <br/>

A rotary encoder is a position sensor that converts the rotation of a knob into an output signal, indicating the direction in which the knob is turned.

Rotary encoders are digital versions of potentiometers, offering greater versatility. They can rotate continuously, while potentiometers have limited rotation. Potentiometers indicate exact knob position, while rotary encoders show changes in position.

Pinout
---------------------------
* **VCC**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **SW**: Digital output. 
* **CLK**: is similar to CLK output, but it lags behind CLK by a 90° phase shift. This output is used to determine the direction of rotation.
* **DT**: is the primary output pulse used to determine the amount of rotation. Each time the knob is turned in either direction by just one detent (click), the ‘CLK’ output goes through one cycle of going HIGH and then LOW.

Principle
---------------------------

Incremental encoders produce two-phase square waves, with a 90-degree phase difference commonly referred to as the A and B channels.

As illustrated below, when channel A transitions from a high level to a low level, if channel B is at a high level, it indicates that the rotary encoder is rotating clockwise (CW); if at that moment channel B is at a low level, it means the rotation is counterclockwise (CCW). Therefore, by reading the value of channel B when channel A is at a low level, we can determine the direction in which the rotary encoder rotates.

.. image:: img/17_rotary_encoder_wave.png
    :width: 60%
    :align: center


Schematic diagram
---------------------------

.. image:: img/17_rotary_encoder_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson17_rotary_encoder` (Arduino UNO)
* :ref:`esp32_lesson17_rotary_encoder` (ESP32)
* :ref:`pico_lesson17_rotary_encoder` (Raspberry Pi Pico)
* :ref:`pi_lesson17_rotary_encoder` (Raspberry Pi)