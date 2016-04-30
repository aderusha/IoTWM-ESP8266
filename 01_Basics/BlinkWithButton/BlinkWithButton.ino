/*
 Based on "Button" by DojoDave and Tom Igoe
 This example code is in the public domain.

 Turns on an LED when the user presses a button
 */

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13

// Declare global variables
int buttonState = 0;            // variable for reading the pushbutton status

void setup() {
  pinMode(ledBlue, OUTPUT);     // initialize the blue LED pin as an output
  pinMode(inputButton, INPUT);  // initialize the pushbutton pin as an input
}

// The loop function runs over and over again forever
void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(inputButton);

  // check if the pushbutton is pressed
  if (buttonState == LOW) {
    digitalWrite(ledBlue, HIGH); // turn ledBlue on
  } else {
    digitalWrite(ledBlue, LOW);  // turn ledBlue off
  }
}
