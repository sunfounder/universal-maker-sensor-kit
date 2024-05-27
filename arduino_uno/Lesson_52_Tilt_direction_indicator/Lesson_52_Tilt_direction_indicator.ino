/*
  This code initializes an MPU6050 accelerometer and gyroscope sensor 
  along with an OLED display. It continuously reads the sensor data 
  to determine the tilt direction of the MPU6050. Based on the tilt 
  direction, it displays an appropriate arrow (up, down, left, or right) 
  or a circle (if there is no significant tilt) on the OLED display.

  Board: Arduino Uno R3 (or R4)
  Component: MPU6050 Module and OLED Module
*/

// Import the necessary libraries for MPU6050 Module and OLED Module
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // initialize the OLED object
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();

  delay(100);
}

void loop() {

  display.clearDisplay();

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("acceleration:");
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.println(a.acceleration.z);

  // Check the tilt direction based on acceleration values and draw corresponding arrows or circle
  if (a.acceleration.x >= 2) {
    // Draw an upward arrow if tilted upwards
    drawUpArrow();
  } else if (a.acceleration.x <= -2) {
    // Draw a downward arrow if tilted downwards
    drawDownArrow();
  } else if (a.acceleration.y >= 2) {
    // Draw a leftward arrow if tilted to the left
    drawLeftArrow();
  } else if (a.acceleration.y <= -2) {
    // Draw a rightward arrow if tilted to the right
    drawRightArrow();
  } else {
    // Draw a circle if there is no significant tilt
    drawCircle();
  }
  display.display();

  delay(200);
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