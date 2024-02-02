.. _uno_lesson18_ds18b20:

Lesson 18: Temperature Sensor Module (DS18B20)
================================================

In this lesson, you'll learn how to read temperature data from a DS18B20 sensor using Arduino. We'll cover using the DallasTemperature library to communicate with the sensor and display readings in both Celsius and Fahrenheit on the Serial Monitor. This project is ideal for Arduino beginners, providing practical experience with temperature sensors and data processing.

Required Components
---------------------------

* Arduino UNO R3 or R4
* :ref:`cpn_ds18b20`

Wiring
---------------------------

.. image:: img/Lesson_18_DS18B20_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7619d902-81b3-4faa-bdf4-29b4429ccd54/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Library inclusion

   The inclusion of the OneWire and DallasTemperature libraries allows communication with the DS18B20 sensor.

   .. code-block:: arduino

      #include <OneWire.h>
      #include <DallasTemperature.h>

#. Defining the sensor data pin

   The DS18B20 is connected to digital pin 2 of the Arduino.

   .. code-block:: arduino

      #define ONE_WIRE_BUS 2

#. Initializing the sensor

   The OneWire instance and DallasTemperature object are created and initialized.

   .. code-block:: arduino

      OneWire oneWire(ONE_WIRE_BUS);	
      DallasTemperature sensors(&oneWire);

#. Setup function

   The ``setup()`` function initializes the sensor and sets up serial communication.

   .. code-block:: arduino

      void setup(void)
      {
         sensors.begin();	// Start up the library
         Serial.begin(9600);
      }

#. Main loop

   In the ``loop()`` function, the program requests temperature readings and prints them in both Celsius and Fahrenheit.

   .. code-block:: arduino

      void loop(void)
      { 
         sensors.requestTemperatures();
         Serial.print("Temperature: ");
         Serial.print(sensors.getTempCByIndex(0));
         Serial.print("℃ | ");
         Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
         Serial.println("℉");
         delay(500);
      }