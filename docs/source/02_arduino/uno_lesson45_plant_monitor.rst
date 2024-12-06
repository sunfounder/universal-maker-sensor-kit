
.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_lesson45_plant_monitor:

Lesson 45: Plant Monitor
=============================================================


This project intelligently automates plant watering by triggering a water pump whenever the soil's moisture level dips below a predetermined threshold. 
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

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
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

.. note:: 
   The kit may contain different versions of the DHT11 module. Please confirm the wiring method according to the module you have.

.. image:: img/Lesson_45_Plant_monitor_uno_bb.png
    :width: 100%

.. image:: img/Lesson_45_Plant_monitor_uno_new_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/700a51fb-6bb3-46c0-b0eb-5b03a6eb681e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Code Analysis
---------------------------



The code is structured to seamlessly manage plant watering by monitoring environmental parameters:

1. Library Inclusions and Constants/Variables:

   Incorporate ``Wire.h``, ``LiquidCrystal_I2C.h``, and ``DHT.h`` libraries for functionality.
   Specify pin assignments and settings for the DHT11 sensor, soil moisture sensor, and water pump.

2. ``setup()``:

   Configure pin modes for the moisture sensor and pump.
   Initially deactivate the pump.
   Initialize and backlight the LCD.
   Activate the DHT sensor.

3. ``loop()``:

   Measure humidity and temperature via the DHT sensor.
   Gauge soil moisture through the soil moisture sensor.
   Display the temperature and humidity on the LCD, then show soil moisture levels.
   Assess soil moisture to decide on water pump activation; if soil moisture is under 500 (adjustable threshold), run the pump for 1 second.




