/*
  This program reads the analog input from a capacitive soil moisture sensor 
  connected to pin 25 and prints the value to the serial monitor. 
  The smaller the value, the higher the soil moisture level. 

  Board: ESP32 Development Board
  Component: Capacitive soil moisture sensor module
*/

// Define the sensor pin
const int sensorPin = 25;

void setup() {
  Serial.begin(9600);// Initialize serial communication at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin)); // The smaller the value, the higher the soil moisture level
  delay(500);// Wait for 500 milliseconds before taking the next reading
}
