/*
 Based on: ESP8266 Blink by Simon Peter
 This example code is in the public domain
 
 Blink the blue LED on the Witty Cloud
 
 The blue LED on the Witty Cloud module is connected to D7
*/

void setup() {
  pinMode(D7, OUTPUT);     // Initialize the D7 pin as an output
  Serial.begin(9600);      // initialize serial communication at 9600 bits per second
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D7, HIGH);    // Turn the LED on
  Serial.println("LED On");  // Announce that we've turned on the LED over the serial port
  delay(1000);               // Wait for a second
  digitalWrite(D7, LOW);     // Turn the LED off
  Serial.println("LED Off"); // Announce that we've turned off the LED over the serial port
  delay(2000);               // Wait for two seconds (to demonstrate the active low LED)
}
