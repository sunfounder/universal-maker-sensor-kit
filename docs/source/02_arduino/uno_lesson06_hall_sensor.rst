.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson06_hall_sensor:

Lesson 06: Hall Sensor Module
==================================

In this lesson, you will learn how a Hall sensor detects magnetic fields using Arduino. We'll explore how to read the sensor's analog signal with Arduino Uno, interpreting the values to determine the polarity of a magnetic field. You'll understand the workings of the Hall sensor, and how the Arduino board processes and displays these readings in real-time. 

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_hall`
        - \-
        

Wiring
---------------------------

.. image:: img/Lesson_06_hall_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fc459930-a030-4a1d-b998-e57a6a4f2e78/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Setting up the Hall Sensor

   .. code-block:: arduino

      const int hallSensorPin = A0;  // Pin A0 connected to the Hall sensor output
      void setup() {
        Serial.begin(9600);             // Initialize serial communication at 9600 bps
        pinMode(hallSensorPin, INPUT);  // Set hall sensor pin as input
      }

   The hall sensor's output is connected to pin A0 on the Arduino. The ``setup()`` function is used to initialize serial communication at 9600 bits per second (bps) for displaying data on the serial monitor. The ``pinMode()`` function is used to configure A0 as an input pin.

2. Reading from the Hall Sensor and Determining Polarity

   The Hall sensor module is equipped with a 49E linear Hall effect sensor, which can measure the polarity of the magnetic field's north and south poles as well as the relative strength of the magnetic field. If you place a magnet's south pole near the side marked with 49E (the side with text engraved on it), the value read by the code will increase linearly in proportion to the applied magnetic field strength. Conversely, if you place a north pole near this side, the value read by the code will decrease linearly in proportion to that magnetic field strength. For more details, please refer to :ref:`cpn_hall`.

   .. code-block:: arduino

      void loop() {
        int sensorValue = analogRead(hallSensorPin);  // Read analog value from Hall sensor
        Serial.print(sensorValue);                    // Output raw sensor value to Serial Monitor
        delay(200);                                   // Delay for 200 milliseconds

        // Determine magnetic pole based on sensor value
        if (sensorValue >= 700) {
          Serial.print(" - South pole detected");  // South pole detected if value >= 700
        } else if (sensorValue <= 300) {
          Serial.print(" - North pole detected");  // North pole detected if value <= 300
        }

        Serial.println();  // New line for next output
      }

