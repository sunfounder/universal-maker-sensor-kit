/*
  This code reads the digital value from a Infrared obstacle avoidance sensor connected to 
  pin 25 and prints it to the serial monitor every 50 milliseconds.
  When the module detects obstacles ahead, the red indicator light on the module will 
  illuminate and the OUT port will continuously output a low-level signal.

  Board: ESP32 Development Board
  Component: Infrared obstacle avoidance sensor
*/

// Define the pin numbers for the Infrared obstacle avoidance sensor
const int sensorPin = 25;

void setup() {
  pinMode(sensorPin, INPUT);  // Set sensorPin as input
  Serial.begin(9600);         // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(digitalRead(sensorPin));  // Read the digital value from the sensor and print it to the serial monitor
  delay(50);
}