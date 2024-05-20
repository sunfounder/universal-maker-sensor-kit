.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/fun_project/08-fun-Touch_toggle_light.html

.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_touch_toggle_light:

Lesson 42: Touch toggle light
==================================


This project is a simple implementation of a traffic light control system utilizing a touch sensor and a traffic light LED module. 
Activating the touch sensor initiates a sequence where LEDs illuminate in the following order: Red -> Yellow -> Green.


Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_touch`
        - \-
    *   - :ref:`cpn_traffic`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Wiring
---------------------------

.. image:: img/Lesson_42_Touch_toggle_light_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/f53d6cf6-ed27-49d3-b4d3-12f29b417a89/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

The operation of this project is straightforward: a touch detection on the sensor triggers the illumination of the next LED in the sequence (Red -> Yellow -> Green), controlled by the ``currentLED`` variable.

1. Define pins and initial values

   .. code-block:: arduino
   
      const int touchSensorPin = 2;  // Touch sensor pin
      const int rledPin = 7;         // Red LED pin
      const int yledPin = 8;         // Yellow LED pin
      const int gledPin = 9;         // Green LED pin
      int lastTouchState;            // Previous touch sensor state
      int currentTouchState;         // Current touch sensor state
      int currentLED = 0;            // Current LED: 0->Red, 1->Yellow, 2->Green
   
   These lines establish the pin connections for the Arduino board components and initialize the touch sensor and LED states.

2. setup() function

   .. code-block:: arduino
   
       void setup() {
         Serial.begin(9600);              // Initialize serial communication
         pinMode(touchSensorPin, INPUT);  // Set touch sensor pin as input
         // Configure LED pins as outputs
         pinMode(rledPin, OUTPUT);
         pinMode(yledPin, OUTPUT);
         pinMode(gledPin, OUTPUT);
         currentTouchState = digitalRead(touchSensorPin); // Read initial touch state
       }
   
   This function configures the initial setup for the Arduino, defining input and output modes and starting serial communication for debugging.

3. loop() function

   .. code-block:: arduino
   
       void loop() {
         lastTouchState = currentTouchState;                        // Store the last state
         currentTouchState = digitalRead(touchSensorPin);           // Read new touch state
         if (lastTouchState == LOW && currentTouchState == HIGH) {  // Detect touch
           Serial.println("Sensor touched");
           turnAllLEDsOff();  // Turn off all LEDs
           // Activate the next LED in sequence
           switch (currentLED) {
             case 0:
               digitalWrite(rledPin, HIGH);
               currentLED = 1;
               break;
             case 1:
               digitalWrite(yledPin, HIGH);
               currentLED = 2;
               break;
             case 2:
               digitalWrite(gledPin, HIGH);
               currentLED = 0;
               break;
           }
         }
       }

   The loop continuously monitors the touch sensor, cycling through the LEDs when a touch is detected, ensuring only one LED is on at any given time.

4. Turn off LEDs function

   .. code-block:: arduino
      
       void turnAllLEDsOff() {
         // Set all LED pins to LOW, turning them off
         digitalWrite(rledPin, LOW);
         digitalWrite(yledPin, LOW);
         digitalWrite(gledPin, LOW);
       }

   This auxiliary function turns off all LEDs, aiding in the cycling process.