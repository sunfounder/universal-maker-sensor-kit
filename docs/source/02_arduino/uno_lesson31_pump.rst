.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson31_pump:

Lesson 31: Centrifugal Pump
==================================

In this lesson, you'll learn how to control a centrifugal pump with an Arduino Uno R3 or R4 and an L9110 motor control board. You'll discover how to set up and program the Arduino to start the pump in one direction, run it for a specific duration, and then stop it. This hands-on experience is ideal for beginners and offers fundamental insight into managing motor operations and understanding output controls in Arduino projects.

Required Components
--------------------------

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

* Arduino UNO R3 or R4
* :ref:`cpn_pump`
* :ref:`cpn_l9110`


Wiring
---------------------------

.. image:: img/Lesson_31_pump_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f5fad7fa-4b2c-4630-a832-d3a5e077d9fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Two pins are defined for controlling the motor, specifically ``motorB_1A`` and ``motorB_2A``. These pins will connect to the L9110 motor control board to control the direction and speed of the motor.
  
   .. code-block:: arduino
   
      const int motorB_1A = 9;
      const int motorB_2A = 10;

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
