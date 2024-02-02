/*
  This program reads atmospheric pressure, temperature and approximate altitude from an Atmospheric 
  Pressure Sensor(GY-BMP280-3.3) using an Arduino Uno board. It uses the Adafruit BMP280 library to 
  interface with the sensor, and prints the readings to the Serial Monitor.
  
  Board: Arduino Uno R3 (or R4)
  Component: Atmospheric Pressure Sensor(GY-BMP280-3.3)
  Library: https://github.com/adafruit/Adafruit_BMP280_Library  (Adafruit BMP280 by Adafruit)
*/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;  // use I2C interface

void setup() {
  Serial.begin(9600);          // initialize serial communication with baud rate of 9600
  while (!Serial) delay(100);  // wait for native usb
  Serial.println(F("BMP280 test"));

  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
  if (!status) {
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
  // Read and print temperature in degrees Celsius.
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  //Read and print atmospheric pressure in hectopascals (hPa).
  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  Serial.println(" hPa");

  //Read and print approximate altitude based on standard pressure (1013.25 hPa).
  Serial.print(F("Approx altitude = "));
  Serial.print(bmp.readAltitude(1013.25));
  Serial.println(" m");

  Serial.println();  // Print a blank line to separate readings.
  delay(2000);       // Wait for 2 seconds before taking the next set of readings.
}