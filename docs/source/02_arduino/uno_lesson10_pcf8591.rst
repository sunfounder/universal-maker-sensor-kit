.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson10_pcf8591:

Lesson 10: PCF8591 ADC DAC Converter Module
==============================================

In this lesson, you'll learn how to connect the Arduino Uno R4 (or R3) with a PCF8591 ADC DAC Converter Module. We'll cover reading analog values from input AIN0, sending these values to the DAC(AOUT), and displaying both the raw and voltage-converted readings on the serial monitor. The module’s potentiometer is connected to AIN0 using jumper caps, and the D2 LED on the module is connected to AOUT, so you can see that the brightness of D2 LED changes as you rotate the potentiometer.

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
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|


Wiring
---------------------------

.. image:: img/Lesson_10_PCF8591_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/217d04d3-2c19-44df-b66b-5c1582955260/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. **Including the Library and Defining Constants**

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"Adafruit PCF8591"** and install it. 

   .. code-block:: arduino

      // Include Adafruit PCF8591 library
      #include <Adafruit_PCF8591.h>
      // Define the reference voltage for ADC conversion
      #define ADC_REFERENCE_VOLTAGE 5.0

   This section includes the Adafruit PCF8591 library, which provides functions for interacting with the PCF8591 module. The ADC reference voltage is set to 5.0 volts, which is the maximum voltage that the ADC can measure.

#. **Setting Up the PCF8591 Module**

   .. code-block:: arduino

      // Create an instance of the PCF8591 module
      Adafruit_PCF8591 pcf = Adafruit_PCF8591();
      void setup() {
        Serial.begin(9600);
        Serial.println("# Adafruit PCF8591 demo");
        if (!pcf.begin()) {
          Serial.println("# PCF8591 not found!");
          while (1) delay(10);
        }
        Serial.println("# PCF8591 found");
        pcf.enableDAC(true);
      }

   In the setup function, serial communication is started, and an instance of the PCF8591 module is created. The ``pcf.begin()`` function checks if the module is connected properly. If not, it prints an error message and halts the program. If the module is found, it enables the DAC.

#. **Reading from ADC and Writing to DAC**

   .. code-block:: arduino

      void loop() {
        AIN0 = pcf.analogRead(0);
        pcf.analogWrite(AIN0);
        Serial.print("AIN0: ");
        Serial.print(AIN0);
        Serial.print(", ");
        Serial.print(int_to_volts(AIN0, 8, ADC_REFERENCE_VOLTAGE));
        Serial.println("V");
        delay(500);
      }

   The loop function continuously reads the analog value from AIN0 (analog input 0) of the PCF8591 module, then writes this value back to the DAC. It also prints the raw value and the voltage-converted value of AIN0 to the Serial Monitor.

   Jumper caps link the module's potentiometer to AIN0, and the D2 LED is connected to AOUT; please refer to the PCF8591 module :ref:`schematic <cpn_pcf8591_sch>` for details. The brightness of the LED changes as the potentiometer is rotated.

#. **Digital to Voltage Conversion Function**

   .. code-block:: arduino

      float int_to_volts(uint16_t dac_value, uint8_t bits, float logic_level) {
        return (((float)dac_value / ((1 << bits) - 1)) * logic_level);
      }

   This function converts the digital value back to its corresponding voltage. It takes the digital value (``dac_value``), the number of bits of resolution (``bits``), and the logic level voltage (``logic_level``) as arguments. The formula used is a standard approach to convert a digital value to its equivalent voltage.