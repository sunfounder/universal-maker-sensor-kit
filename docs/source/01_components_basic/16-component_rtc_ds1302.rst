.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_rtc_ds1302:

Real Time Clock Module (DS1302)
=====================================

.. image:: img/16_DS1302_module.png
    :width: 400
    :align: center

.. raw:: html

   <br/>

The DS1302 module is a Real-Time Clock (RTC) module that can track years, months, days, weekdays, hours, minutes, and seconds. It also has the ability to adjust for leap years. It is useful for creating projects requiring precise timing and scheduling.

Specification
---------------------------
* Supply Voltage: 3.3V - 5V
* PCB Size: 44 x 23mm
* Clock IC: DS1302
* Operating temperature: 0℃ - 70℃

Pinout
---------------------------
* **VCC**: Module power supply
* **GND**: Ground 
* **CLK**: Clock pin
* **DAT**: Data pin 
* **RST**: Reset pin

Schematic diagram
---------------------------

.. image:: img/16_rtc_ds1302_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson16_ds1306` (Arduino UNO)
* :ref:`esp32_lesson16_ds1306` (ESP32)
* :ref:`pico_lesson16_ds1306` (Raspberry Pi Pico)
