#include <Servo.h>

// Defines pins for ultrasonic sensors
const int trigPin1 = 9;  // Ultrasonic Sensor 1 (For Parking) TRIG Pin
const int echoPin1 = 10; // Ultrasonic Sensor 1 (For Parking) ECHO Pin

// Defines pin for the servo motor
const int servoPin = 8;

// Defines variables for ultrasonic sensor
long duration1;
int distance1;

// Defines variables for the servo motor
Servo servo;
int angle = 70;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);       // Starts the serial communication

  servo.attach(servoPin);   // Attaches the servo motor to its pin
  servo.write(angle);       // Initializes servo to angle 70
}

void loop() {
  // Clears the trigPin
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
  Serial.print("Distance 1: ");
  Serial.println(distance1);

  // Control the servo motor based on distance
  if (distance1 < 10 && distance1 > 1) {
    // If distance is less than 10, rotate servo to 170 degrees
    servo.write(170);
  } else {
    // If distance is greater than or equal to 10, rotate servo to 70 degrees
    servo.write(70);
  }

  // Wait a short period before repeating the loop
  delay(500);
}
