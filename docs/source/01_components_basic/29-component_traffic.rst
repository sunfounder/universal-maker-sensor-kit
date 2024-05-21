.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_traffic:

Traffic Light Module
==========================

.. image:: img/29_traffic_light.png
    :width: 400
    :align: center

.. raw:: html
    
    <br/>

The traffic light module is a small device that can display red, yellow and green lights, just like a real traffic light. It can be used to make a traffic light system model or to learn how to control LEDs with Arduino. It is featured with its small size, simple wiring, targeted, and custom installation. It can be connected PWM pin to control the brightness of the LED.

Principle
---------------------------
The traffic light module can be controlled in two primary ways. The more straightforward method involves using digital inputs from the Arduino, where a HIGH or LOW signal directly turns the corresponding LED on or off. Alternatively, PWM (pulse-width modulation) can be used, especially when varying the brightness of the LED is desired. PWM is a technique where the duty cycle of a digital signal is changed to modulate the brightness of the LED. A duty cycle represents the percentage of time that a signal remains on during a specific period. For instance, a 50% duty cycle implies the signal is active for half the duration and inactive for the remainder. Adjusting the duty cycle allows for the LED's brightness modulation.

Schematic diagram
---------------------------

.. image:: img/29_traffic_light_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson29_traffic_light_module` (Arduino UNO)
* :ref:`esp32_lesson29_traffic_light_module` (ESP32)
* :ref:`pico_lesson30_relay_module` (Raspberry Pi Pico)
* :ref:`pi_lesson30_relay_module` (Raspberry Pi)

* :ref:`uno_lesson30_relay_module` (Arduino UNO)

* :ref:`uno_touch_toggle_light` (Arduino UNO)
* :ref:`uno_bluetooth_traffic_light` (Arduino UNO)
* :ref:`esp32_touch_toggle_light` (ESP32)