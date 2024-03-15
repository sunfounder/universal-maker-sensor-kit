.. _esp32_soap_dispenser:

Lesson 37: Automatic soap dispenser
=====================================

The Automatic Soap Dispenser project uses an Arduino Uno board along 
with an infrared obstacle avoidance sensor and a water pump. 
The sensor detects the presence of an object such as a hand, 
which activates the water pump to dispense soap.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Wiring
---------------------------

.. image:: img/Lesson_37_Automatic_soap_dispenser_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f1923f60-5b82-497b-915f-ecc7ad46fea4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Code Analysis
---------------------------

The main idea behind this project is to create a hands-free soap dispensing system. The infrared obstacle avoidance sensor detects when an object (like a hand) is close. Upon detecting an object, the sensor sends a signal to the Arduino, which in turn triggers the water pump to dispense soap. The pump stays active for a brief period, dispensing soap, then turns off.

#. **Defining the pins for the sensor and the pump**

    In this code snippet, we define the Arduino pins that connect to the sensor and pump. 
    We define pin 7 as the sensor pin and we will use the variable ``sensorValue`` to store the data read from this sensor. 
    For the water pump, we use two pins, 9 and 10.
    
    .. code-block:: arduino
   
        // Define the pin numbers for the Infrared obstacle avoidance sensor
        const int sensorPin = 35;
        int sensorValue;

        // Define pin numbers for the water pump
        const int pump1A = 19;
        const int pump1B = 21;

#. **Setting up the sensor and pump**

    In the ``setup()`` function, we define the modes for the pins we're using. 
    The sensor pin is set to ``INPUT`` as it will be used to receive data from the sensor. 
    The pump pins are set to ``OUTPUT`` as they will send commands to the pump. 
    We ensure that the pin ``pump1B`` starts in a ``LOW`` state (off), 
    and we start the serial communication with a baud rate of 9600.

    .. code-block:: arduino
    
        void setup() {
            // Set the sensor pin as input
            pinMode(sensorPin, INPUT);

            // Initialize the pump pins as output
            pinMode(pump1A, OUTPUT);    
            pinMode(pump1B, OUTPUT);    

            // Keep pump1B low
            digitalWrite(pump1A, LOW); 
            digitalWrite(pump1B, LOW);  

            Serial.begin(9600);
        }

#. **Continuously checking the sensor and controlling the pump**

   In the ``loop()`` function, the Arduino constantly reads the value from the sensor using ``digitalRead()`` and assigns it to ``sensorValue()``. It then prints this value to the serial monitor for debugging purposes. If the sensor detects an object, ``sensorValue()`` will be 0. When this happens, ``pump1A`` is set to ``HIGH``, activating the pump, and a delay of 700 milliseconds allows the pump to dispense soap. The pump is then deactivated by setting ``pump1A`` to ``LOW``, and a 1-second delay gives the user time to move their hand away before the cycle repeats.

   .. note:: 
   
      If the sensor is not working properly, adjust the IR transmitter and receiver to make them parallel. Additionally, you can adjust the detection range using the built-in potentiometer.

   .. code-block:: arduino
   
        void loop() {
            sensorValue = digitalRead(sensorPin);
            Serial.println(sensorValue);

            // If an object is detected, turn on the pump for a brief period, then turn it off
            if (sensorValue == 0) {  
                digitalWrite(pump1A, HIGH);
                delay(700);
                digitalWrite(pump1A, LOW);
                delay(1000);
            }
        }
