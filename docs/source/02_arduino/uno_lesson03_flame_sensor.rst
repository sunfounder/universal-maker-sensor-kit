.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson03_flame:

Lesson 03: Flame Sensor Module
==================================

In this lesson, you will learn how to integrate a flame sensor with an Arduino board to detect the presence of fire. We will see how the flame sensor, when detecting a flame, triggers the Arduino's built-in LED to light up and sends a warning message to the serial monitor. Conversely, in the absence of a flame, the LED stays off, and a different message is relayed to the monitor. This project is an excellent starting point for beginners, offering a comprehensive understanding of how to manage digital inputs and outputs on the Arduino platform. It provides a hands-on approach to learning about sensor integration and real-time response mechanisms in an Arduino-based system.

Required Components
---------------------------

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
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|


Wiring
---------------------------

.. image:: img/Lesson_03_flame_module_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/244b68c4-0c4d-46fb-b220-985d42f4efdc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. The first line of code is a constant integer declaration for the flame sensor pin. We use the digital pin 7 to read the output from the flame sensor.

   .. code-block:: arduino
   
      const int sensorPin = 7;

2. The ``setup()`` function initializes the flame sensor pin as an input and the built-in LED pin as an output. It also starts the serial communication at a baud rate of 9600 for printing messages to the serial monitor.

   .. code-block:: arduino
   
      void setup() {
        pinMode(sensorPin, INPUT);     // Set the flame sensor pin as input
        pinMode(LED_BUILTIN, OUTPUT);  // Set the built-in LED pin as output
        Serial.begin(9600);            // Initialize the serial monitor at a baud rate of 9600
      }

3. The ``loop()`` function is where we continuously check the status of the flame sensor. If the sensor detects a flame, the built-in LED is turned on and a message is printed to the serial monitor. If no flame is detected, the LED is turned off and a different message is printed. The process repeats every 100 milliseconds.

   .. note:: 
      You can change the threshold for detecting flames by adjusting the potentiometer on the flame sensor module.

   .. code-block:: arduino
   
      void loop() {
        // Check if the sensor is detecting a fire
        if (digitalRead(sensorPin) == 0) {
          digitalWrite(LED_BUILTIN, HIGH);  // Turn on the built-in LED
          Serial.println("** Fire detected!!! **");
        } else {
          digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED
          Serial.println("No Fire detected");
        }
        delay(100);
      }
