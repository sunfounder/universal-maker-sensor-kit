.. _cpn_button:

Button Module
==========================

.. image:: img/01_button.png
    :width: 300
    :align: center

.. raw:: html

   <br/>

.. _btn_intro:

The button module is an electronic device that detects the state of a button.They are usually used as switches to connect or break circuits.Buttons are used in many scenarios, such as doorbells, desk lamps, remote controls, elevators, fire alarms, etc.

Principle
---------------------------
The button module works on the principle of a switch. A switch is an electrical component that can be used to open or close a circuit. 

The following is the internal structure of a button. The symbol on the right below is usually used to represent a button in circuits.

.. image:: img/01_button_2.png
    :width: 400
    :align: center

Since the pin 1 is connected to pin 2, and pin 3 to pin 4, when the button is pressed, the 4 pins are connected, thus closing the circuit.

.. image:: img/01_button_3.png
    :width: 700
    :align: center

.. _cpn_button_sch:

Schematic diagram
---------------------------

.. image:: img/01_button_module_schematic.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>


Example
---------------------------
* :ref:`uno_lesson01_button` (Arduino UNO)
* :ref:`eps32_lesson01_button` (ESP32)
* :ref:`pico_lesson01_button` (Raspberry Pi Pico)
* :ref:`pi_lesson01_button` (Raspberry Pi)
* :ref:`esp32_iot_mqtt` (ESP32)