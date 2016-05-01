# WiFiManager
Something something libraries

### Process

In the IDE select "Sketch" > "Include Library" > "Manage Libraries" to bring up the Library Manager window.  In this window we're going to search for "WiFiManager" by typing our search term in the filter dialog box in the upper right of the Library Manger.  Click on the desired library for more information, and select "Install" to download and install the selected libary into your IDE.

![Add WiFiManager library](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/AddWiFiManagerLibrary.png)

As noted earlier, Arduino libraries often come with example sketches, and this one is no different.  Select "File" > "Examples" > "WiFiManager" > "AutoConnect" to open a helpful example.

The AutoConnect sketch demonstrates a self-configuration portal for user provisioning of WiFi credentials.  The sketch checks for saved Wifi credentials, and failing that, starts up it's own AP allowing the user to connect to the device and provide their WiFi creds through a browser.  The user will be presented with a list of networks and given a dialog box to enter the password.  These values will be saved on the device and will be used for future connections.

Let's make a couple of modifications before uploading this to your device.  In line 26 change the value "AutoConnectAP" to your name, something like this: `wifiManager.autoConnect("JaneDoeAP");``
