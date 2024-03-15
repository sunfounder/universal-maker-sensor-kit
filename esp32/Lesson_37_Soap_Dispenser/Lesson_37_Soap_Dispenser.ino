/*
  This program uses an ESP32 board with an infrared obstacle avoidance sensor and a water pump.
  The sensor is used to detect the presence of an object. When an object is detected, the water pump
  is activated to dispense liquid (liquid hand soap).

  Board: ESP32
  Component: Infrared obstacle avoidance sensor and water pump
*/

// Define the pin numbers for the Infrared obstacle avoidance sensor
const int sensorPin = 35;
int sensorValue;

// Define pin numbers for the water pump
const int pump1A = 19;
const int pump1B = 21;

void setup() {
  // Set the sensor pin as input
  pinMode(sensorPin, INPUT);

  // Initialize the pump pins as output
  pinMode(pump1A, OUTPUT);    
  pinMode(pump1B, OUTPUT);    

  // Keep pump1B low
  digitalWrite(pump1A, LOW); 
  digitalWrite(pump1B, LOW);  

  Serial.begin(9600);
}

void loop() {
  sensorValue = digitalRead(sensorPin);
  Serial.println(sensorValue);

  // If an object is detected, turn on the pump for a brief period, then turn it off
  if (sensorValue == 0) {  
    digitalWrite(pump1A, HIGH);
    delay(700);
    digitalWrite(pump1A, LOW);
    delay(1000);
  }
}
