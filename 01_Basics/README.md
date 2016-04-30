# ESP8266 for IoT
# Getting started
Let's try some basics to get ourselves familiarized with the Arduino environment.

### The code
#### [Blink](Blink)
The "Hello world" of embedded devices, we'll start with a blinking LED along with displaying some serial output.  Demonstrates basic program structure, digital outputs, and writing to serial.

#### [BlinkWithButton](BlinkWithButton)
Use the button to capture local user input and turn on the LED.  Demonstrates digital input and conditional statements.

#### [NightLight](NightLight)
Detect ambient light conditions with the LDR and turn on a night light when it's dark, along with a button to toggle the device on and off.  Demonstrates analog input/output and nested conditional statements.

### The Process
1. Open the first "sketch" in the Arduino IDE by double-clicking the file "IoTWM-ESP8266-master\01_Basics\Blink\Blink.ino".
2. In the "Tools" menu select "Board" and then "NodeMCU 1.0 (ESP-12E Module)".
3. In the "Tools" menu select "Port" and then the COM port assigned to your device.
4. Compile the sketch and verify no errors are thrown.
5. Upload the sketch to your device with the upload button.

![Arduino IDE](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/ArduinoIDE.png)
