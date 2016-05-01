# ESP8266 for IoT
# Introduction
This series of tutorials will cover several approaches to utilizing the ESP8266 platform for IoT device development and experimentation.  Each tutorial stands alone and can be used as a starting point for your own projects.

# Witty Cloud development board
The board we'll be using is the Witty Cloud board produced by [GizWits](http://www.gizwits.com/) as a tool for utilizing their IoT cloud service.  This board provides an easy-to-use platform for experimentation with the ESP8266 including simple inputs and outputs along with a USB programming  interface and which is [available at a very low cost to users  around the world](http://www.aliexpress.com/wholesale?catId=0&SearchText=Witty+cloud+Development+Board).

Like most things involving the ESP8266, the [Witty Cloud development environment](http://site.gizwits.com/zh-cn/developer/), documentation, mobile apps, and reference libraries are all in Chinese.  In response a community effort has ported the development tools into the Arduino environment and has built a wide range of libraries for use in the Arduino IDE.  It is because of these efforts that we are able to use this inexpensive board in a simple development environment today.

<img src="https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/WittyCloudBoard.jpg" width="600">

# Tutorials
### [01_Basics](../01_Basics)
We'll start with the "hello world" of the embedded world and blink some LEDs.  Learn how to upload and run programs on the ESP8266, then learn how to read input and utilize serial output.

### [02_WiFi](../02_WiFi)
Learn how to interface with WiFi.  We'll create mesh networks, deploy a soft AP for gathering credentials, and connect to an AP.

### [03_REST_and_MQTT](../03_REST_and_MQTT)
Send REST commands to your device, then publish/subscribe to a public MQTT broker.  This tutorial relies on a cloud-based, public, and completely insecure broker for demo purposes.

### [04_Blynk](../04_Blynk)
Connect your device to the cloud and create a mobile app interface to control it from an Android or IOS device.

# Reference material
### Witty Cloud Pinout
*[source](http://www.schatenseite.de/en/2016/04/22/esp8266-witty-cloud-module/)*

| Label | Pin (Arduino) | Purpose |
| --- | --- | --- |
| REST | — | Reset |
| ADC | A0 | Analog input, connected to LDR |
| CH_PD | — | Chip Power-Down |
| GPIO16 | D0 | GPIO, freely usable |
| GPIO14 | D5 | GPIO, freely usable |
| GPIO12 | D6 | GPIO, green channel of RGB-LED |
| GPIO13 | D7 | GPIO, blue channel of RGB-LED |
| VCC | — | +5V power |
| TXD | TX | Serial interface |
| RXD | RX | Serial interface |
| GPIO5 | D1 | GPIO, freely usable |
| GPIO4 | D2 | GPIO, connected to pushbutton (LOW=pressed) |
| GPIO0 | D3 | GPIO, connected to flash-button, not really freely usable |
| GPIO2 | D4 | GPIO, connected to blue LED on the ESP-Module |
| GPIO15 | D8 | GPIO, red channel of RGB-LED |
| GND | — | Ground |


* [Witty Cloud board diagram](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/WittyCloudBoard.jpg)
* [ESP8266 pin mapping for Arduino](https://github.com/esp8266/Arduino/blob/master/variants/nodemcu/pins_arduino.h#L31-47)
* [ESP8266 overview and history](https://en.wikipedia.org/wiki/ESP8266)
* [Arduino core for ESP8266 project page](https://github.com/esp8266/Arduino)

# Community resources
* [The Arduino Community Forums](https://forum.arduino.cc/) - The epicenter of everything Arduino, suitable for beginners and experts alike.  If you're looking to interface with something, having trouble with code, or are just looking for ideas, this is the place to get started.
* [ESP8266 Community Forums](http://www.esp8266.com/) - Community forums specifically dealing with the ESP8266 platform for English-language users.
