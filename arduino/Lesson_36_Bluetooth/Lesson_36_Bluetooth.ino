/*
  The code establishes a software serial communication using Arduino’s 
  SoftwareSerial library, allowing the Arduino to communicate with the 
  JDY-31 Bluetooth module through its digital pins 3 and 4 (as Rx and Tx). It 
  checks for data transfer between them, forwarding received messages from one 
  to the other at a baud rate of 9600. With this code, you can use the 
  Arduino’s serial monitor to send AT firmware commands to the JDY-31 Bluetooth 
  module and receive its responses.
*/

// Set up Bluetooth module communication
#include <SoftwareSerial.h>
const int bluetoothTx = 3;                           // bluetooth tx to 3 pin
const int bluetoothRx = 4;                           // bluetooth rx to 4 pin
SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);  // Declare SoftwareSerial object for Bluetooth communication

void setup() {
  Serial.begin(9600);
  bleSerial.begin(9600);
}

void loop() {
  if (bleSerial.available()) {
    Serial.write(bleSerial.read());
  }
  if (Serial.available()) {
    bleSerial.write(Serial.read());
  }
}