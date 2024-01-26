/*
  This Arduino code snippet reads temperature data from a DS18B20 temperature 
  sensor module and displays it on the Serial Monitor. The temperature readings 
  are provided in both Celsius and Fahrenheit units, using the DallasTemperature 
  library to interface with the sensor.

  Board: ESP32 Development Board
  Component: Temperature Sensor Module (DS18B20)
  Library: https://github.com/milesburton/Arduino-Temperature-Control-Library  (DallasTemperature by Miles Burton)
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire 
#define ONE_WIRE_BUS 25

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);	

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();	// Start up the library
  Serial.begin(9600);
}

void loop(void)
{ 
  // Send the command to get temperatures
  sensors.requestTemperatures(); 

  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("℃ | ");
  
  //print the temperature in Fahrenheit
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.println("℉");
  
  delay(500);
}