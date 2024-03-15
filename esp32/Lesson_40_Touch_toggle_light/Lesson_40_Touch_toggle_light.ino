/*
  The code controls a traffic light LED module with a touch sensor. 
  Once the touch sensor is activated, the LEDs cycle through turning 
  on in sequence: Red -> Yellow -> Green.

  Board: ESP32
  Component: Touch Sensor Module and Traffic Light Module
*/

// Define pins for touch sensor and LEDs
const int touchSensorPin = 14;  // touch sensor pin
const int rledPin = 27;         // red LED pin
const int yledPin = 26;         // yellow LED pin
const int gledPin = 25;         // green LED pin

int lastTouchState;     // the previous state of touch sensor
int currentTouchState;  // the current state of touch sensor
int currentLED = 0;     // current LED 0->Red, 1->Yellow, 2->Green

void setup() {
  Serial.begin(9600);              // initialize serial
  pinMode(touchSensorPin, INPUT);  // configure touch sensor pin as input

  // set LED pins as outputs
  pinMode(rledPin, OUTPUT);
  pinMode(yledPin, OUTPUT);
  pinMode(gledPin, OUTPUT);

  currentTouchState = digitalRead(touchSensorPin);
}

void loop() {
  lastTouchState = currentTouchState;               // save the last state
  currentTouchState = digitalRead(touchSensorPin);  // read new state

  // check if the touch sensor was just touched
  if (lastTouchState == LOW && currentTouchState == HIGH) {
    Serial.println("The sensor is touched");

    turnAllLEDsOff();  // Turn off all LEDs

    // switch on the next LED in sequence
    switch (currentLED) {
      case 0:
        digitalWrite(rledPin, HIGH);
        currentLED = 1;
        break;
      case 1:
        digitalWrite(yledPin, HIGH);
        currentLED = 2;
        break;
      case 2:
        digitalWrite(gledPin, HIGH);
        currentLED = 0;
        break;
    }
  }
}

// function to turn off all LEDs
void turnAllLEDsOff() {
  digitalWrite(rledPin, LOW);
  digitalWrite(yledPin, LOW);
  digitalWrite(gledPin, LOW);
}
