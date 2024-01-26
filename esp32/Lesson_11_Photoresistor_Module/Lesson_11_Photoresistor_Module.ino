/*
  This Arduino code reads and displays the analog value from
  a photoresistance sensor connected to an ESP32 Development 
  Board. It continuously measures the light intensity detected 
  by the sensor and outputs the readings to the serial monitor.

  Board: ESP32 Development Board
  Component: Photoresistance Sensor Module
*/

// Define the pin numbers for the photoresistance sensor module
const int sensorPin = 25;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
  delay(50);                              // Wait for 50 milliseconds
}