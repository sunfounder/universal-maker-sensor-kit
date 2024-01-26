/*
  This program tests the Adafruit VL53L0X Time of Flight Distance Sensor.
  It initializes the sensor, reads a distance measurement, and prints the 
  distance in millimeters to the serial monitor.
  Note: The VL53L0X can handle about 50 - 1200 mm of range distance.

  Board: ESP32 Development Board
  Component: Time of Flight Distance Sensor (GY-530 base on VL53L0X)
  Library: https://github.com/adafruit/Adafruit_VL53L0X  (Adafruit_VL53L0X by Adafruit)
*/


#include <Adafruit_VL53L0X.h>

//Create an object of the Adafruit_VL53L0X class
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (!Serial) {
    delay(1);
  }

  //Initialize the sensor
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1)  //Stop the program if the sensor cannot be initialized
      ;
  }

  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false);  // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): ");
    Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }

  delay(100);
}