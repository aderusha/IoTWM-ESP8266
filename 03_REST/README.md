# aREST
Here we'll be using the [aREST framework](https://arest.io/) to provide us with the ability to interface with the ESP8266 utilizing common [REST](https://en.wikipedia.org/wiki/Representational_state_transfer) commands.  A full discussion of RESTful interfaces is beyond the scope of this lesson, but at a rough approximation adding REST capabilities allows us to communicate with the ESP8266 using simple HTTP requests which you can enter in a web brower.

### Process

In the IDE select "Sketch" > "Include Library" > "Manage Libraries" to bring up the Library Manager window.  In this window we're going to search for "aREST" by typing our search term in the filter dialog box in the upper right of the Library Manger.  Click on the desired library for more information, and select "Install" to download and install the selected library into your IDE.

![Add aREST library](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/AddArestLibrary.png)

Open the "aREST.ino" sketch under [03_REST\aREST\aREST.ino](aREST/aREST.ino).  Modify the WiFi credentials to connect to the wireless network, upload the sketch to your device, and observe the boot process in the Serial Monitor.
