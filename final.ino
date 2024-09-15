#include <Servo.h>

// Defines pins for gas sensor and LED
const int gasSensorPin = A1; // MQ-6 A0 Pin
const int gasLEDPin = 12;    // LED Green

// Defines pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

const int trigPin1 = 6;
const int echoPin1 = 7;
// defines variables
long duration1;
int distance1;

// Defines pin for the servo motor
const int servoPin = 8;

// Defines variables for gas sensor
int GAS_VAL = 0;

// Defines variables for ultrasonic sensor
long duration;
int distance;

// Defines variables for the servo motor
Servo servo;
int angle = 70;

// Defines pins for light sensor and LEDs
const int greenLedPin = 2;
const int yellowLedPin = 3;
const int redLedPin = 4;
const int lightSensorPin = A0; // Analog pin for light sensor
int analogValue = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize pins for gas sensor and LED
  pinMode(gasSensorPin, INPUT);
  pinMode(gasLEDPin, OUTPUT);

  // Initialize pins for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize servo motor
  servo.attach(servoPin);
  servo.write(angle);

  // Initialize pins for light sensor and LEDs
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

   pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(A0, OUTPUT);
  
  // Print setup complete message
  Serial.println("Setup complete");
}

void loop() {
  // Gas Sensor Code
  /*
  GAS_VAL = analogRead(gasSensorPin);
  Serial.print("Gas Value: ");
  Serial.println(GAS_VAL);

  if (GAS_VAL > 500) {
    Serial.println("LPG Detected");
    digitalWrite(gasLEDPin, HIGH); // Green LED ON
  } else {
    Serial.println("LPG Not Detected");
    digitalWrite(gasLEDPin, LOW); // Green LED OFF
  }
  */

  // Ultrasonic Sensor Code
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  // Control the servo motor based on distance
  if (distance < 10 and distance>1) {
    // If distance is less than 10, rotate servo to 170 degrees
    servo.write(170);
  } else {
    // If distance is greater than or equal to 10, rotate servo to 70 degrees
    servo.write(70);
  }
s
  // Light Sensor Code
  analogValue = analogRead(lightSensorPin);

  // Print the analog value to the Serial Monitor
  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  if (analogValue < 150) {
    digitalWrite(redLedPin, HIGH);
    Serial.println("Red LED ON");
    digitalWrite(greenLedPin, HIGH);
    Serial.println("Green LED ON");
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance1);

  // Check if distance is less than 10
  if (distance1 < 10 and distance1>0) {
    // If distance is less than 10, set digital pin 13 high
    digitalWrite(A0, HIGH);
  } else {
    // If distance is greater than or equal to 10, set digital pin 13 low
    digitalWrite(A0, LOW);
  }
  delay(400);
}
