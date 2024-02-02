.. _esp32_lesson10_pcf8591:

Lesson 10: PCF8591 ADC DAC Converter Module
==============================================

In this lesson, you'll learn how to connect the ESP32 Development Board with a PCF8591 ADC DAC Converter Module. We'll cover reading analog values from input AIN0, sending these values to the DAC(AOUT), and displaying both the raw and voltage-converted readings on the serial monitor. The module's potentiometer is connected to AIN0 using jumper caps, and the D2 LED on the module is connected to AOUT, so you can see that the brightness of D2 LED changes as you rotate the potentiometer.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_pcf8591`
* :ref:`cpn_breadboard`

Wiring
---------------------------

.. image:: img/Lesson_10_PCF8591_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f184da9-9ea5-4c8a-877e-a7a41abf8c15/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. **Including the Library and Defining Constants**

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"Adafruit PCF8591"** and install it. 

   .. code-block:: arduino

      // Include Adafruit PCF8591 library
      #include <Adafruit_PCF8591.h>
      // Define the reference voltage for ADC conversion
      #define ADC_REFERENCE_VOLTAGE 3.3

   This section includes the Adafruit PCF8591 library, which provides functions for interacting with the PCF8591 module. The ADC reference voltage is set to 3.3 volts, which is the maximum voltage that the ADC can measure.

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