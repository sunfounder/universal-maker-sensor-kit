
.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_plant_monitor:

Lesson 43: Plant Monitor
=============================================================


This project intelligently automates plant watering by triggering a water pump whenever the soil's 
moisture level dips below a predetermined threshold. 
It also features an LCD display that showcases the temperature, humidity, 
and soil moisture levels, offering users valuable insights into the plant's environmental conditions.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_power_module`
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_dht11`
        - \-

Wiring
---------------------------

.. image:: img/Lesson_43_Plant_monitor_esp32_bb.png
    :width: 100%


Code
---------------------------

.. note:: 
   To install the library, use the Arduino Library Manager and search for **"LiquidCrystal I2C"** and **"DHT sensor library"** and install it.  

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c769b454-80f4-4516-83ce-9ff702d8627f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Code Analysis
---------------------------

The code is structured to seamlessly manage plant watering by monitoring environmental parameters:

1. Library Inclusions and Constants/Variables:

    Incorporate ``Wire.h``, ``LiquidCrystal_I2C.h``, and ``DHT.h`` libraries for functionality.
    Specify pin assignments and settings for the DHT11 sensor, soil moisture sensor, and water pump.

    .. code-block:: arduino

        #include <Wire.h>
        #include <LiquidCrystal_I2C.h>
        #include <DHT.h>

        #define DHTPIN 14              // Digital pin for DHT11 sensor
        #define DHTTYPE DHT11         // DHT11 sensor type
        #define SOIL_MOISTURE_PIN 35  // Analog pin for soil moisture sensor
        #define WATER_PUMP_PIN 25      // Digital pin for water pump


        // Initialize sensor and LCD objects
        DHT dht(DHTPIN, DHTTYPE);
        LiquidCrystal_I2C lcd(0x27, 16, 2);



2. ``setup()``:

    Configure pin modes for the moisture sensor and pump.
    Initially deactivate the pump.
    Initialize and backlight the LCD.
    Activate the DHT sensor.

    .. code-block:: arduino

        void setup() {
            // Set pin modes
            pinMode(SOIL_MOISTURE_PIN, INPUT);
            pinMode(WATER_PUMP_PIN, OUTPUT);

            // Initialize water pump as off
            digitalWrite(WATER_PUMP_PIN, LOW);

            // Initialize LCD and backlight
            lcd.init();
            lcd.backlight();

            // Start DHT sensor
            dht.begin();
        }




3. ``loop()``:

    Measure humidity and temperature via the DHT sensor.
    Gauge soil moisture through the soil moisture sensor.
    Display the temperature and humidity on the LCD, then show soil moisture levels.
    Assess soil moisture to decide on water pump activation; if soil moisture is under 500 (adjustable threshold), run the pump for 1 second.

    .. code-block:: arduino

        void loop() {
            // Read humidity and temperature from DHT11
            float humidity = dht.readHumidity();
            float temperature = dht.readTemperature();

            // Read soil moisture level
            int soilMoisture = analogRead(SOIL_MOISTURE_PIN);

            // Display temperature and humidity on LCD
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Temp: " + String(temperature) + "C");
            lcd.setCursor(0, 1);
            lcd.print("Humidity: " + String(humidity) + "%");

            delay(2000);

            // Display soil moisture on LCD
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Soil Moisture: ");
            lcd.setCursor(0, 1);
            lcd.print(String(soilMoisture));

            // Activate water pump if soil is dry
            if (soilMoisture > 650) {
                digitalWrite(WATER_PUMP_PIN, HIGH);  // Turn on water pump
                delay(1000);                         // Pump water for 1 second
                digitalWrite(WATER_PUMP_PIN, LOW);   // Turn off water pump
            }

            delay(2000);  // Wait before next loop iteration
        }

