.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_pir_motion:

PIR Motion Module (HC-SR501)
=====================================

.. image:: img/12_pir_module.png
    :width: 300
    :align: center


The Passive Infrared(PIR) Motion Sensor is a sensor that detects motion. It is commonly used in security systems and automatic lighting systems. The sensor has two slots that detect infrared radiation. When an object, such as a person, passes in front of the sensor, it detects a change in the amount of infrared radiation and triggers an output signal.

Specification
---------------------------
* Supply Voltage: 5V~20V; 
* Output: Defaults to low; goes high when someone passes by.
* Delay Time: 5~200s(adjustable)
* Blocking Time: 8s
* Sensing Range: <120°, within 7 meters(adjustable)
* Trigger Mode: L Non-repeatable trigger mode, H Repeatable trigger mode
* PCB size: 32 x 24mm
* Lens size: 23mm
* Working temperature: -15~+70℃


Pinout
---------------------------
* **VCC**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **DO**: Digital output. Defaults to low; goes high when someone passes by.

Principle
---------------------------
The PIR sensor is split into two slots that are connected to a differential amplifier. Whenever a stationary object is in front of the sensor, the two slots receive the same amount of radiation and the output is zero. Whenever a moving object is in front of the sensor, one of the slots receives more radiation than the other , which makes the output fluctuate high or low. This change in output voltage is a result of detection of motion.

.. image:: img/12_pir_working_principle.jpg
    :width: 500
    :align: center

After the sensing module is wired, there is a one-minute initialization. During the initialization, module will output for 0~3 times at intervals. Then the module will be in the standby mode. Please keep the interference of light source and other sources away from the surface of the module so as to avoid the misoperation caused by the interfering signal. Even you’d better use the module without too much wind, because the wind can also interfere with the sensor.

.. image:: img/12_pir_module_back.png
    :width: 350
    :align: center

.. raw:: html
    
    <br/><br/> 

Distance Adjustment
^^^^^^^^^^^^^^^^^^^^
Turning the knob of the distance adjustment potentiometer clockwise, the range of sensing distance increases, and the maximum sensing distance range is about 0-7 meters. If turn it anticlockwise, the range of sensing distance is reduced, and the minimum sensing distance range is about 0-3 meters.

Delay adjustment
^^^^^^^^^^^^^^^^^^^^
Rotate the knob of the delay adjustment potentiometer clockwise, you can also see the sensing delay increasing. The maximum of the sensing delay can reach up to 300s. On the contrary, if rotate it anticlockwise, you can shorten the delay with a minimum of 5s.

Two Trigger Modes
^^^^^^^^^^^^^^^^^^^^
Choosing different modes by using the jumper cap.

* H: Repeatable trigger mode, after sensing the human body, the module outputs high level. During the subsequent delay period, if somebody enters the sensing range,the output will keep being the high level.
* L: Non-repeatable trigger mode, outputs high level when it senses the human body. After the delay, the output will change from high level into low level automatically.

Example
---------------------------
* :ref:`uno_lesson12_pir_motion` (Arduino UNO)
* :ref:`esp32_lesson12_pir_motion` (ESP32)
* :ref:`pico_lesson12_pir_motion` (Raspberry Pi Pico)
* :ref:`pi_lesson12_pir_motion` (Raspberry Pi)
