// Defines pins for ultrasonic sensor
const int trigPin2 = 6;  // Ultrasonic Sensor 2 (For Thief Detection) TRIG Pin
const int echoPin2 = 7;  // Ultrasonic Sensor 2 (For Thief Detection) ECHO Pin

// Defines variables for ultrasonic sensor
long duration2;
int distance2;

// Defines pin for LED indicator
const int ledPin = 2; // Adjusted to match the LED pin from the main code

void setup() {
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);  // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT);   // Sets the LED pin as an Output
  
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance 2: ");
  Serial.println(distance2);

  // Check if distance is less than 10
  if (distance2 < 10 && distance2 > 1) {
    // If distance is less than 10, turn on LED
    digitalWrite(ledPin, HIGH);
  } else {
    // If distance is greater than or equal to 10, turn off LED
    digitalWrite(ledPin, LOW);
  }
  
  delay(400);
}
