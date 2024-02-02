.. _esp32_lesson25_water_level:

Lesson 25: Water Level Sensor Module
=========================================

In this lesson, you'll learn how to use an ESP32 Development Board for reading a water level sensor. We'll cover continuously monitoring the sensor's analog value and displaying it on the serial monitor. This project provides a great opportunity to grasp sensor integration and analog data reading with Arduino, making it ideal for beginners in electronics and microcontroller programming.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_water_level`
* :ref:`cpn_breadboard` 

Wiring
---------------------------

.. image:: img/Lesson_25_Water_Level_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f312bfd8-5583-4d54-a116-35e32d957ef6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. **Initializing the Sensor Pin**:

   Before using the water level sensor, it's pin number is defined using a constant variable. This makes the code more readable and easier to modify.

   .. code-block:: arduino

      const int sensorPin = 25;

#. **Setting Up Serial Communication**:

   In the ``setup()`` function, the baud rate for serial communication is set. This is crucial for the Arduino to communicate with the computer's serial monitor.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  // Start serial communication at 9600 baud rate
      }

#. **Reading Sensor Data and Outputting to Serial Monitor**:

   The ``loop()`` function continuously reads the sensor's analog value using ``analogRead()`` and outputs it to the serial monitor using ``Serial.println()``. The ``delay(100)`` function makes the Arduino wait for 100 milliseconds before repeating the loop, controlling the rate of data reading and transmission.

   .. code-block:: arduino
    
      void loop() {
        Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
        delay(100);                             // Wait for 100 milliseconds
      }