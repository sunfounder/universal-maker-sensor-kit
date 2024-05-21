.. https://github.com/sunfounder/ultimate-sensor-kit/blob/docs/docs/source/iot_project/01-iot_Flame_alert_system.rst

.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _uno_iot_flame:

Lesson 50: Flame Alert System with Blynk
============================================================



In this chapter, we will guide you through the process of creating a home flame alarm system demo using Blynk. By utilizing a flame sensor, you can detect potential fires in your home. Sending the detected values to Blynk allows for remote monitoring of your home via the internet. In case of a fire, Blynk will promptly notify you via email.


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
    *   - :ref:`cpn_esp8266`
        - \-
    *   - :ref:`cpn_flame`
        - \-


Wiring
---------------------------

.. image:: img/Lesson_50_Iot_flame_alert_system_uno_bb.png
    :width: 100%



Configure Blynk
-----------------------------

**1 Create template**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Firstly, we need to establish a template on Blynk. Follow the steps below to create a **"Flame Alert System"** template. 

.. image:: img/01-create_template_1_shadow.png
    :width: 70%
    :align: center

Ensure that the **HARDWARE** is configured as **ESP8266** and the **CONNECT TYPE** is set to **WiFi**.

.. image:: img/01-create_template_2_shadow.png
    :width: 70%
    :align: center

.. raw:: html
    
    <br/>  

**2 Datastream**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Create a **Datastream** of type **Virtual Pin** in the **Datastream** page to get the value of Flame sensor module. 

.. image:: img/01-datastream_1_shadow.png
    :width: 90%
    :align: center

Set the name of the **Virtual Pin** to ``flame_sensor_value``. Set the **DATA TYPE** to **Integer** and MIN and MAX to **0** and **1**.

.. image:: img/01-datastream_2_shadow.png
    :width: 90%
    :align: center

.. raw:: html
    
    <br/> 

**3 Event**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Next, we will create an **event** that logs the detection of flames and sends an email notification.

.. image:: img/01-event_1_shadow.png
    :width: 80%
    :align: center

.. note::
    It is recommended to keep it consistent with my settings, otherwise you may need to modify the code to run the project.

Set **EVENT NAME** to ``flame_detection_alert``. At the same time, you can customize the content of email sent by setting **DESCRIPTION** for event triggering. You can also set frequency limits for event triggering below.

.. image:: img/01-event_2_shadow.png
    :width: 80%
    :align: center

Go to the **Notifications** page and configure email settings.

.. image:: img/01-event_3_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/> 

**4 Web Dashboard**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

We also need to set up the **Web Dashboard** to display the sensor data sent from the Uno board.

Drag and drop an **Label widget** on the **Web Dashboard** page.

.. image:: img/01-web_dashboard_1_shadow.png
    :width: 100%
    :align: center

In the settings page of the **Label widget**, select **Datastream** as **flame_sensor_value(V0)**. Then set the color of **WIDGET BACKGROUND** to change with the value of data. When the displayed value is 1, it will be shown in green. When the value is 0, it will be shown in red.

.. image:: img/01-web_dashboard_2_shadow.png
    :width: 100%
    :align: center

.. image:: img/01-web_dashboard_3_shadow.png
    :width: 100%
    :align: center

.. raw:: html
    
    <br/> 

**5 Save template**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

At last, remember to save the template.

.. image:: img/01-save_template_shadow.png
    :width: 70%
    :align: center

In case you need to edit the template, you can click on the edit button in the upper right corner.

.. image:: img/01-save_template_2_shadow.png
    :width: 70%
    :align: center

.. raw:: html
    
    <br/> 


Code
----------------------- 

#. Open the ``Lesson_50_Flame_alert_system.ino`` file under the path of ``universal-maker-sensor-kit\arduino_uno\Lesson_50_Flame_alert_system``, or copy this code into **Arduino IDE**.


   .. raw:: html
       
       <iframe src=https://create.arduino.cc/editor/sunfounder01/ef829dd7-337d-475d-908b-d118c6a93eef/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Create a Blynk device using the Flame Detection Alert template. Then, replace the ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME``, and ``BLYNK_AUTH_TOKEN`` with your own. 

   .. code-block:: arduino
    
      #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
      #define BLYNK_TEMPLATE_NAME "Flame Alert System"
      #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"
   
   .. image:: img/01-create_device_1_shadow.png
    :width: 80%
    :align: center

   .. image:: img/01-create_device_2_shadow.png
    :width: 80%
    :align: center

   .. image:: img/01-create_device_3_shadow.png
    :width: 80%
    :align: center

   .. image:: img/01-create_device_4_shadow.png
    :width: 80%
    :align: center

#. You also need to enter the ``ssid`` and ``password`` of the WiFi you are using. 

   .. code-block:: arduino

    char ssid[] = "your_ssid";
    char pass[] = "your_password";

#. After selecting the correct board and port, click the **Upload** button.

