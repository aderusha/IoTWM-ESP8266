/*
  This a simple example of the aREST UI Library for the ESP8266.
  See the README file for more details.

  Written in 2014 by Marco Schwartz under a GPL license.
*/

// Import required libraries
#include <ESP8266WiFi.h>
#include <aREST.h>
#include <aREST_UI.h>

// Create aREST instance
aREST_UI rest = aREST_UI();

// WiFi parameters
const char* ssid = "EMBEDED";
const char* password = "buildit1";

// The port to listen for incoming TCP connections
#define LISTEN_PORT           80

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13

// Variables to be exposed to the API
int ldrLevel;
//int temperature;
//float humidity;

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Create button to control red LED
  rest.button(ledRed);
  rest.slider(ledBlue);
  rest.title("aREST_UI demo");

  // Init variables and expose them to REST API
  //temperature = 22;
  //humidity = 39.1;
  //rest.variable("temperature",&temperature);
  //rest.variable("humidity",&humidity);
  ldrLevel = analogRead(inputLDR);
  rest.variable("ldr",&ldrLevel);

  // Function to be exposed
  rest.function("led",ledControl);

  // Give name and ID to device
  rest.set_id("1");
  rest.set_name("esp8266");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Attempting connection to wireless network ");
  Serial.print(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.print("Server started @ http://");

  // Print the IP address
  Serial.print(WiFi.localIP());
  Serial.print(":");
  Serial.println(LISTEN_PORT);

}

void loop() {

  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);

}

int ledControl(String command) {

  Serial.println(command);

  // Get state from command
  int state = command.toInt();

  digitalWrite(5,state);
  return 1;
}
