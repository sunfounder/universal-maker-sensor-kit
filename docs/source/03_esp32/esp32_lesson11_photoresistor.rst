.. _esp32_lesson11_photoresistor:

Lesson 11: Photoresistor Module
==================================

In this lesson, you will learn how to use a photoresistance sensor with an ESP32 Development Board to measure light intensity. We'll explore how the sensor detects different light levels and processes and displays these readings on the serial monitor. This project is ideal for beginners as it provides hands-on experience with analog sensors and real-time data handling in Arduino programming.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_photoresistor`
* :ref:`cpn_breadboard`

Wiring
---------------------------

.. image:: img/Lesson_11_Photoresistance_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d66fd803-df3b-4afd-9986-b335e0739241/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. **Setting Up the Sensor Pin and Serial Communication**

   We start by defining the sensor pin and initializing serial communication in the setup function. The photoresistor is connected to the pin 25.

   .. code-block:: arduino

      const int sensorPin = 25;  // Pin connected to the photoresistor

      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

#. **Reading and Displaying Sensor Data**

   In the loop function, we continuously read the analog value from the sensor and print it to the Serial Monitor. We also add a short delay to stabilize the readings.

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));  // Read and print the analog value
        delay(50);                              // Short delay to stabilize readings
      }




