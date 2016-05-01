# WiFiManager
Something something libraries

### Process

In the IDE select "Sketch" > "Include Library" > "Manage Libraries" to bring up the Library Manager window.  In this window we're going to search for "WiFiManager" by typing our search term in the filter dialog box in the upper right of the Library Manger.  Click on the desired library for more information, and select "Install" to download and install the selected libary into your IDE.

![Add WiFiManager library](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/AddWiFiManagerLibrary.png)

As noted earlier, Arduino libraries often come with example sketches, and this one is no different.  Select "File" > "Examples" > "WiFiManager" > "AutoConnect" to open a helpful example.

The AutoConnect sketch demonstrates a self-configuration portal for user provisioning of WiFi credentials.  The sketch checks for saved Wifi credentials, failing that, starts up it's own AP allowing the user to connect to the device and provide their WiFi creds through a browser.  The user will be presented with a list of networks and given a dialog box to enter the password.  These values will be saved on the device and will be used for future connections.

Let's make a couple of modifications before uploading this to your device.  In line 26 change the value "AutoConnectAP" to your name.  It should look something like this: `wifiManager.autoConnect("JaneDoeAP");``

On line 32 the example sketch prints a success message over serial.  Let's add a couple lines to that message to provide us with the IP address assignment which will help us when running and configuring this sketch.

```
//if you get here you have connected to the WiFi
Serial.println("connected...yeey :)");
Serial.println("local ip");
Serial.println(WiFi.localIP());
```
On device bootup, WiFiManager will load and check for saved WiFi credentials.  As this is the first time we've run it, it creates a temporary AP and waits for us to connect.
```
*WM: Configuring access point...
*WM: JaneDoeAP
*WM: AP IP address:
*WM: 192.168.4.1
*WM: HTTP server started
```
On your laptop or mobile device, connect to the AP name you entered in your sketch (in this case, "JaneDoeAP").  Once you've connected, open a browser and go to a site like "example.com".  You should be redirected to a configuration portal that looks like this:

![WiFiManager Configuration Portal](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/WiFiManagerConfigPortal.png)

Select "Configure WiFi" and the device will scan for local broadcasting APs.  Select an AP from the list (or enter your own), enter the AP's password, then select "Save".  Upon successful connection the sketch will write the saved values to flash and continue program execution.  Later reboot cycles will attempt to connect using the saved values.

#### Reset Saved Settings
WiFiManager saves its settings to flash which is convenient for devices installed in the field.  For development, it's often helpful to blow away those saved settings so you can test the setup procedures.  In line 17 of the AutoConnect sketch you'll find the command `//wifiManager.resetSettings();`.  This command is commented out.  Remove the forward slashes `//` from that command to reset the saved credentials every time that command is run (in this case, every boot up).  

Once you're confident that your sketch is working and is ready to deploy, comment this command back out again so saved credentials will persist between restarts.
