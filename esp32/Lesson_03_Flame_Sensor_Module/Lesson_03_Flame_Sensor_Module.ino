/*
  The code is designed for an ESP32 Development Board and interfaces 
  with a flame sensor module to constantly monitor its output. When 
  the sensor detects a flame (indicated by the LOW output), it sends 
  a fire alert message to the serial monitor; otherwise, it prints a 
  message indicating no fire is detected. The check happens every 100 
  milliseconds.

  Board: ESP32 Development Board
  Component: Flame sensor module
*/

// Define the pin used for the flame sensor
const int sensorPin = 25;

void setup() {
  pinMode(sensorPin, INPUT);  // Set the flame sensor pin as input
  Serial.begin(9600);         // Initialize the serial monitor at a baud rate of 9600
}

void loop() {
  // Check if the sensor is detecting a fire
  if (digitalRead(sensorPin) == 0) {
    Serial.println("** Fire detected!!! **");
  } else {
    Serial.println("No Fire detected");
  }
  delay(100);
}