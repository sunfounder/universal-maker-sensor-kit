.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson10_pcf8591:

Lesson 10: PCF8591 ADC DAC Converter Module
==============================================

.. note::
   The Raspberry Pi does not have analog input capabilities, so it needs a module like the :ref:`cpn_pcf8591` to read analog signals for processing.

In this lesson, you will learn how to use a Raspberry Pi to interact with the PCF8591 module for analog-to-digital and digital-to-analog conversion. We’ll cover reading analog values from input AIN0, sending these values to the DAC(AOUT). The module's potentiometer is connected to AIN0 using jumper caps, and the D2 LED on the module is connected to AOUT, so you can see that the brightness of D2 LED changes as you rotate the potentiometer.

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. note::
   In this project, we utilized the AIN0 pin of the PCF8591 module, which is linked to a potentiometer on the module through a jumper cap. **Please make sure that the jumper cap on the module is correctly placed.** For more details, please refer to the PCF8591 module :ref:`schematic <cpn_pcf8591_sch>`.

.. image:: img/Lesson_10_PCF8591_pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: Python

   import PCF8591 as ADC  # Import the library for the PCF8591 module
   import time  # Import the time library for adding delays
   
   # Initialize the PCF8591 module at I2C address 0x48.
   # This address is used for communication with the Raspberry Pi.
   ADC.setup(0x48)
   
   try:
       while True:  # Start an infinite loop to continuously monitor the sensor.
           # Read the analog value from the potentiometer connected to AIN0.
           # Channel range from 0 to 3 represents AIN0 to AIN3.
           # The potentiometer's rotation alters the voltage, which is read by the PCF8591.
           potentiometer_value = ADC.read(0)
           print(potentiometer_value)
   
           # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
           # LED won't light up below 80, so convert '0-255' to '80-255'
           # As the potentiometer is adjusted, the LED's brightness varies proportionally.
           tmp = potentiometer_value*(255-80)/255+80
           ADC.write(tmp)
   
           # Add a short delay of 0.2 seconds to make the loop more manageable.
           time.sleep(0.2)
   
   except KeyboardInterrupt:
       # If a KeyboardInterrupt (CTRL+C) is detected, exit the loop and end the program.
       print("Exit")



Code Analysis
---------------------------

1. **Importing Libraries**:

   The script starts by importing required libraries. The ``PCF8591`` library is used for interacting with the ADC/DAC module, and ``time`` is for creating delays.

   .. code-block:: python

      import PCF8591 as ADC  # Import the library for the PCF8591 module
      import time  # Import the time library for adding delays

2. **Initializing PCF8591 Module**:

   The PCF8591 module is initialized at the I²C address 0x48. This step is crucial for setting up communication between the Raspberry Pi and the module.

   .. code-block:: python

      ADC.setup(0x48)  # Initialize the PCF8591 module at I2C address 0x48

3. **Reading from Potentiometer and Writing to LED**:

   Within a ``try`` block, a continuous ``while True`` loop reads the value from the potentiometer connected to AIN0 and writes this value to the DAC connected to AOUT. Jumper caps link the module's potentiometer to AIN0, and the D2 LED is connected to AOUT; please refer to the PCF8591 module :ref:`schematic <cpn_pcf8591_sch>` for details. The brightness of the LED changes as the potentiometer is rotated.

   - Use ``ADC.read(channel)`` to read the analog input of the specific channel. The channel range from 0 to 3 represents AIN0 to AIN3.

   - Use ``ADC.write(Value)`` to set the analog output of the AOUT pin with a Value range from 0 to 255.

   .. raw:: html

      <br/>

   .. code-block:: python

      try:
          while True:  # Start an infinite loop to continuously monitor the sensor.
              potentiometer_value = ADC.read(0)
              print(potentiometer_value)
              tmp = potentiometer_value*(255-80)/255+80
              ADC.write(tmp)
              time.sleep(0.2)

4. **Handling Keyboard Interrupts**:

   A ``KeyboardInterrupt`` (such as pressing CTRL+C) allows for a graceful exit from the loop without generating errors.

   .. code-block:: python

      except KeyboardInterrupt:
          print("Exit")