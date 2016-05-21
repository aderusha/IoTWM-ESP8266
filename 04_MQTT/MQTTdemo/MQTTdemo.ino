/*
  Witty Cloud MQTT Demonstrator
  Based on "Basic ESP8266 MQTT example"
  https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino

  Connect to WiFi and an MQTT broker defined in the program below, then:
    * Subscribe to incoming messages under a specified topic
    * Control the RGB LED in response to subscribed messages
    * Publish the LDR reading every 60 seconds
    * Turn off the RGB LEDs when the button is pressed
    * Send a command to a partner device to turn on the RGB LEDs when the button is pressed
    * Turn on the RGB LEDs when a partner command is received
*/

#include <ESP8266WiFi.h>
#include <string.h>
#include <PubSubClient.h>

// Enter a unique value here
const char* device_name = "YourName";

// Enter a partner device name here
String partner_name = "PartnerName";

// Update these with values suitable for your network.
const char* ssid = "EMBEDED";
const char* password = "buildit1";

const char* mqtt_broker = "test.mosquitto.org";
const char* mqtt_topic_base = "IoTWM-ESP8266";

// setup topic and subscription strings
String mqtt_topic = String(mqtt_topic_base) + "/" + String(device_name);
String mqtt_subscription = mqtt_topic + "/#";
String mqtt_red = mqtt_topic + "/red";
String mqtt_green = mqtt_topic + "/green";
String mqtt_blue = mqtt_topic + "/blue";
String mqtt_ldr = mqtt_topic + "/ldr";
String mqtt_button = mqtt_topic + "/button";
String mqtt_partner_in = mqtt_topic + "/partner";
String mqtt_partner_out = String(mqtt_topic_base) + "/" + partner_name + "/partner";

// Declare constants to map to specific pins on the Witty Cloud board
const int inputLDR = A0;   // Pin labeled ADC
const int inputButton = 4; // Pin labeled GPIO4
const int ledRed = 15;     // Pin labeled GPIO15
const int ledGreen = 12;   // Pin labeled GPIO12
const int ledBlue = 13;    // Pin labeled GPIO13

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char ldrMsg[6];

void setup() {
  pinMode(inputLDR, INPUT);    // initialize the LDR as an input
  pinMode(inputButton, INPUT); // initialize the button as an input
  pinMode(ledRed, OUTPUT);     // Initialize the blue LED pin as an output
  pinMode(ledGreen, OUTPUT);   // Initialize the blue LED pin as an output
  pinMode(ledBlue, OUTPUT);    // Initialize the blue LED pin as an output
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Attempting connection to wireless network ");
  Serial.print(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected and assigned IP: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_broker, 1883);
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  String inMessage;
  for (int i = 0; i < length; i++) {
    inMessage += (char)payload[i];
  }
  Serial.print("Incoming message ");
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(inMessage);

  // Catch an incoming command
  if (String(topic) == mqtt_red) {
    Serial.print("Caught incoming red LED command: ");
    Serial.println(inMessage);
    analogWrite(ledRed, inMessage.toInt());
  }

  // Catch an incoming command
  if (String(topic) == mqtt_green) {
    Serial.print("Caught incoming green LED command: ");
    Serial.println(inMessage);
    analogWrite(ledGreen, inMessage.toInt());
  }

  // Catch an incoming command
  if (String(topic) == mqtt_blue) {
    Serial.print("Caught incoming blue LED command: ");
    Serial.println(inMessage);
    analogWrite(ledBlue, inMessage.toInt());
  }

  // Catch an incoming command
  if (String(topic) == mqtt_partner_in) {
    Serial.print("Caught incoming partner command: ");
    Serial.println(inMessage);
    analogWrite(ledRed, 1024);
    analogWrite(ledGreen, 1024);
    analogWrite(ledBlue, 1024);
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection to broker: ");
    Serial.println(mqtt_broker);
    // Attempt to connect
    if (client.connect(device_name)) {
      Serial.print("MQTT client connected as ");
      Serial.println(device_name);
      // Once connected, publish an announcement...
      client.publish(mqtt_topic.c_str(), "MQTT client connected");
      // ... and resubscribe
      client.subscribe(mqtt_subscription.c_str());
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(". Trying again in 5 seconds.");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Catch a local button press
  int buttonStatus = !digitalRead(inputButton);
  if (buttonStatus) {
    Serial.print("Caught local button press, sending command to partner: ");
    Serial.println(partner_name);
    client.publish(mqtt_partner_out.c_str(), "Pressed");
    analogWrite(ledRed, 0);
    analogWrite(ledGreen, 0);
    analogWrite(ledBlue, 0);
  }

  // Report the LDR level every 60 seconds
  long now = millis();
  if (now - lastMsg > 60000) {
    lastMsg = now;
    int ldrValue = analogRead(inputLDR);
    snprintf (ldrMsg, 6, "%d", ldrValue);
    Serial.print("Publishing LDR value: ");
    Serial.println(ldrMsg);
    client.publish(mqtt_ldr.c_str(), ldrMsg);
  }
}
