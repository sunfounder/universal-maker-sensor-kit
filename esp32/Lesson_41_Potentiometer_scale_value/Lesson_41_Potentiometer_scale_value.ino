/*
  This Arduino code reads the value from a potentiometer connected to analog pin A0. 
  The read value is then displayed on an LCD 1620 with an I2C interface. 
  Additionally, the value is sent to the serial monitor. The LCD also displays a bar 
  corresponding to the potentiometer's value.

  Board: ESP32
  Component:  Liquid Crystal Display 1620 with I2C Interface and Potentiometer module
  Library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (LiquidCrystal I2C by Frank de Brabander)  
*/

// Required libraries for I2C and LCD operations
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD at I2C address 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables to hold the potentiometer readings
int lastRead = 0;     // Previous potentiometer value
int currentRead = 0;  // Current potentiometer value

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the LCD backlight
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  // Read the current potentiometer value
  int currentRead = analogRead(35);

  // Map the read value from 0-4096 to 0-16
  int barLength = map(currentRead, 0, 4096, 0, 16);

  // Update LCD only if the difference between current and last reading is greater than 2 to avoid jitter
  if (abs(lastRead - currentRead) > 2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Value:");
    lcd.setCursor(7, 0);
    lcd.print(currentRead);
    Serial.println(currentRead);

    // Display a bar on the second row of LCD proportional to the potentiometer value
    for (int i = 0; i < barLength; i++) {
      lcd.setCursor(i, 1);
      lcd.print(char(255));
    }
  }

  // Update the last read value for the next iteration
  lastRead = currentRead;

  // Introduce a delay for a stable reading
  delay(200);
}