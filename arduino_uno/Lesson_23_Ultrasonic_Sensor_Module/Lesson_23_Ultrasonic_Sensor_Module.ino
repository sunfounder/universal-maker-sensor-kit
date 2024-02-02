/*
  Read data from an ultrasonic sensor connected to the Arduino board
  and print the distance measurement in centimeters
  through the serial communication.

  Board: Arduino Uno R3 (or R4)
  Component: Ultrasonic distance Sensor(HC-SR04)
*/

// Define the pin numbers for the ultrasonic sensor
const int echoPin = 3;
const int trigPin = 4;

void setup() {
  Serial.begin(9600);                    // Start serial communication with a baud rate of 9600
  pinMode(echoPin, INPUT);               // Set echo pin as input
  pinMode(trigPin, OUTPUT);              // Set trig pin as output
  Serial.println("Ultrasonic sensor:");  // Print a message indicating the ultrasonic sensor is ready
}

void loop() {
  float distance = readDistance();  // Call the function to read the sensor data and get the distance
  Serial.print(distance);           // Print the distance value
  Serial.println(" cm");            // Print " cm" to indicate the unit of measurement
  delay(400);                       // Delay for 400 milliseconds before repeating the loop
}

// Function to read the sensor data and calculate the distance
float readDistance() {
  digitalWrite(trigPin, LOW);   // Set trig pin to low to ensure a clean pulse
  delayMicroseconds(2);         // Delay for 2 microseconds
  digitalWrite(trigPin, HIGH);  // Send a 10 microsecond pulse by setting trig pin to high
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Set trig pin back to low

  // Measure the pulse width of the echo pin and calculate the distance value
  float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
  return distance;
}