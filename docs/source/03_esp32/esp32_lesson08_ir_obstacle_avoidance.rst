.. _esp32_lesson08_ir_obstacle_avoidance:

Lesson 08: IR Obstacle Avoidance Sensor Module
====================================================

In this lesson, you'll learn how to use an Infrared obstacle avoidance sensor with an ESP32 Development Board. We'll explore how the sensor detects obstacles and alters its output signal. You'll also learn how to read these signals using the ESP32 and display them on the serial monitor. This project provides a great opportunity for beginners to gain hands-on experience with sensors and digital input processing on the ESP32 platform, making it perfect for those interested in building interactive projects.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_ir_obstacle`
* :ref:`cpn_breadboard`

Wiring
---------------------------

.. image:: img/Lesson_08_Obstacle_Avoidance_Sensor_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e04a4a04-e707-46a1-aee5-488add646356/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Define pin number for sensor connection:

   .. code-block:: arduino

     const int sensorPin = 25;

   Connect the sensor's output pin to pin 25.

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
