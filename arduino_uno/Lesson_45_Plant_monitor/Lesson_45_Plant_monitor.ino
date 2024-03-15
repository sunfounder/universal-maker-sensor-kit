/*
  Automatic watering system based on soil moisture, temperature, and humidity readings.

  Board: Arduino Uno R4 
  Component: I2C LCD1602, DC Water Pump with TA6586 Motor Driver Chip, Soil Moisture Module, and Humiture Sensor Module
  Library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (LiquidCrystal I2C by Frank de Brabander)
           https://github.com/adafruit/DHT-sensor-library  (DHT sensor library by Adafruit)
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 4              // Digital pin for DHT11 sensor
#define DHTTYPE DHT11         // DHT11 sensor type
#define SOIL_MOISTURE_PIN A0  // Analog pin for soil moisture sensor
#define WATER_PUMP_PIN 8      // Digital pin for water pump


// Initialize sensor and LCD objects
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Set pin modes
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(WATER_PUMP_PIN, OUTPUT);

  // Initialize water pump as off
  digitalWrite(WATER_PUMP_PIN, LOW);

  // Initialize LCD and backlight
  lcd.init();
  lcd.backlight();

  // Start DHT sensor
  dht.begin();
}

void loop() {
  // Read humidity and temperature from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read soil moisture level
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);

  // Display temperature and humidity on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperature) + "C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(humidity) + "%");

  delay(2000);

  // Display soil moisture on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture: ");
  lcd.setCursor(0, 1);
  lcd.print(String(soilMoisture));

  // Activate water pump if soil is dry
  if (soilMoisture > 650) {
    digitalWrite(WATER_PUMP_PIN, HIGH);  // Turn on water pump
    delay(1000);                         // Pump water for 1 second
    digitalWrite(WATER_PUMP_PIN, LOW);   // Turn off water pump
  }

  delay(2000);  // Wait before next loop iteration
}
