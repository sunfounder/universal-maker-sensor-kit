.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_pcf8591:

PCF8591 ADC DAC Converter Module
=====================================

.. image:: img/10_pcf8591_module.png
    :width: 35%
    :align: center

.. raw:: html

   <br/>

The PCF8591 is a single-chip, single-supply low-power 8-bit CMOS data acquisition device with four analog inputs, one analog output and a serial I2C-bus interface. Three address pins A0, A1 and A2 are used for programming the hardware address, allowing the use of up to eight devices connected to the I2C-bus without additional hardware. Address, control and data to and from the device are transferred serially via the two-line bidirectional I2C-bus.

The functions of the device include analog input multiplexing, on-chip track and hold function, 8-bit analog-to-digital conversion and an 8-bit digital-to-analog conversion. The maximum conversion rate is given by the maximum speed of the I2C-bus.

Principle
---------------------------

**Addressing:**

Each PCF8591 device in an I2C-bus system is activated by sending a valid address to the device. The address consists of a fixed part and a programmable part. The programmable part must be set according to the address pins A0, A1 and A2. The address always has to be sent as the first byte after the start condition in the I2C-bus protocol. The last bit of the address byte is the read/write-bit which sets the direction of the following data transfer (see as below).

.. image:: img/10_pcf8591_addressing.png
   :width: 60%

**Control byte:**

The second byte sent to a PCF8591 device will be stored in its control register and is required to control the device function. The upper nibble of the control register is used for enabling the analog output, and for programming the analog inputs as single-ended or differential inputs. The lower nibble selects one of the analog input channels defined by the upper nibble. If the auto-increment flag is set, the channel number is incremented automatically after each A/D conversion. See the figure below.

.. image:: img/10_pcf8591_byte.png
   :width: 80%

.. _cpn_pcf8591_sch:

Schematic diagram
---------------------------

.. image:: img/10_pcf8591_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson10_pcf8591` (Arduino UNO)
* :ref:`esp32_lesson10_pcf8591` (ESP32)
* :ref:`pico_lesson10_pcf8591` (Raspberry Pi Pico)
* :ref:`pi_lesson10_pcf8591` (Raspberry Pi)

* :ref:`pi_lesson02_soil_moisture` (Raspberry Pi)
* :ref:`pi_lesson09_joystick` (Raspberry Pi)
* :ref:`pi_lesson11_photoresistor` (Raspberry Pi)
* :ref:`pi_lesson13_potentiometer` (Raspberry Pi)
* :ref:`pi_lesson25_water_level` (Raspberry Pi)
