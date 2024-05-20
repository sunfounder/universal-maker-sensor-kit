

.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _esp32_iot_intrusion_alert_system:

Lesson 49: Blynk-based Intrusion Notification System
=============================================================

This project demonstrate a simple home intrusion detection system using a PIR motion sensor (HC-SR501).
When the system is set to "Away" mode through the Blynk app, the PIR sensor monitors for motion.
Any detected movement triggers a notification on the Blynk app, alerting the user of potential intrusion.

**Required Components**

In this project, we need the following components. 


.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_pir_motion`
        - \-


1. Circuit Assembly
--------------------

.. image:: img/Lesson_12_PIR_Module_esp32_bb.png
    :width: 100%
    :align: center

2. Blynk Configuration
----------------------

**2.1 Initializing Blynk**

#. Navigate to the |link_blynk| and select **START FREE**. 

   .. image:: img/09_blynk_access.png
        :width: 90%

#. Enter your email to initiate the registration process.

   .. image:: img/09_blynk_sign_in.png
        :width: 70%
        :align: center

#. Confirm your registration through your email.

    .. image:: img/09_blynk_password.png
        :width: 90%

#. After confirmation, **Blynk Tour** will appear. It is recommended to select "Skip". If **Quick Start** also appears, consider skipping it as well.
   
    .. image:: img/09_blynk_tour.png
        :width: 90%

**2.2 Template Creation**

#. First, create a template in Blynk. Follow the subsequent instructions to create the **Intrusion Alert System** template.

    .. image:: img/09_create_template_1_shadow.png
        :width: 700
        :align: center

#. Assign a name to the template, select **ESP32** Hardware, and select **Connection Type** as **WiFi**, then select **Done**.

    .. image:: img/09_create_template_2_shadow.png
        :width: 700
        :align: center

**2.3 Datastream Generation**

Open the template you just set up, let's create two datastreams.

#. Click **New Datastream**.

    .. image:: img/09_blynk_new_datastream.png
        :width: 700
        :align: center

#. In the popup, choose **Virtual Pin**.

    .. image:: img/09_blynk_datastream_virtual.png
        :width: 700
        :align: center

#. Name the **Virtual Pin V0** as **AwayMode**. Set the **DATA TYPE** as **Integer** with **MIN** and **MAX** values as **0** and **1**.

    .. image:: img/09_create_template_shadow.png
        :width: 700
        :align: center

#. Similarly, create another **Virtual Pin** datastream. Name it **Current Status** and set the **DATA TYPE** to **String**.

    .. image:: img/09_datastream_1_shadow.png
        :width: 700
        :align: center

**2.4 Setting Up an Event**

Next, we'll set up an event that sends an email notification if an intrusion is detected.

#. Click **Add New Event**.

    .. image:: img/09_blynk_event_add.png

#. Define the event's name and its specific code. For **TYPE**, choose **Warning** and write a short description for the email to be sent when the event happens. You can also adjust how often you get notified.

    .. note::
        
        Make sure the **EVENT CODE** is set as ``intrusion_detected``. This is predefined in the code, so any changes would mean you need to adjust the code as well.

    .. image:: img/09_event_1_shadow.png
        :width: 700
        :align: center

#. Go to the **Notifications** section to turn on notifications and set up email details.

    .. image:: img/09_event_2_shadow.png
        :width: 80%
        :align: center

.. raw:: html
    
    <br/> 

**2.5  Fine-Tuning the Web Dashboard**

Making sure the **Web Dashboard** interacts perfectly with the Intrusion Alert System is vital.

#. Simply drag and place both the **Switch widget** and the **Label widget** onto the **Web Dashboard**.

    .. image:: img/09_web_dashboard_1_shadow.png
        :width: 100%
        :align: center

#. When you hover over a widget, three icons will appear. Use the settings icon to adjust the widget's properties.

    .. image:: img/09_blynk_dashboard_set.png
        :width: 100%
        :align: center

#. In the **Switch widget** settings, select **Datastream** as **AwayMode(V0)**. Set **ONLABEL** and **OFFLABEL** to display **"away"** and **"home"**, respectively.

    .. image:: img/09_web_dashboard_2_shadow.png
        :width: 100%
        :align: center

#. In the **Label widget** settings, select **Datastream** as **Current Status(V1)**.

    .. image:: img/09_web_dashboard_3_shadow.png
        :width: 100%
        :align: center

**2.6 Saving the Template**

Lastly, don't forget to save your template.

    .. image:: img/09_save_template_shadow.png
        :width: 100%
        :align: center

**2.7 Making a Device**

#. It's time to create a new device.

    .. image:: img/09_blynk_device_new.png
        :width: 700
        :align: center

#. Click on **From template** to start with a new setup.

    .. image:: img/09_blynk_device_template.png
        :width: 700
        :align: center

#. Then, pick the **Intrusion Alert System** template and click on **Create**.

    .. image:: img/09_blynk_device_template2.png
        :width: 700
        :align: center

#. Here, you'll see the ``Template ID``, ``Device Name``, and ``AuthToken``. You need to copy these into your code so the ESP32 can work with Blynk.

    .. image:: img/09_blynk_device_code.png
        :width: 700
        :align: center

3. Code Execution
-----------------------------
#. Before running the code, make sure to install the ``Blynk`` library from the **Library Manager** on the Arduino IDE.

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#. Open the ``Lesson_49_Blynk_based_intrusion_system.ino`` file, which is located in the ``universal-maker-sensor-kit\esp32\Lesson_49_Blynk_based_intrusion_system`` directory. You can also copy its content into the Arduino IDE.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/987fb2fd-47e9-4a73-9020-6b2111eadd9c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Replace the placeholders for ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME``, and ``BLYNK_AUTH_TOKEN`` with your own unique IDs.

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. You also need to enter your WiFi network's ``ssid`` and ``password``.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. Choose the correct board (**ESP32 Dev Module**) and port, then click the **Upload** button.

#. Open the Serial monitor (set baud rate to 115200) and wait for a successful connection message.

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. After a successful connection, activating the switch in Blynk will start the PIR module's surveillance. When motion is detected (state of 1), it will say, "Somebody here!" and send an alert to your email.

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. Code explanation
-----------------------------

#. **Configuration & Libraries**

   Here, you set up the Blynk constants and credentials. You also include the necessary libraries for the ESP32 and Blynk.

    .. code-block:: arduino

        /* Comment this out to disable prints and save space */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **WiFi Setup**

   Enter your WiFi credentials.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **PIR Sensor Configuration**

   Set the pin where the PIR sensor is connected and initialize the state variables.

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **setup() Function**

   This function initializes the PIR sensor as an input, sets up serial communication, connects to WiFi, and configures Blynk.

   - We use ``timer.setInterval(1000L, myTimerEvent)`` to set the timer interval in ``setup()``, here we set to execute the ``myTimerEvent()`` function every **1000ms**. You can modify the first parameter of ``timer.setInterval(1000L, myTimerEvent)`` to change the interval between ``myTimerEvent`` executions.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void setup() {

            pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input
            Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging
            
            // Configure Blynk and connect to WiFi
            Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
            
            timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
        }

#. **loop() Function**

   The loop function continuously runs Blynk and the Blynk timer functions.

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }

#. **Blynk App Interaction**

   These functions are called when the device connects to Blynk and when there's a change in the state of the virtual pin V0 on the Blynk app.

   - Every time the device connects to the Blynk server, or reconnects due to poor network conditions, the ``BLYNK_CONNECTED()`` function is called. The ``Blynk.syncVirtual()`` command request a single Virtual Pin value. The specified Virtual Pin will perform ``BLYNK_WRITE()`` call. 

   - Whenever the value of a virtual pin on the BLYNK server changes, it will trigger ``BLYNK_WRITE()``.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
      
        // This function is called every time the device is connected to the Blynk.Cloud
        BLYNK_CONNECTED() {
            Blynk.syncVirtual(V0);
        }
      
        // This function is called every time the Virtual Pin 0 state changes
        BLYNK_WRITE(V0) {
            awayHomeMode = param.asInt();
            // additional logic
        }

#. **Data Handling**

   Every second, the ``myTimerEvent()`` function calls ``sendData()``. If the away mode is enabled on Blynk, it checks the PIR sensor and sends a notification to Blynk if motion is detected.

   - We use ``Blynk.virtualWrite(V1, "Somebody in your house! Please check!");`` to change the text of a label.

   - Use ``Blynk.logEvent("intrusion_detected");`` to log event to Blynk.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void myTimerEvent() {
           sendData();
        }

        void sendData() {
           if (awayHomeMode == 1) {
              state = digitalRead(sensorPin);  // Read the state of the PIR sensor

              Serial.print("state:");
              Serial.println(state);

              // If the sensor detects movement, send an alert to the Blynk app
              if (state == HIGH) {
                Serial.println("Somebody here!");
                Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
                Blynk.logEvent("intrusion_detected");
              }
           }
        }

**Reference**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|