.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_VL53L0X:

Time of Flight Micro-LIDAR Distance Sensor (VL53L0X)
===============================================================

.. image:: img/21_VL53L0X_module.png
    :width: 350
    :align: center

.. raw:: html
    
    <br/>

The VL53L0X module is an advanced time-of-flight (ToF) ranging sensor that offers highly accurate distance measurement, regardless of the target's color and reflectance. Manufactured by STMicroelectronics, this sensor excels in measuring absolute distances up to 2 meters, making it well-suited for various applications in fields such as robotics, drones, and wearable devices.

Specification
---------------------------
* Supply Voltage: 3.3V or 5V
* PCB Size: 11 x 25mm
* Communication method: I2C
* ToF ranging length: ≤2M

Pinout
---------------------------
* **VIN**: This is the power pin. 
* **GND**: Common ground for power and logic.
* **SCL**: I2C clock pin, connect to your microcontrollers I2C clock line.
* **SDA**: I2C data pin, connect to your microcontrollers I2C data line.
* **GPIO1**: Programmable interrupt output. This output is not level-shifted.
* **XSHUT**: This pin is an active-low shutdown input; Driving this pin low puts the sensor into hardware standby. This input is not level-shifted.


Example
---------------------------
* :ref:`uno_lesson21_vl53l0x` (Arduino UNO)
* :ref:`esp32_lesson21_vl53l0x` (ESP32)
* :ref:`pico_lesson21_vl53l0x` (Raspberry Pi Pico)
* :ref:`pi_lesson21_vl53l0x` (Raspberry Pi)