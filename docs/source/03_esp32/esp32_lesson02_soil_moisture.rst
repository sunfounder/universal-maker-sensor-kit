.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_lesson02_soil_moisture:

Lesson 02: Capacitive Soil Moisture Module
============================================

In this lesson, you will learn how to use a capacitive soil moisture sensor with an ESP32 Development Board to read the moisture level of soil. We'll cover connecting the sensor to pin 25, reading its analog value, and interpreting these readings to determine the soil's moisture level. This project is ideal for beginners as it provides hands-on experience in working with sensors and understanding analog input on the ESP32 platform.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_02_Capacitive_Soil_Moisture_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ab3dd759-5698-477c-b837-0c3719a09b8d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Defining the sensor pin:

   This line of code declares a constant integer ``sensorPin`` and assigns it the value of ``25``, which is the pin the sensor is connected to.

   .. code-block:: arduino

      const int sensorPin = 25;

#. Setup function:

   The ``setup()`` function is executed once when the program starts. It initializes serial communication at 9600 baud rate. This setup is necessary for sending data to the serial monitor.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
      }

#. Loop function:

   The ``loop()`` function runs continuously after ``setup()``. It reads the sensor value from pin A0 using ``analogRead()`` and prints this value to the serial monitor. The ``delay(500)`` statement pauses the loop for 500 milliseconds before the next reading, thus controlling the rate of data acquisition.

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));
        delay(500);
      }

