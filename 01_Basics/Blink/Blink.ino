/*
 Based on "ESP8266 Blink" by Simon Peter
 This example code is in the public domain
 
 Blink the blue LED on the Witty Cloud
*/

// Declare constants. Used here to set pin numbers.
const int ledPin =  D7;       // D7 is the blue LED

void setup() {
  pinMode(ledPin, OUTPUT);    // Initialize the D7 pin as an output
  Serial.begin(9600);         // initialize serial communication at 9600 bits per second
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  Serial.println("LED On");   // Announce that we've turned on the LED over the serial port
  delay(1000);                // Wait for a second
  digitalWrite(ledPin, LOW);  // Turn the LED off
  Serial.println("LED Off");  // Announce that we've turned off the LED over the serial port
  delay(2000);                // Wait for two seconds (to demonstrate the active low LED)
}
