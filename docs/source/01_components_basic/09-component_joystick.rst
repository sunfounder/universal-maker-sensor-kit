.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_joystick:

Joystick Module
==========================

.. image:: img/09_joystick.png
    :width: 400
    :align: center

.. raw:: html

   <br/>

A joystick module is a device that can measure the movement of a knob in two directions: horizontal (X-axis) and vertical (Y-axis). A joystick module can be used to control various things such as games, robots, cameras, etc.

Specification
---------------------------
* Supply Voltage: 3.3V or 5V
* PCB Size: 34 x 26mm
* Output Signal Type: DO and AO
* Analog Output: X, Y, 2 Axis analog output
* Digital Output: Z, digital output

Pinout
---------------------------
* **+5V**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **VRX**: Analog output. X-axis analog output voltage. Moving the joystick from left to right will cause the output voltage to change from 0 to VCC. When the joystick is in the center position (idle state), it will read about half of VCC.
* **VRY**: Analog output. Y-axis analog output voltage. Moving the joystick up or down will cause the output voltage to change from 0 to VCC. When the joystick is in the center position (at rest), it will read approximately half of VCC.
* **SW**: Digital output. The pushbutton switch outputs a floating signal by default. 

.. tip::
    To read the pushbutton switch, a pull-up resistor is needed. When the joystick knob is pressed, the switch output becomes LOW; otherwise, it remains HIGH. Ensure that the input pin connected to the switch has either internal pull-up enabled or an external pull-up resistor connected.

Principle
---------------------------
Joystick operates based on the resistance change of two potentiometers (usually 10-kilo ohms). By changing resistance in x and y directions, Arduino receives varying voltages which are interpreted to x and y coordinates. The processor needs an ADC unit to change the joystick’s analog values into digital values and perform necessary processing.

Arduino boards have six 10-bits ADC channels. It means the Arduino’s reference voltage (5 volts) is divided to 1024 segments. When joystick moves along the x-axis, the ADC value rises from 0 to 1023, with the value 512 in the middle. The image below displays the ADC approximate value based on the joystick position.

.. image:: img/09_joystick_xy.png
    :width: 400
    :align: center

Schematic diagram
---------------------------

.. image:: img/09_joystick_schematic.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson09_joystick` (Arduino UNO)
* :ref:`esp32_lesson09_joystick` (ESP32)
* :ref:`pico_lesson09_joystick` (Raspberry Pi Pico)
* :ref:`pi_lesson09_joystick` (Raspberry)

* :ref:`uno_lesson53_direction_indicator` (Arduino UNO)
