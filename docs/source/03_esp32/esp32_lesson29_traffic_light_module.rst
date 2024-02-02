.. _esp32_lesson29_traffic_light_module:

Lesson 29: Traffic Light Module
==================================

In this lesson, you'll learn how to use an ESP32 Development Board to control a Mini Traffic Light Module. We'll cover setting up the board and writing code to create a traffic light sequence: 5 seconds of green light, blinking yellow light for 1.5 seconds, and 5 seconds of red light. This project is ideal for beginners in electronics and programming as it provides practical experience with output operations and basic timing control using the ESP32.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_traffic`
* :ref:`cpn_breadboard` 

Wiring
---------------------------

.. image:: img/Lesson_29_Traffic_Light_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/df3260e8-4f79-4dca-aa47-c3a684867ca1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Before any operations, we define constants for the pins where LEDs are connected. This makes our code easier to read and modify.

  .. code-block:: arduino

     const int rledPin = 25;  //red
     const int yledPin = 26;  //yellow
     const int gledPin = 27;  //green

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

