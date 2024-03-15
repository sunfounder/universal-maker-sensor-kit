/*
  This Arduino code is designed to operate a relay-controlled light, which 
  turns on when motion is detected by a PIR (passive infrared) sensor, and 
  tays on for 5 seconds since the last motion was detected.
  
  Board: Arduino Uno
  Component: PIR (passive infrared) motion sensor(HC-SR501) and Relay module
*/

// Define the pin number for the relay
const int relayPin = 9;

// Define the pin number for the PIR sensor
const int pirPin = 8;

// Motion delay threshold in milliseconds
const unsigned long MOTION_DELAY = 5000;

unsigned long lastMotionTime = 0;  // Timestamp of the last motion detection
bool motionDetected = false;       // Flag to track if motion is detected

void setup() {
  pinMode(relayPin, OUTPUT);    // Set relayPin as an output pin
  pinMode(pirPin, INPUT);       // Set the PIR pin as an input
  digitalWrite(relayPin, LOW);  // Turn off the relay initially
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    lastMotionTime = millis();     // Update the last motion time
    digitalWrite(relayPin, HIGH);  // Turn on the relay (and hence the light)
    motionDetected = true;
  }

  // If motion was detected earlier and 5 seconds have elapsed, turn off the relay
  if (motionDetected && (millis() - lastMotionTime >= MOTION_DELAY)) {
    digitalWrite(relayPin, LOW);  // Turn off the relay
    motionDetected = false;
  }
}