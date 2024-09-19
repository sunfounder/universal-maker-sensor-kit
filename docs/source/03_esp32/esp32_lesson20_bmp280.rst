.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_lesson20_bmp280:

Lesson 20: Temperature, Humidity & Pressure Sensor (BMP280)
====================================================================

In this lesson, you will learn how to measure atmospheric pressure, temperature, and approximate altitude using the BMP280 sensor with an ESP32 Development Board. We will cover interfacing the sensor with the Adafruit BMP280 library and displaying readings on the Serial Monitor. This tutorial is ideal for those seeking to enhance their understanding of environmental sensing and data logging on the ESP32 platform.

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

    *   - ESP32 & Development Board (:ref:`cpn_esp32_wroom_32e`)
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_bmp280`
        - |link_bmp280_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_20_bmp280_esp32_bb.png
    :width: 100%


Code
---------------------------

.. note:: 
   To install the library, use the Arduino Library Manager and search for **"Adafruit BMP280"** and install it. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/25c4b695-7d09-47f5-9385-61d239afa214/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Including Libraries and Initialization. Necessary libraries are included and the BMP280 sensor is initialized for communication using the I2C interface.

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"Adafruit BMP280"** and install it. 

   - Adafruit BMP280 Library: This library provides an easy-to-use interface for the BMP280 sensor, allowing the user to read temperature, pressure, and altitude. 
   - Wire.h: Used for I2C communication.

   .. raw:: html
    
    <br/>

   .. code-block:: arduino
    
      #include <Wire.h>
      #include <Adafruit_BMP280.h>
      #define BMP280_ADDRESS 0x76
      Adafruit_BMP280 bmp;  // use I2C interface


2. The ``setup()`` function initializes the Serial communication, checks for the BMP280 sensor, and sets up the sensor with default settings.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        while (!Serial) delay(100);
        Serial.println(F("BMP280 test"));
        unsigned status;
        status = bmp.begin(BMP280_ADDRESS);
        // ... (rest of the setup code)

3. The ``loop()`` function reads data from the BMP280 sensor for temperature, pressure, and altitude. This data is printed to the Serial Monitor.

   .. code-block:: arduino

      void loop() {
        // ... (read and print temperature, pressure, and altitude data)
        delay(2000);  // 2-second delay between readings.
      }
