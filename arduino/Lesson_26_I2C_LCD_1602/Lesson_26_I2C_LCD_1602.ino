/*
  This code initializes and sets up a Liquid Crystal Display 16x2 with an I2C interface 
  using the LiquidCrystal I2C library. And prints "Hello world!" and "LCD Tutorial" on the 
  first and second lines of the display.

  Board: Arduino Uno R3 (or R4)
  Component: Liquid Crystal Display 1620 with I2C Interface
  Library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (LiquidCrystal I2C by Frank de Brabander)  
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // initialize the Liquid Crystal Display object with the I2C address 0x27, 16 columns and 2 rows

void setup() {
  lcd.init();       // initialize the LCD
  lcd.clear();      // clear the LCD display
  lcd.backlight();  // Make sure backlight is on

  // Print a message on both lines of the LCD.
  lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
  lcd.print("Hello world!");

  lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
  lcd.print("LCD Tutorial");
}

void loop() {
}