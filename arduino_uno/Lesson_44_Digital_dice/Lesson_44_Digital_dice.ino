/*
  This code simulates a dice roll on a OLED display. Shaking the device 
  (vib switch activation) starts the roll, displaying random numbers rapidly 
  and stopping after a short duration.

  Board: Arduino Uno R4 / R3 
  Component: OLED Display with 74HC595 and vib Switch
*/


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);




const int vibPin = 2;    // The pin where the vib switch is connected

// State and timing variables
volatile bool rolling = false;
unsigned long lastShakeTime = 0;

void setup() {
  // Initialize pins
  pinMode(vibPin, INPUT);  

  // initialize the OLED object
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  // Attach an interrupt to the vibPin. When the vib switch is activated, the shakeDetected function will be called
  attachInterrupt(digitalPinToInterrupt(vibPin), rollDice, CHANGE);
}


void loop() {
  // Check if it's rolling
  if (rolling) {
    byte number = random(1, 7);  // Generate a random number between 1 and 6
    displayNumber(number);
    delay(80);  // Delay to make the rolling effect visible

    // Stop rolling after 1 second
    if ((millis() - lastShakeTime) > 1000) {
      rolling = false;
    }
  }
}

// Interrupt handler for shake detection
void rollDice() {
  if (digitalRead(vibPin) == LOW) {
    lastShakeTime = millis();  // Record the time of shake
    rolling = true;            // Start rolling
  }
}

// Function to display a number on the 7-segment display
void displayNumber(byte number) {
  display.clearDisplay();  // Clear the screen


  // Display Text
  display.setTextSize(4);       // Set text size
  display.setTextColor(WHITE);  // Set text color
  display.setCursor(54, 20);     // Set cursor position
  display.println(number);
  display.display();  // Display the content on the screen

}
