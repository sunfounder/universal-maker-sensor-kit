.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_lesson33_servo:

Lesson 33: Servo Motor (SG90)
==================================

In this lesson, you'll learn how to control a servo motor with an ESP32 Development Board. We'll cover the process of making the servo motor scan from 0 to 180 degrees and back, giving you hands-on experience in managing servo movements. This project is ideal for those seeking to grasp motor control and the use of pulse width modulation (PWM) in robotics, utilizing the versatile ESP32 board.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_33_Servo_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/877c9719-5f1b-4df1-9d3b-9e9500a5df08/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Including the Library

   The ESP32Servo library is included to manage servo motor operations.

   .. code-block:: arduino

     #include <ESP32Servo.h>

#. Defining Servo and Pin

   A Servo object is created, and a pin is defined for servo control.

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

     Servo myServo;
     const int servoPin = 25;

#. Setting Pulse Width Limits

   Minimum and maximum pulse widths are defined for servo motion limits.

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

     const int minPulseWidth = 500; // 0.5 ms
     const int maxPulseWidth = 2500; // 2.5 ms

#. Setup Function

   - The servo is attached to the defined pin and its pulse width range is set.
   - The PWM frequency is set to 50Hz, standard for servos.

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

     void setup() {
       myServo.attach(servoPin, minPulseWidth, maxPulseWidth);
       myServo.setPeriodHertz(50);
     }

#. Loop Function

   - Servo rotation is controlled in a loop, moving from 0 to 180 degrees, then back to 0 degrees.
   - ``writeMicroseconds()`` is used to set the servo position based on pulse width.

   .. raw:: html
      
      <br/>

   .. code-block:: arduino

      void loop() {
        // Rotate the servo from 0 to 180 degrees
        for (int angle = 0; angle <= 180; angle++) {
          int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
          myServo.writeMicroseconds(pulseWidth);
          delay(15);
        }
      
        // Rotate the servo from 180 to 0 degrees
        for (int angle = 180; angle >= 0; angle--) {
          int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
          myServo.writeMicroseconds(pulseWidth);
          delay(15);
        }
      }