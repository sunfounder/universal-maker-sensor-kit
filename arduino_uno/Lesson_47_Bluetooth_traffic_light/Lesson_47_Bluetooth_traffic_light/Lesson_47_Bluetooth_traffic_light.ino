/*
  The code initializes a Bluetooth module for communication and sets up 
  three LEDs (red, yellow, and green). It reads characters from the Bluetooth 
  connection, and based on the received character ('R', 'Y', or 'G'), it 
  toggles the respective LED (turning all other LEDs off).

  Board: Arduino Uno R4 (or R3)
  Component: JDY-31 bluetooth module and Traffic Light Module
*/

// Set up Bluetooth module communication
#include <SoftwareSerial.h>
const int bluetoothTx = 3;                           // bluetooth tx to 3 pin
const int bluetoothRx = 4;                           // bluetooth rx to 4 pin
SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);  // Declare SoftwareSerial object for Bluetooth communication

// Pin numbers for each LED
const int rledPin = 10;  //red
const int yledPin = 11;  //yellow
const int gledPin = 12;  //green

char character;  // Character received from Bluetooth communication

void setup() {
  // Set LED pins as output
  pinMode(rledPin, OUTPUT);
  pinMode(yledPin, OUTPUT);
  pinMode(gledPin, OUTPUT);

  Serial.begin(9600);
  bleSerial.begin(9600);
}

void loop() {
  // Check if there are data available from the Bluetooth module
  while (bleSerial.available() > 0) {

    character = bleSerial.read();  // Read the incoming character
    Serial.println(character);     // Print the received character to the serial monitor

    // Toggle respective LED based on received character
    if (character == 'R') {
      toggleLights(rledPin);
    } else if (character == 'Y') {
      toggleLights(yledPin);
    } else if (character == 'G') {
      toggleLights(gledPin);
    }
  }
}

// Function to turn off all LEDs and turn on the specified LED
void toggleLights(int targetLight) {
  digitalWrite(rledPin, LOW);  // Turn off Red LED
  digitalWrite(yledPin, LOW);  // Turn off Yellow LED
  digitalWrite(gledPin, LOW);  // Turn off Green LED

  digitalWrite(targetLight, HIGH);  // Turn on the target LED
}
