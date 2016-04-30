/*
 Based on "Button" by DojoDave and Tom Igoe
 This example code is in the public domain.

 Turns on an LED when the user presses a button
 */

// Declare constants. Used here to set pin numbers.
const int buttonPin = D2;       // D2 is the pushbutton, LOW == pressed, HIGH == not pressed
const int ledPin =  D7;         // D7 is the blue LED

// Declare global variables
int buttonState = 0;            // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);      // initialize the blue LED pin as an output
  pinMode(buttonPin, INPUT);    // initialize the pushbutton pin as an input
}

// The loop function runs over and over again forever
void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH); // turn LED on
  } else {
    digitalWrite(ledPin, LOW);  // turn LED off
  }
}
