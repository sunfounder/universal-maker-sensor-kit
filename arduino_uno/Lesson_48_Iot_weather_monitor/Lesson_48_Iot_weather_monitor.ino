/*
  This code sends data from an Atmospheric Pressure Sensor(GY-BMP280-3.3) to the 
  ThingSpeak cloud platform using an ESP8266 module and Wi-Fi network. It reads temperature and 
  pressure data from the sensor and sends it to ThingSpeak every 20 seconds.

  Board: Arduino Uno R4 (or R3) and ESP01
  Component: Atmospheric Pressure Sensor(GY-BMP280-3.3)
  Library: https://github.com/adafruit/Adafruit_BMP280_Library  (Adafruit BMP280 by Adafruit)
*/

#include <SoftwareSerial.h>      //Software Serial library
SoftwareSerial espSerial(2, 3);  //Pin 2 and 3 act as RX and TX. Connect them to TX and RX of ESP8266
#define DEBUG true

// Network and thingspeak API configurations
String mySSID = "your_ssid";        // WiFi SSID
String myPWD = "your_password";     // WiFi Password
String myAPI = "xxxxxxxxxxxx";  // API Key
String myHOST = "api.thingspeak.com";
String myPORT = "80";

// Configure request time interval
unsigned long lastConnectionTime = 0;          // Store the last time the server was connected in milliseconds
const unsigned long postingInterval = 20000L;  // Delay between updates in milliseconds (20 seconds)

// Configure GY-BMP280-3.3 module
#include <Wire.h>
#include <Adafruit_BMP280.h>
#define BMP280_ADDRESS 0x76  // BMP280 sensor I2C address
Adafruit_BMP280 bmp;         // use I2C interface
unsigned bmpStatus;
float pressure;
float temperature;

void setup() {
  Serial.begin(9600);
  espSerial.begin(115200);

  // Initialize the ESP8266 module
  sendATCommand("AT+RST", 1000, DEBUG);                                         //Reset the ESP8266 module
  sendATCommand("AT+CWMODE=1", 1000, DEBUG);                                    //Set the ESP mode as station mode
  sendATCommand("AT+CWJAP=\"" + mySSID + "\",\"" + myPWD + "\"", 1000, DEBUG);  //Connect to WiFi network

  // Initialize the bmp280 sensor
  bmpStatus = bmp.begin(BMP280_ADDRESS);
  if (!bmpStatus) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                     "try a different address!"));
    while (1) delay(10);  // Stop code execution if the sensor is not found.
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
  //Send data according to the time interval you set.
  if (millis() - lastConnectionTime > postingInterval) {
    sendData();
  }
}

void sendData() {
  // Read the temperature and pressure from the BMP280 sensor
  pressure = bmp.readPressure();
  temperature = bmp.readTemperature();

  // If the data is invalid, print an error message and stop sending it
  if (isnan(pressure) || isnan(temperature)) {
    Serial.println("Failed to read from BMP sensor!");
    return;
  }

  // Construct the GET request for ThingSpeak
  String sendData = "GET /update?api_key=" + myAPI;
  sendData += "&field1=" + String(temperature);
  sendData += "&field2=" + String(pressure);

  // Send the GET request to ThingSpeak via the ESP8266
  sendATCommand("AT+CIPMUX=1", 1000, DEBUG);                                         //Allow multiple connections
  sendATCommand("AT+CIPSTART=0,\"TCP\",\"" + myHOST + "\"," + myPORT, 1000, DEBUG);  // Start a TCP connection to ThingSpeak
  sendATCommand("AT+CIPSEND=0," + String(sendData.length() + 4), 1000, DEBUG);       // Send the GET request
  espSerial.find(">");                                                         // Wait for the ">" character from the ESP8266
  espSerial.println(sendData);                                                 // Send the GET request
  Serial.println(sendData);

  // Print the values
  Serial.println("Value to be sent: ");
  printBMP();  // Call the printBMP function to print the temperature and pressure

  sendATCommand("AT+CIPCLOSE=0", 1000, DEBUG);  // Close the TCP connection
  lastConnectionTime = millis();          // Update the last connection time
}

void sendATCommand(String command, const int timeout, boolean debug) {
  // Print and send command
  Serial.print("AT Command ==> ");
  Serial.print(command);
  Serial.println();
  espSerial.println(command);  // Send the AT command

  // Get response
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

void printBMP() {
  // Print temperature and pressure data to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C.  Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");
  Serial.println();
}
