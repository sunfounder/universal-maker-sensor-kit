/*
  This Arduino sketch reads the analog value from a water level sensor 
  connected to pin A0. It continuously reads the sensor value and sends 
  it to the serial monitor every 100 milliseconds.

  Board: Arduino Uno R3 (or R4)
  Component: Water Level Sensor Module
*/

// Define the pin numbers for the Water Level Sensor Module
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
  delay(100);                             // Wait for 100 milliseconds
}