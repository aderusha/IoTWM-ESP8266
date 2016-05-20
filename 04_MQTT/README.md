# MQTT
[MQTT](https://en.wikipedia.org/wiki/MQTT) is a protocol for lightweight machine-to-machine communication, suitable for low-power devices communicating over low-bandwidth and unreliable links. MQTT communications are coordinated by a central MQTT broker.  Clients "publish" messages to a broker and can "subscribe" to messages sent by other devices.  Messages are arranged into a hierarchy of "topics", allowing clients to subscribe to a specific sub-set of topics published to a broker.

In order to get started with MQTT you will need an MQTT broker and one or more MQTT clients.  MQTT brokers are available as open-source software packages, commercially-supported servers, and cloud services.  For purposes of our experimentation we will work with the [Mosquitto project](http://mosquitto.org/) tools along with their [public test broker](http://test.mosquitto.org/).  We will deploy a test client to the Witty Cloud board and demonstrate the use of a web MQTT client to publish/subscribe messages.

### Projects
#### [MQTTdemo](MQTTdemo/MQTTdemo.ino)
This sketch relies on the ["PubSubClient"](/knolleary/pubsubclient) library for Arduino and ESP8266.  In the IDE select "Sketch" > "Include Library" > "Manage Libraries" to bring up the Library Manager window.  In this window we're going to search for "PubSubClient" by typing our search term in the filter dialog box in the upper right of the Library Manger.  Click on the desired library for more information, and select "Install" to download and install the selected library into your IDE.  
![Add PubSubClient library](https://github.com/aderusha/IoTWM-ESP8266/blob/master/Images/AddPubSubClientLibrary.png)
