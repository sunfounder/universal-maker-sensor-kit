/*
  This code snippet is used to control a servo motor to scan from 0 to 180 degrees 
  and then back from 180 to 0 degrees repeatedly.
  
  Board: ESP32 Development Board
  Component: Servo motor(SG90)
*/

#include <ESP32Servo.h>

// Define the servo and the pin it is connected to
Servo myServo;
const int servoPin = 25;

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

void setup() {
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); // Standard 50Hz servo
}

void loop() {
  // Rotate the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(15);
  }

  // Rotate the servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(15);
  }
}
