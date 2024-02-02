.. _uno_lesson21_vl53l0x:

Lesson 21: Time of Flight Micro-LIDAR Distance Sensor (VL53L0X)
====================================================================

In this lesson, you will learn how to use the VL53L0X Time of Flight Distance Sensor with an Arduino Uno. We'll cover the basics of connecting the sensor to measure distances in millimeters and displaying the readings on the serial monitor. This project provides hands-on experience with advanced sensors and their real-world applications, enhancing your Arduino skills.

Required Components
---------------------------

* Arduino UNO R3 or R4
* :ref:`cpn_VL53L0X`

Wiring
---------------------------

.. image:: img/Lesson_21_VL53L0X_module_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/72c81822-13e0-4a33-8da0-acf3c966bf57/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Including the necessary library and initializing the sensor object. We start by including the library for the VL53L0X sensor and creating an instance of the Adafruit_VL53L0X class.

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"Adafruit_VL53L0X"** and install it.  

   .. code-block:: arduino

      #include <Adafruit_VL53L0X.h>
      Adafruit_VL53L0X lox = Adafruit_VL53L0X();

#. Initialization in the ``setup()`` function. Here, we set up serial communication and initialize the distance sensor. If the sensor can't be initialized, the program halts.

   .. code-block:: arduino

      void setup() {
        Serial.begin(115200);
        while (!Serial) {
          delay(1);
        }
        Serial.println("Adafruit VL53L0X test");
        if (!lox.begin()) {
          Serial.println(F("Failed to boot VL53L0X"));
          while (1)
            ;
        }
        Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
      }

#. Capturing and displaying the measurements in the ``loop()`` function. Continuously, the Arduino captures a distance measurement using the ``rangingTest()`` method. If the measurement is valid, it's printed to the serial monitor.

   .. code-block:: arduino
       
      void loop() {
        VL53L0X_RangingMeasurementData_t measure;
        Serial.print("Reading a measurement... ");
        lox.rangingTest(&measure, false);
        if (measure.RangeStatus != 4) {
          Serial.print("Distance (mm): ");
          Serial.println(measure.RangeMilliMeter);
        } else {
          Serial.println(" out of range ");
        }
        delay(100);
      }