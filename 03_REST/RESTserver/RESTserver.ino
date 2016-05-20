/*
  Based on "HelloServer" by Ivan Grokhotkov
  This example code is in the public domain.

  Query LDR: http://<ip>/ldr
  Set RGD LED:  http://<ip>/led?red=100&blue=50&green=7

*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "EMBEDED";
const char* password = "buildit1";
const char* partner = "10.0.100.1";

ESP8266WebServer server(80);

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13

// The port to listen for incoming TCP connections
#define LISTEN_PORT 80

int ledToggle = 0;

// Create callbacks for REST commands

// Send main page
void handleRoot() {
  String message = "<html><body><h1>REST server example</h1>\n\n";
  message += "<a href=/toggle>Toggle LED</a><br>\n";
  message += "<a href=/ldr>Read LDR</a><br>\n";
  message += "<a href=/led?red=1024&green=0&blue=0>LED Red</a><br>\n";
  message += "<a href=/led?red=0&green=1024&blue=0>LED Green</a><br>\n";
  message += "<a href=/led?red=0&green=0&blue=1024>LED Blue</a><br>\n";
  message += "</body></html>";
  server.send(200, "text/html", message);
}

// handler to toggle LED
void handleToggle() {
  ledToggle = !ledToggle;
  digitalWrite(ledRed, ledToggle);
  digitalWrite(ledGreen, ledToggle);
  digitalWrite(ledBlue, ledToggle);
  String message = "<html><body><h1>LED Toggle ";
  if (ledToggle) {
    message += "on";
  }
  else {
    message += "off";
  }
  message += "</h1></body></html>";
  server.send(200, "text/html", message);
}

// handler for "/led".  Use red/green/blue variables in the GET
// command to set the RGB LED.  Example REST command would look
// like this:  http://1.2.3.4/led?red=1024&green=0&blue=512
void handleLed() {
  String message = "Received LED command\n";

  if (server.arg("red") != "") {
    String redString = server.arg("red");
    int redValue = redString.toInt();
    analogWrite(ledRed, redValue);
    message += "Red: ";
    message += redValue;
    message += "\n";
  }

  if (server.arg("green") != "") {
    String greenString = server.arg("green");
    int greenValue = greenString.toInt();
    analogWrite(ledGreen, greenValue);
    message += "Green: ";
    message += greenValue;
    message += "\n";
  }

  if (server.arg("blue") != "") {
    String blueString = server.arg("blue");
    int blueValue = blueString.toInt();
    analogWrite(ledBlue, blueValue);
    message += "Blue: ";
    message += blueValue;
    message += "\n";
  }

  server.send(200, "text/plain", message);
  Serial.println(message);
}

// handler for /ldr
// Return a simple JSON string with the LDR reading
void handleLdr() {
  int ldrLevel = analogRead(inputLDR);
  String message = "{\"ldr\":\"";
  message += ldrLevel;
  message += "\"}";
  server.send(200, "text/plain", message);
  Serial.println(message);
}

// Send the user a 404 if we've been sent something we can't handle
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

// Send a REST command to another device
void partnerToggle() {
  WiFiClient client;
  if (!client.connect(partner, 80)) {
    Serial.println("HTTP client connection failed");
    return;
  }
  String url = "/toggle";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + partner + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println("HTTP client timeout");
      client.stop();
      return;
    }
  }
  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("HTTP client connection closed");
}


void setup(void) {
  pinMode(inputLDR, INPUT);    // initialize the LDR as an input
  pinMode(inputButton, INPUT); // initialize the button as an input
  pinMode(ledRed, OUTPUT);     // Initialize the blue LED pin as an output
  pinMode(ledGreen, OUTPUT);   // Initialize the blue LED pin as an output
  pinMode(ledBlue, OUTPUT);    // Initialize the blue LED pin as an output

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

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

  server.on("/", handleRoot);
  server.on("/led", handleLed);
  server.on("/ldr", handleLdr);
  server.on("/toggle", handleToggle);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.print("Server started @ http://");

  // Print the IP address
  Serial.print(WiFi.localIP());
  Serial.print(":");
  Serial.println(LISTEN_PORT);
}

void loop(void) {
  // run the HTTP server loop
  server.handleClient();

  // run an HTTP request if the local button is pressed
  int buttonValue = !digitalRead(inputButton);
  if (buttonValue) {
    partnerToggle();
  }
}
