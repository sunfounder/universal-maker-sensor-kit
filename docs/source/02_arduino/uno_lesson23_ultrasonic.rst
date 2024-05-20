.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson23_ultrasonic:

Lesson 23: Ultrasonic Sensor Module (HC-SR04)
================================================

In this lesson, you will learn how to use an ultrasonic sensor with Arduino to measure distances. We'll cover connecting the HC-SR04 sensor to the Arduino Uno R4 board and using it to calculate and display distance measurements in centimeters. This project is ideal for beginners, providing hands-on experience with Arduino's serial communication and sensor data processing. You'll gain valuable insights into working with digital signals and understanding the basics of ultrasonic sensing technology.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|



Wiring
---------------------------

.. image:: img/Lesson_23_ultrasonic_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/633ae8f5-4b15-4888-b4cb-b1eb24f3e2ef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Pin declaration:

   Start by defining the pins for the ultrasonic sensor. ``echoPin`` and ``trigPin`` are declared as integers and their values are set to match the physical connection on the Arduino board.

   .. code-block:: arduino

      const int echoPin = 3;
      const int trigPin = 4;

2. ``setup()`` function:

   The ``setup()`` function initializes the serial communication, sets the pin modes, and prints a message to indicate the ultrasonic sensor is ready.
 
   .. code-block:: arduino
 
      void setup() {
        Serial.begin(9600);
        pinMode(echoPin, INPUT);
        pinMode(trigPin, OUTPUT);
        Serial.println("Ultrasonic sensor:");
      }

3. ``loop()`` function:

   The ``loop()`` function reads the distance from the sensor and prints it to the serial monitor, then delays for 400 milliseconds before repeating.

   .. code-block:: arduino

      void loop() {
        float distance = readDistance();
        Serial.print(distance);
        Serial.println(" cm");
        delay(400);
      }

4. ``readDistance()`` function :

   The ``readDistance()`` function triggers the ultrasonic sensor and calculates the distance based on the time it takes for the signal to bounce back.

   For more details, please refer to the working :ref:`principle <cpn_ultrasonic_principle>` of the ultrasonic sensor module.

   .. code-block:: arduino

      float readDistance() {
        digitalWrite(trigPin, LOW);   // Set trig pin to low to ensure a clean pulse
        delayMicroseconds(2);         // Delay for 2 microseconds
        digitalWrite(trigPin, HIGH);  // Send a 10 microsecond pulse by setting trig pin to high
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);  // Set trig pin back to low
        float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
        return distance;
      }
