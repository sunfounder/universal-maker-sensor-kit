.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_photoresistor:

Photoresistor Module
==========================

.. image:: img/11_photoresistor_module.png
    :width: 400
    :align: center

.. raw:: html

   <br/>

The photoresistor module is a device that can detect the intensity of light in the environment. It can be used for various purposes, such as adjusting the brightness of a device, detecting day and night, or activating a light switch.

An important component of the photoresistor module is the photoresistor. A photoresistor is a light-controlled variable resistor. The resistance of a photoresistor decreases with increasing incident light intensity; in other words, it exhibits photo conductivity.

A photoresistor can be applied in light-sensitive detector circuits and light-activated and dark-activated switching circuits acting as a resistance semiconductor. In the dark, a photoresistor can have a resistance as high as several megaohms (MΩ), while in the light, a photoresistor can have a resistance as low as a few hundred ohms.

Here is the electronic symbol of photoresistor.

.. image:: img/11_photoresistor_symbol_2.png
    :width: 200
    :align: center

Specification
---------------------------
* Supply Voltage: 3.3V - 5V
* PCB Size: 32 x 14mm
* Output Signal Type: DO and AO

Pinout
---------------------------
* **VCC**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **DO**: Digital output. When the intensity of the light exceeds the threshold value (set by the potentiometer), D0 becomes LOW; otherwise, it remains HIGH.
* **AO**: Analog output. The stronger the light, the lower the output value; conversely, the weaker the light, the higher the output value.

Principle
---------------------------
The photoresistor module works on the principle of changing resistance in response to different light intensities. The sensor has a built-in potentiometer that adjusts the sensor's digital output (D0) threshold. 

Schematic diagram
---------------------------

.. image:: img/11_photoresistor_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson11_photoresistor` (Arduino UNO)
* :ref:`esp32_lesson11_photoresistor` (ESP32)
* :ref:`pico_lesson11_photoresistor` (Raspberry Pi Pico)
* :ref:`pi_lesson11_photoresistor` (Raspberry Pi)

