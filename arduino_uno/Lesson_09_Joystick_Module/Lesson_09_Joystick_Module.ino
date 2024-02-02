/*
  The code reads values from a joystick module and prints them on the serial monitor. 
  The joystick module has two analog axes (X and Y), which are connected to Arduino 
  pins A0 and A1. The decimal form of the X and Y axis values is read and displayed 
  on the serial monitor.

  Board: Arduino Uno R3(or R4)
  Component: Joystick Module
*/

const int xPin = A0;  //the VRX attach to
const int yPin = A1;  //the VRY attach to
const int swPin = 8;  //the SW attach to

void setup() {
  pinMode(swPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  Serial.print("X: ");
  Serial.print(analogRead(xPin));  // print the value of VRX
  Serial.print("|Y: ");
  Serial.print(analogRead(yPin));  // print the value of VRX
  Serial.print("|Z: ");
  Serial.println(digitalRead(swPin));  // print the value of SW
  delay(50);
}
