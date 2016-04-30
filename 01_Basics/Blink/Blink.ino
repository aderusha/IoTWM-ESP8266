/*
 Based on "ESP8266 Blink" by Simon Peter
 This example code is in the public domain
 
 Blink the blue LED on the Witty Cloud
*/

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13

void setup() {
  pinMode(ledBlue, OUTPUT);    // Initialize the blue LED pin as an output
  Serial.begin(9600);          // initialize serial communication at 9600bps
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledBlue, HIGH); // Turn the LED on
  Serial.println("LED On");    // Announce that we've turned on the LED over the serial port
  delay(1000);                 // Wait for a second
  digitalWrite(ledBlue, LOW);  // Turn the LED off
  Serial.println("LED Off");   // Announce that we've turned off the LED over the serial port
  delay(2000);                 // Wait for two seconds (to demonstrate the active low LED)
}
