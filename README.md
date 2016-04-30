# ESP8266 for IoT
###### Getting started with Arduino and the ESP8266 for IoT development

This presentation will require the use of some simple free tools on your computer.  Download and install the items listed below before the presentation so you'll be ready to hack once we get started.

### Requirements
- A Windows, OSX, or Linux computer with an available USB port
- A micro-USB cable
- An ESP8266 development board (we'll be providing this part)

### 1.) Install the Arduino IDE
Download the Arduino IDE for your operating system and install with the instructions linked below

- [Software download](http://www.arduino.cc/en/main/software)
- [Installation instructions](http://www.arduino.cc/en/Guide/HomePage)

### 2.) Configure the ESP8266 Board Manager
Once the Arduino IDE is available we can add support for the development boards we'll be using.

1. Launch the Arduino application
2. Select the "File" menu, then "Preferences"
3. Paste the following URL in the box labeled "Additional Boards Manager URLs": `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
4. Click OK to accept the changes

![Board Manager screenshot](https://i.imgur.com/cvi7Hbl.png)

### 3.) Install Serial Drivers
The development board we'll be using has a CH341 USB-to-serial chipset which requires drivers on many systems.
#### Windows 10
No driver is required because Windows 10 is great and Just Works.
#### Windows 7/8
You should probably upgrade to Windows 10 (see above), otherwise [click here](http://www.wch.cn/downfile/5) to download the Windows driver from [the chipset manufacturer's website](https://translate.google.com/translate?hl=en&sl=zh-CN&u=http://www.wch.cn/download/CH341SER_ZIP.html).
#### Mac OSX
You should probably upgrade to Windows 10 (see above), otherwise [click here](http://www.wch.cn/downfile/178) to download the OSX driver from [the chipset manufacturer's website](https://translate.google.com/translate?hl=en&sl=zh-CN&u=http://www.wch.cn/download/CH341SER_MAC_ZIP.html).
#### Linux
You should probably reconsider the life decisions that led you to run Linux on a laptop and then [click here](http://www.wch.cn/downfile/177) to download the drivers from [the manufacturer's site](https://translate.google.com/translate?hl=en&sl=zh-CN&u=http://www.wch.cn/download/CH341SER_LINUX_ZIP.html).

### 4.) [Get started with the tutorials](00_Introduction)
---
*Link to this project page:*

![QR shortcut to this project](http://i.imgur.com/FNq8hDJ.png)
