/*
  Read the analog output value(0-1023) of the gas sensor and print it 
  to the serial monitor.
  Note: After the sensor is powered on, it needs to be preheated for 
  at least 3 minute before stable measurement readings can be obtained. 
  It is normal for the sensor to generate heat during operation due to 
  the presence of a heating wire inside.

  Board: Arduino Uno R3 (or R4)
  Component: Gas Sensor(MQ-2)
*/

// Define the pin numbers for the Gas Sensor
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.print("Analog output: ");
  Serial.println(analogRead(sensorPin));  // Read the analog value of the gas sensor and print it to the serial monitor
  delay(50);                             // Wait for 50 milliseconds
}
