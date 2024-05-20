.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pi_lesson02_soil_moisture:

Lesson 02: Capacitive Soil Moisture Module
============================================

.. note::
   The Raspberry Pi does not have analog input capabilities, so it needs a module like the :ref:`cpn_pcf8591` to read analog signals for processing.

In this tutorial, we'll explore how to monitor soil moisture levels using a Raspberry Pi. You'll learn to set up a Capacitive Soil Moisture Sensor with the PCF8591 module for analog-to-digital conversion and use Python to continuously track the soil's moisture content. This project is a hands-on introduction to sensors, ADCs (analog-to-digital converters), and real-time data monitoring on the Raspberry Pi.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|


Wiring
---------------------------

.. image:: img/Lesson_02_Soil_Moisture_Module_pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: Python

   import PCF8591 as ADC  # Import PCF8591 module
   import time  # Import time for delay
   
   ADC.setup(0x48)  # Initialize PCF8591 at address 0x48
   
   try:
       while True:  # Continuously read and print moisture level
           print(ADC.read(1))  # Read from Soil Moisture Sensor at AIN1
           time.sleep(0.2)  # Delay of 0.2 seconds
   except KeyboardInterrupt:
       print("Exit")  # Exit on CTRL+C


Code Analysis
---------------------------

1. **Import Libraries**:

   This section imports necessary Python libraries. The ``PCF8591`` library is used for interacting with the PCF8591 module, and ``time`` is for implementing delays in the code.

   .. code-block:: python

      import PCF8591 as ADC  # Import PCF8591 module
      import time  # Import time for delay

2. **Initialize PCF8591 Module**:

   Here, the PCF8591 module is initialized. The address ``0x48`` is the I²C address of the PCF8591 module. This is necessary for the Raspberry Pi to communicate with the module.

   .. code-block:: python

      ADC.setup(0x48)  # Initialize PCF8591 at address 0x48

3. **Main Loop and Reading Data**:

   The ``try`` block includes a continuous loop that consistently reads data from the capacitive soil moisture module. The ``ADC.read(1)`` function captures the analog input from the sensor connected to channel 1 (AIN1) of the PCF8591 module. Incorporating a ``time.sleep(0.2)`` creates a 0.2-second pause between each reading. This not only helps in reducing CPU usage on the Raspberry Pi by avoiding excessive data processing demands, but also prevents the terminal from being overrun with rapidly scrolling information, making it easier to monitor and analyze the output.

   .. code-block:: python

      try:
          while True:  # Continuously read and print moisture level
              print(ADC.read(1))  # Read from Soil Moisture Sensor at AIN1
              time.sleep(0.2)  # Delay of 0.2 seconds

4. **Handling Keyboard Interrupt**:

   The ``except`` block is designed to catch a KeyboardInterrupt (like pressing CTRL+C). When this interrupt occurs, the script prints "exit" and stops running. This is a common way to gracefully exit a continuously running script in Python.

   .. code-block:: python

      except KeyboardInterrupt:
          print("exit")  # Exit on CTRL+C