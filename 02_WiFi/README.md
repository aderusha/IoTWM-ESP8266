# Interface with WiFi
The ESP8266 WiFi chipset provides the ability for your device to communicate with other devices, your network, or the cloud, all made simple with stock libraries available through the Arduino IDE.  We'll step through various WiFi configurations to get a handle on what's possible.


### Projects
#### [WiFiMesh](WiFiMesh/README.md)
Create a WiFi mesh network for device-to-device communication without supporting infrastructure.  Learn how to use the built-in examples as a starting point for your own projects.

#### WiFiManager
Use the WiFiManager library for advanced WiFi connectivity and guided end-user device configuration.

### Resources
#### [WittyCloudClearAllSettings](WittyCloudClearAllSettings/WittyCloudClearAllSettings.ino)
Quick sketch that will delete all saved settings from the various storage bins that the ESP8266 maintains, including WiFi creds, EEPROM, and the SPIFFS filesystem.
#### [ESP8266 OTA programming](http://esp8266.github.io/Arduino/versions/2.0.0/doc/ota_updates/ota_updates.html)
The ESP8266/Arduino IDE integration offers Over-The-Air programming which lets you push code updates to a running ESP8266 device over WiFi.  This can be helpful when testing deployments with several systems or updating systems in the field.  **USE CAUTION!** Updating a running system may have unexpected consequences for the device and for whatever the device is controlling.

Setting up OTA capability in the IDE is a little time consuming and requires installing a few extra pieces.  Once you have the tools in place, adding OTA support to your existing sketches is usually very simple.  The linked guide will walk you through the steps of setting OTA up for your own testing.
