.. _esp32_lesson21_vl53l0x:

Lesson 21: Time of Flight Micro-LIDAR Distance Sensor (VL53L0X)
====================================================================

In this lesson, you will learn how to use the Adafruit VL53L0X Time of Flight Distance Sensor with an ESP32 Development Board. We'll cover initializing the sensor, reading distance measurements, and displaying them in millimeters on the serial monitor.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_VL53L0X`
* :ref:`cpn_breadboard` 

Wiring
---------------------------

.. image:: img/Lesson_21_VL53L0X_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2f8bf48c-e404-4a3d-a9ac-eb1878f54017/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

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

#. Capturing and displaying the measurements in the ``loop()`` function. Continuously, the ESP32 Development Board captures a distance measurement using the ``rangingTest()`` method. If the measurement is valid, it's printed to the serial monitor.

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