#. Open the Serial monitor(set baudrate to 115200) and wait for a prompt such as a successful connection to appear.

   .. image:: img/01-ready_1_shadow.png
    :width: 80%
    :align: center

   .. note::

       If the message ``ESP is not responding`` appears when you connect, please follow these steps.

       * Make sure the 9V battery is plugged in.
       * Reset the ESP8266 module by connecting the pin RST to GND for 1 second, then unplug it.
       * Press the reset button on the R4 board.

       Sometimes, you may need to repeat the above operation 3-5 times, please be patient.

#. Now, Blynk will show the data read from flame sensor. In the label widget, you can see the value read by the flame sensor. When the displayed value is 1, the background of the label will be shown in green. When the value is 0, the background of the label will be shown in red and Blynk will send you an alert email.
   
   .. image:: img/01-ready_2_shadow.png
    :width: 80%
    :align: center

#. If you want to use Blynk on mobile devices, please refer to :ref:`blynk_mobile`.

Code Analysis
---------------------------

1. **Library Initialization**

   Before we start, it's crucial to set up the necessary libraries and settings for communication between the Arduino, ESP8266 WiFi module, and Blynk app. This code sets up the required libraries and configures a software serial connection between the Arduino and ESP8266 module, with the appropriate baud rate for data transmission.
   
   .. code-block:: arduino
   
       //Set debug prints on Serial Monitor
       #define BLYNK_PRINT Serial
   
       #include <ESP8266_Lib.h>               // Library for ESP8266
       #include <BlynkSimpleShieldEsp8266.h>  // Library for Blynk
   
       // Software Serial on Uno
       #include <SoftwareSerial.h>
       SoftwareSerial EspSerial(2, 3);  // RX, TX
       #define ESP8266_BAUD 115200      // Set the ESP8266 baud rate
       ESP8266 wifi(&EspSerial);

2. **Blynk and WiFi configuration**

   For the project to communicate with the Blynk app, it needs to connect to a Wi-Fi network. The credentials need to specified here.
   
   .. code-block:: arduino

      // Template ID, Device Name and Auth Token are provided by the Blynk Cloud
      // See the Device Info tab, or Template settings
      #define BLYNK_TEMPLATE_ID "TMPxxxxxx"
      #define BLYNK_TEMPLATE_NAME "Flame Alert System"
      #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxx" 
      
      // Your WiFi credentials.
      // Set password to "" for open networks.
      char ssid[] = "your_ssid";
      char pass[] = "your_password";

3. **Sensor Pin & Timer Declaration**

   Define the pin number for the flame.
   Blynk library provides a built-in timer, and we create a timer object. More about |link_blynk_timer_intro| 

   .. code-block:: arduino

       const int sensorPin = 8;
       BlynkTimer timer;

4. **setup() Function**

   Initial configurations such as setting the pin mode for the sensorPin, initiating serial communication, setting the BlynkTimer, and connecting to the Blynk app are done in this function.

   - We use ``timer.setInterval(1000L, myTimerEvent)`` to set the timer interval in setup(), here we set to execute the ``myTimerEvent()`` function every **1000ms**. You can modify the first parameter of ``timer.setInterval(1000L, myTimerEvent)`` to change the interval between ``myTimerEvent`` executions.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

       void setup() {
         pinMode(sensorPin, INPUT);
         Serial.begin(115200);
         EspSerial.begin(ESP8266_BAUD);
         delay(1000);
         timer.setInterval(1000L, myTimerEvent);
         Blynk.config(wifi,BLYNK_AUTH_TOKEN);
         Blynk.connectWiFi(ssid, pass);
       }

5. **loop() Function**

   The main loop runs the Blynk and Timer services continuously.

   .. code-block:: arduino

       void loop() {
         Blynk.run();
         timer.run();
       }

6. **myTimerEvent() & sendData() Function**

   

   .. code-block:: arduino
 
       void myTimerEvent() {
         // Please don't send more that 10 values per second.
         sendData();  // Call function to send sensor data to Blynk app
       }

   The ``sendData()`` function reads the value from the flame sensor and sends it to Blynk. If it detects a flame (value 0), it sends ``flame_detection_alert`` event to the Blynk app.

   - Use ``Blynk.virtualWrite(vPin, value)`` to send data to virtual pin V0 on Blynk. More about |link_blynk_virtualWrite|.

   - Use ``Blynk.logEvent("event_code")`` to log event to Blynk. More about |link_blynk_logEvent|.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
       
      void sendData() {
        int data = digitalRead(sensorPin);
        Blynk.virtualWrite(V0, data);  // send data to virtual pin V0 on Blynk
        Serial.print("flame:");
        Serial.println(data);  // Print flame status on Serial Monitor
        if (data == 0) {
          Blynk.logEvent("flame_alert");  // log flame alert event if sensor detects flame
        }
      }

**Reference**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|