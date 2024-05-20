.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_lesson31_pump:

Lesson 31: Centrifugal Pump
==================================

In this lesson, you'll learn how to control a centrifugal pump with an ESP32 Development Board and an L9110 motor control board. We'll cover setting up and using two pins to operate the motor, causing the pump to spin in one direction for 5 seconds before shutting off. This project provides hands-on experience in managing motor operations and understanding digital signals in microcontroller programming, making it ideal for beginners in electronics and programming.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_31_Pump_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b1b98b14-d067-4cba-8c3f-a04a8ad5e0c7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Two pins are defined for controlling the motor, specifically ``motorB_1A`` and ``motorB_2A``. These pins will connect to the L9110 motor control board to control the direction and speed of the motor.
  
   .. code-block:: arduino
   
      const int motorB_1A = 26;
      const int motorB_2A = 25;

2. Configuring the pins and controlling the motor:

   - The ``setup()`` function initializes the pins as ``OUTPUT`` which means they can send signals to the motor control board.

   - The ``analogWrite()`` function is used to set the motor speed. Here, setting one pin to ``HIGH`` and the other to ``LOW`` makes the pump spin in one direction. After a 5-second delay, both pins are set to 0, turning off the motor.

   .. raw:: html

      <br/>
   
   .. code-block:: arduino
   
      void setup() {
         pinMode(motorB_1A, OUTPUT);  // set pump pin 1 as output
         pinMode(motorB_2A, OUTPUT);  // set pump pin 2 as output
         analogWrite(motorB_1A, HIGH); 
         analogWrite(motorB_2A, LOW);
         delay(5000);// wait for 5 seconds
         analogWrite(motorB_1A, 0);  // turn off the pump
         analogWrite(motorB_2A, 0);
      }
