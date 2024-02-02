/*
  A simple code to read input from a touch sensor
  connected to pin 7 of an Arduino Uno board.
  If the sensor is touched, the built-in LED is turned on
  and a message is printed to the serial monitor.
  If the sensor is not touched, the LED is turned off
  and a different message is printed.

  Board: Arduino Uno R3 (or R4)
  Component: Touch Sensor
*/

// Define the pin used for the touch sensor
const int sensorPin = 7;

void setup() {
  pinMode(sensorPin, INPUT);     // Set the sensor pin as input
  pinMode(LED_BUILTIN, OUTPUT);  // Set the built-in LED pin as output
  Serial.begin(9600);            // Start the serial communicatio
}
void loop() {
  if (digitalRead(sensorPin) == 1) {  // If the sensor is touched
    digitalWrite(LED_BUILTIN, HIGH);  // Turn on the built-in LED
    Serial.println("Touch detected!");
  } else {
    digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED
    Serial.println("No touch detected...");
  }
  delay(100);  // Wait for a short period to avoid rapid reading of the sensor
}