/*
  Based on "AnalogInOutSerial" by Tom Igoe
  This example code is in the public domain.

  Reads an analog input pin, clips the value to a set max/min,
  maps the result to a range from 255 to 0, and uses the result
  to set the pulsewidth modulation (PWM) of an output pin.
  Toggle the NightLight function on/off with the button, and write
  diagnostic information to the serial output.
*/

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13
const int ldrMin = 100;    // Clip the LDR at max/min values for
const int ldrMax = 400;    // use in varying light conditions

// Declare global variables
int sensorValue = 0;       // value read from the LDR
int outputValue = 0;       // value output to the PWM (analog out)
int powerToggle = 1;       // record power toggle state
int buttonValue = 1;       // value read from the button

void setup() {
  pinMode(inputLDR, INPUT);    // initialize the LDR as an input
  pinMode(inputButton, INPUT); // initialize the button as an input
  pinMode(ledRed, OUTPUT);     // Initialize the blue LED pin as an output
  pinMode(ledGreen, OUTPUT);   // Initialize the blue LED pin as an output
  pinMode(ledBlue, OUTPUT);    // Initialize the blue LED pin as an output
  Serial.begin(9600);          // Initialize serial communication at 9600bps
}

void loop() {
  // read the power toggle button (and negate it as press == LOW on this board)
  buttonValue = !digitalRead(inputButton);
  // catch the power toggle button
  if (buttonValue) {
    Serial.println("Caught button press");
    // if the power is currently on, turn off the LEDs
    if (powerToggle) {
      analogWrite(ledRed, 0);
      analogWrite(ledGreen, 0);
      analogWrite(ledBlue, 0);
    }
    // toggle the current recorded power state
    powerToggle = !powerToggle;
    // wait until the user releases the button
    while (buttonValue) {
      buttonValue = !digitalRead(inputButton);
      delay(50);
    }
  }

  // read the LDR value
  sensorValue = analogRead(inputLDR);
  // clip the recorded value at our defined max/min
  if (sensorValue > ldrMax) {
    sensorValue = ldrMax;
  }
  if (sensorValue < ldrMin) {
    sensorValue = ldrMin;
  }
  // map it to the range of the analog out,
  // inverting the values because it's a nightlight
  outputValue = map(sensorValue, ldrMin, ldrMax, 255, 0);

  if (powerToggle) {
    // write the RGB values out to the LED pins if we're powered on
    analogWrite(ledRed, outputValue);
    analogWrite(ledGreen, outputValue);
    analogWrite(ledBlue, outputValue);
  }

  // print the results to the serial monitor:
  Serial.print("buttonValue = ");
  Serial.print(buttonValue);
  Serial.print("\t power = ");
  Serial.print(powerToggle);
  Serial.print("\t sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 50 milliseconds before the next loop
  delay(50);
}
