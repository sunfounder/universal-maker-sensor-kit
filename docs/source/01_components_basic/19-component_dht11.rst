.. _cpn_dht11:

Temperature and Humidity Sensor Module (DHT11)
================================================

.. image:: img/19_dht11_module.png
    :width: 360
    :align: center

.. raw:: html

   <br/>

The digital temperature and humidity sensor DHT11 is a composite sensor that contains a calibrated digital signal output of temperature and humidity. The technology of a dedicated digital modules collection and the temperature and humidity sensing technology are applied to ensure that the product has high reliability and excellent long-term stability.

Specification
---------------------------
* Supply Voltage: 3.3V - 5V
* Output Signal Type: Digital output
* Temperature Measurement Range: 0-50℃ ± 2℃
* Humidity Measurement Range: 20-90%RH ± 5%RH
* Temperature Accuracy: ±2°C
* Humidity Accuracy: ±5% RH

Pinout
---------------------------
* **VCC**: This is the positive power supply input from the main control. 
* **GND**: Ground connection.
* **DO**: Digital output. 

Principle
---------------------------
Only three pins are available for use: VCC, GND, and DATA. The communication process begins with the DATA line sending start signals to DHT11, and DHT11 receives the signals and returns an answer signal. Then the host receives the answer signal and begins to receive 40-bit humidity and temperature data (8-bit humidity integer + 8-bit humidity decimal + 8-bit temperature integer + 8-bit temperature decimal + 8-bit checksum).

.. image:: img/19_dht11_module_2.png
    :width: 300
    :align: center

.. raw:: html
    
    <br/>

Schematic diagram
---------------------------

.. image:: img/19_dht11_module_schematic.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>


Example
---------------------------
* :ref:`uno_lesson19_dht11` (Arduino UNO)
* :ref:`esp32_lesson19_dht11` (ESP32)
* :ref:`pico_lesson19_dht11` (Raspberry Pi Pico)
* :ref:`pi_lesson19_dht11` (Raspberry Pi)

