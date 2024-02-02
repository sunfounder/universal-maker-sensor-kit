.. _esp32_lesson15_raindrop:

Lesson 15: Raindrop Detection Module
=======================================

In this lesson, you will learn how to use a raindrop detection sensor with an ESP32 Development Board. We'll cover reading digital signals from the sensor when it detects rainwater and displaying this information on the serial monitor. This project provides an engaging way to grasp digital input and output in microcontroller programming, making it ideal for beginners in electronics and coding with the ESP32 platform.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_raindrop`
* :ref:`cpn_breadboard` 

Wiring
---------------------------

.. image:: img/Lesson_15_Raindrop_Detection_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5aff47ab-22c5-4500-bbe3-fefc55f6e40f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Defining sensor pin

   Here, a constant integer named ``sensorPin`` is defined and assigned the value 25. This corresponds to the digital pin on the ESP32 Development Board where the raindrops detection sensor is connected.

   .. code-block:: arduino
   
       const int sensorPin = 25;

2. Setting up the pin mode and initiating serial communication.

   In the ``setup()`` function, two essential steps are performed. Firstly, ``pinMode()`` is used to set the ``sensorPin`` as an input, enabling us to read digital values from the raindrops sensor. Secondly, serial communication is initialized with a baud rate of 9600.

   .. code-block:: arduino
   
       void setup() {
         pinMode(sensorPin, INPUT);
         Serial.begin(9600);
       }

3. Reading the digital value and sending it to the serial monitor. 

   The ``loop()`` function reads the digital value from the raindrops sensor using ``digitalRead()``. This value (either HIGH or LOW) is printed to the Serial Monitor. When raindrops are detected, the serial monitor will display 0; when no raindrops are detected, it will display 1. The program then waits for 50 milliseconds before the next reading.

   .. code-block:: arduino
   
       void loop() {
         Serial.println(digitalRead(sensorPin));
         delay(50);
       }
