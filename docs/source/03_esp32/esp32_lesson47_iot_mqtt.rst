.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_iot_mqtt:

Lesson 47: IoT Communication with MQTT
=======================================

This project focuses on utilizing MQTT, a popular communication protocol in the Internet of Things (IoT) domain. MQTT enables IoT devices to exchange data using a publish/subscribe model, where devices communicate through topics.

In this project, we explore the implementation of MQTT by building a circuit that includes an LED, a button, and a thermistor. The ESP32-WROOM-32E microcontroller is used to establish a connection to WiFi and communicate with an MQTT broker. The code allows the microcontroller to subscribe to specific topics, receive messages, and control the LED based on the received information. Additionally, the project demonstrates publishing temperature data from the thermistor to a designated topic when the button is pressed.

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

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_button`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**Code Upload**

#. Build the circuit.

    .. note:: 
        When establishing a connection to WiFi, only the 36, 39, 34, 35, 32, 33 pins can be employed for analog reading. Please ensure the thermistor is connected to these designated pins.

    .. image:: img/Lesson_01_Button_Module_esp32_bb.png

#. Then, connect ESP32-WROOM-32E to the computer using the USB cable.


#. Open the code.

    * Open the ``Lesson_47_MQTT.ino`` file located in the ``universal-maker-sensor-kit\esp32\Lesson_47_MQTT`` directory, or copy the code into the Arduino IDE.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``PubSubClient`` library is used here, you can install it from the **Library Manager**.

        .. image:: img/mqtt_lib.png
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3f33a562-ebaa-48ed-a3ba-ae11e0b9706f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Locate the following lines and modify them with your ``<SSID>`` and ``<PASSWORD>``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Find the next line and modify your ``unique_identifier``. Guarantee that your ``unique_identifier`` is truly unique as any IDs that are identical trying to log in to the same MQTT Broker may result in a login failure.

    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";  

**Topic Subscription**

#. To avoid interference from messages sent by other participants, you can set it as an obscure or uncommon string. Simply replace the current topic ``SF/LED`` with your desired topic name.

    .. note:: 
        You have the freedom to set the Topic as any character you desire. Any MQTT device that has subscribed to the identical Topic will be able to receive the same message. You can also simultaneously subscribe to multiple Topics.

    .. code-block::  Arduino
        :emphasize-lines: 9

        void reconnect() {
            // Loop until we're reconnected
            while (!client.connected()) {
                Serial.print("Attempting MQTT connection...");
                // Attempt to connect
                if (client.connect(unique_identifier)) {
                    Serial.println("connected");
                    // Subscribe
                    client.subscribe("SF/LED");
                } else {
                    Serial.print("failed, rc=");
                    Serial.print(client.state());
                    Serial.println(" try again in 5 seconds");
                    // Wait 5 seconds before retrying
                    delay(5000);
                }
            }
        }

#. Modify the functionality to respond to the subscribed topic. In the provided code, if a message is received on the topic ``SF/LED``, it checks whether the message is ``on`` or ``off``. Depending on the received message, it changes the output state to control the LED's on or off status.

    .. note::
       You can modify it for any topic you are subscribed to, and you can write multiple if statements to respond to multiple topics.

    .. code-block::  arduino
        :emphasize-lines: 15

        void callback(char* topic, byte* message, unsigned int length) {
            Serial.print("Message arrived on topic: ");
            Serial.print(topic);
            Serial.print(". Message: ");
            String messageTemp;

            for (int i = 0; i < length; i++) {
                Serial.print((char)message[i]);
                messageTemp += (char)message[i];
            }
            Serial.println();

            // If a message is received on the topic "SF/LED", you check if the message is either "on" or "off".
            // Changes the output state according to the message
            if (String(topic) == "SF/LED") {
                Serial.print("Changing state to ");
                if (messageTemp == "on") {
                    Serial.println("on");
                    digitalWrite(ledPin, HIGH);
                } else if (messageTemp == "off") {
                    Serial.println("off");
                    digitalWrite(ledPin, LOW);
                }
            }
        }

#. After selecting the correct board (ESP32 Dev Module) and port, click the **Upload** button.

#. Open the serial monitor and if the following information is printed, it indicates a successful connection to the MQTT server.

    .. code-block:: 

        WiFi connected
        IP address: 
        192.168.18.77
        Attempting MQTT connection...connected

**Message Publication via HiveMQ**

HiveMQ is a messaging platform that functions as an MQTT broker, facilitating fast, efficient, and reliable data transfer to IoT devices.

Our code specifically utilizes the MQTT broker provided by HiveMQ. We have included the address of the HiveMQ MQTT broker in the code as follows:


    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";

#. At present, open the |link_hivemq| in your web browser.

#. Connect the client to the default public proxy.

    .. image:: img/sp230512_092258.png

#. Publish a message in the Topic you have subscribed to. In this project, you can publish ``on`` or ``off`` to control your LED.

    .. image:: img/sp230512_140234.png

**Message Publication to MQTT**

We can also utilize the code to publish information to the Topic. 
In this demonstration, we have coded a feature that sends the simple message to the Topic when you press the button.

#. Click on **Add New Topic Subscription**.

    .. image:: img/sp230512_092341.png

#. Fill in the topics you desire to follow and click **Subscribe**. In the code, we send message to the topic ``SF/TEMP``.

    .. code-block::  Arduino
        :emphasize-lines: 14

        void loop() {
            if (!client.connected()) {
                reconnect();
            }
            client.loop();

            // if the button pressed, publish the temperature to topic "SF/TEMP"
            if (digitalRead(buttonPin)) {
                    long now = millis();
                    if (now - lastMsg > 5000) {
                    lastMsg = now;
                    char tempString[8];
                    strcpy(tempString,"hello");
                    client.publish("SF/TEMP", tempString);
                }
            }
        }

#. Hence, we can monitor this Topic on HiveMQ, allowing us to view the information you have published.

    .. image:: img/sp230512_154342.png
