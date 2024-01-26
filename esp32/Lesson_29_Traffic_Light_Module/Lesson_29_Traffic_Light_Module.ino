/*
  This code controls a LED Mini Traffic Light Module using an ESP32 Development Board. 
  The code sets the pin modes to OUTPUT and then runs a loop that cycles through 
  the traffic light pattern: green light on for 5 seconds, yellow light on for 1.5 
  seconds, red light on for 5 seconds, and then the pattern repeats.

  Board: ESP32 Development Board
  Component: LED Mini Traffic Light Module
*/

// Pin numbers for each LED
const int rledPin = 25;  //red
const int yledPin = 26;  //yellow
const int gledPin = 27;  //green

void setup() {
  pinMode(rledPin, OUTPUT);
  pinMode(yledPin, OUTPUT);
  pinMode(gledPin, OUTPUT);
}

void loop() {
  // Green LED on for 5 seconds
  digitalWrite(gledPin, HIGH);
  delay(5000);
  digitalWrite(gledPin, LOW);

  // Blink yellow LED three times with intervals of 0.5 seconds
  digitalWrite(yledPin, HIGH);
  delay(500);
  digitalWrite(yledPin, LOW);
  delay(500);
  digitalWrite(yledPin, HIGH);
  delay(500);
  digitalWrite(yledPin, LOW);
  delay(500);
  digitalWrite(yledPin, HIGH);
  delay(500);
  digitalWrite(yledPin, LOW);
  delay(500);

  // Red LED on for 5 seconds
  digitalWrite(rledPin, HIGH);
  delay(5000);
  digitalWrite(rledPin, LOW);
}