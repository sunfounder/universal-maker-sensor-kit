.. _uno_lesson22_touch_sensor:

Lesson 22: Touch Sensor Module
==================================

In this lesson, you will learn how to integrate a touch sensor with an Arduino Uno. We'll focus on reading inputs from the touch sensor connected to the Arduino and how these inputs affect the program's flow. You'll discover how to use conditional statements to detect touch events and respond with appropriate actions and messages. This project is excellent for beginners, providing a clear understanding of working with digital inputs and basic Arduino programming concepts.

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
        - |link_touch_buy|


Wiring
---------------------------

.. image:: img/Lesson_22_touch_sensor_moudle_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a0d962e5-5d21-4f26-88db-c38f8e9fb90c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Setting up the necessary variables. We start by defining the pin number where the touch sensor is connected.

   .. code-block:: arduino

      const int sensorPin = 7;

#. Initialization in the ``setup()`` function. Here, we specify that the sensor pin will be used for input, the built-in LED will be used for output, and we start the serial communication to allow messages to be sent to the serial monitor.

   .. code-block:: arduino

      void setup() {
        pinMode(sensorPin, INPUT);
        pinMode(LED_BUILTIN, OUTPUT);
        Serial.begin(9600);
      }

#. Continuously, the Arduino checks if the touch sensor is activated. If touched, it turns on the LED and sends a "Touch detected!" message. If not touched, it turns off the LED and sends a "No touch detected..." message. A delay is introduced to prevent the sensor from being read too quickly.

   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == 1) {
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.println("Touch detected!");
        } else {
          digitalWrite(LED_BUILTIN, LOW);
          Serial.println("No touch detected...");
        }
        delay(100);
      }