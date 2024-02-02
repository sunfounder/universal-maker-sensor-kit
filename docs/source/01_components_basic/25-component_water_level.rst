.. _cpn_water_level:

Water Level Sensor Module
=====================================

.. image:: img/25_water_leve_module.png
    :width: 450
    :align: center

.. raw:: html

   <br/>

The water level sensor is an affordable, user-friendly device that is compact and lightweight. It uses exposed parallel wire traces to measure the size of water droplets or volume, thus determining the water level. This sensor effortlessly converts water levels into analog signals, which can be readily utilized by program functions for triggering water level alarms. Its low power consumption and high sensitivity are also notable features.

Specification
---------------------------
* Supply Voltage: 3.3V or 5V
* PCB size: 22 x 60mm
* Working temperature range: 10℃ - 30℃
* Working humidity range: 10% - 90%

Pinout
---------------------------
* **V**: This is the positive power supply input from the main control. 
* **G**: Ground connection.
* **A**: Analog output. The higher the water level, the greater the output voltage.

Schematic diagram
---------------------------

.. image:: img/25_water_leve_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson25_water_level` (Arduino UNO)
* :ref:`esp32_lesson25_water_level` (ESP32)
* :ref:`pico_lesson25_water_level` (Raspberry Pi Pico)
* :ref:`pi_lesson25_water_level` (Raspberry Pi)
