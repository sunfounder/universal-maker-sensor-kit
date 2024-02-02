.. _esp32_lesson03_flame:

Lesson 03: Flame Sensor Module
==================================

In this lesson, you will learn how to connect a flame sensor to an ESP32 Development Board for fire detection. We'll examine the sensor's response to fire and how it triggers a warning message. This project is ideal for beginners working with sensors and ESP32, providing hands-on experience in monitoring environmental factors using basic electronic components.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_flame`
* :ref:`cpn_breadboard`

Wiring
---------------------------

.. image:: img/Lesson_03_Flame_Sensor_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/82f965f6-4213-4c23-88db-4257cf12d920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. **Defining the Sensor Pin**:

   The pin to which the flame sensor is connected is defined as an integer constant.
 
   .. code-block:: arduino

      const int sensorPin = 25;

#. **Setup Function**:

   This function runs once when the ESP32 starts. It initializes the sensor pin as an input and begins serial communication at 9600 baud rate for output.
 
   .. code-block:: arduino

      void setup() {
        pinMode(sensorPin, INPUT);
        Serial.begin(9600);
      }

#. **Loop Function**:

   The core of the program, it continuously checks the state of the flame sensor. If the sensor detects a flame (returns 0), it prints a fire alert message. Otherwise, it indicates no fire is detected. The check happens every 100 milliseconds.
 
   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == 0) {
          Serial.println("** Fire detected!!! **");
        } else {
          Serial.println("No Fire detected");
        }
        delay(100);
      }
