/*
  Read the analog value(0-1023) of a potentiometer module connected to 
  pin A0 and prints it to the serial monitor. 

  Board: Arduino Uno R3 (or R4)
  Component: Potentiometer module
*/

// Define the pin numbers for the potentiometer module
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
  delay(50);                              // Wait for 50 milliseconds
}