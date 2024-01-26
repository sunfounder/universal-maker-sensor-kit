/*
  This code controls a one channel relay module using an ESP32 Development Board. 
  The relay is turned on and off in a loop, with a delay of 3 seconds 
  between each state change.
  
  Board: ESP32 Development Board
  Component: One Channel Relay Module
*/

// Define the relay pin as pin 25
const int relayPin = 25;

void setup() {
  // Set relayPin as an output pin
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // Turn off the relay by setting the pin LOW
  digitalWrite(relayPin, LOW);
  delay(3000);

  // Turn on the relay by setting the pin HIGH
  digitalWrite(relayPin, HIGH);
  delay(3000);
}