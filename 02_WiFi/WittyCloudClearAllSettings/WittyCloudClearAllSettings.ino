/*
  Clear out the filesystem and any saved settings on a
  Witty Cloud ESP8266 development board.

  This code is in the public domain.
*/

#include <FS.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <EEPROM.h>

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13

void setup() {
  pinMode(ledRed, OUTPUT);     // Initialize the blue LED pin as an output
  pinMode(ledGreen, OUTPUT);   // Initialize the green LED pin as an output
  pinMode(ledBlue, OUTPUT);    // Initialize the red LED pin as an output

  Serial.begin(115200);
  Serial.print("\n\n\n");

  // Set LED to blue while clearing EEPROM
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);

  // Write a 0 to all 512 bytes of the EEPROM
  Serial.println("Clearing 512 bytes of EEPROM...");
  EEPROM.begin(512);
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);

  // Set LED to red while formatting SPIFFS
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);

  // Format SPIFFS
  Serial.println("Formatting SPIFFS...");
  SPIFFS.format();

  // Set LED to red while clearing WiFiManager settings
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);

  // Clear WiFiManager settings, wherever they live
  Serial.println("Clearing WiFiManager settings...");
  WiFiManager wifiManager;
  wifiManager.resetSettings();

  // Set LED to green when completed
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
}

void loop() {
  Serial.println("Device successfully erased.");

  // Flash LED blue/green once the process completes until the
  // heat death of the universe or the device is restarted.
  while (true) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, LOW);
    delay(200);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, HIGH);
    delay(200);
  }
}
