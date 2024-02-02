/*
  This code initializes an RGB LED module and displays the primary colors of red, green, and blue. 
  It then proceeds to display the seven colors of the rainbow in sequence.
  
  Board: Arduino Uno R3 (or R4)
  Component: RGB LED module
*/

// Pin numbers for each color channel
const int rledPin = 9;  // pin connected to the red color channel
const int gledPin = 10;  // pin connected to the green color channel
const int bledPin = 11;   // pin connected to the blue color channel

void setup() {
  pinMode(rledPin, OUTPUT);
  pinMode(gledPin, OUTPUT);
  pinMode(bledPin, OUTPUT);
}

void loop() {
setColor(255, 0, 0);  // Set RGB LED color to red
delay(1000);
setColor(0, 255, 0);  // Set RGB LED color to green
delay(1000);
setColor(0, 0, 255);  // Set RGB LED color to blue
delay(1000);

// Display the colors of the rainbow
setColor(255, 0, 0);  // Set RGB LED color to red
delay(1000);
setColor(255, 165, 0);  // Set RGB LED color to orange
delay(1000);
setColor(255, 255, 0);  // Set RGB LED color to yellow
delay(1000);
setColor(0, 128, 0);  // Set RGB LED color to green
delay(1000);
setColor(0, 0, 255);  // Set RGB LED color to blue
delay(1000);
setColor(75, 0, 130);  // Set RGB LED color to indigo
delay(1000);
setColor(230, 130, 238);  // Set RGB LED color to violet
delay(1000);
}

void setColor(int R, int G, int B) {
  analogWrite(rledPin, R);  // Set the intensity of the red color channel
  analogWrite(gledPin, G);  // Set the intensity of the green color channel
  analogWrite(bledPin, B);  // Set the intensity of the blue color channel
}