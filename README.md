#Control your Garage Door with Alexa and Ubi mobile app using ESP8266


This project will use the wemos d1 mini and 2 channel relay to control a 2 car garage using Alexa and Ubi mobile app.

Parts you need:

[WeMos D1-mini](http://www.ebay.com/sch/i.html?_odkw=wemos+d1+mini&_osacat=0&_from=R40&_trksid=p2045573.m570.l1313.TR4.TRC1.A0.H0.TRS0&_nkw=wemos+d1+mini&_sacat=0) ($4.00)

[2 Channel mechanical Relay](http://www.ebay.com/itm/2-Channel-DC-5V-Relay-NO-NC-With-Optocoupler-Module-Isolation-For-Arduino-/301108325591?hash=item461b746cd7:g:ArsAAOSw-jhUH7Em) ($3.00) Note: Do not use a Solid State Relay SSR, it won't work. 

How to use:

1. Download the code
2. Open file GarageDoor.ino in the Arduino editor.
3. Change the WI-FI settings.
4. Rename/Define callbacks (ex. change "garage name" to "right garage door") Note: don't use Cap letters.
5. Flash
6. Download/Install Ubi mobile app and login using your Amazon account username/password (Ubi is an echo device simulator that will allow you to control your devices remotely)

Note: Alexa doesn't recognize open/close commands so you have to use on and off (ex. "garage door name" on)


This project is based on the forked repos. This library enables your esp8266 to simulate a Belkin Wemo touch switch to open and close your garage door. It can be discovered as a device by your Amazon Echo/Dot under the Smart home section. 


