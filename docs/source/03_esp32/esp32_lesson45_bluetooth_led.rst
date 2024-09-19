.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_bluetooth_led:


Lesson 45: Bluetooth Control RGB LED
===============================================

This project is an extension of a previous project(:ref:`esp32_bluetooth`), 
adding RGB LED configurations and custom commands such as "led_off", "red", "green", etc. These commands allow the RGB LED to be controlled by sending commands from a mobile device using LightBlue.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**Operation Steps**

#. Build the circuit.

    .. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png

#. Open the ``Lesson_45_Bluetooth_RGB.ino`` file located in the ``universal-maker-sensor-kit\esp32\Lesson_45_Bluetooth_RGB`` directory, or copy the code into the Arduino IDE.

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/714bacdf-4ee6-4f6e-8ac3-04e328154d7a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. To avoid UUID conflicts, it is recommended to randomly generate three new UUIDs using the |link_uuid| provided by the Bluetooth SIG, and fill them in the following lines of code.

    .. note::
        If you have already generated three new UUIDs in the :ref:`esp32_bluetooth` project, then you can continue using them.


    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. Select the correct board and port, then click the **Upload** button.

#. After the code has been successfully uploaded, turn on **Bluetooth** on your mobile device and open the **LightBlue** app.

    .. image:: img/bluetooth_open.png

#. On the **Scan** page, find **ESP32-Bluetooth** and click **CONNECT**. If you don't see it, try refreshing the page a few times. When **"Connected to device!"** appears, the Bluetooth connection is successful. Scroll down to see the three UUIDs set in the code.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Tap the Send UUID, then set the data format to "UTF-8 String". Now you can write these commands: "led_off", "red", "green", "blue", "yellow", and "purple" to see if the RGB LED responds to these instructions.

    .. image:: img/bluetooth_send_rgb.png
    

**How it works?**

This code is an extension of a previous project(:ref:`esp32_bluetooth`), adding RGB LED configurations and custom commands such as "led_off", "red", "green", etc. These commands allow the RGB LED to be controlled by sending commands from a mobile device using LightBlue.

Let's break down the code step by step:

* Add new global variables for the RGB LED pins, PWM channels, frequency, and resolution.

    .. code-block:: arduino

        ...

        // Define RGB LED pins
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        // Define PWM channels
        const int redChannel = 0;
        const int greenChannel = 1;
        const int blueChannel = 2;

        ...

* Within the ``setup()`` function, the PWM channels are initialized with the predefined frequency and resolution. The RGB LED pins are then attached to their respective PWM channels.

    .. code-block:: arduino
        
        void setup() {
            ...

            // Set up PWM channels
            ledcSetup(redChannel, freq, resolution);
            ledcSetup(greenChannel, freq, resolution);
            ledcSetup(blueChannel, freq, resolution);
            
            // Attach pins to corresponding PWM channels
            ledcAttachPin(redPin, redChannel);
            ledcAttachPin(greenPin, greenChannel);
            ledcAttachPin(bluePin, blueChannel);

        }

* Modify the ``onWrite`` method in the ``MyCharacteristicCallbacks`` class. This function listens for data coming from the Bluetooth connection. Based on the received string (like ``"led_off"``, ``"red"``, ``"green"``, etc.), it controls the RGB LED.

    .. code-block:: arduino

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = pCharacteristic->getValue();
                if (value == "led_off") {
                    setColor(0, 0, 0); // turn the RGB LED off
                    Serial.println("RGB LED turned off");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Red
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // green
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // blue
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // yellow
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // purple
                    Serial.println("purple");
                }
            }
        };

* Finally, a function is added to set the RGB LED color.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redChannel, red);
            ledcWrite(greenChannel, green);
            ledcWrite(blueChannel, blue);
        }

In summary, this script enables a remote control interaction model, where the ESP32 operates as a Bluetooth Low Energy (BLE) server.

The connected BLE client (like a smartphone) can send string commands to change the color of an RGB LED. The ESP32 also gives feedback to the client by sending back the string received, allowing the client to know what operation was performed.
