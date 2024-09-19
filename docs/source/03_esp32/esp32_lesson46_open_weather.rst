.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_iot_owm:



Lesson 46: Real-time Weather From @OpenWeatherMap
====================================================

The IoT Open Weather Display project utilizes the ESP32 board and an I2C LCD1602 module to create a weather information display that retrieves data from the OpenWeatherMap API. 

This project serves as an excellent introduction to working with APIs, Wi-Fi connectivity, and data display on an LCD module using the ESP32 board. With the IoT Open Weather Display, you can conveniently access real-time weather updates at a glance, making it an ideal solution for home or office environments.

**Required Components**

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

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board (:ref:`cpn_esp32_wroom_32e`)
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Get OpenWeather API keys**

|link_openweather| is an online service, owned by OpenWeather Ltd, that provides global weather data via API, including current weather data, forecasts, nowcasts and historical weather data for any geographical location.

#. Visit |link_openweather| to log in/create an account.

    .. image:: img/OWM-1.png

#. Click into the API page from the navigation bar.

    .. image:: img/OWM-2.png

#. Find **Current Weather Data** and click Subscribe.

    .. image:: img/OWM-3.png

#. Under **Current weather and forecasts collection** , subscribe to the appropriate service. In our project, Free is good enough.

    .. image:: img/OWM-4.png

#. Copy the Key from the **API keys** page.

    .. image:: img/OWM-5.png


**Complete Your Device**

#. Build the circuit.

    .. image:: img/Lesson_26_LCD1602_esp32_bb.png
        :width: 800

#. Open the code.

    * Open the ``Lesson_46_OpenWeatherMap.ino`` file located in the ``universal-maker-sensor-kit\esp32\Lesson_46_OpenWeatherMap`` directory, or copy the code into the Arduino IDE.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``LiquidCrystal I2C``  and ``Arduino_JSON`` libraries are used here, you can install them from the **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5e262afa-97ca-45ba-807b-adf7650b30e8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
         

#. Locate the following lines and modify them with your ``<SSID>`` and ``<PASSWORD>``.


    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Fill in the API keys you copied earlier into ``openWeatherMapApiKey``.

    .. code-block::  Arduino

        // Your Domain name with URL path or IP address with path
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. Replace with your country code and city.

    .. code-block::  Arduino

        // Replace with your country code and city
        // Fine the country code by https://openweathermap.org/find
        String city = "<CITY>";
        String countryCode = "<COUNTRY CODE>";

#. After the code runs, you will see the time and weather information of your location on the I2C LCD1602.

.. note::
   When the code is running, if the screen is blank, you can turn the potentiometer on the back of the module to increase the contrast.

