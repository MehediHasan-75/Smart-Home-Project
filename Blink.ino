#define BLYNK_TEMPLATE_ID "TMPL6srCHVLYh"
#define BLYNK_TEMPLATE_NAME "nodemcu"
#define BLYNK_AUTH_TOKEN "93rVaCGyT2yKeTtMfHAY7t3OWUQzdjjb"


#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your unique Blynk Auth Token
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials
char ssid[] = "Okay";
char pass[] = "okayokay1";

// Define the pins for the LEDs
const int ledPin1 = D0;
const int ledPin2 = D1;
const int ledPin3 = D2;

void setup() {
  // Debug console
  Serial.begin(9600);

  // Blynk begins
  Blynk.begin(auth, ssid, pass);

  // Initialize the digital pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // Run Blynk
  Blynk.run();
}

// Blynk function to control the LED on D0
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // Get value from the Blynk app
  digitalWrite(ledPin1, pinValue); // Set LED state
}

// Blynk function to control the LED on D1
BLYNK_WRITE(V2) {
  int pinValue = param.asInt(); // Get value from the Blynk app
  digitalWrite(ledPin2, pinValue); // Set LED state
}

// Blynk function to control the LED on D2
BLYNK_WRITE(V3) {
  int pinValue = param.asInt(); // Get value from the Blynk app
  digitalWrite(ledPin3, pinValue); // Set LED state
}
