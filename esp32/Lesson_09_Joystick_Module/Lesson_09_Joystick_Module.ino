/*
  The code reads values from a joystick module and prints them on the serial monitor. 
  The joystick module has two analog axes (X and Y). The decimal form of the X and Y 
  axis values is read and displayed on the serial monitor.

  Board: ESP32 Development Board
  Component: Joystick Module
*/

const int xPin = 27;  //the VRX attach to
const int yPin = 26;  //the VRY attach to
const int swPin = 25;  //the SW attach to

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
