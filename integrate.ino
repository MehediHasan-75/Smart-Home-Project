#include <Servo.h>

// Defines pins for gas sensor and LED
const int gasSensorPin = A1;  // MQ-6 A1 Pin
const int gasLEDPin = 12;     // Gas Sensor Indicator LED

// Defines pins for ultrasonic sensors
const int trigPin1 = 9;  // Ultrasonic Sensor 1 (For Parking) TRIG Pin
const int echoPin1 = 10; // Ultrasonic Sensor 1 (For Parking) ECHO Pin
const int trigPin2 = 6;  // Ultrasonic Sensor 2 (For Thief Detection) TRIG Pin
const int echoPin2 = 7;  // Ultrasonic Sensor 2 (For Thief Detection) ECHO Pin

// Defines pin for the servo motor
const int servoPin = 8;

// Defines variables for gas sensor
int GAS_VAL = 0;

// Defines variables for ultrasonic sensors
long duration1, duration2;
int distance1, distance2;

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

  // Initialize pins for ultrasonic sensors
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Initialize servo motor
  servo.attach(servoPin);
  servo.write(angle);

  // Initialize pins for light sensor and LEDs
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Print setup complete message
  Serial.println("Setup complete");
}

void loop() {
  // Gas Sensor Code
  GAS_VAL = analogRead(gasSensorPin);
  Serial.print("Gas Value: ");
  Serial.println(GAS_VAL);

  if (GAS_VAL > 500) {
    Serial.println("LPG Detected");
    digitalWrite(gasLEDPin, HIGH); // Gas LED ON
  } else {
    Serial.println("LPG Not Detected");
    digitalWrite(gasLEDPin, LOW); // Gas LED OFF
  }

  // Ultrasonic Sensor 1 Code (For Parking)
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.print("Distance 1: ");
  Serial.println(distance1);

  // Control the servo motor based on distance from Ultrasonic Sensor 1
  if (distance1 < 10 && distance1 > 1) {
    servo.write(170);
  } else {
    servo.write(70);
  }

  // Ultrasonic Sensor 2 Code (For Thief Detection)
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  Serial.print("Distance 2: ");
  Serial.println(distance2);

  // Light Sensor Code
  analogValue = analogRead(lightSensorPin);
  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  if (analogValue < 300) {
    digitalWrite(redLedPin, HIGH);
    Serial.println("Red LED ON");
    digitalWrite(greenLedPin, HIGH);
    Serial.println("Green LED ON");
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }

  // Add a delay to stabilize the readings
  delay(500);
}
