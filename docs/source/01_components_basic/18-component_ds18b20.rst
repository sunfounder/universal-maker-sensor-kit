.. _cpn_ds18b20:

Temperature Sensor Module (DS18B20)
===============================================

.. image:: img/18_ds18b20_module.png
    :width: 300
    :align: center

.. raw:: html

   <br/>

The DS18B20 is a digital temperature sensor that can measure temperatures ranging from -67°F to +257°F with an accuracy of ±0.5°C. It follows the single wire protocol and can communicate with a microcontroller using only one pin. The sensor can be powered directly from the data line, eliminating the need for an external power supply. The applications of the DS18B20 temperature sensor include industrial systems, consumer products, systems which are sensitive thermally, thermostatic controls, and thermometers.

Specification
---------------------------
* PCB Size: 13 x 27.9mm
* Power Supply: 3V to 5.5V
* Temperature Range: -55 to 125°C
* Accuracy:	±0.5°C
* Resolution: 9 to 12 bit (selectable)

Pinout
---------------------------
* **VCC**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **OUT**: The 1-Wire Data Bus that should be connected to a digital pin on the microcontroller.

Schematic diagram
---------------------------

.. image:: img/18_ds18b20_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson18_ds18b20` (Arduino UNO)
* :ref:`esp32_lesson18_ds18b20` (ESP32)
* :ref:`pico_lesson18_ds18b20` (Raspberry Pi Pico)
* :ref:`pi_lesson18_ds18b20` (Raspberry Pi)