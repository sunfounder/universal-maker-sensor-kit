/*
  This code reads the digital value from a raindrops detection sensor module connected to 
  pin 7 and prints it to the serial monitor every 50 milliseconds.
  When the rainwater on the sensor reaches the threshold, 
  the DO output is low and the indicator light is on.

  Board: Arduino Uno R3 (or R4)
  Component: Raindrops Detection Sensor Module
*/

// Define the pin numbers for the raindrops detection sensor module
const int sensorPin = 7;

void setup() {
  pinMode(sensorPin, INPUT);  // Set sensorPin as input
  Serial.begin(9600);         // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(digitalRead(sensorPin));  // Read the digital value from the sensor and print it to the serial monitor
  delay(50);
}