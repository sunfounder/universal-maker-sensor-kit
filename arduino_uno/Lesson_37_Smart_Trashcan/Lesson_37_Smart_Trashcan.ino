/*
  This is an Arduino code for a smart trash can that automatically opens its lid when an object comes within 20cm of it.
  
  This Arduino code controls an SG90 servo motor based on readings from an ultrasonic distance sensor. 
  The distance is measured three times, and the average is computed. If the averaged distance is less 
  than or equal to 20, the servo rotates to an open angle of 180 degrees; otherwise, it returns to a 
  closed position of 0 degrees after a one-second delay. 

  Board: Arduino Uno R3 (or R4)
  Component: Servo motor(SG90) and Ultrasonic distance Sensor(HC-SR04)
*/

#include <Servo.h>

// Set up the servo motor parameters
Servo servo;
const int servoPin = 9;
const int openAngle = 0;
const int closeAngle = 90;

// Set up the ultrasonic sensor parameters
const int trigPin = 6;
const int echoPin = 5;
long distance, averageDistance;
long averDist[3];

// Distance threshold in centimeters
const int distanceThreshold = 20;

void setup() {
  // Initialize serial communication with the computer at 9600 baud rate
  Serial.begin(9600);

  // Configure the trigger and echo pins of the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach the servo to its control pin and set its initial position
  servo.attach(servoPin);
  servo.write(closeAngle);
  delay(100);
  servo.detach();  // Detach the servo to save power when not in use
}

void loop() {
  // Measure the distance three times
  for (int i = 0; i <= 2; i++) {
    distance = readDistance();
    averDist[i] = distance;
    delay(10);
  }

  // Calculate the average distance
  averageDistance = (averDist[0] + averDist[1] + averDist[2]) / 3;
  Serial.println(averageDistance);

  // Control the servo based on the averaged distance
  if (averageDistance <= distanceThreshold) {
    servo.attach(servoPin);  // Reattach the servo before sending a command
    delay(1);
    servo.write(openAngle);  // Rotate the servo to the open position
    delay(3500);
  } else {
    servo.write(closeAngle);  // Rotate the servo back to the closed position
    delay(1000);
    servo.detach();  // Detach the servo to save power when not in use
  }
}

// Function to read the sensor data and calculate the distance
float readDistance() {
  // Send a pulse on the trigger pin of the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse width of the echo pin and calculate the distance value
  float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
  return distance;
}
