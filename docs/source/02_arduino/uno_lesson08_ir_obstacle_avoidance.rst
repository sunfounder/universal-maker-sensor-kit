.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson08_ir_obstacle_avoidance:

Lesson 08: IR Obstacle Avoidance Sensor Module
====================================================

In this lesson, you will learn how to use an Infrared obstacle avoidance sensor with an Arduino Uno. We will explore how to read digital signals from the sensor to detect obstacles. You'll see how the sensor's red indicator light illuminates in the presence of obstacles and how it sends a low-level signal to the Arduino. This lesson is perfect for beginners, providing hands-on experience with reading digital inputs and practicing serial communication on the Arduino platform.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|



Wiring
---------------------------

.. image:: img/Lesson_08_IR_obstacle_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/be83e63b-959c-4d9c-a27b-0be46291c1f8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Define pin number for sensor connection:

   .. code-block:: arduino

     const int sensorPin = 2;

   Connect the sensor's output pin to Arduino pin 2.

2. Setup serial communication and define sensor pin as input:

   .. code-block:: arduino

     void setup() {
       pinMode(sensorPin, INPUT);  
       Serial.begin(9600);
     }

   Initialize serial communication at 9600 baud rate to print to serial monitor.
   Set sensor pin as input to read input signal.

3. Read sensor value and print to serial monitor:

   .. code-block:: arduino

     void loop() {
       Serial.println(digitalRead(sensorPin));
       delay(50); 
     }
   
   Continuously read digital value from sensor pin using ``digitalRead()`` and print value to serial monitor using ``Serial.println()``.
   Add 50ms delay between prints for better viewing.

   .. note:: 
   
      If the sensor is not working properly, adjust the IR transmitter and receiver to make them parallel. Additionally, you can adjust the detection range using the built-in potentiometer.
