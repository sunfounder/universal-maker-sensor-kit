/*
  This code controls a one channel relay module using an Arduino Uno. 
  The relay is turned on and off in a loop, with a delay of 3 seconds 
  between each state change.
  
  Board: Arduino Uno R3 (or R4)
  Component: One Channel Relay Module
*/

// Define the relay pin as pin 6
const int relayPin = 6;

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