/*
  This code sets up an Arduino board with an ESP8266 module 
  to detect vibrations and send an HTTP request to IFTTT server 
  when a vibration is detected.The time interval between alerts 
  is set to 120000 milliseconds (2 minutes) to avoid sending too 
  many alerts in a short period of time.

  Board: Arduino Uno R4 (or R3) and ESP01
  Component: Vibration Sensor(SW-420)
*/

#include <SoftwareSerial.h>      //Software Serial library
SoftwareSerial espSerial(2, 3);  //Pin 2 and 3 act as RX and TX. Connect them to TX and RX of ESP8266
#define DEBUG true

// Network and thingspeak API configurations
String mySSID = "your_ssid";     // WiFi SSID
String myPWD = "your_password";  // WiFi Password
String myHOST = "maker.ifttt.com";
String myPORT = "80";
String URL = "/trigger/vibration_detected/with/key/xxxxxxxxxxx";  // Replace with your unique IFTTT URL resource

// Configure request time interval
unsigned long lastAlertTime = 0;                // Stores the last alert time in milliseconds
const unsigned long postingInterval = 120000L;  // Delay between alerts in milliseconds

// Configure Vibration Sensor
const int sensorPin = 7;

void setup() {
  Serial.begin(9600);
  espSerial.begin(115200);

  // Initialize the ESP8266 module
  sendATCommand("AT+RST", 1000, DEBUG);                                         //Reset the ESP8266 module
  sendATCommand("AT+CWMODE=1", 1000, DEBUG);                                    //Set the ESP mode as station mode
  sendATCommand("AT+CWJAP=\"" + mySSID + "\",\"" + myPWD + "\"", 3000, DEBUG);  //Connect to WiFi network

  while (!espSerial.find("OK")) {
    //Wait for connection
  }
}

void loop() {

  if (digitalRead(sensorPin)) {
    if (lastAlertTime == 0 || millis() - lastAlertTime > postingInterval) {
      Serial.println("Detected vibration!!!");
      sendAlert();  //Send an HTTP request to IFTTT server
    } else {
      Serial.print("Detected vibration!!! ");
      Serial.println("Since an email has been sent recently, no warning email will be sent this time to avoid bombarding your inbox.");
    }
  } else {
    if (DEBUG) {
      Serial.println("Detecting...");
    }
  }
  delay(500);
}

void sendAlert() {

  // Construct the GET request for ThingSpeak
  String sendData = "GET " + URL + " HTTP/1.1" + "\r\n";
  sendData += "Host: maker.ifttt.com\r\n";
  sendData += "Connection: close\r\n";
  sendData += "\r\n";

  // Send the GET request to IFTTT via the ESP8266
  sendATCommand("AT+CIPMUX=0", 1000, DEBUG);                                       //Allow multiple connections
  sendATCommand("AT+CIPSTART=\"TCP\",\"" + myHOST + "\"," + myPORT, 3000, DEBUG);  // Start a TCP connection to ThingSpeak
  sendATCommand("AT+CIPSEND=" + String(sendData.length() + 4), 1000, DEBUG);       // Send the GET request
  espSerial.find(">");                                                       // Wait for the ">" character from the ESP8266
  espSerial.println(sendData);                                               // Send the GET request
  Serial.print(sendData);

  sendATCommand("AT+CIPCLOSE", 1000, DEBUG);  // Close the TCP connection
  lastAlertTime = millis();             //Record the time when an HTTP request is sent
}

void sendATCommand(String command, const int timeout, boolean debug) {
  // Print and send command
  Serial.print("AT Command ==> ");
  Serial.print(command);
  Serial.println();
  espSerial.println(command);  // Send the AT command

  // Get the response from the ESP8266 module
  String response = "";
  long int time = millis();
  while ((time + timeout) > millis()) {  // Wait for the response until the timeout
    while (espSerial.available()) {
      char c = espSerial.read();
      response += c;
    }
  }

  // Print response if debug mode is on
  if (debug) {
    Serial.println(response);
    Serial.println("--------------------------------------");
  }

}
