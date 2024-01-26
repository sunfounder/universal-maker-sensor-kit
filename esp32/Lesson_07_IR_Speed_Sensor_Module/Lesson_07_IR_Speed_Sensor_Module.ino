/*
  This code is intended for an ESP32 Development Board connected to a 
  Speed Sensor Module. It is designed to monitor the sensor and detect 
  obstructions. A high (1) reading on the sensor pin indicates an 
  obstruction, while a low (0) reading means there is no obstruction. 
  This status is communicated through the Serial Monitor.

  Board: ESP32 Development Board
  Component: Speed Sensor Module
*/

// Define the sensor pin connected to the ESP32
const int sensorPin = 25;

void setup() {
  Serial.begin(9600);         // Initialize Serial communication at 9600 baud rate
  pinMode(sensorPin, INPUT);  // Set sensorPin as an input to read from the speed sensor
}

void loop() {
  // Read the sensor value
  if (digitalRead(sensorPin) == HIGH) {  // If sensor pin is high (1), obstruction is detected
    Serial.println("Obstruction detected");
  } else {                               // If sensor pin is low (0), no obstruction
    Serial.println("Unobstructed");
  }
}