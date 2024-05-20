.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _config_esp8266:

1.1 Configuring the ESP8266
===============================

The ESP8266 module that comes with the kit is already pre-burned with AT firmware, but you still need to modify its configuration by following the steps below.


1. Build the circuit.

   .. image:: img/wiring_r4_configure.png
       :width: 800

2. Open the ``00-Set_software_serial.ino`` file under the path of ``ultimate-sensor-kit\iot_project\wifi\00-Set_software_serial``. Or copy this code into Arduino IDE. And upload the code.

   The code establishes a software serial communication using Arduino's SoftwareSerial library, allowing the Arduino to communicate with the ESP8266 module through its digital pins 2 and 3 (as Rx and Tx). It checks for data transfer between them, forwarding received messages from one to the other at a baud rate of 115200. **With this code, you can use the Arduino's serial monitor to send AT firmware commands to the ESP8266 module and receive its responses.**

   .. code-block:: Arduino

       #include <SoftwareSerial.h>
       SoftwareSerial espSerial(2, 3); //Rx,Tx

       void setup() {
           // put your setup code here, to run once:
           Serial.begin(115200);
           espSerial.begin(115200);
       }

       void loop() {
           if (espSerial.available()) {
               Serial.write(espSerial.read());
           }
           if (Serial.available()) {
               espSerial.write(Serial.read());
           }
       }


3. Click the magnifying glass icon (Serial Monitor) in the upper right corner and set the baud rate to **115200**. (You may have some printed information like me, or you may not, it doesn’t matter, just go to the next step.)

   .. image:: img/esp01_configurie_1.png

   .. warning::
        
        * If ``ready`` doesn't appear, you can try to reset the ESP8266 module(connect RST to GND) and re-open the Serial Monitor.

        * In addition, if the result is ``OK``, you may need to re-burn the firmware, please refer to :ref:`burn_firmware` for details. If you still can't solve it, please take a screenshot of the serial monitor and send it to service@sunfounder.com, we will help you solve the problem as soon as possible.

4. Click on **NEWLINE DROPDOWN BOX**, select ``both NL & CR`` in the drop down option, enter ``AT``, if it returns OK, it means ESP8266 has successfully established connection with R4 board.

   .. image:: img/esp01_configurie_2.png

   .. image:: img/esp01_configurie_3.png

5. Enter ``AT+CWMODE=3`` and the managed mode will be changed to **Station and AP** coexistence.

   .. image:: img/esp01_configurie_4.png

.. 6. In order to use the software serial later, you must input ``AT+UART=9600,8,1,0,0`` to modify the ESP8266's baud rate to 9600.

..    .. image:: img/esp01_configurie_5.png


**Reference**

* |link_esp8266_at|