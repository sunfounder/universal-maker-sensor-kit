/*
  This code defines and initializes two pins for a motor and sets its speed.

  Board: ESP32 Development Board
  Component: Motor and L9110 motor control board
*/

// Define the motor pins
const int motorB_1A = 26;
const int motorB_2A = 25;


void setup() {

  pinMode(motorB_1A, OUTPUT);  // set motor pin 1 as output
  pinMode(motorB_2A, OUTPUT);  // set motor pin 2 as output

  analogWrite(motorB_1A, 255);  // set motor speed (0-255)
  analogWrite(motorB_2A, 0);

  delay(5000);

  analogWrite(motorB_1A, 0);  
  analogWrite(motorB_2A, 0);

}

void loop() {

}