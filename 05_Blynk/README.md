# Blynk
[Blynk](http://blynk.cc/getting-started/) is the result of a successful Kickstarter campaign to create a mobile application front-end for your own connected projects.  Blynk works as a "freemium" model where you buy "Fuel" to create widgets and share the results with your users (they gotta pay the bills too).  For test purposes there is plenty to do without making a purchase, so you can get a feel for the service before spending any money.  Today's demo will rely entirely on the free offering.

### NOTE: This demo requires an Android or IOS mobile device.

### Process
This sketch relies on the ["Blynk"](https://github.com/blynkkk/blynk-library) library for Arduino and ESP8266.  In the IDE select "Sketch" > "Include Library" > "Manage Libraries" to bring up the Library Manager window.  In this window we're going to search for "Blynk" by typing our search term in the filter dialog box in the upper right of the Library Manger.  Click on the desired library for more information, and select "Install" to download and install the selected library into your IDE.
![Add Blynk library](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/AddBlynkLibrary.png)

Under "File" > "Examples" > "Blynk" > "Boards_WiFi" select "ESP8266_Standalone" to open an example sketch for the ESP8266 device.  On line 39 you'll find the command `Blynk.begin(auth, "ssid", "pass");`.  Change that statement to include the local WiFi credentials, like so: `Blynk.begin(auth, "wifi", "password");`

Now install the mobile app for [IOS](https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&mt=8) or [Android](https://play.google.com/store/apps/details?id=cc.blynk) and launch the application on your device.  Select "Create Account", enter your email address (use a real address that you have access to today), and assign a password.

From the main Blynk screen select "Create New Project".  Enter a name for your project, then click on "Hardware Model" to bring up a list of supported boards.  Scroll until you find "ESP8266" and select "Continue".  Click "Create" in the app to save your settings and to send an "Auth Token" to your provided email account.

Check your email account for a message from blynk.cc.  Open the email on your computer and look for the Auth Token which will be a 32-character string of letters and numbers.  Copy the token and switch back to the Arduino IDE on your PC.  Find line 35 in the example sketch and replace "YourAuthToken" with the token provided, like so: `char auth[] = "00112233445566778899aabbccddeeff";`.  On lines 39 and 40, replace "YourNetworkName" and "YourPassword" with the WiFi credentials for your network.  With the Blynk auth token and WiFi creds setup we are ready to upload your sketch to the board.

Once the sketch is uploaded to your board you can now create your control interface in the Blynk mobile app.  With your Project open, click in the empty black area to bring up the Widget Box.

![Blynk Demo 01](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/BlynkDemo01.png)

Select "Slider" to place a Slider control into the project.  Repeat this task two more times, placing a total of 3 sliders.

![Blynk Demo 02](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/BlynkDemo02.png)

Press again in the empty background to bring up the Widget Box, and this time select "Value Display".  Finally, repeat the process one last time and select "Graph".  You should now have 5 items in your project.

![Blynk Demo 03](

https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/BlynkDemo03.png)

Press on the first Slider control to configure.  Give the slider a name by pressing on the text "Slider" and entering "Red".

![Blynk Demo 04](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/BlynkDemo04.png)

Assign a color to this control by clicking the teardrop shape next to the control name and selecting the Red colored teardrop.

![Blynk Demo 05](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/BlynkDemo05.png)

Finally, to configure the Output select the word "Pin", and select `Digital` > `gp15 PWM` (reference the [Witty Cloud pin map](https://github.com/aderusha/IoTWM-ESP8266/tree/master/00_Introduction#witty-cloud-pinout) for why we chose this)

![Blynk Demo 06](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/BlynkDemo06.png)
