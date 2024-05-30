/*
  This code initializes an OLED display and reads input from a joystick 
  connected to analog pins A0 and A1. It continuously monitors the joystick's 
  position to determine its tilt direction. Depending on the tilt direction, 
  it displays an appropriate arrow (up, down, left, or right) or a circle 
  (if the joystick is centered) on the OLED display.

  Board: Arduino Uno R3 (or R4)
  Component: Joystick Module and OLED Module
  Library: https://github.com/adafruit/Adafruit_SSD1306 (Adafruit SSD1306 by Adafruit)  
           https://github.com/adafruit/Adafruit-GFX-Library (Adafruit GFX Library by Adafruit) 
*/


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Joystick pins
const int xPin = A0;  // VRX pin
const int yPin = A1;  // VRY pin

// Threshold for determining joystick center position
const int threshold = 50;

void setup() {
  Serial.begin(9600);

  // initialize the OLED object
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  // Clear the buffer.
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();  // Clear the display for the next frame

  int xValue = analogRead(xPin);       // Read the x-axis value
  int yValue = analogRead(yPin) * -1;  // Read the y-axis value (inverted)

  // Print the joystick values to the Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print("|Y: ");
  Serial.println(-yValue);

  float yLine1 = line1(xValue);  // Calculate line 1 boundary
  float yLine2 = line2(xValue);  // Calculate line 2 boundary

  // Calculate relative joystick position
  int relX = xValue - 512;
  int relY = -yValue - 512;

  // Determine the direction based on the joystick position
  if (abs(relX) < threshold && abs(relY) < threshold) {
    // Center position
    drawCircle();
  } else if (yValue > yLine1 && yValue > yLine2) {
    drawUpArrow();
  } else if (yValue < yLine1 && yValue < yLine2) {
    drawDownArrow();
  } else if (yValue < yLine1 && yValue > yLine2) {
    drawRightArrow();
  } else if (yValue > yLine1 && yValue < yLine2) {
    drawLeftArrow();
  }

  // Update the display
  display.display();

  delay(80);
}

float line1(float x) {
  return x - 1023;
}

float line2(float x) {
  return -x;
}

void drawUpArrow() {
  display.fillTriangle(49, 30, 64, 15, 79, 30, WHITE);  // Draw the arrowhead
  display.fillRect(59, 30, 10, 20, WHITE);              // Draw the arrow shaft
}

void drawDownArrow() {
  display.fillTriangle(49, 36, 64, 51, 79, 36, WHITE);  // Draw the arrowhead
  display.fillRect(59, 16, 10, 20, WHITE);              // Draw the arrow shaft
}

void drawRightArrow() {
  display.fillTriangle(70, 15, 85, 30, 70, 45, WHITE);  // Draw the arrowhead
  display.fillRect(50, 25, 20, 10, WHITE);              // Draw the arrow shaft
}

void drawLeftArrow() {
  display.fillTriangle(60, 15, 45, 30, 60, 45, WHITE);  // Draw the arrowhead
  display.fillRect(60, 25, 20, 10, WHITE);              // Draw the arrow shaft
}

void drawCircle() {
  display.fillCircle(64, 32, 10, WHITE);  // Draw the outer circle
  display.fillCircle(64, 32, 8, BLACK);   // Draw the inner circle to create a ring
}
