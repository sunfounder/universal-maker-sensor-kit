/*
  This Arduino code implements a Heart Rate Monitor using the MAX30102 sensor and an 
  SSD1306 OLED Display. The code measures the heart rate by calculating the time between 
  beats. It takes four measurements, averages them, and displays this average value on the 
  OLED screen. When the finger is not present on the sensor, it notifies the user to place 
  their finger on it.

  NOTE: This code should NOT be used for any serious or medically reliable heart rate
  monitoring or diagnosis. It is a simple hobbyist project or initial testing setup and is
  not certified or guaranteed to provide accurate and reliable heart rate readings.

  Board: ESP32
  Component: OLED (SSD1306), Pulse Oximeter and Heart Rate Sensor(MAX30102)
  Library: https://github.com/adafruit/Adafruit_SSD1306 (Adafruit SSD1306 by Adafruit)  
           https://github.com/adafruit/Adafruit-GFX-Library (Adafruit GFX Library by Adafruit) 
           https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library  (SparkFun MAX3010x Pulse and Proximity Sensor Library)
*/

#include <Adafruit_GFX.h>  // OLED  libraries
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "MAX30105.h"   // MAX3010x library
#include "heartRate.h"  // Heart rate  calculating algorithm

// Define sensor, rates array, and beat variables
MAX30105 particleSensor;
const byte RATE_SIZE = 4;  // Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE];     // Array  of heart rates
byte rateSpot = 0;
long lastBeat = 0;  // Time at which the last  beat occurred
float beatsPerMinute;
int beatAvg = 0;

// OLED display configuration
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display  height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino  reset pin)
#define SCREEN_ADDRESS 0x3C  // I2C address of the OLED display

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  //Declaring the display name (display)

// Bitmap data for heart icons
static const unsigned char PROGMEM beat1_bmp[] = { 0x03, 0xC0, 0xF0, 0x06, 0x71, 0x8C, 0x0C, 0x1B, 0x06, 0x18, 0x0E, 0x02, 0x10, 0x0C, 0x03, 0x10,
                                                   0x04, 0x01, 0x10, 0x04, 0x01, 0x10, 0x40, 0x01, 0x10, 0x40, 0x01, 0x10, 0xC0, 0x03, 0x08, 0x88,
                                                   0x02, 0x08, 0xB8, 0x04, 0xFF, 0x37, 0x08, 0x01, 0x30, 0x18, 0x01, 0x90, 0x30, 0x00, 0xC0, 0x60,
                                                   0x00, 0x60, 0xC0, 0x00, 0x31, 0x80, 0x00, 0x1B, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x04, 0x00 };

static const unsigned char PROGMEM beat2_bmp[] = { 0x01, 0xF0, 0x0F, 0x80, 0x06, 0x1C, 0x38, 0x60, 0x18, 0x06, 0x60, 0x18, 0x10, 0x01, 0x80, 0x08,
                                                   0x20, 0x01, 0x80, 0x04, 0x40, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x02, 0xC0, 0x00, 0x08, 0x03,
                                                   0x80, 0x00, 0x08, 0x01, 0x80, 0x00, 0x18, 0x01, 0x80, 0x00, 0x1C, 0x01, 0x80, 0x00, 0x14, 0x00,
                                                   0x80, 0x00, 0x14, 0x00, 0x80, 0x00, 0x14, 0x00, 0x40, 0x10, 0x12, 0x00, 0x40, 0x10, 0x12, 0x00,
                                                   0x7E, 0x1F, 0x23, 0xFE, 0x03, 0x31, 0xA0, 0x04, 0x01, 0xA0, 0xA0, 0x0C, 0x00, 0xA0, 0xA0, 0x08,
                                                   0x00, 0x60, 0xE0, 0x10, 0x00, 0x20, 0x60, 0x20, 0x06, 0x00, 0x40, 0x60, 0x03, 0x00, 0x40, 0xC0,
                                                   0x01, 0x80, 0x01, 0x80, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x30, 0x0C, 0x00,
                                                   0x00, 0x08, 0x10, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x01, 0x80, 0x00 };


void setup() {

  Wire.setClock(400000);  // Set I2C speed to 400kHz

  Serial.begin(9600);  // Start serial communication at 9600 baud rate

  // Start the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);  //Start the OLED display
  display.display();

  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST))  //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1)
      ;  // If sensor is not detected, stop the program
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");

  // Configure the sensor
  particleSensor.setup();                     //Configure sensor with default  settings
  particleSensor.setPulseAmplitudeRed(0x0A);  //Turn Red LED to low to  indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0);   //Turn off Green LED
}

void loop() {
  // Get IR value from sensor
  long irValue = particleSensor.getIR();  //Reading the IR value

  //If a finger is detected
  if (irValue > 50000) {

    // Check if a beat is detected
    if (checkForBeat(irValue) == true) {

      display.clearDisplay();                                // Clear the display
      display.drawBitmap(23, 15, beat1_bmp, 24, 21, WHITE);  // Draw the first bmp  picture (little heart)
      display.setTextSize(2);                                // Near  it display the average BPM you can display the BPM if you want
      display.setTextColor(WHITE);
      display.setCursor(60, 10);
      display.println("BPM");
      display.setCursor(60, 28);
      display.println(beatAvg);
      display.display();

      // Calculate the BPM
      long delta = millis() - lastBeat;  // Measure duration between two beats
      lastBeat = millis();
      beatsPerMinute = 60 / (delta / 1000.0);  // Convert to beats per minute

      // Calculate the average BPM
      if (beatsPerMinute < 255 && beatsPerMinute > 20)  // Check if the BPM value is within a valid range
      {
        rates[rateSpot++] = (byte)beatsPerMinute;  // Store this  reading in the array
        rateSpot %= RATE_SIZE;                     // Wrap variable

        // Calculate average of BPM readings
        beatAvg = 0;
        for (byte x = 0; x < RATE_SIZE; x++)
          beatAvg += rates[x];
        beatAvg /= RATE_SIZE;

        delay(100);

        display.clearDisplay();                                // Clear  the display
        display.drawBitmap(18, 10, beat2_bmp, 32, 32, WHITE);  // Draw  the second picture (bigger heart)
        display.setTextSize(2);                                // And  still displays the average BPM
        display.setTextColor(WHITE);
        display.setCursor(60, 10);
        display.println("BPM");
        display.setCursor(60, 28);
        display.println(beatAvg);
        display.display();
      }

      //Print the IR value, current BPM value, and average BPM value to the serial monitor
      Serial.print("IR=");
      Serial.print(irValue);
      Serial.print(", BPM=");
      Serial.print(beatsPerMinute);
      Serial.print(", Avg BPM=");
      Serial.println(beatAvg);
    }
  }
  // If no finger is detected, notify the user
  else {
    // beatAvg = 0;
    Serial.println("Place your index finger on the sensor with steady pressure.");

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(30, 5);
    display.println("Please place ");
    display.setCursor(30, 15);
    display.println("your finger ");
    display.setCursor(30, 25);
    display.println("and wait... ");
    display.display();
  }
}
