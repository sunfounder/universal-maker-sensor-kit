/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  NOTE: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
#define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxx"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


// Define WiFi credentials
char ssid[] = "your_ssid";
char pass[] = "your_password";

// Define the PIR sensor pin and related variables
const int sensorPin = 14;
int state = 0;
int awayHomeMode = 0;

// Create Blynk Timer object
BlynkTimer timer;

void setup() {

  pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input
  Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging

  // Configure Blynk and connect to WiFi
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

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
