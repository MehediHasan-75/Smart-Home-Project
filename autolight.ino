// Defines pins for LEDs
const int greenLedPin = 2;
const int yellowLedPin = 3;
const int redLedPin = 4;

// Defines pin for light sensor
const int lightSensorPin = A0; // Light Sensor Pin
int analogValue = 0;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  Serial.begin(9600);  // Initialize the serial communication at 9600 baud rate
}

void loop() {
  analogValue = analogRead(lightSensorPin);
  
  // Print the analog value to the Serial Monitor
  Serial.print("Analog Value: ");
  Serial.println(analogValue);
  
  if (analogValue < 300) { // Adjusted threshold to 300 as per main code
    digitalWrite(redLedPin, HIGH);
    Serial.println("Red LED ON");
    digitalWrite(greenLedPin, HIGH);
    Serial.println("Green LED ON");
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }
  
  delay(500); // Add a delay for stability
}
