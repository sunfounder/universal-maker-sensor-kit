.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_lesson07_speed:

Lesson 07: Infrared Speed Sensor Module
==========================================

In this lesson, you'll learn how to use an ESP32 Development Board with a Speed Sensor Module to detect obstructions. We'll see how the sensor sends a high signal when there's an obstruction and a low signal when the path is clear. This project is ideal for those looking to grasp sensor integration and basic input/output operations in a practical setting using the ESP32 platform.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|


Wiring
---------------------------

.. image:: img/Lesson_07_Speed_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/bdf494c6-c0b1-4dbd-89bc-ce671db41bbb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Define the sensor pin

   The sensor pin is declared as a constant integer and is assigned pin number 25 of the ESP32.

   .. code-block:: arduino

      const int sensorPin = 25;

#. Setup function

   This function initializes the serial communication at 9600 baud rate and sets the sensorPin as an input.

   .. code-block:: arduino
    
      void setup() {
        Serial.begin(9600);
        pinMode(sensorPin, INPUT);
      }

#. Loop function

   The loop function continuously checks the sensor pin's status.
   If the sensor pin reads HIGH, it prints "Obstruction detected" to the Serial Monitor.
   If the sensor pin is LOW, it prints "Unobstructed".

   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == HIGH) {
          Serial.println("Obstruction detected");
        } else {
          Serial.println("Unobstructed");
        }
      }

#. More

   If an encoder is mounted on the motor, the rotational speed of the motor can be calculated by counting the number of times an obstruction passes the sensor within a specific period.

   .. image:: img/Lesson_07_Encoder_Disk.png
      :align: center
      :width: 20%