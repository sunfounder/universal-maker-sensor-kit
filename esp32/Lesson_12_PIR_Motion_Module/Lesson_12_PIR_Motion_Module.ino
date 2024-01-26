/*
  This code reads the digital input from a PIR (passive infrared) motion sensor connected to pin 2. 
  If the digital input is HIGH, it prints the message "Somebody here!" to the serial monitor.
  
  Board: ESP32 Development Board
  Component: PIR (passive infrared) motion sensor(HC-SR501)
*/

// Define the pin number for the PIR sensor
const int pirPin = 25;
// Declare and initialize the state variable
int state = 0;

void setup() {
  pinMode(pirPin, INPUT);  // Set the PIR pin as an input
  Serial.begin(9600);      // Start serial communication with a baud rate of 9600
}

void loop() {
  state = digitalRead(pirPin);         // Read the state of the PIR sensor
  if (state == HIGH) {                 // If the PIR sensor detects movement (state = HIGH)
    Serial.println("Somebody here!");  // Print "Somebody here!" to the serial monitor
  } else {
    Serial.println("Monitoring...");
    delay(100);
  }
}