/*
  The code establishes a software serial communication using Arduino’s 
  SoftwareSerial library, allowing the Arduino to communicate with the 
  ESP8266 module through its digital pins 2 and 3 (as Rx and Tx). It checks 
  for data transfer between them, forwarding received messages from one to 
  the other at a baud rate of 115200. With this code, you can use the 
  Arduino’s serial monitor to send AT firmware commands to the ESP8266 module 
  and receive its responses.
*/

#include <SoftwareSerial.h>
SoftwareSerial espSerial(2, 3);  //Rx,Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  espSerial.begin(115200);
}

void loop() {
  if (espSerial.available()) {
    Serial.write(espSerial.read());
  }
  if (Serial.available()) {
    espSerial.write(Serial.read());
  }
}