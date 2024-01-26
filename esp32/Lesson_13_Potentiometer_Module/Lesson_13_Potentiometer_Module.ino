/*
  Read the analog value(0-4095) of a potentiometer module connected to 
  pin 25 and prints it to the serial monitor. 

  Board: ESP32 Development Board
  Component: Potentiometer module
*/

// Define the pin numbers for the potentiometer module
const int sensorPin = 25;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
  delay(50);                              // Wait for 50 milliseconds
}