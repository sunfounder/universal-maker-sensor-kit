/*
  This code measures the speed of a motor connected to an Arduino Uno 
  using a speed sensor module.

  Board: Arduino Uno R3 (or R4)
  Component: Speed Sensor Module
*/

// Define the sensor and motor pins
const int sensorPin = 11;
const int motorB_1A = 9;
const int motorB_2A = 10;

// Define variables for measuring speed
unsigned long start_time = 0;
unsigned long end_time = 0;
int steps = 0;
float steps_old = 0;
float temp = 0;
float rps = 0;

void setup() {
  Serial.begin(9600);

  pinMode(sensorPin, INPUT);   // set sensor pin as input
  pinMode(motorB_1A, OUTPUT);  // set motor pin 1 as output
  pinMode(motorB_2A, OUTPUT);  // set motor pin 2 as output

  analogWrite(motorB_1A, 160);  // set motor speed
  analogWrite(motorB_2A, 0);
}

void loop() {
  start_time = millis();
  end_time = start_time + 1000;

  // measure steps taken within 1 second
  while (millis() < end_time) {
    if (digitalRead(sensorPin)) {
      steps = steps + 1;
      while (digitalRead(sensorPin))
        ;
    }
  }
  temp = steps - steps_old;
  steps_old = steps;
  rps = (temp / 20);  // calculate revolutions per second, adjust the denominator to match your current situation.

  // print the revolutions per second
  Serial.print("rps:");
  Serial.println(rps);
}