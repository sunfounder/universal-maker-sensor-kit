.. _uno_lesson24_vibration_sensor:

Lesson 24: Vibration Sensor Module (SW-420)
==============================================

In this lesson, you will learn how to detect vibrations using a vibration sensor with an Arduino Uno. We'll explore how the sensor signals the presence of vibrations to the Arduino, triggering it to display a message. This project is perfect for beginners to understand digital input processing and serial communication in Arduino. You'll gain hands-on experience in reading sensor data and implementing conditional logic in your sketches.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|



Wiring
---------------------------

.. image:: img/Lesson_24_vibration_module_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a04cb423-f55b-465a-bef3-100260eef067/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. The first line of code is a constant integer declaration for the vibration sensor pin. We use digital pin 7 to read the output from the vibration sensor.

   .. code-block:: arduino
   
      const int sensorPin = 7;

2. In the ``setup()`` function, we initialize the serial communication at a baud rate of 9600 to print readings from the vibration sensor to the serial monitor. We also set the vibration sensor pin as an input.

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);         // Start serial communication at 9600 baud rate
        pinMode(sensorPin, INPUT);  // Set the sensorPin as an input pin
      }

3. The ``loop()`` function is where we continuously check for any vibrations detected by the sensor. If the sensor detects a vibration, it prints "Detected vibration..." to the serial monitor. If no vibration is detected, it prints "...". The loop repeats every 100 milliseconds.

   .. code-block:: arduino
   
      void loop() {
        if (digitalRead(sensorPin)) {               // Check if there is any vibration detected by the sensor
          Serial.println("Detected vibration...");  // Print "Detected vibration..." if vibration detected
        } 
        else {
          Serial.println("...");  // Print "..." otherwise
        }
        // Add a delay to avoid flooding the serial monitor
        delay(100);
      }