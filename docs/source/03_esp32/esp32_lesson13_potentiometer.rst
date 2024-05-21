.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_lesson13_potentiometer:

Lesson 13: Potentiometer Module
==================================

In this lesson, you'll learn how to read the analog value of a potentiometer with the ESP32 development board. We'll connect a potentiometer module to pin 25 and observe the changing analog values (0-4095) in the serial monitor. This project provides hands-on experience in understanding analog inputs and serial communication, making it an excellent exercise for beginners to explore the capabilities of the ESP32 board.

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

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_13_Potentiometer_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/80644221-74b4-4df5-804e-236fdc4ab30e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. This line of code defines the pin number to which the potentiometer is connected on the ESP32 Development Board.

   .. code-block:: arduino

      const int sensorPin = 25;

#. The ``setup()`` function is a special function in Arduino that is executed only once when the ESP32 Development Board is powered on or reset. In this project, the ``Serial.begin(9600)`` command initiates serial communication at a baud rate of 9600.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  
      }

#. The ``loop()`` function is the main function where the program runs repeatedly. In this function, the ``analogRead()`` function reads the analog value from the potentiometer and prints it to the serial monitor using ``Serial.println()``. The ``delay(50)`` command makes the program wait for 50 milliseconds before taking the next reading.

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));  
        delay(50);
      }
