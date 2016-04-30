# ESP8266 for IoT
# Introduction
This series of tutorials will cover several approaches to utilizing the ESP8266 platform for IoT device development and experimentation.  Each tutorial stands alone and can be used as a starting point for your own projects.

# Witty Cloud development board
The board we'll be using is the Witty Cloud board produced by [GizWits](http://www.gizwits.com/) as a tool for utilizing their IoT cloud service.  This board provides an easy-to-use platform for experimentation with the ESP8266 including simple inputs and outputs along with a USB programming and power interface and is [available at a very low cost](http://www.aliexpress.com/item/ESP8266-serial-WIFI-Witty-cloud-Development-Board-ESP-12F-module-MINI-nodemcu/32566502491.html).

Unfortunately, the [documentation](http://site.gizwits.com/zh-cn/developer/), mobile apps, and reference libraries are all in Chinese.  As a result we'll need to rely on community efforts to document the platform and to create libraries for use in the Arduino IDE.

<img src="http://i.imgur.com/pwaXoCt.jpg" width="600">

# Tutorials
### [01_Blink](../01_Blink)
The "hello world" of the embedded world, we'll start with the simplest sketch possible and blink some LEDs.  Learn how to upload and run programs on the ESP8266.

### [02_WiFi_and_REST](../02_WiFi_and_REST)
Connect the ESP8266 to wireless and send commands to the device via REST.  Uses the [aREST library](https://github.com/marcoschwartz/aREST) for Arduino and ESP8266.

### [03_MQTT](../03_MQTT)
Publish and subscribe to topics on a public MQTT broker.  This tutorial relies on a cloud-based, public, and completely insecure broker for demo purposes.

### [04_Blynk](../04_Blynk)
Connect your device to the cloud and create a mobile app interface to control it from an Android or IOS device.

# Reference material
### Witty Cloud Pinout
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
| GPIO4 | D2 | GPIO, connected to pushbutton |
| GPIO0 | D3 | GPIO, connected to flash-button, not really freely usable |
| GPIO2 | D4 | GPIO, connected to blue LED on the ESP-Module |
| GPIO15 | D8 | GPIO, red channel of RGB-LED |
| GND | — | Ground |

* [Witty Cloud board diagram](http://i.imgur.com/pwaXoCt.jpg)
* [ESP8266 pin mapping for Arduino](https://github.com/esp8266/Arduino/blob/master/variants/nodemcu/pins_arduino.h#L31-47)
* [ESP8266 overview and history](https://en.wikipedia.org/wiki/ESP8266)

# Community resources
* [The Arduino Community Forums](https://forum.arduino.cc/) - The epicenter of everything Arduino, suitable for beginners and experts alike.  If you're looking to interface with something, having trouble with code, or are just looking for ideas, this is the place to get started.
* [ESP8266 Community Forums](http://www.esp8266.com/) - Community forums specifically dealing with the ESP8266 platform for English-language users.
