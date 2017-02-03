#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include "WemoSwitch.h"
#include "WemoManager.h"
#include "CallbackFunction.h"

  const int relayS1Pin = D1;
  const int relayS2Pin = D2;


// prototypes
  boolean connectWifi();

//on/off callbacks
  void relayS1On();
  void relayS1Off();
  void relayS2On();
  void relayS2Off();


//------- Replace the following! ------
char ssid[] = "WIFI_Name";       // your network SSID (name)
char password[] = "PASSWORD";  // your network key

WiFiServer server(80);//-------NEW

WemoManager wemoManager;
  WemoSwitch *S1 = NULL;
  WemoSwitch *S2 = NULL;
  

void setup()
{
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  // Start the server -----NEW
  server.begin();
  Serial.println("Server started");

  // Print the IP address--------NEW
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  wemoManager.begin();
  // Format: Alexa invocation name, local port no, on callback, off callback
  S1 = new WemoSwitch("garage name", 81, S1On, S1Off);   // Change to the name you want and Do not use cap letters in the name
  S2 = new WemoSwitch("garage 2 name", 82, S2On, S2Off); // Change to the name you want and Do not use cap letters in the name
  
    wemoManager.addDevice(*S1);
    wemoManager.addDevice(*S2);
  

  pinMode(relayS1Pin, OUTPUT); // initialize digital Pin as an output.
  digitalWrite(relayS1Pin, HIGH); 

  pinMode(relayS2Pin, OUTPUT); // initialize digital Pin as an output.
  digitalWrite(relayS2Pin, HIGH); 

}

void loop()

{
  wemoManager.serverLoop();
}


void S1On() {
    Serial.print("Switch 1 on ...");
    digitalWrite(relayS1Pin, LOW);
    delay(700);
    digitalWrite(relayS1Pin, HIGH);
}

void S1Off() {
    Serial.print("Switch 1 off ...");
    digitalWrite(relayS1Pin, LOW);
    delay(700);
    digitalWrite(relayS1Pin, HIGH);
}

void S2On() {
    Serial.print("Switch 2 on ...");
    digitalWrite(relayS2Pin, LOW);
    delay(700);
    digitalWrite(relayS2Pin, HIGH);
}

void S2Off() {
    Serial.print("Switch 2 off ...");
    digitalWrite(relayS2Pin, LOW);
    delay(700);
    digitalWrite(relayS2Pin, HIGH);
}


