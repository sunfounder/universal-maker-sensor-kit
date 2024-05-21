.. _uno_lesson11_photoresistor:

Lesson 11: Photoresistor Module
==================================

In this lesson, you will learn how to measure light intensity using a photoresistor sensor with an Arduino Uno. We'll cover reading and displaying the analog values from the sensor, which reflect the amount of light it detects. This project is ideal for beginners as it provides hands-on experience in working with sensors and understanding analog input on the Arduino platform. You'll also improve your proficiency in serial communication by outputting sensor readings to the serial monitor.

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

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_sensor_module_buy|


Wiring
---------------------------

.. image:: img/Lesson_11_photoresistor_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ac4664d2-2f44-4d5f-9cf4-a82eadc74d3e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. **Setting Up the Sensor Pin and Serial Communication**

   We start by defining the sensor pin and initializing serial communication in the setup function. The photoresistor is connected to the analog pin A0.

   .. code-block:: arduino

      const int sensorPin = A0;  // Pin connected to the photoresistor

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




