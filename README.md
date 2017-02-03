#Control your Garage Door with Alexa and Ubi mobile app using ESP8266


This project will use the wemos d1 mini and 2 channel relay to control a 2 car garage using Alexa and Ubi mobile app.

Parts you need:

WeMos D1-mini ($5.00)

2 Channel mechanical Relay ($5.00)

How to use:

1. Download the code
2. Open file GarageDoor.ino in the Arduino editor.
3. Change the WI-FI settings.
4. Rename/Define callbacks (ex. change "garage name" to "right garage door") Note: don't use Cap letters.
5. Flash
6. Download/Install Ubi mobile app and login using your Amazon account username/password (Ubi is an echo device simulator that will allow you to control your devices remotely)

Note: Alexa doesn't recognize open/close commands so you have to use on and off (ex. "garage door name" on)


This project is based on the forked repos. This library enables your esp8266 to simulate a Belkin Wemo touch switch to open and close your garage door. It can be discovered as a device by your Amazon Echo/Dot under the Smart home section. 


