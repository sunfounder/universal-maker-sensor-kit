/*
  A simple code to read input from a touch sensor
  connected to pin 25 of an ESP32 Development Board.

  Board: ESP32 Development Board
  Component: Touch Sensor
*/

// Define the pin used for the touch sensor
const int sensorPin = 25;

void setup() {
  pinMode(sensorPin, INPUT);     // Set the sensor pin as input
  Serial.begin(9600);            // Start the serial communicatio
}
void loop() {
  if (digitalRead(sensorPin) == 1) {  // If the sensor is touched
    Serial.println("Touch detected!");
  } else {
    Serial.println("No touch detected...");
  }
  delay(100);  // Wait for a short period to avoid rapid reading of the sensor
}