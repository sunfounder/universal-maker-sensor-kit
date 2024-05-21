.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_vibration:

Vibration Sensor Module (SW-420)
=====================================

.. image:: img/24_sw420_vibration_module.png
    :width: 400
    :align: center

The SW-420 vibration sensor is a module that detects vibrations or shocks on a surface. It can be used for various purposes, such as detecting door knocks, machine malfunctions, car collisions, or alarm systems. It operates within a voltage range of 3.3 V to 5 V and has three peripherals: two LEDs (one for power status and the other for sensor output) and a potentiometer that can be used to control the vibration threshold point.

Pinout
---------------------------
* **VCC**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **DO**: Digital output. During normal operation, the sensor outputs a Logic Low signal. When vibration is detected, the sensor outputs a Logic High signal.

Principle
---------------------------
SW-420 vibration sensor module consists of a SW-420 vibration switch and an LM393 voltage comparator. A SW-420 vibration switch is a device that has a spring and a rod inside a tube. When the switch is exposed to a vibration, the spring touches the rod and closes the circuit. The vibration sensor in the module detects these oscillations and converts them into electrical signals. The LM393 comparator chip then compares these signals with a reference voltage set by the potentiometer. If the amplitude of the signal exceeds this reference voltage, the output of the comparator goes high (1), otherwise it goes low (0).

Schematic diagram
---------------------------

.. image:: img/24_sw420_vibration_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson24_vibration_sensor` (Arduino UNO)
* :ref:`esp32_lesson24_vibration_sensor` (ESP32)
* :ref:`pico_lesson24_vibration_sensor` (Raspberry Pi Pico)
* :ref:`pi_lesson24_vibration_sensor` (Raspberry Pi)


* :ref:`uno_digital_dice` (Arduino UNO)
* :ref:`uno_iot_vib_alert_system` (Arduino UNO)
* :ref:`esp32_digital_dice` (ESP32)