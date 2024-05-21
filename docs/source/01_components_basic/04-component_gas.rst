.. _cpn_gas:

Gas/Smoke Sensor Module (MQ2) 
=====================================

.. image:: img/04_mq2_gas_module.png
    :width: 350
    :align: center

.. tip::
   MQ2 is a heating-driven sensor that usually requires preheating before use. During the preheating period, the sensor typically reads high and gradually decreases until it stabilizes.

The MQ-2 sensor is a versatile gas sensor capable of detecting a wide range of gases including alcohol, carbon monoxide, hydrogen, isobutene, liquefied petroleum gas, methane, propane, and smoke. It is popular among beginners due to its low cost and easy-to-use features.

Principle
---------------------------
The MQ-2 sensor works on the principle of resistance changes in the presence of different gases. When the target gas comes in contact with the heated MOS(Metal Oxide Semiconductor) material, it undergoes oxidation or reduction reactions that change the resistance of the MOS material. **It is noteworthy that the MQ2 gas sensor is capable of detecting multiple gases, but lacks the ability to differentiate between them.** This is a common characteristic of most gas sensors. 

The sensor has a built-in potentiometer that allows you to adjust the sensor digital output (D0) threshold. When the concentration of gas in the air exceeds a certain threshold value, the resistance of the sensor changes. This change in resistance is then converted into an electrical signal that can be read by an Arduino board.

Calibrating the MQ2 Gas Sensor
----------------------------------
Because the MQ2 is a heater-driven sensor, the calibration of the sensor may drift if it is left in storage for an extended period of time.
When first used after a long period of storage (a month or more), the sensor must be fully warmed up for 24-48 hours to ensure maximum accuracy.
If the sensor has recently been used, it will only take 5-10 minutes to fully warm up. During the warm-up period, the sensor typically reads high and gradually decreases until it stabilizes.

Specification
---------------------------
* Model: MQ2
* Supply Voltage: 5V
* PCB Size: 32 x 20mm
* Output Signal Type: DO and AO
* Detection Concentration: 300 to 10000ppm
* Preheat Duration: Over 24 hours (first time)
* Detect Gas: LPG, Alcohol, Propane, Hydrogen, CO and even methane

Pinout
---------------------------
* **VCC**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **DO**: Digital output. It indicates the presence of combustible gases. When the gas concentration exceeds the threshold value (as set by the potentiometer), D0 becomes LOW; otherwise, it is HIGH.
* **AO**: Analog output. It produces an analog output voltage proportional to gas concentration, so a higher concentration results in a higher voltage and a lower concentration results in a lower voltage.


Example
---------------------------
* :ref:`uno_lesson04_mq2` (Arduino UNO)
* :ref:`esp32_lesson04_mq2` (ESP32)
* :ref:`pico_lesson04_mq2` (Raspberry Pi Pico)
* :ref:`pi_lesson04_mq2` (Raspberry Pi)

* :ref:`uno_lesson38_gas_leak_alarm` (Arduino UNO)
* :ref:`esp32_gas_leak_alarm` (ESP32)