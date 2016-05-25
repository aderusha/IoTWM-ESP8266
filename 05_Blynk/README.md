# Blynk
[Blynk](blynk.cc/getting-started/) is the result of a successful Kickstarter campaign to create a mobile application front-end for your own connected projects.  Blynk recently moved to a "freemium" model where you buy "Fuel" to create widgets and share the results with your users (they gotta pay the bills too).  For test purposes there is plenty to do without making a purchase, so you can get a feel for the service before spending any money.  Today's demo will rely entirely on the free offering.

### NOTE: This demo requires an Android or IOS mobile device.

### Process
This sketch relies on the ["Blynk"](https://github.com/blynkkk/blynk-library) library for Arduino and ESP8266.  In the IDE select "Sketch" > "Include Library" > "Manage Libraries" to bring up the Library Manager window.  In this window we're going to search for "Blynk" by typing our search term in the filter dialog box in the upper right of the Library Manger.  Click on the desired library for more information, and select "Install" to download and install the selected library into your IDE.
![Add Blynk library](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/AddBlynkLibrary.png)

Under "File" > "Examples" > "Blynk" > "Boards_WiFi" select "ESP8266_Standalone" to open an example sketch for the ESP8266 device.  On line 39 you'll find the command `Blynk.begin(auth, "ssid", "pass");`.  Change that statement to include the local WiFi credentials, like so: `Blynk.begin(auth, "EMBEDED", "buildit1");`

Now install the mobile app for [IOS](https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&mt=8) or [Android](https://play.google.com/store/apps/details?id=cc.blynk) and launch the application on your device.  Select "Create Account", enter your email address (use a real address that you have access to today), and assign a password.

From the main Blynk screen select "Create New Project".  Enter a name for your project, then click on "Hardware Model" to bring up a list of supported boards.  Scroll until you find "ESP8266" and select "Continue"
