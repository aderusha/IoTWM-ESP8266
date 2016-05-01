
#include <FS.h>                   //this needs to be first, or it all crashes and burns...
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <EEPROM.h>

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13

void setup() {
  pinMode(ledRed, OUTPUT);     // Initialize the blue LED pin as an output
  pinMode(ledGreen, OUTPUT);   // Initialize the blue LED pin as an output
  pinMode(ledBlue, OUTPUT);    // Initialize the blue LED pin as an output

  Serial.begin(115200);
  Serial.print("\n\n\n");

  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);

  // write a 0 to all 512 bytes of the EEPROM
  Serial.println("Clearing 512 bytes of EEPROM...");
  EEPROM.begin(512);
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);

  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);

  // format SPIFFS
  Serial.println("Formatting SPIFFS...");
  SPIFFS.format();

  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);

  // clear WiFiManager settings, wherever they live
  Serial.println("Clearing WiFiManager settings...");
  WiFiManager wifiManager;
  wifiManager.resetSettings();

  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
}

void loop() {
  Serial.println("Device erased.");
  while (true) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, LOW);
    delay(200);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, HIGH);
    delay(200);
  }
}
