# REST
[A full discussion of RESTful interfaces](http://www.restapitutorial.com/lessons/whatisrest.html) is beyond the scope of this lesson, but at a rough approximation adding REST capabilities allows us to communicate with the ESP8266 using simple HTTP requests which you can enter in a web browser.  This can be valuable when deploying systems at scale, allowing for easy implementation of load balancers, cache layers, and similar architectural constructs.

### Projects
#### [RESTserver](RESTserver/RESTserver.ino)
This sketch demonstrates the use of REST commands to GET information from the device, to send commands to the device, and to send commands to other devices.  The sketch utilizes a simple REST HTTP server which you can customize to provide your own interfaces and controls, and provides a simple web page to explore the capabilities provided.

#### [aREST](aREST/aREST.ino)
*
**WARNING**: The aREST ESP8266 library has been experiencing several issues with memory leaks and overall reliability problems.  I'm leaving this exercise here in hopes that this is resolved at some point, but for the moment, assume that aREST on ESP8266 will not serve as a reliable platform for your own projects.*

Use the [aREST framework](https://arest.io/) to provide an interface to the ESP8266 utilizing common [REST](https://en.wikipedia.org/wiki/Representational_state_transfer) commands.  

In the IDE select "Sketch" > "Include Library" > "Manage Libraries" to bring up the Library Manager window.  In this window we're going to search for "aREST" by typing our search term in the filter dialog box in the upper right of the Library Manger.  Click on the desired library for more information, and select "Install" to download and install the selected library into your IDE.  

![Add aREST library](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/AddArestLibrary.png)

Repeat this process for the aREST_UI library.  Open the "aREST.ino" sketch under [03_REST\aREST\aREST.ino](aREST/aREST.ino).  Modify the WiFi credentials to connect to the wireless network, upload the sketch to your device, and observe the boot process in the Serial Monitor.  Open the
