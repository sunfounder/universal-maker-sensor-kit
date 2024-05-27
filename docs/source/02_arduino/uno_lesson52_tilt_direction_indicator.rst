
.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_iot_intrusion_alert_system:

Lesson 52: Tilt Direction Indicator
===========================================

This Arduino project uses an MPU6050 accelerometer and gyroscope sensor along with an OLED display. The project reads data from the MPU6050 sensor to detect the tilt direction and displays corresponding arrows (up, down, left, or right) or a circle (if there is no significant tilt) on the OLED screen based on the tilt direction.


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
    *   - :ref:`cpn_mpu6050`
        - |link_mpu6050_buy|
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Wiring
---------------------------

.. image:: img/Lesson_52_Tilt_direction_indicatorr_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src="https://app.arduino.cc/sketches/ea5345ae-b849-424d-9b61-9a192695aef8?view-mode=embed" style="height:510px;width:100%;margin:10px 0" frameborder=0 /></iframe>


Code Analysis
---------------------------

#. Library inclusion and OLED display setup

   The project starts by including the necessary libraries to interface with the MPU6050 sensor and OLED display. The OLED display dimensions and I2C address are defined, followed by the creation of the display object.

   .. code-block:: arduino

       #include <Adafruit_MPU6050.h>
       #include <Adafruit_Sensor.h>
       #include <Wire.h>
       #include <Adafruit_GFX.h>
       #include <Adafruit_SSD1306.h>

       #define SCREEN_WIDTH 128
       #define SCREEN_HEIGHT 64

       #define OLED_RESET -1
       #define SCREEN_ADDRESS 0x3C
       Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

       Adafruit_MPU6050 mpu;

#. Setup function

   In the setup function, the serial communication is initialized, and the MPU6050 sensor is initialized with specific settings for accelerometer and gyroscope ranges. The OLED display is also initialized and cleared.

   .. code-block:: arduino

       void setup(void) {
         Serial.begin(115200);

         if (!mpu.begin()) {
           Serial.println("Failed to find MPU6050 chip");
           while (1) {
             delay(10);
           }
         }

         mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
         mpu.setGyroRange(MPU6050_RANGE_500_DEG);
         mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

         if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
           Serial.println(F("SSD1306 allocation failed"));
           for (;;)
             ;  // Don't proceed, loop forever
         }
         display.clearDisplay();

         delay(100);
       }

#. Loop function

   In the loop function, sensor data is continuously read, and the tilt direction is determined based on acceleration values. Depending on the tilt direction, different arrows or a circle are drawn on the OLED display.

   The code reads data from the MPU6050 sensor to detect the tilt direction and displays corresponding arrows (up, down, left, or right) or a circle (if there is no significant tilt) on the OLED screen based on the tilt direction.

   .. code-block:: arduino

       void loop() {

         display.clearDisplay();

         sensors_event_t a, g, temp;
         mpu.getEvent(&a, &g, &temp);

         Serial.print("acceleration:");
         Serial.print(a.acceleration.x);
         Serial.print(",");
         Serial.print(a.acceleration.y);
         Serial.print(",");
         Serial.println(a.acceleration.z);

         if (a.acceleration.x >= 2) {
           drawUpArrow();
         } else if (a.acceleration.x <= -2) {
           drawDownArrow();
         } else if (a.acceleration.y >= 2) {
           drawLeftArrow();
         } else if (a.acceleration.y <= -2) {
           drawRightArrow();
         } else {
           drawCircle();
         }
         display.display();

         delay(200);
       }

#. Drawing functions

   Several helper functions are defined to draw different shapes on the OLED display. These functions use the ``Adafruit_GFX`` library to draw arrows and circles.

   .. code-block:: arduino

       void drawUpArrow() {
         display.fillTriangle(49, 30, 64, 15, 79, 30, WHITE);
         display.fillRect(59, 30, 10, 20, WHITE);
       }

       void drawDownArrow() {
         display.fillTriangle(49, 36, 64, 51, 79, 36, WHITE);
         display.fillRect(59, 16, 10, 20, WHITE);
       }

       void drawRightArrow() {
         display.fillTriangle(70, 15, 85, 30, 70, 45, WHITE);
         display.fillRect(50, 25, 20, 10, WHITE);
       }

       void drawLeftArrow() {
         display.fillTriangle(60, 15, 45, 30, 60, 45, WHITE);
         display.fillRect(60, 25, 20, 10, WHITE);
       }

       void drawCircle() {
         display.fillCircle(64, 32, 10, WHITE);
         display.fillCircle(64, 32, 8, BLACK);
       }


**Reference**

- |link_adafruit_gfx_graphics_library|

