# ESP8266 for IoT
###### Getting started with Arduino and the ESP8266 for IoT development

This presentation will require the use of some simple free tools on your computer.  Download and install the items listed below before the presentation so you'll be ready to hack once we get started.

### Requirements
- A Windows, OSX, or Linux computer with an available USB port
- A micro-USB cable
- An ESP8266 development board (we'll be providing this part)
- An Android or IOS device (phone or tablet, only required for the last exercise)

### Setup Procedure
##### 1. Install the Arduino IDE
Download the Arduino IDE for your operating system and install with the instructions linked below.  We'll be using the downloaded version, so skip the sections regarding the online/cloud editor.

- [Software download](http://www.arduino.cc/en/main/software)
- [Installation instructions](http://www.arduino.cc/en/Guide/HomePage)

##### 2. Configure the ESP8266 Board Manager
Once the Arduino IDE is available we can add support for the development boards we'll be using.

1. Launch the Arduino application
2. Select the "File" menu ("Arduino" menu on OSX), then "Preferences"
3. Paste the following URL in the box labeled "Additional Boards Manager URLs": `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
The page should look something like this:
![Board Manager screenshot](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/BoardManagerScreenshot.png)
4. While we're here, check "Display line numbers"
5. Click OK to accept the changes
6. Select the "Tools" menu, "Board" menu, then "Boards Manager"
7. Search for ESP8266, click on the "esp8266" board and select "Install"

##### 3. Install Serial Drivers
The development board we'll be using has a CH341 USB-to-serial chipset which requires drivers on many systems.
###### Windows 10
No driver is required and the device should plug and play.
###### Windows 7/8
[Click here](http://www.wch.cn/downfile/5) to download the Windows driver from [the chipset manufacturer's website](https://translate.google.com/translate?hl=en&sl=zh-CN&u=http://www.wch.cn/download/CH341SER_ZIP.html).
###### Mac OSX
[Click here](http://www.wch.cn/downfile/178) to download the OSX driver from [the chipset manufacturer's website](https://translate.google.com/translate?hl=en&sl=zh-CN&u=http://www.wch.cn/download/CH341SER_MAC_ZIP.html).
###### Linux
[Click here](http://www.wch.cn/downfile/177) to download the drivers from [the manufacturer's site](https://translate.google.com/translate?hl=en&sl=zh-CN&u=http://www.wch.cn/download/CH341SER_LINUX_ZIP.html).

### [Now get started with the tutorials!](00_Introduction)

