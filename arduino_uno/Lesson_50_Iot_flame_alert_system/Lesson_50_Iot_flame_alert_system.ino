/*
  Detect flames using a flame sensor connected to an Arduino Uno board and an ESP-01 module, 
  and send an alert to the Blynk app using the Blynk Cloud service.
  This example shows how value can be pushed from Arduino to the Blynk App.

  Board: Arduino Uno R4 (or R3) and ESP01
  Component:  Flame sensor
  Library: https://github.com/blynkkk/blynk-library 
*/

// Template ID, Device Name and Auth Token are provided by the Blynk Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
#define BLYNK_TEMPLATE_NAME "Flame Alert System"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

//Set debug prints on Serial Monitor
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>               // Library for ESP8266
#include <BlynkSimpleShieldEsp8266.h>  // Library for Blynk

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your_ssid";
char pass[] = "your_password";

// Software Serial on Uno
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3);  // RX, TX
#define ESP8266_BAUD 115200      // Set the ESP8266 baud rate
ESP8266 wifi(&EspSerial);

// Flame sensor pin
const int sensorPin = 8;

BlynkTimer timer;

void myTimerEvent() {
  // Please don't send more that 10 values per second.
  sendData();  // Call function to send sensor data to Blynk app
}

// Function to send sensor data to Blynk app
void sendData() {
  int data = digitalRead(sensorPin);
  Blynk.virtualWrite(V0, data);  // send data to virtual pin V0 on Blynk
  Serial.print("flame:");        
  Serial.println(data);          // Print flame status on Serial Monitor
  if (data == 0) {
    Blynk.logEvent("flame_detection_alert");  // log flame alert event if sensor detects flame
  }
}

void setup() {
  pinMode(sensorPin, INPUT);  // Set flame sensor pin as input

  Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging
  EspSerial.begin(ESP8266_BAUD);  // Set ESP8266 baud rate
  delay(1000);

  timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second

  // Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);  // Connect to Blynk app with authentication token and WiFi credentials
  Blynk.config(wifi,BLYNK_AUTH_TOKEN);
  Blynk.connectWiFi(ssid, pass);
}

void loop() {
  Blynk.run();
  timer.run();  // Initiates BlynkTimer
}
