/*
  The code is designed for an Arduino Uno R4 (or R3) to interface with a JDY-31 Bluetooth 
  module and an LCD module. The Arduino listens for incoming data from the Bluetooth module, 
  and upon receiving, displays the data on both the LCD and the serial monitor. It also 
  forwards any data received from the serial monitor to the Bluetooth module.

  Board: Arduino Uno R4 (or R3)
  Component: JDY-31 bluetooth module and LCD Module
  Library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (LiquidCrystal I2C by Frank de Brabander)  
*/

// Set up LCD Module
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // initialize the Liquid Crystal Display object with the I2C address 0x27, 16 columns and 2 rows

// Set up Bluetooth module communication
#include <SoftwareSerial.h>
const int bluetoothTx = 3;                           // bluetooth tx to 3 pin
const int bluetoothRx = 4;                           // bluetooth rx to 4 pin
SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);  // Declare SoftwareSerial object for Bluetooth communication

void setup() {
  lcd.init();       // initialize the LCD
  lcd.clear();      // clear the LCD display
  lcd.backlight();  // Make sure backlight is on

  Serial.begin(9600);
  bleSerial.begin(9600);
}

void loop() {
  String data;

  // Check if there's any data from the Bluetooth module
  if (bleSerial.available()) {

    data += bleSerial.readString();               // Read incoming string from Bluetooth
    data = data.substring(0, data.length() - 2);  // Remove last two characters from the data
    Serial.print(data);                           // Display data on serial monitor

    lcd.clear();          // Clear previous message on LCD
    lcd.setCursor(0, 0);  // Set cursor to beginning of LCD
    lcd.print(data);      // Display the received data on LCD
  }

  // Check if there's any data from the Serial monitor (PC)
  if (Serial.available()) {
    bleSerial.write(Serial.read());  // Forward the received byte to Bluetooth module
  }
}
