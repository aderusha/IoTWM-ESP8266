# WiFi Mesh
Instead of providing code let's take a moment to check out the Arduino "example" sketches.  The core Arduino distribution includes examples for loads of concepts covering program structure and interfacing with common devices.  Adding new boards (as we did for the ESP8266) or new libraries (as we will do soon) can also add examples to the Arduino IDE.

### Requirements
This exercise requires two or more ESP8266 devices in order for a mesh to be created.

### Process

In the IDE select "File" > "Examples" > "ESP8266WiFiMesh" > "HelloMesh".  This will open up a new window with example code that was deployed when you added the ESP8266 board definition.  Before digging into the code, let's go ahead and upload it as-is.  Open the serial monitor and observe.... nothing maybe?  Maybe some weird characters?

The serial debug output in this example is set to 115200bps on line 32.  Select the correct bitrate in the bottom-right of the serial monitor window, and if you have more than one board running you should start seeing messages from other boards within 30 seconds or so.

![WiFi Mesh Serial Output](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/WiFiMesh.png)

Now let's modify the code.  On line 50 edit the sprintf command to replace "Mesh_Node" with your name, like this: `sprintf(request, "Hello world request #%d from First Last %d.", request_i++, ESP.getChipId());`  Click upload and watch the serial monitor for other devices on the mesh to start broadcasting their own names.

You'll be prompted to save your work when you attempt to close a window that has unsaved changes.  If you have made changes to an example sketch, you'll be advised that the example is read-only and then prompted to save your changes into a new folder.
