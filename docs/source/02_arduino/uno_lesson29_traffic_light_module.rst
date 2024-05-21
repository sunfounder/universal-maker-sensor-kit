.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson29_traffic_light_module:

Lesson 29: Traffic Light Module
==================================

In this lesson, you will learn how to use Arduino to control a mini LED traffic light. We’ll cover programming the Arduino Uno to cycle through green, yellow, and red lights, simulating a real traffic signal. This project is ideal for beginners as it provides practical experience in coding light sequences and timing controls on the Arduino platform.

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
    *   - :ref:`cpn_traffic`
        - |link_traffic_light_module_buy|

* Arduino UNO R3 or R4
* :ref:`cpn_traffic`

Wiring
---------------------------

.. image:: img/Lesson_29_traffic_light_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/48f3abf4-1a9c-405f-9247-7dbd61e64f75/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Before any operations, we define constants for the pins where LEDs are connected. This makes our code easier to read and modify.

  .. code-block:: arduino

     const int rledPin = 9;  //red
     const int yledPin = 8;  //yellow
     const int gledPin = 7;  //green

2. Here, we specify the pin modes for our LED pins. They are all set to ``OUTPUT`` because we intend to send voltage to them.

  .. code-block:: arduino

     void setup() {
       pinMode(rledPin, OUTPUT);
       pinMode(yledPin, OUTPUT);
       pinMode(gledPin, OUTPUT);
     }

3. This is where our traffic light cycle logic is implemented. The sequence of operations is:

    * Turn the green LED on for 5 seconds.
    * Blink the yellow LED three times (each blink lasts for 0.5 seconds).
    * Turn the red LED on for 5 seconds.
    
  .. code-block:: arduino

     void loop() {
       digitalWrite(gledPin, HIGH);
       delay(5000);
       digitalWrite(gledPin, LOW);
       
       digitalWrite(yledPin, HIGH);
       delay(500);
       digitalWrite(yledPin, LOW);
       delay(500);
       digitalWrite(yledPin, HIGH);
       delay(500);
       digitalWrite(yledPin, LOW);
       delay(500);
       digitalWrite(yledPin, HIGH);
       delay(500);
       digitalWrite(yledPin, LOW);
       delay(500);
       
       digitalWrite(rledPin, HIGH);
       delay(5000);
       digitalWrite(rledPin, LOW);
     }

