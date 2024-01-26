/*
  This Arduino sketch is for an Arduino Uno R4 (or R3) board connected to a 
  PCF8591 ADC DAC Converter Module. It sets up the PCF8591 module, reads an 
  analog value from input AIN0, writes this value to the DAC(AOUT), and displays 
  the raw and voltage-converted value of AIN0 on the serial monitor. The code 
  also contains a function to convert a digital value to its corresponding voltage.

  Board: Arduino Uno R3 (or R4)
  Component: PCF8591 ADC DAC Converter Module
  Library: https://github.com/adafruit/Adafruit_PCF8591 (Adafruit PCF8591 by Adafruit)
*/

// Include Adafruit PCF8591 library
#include <Adafruit_PCF8591.h>

// Define the reference voltage for ADC conversion
#define ADC_REFERENCE_VOLTAGE 5.0

// Create an instance of the PCF8591 module
Adafruit_PCF8591 pcf = Adafruit_PCF8591();

// Variable to store analog input value from AIN0
uint8_t AIN0;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Print initialization message
  Serial.println("# Adafruit PCF8591 demo");

  // Check if PCF8591 module is connected
  if (!pcf.begin()) {
    // Print error message if not found and halt
    Serial.println("# PCF8591 not found!");
    while (1)
      delay(10);
  }
  // Print success message if found
  Serial.println("# PCF8591 found");

  // Enable the DAC on the PCF8591 module
  pcf.enableDAC(true);
}

void loop() {
  // Read analog value from AIN0
  AIN0 = pcf.analogRead(0);

  // Write the read value back to the DAC
  pcf.analogWrite(AIN0);

  // Print the raw and voltage-converted value of AIN0
  Serial.print("AIN0: ");
  Serial.print(AIN0);
  Serial.print(", ");
  Serial.print(int_to_volts(AIN0, 8, ADC_REFERENCE_VOLTAGE));
  Serial.println("V");

  // Serial.print("AIN1: ");
  // Serial.print(int_to_volts(pcf.analogRead(1), 8, ADC_REFERENCE_VOLTAGE));
  // Serial.println("V");

  // Serial.print("AIN2: ");
  // Serial.print(int_to_volts(pcf.analogRead(2), 8, ADC_REFERENCE_VOLTAGE));
  // Serial.println("V");

  // Serial.print("AIN3: ");
  // Serial.print(int_to_volts(pcf.analogRead(3), 8, ADC_REFERENCE_VOLTAGE));
  // Serial.println("V");

  // Delay for half a second before next read
  delay(500);
}

// Function to convert digital value to voltage
float int_to_volts(uint16_t dac_value, uint8_t bits, float logic_level) {
  return (((float)dac_value / ((1 << bits) - 1)) * logic_level);
}
