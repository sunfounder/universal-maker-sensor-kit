.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson41_heartrate_monitor:

Lesson 41: Heart rate monitor
==================================

This Arduino project aims to build a simple Heart Rate Monitor using a MAX30102 pulse oximeter sensor and an SSD1306 OLED Display. The code takes measurements of the heart rate by determining the time between heartbeats. By taking four measurements, it computes their average and presents the resultant average heart rate on an OLED screen. If the sensor doesn't detect a finger, it sends a prompt to the user to position their finger correctly on the sensor.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_max30102`
        - |link_max30102_module_buy|
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Wiring
---------------------------

.. image:: img/Lesson_41_Heart_rate_monitor_uno_bb.png
    :width: 100%


Code
---------------------------

.. note:: 
   To install the library, open the Arduino Library Manager, search for **"SparkFun MAX3010x"** , **"Adafruit SSD1306"** , and **"Adafruit GFX"**, then install them.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0f574652-4575-46b9-88b7-2d30573bcb71/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

The main principle behind this project is to capture the pulsation of blood flow through a finger using the MAX30102 sensor. As blood pumps through the body, it causes tiny changes in the volume of blood in the vessels of the fingertip. By shining light through the finger and measuring the amount of light that gets absorbed or reflected back, the sensor detects these minute volume changes. The time interval between subsequent pulses is then used to calculate the heart rate in beats per minute (BPM). This value is then averaged over four measurements and displayed on the OLED screen.


1. **Library Inclusions and Initial Declarations**:

   The code begins by including necessary libraries for the OLED display, MAX30102 sensor, and heart rate calculation. Additionally, the configuration for the OLED display and the variables for heart rate calculation are declared.

   .. note:: 
      To install the library, open the Arduino Library Manager, search for **"SparkFun MAX3010x"** , **"Adafruit SSD1306"** , and **"Adafruit GFX"**, then install them.

   .. code-block:: arduino

      #include <Adafruit_GFX.h>  // OLED  libraries
      #include <Adafruit_SSD1306.h>
      #include <Wire.h>
      #include "MAX30105.h"   // MAX3010x library
      #include "heartRate.h"  // Heart rate  calculating algorithm

      // ... Variables and OLED configuration

   In this project, we've also whipped up a couple of bitmaps. The ``PROGMEM`` keyword denotes that the array is stored in the program memory of the Arduino microcontroller. Storing data in program memory(PROGMEM) instead of RAM can be helpful for large amounts of data, which would otherwise take up too much space in RAM.


   .. code-block:: arduino

      static const unsigned char PROGMEM beat1_bmp[] = {...}

      static const unsigned char PROGMEM beat2_bmp[] = {...}

2. **Setup Function**:

   Initializes I2C communication, starts serial communication, initializes the OLED display, and sets up the MAX30102 sensor.

   .. code-block:: arduino

      void setup() {
          Wire.setClock(400000);
          Serial.begin(9600);
          display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
          // ... Rest of the setup code

3. **Main Loop**:

   The core functionality resides here. The IR value is read from the sensor. If a finger is detected (IR value greater than 50,000), the program checks if a heartbeat is sensed. When a heartbeat is detected, the OLED screen displays the BPM and the time between heartbeats is used to calculate BPM. Otherwise, it prompts the user to place their finger on the sensor.
   
   We have also prepared two bitmaps with heartbeats, and by switching between these two bitmaps, we can achieve a dynamic visual effect.

   .. code-block:: arduino

      void loop() {
        // Get IR value from sensor
        long irValue = particleSensor.getIR();  
      
        //If a finger is detected
        if (irValue > 50000) {
      
          // Check if a beat is detected
          if (checkForBeat(irValue) == true) {

            // Update OLED display
            // Calculate the BPM
      
            // Calculate the average BPM
            //Print the IR value, current BPM value, and average BPM value to the serial monitor

            // Update OLED display
            
          }
        }
        else {
          // ... Prompt to place the finger on the sensor
        }
      }
      

