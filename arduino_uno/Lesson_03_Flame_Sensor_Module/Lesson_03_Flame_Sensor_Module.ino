/*
  The code reads the output of a flame sensor connected to pin 7 of an Arduino Uno board, 
  and turns on the built-in LED and prints a message to the serial monitor if a flame is 
  detected. If no flame is detected, the built-in LED is turned off and a message is 
  printed to the serial monitor.

  Board: Arduino Uno R3 (or R4)
  Component: Flame sensor module
*/

// Define the pin used for the flame sensor
const int sensorPin = 7;

void setup() {
  pinMode(sensorPin, INPUT);     // Set the flame sensor pin as input
  pinMode(LED_BUILTIN, OUTPUT);  // Set the built-in LED pin as output
  Serial.begin(9600);            // Initialize the serial monitor at a baud rate of 9600
}
void loop() {
  // Check if the sensor is detecting a fire
  if (digitalRead(sensorPin) == 0) {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn on the built-in LED
    Serial.println("** Fire detected!!! **");
  } else {
    digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED
    Serial.println("No Fire detected");
  }
  delay(100);
}