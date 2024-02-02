/*
  Uses the Adafruit_MPU6050 library to retrieve data from the MPU6050 sensor. 
  The process involves initializing serial communication, 
  verifying if the sensor is detected, configuring accelerometer and gyro ranges, 
  reading sensor data, and displaying acceleration, rotation, and temperature values 
  on the serial monitor.
  
  Board: Arduino Uno R3 (or R4)
  Component: Accelerometer & Gyroscope Sensor(MPU6050)
  Library: https://github.com/adafruit/Adafruit_MPU6050  (Adafruit MPU6050 by Adafruit)
*/

// Include the necessary libraries
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// Create an object for the MPU6050 sensor
Adafruit_MPU6050 mpu;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Check if the MPU6050 sensor is detected
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // Add a delay for stability
  delay(100);
}

void loop() {
  // Get new sensor events with the readings
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Print out the acceleration readings in m/s^2
  Serial.print("Acceleration:   X:");
  Serial.print(a.acceleration.x);
  Serial.print(", Y:");
  Serial.print(a.acceleration.y);
  Serial.print(", Z:");
  Serial.print(a.acceleration.z);
  Serial.println(" (m/s^2)");

  // Print out the rotation readings in rad/s
  Serial.print("Rotation:       X:");
  Serial.print(g.gyro.x);
  Serial.print(", Y:");
  Serial.print(g.gyro.y);
  Serial.print(", Z:");
  Serial.print(g.gyro.z);
  Serial.println(" (rad/s)");

  // Print out the temperature reading in degrees Celsius
  Serial.print("Temperature:    ");
  Serial.print(temp.temperature);
  Serial.println(" (degC)");

  // Add a blank line for readability
  Serial.println("");

  // Add a delay to avoid flooding the serial monitor
  delay(1000);
}
