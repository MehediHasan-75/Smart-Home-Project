int GAS_VAL = 0;

// Define pin for gas sensor and LED
const int gasSensorPin = A1;  // MQ-6 A1 Pin
const int gasLEDPin = 12;     // Gas Sensor Indicator LED

void setup() {
  pinMode(gasSensorPin, INPUT); // MQ-6 A1 Pin
  Serial.begin(9600);
  pinMode(gasLEDPin, OUTPUT);   // Gas Sensor Indicator LED
}

void loop() {
  GAS_VAL = analogRead(gasSensorPin);
  Serial.println(GAS_VAL);

  if (GAS_VAL > 500) {
    Serial.println("LPG Detected");
    digitalWrite(gasLEDPin, HIGH); // Gas LED ON
  } else {
    Serial.println("LPG Not Detected");
    digitalWrite(gasLEDPin, LOW); // Gas LED OFF
  }
  
  delay(100);
}
