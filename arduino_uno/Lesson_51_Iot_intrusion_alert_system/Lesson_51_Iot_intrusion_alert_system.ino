/*
  This code sets up a simple home intrusion detection system with a Passive Infrared (PIR) sensor (HC-SR501) 
  on an Arduino Uno board using an ESP01 WiFi module for communication. 
  When the system is set to 'Away' mode through the Blynk app, the PIR sensor monitors for motion.
  Any detected movement triggers a notification on the Blynk app, alerting the user of potential intrusion. 

  Board: Arduino Uno R4(or R3) and ESP01
  Component:  Passive infrared motion sensor(HC-SR501)
  Library: https://github.com/blynkkk/blynk-library 
*/

// Template ID, Device Name and Auth Token are provided by the Blynk Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPxxxx"
#define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
#define BLYNK_AUTH_TOKEN "xxxxxx-"

#define BLYNK_PRINT Serial  // Enables debug prints on Serial Monitor

// Include necessary libraries for ESP8266 and Blynk
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>


// Define WiFi credentials
char ssid[] = "your_ssid";
char pass[] = "your_password";  // Set password to "" for open networks.

// Software Serial on Uno
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3);  // RX, TX
#define ESP8266_BAUD 115200      // Set the ESP8266 baud rate
ESP8266 wifi(&EspSerial);

// Define the PIR sensor pin and related variables
const int sensorPin = 8;
int state = 0;
int awayHomeMode = 0;

// Create Blynk Timer object
BlynkTimer timer;

void setup() {

  pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input

  Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging
  EspSerial.begin(ESP8266_BAUD);  // Set ESP8266 baud rate
  delay(10);

  // Configure Blynk and connect to WiFi
  Blynk.config(wifi, BLYNK_AUTH_TOKEN);
  Blynk.connectWiFi(ssid, pass);

  timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run BlynkTimer
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
}

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0) {
  awayHomeMode = param.asInt();  // Set incoming value from pin V0 to a variable

  if (awayHomeMode == 1) {
    Serial.println("The switch on Blynk has been turned on.");
    Blynk.virtualWrite(V1, "Detecting signs of intrusion...");
  } else {
    Serial.println("The switch on Blynk has been turned off.");
    Blynk.virtualWrite(V1, "Away home mode close");
  }
}

void myTimerEvent() {
  // Please don't send more that 10 values per second.
  sendData();  // Call function to send sensor data to Blynk app
}

// Function to send sensor data to Blynk app
void sendData() {
  if (awayHomeMode == 1) {
    state = digitalRead(sensorPin);  // Read the state of the PIR sensor

    Serial.print("state:");
    Serial.println(state);

    // If the sensor detects movement, send an alert to the Blynk app
    if (state == HIGH) {
      Serial.println("Somebody here!");
      Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
      Blynk.logEvent("intrusion_detected");
    }
  }
}
